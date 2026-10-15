/*
 * function: RESEARCH_GRAPH_RequestFadeIn
 * address: 0x021BF60C
 * packet: pkt_ov217_021BF60C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj08435.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct PalAnmObj;
extern int PALANM_RequestFade(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
void RESEARCH_GRAPH_RequestFadeIn(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct Obj08435 *)p)->f3B8,1,0xffff,3,0,7,0xffff,((struct Obj08435 *)p)->f3BC);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct Obj08435 *)p)->f3B8,4,0xffff,3,0,7,0xffff,((struct Obj08435 *)p)->f3BC);
}
