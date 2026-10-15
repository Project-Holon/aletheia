/*
 * function: BR_CODEIN_RecordDeleteButtons
 * address: 0x021DD054
 * packet: pkt_ov183_021DD054
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj00050.h"
#include "../include/Obj06598.h"
#include "../include/Obj10730.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BG_SYS_PushTile(u32 index);
void BR_CODEIN_RecordDeleteButtons(char *p, char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD8) {
        if(((struct Obj00050 *)p)->f28) { BR_UTIL_Delete(((struct Obj00050 *)p)->f28); *(int *)&((struct Obj00050 *)p)->f28=0; }
        for(i=0;i<2;i++) {
            slot=p+i*4;
            if(((struct Obj10730 *)slot)->f1C) { BR_BTN_DeleteObject(((struct Obj10730 *)slot)->f1C); *(int *)&((struct Obj10730 *)slot)->f1C=0; }
        }
        BG_SYS_PushTile(4);
        BR_RES_ReleaseSprite((char *)(((struct Obj06598 *)q)->f10),6);
        BR_RES_ApplyBgSet(((struct Obj06598 *)q)->f10,5);
        ((struct Obj00050 *)p)->fD8=0;
    }
}
