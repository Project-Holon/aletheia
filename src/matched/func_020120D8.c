/*
 * function: func_020120D8
 * address:  0x020120D8
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern int func_020123C4(void *p);
int func_020120D8(char *p)
{
    if (func_020123C4(p))
        return 1;
    return *(unsigned char *)(p + 0x31);
}
