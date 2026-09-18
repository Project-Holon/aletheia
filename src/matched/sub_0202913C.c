/*
 * function: func_0202913C
 * address:  0x0202913C
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02029344  0x02029344  thumb
 */

typedef unsigned int u32;

extern void sub_02029344(void *obj, u32 value);

void func_0202913C(void *obj)
{
    switch (*(u32 *)((char *)obj + 0x1c)) {
    case 0:
    case 5:
        break;
    case 3:
        sub_02029344(obj, 11);
        break;
    }
}
