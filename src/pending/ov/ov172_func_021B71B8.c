/*
 * function: func_021B71B8
 * address: 0x021B71B8
 * packet: pkt_ov172_021B71B8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-02 first pass, 110 bytes left, control flow and all calls match. Keys: the mode==0
 *   block is the if arm of an if/else that holds the rest (own `b end`, not the shared trampoline);
 *   halving is `/= 2` (lsrs plus hoisted field pointers), doubling `<<= 1`; size is w * h * 2.
 *   Residue: (1) scale select lands in r0 then `lsls r5, r0`, the original selects straight into r5
 *   (ternary, if/else + `<<= 12`, `* 0x1000`, block-scoped scale all inert); (2) spill slots for
 *   bit and h are swapped (orig bit sp+0x10, h sp+0x14; declaration order and block scope inert);
 *   (3) inner ECF0 call: original loads ent.h first and keeps ent.w in r3 until the size arg, ours
 *   loads ent.w first (u16 *dst, &dst[..] form, j + h - eh form, distributed offset all inert).
 *   func_021B8B8C/8BAC take `int unused` in their matched definitions, hence (int)p.
 * symbols:
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8BAC 0x021B8BAC thumb ov172
 *   func_021BE1E4 0x021BE1E4 thumb ov172
 *   func_020862F0 0x020862F0 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_0207E100 0x0207E100 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0207C778 0x0207C778 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_0202EB14 0x0202EB14 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long fx32;
typedef volatile u16 vu16;

typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

typedef struct {
    u8 pad00[0xc];
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
} Ent;

typedef struct {
    u8 pad00[4];
    u8 *f4;
    u8 *f8;
    u8 *fc;
    u8 f10;
    u8 pad11[3];
    int f14;
    int f18;
    int f1c;
    u32 f20;
    u8 pad24[8];
    u8 f2c;
    u8 f2d;
    u8 pad2e[2];
    int f30;
    Ent ent[4];
} Work;

extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021BE054(void *p);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern u8 func_021B8BAC(int unused, char *base, int i);
extern void func_021BE1E4(u8 *p);
extern void func_020862F0(void *startAddr, u32 nBytes);
extern void func_0207ECF0(const void *src, u32 offset, u32 size);
extern void *func_0207E100(void);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern fx32 func_0207C778(fx32 v);
extern void func_0207D59C(u32 addr, const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1);
extern int func_0202EB14(void);

void func_021B71B8(void *p, Work *s)
{
    int mode;
    u32 big;
    u32 base;
    u8 *dst;
    int bit;
    u16 h;
    u8 k, n;
    int w, idx, j;
    fx32 scale;
    MtxFx22 mtx;

    mode = func_021BE05C(p);
    big = func_021BE078(p);
    base = func_021BDFE4(p);
    if (func_021BE054(p) < 2)
        return;
    if (mode == 0) {
        if (s->f10 != 0) {
            func_020862F0(s->f4, 0x18000);
            func_0207ECF0(s->f4, 0, 0x18000);
            s->f10 = 0;
            return;
        }
    } else {
    if (s->f14 == 1) {
        n = 0;
        for (k = 0; k < 4; k++) {
            if ((1 << k) & s->f10)
                n++;
        }
        if (n != func_021BE054(p))
            return;
        if (s->f2c < 2) {
            s->f10 = 0;
            s->f2c++;
            for (k = 0; k < 4; k++) {
                if (func_021B8B8C((int)p, (char *)base, k) == 1 && func_021B8BAC((int)p, (char *)base, k) == 0)
                    s->f10 |= 1 << k;
            }
            return;
        }
        if (s->f2d < 0xC0)
            return;
        if (s->f18 == 1) {
            s->f2d = 0;
            s->f30 = 1;
            s->f18 = 0;
            *(vu16 *)0x04000040 = 0xFF;
            *(vu16 *)0x04000044 = 0;
            *(vu16 *)0x04000042 = 0x8000;
            *(vu16 *)0x04000046 = 0;
        }
        if (s->f1c == 1) {
            s->f1c = 0;
            func_021BE1E4(p);
        }
        func_02082A7C(0, func_0207E100(), 0x18000);
        s->f14 = 0;
        if (s->f20 != func_021BE078(p)) {
            s->f20 = func_021BE078(p);
            scale = (s->f20 == 1 ? 2 : 1) << 12;
            mtx._00 = func_0207C778(scale);
            mtx._11 = func_0207C778(scale);
            mtx._01 = 0;
            mtx._10 = 0;
            func_0207D59C(0x04000030, &mtx, 0, 0, 0, 0);
            for (k = 0; k < 4; k++) {
                if (s->f20 == 1) {
                    s->ent[k].a /= 2;
                    s->ent[k].b /= 2;
                    s->ent[k].c /= 2;
                    s->ent[k].d /= 2;
                    s->ent[k].x /= 2;
                    s->ent[k].y /= 2;
                    s->ent[k].w /= 2;
                    s->ent[k].h /= 2;
                } else {
                    s->ent[k].a *= 2;
                    s->ent[k].b *= 2;
                    s->ent[k].c *= 2;
                    s->ent[k].d *= 2;
                    s->ent[k].x *= 2;
                    s->ent[k].y *= 2;
                    s->ent[k].w *= 2;
                    s->ent[k].h *= 2;
                }
            }
        }
        s->f30 = 0;
    }
    for (k = 0; k < 4; k++) {
        bit = 1 << k;
        if (bit & s->f10) {
            if (func_021B8B8C((int)p, (char *)base, k) == 1) {
                idx = k;
                if (mode == 1 && idx != 0)
                    idx = 1;
                if (big == 0) {
                    w = 0x80;
                    h = (mode == 1) ? 0xC0 : 0x60;
                } else {
                    w = 0x40;
                    h = (mode == 1) ? 0x60 : 0x30;
                }
                if (func_021B8BAC((int)p, (char *)base, k) == 1 && func_0202EB14() == 0) {
                    dst = s->f4 + idx * (w * h * 2);
                    func_020862F0(dst, w * h * 2);
                } else if (big == 0) {
                    if (mode == 1) {
                        dst = s->f8;
                        func_020862F0(dst, 0xC000);
                    } else {
                        dst = s->f8 + 0x3000;
                        func_020862F0(dst, 0x6000);
                    }
                } else {
                    if (mode == 1) {
                        dst = s->fc;
                        func_020862F0(dst, 0x3000);
                    } else {
                        dst = s->fc + 0xC00;
                        func_020862F0(dst, 0x1800);
                    }
                }
                for (j = 0; j < s->ent[k].h; j++) {
                    func_0207ECF0((u16 *)dst + (h - s->ent[k].h + j) * w + (w - s->ent[k].w),
                                  s->ent[k].x * 2 + (j + s->ent[k].y) * 512, s->ent[k].w * 2);
                }
            }
            s->f10 -= (u8)bit;
        }
    }
    }
}
