/*
 * function: FLDMMDL_BLACT_AddRes
 * address:  0x0219CB24
 * packet:   pkt_ov021_0219CB24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_BLACT_AddResSlot  0x0219D3F0  thumb  ov021
 *   FLDMMDL_BLACT_AddResIndex  0x0219CA40  thumb  ov021

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned short FLDMMDL_BLACT_AddResSlot(int *o, int a1, int a2, int a3, int a4, int a5);
extern void FLDMMDL_BLACT_AddResIndex(u8 *, u32, u32, u32);

void FLDMMDL_BLACT_AddRes(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1)
{
    int r = -1;
    u32 t;
    if (s1 & 2) r = 2;
    t = FLDMMDL_BLACT_AddResSlot((int *)o, b, c, s0, a, r);
    FLDMMDL_BLACT_AddResIndex(o + 0x14, b, t, (u16)s1);
}
