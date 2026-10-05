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
 * symbols:
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE1E4 0x021BE1E4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8BAC 0x021B8BAC thumb ov172
 *   func_020862F0 0x020862F0 arm
 *   func_0207ECF0 0x0207ECF0 arm
 *   func_0207E100 0x0207E100 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0207C778 0x0207C778 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_0202EB14 0x0202EB14 thumb
 *
 * note (2026-10-04, wave D3 lane 09): DIFF, 106 bytes, size 960 equals the
 * original. Closed so far: sub == 0 as an if/else around the rest (not an early
 * return: the original has a far "b" to the end), halve branch with raw
 * *(u16 *)((u8 *)q + 0x48 + i * 0x1C) = (u32)... >> 1 (gives the hoisted base
 * pointers and lsrs) while the double branch uses q->ent[i].f <<= 1, the
 * func_020862F0 call written in each dst arm, declaration order sub, wide,
 * base, dst, h, bit (h as int with a (u16) cast, a u16 local takes the lowest
 * slot), w * h * 2. Residue: (1) scale for func_0207C778 is built in r0 then
 * moved to r5, original builds it in r5 directly (tried ternary, if/else, shift
 * forms); m[3] store and "movs r5,#0" swap. (2) copy loop: the original loads
 * ent.h (0x46) before ent.w (0x44) and ent.y (0x42) before ent.x (0x40) and adds
 * (w - ew) * 2 + (dst + rows * 2); the draft loads ent.w first. Writing
 * (w - ew) first fixes the second argument order but not the first. 2 bytes
 * shorter there, so branch targets after +0x34 shift by 2.
 *
 * note (2026-10-05, wD4 lane05): 103 bytes, almost all the 2-byte shift after the copy loop. Closed: the scale
 *   is `s = q->f20 == 1 ? 0x2000 : 0x1000` (tail merge shares the lsls; built in r5 directly); second copy argument
 *   now matches with arg1 written dst + (w - ew) + (j + (h - eh)) * w and arg2 (j + y) * 0x200 + x * 2.
 *   Residue: (1) arg1 order: original loads eh, h, ew(r3), computes j + (h - eh), copies it to r2 before muls,
 *   then w - ew, then (w - ew) * 2 + (dst + A * 2); ours computes w - ew first (2 bytes shorter, no copy).
 *   Tried dst + A + B, (B) + (dst + A), &dst[A] + B, dst + (A + B). (2) m[3] store and `movs r5,#0` swap
 *   (tried m[2] = m[1] = 0 and m[1], m[2] before m[3]: no gain).
 *
 * note (2026-10-05, wD5 lane07): 47 bytes (was 103), size and all branch targets now match. Fix: the row term as a
 *   named loop-body local `int r = j + (h - q->ent[i].h);` (gives the original's `adds r2,r1,#0` copy before muls).
 *   Residue: (1) the loop body loads ent.w (0x44) first and adds dst + (w - ew) before the r*w term; the original
 *   loads eh, h, computes r, then ew, and adds (w - ew)*2 + (dst + r*w*2). Tried dst + r*w + (w - ew) with and
 *   without an ew local (54 bytes, ew load still first). (2) m[3] store and `movs r5,#0` swap (unchanged).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u8 pad[0xC];
} Ent;

typedef struct Q {
    u32 f0;
    char *f4;
    char *f8;
    char *fC;
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
    u8 pad34[0xC];
    Ent ent[4];
} Q;

extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021BE054(void *p);
extern void func_021BE1E4(void *p);
extern u32 func_021B8B8C(void *p, u32 base, int i);
extern u8 func_021B8BAC(void *p, u32 base, int i);
extern void func_020862F0(void *p, u32 n);
extern void func_0207ECF0(const void *src, u32 off, u32 size);
extern void *func_0207E100(void);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern int func_0207C778(int);
extern void func_0207D59C(void *, int *, int, int, int, int);
extern int func_0202EB14(void);

void func_021B71B8(void *p, Q *q)
{
    int sub;
    u32 wide;
    u32 base;
    u16 *dst;
    int h;
    int bit;
    u8 i;
    int m[4];

    sub = func_021BE05C(p);
    wide = func_021BE078(p);
    base = func_021BDFE4(p);
    if (func_021BE054(p) < 2)
        return;
    if (sub == 0) {
        if (q->f10 != 0) {
            func_020862F0((u16 *)q->f4, 0x18000);
            func_0207ECF0(q->f4, 0, 0x18000);
            q->f10 = 0;
        }
    } else {
        if (q->f14 == 1) {
            u8 n = 0;
            for (i = 0; i < 4; i++) {
                if ((1 << i) & q->f10)
                    n++;
            }
            if (n != func_021BE054(p))
                return;
            if (q->f2c < 2) {
                q->f10 = 0;
                q->f2c++;
                for (i = 0; i < 4; i++) {
                    if (func_021B8B8C(p, base, i) == 1 && func_021B8BAC(p, base, i) == 0)
                        q->f10 |= (u8)(1 << i);
                }
                return;
            }
            if (q->f2d < 0xC0)
                return;
            if (q->f18 == 1) {
                q->f2d = 0;
                q->f30 = 1;
                q->f18 = 0;
                *(volatile u16 *)0x04000040 = 0xFF;
                *(volatile u16 *)0x04000044 = 0;
                *(volatile u16 *)0x04000042 = 0x8000;
                *(volatile u16 *)0x04000046 = 0;
            }
            if (q->f1c == 1) {
                q->f1c = 0;
                func_021BE1E4(p);
            }
            func_02082A7C(0, func_0207E100(), 0x18000);
            q->f14 = 0;
            if (q->f20 != func_021BE078(p)) {
                int s;
                q->f20 = func_021BE078(p);
                s = q->f20 == 1 ? 0x2000 : 0x1000;
                m[0] = func_0207C778(s);
                m[3] = func_0207C778(s);
                m[1] = 0;
                m[2] = 0;
                func_0207D59C((void *)0x04000030, m, 0, 0, 0, 0);
                for (i = 0; i < 4; i++) {
                    if (q->f20 == 1) {
                        *(u16 *)((u8 *)q + 0x48 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x48 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4A + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4A + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4C + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4C + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x4E + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x4E + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x40 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x40 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x42 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x42 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x44 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x44 + i * 0x1C) >> 1;
                        *(u16 *)((u8 *)q + 0x46 + i * 0x1C) = (u32)*(u16 *)((u8 *)q + 0x46 + i * 0x1C) >> 1;
                    } else {
                        q->ent[i].a <<= 1;
                        q->ent[i].b <<= 1;
                        q->ent[i].c <<= 1;
                        q->ent[i].d <<= 1;
                        q->ent[i].x <<= 1;
                        q->ent[i].y <<= 1;
                        q->ent[i].w <<= 1;
                        q->ent[i].h <<= 1;
                    }
                }
            }
            q->f30 = 0;
        }
        for (i = 0; i < 4; i++) {
            bit = 1 << i;
            if (!(bit & q->f10))
                continue;
            if (func_021B8B8C(p, base, i) == 1) {
                u32 idx = i;
                int w;
                u32 size;
                int j;
                if (sub == 1 && idx != 0)
                    idx = 1;
                if (wide == 0) {
                    w = 0x80;
                    h = (u16)(sub == 1 ? 0xC0 : 0x60);
                } else {
                    w = 0x40;
                    h = (u16)(sub == 1 ? 0x60 : 0x30);
                }
                if (func_021B8BAC(p, base, i) == 1 && func_0202EB14() == 0) {
                    dst = (u16 *)(q->f4 + idx * (w * h * 2));
                    func_020862F0(dst, w * h * 2);
                } else if (wide == 0) {
                    if (sub == 1) {
                        dst = (u16 *)q->f8;
                        func_020862F0(dst, 0xC000);
                    } else {
                        dst = (u16 *)(q->f8 + 0x3000);
                        func_020862F0(dst, 0x6000);
                    }
                } else {
                    if (sub == 1) {
                        dst = (u16 *)q->fC;
                        func_020862F0(dst, 0x3000);
                    } else {
                        dst = (u16 *)(q->fC + 0xC00);
                        func_020862F0(dst, 0x1800);
                    }
                }
                for (j = 0; j < q->ent[i].h; j++) {
                    int r = j + (h - q->ent[i].h);
                    func_0207ECF0(dst + (w - q->ent[i].w) + r * w,
                                  (j + q->ent[i].y) * 0x200 + q->ent[i].x * 2,
                                  q->ent[i].w * 2);
                }
            }
            q->f10 -= (u8)bit;
        }
    }
}
