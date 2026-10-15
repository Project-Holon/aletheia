/*
 * function: NAMEIN_GRAPHIC_ApplyConversion
 * address: 0x021F21FC
 * packet: pkt_ov194_021F21FC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: shared failure label retains one exit; byte-offset cast +10 inside the loop
 * materialises the added-array base after the entry guard, unlike change.added.
 * symbols:
 *   NAMEIN_GRAPHIC_FindTableIndex 0x021F4ED8 thumb ov194
 *   NAMEIN_GRAPHIC_PickTable8 0x021F4E18 thumb ov194
 *   NAMEIN_GRAPHIC_CopyTableEntries 0x021F4DDC thumb ov194
 *   NAMEIN_GRAPHIC_Backspace 0x021F2150 thumb ov194
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 */
#include "../include/Obj08342.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 NAMEIN_GRAPHIC_FindTableIndex(const char *p, const u16 *b);
extern int NAMEIN_GRAPHIC_PickTable8(int,int,u16 *,int,u8 *);
extern void NAMEIN_GRAPHIC_CopyTableEntries(const char *p, int i, u16 *dst, u32 n, u8 *count);
extern int NAMEIN_GRAPHIC_Backspace(u8 *);
extern int NAMEIN_GRAPHIC_AppendChar(char *,u16);
typedef struct { u8 removedCount, addedCount; u16 removed[4],added[4]; } Changes;
int NAMEIN_GRAPHIC_ApplyConversion(u8 *a,int b)
{
    void *p;
    u16 v;
    Changes change;
    int i;
    u16 *tab;
    switch(b) {
    case 0: p=((struct Obj08342 *)a)->f84; break;
    case 1: p=((struct Obj08342 *)a)->f88; break;
    default:return 0;
    }
    if (((struct Obj08342 *)a)->f1E==0) goto fail;
    v=NAMEIN_GRAPHIC_FindTableIndex(p,(u16 *)(a+(((struct Obj08342 *)a)->f1E-1)*2));
    if(v==65535) goto fail;
    if(!NAMEIN_GRAPHIC_PickTable8((int)p,v,change.added,4,&change.addedCount)) goto fail;
    NAMEIN_GRAPHIC_CopyTableEntries(p,v,change.removed,4,&change.removedCount);
    for(i=0;i<change.removedCount;i++) NAMEIN_GRAPHIC_Backspace(a);
    for(i=0;i<change.addedCount;i++) {
        tab=(u16 *)((u8 *)&change+10);
        NAMEIN_GRAPHIC_AppendChar((char *)a,tab[i]);
    }
    return 1;
fail:
    return 0;
}
