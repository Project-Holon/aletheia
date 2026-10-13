/*
 * function: FLDMMDL_MOVE_AttrEffectReflectOff
 * address:  0x0216369C
 * packet:   pkt_0216369C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FLDMMDL_SetMoveBitSplash  0x0216DBCC  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into FLDMMDL_SetMoveBitSplash, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_MOVE_AttrEffectReflectOff.c \
 *       --func FLDMMDL_MOVE_AttrEffectReflectOff --addr 0x0216369C --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_SetMoveBitSplash(void *a0, u32 a1, int a2);

void FLDMMDL_MOVE_AttrEffectReflectOff(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    FLDMMDL_SetMoveBitSplash(a0, 0, a2);
}
