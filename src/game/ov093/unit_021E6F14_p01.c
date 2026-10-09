/*
 * file:     unit_021E6F14_p01.c
 * unit:     yes
 * function: func_021E6F14, func_021E6F30, func_021E6F3C
 * address:  0x021E6F14
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
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C8114  0x021C8114  thumb  ov093
 *   func_021E6F7C  0x021E6F7C  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F26C4     0x021F26C4  data    a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021D7704(int a, int b);
extern u16 func_021C8114(u8 *p);
extern int func_021E6F7C(int id);
extern int func_021C8030(u8 *p, int v, u16 k);
extern int func_021D76BC(int key, u32 val);
void func_021E6F14(int a, int b, int c);
int *func_021E6F30(int *p);
void func_021E6F3C(int x, int a, int c);
extern int d_021F26C4[];


void func_021E6F14(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D7704(0x31, 3 << 11);
}


int *func_021E6F30(int *p)
{
    *p = 1;
    return d_021F26C4;
}


void func_021E6F3C(int x, int a, int c)
{
    u16 id;
    int r;

    if (c == func_021D775C(2)) {
        id = func_021C8114((u8 *)a);
        if (id != 0 && func_021E6F7C(id) == 0) {
            r = func_021C8030((u8 *)a, c, id);
            func_021D76BC(0x12, id);
            func_021D76BC(0xd, r);
        }
    }
}
