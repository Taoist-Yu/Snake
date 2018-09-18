#           Snake
基于QT的贪吃蛇<br>
<br>
## GameWidget
实现了游戏窗口与基本逻辑<br>
该类中定义了事件与计时器，以及贪吃蛇的实体，同时实现了控制画面刷新的相关代码<br>
<br>
## Element
代表游戏中的一个基本元素，蛇的一节身体，蛇头等都是一个element<br>
<br>
## Food
继承自Element<br>
<br>
## SnakeBody
继承自Element<br>
<br>
## SnakeHead
继承自SnakeBody<br>
<br>
## Snake
定义了贪吃蛇（内含SnakeBody链表）<br>
<br>
## Square
定义了游戏场景<br>
