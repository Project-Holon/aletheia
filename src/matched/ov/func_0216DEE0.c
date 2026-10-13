/*
 * function: FLDMMDL_SysSearchPlayer
 * address:  0x0216DEE0
 * packet:   pkt_0216DEE0
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into FLDMMDL_SysSearchObjId, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_SysSearchPlayer.c \
 *       --func FLDMMDL_SysSearchPlayer --addr 0x0216DEE0 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_SysSearchObjId(void *, unsigned);

void *FLDMMDL_SysSearchPlayer(void *a0)
{
    return FLDMMDL_SysSearchObjId(a0, 255);
}
