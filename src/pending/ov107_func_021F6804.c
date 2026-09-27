/*
 * function: MBi_SetChildMPMaxSize
 * address:  0x021F6804
 * packet:   pkt_ov107_021F6804
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_block.o).  decl_line 67.
 *
 * symbols:
 *   d_021F7008   0x021F7008  data
 *   _s32_div_f   0x0209C0A4  arm
 */
typedef unsigned short u16;
typedef int s32;

extern char d_021F7008[];

void MBi_SetChildMPMaxSize(u16 childMaxSize)
{
    s32 n = childMaxSize - 2;

    *(s32 *)(d_021F7008 + 8) = n;
    *(s32 *)(d_021F7008 + 0xC) = 0x1E / n;
    *(s32 *)(d_021F7008 + 0x10) = 0x1E;
}
