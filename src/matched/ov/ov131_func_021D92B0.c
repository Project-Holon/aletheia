/*
 * function: P_STA_RIBBON_UpdateRows
 * address: 0x021D92B0
 * packet: pkt_ov131_021D92B0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * proof: loop i starts at zero and tests i<10 after each byte increment;
 * i*20 <=180. Each other byte index is guarded <10 before *20.
 * prototype: 021D92EA loads r1 for 021D9428 despite its legacy one-input
 * source. Preserve this observed full-word argument in the caller extern.
 * symbols:
 *   P_STA_RIBBON_GetRowY 0x021D9440 thumb ov131
 *   P_STA_OAM_SetBitmapActorsPos 0x021DBE2C thumb ov131
 *   P_STA_RIBBON_GetRowOwnedIndex 0x021D9428 thumb ov131
 *   P_STA_RIBBON_DrawRow 0x021D91F0 thumb ov131
 *   P_STA_OAM_SetBitmapActorsEnabled 0x021DBCA4 thumb ov131
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 */
#include "../include/Obj00091.h"
#include "../include/Obj03816.h"
#include "../include/Obj08147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern s16 P_STA_RIBBON_GetRowY(u8 *,u32);
extern void P_STA_OAM_SetBitmapActorsPos(u8 *,s16,s16);
extern u32 P_STA_RIBBON_GetRowOwnedIndex(u8 *,u32);
extern void P_STA_RIBBON_DrawRow(u8 *,u8 *,u8 *);
extern void P_STA_OAM_SetBitmapActorsEnabled(u8 *,int);
struct PrintSys;
extern void P_STA_OAM_TransferBitmap(u8 *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void GFL_USE_PlaySeInSlot(void *,int);
void P_STA_RIBBON_UpdateRows(u8 *a,u8 *p)
{
    int changed;
    u8 *entries;
    u8 i;
    u32 value;
    u8 *entry;
    s16 y;
    changed=0;
    entries=p;
    entries+=0x70;
    for(i=0;i<10;i++) {
        if(((struct Obj00091 *)p)->fC==1) {
            y=P_STA_RIBBON_GetRowY(p,i);
            P_STA_OAM_SetBitmapActorsPos(*(u8 **)((p+i*20)+0x80),8,y);
            value=P_STA_RIBBON_GetRowOwnedIndex(p,i);
            if(value==65535) {
                *(u16 *)((p+i*20)+0x70)=value;
                P_STA_OAM_SetBitmapActorsEnabled(*(u8 **)((p+i*20)+0x80),0);
            } else if(value!=*(u16 *)((p+i*20)+0x70)) {
                changed=1;
                *(u16 *)((p+i*20)+0x70)=value;
                P_STA_RIBBON_DrawRow(a,p,entries+i*20);
                P_STA_OAM_SetBitmapActorsEnabled(*(u8 **)((p+i*20)+0x80),1);
            }
        }
        entry=p+i*20;
        if(((struct Obj08147 *)entry)->f78==1 && PRINTSYS_QUE_IsExistTarget(((struct Obj03816 *)a)->f84,((struct Obj08147 *)entry)->f7C)==0) {
            ((struct Obj08147 *)entry)->f78=0;
            P_STA_OAM_TransferBitmap(((struct Obj08147 *)entry)->f80);
        }
    }
    if(changed==1 && p[0x60]==0) {
        GFL_USE_PlaySeInSlot((void *)1605,1);
        p[0x60]=3;
    }
    if(((struct Obj00091 *)p)->f68==1) {
        if(p[0x58]<10) P_STA_RIBBON_DrawRow(a,p,(p+0x70)+p[0x58]*20);
        if(p[0x5a]<10) P_STA_RIBBON_DrawRow(a,p,(p+0x70)+p[0x5a]*20);
        p[0x5a]=p[0x58];
        ((struct Obj00091 *)p)->f68=0;
    }
    ((struct Obj00091 *)p)->fC=0;
}
