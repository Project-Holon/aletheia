/*
 * function: func_021F9088
 * address:  0x021F9088
 * packet:   pkt_021F9088
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F90B8  0x021F90B8  thumb  ov135
 *

 *
 * Forward the u16 stack argument to func_021F90B8 with mode 1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_021F90B8(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow);

void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((u8 *)a, (void *)b, c, d, e, 1);
}
