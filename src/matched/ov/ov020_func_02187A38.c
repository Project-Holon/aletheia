/*
 * function: EL_SCOREBOARD_UpdateFadeShared
 * address:  0x02187A38
 * packet:   pkt_ov020_02187A38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blend fade on the main engine (BLDCNT 0x04000050) plus the sub engine's
 * master brightness (0x0400106C), driven by the ratio o->0x18 / o->0x1c.
 * The object pointer is `const char *`: through a const pointer mwcc lets the
 * loads after the G2x_SetBlendAlpha_ call ignore the outgoing stack-argument
 * store, so that store is scheduled last (+0x7E). With a plain `char *` it
 * moves up to +0x78 (8 bytes out); const casts on the loads alone do not.
 *
 * symbols:
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D63C  0x0207D63C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 */
#include "../include/Obj01651.h"

typedef unsigned char u8;
typedef unsigned int u32;

void func_0207D658(u32 addr, int plane, int brightness);
void func_0207D63C(u32 addr, int plane1, int plane2, int ev1, int ev2);
typedef unsigned short u16;
void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

void EL_SCOREBOARD_UpdateFadeShared(const char *o, int st)
{
    int v;

    if (st == 2) {
        func_0207D658(0x04000050, 8,
            (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C) + -16.0f));
    } else if (st == 4) {
        if (*(const u8 *)&((struct Obj01651 *)o)->f15 == *(const u8 *)&((struct Obj01651 *)o)->f14) {
            v = (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C));
            func_0207D63C(0x04000050, 8, 0x11, 16 - v, v);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106C,
                (int)(16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C) + -16.0f));
        } else {
            func_0207D658(0x04000050, 8,
                (int)(0.0f - 16.0f * ((float)*(const u32 *)&((struct Obj01651 *)o)->f18 / (float)*(const u32 *)&((struct Obj01651 *)o)->f1C)));
        }
    }
}
