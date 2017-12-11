# Notes

<!-- TOC depthFrom:2 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [Abstract Data Types -- Information Hiding](#abstract-data-types-information-hiding)

<!-- /TOC -->

- How object-oriented programming is done?
- What its techniques are?
- Why they help us solve bigger problems?
- How we harness generality and program to catch mistakes earlier?

## Abstract Data Types -- Information Hiding

A data type is abstract means that users don't know (or no need to know) its representation.

## Dynamic Linkage -- Generic Functions

### Constructors and Destructors

分配和回收内存的工作应该交给 `new` 和 `delete` 函数，但是初始化内存和回收内存之前的清理工作应该交给某种类型的对象自己去完成（through constructors and destructors），否则 `new` 和 `delete` 就要针对每一种类型做初始化和清理工作，显然缺乏灵活性。

观察 `delete` 的接口：

```c
void delete(void *item);
```

`delete` 要根据对象 `item` 找到它的类型，并且依此找到它的 destructor，但是 `delete` 又不能直接判断 `item` 的类型，否则丧失灵活性。因此每一个对象的起始部分默认是一个指向它的类型（type-descriptor）的指针。

### Dynamic Linkage

Dynamic linkage means that: while we call a method of arbitrary objects, the function that actually does the work is determined as late as possible -- during execution. See an example, [differ](src/ch02/Object.c).
