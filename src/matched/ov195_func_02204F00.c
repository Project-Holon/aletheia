/*
 * function: func_02204F00
 * address:  0x02204F00
 * packet:   pkt_02204F00
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020063B4 0x020063B4 thumb
 */

extern void func_020063B4(void *, void *, int);

void func_02204F00(int unused, char *p)
{
    if (*(int *)(p + 0x30) == 0)
    {
        *(int *)(p + 0x34) = 0;
        func_020063B4((void *)0x3f3, p + 0x34, 1);
        *(int *)(p + 0x30) = 3;
    }
}
