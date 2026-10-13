/*
 * function: FIELD_MSGBG_DeleteSysFrameWindow
 * address:  0x02192BC0
 * packet:   pkt_02192BC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FIELD_MSGBG_ClearSysWindowFrame  0x02192B64  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FIELD_MSGBG_ClearSysWindowFrame(u32 a);
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);

void FIELD_MSGBG_DeleteSysFrameWindow(u8 *p)
{
    FIELD_MSGBG_ClearSysWindowFrame((u32)p);
    func_020452E8((struct Descriptor *)p);
}
