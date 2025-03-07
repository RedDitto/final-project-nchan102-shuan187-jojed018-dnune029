#include "task.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Task::set_title(string title) {
this->title = title;
}

void Task::set_description(string description) {
this->description = description;
}

void Task::set_classification(string classification) {
this->classification = classification;
}

void Task::set_priority(int priority) {
this->priority = priority;
}

void Task::set_duration(int duration){
this->duration = duration;
}

void Task::set_dueDate(string dueDate) {
this->dueDate = dueDate;
}

string Task::get_title() const {
return title;
}
string Task::get_description() const {
return description;
}

string Task::get_classification() const {
return classification;
}

int Task::get_priority() const {
return priority;
}

int Task::get_duration() const{
return duration;
}

string Task::get_dueDate() const{
return dueDate;
}

void Task::print() {
cout<<"Task Title: "<< title<<endl;
cout<<"Description: "<< description<<endl;
cout<<"Classification: "<< classification<<endl;
cout<<"Priority: "<< priority<<endl;
cout<<"Duration: "<< duration<<endl;
cout<<"DueDate: "<< dueDate<<endl;
}

