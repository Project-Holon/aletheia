/*
 * file:     unit_021E8384_p01.c
 * unit:     yes
 * function: func_021E8440, func_021E8478, func_021E8498
 * address:  0x021E8440
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
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int key, u32 val);
void func_021E8440(int a, void *b, int c, int *d);
void func_021E8478(int a, int b, int c, int *d);
void func_021E8498(int a, int b, int c, int *d);


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
