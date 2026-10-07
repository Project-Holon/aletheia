/*
 * file:     eventdata_system_p26.c
 * unit:     yes
 * function: func_0216377C, func_021637B0, func_021637E4, func_02163868, func_021638AC, func_021638C8
 * address:  0x0216377C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021AB2F8  0x021AB2F8  thumb
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_021C484C  0x021C484C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB440  0x021AB440  thumb  ov021
 *   func_021AB358  0x021AB358  thumb  ov021
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 *   func_021AB3EC  0x021AB3EC  thumb
 *   func_021C8F7C  0x021C8F7C  thumb  ov021
 */
#include "../../matched/include/Obj00110.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021AB2F8();
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern u32 func_0216D8AC(void *p);
extern int func_021C484C();
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216DC34(void *a0);
extern int func_02163F40(int a, int dir);
extern int func_0216DC18(void *a0, int a1);
extern void *func_0216D67C(void *a0);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB440();
extern int func_021AB358(int x);
extern void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);
extern int func_021AB3EC();
extern int func_021C8F7C();
int func_0216377C(int a0, int a1, int a2, int a3);
int func_021637B0(int a0, int a1, int a2, int a3);
void func_021637E4(void *a, int q);
void func_02163868(void *a, int q);
int func_021638AC(int a0, int a1);
int func_021638C8(int a0);


int func_0216377C(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f8;
    a0 = func_021AB2F8(a0);
loc_02163788:
    if (a0 != 1) goto loc_021637AE;
loc_0216378C:
a0 = t5 + 0;
    a0 = func_0216D804((void *)a0);
loc_02163792:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D81C((void *)a0);
loc_0216379A:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D8AC((void *)a0);
loc_021637A2:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t6 + 0;
a2 = t7 + 0;
    a0 = func_021C484C(a0, a1, a2, a3);
loc_021637AE:
    return a0;}


int func_021637B0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB2F8(a0);
loc_021637BC:
    if (a0 != 1) goto loc_021637E2;
loc_021637C0:
a0 = t5 + 0;
    a0 = func_0216D83C((void *)a0);
loc_021637C6:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D86C((void *)a0);
loc_021637CE:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D8AC((void *)a0);
loc_021637D6:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t6 + 0;
a2 = t7 + 0;
    a0 = func_021C484C(a0, a1, a2, a3);
loc_021637E2:
    return a0;}


void func_021637E4(void *a, int q)
{
    int r4, r7, s;
    u8 *t = *(u8 * *)&((struct Obj00110 *)q)->f10;

    if (t[6] == 0) {
        return;
    }
    if (func_0216DC34((void *)a) != 0) {
        return;
    }
    r4 = -1;
    if (((struct Obj00110 *)q)->fE & 0x40) {
        r4 = *(int *)(q + 4);
    } else {
        r7 = func_02163F40((int)a, 1);
        if (func_021AB0F8(r7) & 0x40) {
            r4 = r7;
        }
    }
    if (r4 == -1) {
        return;
    }
    r7 = 1;
    r4 = func_021AB0F0(r4);
    s = (int)func_0216D67C((void *)a);
    if (func_021AB440(r4) == 1 || func_021AB358(r4) == 1) {
        r7 = 2;
    }
    func_021BBFB8(s, (u32)a, ((struct Obj00110 *)q)->f14, r7);
    func_0216DC18(a, 1);
}


void func_02163868(void *a, int q)
{
    u8 *t = *(u8 * *)&((struct Obj00110 *)q)->f10;

    if (t[6] != 0 && func_0216DC34((void *)a) != 0) {
        int r = func_02163F40((int)a, 1);

        if (r == -1) {
            func_0216DC18(a, 0);
            return;
        }
        if ((func_021AB0F8(r) & 0x40) == 0) {
            func_0216DC18(a, 0);
        }
    }
}


/*
 * unblocked: func_021C8F7C is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 28 bytes against 26 compiled: the unlabelled follower that
 *   precedes ov021's next entry (its bytes are the original's 2-byte pad).
 */
int func_021638AC(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB3EC(a0);
loc_021638B8:
    if (a0 != 1) goto loc_021638C4;
loc_021638BC:
a1 = ((struct Obj00110 *)t4)->f14;
a0 = t5 + 0;
    a0 = func_021C8F7C(a0, a1);
loc_021638C4:
    return a0;}




int func_021638C8(int a0)
{

    return a0;}
