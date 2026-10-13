/*
 * function: P_STA_RIBBON_UpdateInput
 * address: 0x021D8A2C
 * packet: pkt_ov131_021D8A2C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): the p+0x64 store precedes the p+0x58 store; with source order 58/64/68 the
 *   allocator hoists constant 0 into r7 instead.
 * symbols:
 *   P_STA_RIBBON_GetTouchedRow 0x021D8E24 thumb ov131
 *   KEY_GetTrg 0x020362DC arm
 *   P_STATUS_SetInputEnable 0x021D5A9C thumb ov131
 *   P_STA_RIBBON_SnapCursorToScroll 0x021D8EA8 thumb ov131
 *   P_STA_RIBBON_GetRowOwnedIndex 0x021D9428 thumb ov131
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   P_STA_RIBBON_FreeDetailWindows 0x021D964C thumb ov131
 *   P_STA_RIBBON_PrintDetail 0x021D949C thumb ov131
 *   P_STA_RIBBON_UpdateKeys 0x021D8AD0 thumb ov131
 *   P_STA_RIBBON_UpdateTouch 0x021D8CD0 thumb ov131
 */
#include "../include/Obj00091.h"
#include "../include/Obj00136.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int P_STA_RIBBON_GetTouchedRow(void *unused, u8 *p);
extern u32 KEY_GetTrg(void);
extern void P_STATUS_SetInputEnable(char *p, int a);
extern void P_STA_RIBBON_SnapCursorToScroll(u8 *,u8 *);
extern unsigned int P_STA_RIBBON_GetRowOwnedIndex(unsigned char *p, unsigned int target);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void P_STA_RIBBON_FreeDetailWindows(u8 *,u8 *);
extern void P_STA_RIBBON_PrintDetail(u8 *,u8 *);
extern int P_STA_RIBBON_UpdateKeys(u8 *,u8 *);
extern void P_STA_RIBBON_UpdateTouch(u8 *,u8 *);
void P_STA_RIBBON_UpdateInput(u8 *a,u8 *p)
{
    int index;
    if(((struct Obj00136 *)a)->f44==1) {
        if(p[0x10]==0) return;
        index=P_STA_RIBBON_GetTouchedRow(a,p);
        if(KEY_GetTrg()!=1 && index==-1) return;
        ((struct Obj00091 *)p)->f5C=0;
        P_STATUS_SetInputEnable((char *)a,0);
        if(KEY_GetTrg()==1) {
            P_STA_RIBBON_SnapCursorToScroll(a,p);
            a[0x1c]=0;
        } else {
            ((struct Obj00091 *)p)->f64=1;
            p[0x58]=(u8)index;
            ((struct Obj00091 *)p)->f68=1;
            p[0x59]=P_STA_RIBBON_GetRowOwnedIndex(p,(u8)index);
            P_STATUS_SetInputEnable((char *)a,0);
            a[0x1c]=1;
        }
        GFL_USE_PlaySeDefaultVolume(0x54c);
        P_STA_RIBBON_FreeDetailWindows(a,p);
        P_STA_RIBBON_PrintDetail(a,p);
    } else {
        if(*(u32 *)&((struct Obj00091 *)p)->f8==0 && P_STA_RIBBON_UpdateKeys(a,p)==0) P_STA_RIBBON_UpdateTouch(a,p);
    }
}
