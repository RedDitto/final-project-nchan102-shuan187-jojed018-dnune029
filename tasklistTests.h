#ifndef __TASKLISTTESTS_H__
#define __TASKLISTTESTS_H__
#include "tasklist.hpp"
#include "task.hpp"
#include "base.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "gtest/gtest.h"

using namespace std;

TEST(listConstructor, NameFnct) {

Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");
vector<Task*> testVec;
testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);

Tasklist* testList = new Tasklist(testVec, "Finals Week");

EXPECT_EQ(testList->get_name(), "Finals Week");

delete testList;
}



TEST(listConstructor, EmptyName) {

Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");
vector<Task*> testVec;
testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);

Tasklist* testList = new Tasklist(testVec, "");

EXPECT_EQ(testList->get_name(), "");
delete testList;

}


TEST(listConstructor, EmptyList) {

vector<Task*> testVec;

Tasklist* testList = new Tasklist(testVec, "");

EXPECT_EQ(testList->get_name(), "");
delete testList;

}



TEST(printlist, emptyList) {


vector<Task*> testVec;

Tasklist* testList = new Tasklist(testVec, "Finals Week");

testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(), "list is empty\n");
delete testList;

}





TEST(printTaskList, emptyVect) {

Task* test1 = new Task("", "", "",0, 0, "");
Task* test2 = new Task("", "", "",0 , 0, "");
Task* test3 = new Task("", "", "",0, 0, "");
vector<Task*> testVec;
testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);

Tasklist* testList = new Tasklist(testVec, "Finals Week");


testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(),"Task 1 Title: \nDescription: \nClassification: \nPriority: 0\nDuration: 0\nDueDate: \nTask 2 Title: \nDescription: \nClassification: \nPriority: 0\nDuration: 0\nDueDate: \nTask 3 Title: \nDescription: \nClassification: \nPriority: 0\nDuration: 0\nDueDate: \n");
delete testList;


}


TEST(printTaskList, twoTasks) {

Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",2, 2, "June 5th");
vector<Task*> testVec;
testVec.push_back(test1);
testVec.push_back(test2);

Tasklist* testList = new Tasklist(testVec, "Finals Week List");


testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(),"Task 1 Title: Finals\nDescription: Study for Finals\nClassification: School\nPriority: 1\nDuration: 10\nDueDate: June 10th\nTask 2 Title: Dishes and Sweep\nDescription: Clean Dishes and Sweep Floors\nClassification: Chores\nPriority: 2\nDuration: 2\nDueDate: June 5th\n");

delete testList;


}



TEST(removeTask, RemoveOne) {
Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",2, 2, "June 5th");
Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",3, 2, "June 6th");
vector<Task*> testVec;
testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);


Tasklist* testList = new Tasklist(testVec, "Finals WeekList");

testList->remove_task("Push Day");
testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(),"Task 1 Title: Finals\nDescription: Study for Finals\nClassification: School\nPriority: 1\nDuration: 10\nDueDate: June 10th\nTask 2 Title: Dishes and Sweep\nDescription: Clean Dishes and Sweep Floors\nClassification: Chores\nPriority: 2\nDuration: 2\nDueDate: June 5th\n");

delete testList;
}


/*
 *  * THIS TEST THROW AN OUT OF RANGE ERROR
 *   * TEST(removeTask, removeNonExist) {
 *    * Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
 *     * Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
 *      * Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");
 *       * vector<Task*> testVec;
 *        * testVec.push_back(test1);
 *         * testVec.push_back(test2);
 *          * testVec.push_back(test3);
 *           * Tasklist* testList = new Tasklist(testVec, "Finals WeekList");
 *            * testList->remove_task("Pull Day");
 *             * testing::internal::CaptureStdout();
 *              * testList->print();
 *               * EXPECT_EQ(testing::internal::GetCapturedStdout(),"Task 1 Title: Finals\nDescription: Study for Finals\nClassification: School\nPriority: 1\nDuration: 10\nDueDate: June 10th\nTask 2 Title: Dishes and Sweep\nDescription: Clean Dishes and Sweep Floors\nClassification: Chores\nPriority: 3\nDuration: 2\nDueDate: June 5th\nTask 3 Title: Push Day\nDescription: Hit Chest and Tris\nClassification: Exercise\nPriority: 2\nDuration: 2\nDueDate: June 6th\n");
 *                * }
 *                 * */




TEST(removeTask, removeAllTasks) {
vector<Task*> testVec;

Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");

testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);

Tasklist* testList = new Tasklist(testVec, "Finals WeekList");

testList->remove_task("Push Day");
testList->remove_task("Dishes and Sweep");
testList->remove_task("Finals");

testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(), "list is empty\n");
delete testList;
}



/*
 *  * TEST THREW OUT OF RANGE ERROR
 *   * TEST(removeTask, removeTaskonEmptyList) {
 *    * vector<Task*> testVec;
 *     * Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
 *      * Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
 *       * Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");
 *        * testVec.push_back(test1);
 *         * testVec.push_back(test2);
 *          * testVec.push_back(test3);
 *           * Tasklist* testList = new Tasklist(testVec, "Finals WeekList");
 *            * testList->remove_task("Push Day");
 *             * testList->remove_task("Dishes and Sweep");
 *              * testList->remove_task("Finals");
 *               * testList->remove_task("Finals");
 *                * testing::internal::CaptureStdout();
 *                 * testList->print();
 *                  * EXPECT_EQ(testing::internal::GetCapturedStdout(), "list is empty\n");
 *                   * }
 *                    * */

TEST(addTask, InsertTaskNorm) {
vector<Task*> testVec;

Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");

testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);

Tasklist* testList = new Tasklist(testVec, "Finals WeekList");

testList->add_task("Groceries", "Get Groceries","Errands", 4,1, "June 8th");

testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(), "Task 1 Title: Finals\nDescription: Study for Finals\nClassification: School\nPriority: 1\nDuration: 10\nDueDate: June 10th\nTask 2 Title: Dishes and Sweep\nDescription: Clean Dishes and Sweep Floors\nClassification: Chores\nPriority: 3\nDuration: 2\nDueDate: June 5th\nTask 3 Title: Push Day\nDescription: Hit Chest and Tris\nClassification: Exercise\nPriority: 2\nDuration: 2\nDueDate: June 6th\nTask 4 Title: Groceries\nDescription: Get Groceries\nClassification: Errands\nPriority: 4\nDuration: 1\nDueDate: June 8th\n");

delete testList;


}

TEST(addTask, InsertTaskEmpty) {
vector<Task*> testVec;



Tasklist* testList = new Tasklist(testVec, "Finals WeekList");

testList->add_task("Groceries", "Get Groceries","Errands", 4,1, "June 8th");

testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(), "Task 1 Title: Groceries\nDescription: Get Groceries\nClassification: Errands\nPriority: 4\nDuration: 1\nDueDate: June 8th\n");

delete testList;

}



TEST(InsertAfter, InsertTaskNorm) {
vector<Task*> testVec;

Task* test1 = new Task("Finals", "Study for Finals", "School",1, 10, "June 10th");
Task* test2 = new Task("Dishes and Sweep", "Clean Dishes and Sweep Floors", "Chores",3, 2, "June 5th");
Task* test3 = new Task("Push Day", "Hit Chest and Tris", "Exercise",2, 2, "June 6th");

testVec.push_back(test1);
testVec.push_back(test2);
testVec.push_back(test3);

Tasklist* testList = new Tasklist(testVec, "Finals WeekList");

Task* test4 = new Task("Groceries", "Get Groceries","Errands", 4,1, "June 8th");
testList->insert_after(test4, "Finals", 1);

testing::internal::CaptureStdout();
testList->print();
EXPECT_EQ(testing::internal::GetCapturedStdout(), "Task 1 Title: Finals\nDescription: Study for Finals\nClassification: School\nPriority: 1\nDuration: 10\nDueDate: June 10th\nTask 2 Title: Groceries\nDescription: Get Groceries\nClassification: Errands\nPriority: 4\nDuration: 1\nDueDate: June 8th\nTask 3 Title: Dishes and Sweep\nDescription: Clean Dishes and Sweep Floors\nClassification: Chores\nPriority: 3\nDuration: 2\nDueDate: June 5th\nTask 4 Title: Push Day\nDescription: Hit Chest and Tris\nClassification: Exercise\nPriority: 2\nDuration: 2\nDueDate: June 6th\n");

delete testList;
}


#endif
