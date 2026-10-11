/*
 * file:     unit_068994A8.c
 * unit:     yes
 * function: func_068994A8, func_068994B4
 * address:  0x068994A8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021B9A40  0x021B9A40  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021D76BC  0x021D76BC  thumb
 *   func_021D775C  0x021D775C  thumb
 *   data_0689D718 0x0689D718 data a4
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_021D775C(int a);
extern int func_021B9A40(int a);
extern int func_0201BD28(u16 a, int b);
extern int func_021D76BC(int a, int b);
extern void func_021C8838(int p, int n, int c);
extern void func_021C8860(int p, int v);
void *func_068994A8(u32 *p);
void func_068994B4(int a0, int a1, int x);
extern u32 data_0689D718;

/*
 * Unlabelled store-and-return follower after veneer 0x06899498.
 */
void *func_068994A8(u32 *p) { *p = 1; return &data_0689D718; }


void func_068994B4(int a0, int a1, int x)
{
    u8 v;
    int q;

    v = func_021D775C(4);
    if (x == func_021B9A40(v) && v != func_021D775C(3)
        && func_0201BD28(func_021D775C(0x12), 6) >= 1
        && func_021D76BC(0x40, 1) != 0) {
        q = func_021D775C(0x3f);
        func_021C8838(q, 2, 0x320);
        func_021C8860(q, v);
    }
}
