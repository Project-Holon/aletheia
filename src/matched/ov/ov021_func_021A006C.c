/*
 * function: FLDMMDL_DRAW_InitBlactId
 * address:  0x021A006C
 * packet:   pkt_ov021_021A006C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitDrawProcWork  0x0216D6D8  thumb  ov010
 *   FLDMMDL_G3DOBJ_AddObj  0x0219D634  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_InitDrawProcWork(int a0, int a1);
extern u32 FLDMMDL_G3DOBJ_AddObj(u32 a);

void FLDMMDL_DRAW_InitBlactId(u32 a)
{
    u16 *q = (u16 *)FLDMMDL_InitDrawProcWork(a, 2);
    *q = FLDMMDL_G3DOBJ_AddObj(a);
}
