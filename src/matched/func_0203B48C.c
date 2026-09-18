/*
 * function: func_0203B48C
 * address:  0x0203B48C
 * packet:   pkt_0203B48C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * The same +0x10 virtual call as func_0203B4DC, reporting at line 0x265
 * (613).  Both the first call argument and the reported line derive from the
 * single 1 that the function materialises, which is what makes the line come
 * out as `add r3, r5, #0x264`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B48C.c \
 *       --func func_0203B48C --addr 0x0203B48C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8  *func_0203D788(void);
extern void func_0203AD80(int a0, int a1, int a2, int a3);

void func_0203B48C(void)
{
    if (((u32 (*)(u32, u32))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x10))(1, 0) != 0)
        func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203B448, 0, 0x265);
}
