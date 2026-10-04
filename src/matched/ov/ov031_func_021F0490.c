/*
 * function: func_021F0490
 * address:  0x021F0490
 * packet:   pkt_ov031_021F0490
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);

void func_021F0490(char *p, u32 heap)
{
    *(u32 *)(p + 0xC) = func_0204AC18((void *)heap, 0x13, 1, 0, 0, 3, 0x15);
    *(u32 *)(p + 8) = func_0204A6C8((void *)heap, 0xE, 0, 1, 0x15);
    *(u32 *)(p + 0x10) = func_0204AF28((void *)heap, 0xC, 0xD, 0x15);
}
