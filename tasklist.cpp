#include <iostream>
#include "tasklist.hpp"
#include <string>
#include <vector>

using namespace std;

Tasklist::Tasklist(vector<Task*> tasks, string name) {
	tasklist = tasks;
	listname = name;
}

Tasklist::~Tasklist() {
	for (int i = 0; i < tasklist.size(); ++i) {
		delete tasklist.at(i);
	}
}

void Tasklist::set_name(string name) {
	listname = name;
}

string Tasklist::get_name() const {
	return listname;
}
vector<Task*> Tasklist::get_tasks() const {
	return tasklist;
}

void Tasklist::add_task(string title, string description, string classification, int priority, int duration, string dueDate) {
	Task* currTask = new Task(title, description, classification, priority, duration, dueDate);
	tasklist.push_back(currTask);
}

void Tasklist::insert_after(Task* task, string title, int priority) {
	if (tasklist.empty()) {
		tasklist.push_back(task);
	}
	else {
		for (int i = 0; i < tasklist.size(); ++i) {
			if (tasklist.at(i)->get_title() == title && tasklist.at(i)->get_priority() == priority) {
				tasklist.insert(tasklist.begin() + i + 1, task);
				break;
			}
		}
	}
}

void Tasklist::insert_priority(Task* task, int priority) {
    int loc = -1;
    if (tasklist.empty()) {
        tasklist.push_back(task);
    }
    else {
        for (int i = 0; i < tasklist.size(); ++i) {
            if (tasklist.at(i)->get_priority() <= priority) {
                loc++;
            }
            else if (tasklist.at(i)->get_priority() > priority) {
                if (tasklist.at(i) == tasklist.back()) {
                    tasklist.push_back(task);
                    return;
                }
                tasklist.insert(tasklist.begin() + i + 1, task);
                swap(tasklist.at(i), tasklist.at(i + 1));
                return;
            }
        }
        tasklist.insert(tasklist.begin() + loc + 1, task);
   }
}

void Tasklist::remove_task(string title) {
	int count = 0;
	
	for(int i = 0; i < tasklist.size(); ++i){
	if(tasklist.at(i)->get_title() == title){
	count = i;
}
}
	delete tasklist.at(count);
	tasklist.erase(tasklist.begin() + count);
}

void Tasklist::print() {
	if (tasklist.empty()) {
		cout << "list is empty" << endl;
	}
	for (int i = 0; i < tasklist.size(); ++i) {
		cout << "Task " << i + 1 << " Title: " << tasklist.at(i)->get_title() << endl;
		cout << "Description: " << tasklist.at(i)->get_description() << endl;
		cout << "Classification: " << tasklist.at(i)->get_classification() << endl;
		cout << "Priority: " << tasklist.at(i)->get_priority() << endl;
		cout << "Duration: " << tasklist.at(i)->get_duration() << endl;
		cout << "DueDate: " << tasklist.at(i)->get_dueDate() << endl;
	}

}
