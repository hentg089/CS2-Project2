// Created by markh on 2/9/2023 5814125.

#include <iostream>
#include <string>

#include "ArrayBagWithReceipts.cpp"

template <typename ItemType>
void testAdd1(ArrayBagWithReceipts<ItemType>& arr, ItemType it1, ItemType it2, ItemType it3, ItemType it4, ItemType it5, ItemType it6) {
    std::cout << "The receipts associated with each item we add:" << std::endl;
    std::cout << arr.add(it1) << std::endl;
    std::cout << arr.add(it2) << std::endl;
    std::cout << arr.add(it3) << std::endl;
    std::cout << arr.add(it4) << std::endl;
    std::cout << arr.add(it5) << std::endl;
    std::cout << arr.add(it6) << std::endl;
}

template <typename ItemType>
void testItemsAddedSoFar(ArrayBagWithReceipts<ItemType>& arr){
    std::cout << "Currents items in the bag:" << std::endl;
    std::vector<ItemType> v = arr.toVector();
    for(ItemType i : v){
        std::cout << i << std::endl;
    }
}

template <typename ItemType>
void testBagSize(ArrayBagWithReceipts<ItemType>& arr){
    std::cout << "Our bag size so far: " << std::endl;
    std::cout << arr.getCurrentSize() << std::endl;
}

template <typename ItemType>
void testContainsItems(ArrayBagWithReceipts<ItemType>& arr, ItemType it1, ItemType it2, ItemType it3){
    std::cout << "Does our bag contain these items?: (1:yes | 0:no)" << std::endl;
    std::cout << arr.contains(it1) << std::endl;
    std::cout << arr.contains(it2) << std::endl;
    std::cout << arr.contains(it3) << std::endl;

}

template <typename ItemType>
void remove1Items(ArrayBagWithReceipts<ItemType>& arr, int receipt1){
    std::cout << "lets remove some items and print out which ones we removed after theyre removed:" << std::endl;
    std::cout << arr.remove(receipt1) << std::endl;

}

template <typename ItemType>
void clearbagTest(ArrayBagWithReceipts<ItemType>& arr){
    std::cout << "Lets run the clear method now: " << std::endl;
    arr.clear();
}

template <typename ItemType>
void frequencyTest(ArrayBagWithReceipts<ItemType>& arr, ItemType it1,ItemType it2,ItemType it3){
    std::cout << "frequency of each item in our bag in order of which they are passed in" << std::endl;
    std::cout << arr.getFrequencyOf(it1) << std::endl;
    std::cout << arr.getFrequencyOf(it2) << std::endl;
    std::cout << arr.getFrequencyOf(it3) << std::endl;
}

template <typename ItemType>
void isEmptyTest(ArrayBagWithReceipts<ItemType>& arr){
    if(arr.isEmpty()){
        std::cout << "bag is empty" << std::endl;
    }else{
        std::cout << "bag is not empty" << std::endl;
    }
}


int main() {
    ArrayBagWithReceipts<int> arr; //declaring new array
    testAdd1(arr, 190, 909, 420, 1, -10000, -43); //calling funciton that will put values into the array
    testItemsAddedSoFar(arr); //function call to print out added items
    testBagSize(arr); //function to print out the items
    testContainsItems(arr, 909, -10001, -10000); //funciton call to check if items are in the bag
    remove1Items(arr, 5); //function that will remove some items from our array
    testBagSize(arr); //function call to print out our bag size
    testItemsAddedSoFar(arr); //print our items added again
    clearbagTest(arr); //clear the bag
    testBagSize(arr); //print out bag size
    testAdd1(arr,190, -17,-17,190,1,190); //add items again
    testItemsAddedSoFar(arr); //print out added items
    frequencyTest(arr, 190, -17, 0); //get frequency of our added items
    isEmptyTest(arr); //check if the bag si empty
    clearbagTest(arr);
    isEmptyTest(arr); //check if the bag si empty


    std::cout << "now i'll remove an item from the middel of the array and"
                 " then proceed to add another item to show that the receipt will be recycled\n" << std::endl ;
    testAdd1(arr,190, -17,-17,190,1,190); //add items again

    std::cout << arr.remove(3) << " entry 3 removed" << std::endl; //can reuse receipts
    std::cout << arr.add(189) << " is the receit for the entry" << std::endl; //can reuse receipts

    ArrayBagWithReceipts<double> arr2; //array bag with doubles
    testAdd1(arr2, 0.3, .3534,.34354,.020,.839,90.3);
    testItemsAddedSoFar(arr2);

    return 0;
}
