/*
 * function: func_021B7908
 * address: 0x021B7908
 * packet: pkt_ov173_021B7908
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two zero bytes at 0x021B7966 are alignment padding.
 * symbols:
 *   func_020275F8 0x020275F8 thumb
 *   func_021B78A0 0x021B78A0 thumb ov173
 */
#include "../include/Obj24181.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020275F8(u32);
extern void func_021B78A0(u32 a, int b, u32 c, u32 d, u16 heap);
void func_021B7908(char *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (*(u32 *)(p + i * 8 + 0x144) != 0) {
            func_021B78A0((u32)(((struct Obj24181 *)p)->f13C), (int)(*(void **)(p + i * 4 + 0x80)), func_020275F8((u8)*(u32 *)(p + i * 8 + 0x140)), 0, 0x4f);
            *(u32 *)(p + i * 8 + 0x144) = 0;
        }
    }
}
