/*
 * function: BSUBWAY_COMM_NetInit
 * address:  0x02167AB0
 * packet:   pkt_ov010_02167AB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to ARM GFL_NET_StartSession with (&d_02172014, 0, arg). No lr-saving
 * prologue; bl from ov021 BSUBWAY_SCR_CmdTool at 0x021CB4F4.
 *
 * symbols:
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   d_02172014  0x02172014  data  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern u8 d_02172014[];

void BSUBWAY_COMM_NetInit(void *p)
{
    GFL_NET_StartSession((struct Req *)d_02172014, 0, (u32)p);
}
