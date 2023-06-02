// Created by markh on 2/9/2023 5814125.

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for an array-based implementation of the ADT bag.
 *
 *  Adapted from page 100 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Mark Hentges
 *
 *  @date 9 feb 2023
 *
 *  @version 7.0 */

#ifndef ARRAY_BAG_WITH_RECEIPTS_
#define ARRAY_BAG_WITH_RECEIPTS_

#include <vector>

#include "BagWithReceiptsInterface.h"

/** @class ArrayBag ArrayBag.h "ArrayBag.h"
 *
 *  Specification of an array-based ADT bag. */
template <typename ItemType>
class ArrayBagWithReceipts : public BagWithReceiptsInterface<ItemType> {
private:
    /** Maximum capacity of this bag. */
    static const int DEFAULT_CAPACITY = 6;

    /** Data storage. */
    ItemType items[DEFAULT_CAPACITY];
    bool inUse[DEFAULT_CAPACITY];

    /** Number of items in this bag. */
    int itemCount = 0;

    /** Maximum capacity of this bag. */
    int maxItems = DEFAULT_CAPACITY;

public:
    /** Default constructor. */
    ArrayBagWithReceipts();

    /** Virtual destructor. */
    virtual ~ArrayBagWithReceipts() = default;

    virtual int getCurrentSize() const;

    virtual bool isEmpty() const;

    virtual int add(const ItemType& newEntry);

    virtual ItemType remove(const int itemReceipt);

    virtual void clear();

    virtual int getFrequencyOf(const ItemType& anEntry) const;

    virtual bool contains(const ItemType& anEntry) const;

    virtual std::vector<ItemType> toVector() const;
};


#endif