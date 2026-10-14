/*
 * function: func_0220D370
 * address: 0x0220D370
 * packet: pkt_ov197_0220D370
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj25089.h"
typedef unsigned short u16;typedef unsigned char u8;typedef short s16;typedef struct PalAnmObj PalAnmObj;
extern void *BTLV_EFFECT_GetOwner(void);
extern int PALANM_RequestFade(PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
int func_0220D370(char *p){PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj25089 *)p)->f8,10,65535,0,0,16,0,BTLV_EFFECT_GetOwner());return 19;}
