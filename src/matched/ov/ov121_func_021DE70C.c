/*
 * function: func_021DE70C
 * address: 0x021DE70C
 * packet: pkt_ov121_021DE70C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   DELIVERY_BEACON_Create 0x021576D0 thumb ov010
 *   DELIVERY_BEACON_Start 0x021578A0 thumb ov010
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE7FC 0x021DE7FC thumb ov121
 *   GAME_LANGUAGE_Code 0x0209DF0C data
 */
#include "../include/Obj08101.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 kind;u8 flag,pad;u16 heap;u32 bytes;void *data;u32 lang,align;u8 reserved[96];u32 last;} Config;
extern void func_02082BCC(void *,int,u32);
extern void *DELIVERY_BEACON_Create(u8 *p);
extern int DELIVERY_BEACON_Start(u32 *);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE7FC(void *a, int b, char *p);
extern u8 GAME_LANGUAGE_Code;
void func_021DE70C(void *a,int *state,char *p) {Config cfg;u32 h; switch(*state) {case 0: func_02082BCC(&cfg,0,124);cfg.kind=9;cfg.bytes=720;cfg.data=p+1956;cfg.lang=GAME_LANGUAGE_Code;cfg.align=2097152;cfg.last=1;cfg.flag=0;cfg.heap=((struct Obj08101 *)p)->f58;h=(u32)DELIVERY_BEACON_Create((u8 *)(&cfg));((struct Obj08101 *)p)->f798=h;DELIVERY_BEACON_Start((u32 *)h);BG_SYS_SetSubPlaneVisible(16,0);((struct Obj08101 *)p)->f17A4=0;*state=1;break;case 1:if(GFL_NET_GetRunState()) {GFL_NET_RestartWithDefaultTimeout(1,((struct Obj08101 *)p)->f58);BG_SYS_SetSubPlaneVisible(16,1);*state=2;}break;case 2:func_021DEEA4(a,func_021DE7FC);break;} }
