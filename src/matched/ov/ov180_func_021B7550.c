/*
 * function: func_021B7550
 * address:  0x021B7550
 * packet:   pkt_021B7550
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204AFD8  0x0204AFD8  arm
 */

typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);

void func_021B7550(char *p, int i)
{
    if (*(int *)(p + 0x9100 + i * 4) != -1) {
        func_0204AFD8(*(int *)(p + 0x9100 + i * 4));
        *(int *)(p + 0x9100 + i * 4) = -1;
    }
}
