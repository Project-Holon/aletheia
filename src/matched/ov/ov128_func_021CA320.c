/*
 * function: WF2DMAP_TOUCH_StepItemBarBlink
 * address: 0x021CA320
 * packet: pkt_ov128_021CA320
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_TOUCH_DrawItemHighlight 0x021CA25C thumb ov128
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj00775.h"

typedef unsigned int   u32;
extern void WF2DMAP_TOUCH_DrawItemHighlight(u32 a, u32 b);
int WF2DMAP_TOUCH_StepItemBarBlink(char *p)  {
    switch(((struct Obj00775 *)p)->f8)  {
        case 0: WF2DMAP_TOUCH_DrawItemHighlight(((struct Obj00775 *)p)->f4,1);
        ((struct Obj00775 *)p)->fA=0;
        (((struct Obj00775 *)p)->f8)++;
        break;
        case 1: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            WF2DMAP_TOUCH_DrawItemHighlight(((struct Obj00775 *)p)->f4,2);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 2: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            WF2DMAP_TOUCH_DrawItemHighlight(((struct Obj00775 *)p)->f4,1);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 3: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            WF2DMAP_TOUCH_DrawItemHighlight(((struct Obj00775 *)p)->f4,2);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 4: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            ((struct Obj00775 *)p)->f8=0;
            ((struct Obj00775 *)p)->fA=0;
            return 0;
        }
        break;
    }
    return 1;
}
