/*
 * function: func_021C1D74
 * address:  0x021C1D74
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_021C1E00.
 *
 * symbols:
 *   func_021C1E00  0x021C1E00  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C1E00(void *);

void func_021C1D74(u32 a0)
{
    func_021C1E00((void *)a0);
}
