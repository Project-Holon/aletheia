/*
 * function: func_02172D70
 * address:  0x02172D70
 * packet:   pkt_ov011_02172D70
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02161F74  0x02161F74  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_021735FC  0x021735FC  thumb  ov011
 *   func_02173658  0x02173658  thumb  ov011
 *   func_020392B8  0x020392B8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_02039338  0x02039338  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02012984  0x02012984  thumb
 *   func_02158590  0x02158590  thumb  ov010
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_02161F54  0x02161F54  thumb  ov010
 *   func_02174E3C  0x02174E3C  thumb  ov011
 *   func_02174EAC  0x02174EAC  thumb  ov011
 *   func_02173828  0x02173828  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_02012B70  0x02012B70  thumb
 *   func_02012114  0x02012114  thumb
 *   func_02174978  0x02174978  thumb  ov011
 *   func_02175EB8  0x02175EB8  thumb  ov011
 *   func_0203D378  0x0203D378  arm
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_021739E0  0x021739E0  thumb  ov011
 *   func_02175ED8  0x02175ED8  thumb  ov011
 *   func_02175628  0x02175628  thumb  ov011
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Param {
    void *field00;
    void *field04;
} Param;

typedef struct Work {
    u32   field000;
    void *field004;         /* 0x004 */
    u8    pad008[0x8a - 0x8];
    u8    pad08a : 6;       /* 0x08A */
    u8    mode : 2;
    u8    kind : 6;         /* 0x08B */
    u8    flag08b : 1;
    u8    pad08c[0x8fa - 0x8c];
    u8    field8fa;         /* 0x8FA */
    u8    field8fb;         /* 0x8FB */
    u8    pad8fc;
    u8    step;             /* 0x8FD */
    u8    pad8fe[0x90a - 0x8fe];
    u16   idle;             /* 0x90A */
    u8    pad90c[2];
    s16   timer;            /* 0x90E */
    u8    pad910[0x93f - 0x910];
    u8    bit0 : 1;         /* 0x93F */
    u8    quit : 1;
    u8    bit2 : 1;
    u8    bit3 : 1;
    u8    bit4 : 1;
    u8    bit5 : 1;
    u8    lock : 1;
    u32   stamp : 31;       /* 0x940 */
    u32   warned : 1;
} Work;

extern void *func_02026478(void *p);
extern u32   func_020127C4(void *p);
extern void  func_02161F74(void *p, u32 a, u32 b);
extern int   func_0200FB24(void);
extern void  func_02026400(void *p);
extern u32   func_02035390(void);
extern u32   func_020353B0(void);
extern void  func_021735FC(void *sv, void *p);
extern void  func_02173658(Work *w);
extern int   func_020392B8(void);
extern void  func_0203D7BC(int a);
extern u32   func_02039ACC(void);
extern u32   func_02039338(void);
extern void  func_02012B64(void *sv, u32 a);
extern void *func_02012950(void *sv, int i);
extern void *func_02012944(void *sv);
extern void  func_02008494(void *a, void *b);
extern void  func_02175710(Work *w, u32 a);
extern u8    func_02012984(void *sv);
extern int   func_02158590(void *sv);
extern u32   func_020399A8(void);
extern u32   func_020399B8(u32 a);
extern void  func_02161F54(void *p);
extern void  func_02174E3C(Work *w);
extern void  func_02174EAC(Work *w, u32 a, void *b);
extern int   func_02173828(Work *w);
extern s32   func_0203F4FC(void);
extern int   func_02012B70(void *sv);
extern int   func_02012114(void *p);
extern void  func_02174978(Work *w);
extern int   func_02175EB8(void *p);
extern int   func_0203D378(void);
extern int   func_02175B14(void *p);
extern int   func_021739E0(void);
extern int   func_02175ED8(void *p);
extern int   func_02175628(void);

void func_02172D70(int *state, Param *p, Work *w)
{
    void *sv;
    void *mon;
    s32 base;
    s32 now;

    sv = func_02026478(p->field04);
    if (w != 0 && w->step >= 7) {
        func_02161F74((u8 *)w + 0x35c, func_020127C4(sv), w->field8fb);
    }
    if (func_0200FB24() != 0 || w->quit == 1) {
        if (w->lock) {
            return;
        }
        w->step = 11;
        w->quit = 1;
        func_02026400(w->field004);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1 && w->lock == 0) {
        func_02026400(w->field004);
        return;
    }
    if (w->step == 7 && w->field8fa == 1) {
        func_02026400(w->field004);
        return;
    }
    func_021735FC(sv, (u8 *)w + 0xc);
    func_02173658(w);
    switch (*state) {
    case 0:
        if (func_020392B8() > 1 && w->step < 5) {
            w->step = 5;
            func_0203D7BC(1);
        }
        if (w->step == 5) {
            if (func_02039ACC() == 1) {
                func_02012B64(sv, func_02039338());
                mon = func_02012950(sv, func_02039338());
                func_02008494(func_02012944(sv), mon);
                func_02175710(w, func_02039338());
                w->kind = 0x15;
                w->mode = func_02012984(sv);
                if (func_02158590(sv) == 0) {
                    w->flag08b = 1;
                }
                func_0203D7BC(1);
                (*state)++;
            }
        } else if (w->step == 4) {
            w->timer++;
            if (w->timer > 600) {
                w->timer = 0;
                func_02026400(w->field004);
                return;
            }
        }
        break;
    case 1:
        if (func_020399B8(func_020399A8()) == 1) {
            w->step = 6;
            (*state)++;
        }
        break;
    case 2:
        func_02161F54((u8 *)w + 0x35c);
        func_02174E3C(w);
        func_02174EAC(w, func_02039338(), (u8 *)w + 0x160);
        (*state)++;
        break;
    case 3:
        if (func_02173828(w) == 1) {
            w->step = 7;
            w->stamp = func_0203F4FC();
            (*state)++;
        }
        break;
    case 4:
        if (func_02012B70(sv) == 0 && w->mode != func_02012984(sv)
            && func_02012114(p->field00) == 1) {
            func_02026400(w->field004);
            return;
        }
        func_02174978(w);
        if (func_02175EB8((u8 *)w + 0x1ac) == 1) {
            func_02026400(w->field004);
            return;
        }
        if (func_0203D378() == 1 && func_02175B14((u8 *)w + 0x1ac) == 0) {
            base = w->stamp;
            now = func_0203F4FC();
            if (now < base) {
                now += 86399;
            }
            now -= base;
            if (now >= 180) {
                func_02026400(w->field004);
                return;
            }
            if (now > 170 && w->warned == 0 && func_021739E0() == 1) {
                w->warned = 1;
            }
        } else if (w->lock == 0 && func_0203D378() == 1
                   && func_02175ED8((u8 *)w + 0x1ac) == 1) {
            func_02026400(w->field004);
        } else {
            w->warned = 0;
        }
        if (func_02175628() == 0) {
            w->idle++;
            if (w->idle > 180) {
                func_02026400(w->field004);
                return;
            }
        } else {
            w->idle = 0;
        }
        break;
    }
}
