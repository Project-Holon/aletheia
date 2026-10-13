/*
 * function: func_021A1480
 * address:  0x021A1480
 * packet:   pkt_ov021_021A1480
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   DOWSING_Create  0x021F000C  thumb  ov033
 *   abs_id_21      0x00000021  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_21[];
extern int func_02034AC4(int);
extern void *DOWSING_Create(u32 heap, u32 heap2, u32 a, u32 b);

void func_021A1480(u32 *p)
{
    func_02034AC4((int)abs_id_21);
    p[8] = (u32)DOWSING_Create(0x70, ((u16 *)p)[6], (u32)p, p[5]);
}
