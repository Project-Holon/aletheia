/*
 * function: GURU2_COMM_Send
 * address: 0x021DCBC4
 * packet: pkt_ov137_021DCBC4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_SendWithHeader 0x021DCB94 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void GURU2_COMM_SendWithHeader(u8 *p, u32 id, const void *data, u32 size);
void GURU2_COMM_Send(void *p,u32 a,const void *b,u32 c) {GURU2_COMM_SendWithHeader(p,a,b,c);}
