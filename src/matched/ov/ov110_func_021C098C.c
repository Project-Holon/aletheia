/*
 * function: PMS_SELECT_GRAPHIC_UpdateBgBlink
 * address: 0x021C098C
 * packet: pkt_ov110_021C098C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_SELECT_GRAPHIC_BlendBlinkColors 0x021C088C thumb ov110
 *   gPmsSelectGraphicBlinkColors 0x021C39E0 data a4
 */
#include "../include/Obj05299.h"
typedef unsigned short u16;
typedef unsigned char  u8;
struct Rec;
extern void PMS_SELECT_GRAPHIC_BlendBlinkColors(u16 *ang, u16 *out, struct Rec *recs, u8 count);
extern unsigned short gPmsSelectGraphicBlinkColors[];
void PMS_SELECT_GRAPHIC_UpdateBgBlink(char *p) {
    int v;
    if (((struct Obj05299 *)p)->f1C) {
        v=1;
        if (((struct Obj05299 *)p)->f20<16) {
            v=(((struct Obj05299 *)p)->f20/4)%2;
            (((struct Obj05299 *)p)->f20)++;
        }
        if(v) ((struct Obj05299 *)p)->fC=0xfc00;
        else ((struct Obj05299 *)p)->fC=0x7c00;
    }
    PMS_SELECT_GRAPHIC_BlendBlinkColors((u16 *)(p+0xc),(u16 *)(p+0xe),(struct Rec *)gPmsSelectGraphicBlinkColors,3);
}
