/*
 * file:     unit_021E3420_p02.c
 * unit:     yes
 * function: func_021E35A0, func_021E35F0, func_021E3648
 * address:  0x021E35A0
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
 *   func_021E8624  0x021E8624  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 */
struct S;
struct Unk021D62A8;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021E8624(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D76BC(int key, u32 val);
extern void func_021D7040(struct Node *n);
void func_021E35A0(int u, void *p, int key, int *o);
void func_021E35F0(int u, void *p, int key, int *o);
void func_021E3648(void *u, void *p, int key, int *o);


void func_021E35A0(int u, void *p, int key, int *o)
{
    u8 *q;
    if (key == func_021D775C(3) && func_021E8624((int)p, key) == 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 751);
        func_021C8860((struct S *)(q + 4), key);
        func_021C88C8(p, q);
        o[6] = 1;
    }
}


void func_021E35F0(int u, void *p, int key, int *o)
{
    u8 t = func_021D775C(3);
    if (t != key) {
        if (func_0201BEB8(func_021D775C(0x12), 5) != 0) {
            if (func_021D62C4(func_021C7CF4(p, key), 0x21) == 0) {
                if (func_021D76BC(2, key) != 0) {
                    func_021D76BC(4, key);
                    *o = 1;
                }
            }
        }
    }
}


void func_021E3648(void *u, void *p, int key, int *o)
{
    u8 *q;
    if (key == func_021D775C(2) && *o != 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 754);
        func_021C8860((struct S *)(q + 4), key);
        func_021C8860((struct S *)(q + 4), func_021D775C(3));
        func_021C88C8(p, q);
        func_021D7040(u);
    }
}
