/*
 * function: func_021FD8CC
 * address:  0x021FD8CC
 * packet:   pkt_ov094_021FD8CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   MTX_MultVec43  0x0207BC08  arm
 *   func_021FE1B8  0x021FE1B8  thumb  ov094
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   _ll_mul  0x0209C054  arm
 *
 * The 5 and default arms are separate `else if` / `else` blocks with the
 * whole MUL repeated; the compiler cross-jumps their common tail, and the
 * 0 high word of the rounding addend stays CSE'd in r4 across all three
 * arms (a ternary index colours it differently).
 * Caller func_021FD1CC (same lane) shows s is a 0x60 object: 3x3 matrix,
 * pos at 0x24, counters from 0x30.
 */
typedef signed short s16;
typedef unsigned short u16;
typedef struct { int x, y, z; } VecFx32;
extern const s16 FX_SinCosTable_[];
extern int BUTTON_MAN_GetUserData(void *p);
extern void MTX_MultVec43(const VecFx32 *a, const void *b, VecFx32 *out);
extern void BUTTON_MAN_SetEmitterPos(void *p, const VecFx32 *v);
extern void func_021FE1B8(VecFx32 *v, const VecFx32 *ofs);
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))
void func_021FD8CC(void *p, int active)
{
    VecFx32 v;
    u16 a;
    u16 b;
    int *s;

    s = (int *)BUTTON_MAN_GetUserData(p);
    if (s[18] == 0 || active == 0)
        return;
    if (s[19] == 3) {
        if (s[20] != 0) {
            s[20]--;
            return;
        }
        s[22] += 0xc;
        s[21] += s[22];
        s[20] = s[21] >> 12;
    }
    s[18]--;
    s[14] += s[16];
    s[15] += s[17];
    a = (s[14] >> 12) + 0xc000;
    b = (s[15] >> 12) + 0xc000;
    v.x = FX_SinCosTable_[(a >> 4) * 2];
    v.x = MUL(v.x, s[12]);
    v.x += s[12];
    if (s[19] == 6) {
        v.z = FX_SinCosTable_[(b >> 4) * 2 + 1];
        v.z = MUL(v.z, s[13]);
        v.y = 0;
    } else if (s[19] == 5) {
        v.y = FX_SinCosTable_[(b >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    } else {
        v.y = FX_SinCosTable_[(a >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    }
    MTX_MultVec43(&v, s, &v);
    if (s[23] != 0)
        func_021FE1B8(&v, 0);
    BUTTON_MAN_SetEmitterPos(p, &v);
}
