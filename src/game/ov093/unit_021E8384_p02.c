/*
 * file:     unit_021E8384_p02.c
 * unit:     yes
 * function: func_021E84B8, func_021E84FC, func_021E85F8, func_021E8624, func_021E8638
 * address:  0x021E84B8
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021E8940 0x021E8940 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C7D34 0x021C7D34 thumb ov093
 *   func_021C80AC  0x021C80AC  thumb  ov093
 *   func_021E867C  0x021E867C  thumb  ov093
 *   func_021E868C  0x021E868C  thumb  ov093
 */
#include "../../matched/include/Obj07838.h"
#include "../../matched/include/Obj21548.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern unsigned char func_021B9A40(unsigned int x);
extern void *func_021C88A4(char *p, int a, int b);
extern Word func_021E8940(int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *a, void *b);
extern int func_021C7D34(char *p, int i);
extern int func_021C80AC(u8 *p, int key);
extern int func_021E867C(int b);
extern int func_021E868C(int b);
void func_021E84B8(int a, int b, int c, int *d);
void func_021E84FC(int a, int b, int c, const int *d);
int func_021E85F8(int v);
int func_021E8624(int a, int b);
int func_021E8638(int a, int b);


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
