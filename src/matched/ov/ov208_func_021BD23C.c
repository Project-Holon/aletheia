/*
 * function: func_021BD23C
 * address: 0x021BD23C
 * packet: pkt_ov208_021BD23C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 162 code bytes, then two zero alignment bytes at 021BD2DE.
 * symbols:
 *   func_021BD764 0x021BD764 thumb ov208
 *   func_021BD7E4 0x021BD7E4 thumb ov208
 *   func_021BD878 0x021BD878 thumb ov208
 */
#include "../include/Obj01977.h"
extern int func_021BD764(char *);
extern int func_021BD7E4(void *);
extern void func_021BD878(char *p);
void func_021BD23C(char *p)
{
    unsigned i;
    switch(*(unsigned *)&((struct Obj01977 *)p)->f8) {
    case 0:
        *(int *)&((struct Obj01977 *)p)->f0=-1;
        if(((struct Obj01977 *)p)->fC && !((struct Obj01977 *)p)->f10) {
            for(i=0;i<((struct Obj01977 *)p)->f4;i++) {
                if(func_021BD764(p+0x28+i*0x38)) {
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
        if(func_021BD7E4(p+0x28+((struct Obj01977 *)p)->f0*0x38))((struct Obj01977 *)p)->f8=3;
        break;
    case 3:
        ((struct Obj01977 *)p)->f8=0;
        break;
    }
    for(i=0;i<((struct Obj01977 *)p)->f4;i++)func_021BD878(p+0x28+i*0x38);
}
