
#include <stdio.h>

#include <iostream>
#include <format>

#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

// ============================================================
// Test Declarations — implemented in tests.cpp
// ============================================================

// STAGE 0
void test_printLegacyData_int(void);
void test_printLegacyData_double(void);

// STAGE 1
void test_createTwoStructNodes_links_correctly(void);

// STAGE 2
void test_createTwoClassNodes_links_correctly(void);

// STAGE 3
void test_createTwoTemplateNodes_links_correctly(void);

// STAGE 4
void test_linkedList_addFirst_updates_counter(void);
void test_linkedList_addLast_places_at_end(void);
void test_linkedList_deleteValue_removes_variant(void);
void test_linkedList_destroyList_clears_all(void);
void test_linkedList_deleteFirst(void);
void test_linkedList_deleteLast(void);
void test_linkedList_printList(void);

// ============================================================
// Required by Unity Framework
// ============================================================
void setUp(void)    {}
void tearDown(void) {}

// ============================================================
// Main Test Runner
// ============================================================

// // int member named 'i'
// // double member named'd' 
// class Node{
//     public:    int value;
//     public:    Node * nextPtr;
// };

// template <typename T>
// class classNodeT{
//     public: T value;
//     public: classNodeT * classnodeT;
// };

int main(void) 
{
    // Node node;
    // node.value = 5;
    // node.nextPtr = NULL;

    // classNodeT<int> nodeT;
    // nodeT.value = 5;
    // classNodeT<std::string> nodeT2;

    // nodeT2.value = "hello world";
    // std::cout << nodeT.value << std::endl;
    // std::cout << nodeT.value << std::endl;


    UNITY_BEGIN();

    // ========== STAGE 0 ==========
    RUN_TEST(test_printLegacyData_int);
    RUN_TEST(test_printLegacyData_double);

    // ========== STAGE 1 ==========
    RUN_TEST(test_createTwoStructNodes_links_correctly);

    // ========== STAGE 2 ==========
    RUN_TEST(test_createTwoClassNodes_links_correctly);

    // ========== STAGE 3 ==========
    RUN_TEST(test_createTwoTemplateNodes_links_correctly);

    // ========== STAGE 4 ==========
    RUN_TEST(test_linkedList_addFirst_updates_counter);
    RUN_TEST(test_linkedList_addLast_places_at_end);
    RUN_TEST(test_linkedList_deleteValue_removes_variant);
    RUN_TEST(test_linkedList_destroyList_clears_all);
    RUN_TEST(test_linkedList_deleteFirst);
    RUN_TEST(test_linkedList_deleteLast);
    RUN_TEST(test_linkedList_printList);

    int result = UNITY_END();
    return result;
}