/*
 * function: func_022010D0
 * address: 0x022010D0
 * packet: pkt_ov094_022010D0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate x/y/z clears preserve the original store order.
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   FX_SinCosTable_ 0x020A1B38 data a4
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 */
#include "../include/Obj02439.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef long long s64;
typedef struct Vec { int x, y, z; } Vec;
extern int func_022019F4(char *, int);
extern void func_021F89BC(void *);
extern const s16 FX_SinCosTable_[];
extern void MCSS_SetOfsPosition(void *, u32 *);
#define FIX(x) ((int)(((x) > 0.0f) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
void func_022010D0(void *task, char *q)
{
    char *p = *(char * *)&((struct Obj02439 *)q)->f0;
    Vec v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj02439 *)q)->f4);
    char *e;
    int off;
    int n, f;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj02439 *)q)->f28 != *(u8 *)(p + ((struct Obj02439 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    ((struct Obj02439 *)q)->f18 += ((struct Obj02439 *)q)->f1C;
    n = FX_SinCosTable_[((((struct Obj02439 *)q)->f18 & 0x0ffff000) >> 16) * 2];
    f = FIX((float)n / 4096.0f);
    f = (int)(((s64)f * ((struct Obj02439 *)q)->f20 + 0x800) >> 12);
    if (((struct Obj02439 *)q)->f14 != 0) v.y = f;
    else v.x = f;
    MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
    ((struct Obj02439 *)q)->f24 -= 1;
    if (((struct Obj02439 *)q)->f24 == 0) {
        v.x = 0;
        v.y = 0;
        v.z = 0;
        MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
        func_021F89BC(task);
    }
}
