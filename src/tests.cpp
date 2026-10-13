#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <sstream>
#include <iostream>

// ============================================================
// STAGE 0 Tests
// ============================================================

/// Create a LegacyData union with an int (42). Call printLegacyData.
/// Verify the returned string matches "42".
void test_printLegacyData_int(void) 
{
    LegacyData(42);
}

/// Create a LegacyData union with a double (3.14). Call printLegacyData.
/// Verify the returned string matches "3.14".
void test_printLegacyData_double(void) 
{
    LegacyData(3.14);
}

// ============================================================
// STAGE 1 Tests
// ============================================================

/// Call createTwoStructNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoStructNodes_links_correctly(void)
{
    structNode* LinkedNodes = createTwoStructNodes();
    TEST_ASSERT_EQUAL(5, LinkedNodes);
    TEST_ASSERT_EQUAL(3.14, LinkedNodes);
    delete &LinkedNodes;
}

// ============================================================
// STAGE 2 Tests
// ============================================================

/// Call createTwoClassNodes().
/// Verify head->value contains int 5 with type 'i', and head->nextPtr->value contains double ~3.14 with type 'd'.
/// Clean up allocated memory.
void test_createTwoClassNodes_links_correctly(void) 
{
    classNodeT Node1 = createTwoClassNodes();
    classNodeT Node2 = createTwoClassNodes();

    TEST_ASSERT_EQUAL(5, &Node1);
    TEST_ASSERT_EQUAL(5, &Node2);

    delete &Node1;
    delete &Node2;
}

// ============================================================
// STAGE 3 Tests
// ============================================================

/// Call createTwoTemplateNodes().
/// Verify head->value is 5 and head->nextPtr->value is 3.
/// Clean up allocated memory.
void test_createTwoTemplateNodes_links_correctly(void) 
{
    classNodeT Node1 = createTwoTemplateNodes();
    classNodeT Node2 = createTwoTemplateNodes();
    
    TEST_ASSERT_EQUAL(5, &Node1);
    TEST_ASSERT_EQUAL(3, &Node2);

    delete &Node1;
    delete &Node2;
}

// ============================================================
// STAGE 4: LinkedList Tests
// ============================================================

/// Create a LinkedList. Add two nodes using addFirst.
/// Verify listLength() returns 2 after insertions.
void test_linkedList_addFirst_updates_counter(void) 
{
    LinkedList list;
    list.addFirst(new classNodeVariant(10));
    list.addLast(new classNodeVariant(20));

    TEST_ASSERT_EQUAL(2, list.listLength());
    list.destroyList();
}

/// Create a LinkedList. Add nodes (10, then 20) using addLast.
/// Capture std::cout and verify elements appear in order ("10" before "20").
void test_linkedList_addLast_places_at_end(void) 
{
    LinkedList list;
    list.addLast(new classNodeVariant(10));
    list.addLast(new classNodeVariant(20));

    std::cout << list.printList() << std::endl;
    TEST_ASSERT_EQUAL(10, list.printList());
    TEST_ASSERT_EQUAL(20, list.printList());
    list.destroyList();
}

/// Create a LinkedList with an int, double, and string.
/// Call deleteValue() with the double value (3.14).
/// Verify list length decreases to 2 and second call returns -1.
void test_linkedList_deleteValue_removes_variant(void) 
{
    LinkedList list;
    list.addFirst  (new classNodeVariant(5));
    list.addLast   (new classNodeVariant(3.14));
    list.addLast   (new classNodeVariant("test"));

    list.deleteValue(3.14);

    TEST_ASSERT_EQUAL(2, list.listLength());
    TEST_ASSERT_EQUAL(-1, list.deleteValue(3.14));
}

/// Create a LinkedList and insert three nodes.
/// Call destroyList().
/// Verify listLength() becomes 0.
void test_linkedList_destroyList_clears_all(void) 
{
    LinkedList list;
    list.addFirst(new classNodeVariant(10));
    list.addLast(new classNodeVariant(20));
    list.addLast(new classNodeVariant(30));

    list.destroyList();

    TEST_ASSERT_EQUAL(0, list.listLength());
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteFirst().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteFirst(void) 
{
    LinkedList list;
    list.addFirst(new classNodeVariant(10));
    list.addLast(new classNodeVariant(20));
    list.addLast(new classNodeVariant(30));

    list.deleteFirst();
    TEST_ASSERT_EQUAL(2, list.listLength());
    TEST_ASSERT_EQUAL(0, list.deleteFirst());
}

/// Create a LinkedList with nodes (10, 20, 30).
/// Call deleteLast().
/// Verify listLength() becomes 2 and operation returns 0.
void test_linkedList_deleteLast(void) 
{
    LinkedList list;
    list.addFirst(new classNodeVariant(10));
    list.addLast(new classNodeVariant(20));
    list.addLast(new classNodeVariant(30));

    list.deleteLast();
    TEST_ASSERT_EQUAL(2, list.listLength());
    TEST_ASSERT_EQUAL(0, list.deleteLast());
}

/// Create a LinkedList with nodes (1, 2.5, "test").
/// Redirect std::cout buffer and call printList().
/// Verify printed output contains "1", "2.5" (or "2.50"), and "test".
void test_linkedList_printList(void) 
{
    LinkedList list;
    list.addFirst(new classNodeVariant(1));
    list.addLast(new classNodeVariant(2.5));
    list.addLast(new classNodeVariant("test"));

    std::cout << list.printList() << std::endl;
    TEST_ASSERT_TRUE_MESSAGE(0, "TODO: Implement this test");
}
