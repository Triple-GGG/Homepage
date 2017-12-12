# Annotation

<!-- TOC depthFrom:2 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [Chapter 1 Building Abstractions with Procedures](#chapter-1-building-abstractions-with-procedures)
	- [1.1 The Elements of Programming](#11-the-elements-of-programming)
		- [1.1.2 Naming and the Environment](#112-naming-and-the-environment)

<!-- /TOC -->

## Chapter 1 Building Abstractions with Procedures

### 1.1 The Elements of Programming

#### 1.1.2 Naming and the Environment

`(define size 2)` means that the interpreter associates the value `2` with the name `size`. For associating names with values and later retrieving them, the interpreter must maintain a memory section to keep information. This memory is called *environment* (more precisely the *global environment*).
