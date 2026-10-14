/*
 * function: BTLV_MCSS_ShakeTaskMain
 * address: 0x02200E1C
 * packet: pkt_ov094_02200E1C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   _ll_mul 0x0209C054 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 */
#include "../include/Obj00264.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef long long s64;
typedef struct Vec { int x, y, z; } Vec;
extern int BTLV_MCSS_FindSpriteIndex(char *, int);
extern void BTLV_EFFECT_DeleteTask(void *);
extern const s16 FX_SinCosTable_[];
extern void MCSS_SetOfsPosition(void *, u32 *);
#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))
void BTLV_MCSS_ShakeTaskMain(void *task, char *q)
{
    char *p = *(char * *)&((struct Obj00264 *)q)->f0;
    Vec v = {0, 0, 0};
    int i = BTLV_MCSS_FindSpriteIndex(p, ((struct Obj00264 *)q)->f4);
    char *e;
    int off;
    int x, y;
    int j;
    if (i == -1) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (((struct Obj00264 *)q)->f38 != *(u8 *)(p + ((struct Obj00264 *)q)->f4 + 0x542)) {
        BTLV_EFFECT_DeleteTask(task);
        return;
    }
    if (((struct Obj00264 *)q)->f34 == 0) {
        if (((struct Obj00264 *)q)->f30 == ((struct Obj00264 *)q)->f1C) {
        ((struct Obj00264 *)q)->f30 = 0;
        if (((struct Obj00264 *)q)->f8 & 1)
            ((struct Obj00264 *)q)->f28 -= ((struct Obj00264 *)q)->f2C;
        else
            ((struct Obj00264 *)q)->f28 += ((struct Obj00264 *)q)->f2C;
        if (((struct Obj00264 *)q)->f28 & 0xffff0000) {
            ((struct Obj00264 *)q)->f28 = (u16)((struct Obj00264 *)q)->f28;
            ((struct Obj00264 *)q)->f20 -= 1;
            ((struct Obj00264 *)q)->f34 = ((struct Obj00264 *)q)->f24;
        }
        if (((struct Obj00264 *)q)->f20 != 0) {
            switch (((struct Obj00264 *)q)->fC) {
            case 0:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = FX_SinCosTable_[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                x += ((struct Obj00264 *)q)->f10;
                break;
            case 1:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10) - ((struct Obj00264 *)q)->f10;
                y = FX_SinCosTable_[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14);
                break;
            case 2:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = FX_SinCosTable_[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                y += ((struct Obj00264 *)q)->f14;
                break;
            case 3:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = FX_SinCosTable_[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10);
                y = FX_SinCosTable_[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14) - ((struct Obj00264 *)q)->f14;
                break;
            }
            switch ((((struct Obj00264 *)q)->f8 & 7) >> 1) {
            default:
            case 0:
                v.z = x;
                v.y = y;
                break;
            case 1:
                v.x = x;
                v.z = y;
                break;
            case 2:
                v.x = x;
                v.y = y;
                break;
            }
        }
        MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
        } else {
            ((struct Obj00264 *)q)->f30 += 1;
        }
    } else {
        ((struct Obj00264 *)q)->f34 -= 1;
    }
    if (((struct Obj00264 *)q)->f20 == 0)
        BTLV_EFFECT_DeleteTask(task);
}
