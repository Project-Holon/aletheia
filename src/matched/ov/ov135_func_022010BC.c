/*
 * function: func_022010BC
 * address:  0x022010BC
 * packet:   pkt_022010BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker: the call target 0x0200FB4C (arm9, Thumb leaf) has no label, so its
 * relocation stays wildcarded (requested in docs/sessions/2026-09-27/arm9_requests.md).
 * The four ov114 targets 0x021B97F4, 0x021B99F0, 0x021B99F4, 0x021B9A14 were seeded
 * by tree_ov135_4. Every other byte is identical. Labelling 0x0200FB4C makes this EXACT.
 *
 * symbols:
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0220254C  0x0220254C  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C968  0x0203C968  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0x38 - 0x2C];
    int err;
    u8 pad3C[0xE4 - 0x3C];
    u8 mon[0x10E0 - 0xE4];
    void *wm;
    u8 valid;
    u8 pad10E5[3];
    u32 count;
    u8 buf[0x80];
    u8 pad116C[0x1328 - 0x116C];
    u32 done;
} Work;

extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern void func_021B9774(u8 *p);
extern void func_021B99B8(u8 *p);
extern void func_021B9838(u8 *p);
extern int func_021B99F0(u8 *p);
extern u32 func_021B99F4(u32 p, u32 i);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern void func_0200FB4C(u32 id);
extern void func_0200F7B8(u32 v);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_0220254C(void *mon, u32 heap);
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);

int func_022010BC(Work *p)
{
    int st;
    int r;
    void *rec;

    st = func_021B99DC(p->wm);
    r = func_021B9790(p->wm);
    if (r == 0) {
        rec = func_021B97F4(p->wm);
        switch (st) {
        case 400:
            func_0200FB4C(0x41);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        case 401:
            func_0200FB4C(0x42);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        case 408:
            func_0200FB4C(0x44);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        default:
            func_0200FB4C(0x43);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        case 200:
            p->valid = func_021B99F0(rec);
            p->count = func_021B99F4((u32)rec, 0);
            func_02082D44(func_021B9A14(rec, 1), p->buf, 0x80);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            if (p->valid == 0) {
                if (p->count == 0) {
                    p->state = 4;
                } else if (p->done == 0) {
                    p->done++;
                    p->state = 2;
                    func_0220254C(p->mon, 0x48);
                } else {
                    p->err = -7;
                    p->state = 0x2D;
                }
            } else if (p->done == 0) {
                p->done++;
                p->state = 2;
                func_0220254C(p->mon, 0x48);
            } else {
                p->err = -7;
                p->state = 0x2D;
            }
            break;
        }
    } else if (r != 0xF) {
        p->err = -15;
        p->state = 0x2B;
        func_021B99B8(p->wm);
        func_021B9838(p->wm);
        func_0200FBB0();
        func_0203CA04();
        func_0200FBA0();
        func_0203C968();
    }
    return 2;
}
