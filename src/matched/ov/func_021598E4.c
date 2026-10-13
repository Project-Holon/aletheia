/*
 * function: SCRIPT_WORK_CmdCallFieldCommand
 * address:  0x021598E4
 * packet:   pkt_021598E4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   SCRCMD_FLDMMDL_PauseMmdls  0x021B1BB8  thumb

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into SCRCMD_FLDMMDL_PauseMmdls, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_CmdCallFieldCommand.c \
 *       --func SCRIPT_WORK_CmdCallFieldCommand --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SCRCMD_FLDMMDL_PauseMmdls(int a, void *b);

int SCRIPT_WORK_CmdCallFieldCommand(int a0, void *a1)
{
    return SCRCMD_FLDMMDL_PauseMmdls(a0, a1);
}
