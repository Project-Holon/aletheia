/*
 * function: ZKND_TBAR_UpdateButtonTouch
 * address: 0x021BD764
 * packet: pkt_ov208_021BD764
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 126 code bytes, then two zero alignment bytes at 021BD7E2.
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 */
#include "../include/Obj03928.h"

typedef unsigned int u32;
typedef unsigned char  u8;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 KEY_GetTrg(void);
int ZKND_TBAR_UpdateButtonTouch(char *p)
{
    unsigned x,y;
    int hit=0;
    if(CLACT_GetActorDrawEnable(((struct Obj03928 *)p)->f0)&((struct Obj03928 *)p)->f4) {
        if(TOUCHPANEL_GetPointTrg(&x,&y) && x-((struct Obj03928 *)p)->f18<=((struct Obj03928 *)p)->f1C && y-((struct Obj03928 *)p)->f1A<=24) {
            hit=1;
            func_020355D8(1);
        }
        if(((struct Obj03928 *)p)->f2C && (KEY_GetTrg()&((struct Obj03928 *)p)->f2C)) {
            func_020355D8(0);
            hit=1;
        }
        if(((struct Obj03928 *)p)->f34) {
            func_020355D8(0);
            hit=1;
        }
        if(hit) {
            (*(void (**)(char *))(p+0xc))(p);
            return 1;
        }
    }
    return 0;
}
