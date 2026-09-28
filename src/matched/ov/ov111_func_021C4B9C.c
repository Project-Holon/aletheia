/*
 * function: func_021C4B9C
 * address:  0x021C4B9C
 * packet:   pkt_ov111_021C4B9C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_0202DCD4  0x0202DCD4  thumb
 *   func_0202DCB0  0x0202DCB0  thumb
 *   func_021C479C  0x021C479C  thumb  ov111
 *   func_021C4B74  0x021C4B74  thumb  ov111
 *   func_021C58E0  0x021C58E0  thumb  ov111
 *   func_021C5ACC  0x021C5ACC  thumb  ov111
 *   func_021C631C  0x021C631C  thumb  ov111
 *   _ll_mul          0x0209C054  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef int fx32;
typedef long long fx64;

typedef struct {
    u8 pad0[4];
    void *bg[8];
    u8 pad24[8];
    u8 pix[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x303C - 0x3038];
    fx32 scaleX;
    fx32 scaleY;
    u8 pad3044[4];
    int angle;
    u8 pad304C[0x32B0 - 0x304C];
    void *f32B0;
    u8 pad32B4[0x32C6 - 0x32B4];
    u8 state;
    u8 blink;
    u8 phase;
    u8 pad32C9;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
} Work;

extern s16 FX_SinCosTable_[];
extern void func_020061E4(int se);
extern void func_0202DCD4(void *p, u32 a, u32 b);
extern void func_0202DCB0(void *p, u32 a, u32 b);
extern void func_021C479C(Work *p);
extern void func_021C4B74(Work *p, int flag);
extern void func_021C58E0(Work *p);
extern void func_021C5ACC(u32 bg, const void *src, int mode);
extern void func_021C631C(Work *p, void **bg);

static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

int func_021C4B9C(Work *p)
{
    int done = 0;

    switch (p->state) {
    case 0:
        p->angle = 0;
        p->scaleX = 0x103D;
        p->scaleY = 0x103D;
        func_020061E4(0x65A);
        if (p->f3034 == 0) {
            func_0202DCD4(p->f32B0, 0, 0);
        }
        p->state++;
        break;
    case 1:
        p->scaleX = FX_Mul(FX_SinCosTable_[(p->angle >> 4) * 2 + 1], 0x103D);
        if (p->scaleX <= 0x80) {
            p->scaleX = 0x80;
            p->state++;
        }
        p->angle += 0x400;
        if (p->angle >= 0x4000) {
            p->angle = 0x4000;
        }
        break;
    case 2:
        p->f3034 ^= 1;
        func_021C479C(p);
        func_021C4B74(p, p->f3034);
        p->state++;
        break;
    case 3:
        if (p->f3034 == 0) {
            func_021C58E0(p);
        } else {
            func_021C5ACC(7, p->pix, p->phase);
        }
        p->state++;
        break;
    case 4:
        func_021C631C(p, p->bg);
        p->state++;
        break;
    case 5:
        p->angle -= 0x400;
        if (p->angle <= 0) {
            p->angle = 0;
        }
        p->scaleX = FX_Mul(FX_SinCosTable_[(p->angle >> 4) * 2 + 1], 0x103D);
        if (p->scaleX <= 0x80) {
            p->scaleX = 0x80;
        }
        if (p->angle == 0) {
            p->scaleX = 0x1000;
            p->scaleY = 0x1000;
            done = 1;
            if (p->f3034 == 0) {
                func_0202DCB0(p->f32B0, 0, 1);
                func_0202DCD4(p->f32B0, 0, 1);
            }
        }
        break;
    }
    p->dirty = 1;
    return done;
}
