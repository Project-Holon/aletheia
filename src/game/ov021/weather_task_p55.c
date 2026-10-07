/*
 * file:     weather_task_p55.c
 * unit:     yes
 * function: func_021A4CA8, func_021A4CF4, func_021A4D8C, func_021A4D90, func_021A4DC0, func_021A4E78, func_021A4E9C
 * address:  0x021A4CA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A4FA8  0x021A4FA8  thumb  ov021
 *   func_021A5148  0x021A5148  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A4ED8  0x021A4ED8  thumb  ov021
 *   func_021A4F04  0x021A4F04  thumb  ov021
 *   func_021A4F0C  0x021A4F0C  thumb  ov021
 *   func_021A4F50  0x021A4F50  thumb  ov021
 *   func_021A4F58  0x021A4F58  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A3A20  0x021A3A20  thumb  ov021
 *   func_021A5304  0x021A5304  thumb  ov021
 *   func_021A530C  0x021A530C  thumb  ov021
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 *   func_021A57C0  0x021A57C0  thumb  ov021
 *   func_021A5810  0x021A5810  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj00262.h"
#include "../../matched/include/Obj19790.h"
#include "../../matched/include/Obj04233.h"
#include "../../matched/include/Obj19791.h"

struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_021A3974(u8 *p);
extern void func_021A4FA8(u32, u32, u32);
extern void func_021A5148(u32, u32, u32);
extern void *func_021A3960(unsigned char *p);
extern void func_021A4ED8(u32 *p, int b, u8 *c);
extern void func_021A4F04(u32 *a, void *a1, u32 a2);
extern void func_021A4F0C(u32 a, void *b, u32 c);
extern void func_021A4F50(u32 *a, void *a1, u32 a2);
extern int func_021A4F58(u32 *p, void *a1, u32 a2);
u16 func_0216D5F8(void *p);
int func_02197E7C(int k, int a);
void func_0216D410(int b, int v);
void func_021A3964(u8 *p, u32 v);
extern int func_021A3A20(u32);
extern int func_021A5304(u32 a, u32 b);
extern int func_021A530C(u32 a, u32 b);
extern void func_021A3898(unsigned char *, struct VecFx32 *);
extern int func_02163E34(u32, int *, u32 *);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB44C(u16 id);
extern int func_021A57C0(u8 *p, int dir);
int func_021A5810(u8 *p, int dir);
void func_020061E4(u32 a);
void func_021A4CA8(u32 a, u32 b, u32 c);
void func_021A4CF4(u32 a, u32 b, u32 c);
void func_021A4D8C(u32 a, u32 b, u32 c);
void func_021A4D90(u32 *p, int b, u8 *c);
void func_021A4DC0(u32 *a, u32 b, u32 *c);
void func_021A4E78(u32 *p, int b, u8 *c);
void func_021A4E9C(u32 *p, int b, u8 *c);


/*
 * Addresses are Black-image addresses.
 */
void func_021A4CA8(u32 a, u32 b, u32 c)
{
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj00262 *)a)->fC))) {
    case 0:
        func_021A4CF4(a, b, c);
        return;
    case 1:
        func_021A4FA8(a, b, c);
        return;
    case 2:
    case 3:
        func_021A5148(a, b, c);
        break;
    }
}


void func_021A4CF4(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: func_021A4D8C(a, (u32)x, c); return;
    case 1: func_021A4D90((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A4DC0((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: func_021A4E78((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A4E9C((u32 *)a, (int)x, (u8 *)c); return;
    case 5: func_021A4ED8((u32 *)a, (int)x, (u8 *)c); return;
    case 6: func_021A4F04((u32 *)a, x, c); return;
    case 7: func_021A4F0C(a, (void *)x, c); return;
    case 8: func_021A4F50((u32 *)((u32)((u32)((u32)((u32)((u32)((u32)a)))))), x, c); return;
    case 9: func_021A4F58((u32 *)((u32 *)a), x, c); break;
    }
}


/*
 * Unlabelled leaf (no lr save), filed because it blocks the caller's MATCH.
 *
 * Addresses are Black-image addresses.
 */
void func_021A4D8C(u32 a, u32 b, u32 c)
{
}


void func_021A4D90(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19790 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}


void func_021A4DC0(u32 *a, u32 b, u32 *c)
{
    int buf[3];
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else if ((c[3] & 1) && (c[1] & 2)) {
        if (func_021A3A20(a[3]) == 0) {
            r = 0x10;
        } else {
            r = 0x58;
            func_021A5304((u32)a, 0x20);
            func_021A3898((unsigned char *)a[3], (struct VecFx32 *)buf);
            if (func_02163E34(b, buf, &v) != 0) {
                if (func_021AB44C(func_021AB0F0(v)) != 0) {
                    r = 0xc;
                    f = 0;
                    func_021A530C((u32)a, 0x20);
                }
            }
        }
    } else {
        r = 0xc;
    }
    if (f == 1) {
        if (func_021A57C0((u8 *)((u32)a), ((struct Obj04233 *)c)->f8) == 1) {
            switch (r) {
            case 0x10: r = 0x4c; break;
            case 0x58: r = 0xa3; break;
            case 0xc: r = 0xa7; break;
            }
        }
    }
    func_0216D410(b, func_02197E7C(((struct Obj04233 *)c)->f8, r));
    a[0] = 1;
    func_021A3964((u8 *)a[3], 1);
}


void func_021A4E78(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19791 *)c)->f8, 0x24));
    p[0] = 2;
    func_021A3964((u8 *)p[3], 2);
}


void func_021A4E9C(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj04233 *)c)->f8, 0x1C));
    p[0] = 3;
    func_021A3964((u8 *)p[3], 0);
    if (func_021A5810((u8 *)p, ((struct Obj04233 *)c)->f8) == 0)
        func_020061E4(0x55A);
}
