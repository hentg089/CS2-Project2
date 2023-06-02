// Created by markh on 2/9/2023 5814125.

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for the class ArrayBag.
 *
 *  Adapted from pages 101-111 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Mark Hentges
 *
 *  @date 23 Jan 2023
 *
 *  @version 7.0 */
#include <vector>
#include <iostream>

#include "ArrayBagWithReceipts.h"

//sets all values in the inUse array to false
template <typename ItemType>
ArrayBagWithReceipts<ItemType>::ArrayBagWithReceipts() {
    for(int i = 0; i < DEFAULT_CAPACITY; ++i){
        inUse[i] = false;
    }
}

//returns items count
template <typename ItemType>
int ArrayBagWithReceipts<ItemType>::getCurrentSize() const {
    return itemCount;
}

//checks if the array is empty
template <typename ItemType>
bool ArrayBagWithReceipts<ItemType>::isEmpty() const {
    return !itemCount; // itemCount == 0;
}

//add's items to the items array only if the inUse slots are not being taken up - increments count
template <typename ItemType>
int ArrayBagWithReceipts<ItemType>::add(const ItemType& newEntry) {
    for(int i = 0;i < DEFAULT_CAPACITY; ++i){
        if(inUse[i] == false){
            items[i] = newEntry;
            inUse[i] = true;
            itemCount++;
            return i;
        }
    }
    return -1;
}

//removes elements from the items array and decrements item count.  Essentially sets inUse indexes to false
template <typename ItemType>
ItemType ArrayBagWithReceipts<ItemType>::remove(const int itemReceipt) {
    inUse[itemReceipt] = false;
    itemCount--;
    return items[itemReceipt];
}

//sets all inUse values to false
template <typename ItemType>
void ArrayBagWithReceipts<ItemType>::clear() {
    for(int i = 0; i < DEFAULT_CAPACITY; ++i){
        inUse[i] = false;
    }
    itemCount = 0;
}

//loops through array to check if item is in items and if inUse is true
template <typename ItemType>
bool ArrayBagWithReceipts<ItemType>::contains(const ItemType& anEntry) const {

    int curIndex(0);

    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry && inUse[curIndex]) {
            return true;
        }
        ++curIndex;
    }

    return false;
}

//check to see how many items are equal to anEntry and if that part of the array is in use
template <typename ItemType>
int ArrayBagWithReceipts<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

    int frequency(0);
    int curIndex(0);

    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry && inUse[curIndex]) {
            ++frequency;
        }
        ++curIndex;
    }

    return frequency;
}

//returns a vector of all the items that are in use in the array
template <typename ItemType>
std::vector<ItemType> ArrayBagWithReceipts<ItemType>::toVector() const {

    std::vector<ItemType> bagContents;

    for (int i(0); i < DEFAULT_CAPACITY; ++i) {
        if(inUse[i])
        bagContents.push_back(items[i]);
    }

    return bagContents;
}
