/*
 * function: FLDMMDL_OnMoveBitMoveStart
 * address:  0x0216DA70
 * packet:   pkt_0216DA70
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into FLDMMDL_SetMoveBit, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_OnMoveBitMoveStart.c \
 *       --func FLDMMDL_OnMoveBitMoveStart --addr 0x0216DA70 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

void FLDMMDL_OnMoveBitMoveStart(void *a0)
{

    FLDMMDL_SetMoveBit(a0, 32);
}
