# Notes



## Lexical Analysis

### Input Buffering

Sometimes for recognizing an lexeme, we need to look ahead one or more characters, that requires input buffering techniques. For example, we can use two buffers. When the `forward` pointer is at the end of the first buffer, the second buffer is reloaded and let `forward` points to the beginning of second buffer; vice versa.
