/*
 * function: WORLDTRADE_INPUT_MenuSetMode
 * address: 0x021F9968
 * packet: pkt_ov135_021F9968
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021F99CE.
 */
#include "../include/Obj01259.h"
typedef unsigned char u8;
typedef signed short s16;
void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode)
{
    ((struct Obj01259 *)p)->f54 = mode;
    switch (mode) {
    case 0:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f38 = 0;
        ((struct Obj01259 *)p)->f3A = 0;
        ((struct Obj01259 *)p)->f48 = 6;
        return;
    case 3:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f38 = 0;
        ((struct Obj01259 *)p)->f3A = 0;
        ((struct Obj01259 *)p)->f48 = 18;
        return;
    case 1:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f48 = 30;
        return;
    case 2:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f48 = 33;
        break;
    }
}
