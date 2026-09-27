/*
 * function: func_02206274
 * address:  0x02206274
 * packet:   pkt_02206274
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015F0C 0x02015F0C thumb
 *   func_02015F1C 0x02015F1C thumb
 *   func_02015F14 0x02015F14 thumb
 *   func_02015C78 0x02015C78 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fgr 0x0209BBB0 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *
 * mwccarm calls the add helper (0x0209C95C) _fadd and the subtract helper
 * (0x0209CB8C) _fsub; layout/runtime_arm9.txt lists the two swapped.
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
    u8 pad00[0x44];
    float scale;
    u8 pad48[0x50 - 0x48];
    void *obj[2];
} Owner;

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

extern u32 func_02015F0C(void *obj);
extern s32 func_02015F1C(void *obj);
extern s32 func_02015F14(void *obj);
extern void func_02015C78(void *obj, VecFx32 *pos);

void func_02206274(Owner *o)
{
    u8 i;
    float w, h, d;
    float x, y;
    VecFx32 pos;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            w = func_02015F0C(o->obj[i]);
            h = func_02015F1C(o->obj[i]);
            d = func_02015F14(o->obj[i]);
            w = w * (o->scale / 16.0f);
            if (w > 96.0f)
                w = 96.0f;
            h = h * (o->scale / 16.0f);
            d = d * (o->scale / 16.0f);
            x = ((96.0f - w) / 2.0f + h) * 0.33f;
            y = (0.0f - d) * 0.33f;
            pos.x = FX_F32_TO_FX32(y);
            pos.y = FX_F32_TO_FX32(x);
            pos.z = 0;
            func_02015C78(o->obj[i], &pos);
        }
    }
}
