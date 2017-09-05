## 接口定义

#### 内部接口

- __GET /submissions/last/__  

获取最新的提交。  

- __POST /submissions/Tmp/__  

提交刚刚评测完毕的结果。  

- __POST /auth/acjudge/__  

验证ACJudge是否值得信任，并返回token。  

#### 外部接口

_ __GET /__  

获取前端页面基本框架（单页应用）。

- __GET /submission/list/__

获取提交记录表（有筛选功能）。

- __GET /submission/detail/__

获取提交详细信息。

- __POST /submission/submit/__

提交一次评测。

- __GET /task/list/__

获取题目列表（有筛选功能）。

- __GET /task/detail/__

显示一道题的详细描述。

- __POST /task/add/__ 

添加一道题目。

- __POST /task/data/add/__ 

上传数据包。

