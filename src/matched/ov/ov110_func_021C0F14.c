/*
 * function: PMS_SELECT_GRAPHIC_UpdateInput
 * address: 0x021C0F14
 * packet: pkt_ov110_021C0F14
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Byte +99 is a one-bit field; selection bytes retain 255 and the signed touch result retains -1.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_SELECT_GRAPHIC_RedrawRowsAfterInput 0x021C0C50 thumb ov110
 *   PMS_SELECT_GRAPHIC_PlaceScrollThumb 0x021C0D34 thumb ov110
 *   PMS_SELECT_GRAPHIC_UpdateThumbDrag 0x021C0EB0 thumb ov110
 *   PMS_SELECT_GRAPHIC_StartThumbDrag 0x021C0DE4 thumb ov110
 *   PMS_SELECT_GRAPHIC_GetTouchedRow 0x021C12F8 thumb ov110
 */
#include "../include/Obj00217.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 lo:1; u8 hi:7; } Flags;
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(u8 *);
extern void PMS_SELECT_GRAPHIC_PlaceScrollThumb(char *,int);
extern int PMS_SELECT_GRAPHIC_UpdateThumbDrag(char *);
extern int PMS_SELECT_GRAPHIC_StartThumbDrag(char *);
extern int PMS_SELECT_GRAPHIC_GetTouchedRow(void);
int PMS_SELECT_GRAPHIC_UpdateInput(u8 *p)
{
    int result=0;
    int proceed=1;
    int active;
    int hit;
    if(!((Flags *)(p+0x99))->lo) {
        active=0;
        if(KEY_GetTrg()&~2) active=1;
        if(active && p[0x95]==255) {
            if(p[0x94]==255) p[0x95]=p[0x96];
            else if(p[0x96]<=p[0x94] && p[0x94]<p[0x96]+3) p[0x95]=p[0x94];
            else p[0x95]=p[0x96];
            p[0x94]=255;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
            GFL_USE_PlaySeDefaultVolume(1352);
            PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
        }
    }
    if(proceed && p[0x95]!=255 && !((Flags *)(p+0x99))->lo) {
        if(KEY_GetTrg()&1) {
            result=1;
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(KEY_GetRepeat()&64) {
            if(p[0x95]!=0) {
                p[0x94]=p[0x95];
                p[0x95]--;
                if(p[0x95]+1==p[0x96]) p[0x96]--;
                PMS_SELECT_GRAPHIC_PlaceScrollThumb((char *)p,0);
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        } else if(KEY_GetRepeat()&128) {
            if(p[0x95]<p[0x98]-1) {
                p[0x94]=p[0x95];
                p[0x95]++;
                if(p[0x95]==p[0x96]+3) p[0x96]++;
                PMS_SELECT_GRAPHIC_PlaceScrollThumb((char *)p,0);
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
            proceed=0;
            ((struct Obj00217 *)p)->fA8=0;
        }
    }
    if(proceed) {
        if(((Flags *)(p+0x99))->lo) {
            if(PMS_SELECT_GRAPHIC_UpdateThumbDrag((char *)p)) {
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
            ((struct Obj00217 *)p)->fA8=1;
        } else {
            hit=PMS_SELECT_GRAPHIC_GetTouchedRow();
            if(hit!=-1 && hit>p[0x98]-1) hit=-1;
            if(hit!=-1) {
                p[0x94]=p[0x95];
                p[0x95]=p[0x96]+hit;
                PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                result=1;
                ((struct Obj00217 *)p)->fA8=1;
            } else {
                if(!((Flags *)(p+0x99))->lo) PMS_SELECT_GRAPHIC_StartThumbDrag((char *)p);
                if(((Flags *)(p+0x99))->lo==1) {
                    if(PMS_SELECT_GRAPHIC_UpdateThumbDrag((char *)p) || p[0x95]!=255) {
                        p[0x94]=p[0x95];
                        p[0x95]=255;
                        PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
                    }
                    GFL_USE_PlaySeDefaultVolume(1352);
                    ((struct Obj00217 *)p)->fA8=1;
                }
            }
        }
    }
    return result;
}
