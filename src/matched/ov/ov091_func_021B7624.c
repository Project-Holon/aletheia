/*
 * function: func_021B7624
 * address:  0x021B7624
 * packet:   pkt_ov091_021B7624
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 */

typedef unsigned char u8;

extern void func_020307B0(void *);
extern void func_0204ADA4(int);
extern void func_0204A8D4(int);
extern void func_0204AFD8(int);

void func_021B7624(char *p)
{
    u8 i;

    func_020307B0(*(void **)(p + 0x158));
    for (i = 0; i < 8; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204ADA4(*(int *)(p + i * 4 + 0x178));
    }
    for (i = 8; i < 15; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204A8D4(*(int *)(p + i * 4 + 0x178));
    }
    for (i = 15; i < 23; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204AFD8(*(int *)(p + i * 4 + 0x178));
    }
}
