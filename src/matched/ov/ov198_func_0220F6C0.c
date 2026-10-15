/*
 * function: B_PLIST_MAIN_HandleSelectInput
 * address: 0x0220F6C0
 * packet: pkt_ov198_0220F6C0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   B_PLIST_MAIN_CheckCancel 0x02211958 thumb ov198
 *   B_PLIST_MAIN_HandleCursorInput 0x02210A4C thumb ov198
 *   B_PLIST_MAIN_PopSelectionPair 0x02211128 thumb ov198
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_ClearSelection 0x02211944 thumb ov198
 *   B_PLIST_MAIN_ConfirmSelect 0x0220F7C4 thumb ov198
 */
#include "../include/Obj04601.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 PALANM_GetFadeRequestBits(const char *);
extern u32 B_PLIST_MAIN_CheckCancel(u8 **);
extern int B_PLIST_MAIN_HandleCursorInput(u8 *);
extern int B_PLIST_MAIN_PopSelectionPair(u8 *,u8 *,u8 *,int);
extern void B_PLIST_MAIN_PlaySe(u8 **,u32);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *,u32);
extern void B_PLIST_MAIN_ClearSelection(u8 **);
extern int B_PLIST_MAIN_ConfirmSelect(u8 *);
int B_PLIST_MAIN_HandleSelectInput(u8 *p)
{
    u8 pair[2];
    if(PALANM_GetFadeRequestBits(*(char * *)&((struct Obj04601 *)p)->f1D8)!=0) return 3;
    if(B_PLIST_MAIN_CheckCancel((u8 **)p)==1) return 31;
    if(B_PLIST_MAIN_HandleCursorInput(p)==1) {
        if((*(u8 **)p)[32]==6) {
            if((*(u8 **)p)[31]==2) {
                if(B_PLIST_MAIN_PopSelectionPair(p,pair+1,pair,1)==1) {
                    if(pair[1]<pair[0]) (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[1])[72]=255;
                    else (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[0])[72]=255;
                    p[0x2499]=pair[1];
                    p[0x249a]=pair[0];
                    p[0x1e98]=0;
                    B_PLIST_MAIN_PlaySe((u8 **)p,1362);
                    return 9;
                }
            } else if((*(u8 **)p)[31]!=1) {
                B_PLIST_MAIN_PlaySe((u8 **)p,1362);
                B_PLIST_ANM_StartPaletteAnim(p,6);
                B_PLIST_MAIN_ClearSelection((u8 **)p);
                return 31;
            }
        } else {
            B_PLIST_MAIN_PlaySe((u8 **)p,1357);
            B_PLIST_ANM_StartPaletteAnim(p,(*(u8 **)p)[32]);
            if((*(u8 **)p)[31]==3) return B_PLIST_MAIN_ConfirmSelect(p);
            ((struct Obj04601 *)p)->f217C=12;
            return 29;
        }
    }
    return 3;
}
