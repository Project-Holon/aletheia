/*
 * function: func_021F7108
 * address:  0x021F7108
 * packet:   pkt_ov097_021F7108
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 */

extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
extern void func_0204AFD8(int);

void func_021F7108(char *p)
{
    unsigned i;

    for (i = 0; i < 9; i++)
        func_0204A8D4(*(int *)(p + i * 4 + 0xb4));
    for (i = 0; i < 4; i++)
        func_0204ADA4(*(int *)(p + i * 4 + 0xd8));
    for (i = 0; i < 4; i++)
        func_0204AFD8(*(int *)(p + i * 4 + 0xe8));
}
