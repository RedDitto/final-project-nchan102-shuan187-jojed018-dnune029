#ifndef ___TASKLIST_HPP___
#define ___TASKLIST_HPP___
#include <iostream>
#include <string>
#include <vector>
#include "task.hpp"


using namespace std;


class Tasklist {
private:

	vector<Task*> tasklist;
	string listname;

public:
	Tasklist(vector<Task*>, string);
	~Tasklist();
	void set_name(string name);
	string get_name() const;
	vector<Task*> get_tasks() const;
	void add_task(string title, string description, string classification, int priority, int duration, string dueDate);
	void remove_task(string);
	void print();
	void insert_after(Task*, string, int);
	void insert_priority(Task*, int);
};
#endif
