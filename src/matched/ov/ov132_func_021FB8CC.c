/*
 * function: func_021FB8CC
 * address: 0x021FB8CC
 * packet: pkt_ov132_021FB8CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   func_021FAEE8 0x021FAEE8 thumb ov132
 *   func_021F8084 0x021F8084 thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 *   _u32_div_f 0x0209C2B0 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
#include "../include/Obj03823.h"
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
extern void *STA_ACTING_GetActorSystem(char *p);
extern int func_021FAEE8(char *p);
extern void func_021F8084(void *unused, u32 *p, const u32 *q);
extern void func_021FADF8(char *p, char *q);
extern const s16 FX_SinCosTable_[];
void func_021FB8CC(int unused, char *p)
{
    void *ctx;
    ctx = STA_ACTING_GetActorSystem(((struct Obj03823 *)p)->f0);
    if (func_021FAEE8(p) == 2) {
        Vec zero = { 0, 0, 0 };
        func_021F8084(ctx, ((struct Obj03823 *)p)->f10, (const u32 *)(&zero));
        func_021FADF8(((struct Obj03823 *)p)->f18, ((struct Obj03823 *)p)->f1C);
        return;
    }
    else {
        Vec v;
        int sine;
        v.x = 0;
        sine = FX_SinCosTable_[((int)(((u32)((struct Obj03823 *)p)->f4 << 15) / (u32)((struct Obj03823 *)p)->f8) >> 4) * 2];
        v.y = -(int)(((long long)sine * ((struct Obj03823 *)p)->f14 + 0x800) >> 12);
        v.z = 0;
        func_021F8084(ctx, ((struct Obj03823 *)p)->f10, (const u32 *)(&v));
    }
}
