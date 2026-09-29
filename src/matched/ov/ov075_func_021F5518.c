/*
 * function: func_021F5518
 * address:  0x021F5518
 * packet:   pkt_ov075_021F5518
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state proc; its states 1-3 are func_021F536C's states 4-6, and the
 * shape follows ov073's func_021F53C8.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021F54A0  0x021F54A0  thumb  ov075
 *   func_0204047C  0x0204047C  arm
 *   func_021899F0  0x021899F0  thumb  ov021
 *   func_02080C44  0x02080C44  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02080294  0x02080294  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_02040588  0x02040588  arm
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_02012374  0x02012374  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    int f0;
    u32 f4;
    int f8;
    u32 fC;
    int f10;
    u32 f14;
    u8 pad18[0xC];
    u32 f24;
    int (*f28)(void *sys);
} Work;

extern void *func_020124E4(void *task);
extern void *func_0201210C(void *p);
extern void func_021F54A0(Work *w);
extern void func_0204047C(int idx, u16 val);
extern u32 func_021899F0(u8 *p);
extern u16 func_02080C44(void);
extern void func_02080B98(void);
extern void func_02080294(u32 bank);
extern u32 func_021F54E0(void);
extern void func_02040588(u32 which, u32 enable);
extern void func_021899F8(u8 *p, u32 v);
extern int func_02189A08(int a);
extern u32 func_021CF560(u32 *p);
extern void func_02012374(void *a, int b);

int func_021F5518(void *task, int *st, Work *w)
{
    void *t;
    void *v;
    u32 bank;
    int r;

    t = func_020124E4(task);
    v = func_0201210C(t);
    switch (*st) {
    case 0:
        func_021F54A0(w);
        *st = *st + 1;
        break;
    case 1:
        if (w->f10 != 0) {
            func_0204047C(0, 0);
            func_0204047C(2, 3);
            w->fC = func_021899F0((u8 *)v);
            bank = func_02080C44();
            w->f4 = bank;
            w->f8 = 0;
            if ((bank & 8) == 0) {
                w->f4 = bank | 8;
                w->f8 = 1;
            }
            func_02080B98();
            func_02080294(w->f4);
            w->f14 = func_021F54E0();
            *st = *st + 1;
        }
        break;
    case 2:
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_021899F8((u8 *)v, 2);
        r = w->f28(t);
        w->f24 = func_021CF560((u32 *)func_02189A08((int)v));
        func_02012374(task, r);
        *st = *st + 1;
        break;
    case 3:
        if (w->f8 == 1) {
            w->f4 &= ~8;
            func_02080294(w->f4);
        }
        func_021899F8((u8 *)v, w->fC);
        return 1;
    }
    return 0;
}
