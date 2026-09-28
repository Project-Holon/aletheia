/*
 * function: func_0220851C
 * address:  0x0220851C
 * packet:   pkt_0220851C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208E4C 0x02208E4C data
 *   d_02208E38 0x02208E38 data
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *
 * The rounding is the SDK FX_F32_TO_FX32 shape applied to an integer
 * (x * 4096 is an int multiply, converted for the +-0.5f). mwccarm calls
 * the add helper (0x0209C95C) as _fadd and the subtract helper
 * (0x0209CB8C) as _fsub, as layout/runtime_arm9.txt now does (swapped
 * there until 2026-09-28).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
typedef s16 fx16;

typedef struct Quad {
    u32 tex;
    u32 pltt;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u32 polyId;
    fx32 s0, s1, t0, t1;
    u8 alpha;
    u8 pad35;
    fx16 v[4][3];
    u8 f4e;
} Quad;

extern const s16 d_02208E4C[];
extern const u8 d_02208E38[];

#define FX_F32_TO_FX32(x)     ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

void func_0220851C(Quad *p)
{
    u8 i = p->f4e;
    u8 b;

    p->v[3][1] = d_02208E4C[i];
    p->v[0][1] = p->v[3][1];
    b = d_02208E38[i];
    p->t0 = FX_F32_TO_FX32(b);
}
