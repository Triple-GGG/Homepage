# Notes

<!-- TOC depthFrom:2 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [Key Qualities](#key-qualities)

<!-- /TOC -->

> The primary goal of Kotlin is to provide a more concise, more productive, safer alternative to Java that's suitable in all contexts where Java is used today.

Areas to use Kotlin:

- Building server-side code (backends of web applications)
- Building mobile applications that run on Android devices
- Using the [Intel Multi-OS Engine](https://software.intel.com/en-us/multi-os-engine) to run Kotlin on iOS
- Using Kotlin together with [JavaFX](https://docs.oracle.com/javase/8/javafx/get-started-tutorial/jfx-overview.htm) to build desktop applications

## Key Qualities

- Statically typed

    Benefits of static typing:

    - *Performance* -- Calling methods is faster because there's no need to figure out at runtime which method needs to be called.
    - *Reliability* -- The compiler verifies the correctness of the program, so there are fewer chances for craches at runtime.
    - *Maintainability* -- Working with unfamiliar code is easier because you can see what kind of objects the code is working with. (Very useful when reading code written by other guys)
    - *Tool support* -- Static typing enables reliable refactorings, precise code completion, and other IDE features.
