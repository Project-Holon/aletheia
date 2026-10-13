/*
 * function: BTL_SERVER_CMD_ReadU32
 * address: 0x021CCBE8
 * packet: pkt_ov093_021CCBE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8; typedef unsigned int u32;
typedef struct { u32 wpos,rpos; u8 buf[3000]; } Buf;
u32 BTL_SERVER_CMD_ReadU32(Buf *p) {u32 v;u8 *q;q=(u8*)p+p->rpos;v=((u32)q[8]<<24)|((u32)q[9]<<16)|((u32)q[10]<<8)|q[11];p->rpos+=4;return v;}
