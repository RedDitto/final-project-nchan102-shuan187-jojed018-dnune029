#include <iostream>
#include <algorithm>
#include <vector>
#include "task.hpp"
#include "tasklist.hpp"
#include <string>
#include <list>
using namespace std;

void sortTaskTitle(vector<Task*>& userTasks);
bool compTaskTitle(Task* lhs, Task* rhs);
void sortTaskPriority(vector<Task*>& userTasks);
bool sortPriority(Task* lhs, Task* rhs);
void sortTasklistPriority(vector<Task*> userTasks);


void taskInterface(vector <Task*>& userTasks) {
    char input = '\0';
    int i;
    int taskLocation;
    string stringInput;
    int intInput;
    string title;
    string description;
    string classification;
    int priority;
    int duration;
    string dueDate;

    while (input != 'q') {
        cout << "Press a key:" << endl;
        cout << "a - create task" << endl;
        cout << "r - delete task" << endl;
        cout << "s - sort tasks by title" << endl;
        cout << "j - sort tasks by priority" << endl;
        cout << "t - edit title" << endl;
        cout << "d - edit description" << endl;
        cout << "c - edit classification" << endl;
        cout << "p - edit priority" << endl;
        cout << "i - edit duration" << endl;
        cout << "e - edit due date" << endl;
        cout << "o - print task" << endl;
        cout << "u - print all tasks" << endl;
        cout << "q - quit" << endl;
        cin >> input;
        cout << endl;

        if (input == 'a') {
            cin.ignore();
            cout << "Create Task:" << endl;
            cout << "Title:" << endl;
            getline(cin, stringInput);
            cout << endl;
            title = stringInput;
            cout << "Description:" << endl;
            getline(cin, stringInput);
            cout << endl;
            description = stringInput;
            cout << "Classification:" << endl;
            getline(cin, stringInput);
            cout << endl;
            classification = stringInput;
            cout << "Priority:" << endl;
            cin >> intInput;
            cout << endl;
            priority = intInput;
            cout << "Duration:" << endl;
            cin >> intInput;
            duration = intInput;
            cout << endl;
            cout << "Due Date:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            dueDate = stringInput;
            Task* newTask = new Task(title, description, classification, priority, duration, dueDate);
            userTasks.push_back(newTask);
            newTask = nullptr;
        }
        else if (input == 'r') {
            cout << "Delete Task:" << endl;
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;

            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
	            delete userTasks.at(i);
                    userTasks.erase(userTasks.begin() + i);
                }
            }
            cout << "Task Deleted!" << endl;
        }
        else if (input == 's') {
            sortTaskTitle(userTasks);
        }
        else if (input == 'j') {
            sortTaskPriority(userTasks);
        }
        else if (input == 't') {
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new title:" << endl;
                cin.ignore();
                getline(cin, stringInput);
                cout << endl;
                userTasks.at(taskLocation)->set_title(stringInput);
            }
        }
        else if (input == 'd') {
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new description:" << endl;
                cin.ignore();
                getline(cin, stringInput);
                cout << endl;
                userTasks.at(taskLocation)->set_description(stringInput);
            }
        }
        else if (input == 'c') {
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new classification:" << endl;
                cin.ignore();
                getline(cin, stringInput);
                cout << endl;
                userTasks.at(taskLocation)->set_classification(stringInput);
            }
        }
        else if (input == 'p') {
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new priority:" << endl;
                cin >> intInput;
                cout << endl;
                userTasks.at(taskLocation)->set_priority(intInput);
            }
        }
        else if (input == 'i') {
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new duration:" << endl;
                cin >> intInput;
                cout << endl;
                userTasks.at(taskLocation)->set_duration(intInput);

            }
        }
        else if (input == 'e') {
            cout << "Insert title of existing task:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new due date:" << endl;
                cin.ignore();
                getline(cin, stringInput);
                cout << endl;
                userTasks.at(taskLocation)->set_dueDate(stringInput);

            }
        }
        else if (input == 'o') {
            cout << "Insert title of existing task:" << endl;
            cin >> stringInput;
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
            cout << endl;
            taskLocation = -1;
            for (i = 0; i < userTasks.size(); ++i) {
                if (userTasks.at(i)->get_title() == stringInput && userTasks.at(i)->get_priority() == intInput) {
                    taskLocation = i;
                }
            }
            if (taskLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                userTasks.at(taskLocation)->print();
            }
        }
        else if (input == 'u') {
            for (i = 0; i < userTasks.size(); ++i) {
                userTasks.at(i)->print();
            }
        }
        else if (input != 'q') {
            cout << "Please input a valid character." << endl;
        }
    }

}
void tasklistInterface(vector <Tasklist*>& userTasklist) {
    char input = '\0';
    string stringInput;
    string listname;
    int intInput;
    string title;
    string description;
    string classification;
    int priority;
    int duration;
    string dueDate;
    string taskTitle;
    int taskpriority;
    int tasklistLocation;
    bool list_exists;
    while (input != 'q') {
        cout << "Press a key:" << endl;
        cout << "a - add tasklist" << endl;
        cout << "d - delete tasklist" << endl;
        cout << "i - insert task" << endl;
        cout << "e - insert task after" << endl;
        cout << "o - insert task based on priority" << endl;
        cout << "c - edit list name" << endl;
        cout << "r - remove task" << endl;
        cout << "p - print tasklist" << endl;
        cout << "q - quit" << endl;
        cin >> input;
        cout << endl;
        list_exists = false;

        if (input == 'a') {
            cout << "Create Tasklist:" << endl;
            cout << "Tasklist Title:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            title = stringInput;
            vector<Task*> userTasks;
            Tasklist* newList = new Tasklist(userTasks, title);
            userTasklist.push_back(newList);
            newList = nullptr;
        }
        else if (input == 'd') {
            cout << "Delete Tasklist:" << endl;
            cout << "Insert title of existing tasklist:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;

            for (int i = 0; i < userTasklist.size(); ++i) {
                if (userTasklist.at(i)->get_name() == stringInput) {
                    userTasklist.erase(userTasklist.begin() + i);
                    list_exists = true;
                    break;
                }
            }
            cout << "Tasklist Deleted!" << endl;
            cout << endl;
            if (list_exists == false) {
                cout << "No such list exists." << endl;
            }
        }
        else if (input == 'i') {
            cout << "Insert task into tasklist:" << endl;
            cout << "Insert title of existing tasklist:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            listname = stringInput;
            cout << endl;
            for (int i = 0; i < userTasklist.size(); ++i) {
                if (userTasklist.at(i)->get_name() == listname) {
                    cout << "Create Task:" << endl;
                    cout << "Title:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    title = stringInput;
                    cout << "Description:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    description = stringInput;
                    cout << "Classification:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    classification = stringInput;
                    cout << "Priority:" << endl;
                    cin >> intInput;
                    cout << endl;
                    priority = intInput;
                    cout << "Duration:" << endl;
                    cin >> intInput;
                    duration = intInput;
                    cout << endl;
                    cout << "Due Date:" << endl;
                    cin.ignore();
                    getline(cin, stringInput);
                    cout << endl;
                    dueDate = stringInput;
                    userTasklist.at(i)->add_task(title, description, classification, priority, duration, dueDate);
                    list_exists = true;
                    break;
                }
            }
            if (list_exists == false) {
                cout << "No such list exists." << endl;
            }
        }
        else if (input == 'e') {
            cout << "Insert task into tasklist:" << endl;
            cout << "Insert title of existing tasklist:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            listname = stringInput;
            cout << endl;
            cout << "Insert title of existing task:" << endl;
           
            getline(cin, stringInput);
            
            taskTitle = stringInput;
            cout << endl;
            cout << "Insert priority of existing task:" << endl;
            cin >> intInput;
           
            cin.ignore();
            taskpriority = intInput;
            cout << endl;
            for (int i = 0; i < userTasklist.size(); ++i) {
                if (userTasklist.at(i)->get_name() == listname) {
                    cout << "Create Task:" << endl;
                    cout << "Title:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    title = stringInput;
                    cout << "Description:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    description = stringInput;
                    cout << "Classification:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    classification = stringInput;
                    cout << "Priority:" << endl;
                    cin >> intInput;
                    cout << endl;
                    priority = intInput;
                    cout << "Duration:" << endl;
                    cin >> intInput;
                    duration = intInput;
                    cout << endl;
                    cout << "Due Date:" << endl;
                    cin.ignore();
                    getline(cin, stringInput);
                    cout << endl;
                    dueDate = stringInput;
                    Task* newTask = new Task(title, description, classification, priority, duration, dueDate);
                    userTasklist.at(i)->insert_after(newTask, taskTitle, taskpriority);
                    newTask = nullptr;
                    list_exists = true;
                    break;
                }
            }
            if (list_exists == false) {
                cout << "No such list exists." << endl;
            }
        }
        else if (input == 'o') {
            cout << "Insert task based on priority:" << endl;
            cout << "Insert title of existing tasklist:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            listname = stringInput;
            cout << "Sorting list by priority first." << endl;
            for (int i = 0; i < userTasklist.size(); ++i) {
                if (userTasklist.at(i)->get_name() == listname) {
                    sortTasklistPriority(userTasklist.at(i)->get_tasks());
                    cout << "Create Task:" << endl;
                    cout << "Title:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    title = stringInput;
                    cout << "Description:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    description = stringInput;
                    cout << "Classification:" << endl;
                    getline(cin, stringInput);
                    cout << endl;
                    classification = stringInput;
                    cout << "Priority:" << endl;
                    cin >> intInput;
                    cout << endl;
                    priority = intInput;
                    cout << "Duration:" << endl;
                    cin >> intInput;
                    duration = intInput;
                    cout << endl;
                    cout << "Due Date:" << endl;
                    cin.ignore();
                    getline(cin, stringInput);
                    cout << endl;
                    dueDate = stringInput;
                    Task* newTask = new Task(title, description, classification, priority, duration, dueDate);
                    userTasklist.at(i)->insert_priority(newTask, priority);
                    newTask = nullptr;
                    list_exists = true;
                    break;
                }
            }
            if (list_exists == false) {
                cout << "No such list exists." << endl;
            }
        }
        else if (input == 'c') {
            cout << "Insert title of existing tasklist:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            cout << endl;
            tasklistLocation = -1;
            for (int i = 0; i < userTasklist.size(); ++i) {
                if (userTasklist.at(i)->get_name() == stringInput) {
                    tasklistLocation = i;
                }
            }
            if (tasklistLocation == -1) {
                cout << "Task does not exist." << endl;
            }
            else {
                cout << "Insert new title:" << endl;
                getline(cin, stringInput);
                cout << endl;
                userTasklist.at(tasklistLocation)->set_name(stringInput);
            }
        }
        else if (input == 'r') {
	cout << "Delete task from tasklist:" << endl;
            cout << "Insert title of existing tasklist:" << endl;
            cin.ignore();
            getline(cin, stringInput);
            listname = stringInput;
            cout << endl;
            for (int i = 0; i < userTasklist.size(); ++i) {
                if (userTasklist.at(i)->get_name() == listname) {
                    cout << "Delete Task:" << endl;
                    cout << "Insert title of existing task:" << endl;
                    cin.ignore();
                    getline(cin, stringInput);
                    cout << endl;
                    userTasklist.at(i)->remove_task(stringInput);
                       
                    }
                    cout << "Task Deleted!" << endl;
                    list_exists = true;
                }
            if (list_exists == false) {
                cout << "No such list exists." << endl;
            }
        }
        else if (input == 'p') {
            for (int i = 0; i < userTasklist.size(); ++i) {
                cout << userTasklist.at(i)->get_name() << ":" << endl;
                userTasklist.at(i)->print();
            }
            cout << endl;
        }
        else if (input != 'q') {
            cout << "Please input a valid character." << endl;
        }
    }
}

int main() {

    cout << "Welcome to Task Manager!" << endl;
    char userInput = '\0';
    vector<Task*>userTasks;
    vector<Tasklist*>userTasklists;
    while (userInput != 'q') {
        cout << "Press t for tasks, T for tasklists, or q to quit." << endl;
        cin >> userInput;
        cout << endl;

        if (userInput == 't') {
            taskInterface(userTasks);
        }

        else if (userInput == 'T') {
            tasklistInterface(userTasklists);
        }

        else if (userInput != 'q') {
            cout << "Please input a valid character." << endl;
        }
    }

    int i;
    for (i = 0; i < userTasks.size(); ++i) {
        delete userTasks.at(i);
    }
    for (i = 0; i < userTasklists.size(); ++i) {
        delete userTasklists.at(i);
    }
}

bool compTaskTitle(Task* lhs, Task* rhs) {
    return lhs->get_title() < rhs->get_title();
}
void sortTaskTitle(vector<Task*>& userTasks) {
    sort(userTasks.begin(), userTasks.end(), compTaskTitle);
}
bool sortPriority(Task* lhs, Task* rhs) {
    return lhs->get_priority() < rhs->get_priority();
}
void sortTaskPriority(vector<Task*>& userTasks) {
    sort(userTasks.begin(), userTasks.end(), sortPriority);
}
void sortTasklistPriority(vector<Task*> userTasks) {
    sort(userTasks.begin(), userTasks.end(), sortPriority);
}
