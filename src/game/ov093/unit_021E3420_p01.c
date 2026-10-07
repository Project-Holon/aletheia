/*
 * file:     unit_021E3420_p01.c
 * unit:     yes
 * function: func_021E34FC, func_021E354C, func_021E357C
 * address:  0x021E34FC
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E8798  0x021E8798  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8804  0x021E8804  thumb  ov093
 *   func_021D7040   0x021D7040  thumb
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void func_021E8798(int u, void *a, int b, int d);
extern int func_021D76BC(int key, u32 val);
extern void func_021E8804(int a, void *b, int c, int d);
void func_021E34FC(int u, void *p, int key, int *o);
void func_021E3544(int a, int b, int c, int d);
void func_021E354C(int u, void *a, int b, int c);
/* 021E357C shape F3: gate on func_021D775C(2) then func_021D7040 */ void func_021E357C(int a, int b, int c);


void func_021E34FC(int u, void *p, int key, int *o)
{
    u8 *q;
    if (key == func_021D775C(3) && o[6] == 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 761);
        func_021C8860((struct S *)(q + 4), key);
        func_021C88C8(p, q);
        o[6] = 1;
    }
}


void func_021E3544(int a, int b, int c, int d)
{
    func_021E8798(a, (void *)b, c, d);
}


void func_021E354C(int u, void *a, int b, int c)
{
    if (b == func_021D775C(2)) {
        if (func_021D76BC(0x51, 1) != 0)
            func_021E8804(u, a, b, c);
    }
}


/* 021E357C  shape F3: gate on func_021D775C(2) then func_021D7040 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E3592; adds r0, r5, #0; bl func_021D7040; pop {r3, r4, r5, pc}.
 */
void func_021E357C(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7040(a);
}
