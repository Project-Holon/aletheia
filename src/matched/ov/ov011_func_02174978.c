/*
 * function: func_02174978
 * address:  0x02174978
 * packet:   pkt_ov011_02174978
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02173758  0x02173758  thumb  ov011
 *   func_02174AE0  0x02174AE0  thumb  ov011
 *   func_0217546C  0x0217546C  thumb  ov011
 *   func_02174E3C  0x02174E3C  thumb  ov011
 *   func_02173828  0x02173828  thumb  ov011
 *   func_02174B2C  0x02174B2C  thumb  ov011
 *   func_02174B7C  0x02174B7C  thumb  ov011
 *   func_02174BC4  0x02174BC4  thumb  ov011
 *   func_021743B4  0x021743B4  thumb  ov011
 *   func_021757C4  0x021757C4  thumb  ov011
 *   func_02174374  0x02174374  thumb  ov011
 *   func_02174C38  0x02174C38  thumb  ov011
 *   func_02174CCC  0x02174CCC  thumb  ov011
 *   func_02174DF4  0x02174DF4  thumb  ov011
 *   func_021752DC  0x021752DC  thumb  ov011
 *   func_02173984  0x02173984  thumb  ov011
 *   func_02012E40  0x02012E40  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_021756D0  0x021756D0  thumb  ov011
 *   func_0200BE84  0x0200BE84  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00269.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits;

struct Big;
struct BigObj;
extern u32 func_02026478(void *obj);
extern u32 func_0203D378(void);
extern int func_0203D1B4(void);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern int func_02173758(int a, int b, ...);
extern void func_02174AE0(u8 *);
extern void func_0217546C(u8 *);
extern void func_02174E3C(u8 *);
extern void func_02173828(u8 *);
extern void func_02174B2C(u8 *);
extern void func_02174B7C(u8 *);
extern void func_02174BC4(u8 *);
extern int func_021743B4(u8 *);
extern void func_021757C4(u8 *, u8 *);
extern int func_02174374(u8 *);
extern void func_02174C38(u8 *);
extern void func_02174CCC(u8 *);
extern void func_02174DF4(u8 *);
extern int func_021752DC(u8 *);
extern int func_02173984(u8 *, u8 *);
extern u8 func_02012E40(const u8 *o);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern int func_021756D0(u32 x);
extern void func_0200BE84(void *, u8 *);

void func_02174978(u8 *s)
{
    int h;
    int n;
    void *w;

    h = func_02026478((void *)(((struct Obj00269 *)s)->f4));
    if (func_0203D378() == 1) {
        n = func_0203D1B4();
        if (n > s[0x902]) {
            s[0x902] = n;
            s[0x903] = 1;
            func_02012B4C((struct BigObj *)h, s[0x902]);
        }
    }
    if (s[0x903] == 1 && func_02173758((int)s, s[0x902]) == 1) {
        s[0x903] = 0;
    }
    func_02174AE0(s);
    func_0217546C(s);
    if (s[0x8fe] == 1) {
        func_02174E3C(s);
        func_02173828(s);
    }
    func_02174B2C(s);
    func_02174B7C(s);
    func_02174BC4(s);
    if (s[0x93e] == 1 && func_021743B4(s) == 1) {
        s[0x93e] = 0;
    }
    func_021757C4(s, s + 0x1ac);
    if (s[0x907] == 1 && func_02174374(s) == 1) {
        s[0x907] = 0;
    }
    func_02174C38(s);
    func_02174CCC(s);
    func_02174DF4(s);
    if (func_021752DC(s) == 1) {
        s[0x900] = 1;
    }
    if (s[0x900] == 1 && ((Bits *)(s + 0x904))->b1 == 0 && func_02173984(s, s + 0x70) == 1) {
        s[0x900] = 0;
    }
    if (func_02012E40((const u8 *)h) == 0 && ((Bits *)(s + 0x8f8))->b0 == 1) {
        w = func_0200BE48(func_02012EBC((struct Big *)h));
        if (func_021756D0(((struct Obj00269 *)s)->f8F4) == 0) {
            ((struct Obj00269 *)s)->f8F4 = 0x11;
        }
        func_0200BE84(w, s + 0x8e4);
        ((Bits *)(s + 0x8f8))->b0 = 0;
    }
}
