/*
 * function: BR_NET_StepSearchKind2
 * address: 0x021FFA6C
 * packet: pkt_ov186_021FFA6C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_RequestSearchKind2 0x021D698C thumb ov125
 *   func_02034714 0x02034714 arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   BR_NET_StepWaitRequest 0x021FF8E4 thumb ov186
 *   gBrNetAssertString 0x02200D98 data a1
 */
extern int GDS_RAP_RequestSearchKind2(char *);extern void func_02034714(const char *,unsigned,const char *);extern void BR_NET_SetStep(char *,int);extern void BR_NET_StepWaitRequest(void *,int,int);extern const char gBrNetAssertString[];
void BR_NET_StepSearchKind2(char *p,int unused,char *q) {if(!GDS_RAP_RequestSearchKind2(q))func_02034714(gBrNetAssertString,0,gBrNetAssertString);BR_NET_SetStep(p,(int)BR_NET_StepWaitRequest);}
