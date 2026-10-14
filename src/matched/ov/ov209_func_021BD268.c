/*
 * function: ZUKAN_LIST_StateFadeOut
 * address: 0x021BD268
 * packet: pkt_ov209_021BD268
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_RequestFade 0x021BC730 thumb ov209
 *   ZUKAN_LIST_StartActorMoveFrames 0x021BC90C thumb ov209
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void ZUKAN_LIST_RequestFade(char *,u8,u8),ZUKAN_LIST_StartActorMoveFrames(char *,int);
int ZUKAN_LIST_StateFadeOut(char *p) { ZUKAN_LIST_RequestFade(p,0,16);ZUKAN_LIST_StartActorMoveFrames(p,8);return 1; }
