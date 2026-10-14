/*
 * function: ZUKAN_DETAIL_INFO_HandleTouchLanguageButton
 * address:  0x021BEFA0
 * packet:   pkt_ov208_021BEFA0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note (2026-10-05, integrator): EXACT. The rect bytes are read through a byte pointer with the offset in a local (k = 0x20, c[k] .. c[k + 3]), as in ov208 021C6760; the byte loads then come before x.
 * 2026-10-04 (D2-16): also tried positive forms `x0 <= x && x < x0+w` (13 bytes out, shape changes) and `x0 > x` with u32 or int casts and
 * no locals (13 to 15 bytes out). With `x0 > x` the compare order is right but x0 lands in r0 and x in r1 (the image has x0 in r1);
 * with `x < x0` the registers are right and the compare order flips. The residue is one register colour pair.
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x0 > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x0 > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   ov208_func_021BF280  0x021BF280  thumb  ov208
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct E {
    u8 pad0[0x1c];
    int h1c;
    u8 x0;
    u8 y0;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 f26;
    u8 pad28[4];
    u32 f2c;
    u8 pad30[4];
};

struct S {
    u8 pad0[0x94];
    u32 cur;
    u32 prev;
};

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
struct Obj;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void ov208_func_021BF280(void *first, char *q, void *third, int next);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_020355D8(u8 v);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(int p, u32 on);

int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *a0, struct S *st, int *obj)
{
    int sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct E *e;
    u8 *c;
    int k;

    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    res = 0;
    if (st->cur == 6 && TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct E *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (CLACT_GetActorDrawEnable((struct Obj *)e->h1c) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->prev == i) break;
                st->cur = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ov208_func_021BF280(a0, (char *)st, obj, st->cur);
        *(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1;
        e = (struct E *)((u8 *)st + st->cur * 0x14);
        CLACT_SetActorAnimSeq((struct Obj *)e->h1c, e->f26);
        GFL_USE_PlaySeDefaultVolume(0x54a);
        func_020355D8(1);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(sc, 0);
    }
    return res;
}
