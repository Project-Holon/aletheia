/*
 * function: func_020172BC
 * address:  0x020172BC
 * packet:   pkt_02017270
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172BC.c \
 *       --func func_020172BC --addr 0x020172BC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

extern void func_020172D8(u8 *a0, u32 a1);

u32 func_020172BC(u8 *a0, u8 **a1, u32 a2)
{
    if (*(u32 *)(a0 + 0x1c) == 0x1994) {
        func_020172D8((u8 *)(*(u32 *)(*a1 + 0x14)), a2);
    }
    return 1;
}
