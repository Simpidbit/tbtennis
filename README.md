# Tbtennis项目文档

> Simpidbit\<2766277616@qq.com\>
>
> Octobor, 2024.



## 项目架构

其中每个大框都代表一个线程





```mermaid
flowchart TD;

draw_data["绘制对象数据"];
physics_data["物理对象数据"];


subgraph "游戏逻辑处理线程";
logic_module["游戏逻辑模块"];
end;


subgraph "循环计算线程";
physics_module["物理引擎"];
end;

subgraph "图形渲染线程";
graph_render["图形渲染模块"];
end;

subgraph "客户端通信线程";
data_parser["数据解析器"]-->client_network["客户端网络通信模块"];
end;


subgraph "服务端通信程序";
server_network["服务端网络通信模块"];
end;


logic_module --> draw_data --> graph_render;
logic_module --"数据更改请求"--> physics_module --"更新"--> physics_data;
physics_data --"访问"--> physics_module;
physics_data --> logic_module;

logic_module --> data_parser;

client_network --> server_network;

server_network -."广播".-> client_network;
client_network -..-> data_parser;
data_parser -..-> logic_module;

```







## 程序逻辑

### 客户端

```mermaid
flowchart TD;

step1["程序开始运行，弹出菜单界面"];

    step2_game["开始游戏按钮"];
    step2_settings["游戏设置按钮"];
    step2_log["登录/注册按钮"];

        step3_islogin["判断是否已经登录"];
        	step4_register["注册"];
    	step3_game["选择房间"];
    		step4_game["新开窗口，游戏开始"];


step1-->step2_game-->step3_islogin;
step1-->step2_settings;
step1-->step2_log-->step3_islogin;


step3_islogin--"已登录"-->返回;
step3_islogin--"未登录"-->step4_register-->返回;

step2_game-->step3_game-->step4_game;
```







## 函数文档







## 类文档









## 代码规范



### 注释规范



### 开发过程规范



### 命名规范

- **长标识符**：尽量使用较长的、意义明确的标识符，除非在一些标识符意义特别明显的上下文中.
- **慎用大写**：除了全局（静态）常量和后端代码的某些宏定义，其他情况请不要使用大写字母，包括类名.



### 函数定义与使用规范



### 类或对象使用规范

