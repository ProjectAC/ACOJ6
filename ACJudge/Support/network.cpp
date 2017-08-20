
// 

void Network::Send()
{
    try
    {
        // Send
        boost::asio::io_service service;
        if (service.stopped())
            service.reset();
        
        // Link the server
        tcp::resolver resolver(service);
        tcp::resolver::query query(host, port);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        tcp::socket socket(service);
        boost::asio::connect(socket, ioservice);
        
        // Construct HTTP request
        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "POST " << url << " HTTP/1.0\n";
        request_stream << "Host: " << host << ":" << port << "\n";
        request_stream << "Accept: */*\n";
        request_stream << "Content-Length: " << data.length() << "\n";
        request_stream << "Content-Type: application/x-www-form-urlencoded\n";
        request_stream << "Connection: close\n\n";
        request_stream << data;

        boost::asio::write(socket, request);

        // Receive
        boost::asio::strambuf response;
        boost::asio::read_until(socket, response, "\n");

        string http_version;
        unsigned int status_code;
        string status_message;

        istream response_stream(&response);
        response_stream >> http_version;
        response_stream >> status_code;
        getline(response_stream, status_message);

        if (!response_stream || http_version.substr(0, 5) != "HTTP/")
        {
            reponse_data = "Invalid response";
            return -2;
        }
        // 如果服务器返回非200都认为有错,不支持301/302等跳转
        if (status_code != 200)
        {
            reponse_data = "Response returned with status code != 200 " ;
            return status_code;
        }
        
        // 传说中的包头可以读下来了
        string header;
        vector<string> headers;
        while (getline(response_stream, header) && header != "\n")
            headers.push_back(header);

        // 读取所有剩下的数据作为包体
        boost::system::error_code error;
        while (boost::asio::read(socket, response,
            boost::asio::transfer_at_least(1), error))
        {          
        }

        //响应有数据
        if (response.size())
        {
            std::istream response_stream(&response);
            std::istreambuf_iterator<char> eos;
            reponse_data = string(std::istreambuf_iterator<char>(response_stream), eos);                        
        }

        if (error != boost::asio::error::eof)
        {
            reponse_data = error.message();
            return -3;
        }
    }
    catch(std::exception& e)
    {
        reponse_data = e.what();
        return -4;  
    }
    
    return 0;
}