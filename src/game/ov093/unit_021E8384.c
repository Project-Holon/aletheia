/*
 * file:     unit_021E8384.c
 * unit:     yes
 * function: func_021E8384, func_021E83C0, func_021E83CC, func_021E8440, func_021E8478, func_021E8498, func_021E84B8, func_021E84FC, func_021E85F8, func_021E8624, func_021E8638
 * address:  0x021E8384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F2CF0  0x021F2CF0  data  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6E50  0x021D6E50  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021E8940 0x021E8940 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C7D34 0x021C7D34 thumb ov093
 *   func_021C80AC  0x021C80AC  thumb  ov093
 *   func_021E867C  0x021E867C  thumb  ov093
 *   func_021E868C  0x021E868C  thumb  ov093
 *   d_021F2F68     0x021F2F68  data   ov093  a4
 */
#include "../../matched/include/Obj07838.h"
#include "../../matched/include/Obj21548.h"

struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 a; u16 b; int v; } Ent;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6E50(u8 *p, u8 *id, u16 *value);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern unsigned char func_021B9A40(unsigned int x);
extern Word func_021E8940(int);
extern void func_021C8860(struct S *, u32);
extern int func_021C7D34(char *p, int i);
extern int func_021C80AC(u8 *p, int key);
extern int func_021E867C(int b);
extern int func_021E868C(int b);
int func_021E8384(u32 x, u32 y);
int *func_021E83C0(int *p);
void func_021E83CC(void *a, void *b, int c, int *d);
void func_021E8440(int a, void *b, int c, int *d);
void func_021E8478(int a, int b, int c, int *d);
void func_021E8498(int a, int b, int c, int *d);
void func_021E84B8(int a, int b, int c, int *d);
void func_021E84FC(int a, int b, int c, const int *d);
int func_021E85F8(int v);
int func_021E8624(int a, int b);
int func_021E8638(int a, int b);
extern Ent d_021F2CF0[3];
extern int d_021F2F68[];


int func_021E8384(u32 x, u32 y)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        if ((x == d_021F2CF0[i].a && y == d_021F2CF0[i].b) ||
            (y == d_021F2CF0[i].a && x == d_021F2CF0[i].b))
            return d_021F2CF0[i].v;
    }
    return 0;
}


/*
 * Return r0 from func_021EC01C and func_021EA858 is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int *func_021E83C0(int *p)
{
    *p = 6;
    return d_021F2F68;
}


void func_021E83CC(void *a, void *b, int c, int *d)
{
    u16 y;
    u8 x;
    int r;
    u8 k;

    if (c == func_021D775C(3)) {
        if (func_021D6E50(func_021C7CF4(b, c), &x, &y) != 0) {
            r = func_021E8384(func_021D70A8(a), y);
            k = func_021D775C(0x16);
            if (r != 0) {
                d[1] = r;
                d[0] = 1;
                d[2] = x;
                switch (r) {
                case 1:
                    k = 10;
                    break;
                case 2:
                    k = 9;
                    break;
                case 3:
                    k = 11;
                    break;
                }
                func_021D76BC(0x16, k);
            }
        }
    }
}





void func_021E8440(int a, void *b, int c, int *d)
{
    u8 *m;

    if (c == func_021D775C(3) && *d != 0) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 1, 0xbb);
        func_021C88C8(b, m);
    }
}





void func_021E8478(int a, int b, int c, int *d)
{
    if (c == func_021D775C(2) && *d != 0)
        func_021D76BC(0x51, 1);
}





void func_021E8498(int a, int b, int c, int *d)
{
    if (c == func_021D775C(3) && *d != 0)
        func_021D76BC(0x30, 0x96);
}




void func_021E84B8(int a, int b, int c, int *d)
{
    int k;

    if (c == func_021D775C(2)) {
        if (d[0] != 0) {
            k = 0;
            switch (d[1]) {
            case 1:
                k = 0x206;
                break;
            case 2:
                k = 0x207;
                break;
            case 3:
                k = 0x208;
                break;
            }
            func_021D76BC(0x13, k);
        }
    }
}



/*
 * lever: byte locals plus declaration order restore the spill/register assignment.
 * permuter: rejected added return target; transferred only declarations and two temporaries.
 */
void func_021E84FC(int a, int b, int c, const int *d)
{
    int tmp;
    u8 *p;
    u8 selected;
    int code;
    u8 own;
    u8 other;
    int target;
    int slot;
    u8 message;
    u8 mode;
    u8 *tmp1;
    if (c == func_021D775C(3) && d[0] != 0) {
        mode = 14;
        own = func_021B9A40(c);
        other = func_021B9A40((u8)func_021D775C(6));
        code = 0;
        message = 0;
        target = 31;
        switch (d[1]) {
        case 1:
            message = 0xa4;
            mode = 11;
            selected = own;
            code = 0x28d;
            target = c;
            break;
        case 2:
            message = 0xa8;
            selected = other;
            mode = 12;
            code = 0x28e;
            target = (u8)func_021D775C(6);
            break;
        case 3:
            message = 0xac;
            selected = other;
            mode = 13;
            code = 0x28f;
            target = (u8)func_021D775C(6);
            break;
        }
        if (mode != 14) {
            p = func_021C88A4((char *)b, 25, c);
            ((struct Obj07838 *)p)->f4 = mode;
            p[12] = selected;
            *(Word *)(p + 8) = func_021E8940(4);
            func_021C8838(p + 16, 1, message);
            func_021C8860((struct S *)(p + 16), selected);
            func_021C88C8((void *)b, p);
            if (target != 31) {
                tmp = func_021C7D34((char *)b, target);
                slot = tmp;
                if (slot != 6) {
                    p = func_021C88A4((char *)b, 0x37, c);
                    p[6] = slot;
                    p[7] = 6;
                    tmp1 = p + 4;
                    ((struct Obj21548 *)tmp1)->f0 = code;
                    func_021C88C8((void *)b, p);
                }
            }
        }
    }
}




int func_021E85F8(int v)
{
    u32 i;
    u32 n;

    n = func_021D775C(5);
    i = 0;
    if (n != 0) {
        do {
            if (v == func_021D775C(i + 6))
                return 1;
            i++;
        } while (i < n);
    }
    return 0;
}




int func_021E8624(int a, int b)
{
    if (func_021C80AC((u8 *)a, b) != 0)
        return 1;
    return 0;
}




int func_021E8638(int a, int b)
{
    switch (a) {
    case 0x1e7:
        if (b == 0x70)
            return 1;
        break;
    case 0x1ed:
        if (func_021E867C(b) != 0)
            return 1;
        break;
    case 0x289:
        if (func_021E868C(b) != 0)
            return 1;
        break;
    }
    return 0;
}
