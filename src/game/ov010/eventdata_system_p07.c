/*
 * file:     eventdata_system_p07.c
 * unit:     yes
 * function: func_021636F0, func_0216372C, func_0216375C, func_0216377C, func_021637B0, func_021637E4, func_02163868, func_021638AC, func_021638C8, func_021638CC, func_02163994
 * address:  0x021636F0
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
 *   func_021636A8  0x021636A8  thumb  ov010
 *   func_021636C8  0x021636C8  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DD04 0x0216DD04 thumb ov010
 *   func_021AC528 0x021AC528 thumb ov021
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
 *   func_02163C9C  0x02163C9C  thumb  ov010
 *   func_02163D04  0x02163D04  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02163BAC  0x02163BAC  thumb  ov010
 *   func_0216D52C  0x0216D52C  thumb  ov010
 *   func_0218DC04  0x0218DC04  thumb  ov021
 *   func_0216D88C 0x0216D88C thumb ov010
 */
#include "../../matched/include/Obj07203.h"
#include "../../matched/include/Obj00110.h"

struct Grid;
struct Actor;
struct VecFx32_02163994;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32_021638CC {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021638CC;

typedef struct Obj {
    u32 f00;
    fx32 f04;           /* 0x04 */
} Obj;

typedef struct { int x, y, z; } VecFx32_02163994;

extern int func_021636A8(int a0, int a1);
extern int func_021636C8();
extern u32 func_0216D57C(void *p, u32 v);
extern int func_021AC2C0();
extern int func_0216D568();
extern int func_0216D570();
extern int func_0216DD04(void *p);
extern void func_021AC528(u32 a, u32 b);
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
extern int func_02163C9C(int a, int b, int c);
extern int func_02163D04(void *m, u32 kind, VecFx32_021638CC pos);
extern int func_02163E58(void *m, VecFx32_021638CC *pos, fx32 *y);
extern int func_02163BAC(int a, int b, int c, int d);
extern u32 func_0216D52C(void *p);
extern int func_0218DC04(struct Grid *g, struct VecFx32_021638CC *pos);
extern void func_0216D88C(const struct Actor *p, struct VecFx32_02163994 *out);
void func_021636F0(int a0, int a1);
void func_0216372C(int a0, int a1);
void func_0216375C(void *p, u8 *q);
int func_0216377C(int a0, int a1, int a2, int a3);
int func_021637B0(int a0, int a1, int a2, int a3);
void func_021637E4(void *a, int q);
void func_02163868(void *a, int q);
/* * unblocked: func_021C8F7C is ov021's label across the co-resident * ov010/ov021 pair; the `ov021` token resolves the site as `label`. * Extent runs 28 bytes against 26 compiled: the unlabelled follower that * precedes ov021's next entry (its bytes are the original's 2-byte pad). */ int func_021638AC(int a0, int a1);
int func_021638C8(int a0);
/* * Collects five placement-test failures into a bit mask: 1 from * func_02163C9C, 2 from func_02163D04 (the cell-centre position by * value), 8 when the ground-height probe func_02163E58 fails or lands * 0x14000 or more from the object's height, 4 from func_02163BAC, 0x10 * from the ov021 test at 0x0218DC04. * * x and y are s16 register parameters (their spill homes are stored at * entry); z is read as `*(s16 *)&z` from an int stack parameter: an s16 * z is copied into a fresh spill slot, while this spelling keeps the * incoming slot as its home and reloads it with ldrsh after the calls. */ u32 func_021638CC(void *m, Obj *o, s16 x, s16 y, int z, u16 kind);
/* * trailing: two-byte zero alignment at 0x021639BE before func_021639C0. */ u32 func_02163994(void *p, s16 x, s16 y, int z, u16 kind);




void func_021636F0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_021636A8(a0, a1);
loc_021636FA:
    if (a0 != 1) goto loc_02163728;
loc_021636FE:
a0 = t4 + 0;
    a0 = func_021636C8(a0);
loc_02163704:
    if (a0 != 1) goto loc_02163728;
loc_02163708:
t6 = 1;
t6 = t6 << 0xe;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_02163714:
    if (a0 != 0) goto loc_02163728;
loc_02163718:
a1 = ((struct Obj07203 *)t4)->f14;
a0 = t5 + 0;
    a0 = func_021AC2C0(a0, a1);
loc_02163720:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_0216D568(a0, a1);
loc_02163728:
    return;}




void func_0216372C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_021636A8(a0, a1);
loc_02163736:
    if (a0 != 1) goto loc_0216375A;
loc_0216373A:
a0 = t4 + 0;
    a0 = func_021636C8(a0);
loc_02163740:
    if (a0 != 0) goto loc_02163750;
loc_02163744:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xe;
    a0 = func_0216D568(a0, a1);
loc_0216374E:
    return;
loc_02163750:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xe;
    a0 = func_0216D570(a0, a1);
loc_0216375A:
    return;}



void func_0216375C(void *p, u8 *q)
{
    if (!(((struct Obj00110 *)q)->fE & 2) && !func_0216DD04(p))
        func_021AC528((u32)p, *(u32 *)&((struct Obj00110 *)q)->f14);
}




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



/*
 * Collects five placement-test failures into a bit mask: 1 from
 * func_02163C9C, 2 from func_02163D04 (the cell-centre position by
 * value), 8 when the ground-height probe func_02163E58 fails or lands
 * 0x14000 or more from the object's height, 4 from func_02163BAC, 0x10
 * from the ov021 test at 0x0218DC04.
 *
 * x and y are s16 register parameters (their spill homes are stored at
 * entry); z is read as `*(s16 *)&z` from an int stack parameter: an s16
 * z is copied into a fresh spill slot, while this spelling keeps the
 * incoming slot as its home and reloads it with ldrsh after the calls.
 */
u32 func_021638CC(void *m, Obj *o, s16 x, s16 y, int z, u16 kind)
{
    u32 flags = 0;
    VecFx32_021638CC pos;
    fx32 h;

    pos.x = (x << 16) + 0x8000;
    pos.y = o->f04;
    pos.z = (*(s16 *)&z << 16) + 0x8000;
    if (func_02163C9C((int)m, x, *(s16 *)&z) == 1)
        flags |= 1;
    if (func_02163D04(m, kind, pos) == 1)
        flags |= 2;
    if (func_02163E58(m, &pos, &h) == 1) {
        fx32 d = o->f04 - h;
        if (d < 0)
            d = -d;
        if (d >= 0x14000)
            flags |= 8;
        y = (h >> 4) / 0x1000;
    } else {
        flags |= 8;
    }
    if (func_02163BAC((int)m, x, y, *(s16 *)&z) == 1)
        flags |= 4;
    if (func_0218DC04((struct Grid *)func_0216D52C(func_0216D67C(m)), &pos) == 1)
        flags |= 0x10;
    return flags;
}


/*
 * trailing: two-byte zero alignment at 0x021639BE before func_021639C0.
 */
u32 func_02163994(void *p, s16 x, s16 y, int z, u16 kind)
{
    VecFx32_02163994 pos;
    func_0216D88C((const struct Actor *)p, (struct VecFx32_02163994 *)&pos);
    return func_021638CC(p, (struct Obj *)(&pos), x, y, z, kind);
}
