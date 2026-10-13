/*
 * function: FIELD_PLACE_NAME_DrawFadeOut
 * address:  0x021BCF24
 * packet:   pkt_ov021_021BCF24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 */
#include "../include/Obj20119.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D63C(int, int, int, int, int);

void FIELD_PLACE_NAME_DrawFadeOut(char *p)
{
    float t;
    int a;

    t = (float)(u32)((struct Obj20119 *)p)->f42 / 20.0f;
    a = (int)(16.0f * (1.0f - t));
    func_0207D63C(0x04000050, 8, 0x11, a, (int)(4.0f + 12.0f * t));
}
