#ifndef __TASKS__HPP__
#define __TASKS__HPP__
#include "gtest/gtest.h"
#include "task.hpp"
#include "tasklist.hpp"
#include "base.hpp"
#include <iostream>


TEST(TASKTEST, CONSTRUCTOR){
Task* test = new Task("Shopping","Shopping description","classification",2,3,"August");
EXPECT_EQ(test->get_title(),"Shopping");
delete test;
}

TEST(TASKTEST2, CONSTRUCTORS){
Task* test = new Task("Shopping","Shopping description","classification",2,3,"August");
EXPECT_EQ(test->get_title(),"Shopping");
EXPECT_EQ(test->get_description(),"Shopping description");
EXPECT_EQ(test->get_classification(),"classification");
EXPECT_EQ(test->get_priority(),2);
EXPECT_EQ(test->get_duration(),3);
EXPECT_EQ(test->get_dueDate(),"August");
delete test;
}

TEST(TASKTEST10, PRINT){
Task* test = new Task("Shopping","Shopping description","classification",2,3,"August");
testing::internal::CaptureStdout();
test->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(),"Task Title: Shopping\nDescription: Shopping description\nClassification: classification\nPriority: 2\nDuration: 3\nDueDate: August\n");
delete test;
}


TEST(TASKTEST11, PRINTNOTHING){
Task* test = new Task("","","",0,0,"");
testing::internal::CaptureStdout();
test->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(),"Task Title: \nDescription: \nClassification: \nPriority: 0\nDuration: 0\nDueDate: \n");
delete test;
}




TEST(TASKTEST3, CONSTRUCTORS){
Task* test = new Task("","","",2,3,"");
EXPECT_EQ(test->get_title(),"");
EXPECT_EQ(test->get_description(),"");
EXPECT_EQ(test->get_classification(),"");
EXPECT_EQ(test->get_priority(),2);
EXPECT_EQ(test->get_duration(),3);
EXPECT_EQ(test->get_dueDate(),"");
delete test;
}

TEST(TASKTEST4, CONSTRUCTORS){
Task* test = new Task("","","",0,0,"");
EXPECT_EQ(test->get_title(),"");
EXPECT_EQ(test->get_description(),"");
EXPECT_EQ(test->get_classification(),"");
EXPECT_EQ(test->get_priority(),0);
EXPECT_EQ(test->get_duration(),0);
EXPECT_EQ(test->get_dueDate(),"");
delete test;
}


TEST(TASKTEST5, SETGET){
Task* test = new Task("","","",2,3,"");
test->set_title("title");
EXPECT_EQ(test->get_title(),"title");
delete test;
}

TEST(TASKTEST6, SETGET){
Task* test = new Task("","","",2,3,"");
test->set_title("title");
test->set_description("random description");
EXPECT_EQ(test->get_title(),"title");
EXPECT_EQ(test->get_description(),"random description");
delete test;
}

TEST(TASKTEST7, SETGET){
Task* test = new Task("","","",2,3,"");
test->set_title("title");
test->set_description("random description");
test->set_classification("random classification");
test->set_priority(10);
test->set_duration(100);
test->set_dueDate("september");
EXPECT_EQ(test->get_title(),"title");
EXPECT_EQ(test->get_description(),"random description");
EXPECT_EQ(test->get_classification(),"random classification");
EXPECT_EQ(test->get_priority(),10);
EXPECT_EQ(test->get_duration(),100);
EXPECT_EQ(test->get_dueDate(),"september");
delete test;
}

#endif
