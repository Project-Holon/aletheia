/*
 * function: PDC_MSG_Update
 * address: 0x021B6A3C
 * packet: pkt_ov098_021B6A3C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: lead ends 021B6B5A, alignment 2 B; existing B5C/B68 unit through 6B74; unlabelled 24 B flag leaf at 6B74.
 * prototype: 021B6CDC unused a1/a2 omitted, full body overwrites all outgoing arguments; 02035C60 return is observed live at 021B6AE4 despite owner void prototype.
 * symbols:
 *   PDC_MSG_BlendStartFadeOut 0x021B6C90 thumb ov098
 *   PDC_MSG_BlendUpdate 0x021B6CDC thumb ov098
 *   PRINTSYS_PrintStreamRun 0x0201CE20 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj00466.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec3;
extern void PDC_MSG_BlendStartFadeOut(char *, int);
extern int PDC_MSG_BlendUpdate(u8 *);
extern void PRINTSYS_PrintStreamRun(void *);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
int PDC_MSG_Update(u8 *p)
{
    switch (p[0x39]) {
    case 0:
        PDC_MSG_BlendStartFadeOut((char *)p + 4, p[0x38]);
        p[0x39]++;
    case 1:
        if (!PDC_MSG_BlendUpdate(p + 4)) break;
        if (p[0x38]) {
            p[0x39] = 6;
            break;
        }
        if (((struct Obj00466 *)p)->f0) PRINTSYS_PrintStreamRun(((struct Obj00466 *)p)->f0);
        p[0x39]++;
    case 2:
        if (((struct Obj00466 *)p)->f0) {
            ((struct Obj00466 *)p)->f3C = PRINTSYS_PrintStreamGetState(((struct Obj00466 *)p)->f0);
            if (((struct Obj00466 *)p)->f3C) {
                p[0x39] = 3;
                if (((struct Obj00466 *)p)->f3C == 2) p[0x3a] = 1;
            }
        } else return 1;
        break;
    case 3:
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg()) ((struct Obj00466 *)p)->f40 = 0;
        if (((struct Obj00466 *)p)->f40) (((struct Obj00466 *)p)->f40)--;
        else p[0x39] = 5;
        break;
    case 4:
        if (((struct Obj00466 *)p)->f40) (((struct Obj00466 *)p)->f40)--;
        else p[0x39] = 5;
        break;
    case 5:
        if (((struct Obj00466 *)p)->f3C == 2) {
            GF_FONT_SetDefaultTextColor();
            PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj00466 *)p)->f0);
            ((struct Obj00466 *)p)->f0 = 0;
            p[0x39] = 6;
            return 1;
        } else {
            PRINTSYS_PrintStreamReleasePause(((struct Obj00466 *)p)->f0);
            p[0x39] = 2;
            ((struct Obj00466 *)p)->f40 = ((struct Obj00466 *)p)->f42;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}
