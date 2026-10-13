/*
 * function: SCRIPT_WORK_CheckFlag
 * address:  0x02159190
 * packet:   pkt_02159190
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   SCRIPT_WORK_IsCheckFlagSet  0x02159198  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into SCRIPT_WORK_IsCheckFlagSet, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_CheckFlag.c \
 *       --func SCRIPT_WORK_CheckFlag --addr 0x02159190 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRIPT_WORK_IsCheckFlagSet(int);

int SCRIPT_WORK_CheckFlag(int a0)
{

    return SCRIPT_WORK_IsCheckFlagSet(a0);
}
