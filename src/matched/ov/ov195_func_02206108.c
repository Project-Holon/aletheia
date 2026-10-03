/*
 * function: func_02206108
 * address:  0x02206108
 * packet:   pkt_02206108
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022060C8 0x022060C8 thumb ov195
 *   func_02206274 0x02206274 thumb ov195
 *   func_02017270 0x02017270 thumb
 *   func_02015FF0 0x02015FF0 thumb
 *   func_020173B4 0x020173B4 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015E04 0x02015E04 thumb
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *
 * mwccarm calls the add helper (0x0209C95C) _fadd and the subtract helper
 * (0x0209CB8C) _fsub, as layout/runtime_arm9.txt now does (swapped there
 * until 2026-09-28).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Owner {
    u8 pad00[4];
    void *res0;
    u32 f08;
    u8 pad0c[4];
    void *res1;
    u8 pad14[0x44 - 0x14];
    float scale;
    u8 pad48[4];
    void *sys;
    void *obj[2];
} Owner;

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

extern fx32 func_022060C8(void *res);
extern void func_02206274(Owner *o);
extern void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_02015FF0(void *obj, int v);
extern void func_020173B4(void *obj);
extern void func_02015CAC(void *obj, VecFx32 *scale);
extern void func_02015EA0(void *obj);
extern void func_02015E04(void *obj);

void func_02206108(Owner *o)
{
    u8 i;
    VecFx32 scale;

    for (i = 0; i < 2; i++)
        o->obj[i] = 0;
    scale.x = FX_F32_TO_FX32(o->scale);
    scale.y = FX_F32_TO_FX32(o->scale);
    scale.z = 0x1000;
    if (o->f08 == 0) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                o->obj[i] = func_02017270(o->sys, o->res0, 0, 0, func_022060C8(o->res0), 0);
            else
                o->obj[i] = func_02017270(o->sys, o->res1, 0, 0, func_022060C8(o->res1), 0);
            func_02015FF0(o->obj[i], 1);
            func_020173B4(o->obj[i]);
            func_02015CAC(o->obj[i], &scale);
            if (i != 0) {
                func_02015EA0(o->obj[i]);
                func_02015E04(o->obj[i]);
            }
        }
    } else {
        o->obj[1] = func_02017270(o->sys, o->res0, 0, 0, func_022060C8(o->res0), 0);
        func_02015FF0(o->obj[1], 1);
        func_020173B4(o->obj[1]);
        func_02015CAC(o->obj[1], &scale);
    }
    func_02206274(o);
}
