/*
 * file:     comm_player_p27.c
 * unit:     yes
 * function: func_0216A2EC, func_0216A358, func_0216A390, func_0216A3F8, func_0216A420, func_0216A440
 * address:  0x0216A2EC
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
 *   func_02011400  0x02011400  thumb
 *   func_0216A298  0x0216A298  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_021D096C  0x021D096C  thumb
 *   func_021D0A48   0x021D0A48  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0A74  0x021D0A74  thumb
 */
#include "../../matched/include/Obj12054.h"
#include "../../matched/include/Obj17756.h"

struct Blk37;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u8 func_02011400(int row, int col);
extern void func_0216A298(void *a, void *list);
extern void *func_0200CA1C(void *a);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017988(void *p, u32 a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern void *func_021D096C(void *a);
extern void func_021D0A48(void *, void *);
extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_021D0A74();
int func_0216A2EC(int a0, int a1, int a2, int *a3, int a4);
int func_0216A358(int a,int b,u32 *p,int c);
void func_0216A390(int a0, int a1);
int func_0216A3F8(int a0, int a1);
int func_0216A420(void *a0, void *a1);
int func_0216A440(int a0, int a1);


int func_0216A2EC(int a0, int a1, int a2, int *a3, int a4)
{
    int r6;
    int r0;
    int r1;
    int t;

    r6 = func_02011400(a4, 3);
    r0 = func_02011400(a4, 0);
    r1 = a3[0];
    if (!((u32)r1 < (u32)r6 && (u32)r1 >= (u32)r0)) {
        t = r1;
        if (t < r0) {
            t += 24;
        }
        t = t - r6;
        if (a3[1] + t * 60 < a2 + 1) {
            func_0216A298((void *)a0, (void *)a1);
            return 1;
        }
        return 0;
    }
    t = r1 - r0;
    if (a3[1] + t * 60 < a2) {
        func_0216A298((void *)a0, (void *)a1);
        return 1;
    }
    return 0;
}

int func_0216A358(int a,int b,u32 *p,int c) { u32 hi; u32 lo; int result; hi=func_02011400(c,3); lo=func_02011400(c,0); result=0; if (!(*p < hi && *p >= lo)) { func_0216A390(a,b); result=1; } return result; }


void func_0216A390(int a0, int a1)
{
    int found;
    int n;
    void *l4;
    int i;
    void *e;
    int v;
    int w;

    l4 = func_0200CA1C((void *)a0);
    found = 0;
    n = func_0201AA18((void *)a1);
    for (i = 0; i < n; i++) {
        e = func_0201AB28((void *)a1, i);
        v = func_02017E1C(e, 5, 0);
        w = func_02017E1C(e, 0x6f, 0);
        if (v == 0x1EC && w == 1) {
            func_02017988(e, 0);
            if (found == 0) {
                func_0200CFA0(l4, e);
                found = 1;
            }
        }
    }
}


/*
 * blocked:  listing 40 compiled 38
 */
int func_0216A3F8(int a0, int a1)
{    void *p;
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216A400:
    p = func_020120F4((const struct Ctx *)v0);
loc_0216A406:
    v1 = func_02012F50(p);
loc_0216A40A:
a0 = *(int *)&((struct Obj12054 *)((char *)v1))->f0;
    if (a0 != 0) goto loc_0216A41A;
loc_0216A412:
    p = func_021D096C(v0);
loc_0216A418:
((struct Obj12054 *)((char *)v1))->f0 = p;
loc_0216A41A:
a0 = 0;
    return a0;}


/*
 * blocked:  listing 32 compiled 30 wild=4
 *
 * Overlay index, then the record's handle and one arm9 probe go to the
 * overlay's own pair call.
 */
int func_0216A420(void *a0, void *a1)
{
    void *p = func_0215A5DC(a1);

    func_021D0A48(p, func_02012F50(func_020120F4(p)));

    return 0;
}


/*
 * blocked:
 */
int func_0216A440(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A44C:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A452:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A456:
    v2 = func_02012F50(p);
loc_0216A45A:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0216A464:
a1 = a0 + 0;
a0 = ((struct Obj17756 *)((char *)v2))->f0;
    a0 = func_021D0A74(a0, a1);
loc_0216A46C:
a0 = 0;
    return a0;}
