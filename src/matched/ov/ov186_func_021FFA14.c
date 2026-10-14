/*
 * function: BR_NET_StepSearchKind1
 * address: 0x021FFA14
 * packet: pkt_ov186_021FFA14
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_RequestSearchKind1 0x021D6968 thumb ov125
 *   func_02034714 0x02034714 arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   BR_NET_StepWaitRequest 0x021FF8E4 thumb ov186
 *   gBrNetAssertString 0x02200D98 data a1
 */
extern int GDS_RAP_RequestSearchKind1(char *);extern void func_02034714(const char *,unsigned,const char *);extern void BR_NET_SetStep(char *,int);extern void BR_NET_StepWaitRequest(void *,int,int);extern const char gBrNetAssertString[];
void BR_NET_StepSearchKind1(char *p,int unused,char *q) {if(!GDS_RAP_RequestSearchKind1(q))func_02034714(gBrNetAssertString,0,gBrNetAssertString);BR_NET_SetStep(p,(int)BR_NET_StepWaitRequest);}
