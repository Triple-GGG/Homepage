/**
 * Time: O(m * n), where m, n are the lengths of s and t respectively.
 */
int strindex(const char *s, const char *t) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
