/*
 * function: func_0200ACD0
 * address:  0x0200ACD0
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

char *func_0200ACD0(char *base, int count, int target)
{
    int i;
    for (i = 0; i < count; i++) {
        char *e = base + i * 0x1c;
        if (target == *(int *)(e + 0x14)) {
            if ((*(unsigned int *)(e + 0x10) >> 31) == 1)
                return e;
        }
    }
    return 0;
}
