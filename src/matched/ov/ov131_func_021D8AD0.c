/*
 * function: P_STA_RIBBON_UpdateKeys
 * address: 0x021D8AD0
 * packet: pkt_ov131_021D8AD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Narrow deltas are assigned to u8/s16 locals before forwarding;
 *   inline casts copy into the argument register before truncating.
 * proof: Position is initialized to -16 before the search, as 021D8B4C.
 *   Loop i is u8 bounded by 10. Navigation index keeps the original u8
 *   wrapping and single subtraction, without assuming a 0..9 input.
 *   Its 20-byte scaling is <=5100 and signed arithmetic fits int.
 *   021D9440 returns s16, so subtracting 128 or 8 fits int; outgoing
 *   deltas preserve the original u8 and s16 narrowing respectively.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
 *   P_STATUS_SetInputEnable 0x021D5A9C thumb ov131
 *   P_STA_RIBBON_FreeDetailWindows 0x021D964C thumb ov131
 *   P_STA_RIBBON_HideDetail 0x021D9670 thumb ov131
 *   P_STA_RIBBON_GetRowY 0x021D9440 thumb ov131
 *   P_STA_RIBBON_SnapCursorToScroll 0x021D8EA8 thumb ov131
 *   P_STA_RIBBON_PrintDetail 0x021D949C thumb ov131
 *   P_STA_RIBBON_Scroll 0x021D8F0C thumb ov131
 *   P_STA_RIBBON_SelectRow 0x021D8ED0 thumb ov131
 */
#include "../include/Obj00091.h"
#include "../include/Obj00136.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020061E4(u32 a);
extern void P_STATUS_SetInputEnable(char *p, int a);
extern void P_STA_RIBBON_FreeDetailWindows(u8 *,u8 *);
extern void P_STA_RIBBON_HideDetail(u8 *,u8 *);
extern s16 P_STA_RIBBON_GetRowY(u8 *,u32);
extern void P_STA_RIBBON_SnapCursorToScroll(u8 *,u8 *);
extern void P_STA_RIBBON_PrintDetail(u8 *,u8 *);
extern void P_STA_RIBBON_Scroll(void *,u8 *,int);
extern void P_STA_RIBBON_SelectRow(u8 *a, u8 *p, u8 n);
int P_STA_RIBBON_UpdateKeys(u8 *a,u8 *p)
{
    u8 i,index,narrowDelta;
    s16 shortDelta;
    int position;
    if(func_020362DC()==2) {
        P_STATUS_SetInputEnable((char *)a,1);
        CLACT_SetActorAnimSeq(((struct Obj00136 *)a)->f194,9);
        func_0204B3DC(((struct Obj00091 *)p)->f54,0);
        p[0x58]=255;
        p[0x59]=255;
        ((struct Obj00091 *)p)->f68=1;
        P_STA_RIBBON_FreeDetailWindows(a,p);
        P_STA_RIBBON_HideDetail(a,p);
        a[0x1c]=0;
        func_020061E4(1361);
        return 1;
    }
    if(a[0x1c]==1) {
        if(func_020362DC()==1 || func_020362DC()==128 || func_020362DC()==64) {
            position=-16;
            ((struct Obj00091 *)p)->f5C=0;
            *(int *)&((struct Obj00091 *)p)->f64=0;
            for(i=0;i<10;i++) {
                if(p[0x59]==*(u16 *)(p+0x70+i*20)) position=P_STA_RIBBON_GetRowY(p,i);
            }
            if(position < -4 || position >144) P_STA_RIBBON_SnapCursorToScroll(a,p);
            P_STA_RIBBON_FreeDetailWindows(a,p);
            P_STA_RIBBON_PrintDetail(a,p);
            func_020061E4(1352);
            a[0x1c]=0;
            return 1;
        }
    } else if(func_0203633C()==128) {
        index=p[0x58]+1;
        if(index>=10) index-=10;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            ((struct Obj00091 *)p)->f68=1;
            if(P_STA_RIBBON_GetRowY(p,p[0x58])>128) {
                narrowDelta=P_STA_RIBBON_GetRowY(p,p[0x58])-128;
                P_STA_RIBBON_Scroll(a,p,narrowDelta);
            }
            P_STA_RIBBON_SelectRow(a,p,p[0x58]);
            P_STA_RIBBON_FreeDetailWindows(a,p);
            P_STA_RIBBON_PrintDetail(a,p);
            func_020061E4(1352);
        }
        return 1;
    } else if(func_0203633C()==64) {
        index=p[0x58];
        if(index==0) index=9;
        else index-=1;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            ((struct Obj00091 *)p)->f68=1;
            if(P_STA_RIBBON_GetRowY(p,p[0x58])<8) {
                shortDelta=P_STA_RIBBON_GetRowY(p,p[0x58])-8;
                P_STA_RIBBON_Scroll(a,p,shortDelta);
            }
            P_STA_RIBBON_SelectRow(a,p,p[0x58]);
            P_STA_RIBBON_FreeDetailWindows(a,p);
            P_STA_RIBBON_PrintDetail(a,p);
            func_020061E4(1352);
        }
        return 1;
    }
    return 0;
}
