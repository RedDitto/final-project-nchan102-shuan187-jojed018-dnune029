#ifndef ___TASK_HPP___
#define ___TASK_HPP___

#include "base.hpp"
#include <string>

using namespace std;
class Task : public Base {
	public:
	Task() {
		title = "";
		description = "";
		classification = "";
		priority = 0;
		duration = 0;
		dueDate = "";
	}

	Task(string titl, string des, string clas, int prio, int dur, string due): Base() {
	title = titl;
	description = des;
	classification = clas;
	priority = prio;
	duration = dur;
	dueDate = due;
}
	void set_title(string title);
	void set_description(string description);
	void set_classification(string classification);
	void set_priority(int priority);
	void set_duration(int duration);
	void set_dueDate(string dueDate);
	string get_title() const;
	string get_description() const;
	string get_classification() const;
	int get_priority() const;
	int get_duration() const;
	string get_dueDate() const;
	void print();

	private:
	string title;
	string description;
	string classification;
	int priority;
	int duration;
	string dueDate;
};
#endif
