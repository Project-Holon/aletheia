/*
 * function: INTRO_G3D_UpdateAnimMode
 * address: 0x021BFB2C
 * packet: pkt_ov204_021BFB2C
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_G3D_SetAnimFrame 0x021BFBC8 thumb ov204
 */
#include "../include/Obj01974.h"

extern void INTRO_G3D_SetAnimFrame(char *, unsigned int);

int INTRO_G3D_UpdateAnimMode(char *p)
{
    switch (((struct Obj01974 *)p)->f1C)
    {
    case 0: break;
    case 1:
        --((struct Obj01974 *)p)->f28;
        INTRO_G3D_SetAnimFrame(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 50) return 1;
        break;
    case 2:
        ++((struct Obj01974 *)p)->f28;
        INTRO_G3D_SetAnimFrame(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 70) return 1;
        break;
    case 3:
        --((struct Obj01974 *)p)->f28;
        INTRO_G3D_SetAnimFrame(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 0) return 1;
        break;
    case 4:
        ++((struct Obj01974 *)p)->f28;
        INTRO_G3D_SetAnimFrame(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 120) return 1;
        break;
    }
    return 0;
}
