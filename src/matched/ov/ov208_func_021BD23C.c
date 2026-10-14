/*
 * function: ZKND_TBAR_UpdateButtons
 * address: 0x021BD23C
 * packet: pkt_ov208_021BD23C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 162 code bytes, then two zero alignment bytes at 021BD2DE.
 * symbols:
 *   ZKND_TBAR_UpdateButtonTouch 0x021BD764 thumb ov208
 *   ZKND_TBAR_IsButtonAnimating 0x021BD7E4 thumb ov208
 *   ZKND_TBAR_GetButtonCount 0x021BD878 thumb ov208
 */
#include "../include/Obj01977.h"
extern int ZKND_TBAR_UpdateButtonTouch(char *);
extern int ZKND_TBAR_IsButtonAnimating(int *p);
extern void ZKND_TBAR_GetButtonCount(char *p);
void ZKND_TBAR_UpdateButtons(char *p)
{
    unsigned i;
    switch(*(unsigned *)&((struct Obj01977 *)p)->f8) {
    case 0:
        *(int *)&((struct Obj01977 *)p)->f0=-1;
        if(((struct Obj01977 *)p)->fC && !((struct Obj01977 *)p)->f10) {
            for(i=0;i<((struct Obj01977 *)p)->f4;i++) {
                if(ZKND_TBAR_UpdateButtonTouch(p+0x28+i*0x38)) {
                    ((struct Obj01977 *)p)->f0=i;
                    ((struct Obj01977 *)p)->f8=1;
                    ((struct Obj01977 *)p)->f10=1;
                    break;
                }
            }
        }
        break;
    case 1:
        ((struct Obj01977 *)p)->f8=2;
    case 2:
        if(ZKND_TBAR_IsButtonAnimating((int *)(p+0x28+((struct Obj01977 *)p)->f0*0x38)))((struct Obj01977 *)p)->f8=3;
        break;
    case 3:
        ((struct Obj01977 *)p)->f8=0;
        break;
    }
    for(i=0;i<((struct Obj01977 *)p)->f4;i++)ZKND_TBAR_GetButtonCount(p+0x28+i*0x38);
}
