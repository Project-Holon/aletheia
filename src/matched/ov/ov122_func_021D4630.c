/*
 * function: INTRUDE_COMM_VIEW_InvokeCallback
 * address: 0x021D4630
 * packet: pkt_ov122_021D4630
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Fn)(int,u32 *);
void INTRUDE_COMM_VIEW_InvokeCallback(int a,int b,u32 *p) {if(b==0 && p[1]!=0) {if(((Fn)p[1])(a,p)==0)return;}}
