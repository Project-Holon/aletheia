/*
 * function: func_02184674
 * address:  0x02184674
 * packet:   pkt_ov023_02184674
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The step-table callbacks take (p, *state): the switch value, reused as
 * their second argument, is what keeps it live in r1 through the dispatch
 * (a one-argument callback puts the whole dispatch in r0). func_0218644C
 * is void but leaves r0 = p; no hidden argument here.
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_0218644C  0x0218644C  thumb  ov023
 *   func_020221A4  0x020221A4  thumb
 *   func_021840FC  0x021840FC  thumb  ov022
 *   func_021848A8  0x021848A8  thumb  ov023
 *   func_021848CC  0x021848CC  thumb  ov023
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02185F74  0x02185F74  thumb  ov023
 *   func_02186324  0x02186324  thumb  ov023
 *   func_02185F10  0x02185F10  thumb  ov023
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02184174  0x02184174  thumb  ov022
 *   func_0218417C  0x0218417C  thumb  ov022
 *   func_021867C4  0x021867C4  thumb  ov023
 *   func_0204A600  0x0204A600  arm
 *   func_020310C4  0x020310C4  arm
 *   func_02186708  0x02186708  thumb  ov023
 *   func_0200FB24  0x0200FB24  thumb
 *   d_02186E80     0x02186E80  data   a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00460.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Step {
    int (*fn)(char *p, int state);
    void *f4;
} Step;

extern u16 func_02039338(void);
extern int func_02186558(char *p);
extern void func_0218644C(char *p, int state);
extern u32 func_020221A4(void);
extern void func_021840FC(u32 obj, void (*a)(void), void (*b)(void), char *arg);
struct Tcbl;
extern void func_021848A8(int a, int unused, char *p);
extern void func_021848CC(void);
extern void func_02184560(char *p, int a);
extern void func_02185F74(void *win, int color, char *p);
extern int func_02186324(u8 *p);
extern void func_02185F10(u16 *p);
extern void func_0203A5E4(u32 key);
extern void func_02184174(u8 *p);
extern u32 func_0218417C(u8 *p);
extern void func_021867C4(char *p);
extern void func_0204A600(void);
extern void func_020310C4(struct Tcbl *p);
extern void func_02186708(char *p);
extern u32 func_0200FB24(void);
extern Step d_02186E80[];

int func_02184674(void *task, int *state, int a2, char *p)
{
    int (*fn)(char *p, int state);
    int r;

    if (func_02039338() == 0 && ((struct Obj00460 *)p)->f9280 != 0) {
        ((struct Obj00460 *)p)->f9280 = func_02186558(p) & ((struct Obj00460 *)p)->f9280;
    }
    ((struct Obj00460 *)p)->f194 = *state;
    func_0218644C(p, *state);
    switch (*state) {
    case 0:
        if (func_020221A4() != 0) {
            func_021840FC(**(u32 * *)&((struct Obj00460 *)p)->f4, (void (*)(void))func_021848A8, func_021848CC, p);
            if (func_02039338() == 0) {
                func_02184560(p, 1);
            }
            *state = 1;
        }
        break;
    case 1:
        fn = d_02186E80[*(int *)(p + 0x198)].fn;
        if (fn != 0) {
            *state = fn(p, *state);
        }
        func_02185F74(p + 0x104, 0x44f, p);
        if (func_02039338() == 0) {
            r = func_02186324((u8 *)p);
            if (*state == 1) {
                *state = r;
            }
        }
        func_02185F10((u16 *)(p + 0x4208));
        break;
    case 2:
        fn = d_02186E80[*(int *)(p + 0x198)].fn;
        if (fn != 0 && d_02186E80[*(int *)(p + 0x198)].f4 != 0) {
            *state = fn(p, *state);
        }
        break;
    case 3:
        if (func_020221A4() != 0) {
            func_0203A5E4(0x2900);
            func_02184174((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4));
            *state = 4;
        }
        break;
    case 4:
        if (func_0218417C((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4)) != 0) {
            return 1;
        }
        break;
    }
    func_021867C4(p);
    func_0204A600();
    func_020310C4((struct Tcbl *)(((struct Obj00460 *)p)->f170));
    func_02186708(p);
    if (func_020221A4() != 0 && func_0200FB24() != 0) {
        return 1;
    }
    return 0;
}
