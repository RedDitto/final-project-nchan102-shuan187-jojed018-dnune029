# Task Scheduler 

 > Authors: \<[Nathan Chan](https://github.com/RedDitto)\>, \<[Shengkai Huang](https://github.com/shuan187)\>, \<[Jose Ojeda](https://github.com/jojeda018)\>, \<[Dylan Nunes](https://github.com/dnune029)\>

## Project Description
This "Task Scheduler" program will allow users to add tasks with a title, description, classification, priority, duration, and due date to a list. They would be able to place these tasks as a subtask inside larger tasks, which are represented as a task list, as well as create multiple seperate lists to hold these tasks. Users will be able to add, edit, delete, display, and undo these tasks and task lists. We chose this project because a task scheduler would be very helpful to have as a college student with varying amounts of deadlines. We plan to write this program in C++ and upload our work to this github repository.

## Class Diagram

![Task Scheduler (4)](https://user-images.githubusercontent.com/81592477/171315592-fc94625b-b046-4287-b451-fa16700de2cb.png)

There are two classes for our task scheduler. One of which is the TaskList class, which includes lists that contain a vector of tasks, and each task is differentiated by their description, classification, priority, duration, and deadline. There are two public functions that enables the insertion and deletion of tasks. The entire list can also be displayed. The second class is the Task class, which contains all of the specifications of the tasks that a user will add as well as functions that will set these attributes. 

We chose to use a composite design pattern for our project. We believe that a composite design pattern would fit the structure of our project as our tasklist class contains a group of tasks and the task class has functions that are employed in both classes. We decided to implement only the print both classes. This design pattern would help us write better code as the task class and the task list class are essentially the same in implementaiton; the only difference is that tasks have specific features like description and due date.

  ## Screenshots
  ![Screenshot 2022-06-02 235502](https://user-images.githubusercontent.com/100730925/171803869-7d84398e-6dc8-4639-b8ac-7a2ea3300833.png)
  ![Screenshot 2022-06-02 235935](https://user-images.githubusercontent.com/100730925/171803888-29b89035-610e-4874-b632-c66ba40ceeee.png)
  ![Screenshot 2022-06-03 000120](https://user-images.githubusercontent.com/100730925/171804062-08ef3be6-6075-4cc2-ba69-9e1bcf9788ca.png)
  ![Screenshot 2022-06-03 000255](https://user-images.githubusercontent.com/100730925/171804288-c0f6184a-b7be-4aa6-9ff6-d635f870cb1b.png)
  ![Screenshot 2022-06-03 000354](https://user-images.githubusercontent.com/100730925/171804459-2e5b42f5-c74f-4fd7-a4bd-a6721c70b631.png)
  ![Screenshot 2022-06-03 000424](https://user-images.githubusercontent.com/100730925/171804518-1b8b30c4-8740-44e9-92f8-73a29eec70c2.png)

 ## Installation/Usage
 1. Download base.hpp, main.cpp, task.hpp, task.cpp, tasklist.hpp, and tasklist.cpp
 2. Go to your local terminal and compile with the command
 ```sh
 g++ -std=c++11 -o taskinterface main.cpp task.cpp tasklist.cpp
 ```
 3. Run command 
 ```sh
 ./taskinterface
 ```
 ## Testing
 We used googletest to test all of our functions.
 ![taskstests](https://user-images.githubusercontent.com/40078612/171952911-437e0fc8-422a-4bee-8e14-08bc845d4ef9.jpg)
![tasklisttests](https://user-images.githubusercontent.com/40078612/171953058-5ffe3e1d-ffeb-4790-9c67-85484dce6a5f.png)

