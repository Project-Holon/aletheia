/*
 * function: func_02193418
 * address:  0x02193418
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiValueForKey: locate `key` in `command` with strstr, skip the key text
 * with strlen, then copy up to valueLen-1 characters into `value`, stopping
 * at NUL or at the key's first character (the '\\' delimiter).  Returns 1
 * when the key was found, 0 otherwise.
 *
 * The delimiter is read once at entry.  The loop character must be bound to
 * a named local inside the condition (`(c = p[i]) != '\0'`), otherwise this
 * compiler puts the register delimiter in `cmp`'s first slot instead of the
 * freshly loaded byte and the function is one instruction off.
 *
 * symbols:
 *   func_02094B20  0x02094B20  arm
 *   func_0209477C  0x0209477C  arm
 */

extern int func_02094B20(const char *s1, const char *s2);
extern int func_0209477C(const char *s);

int func_02193418(const char *command, const char *key, char *value, int valueLen)
{
    char *p;
    int i;
    char keychar = key[0];
    char c;

    p = (char *)func_02094B20(command, key);
    if (p == 0)
        return 0;
    p += func_0209477C(key);
    i = 0;
    while ((i < valueLen - 1) && ((c = p[i]) != '\0') && (c != keychar)) {
        value[i] = c;
        i++;
    }
    value[i] = '\0';
    return 1;
}
