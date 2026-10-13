/*
 * function: MUSICAL_DRESSUP_SYS_Delete
 * address:  0x02156CD8
 * packet:   pkt_02156CD8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MUSICAL_DRESSUP_SYS_Delete.c \
 *       --func MUSICAL_DRESSUP_SYS_Delete --addr 0x02156CD8 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020307B0(void *p);

void MUSICAL_DRESSUP_SYS_Delete(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}
