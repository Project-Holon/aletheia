/*
 * file:     unit_021E6F14.c
 * unit:     yes
 * function: func_021E6F14, func_021E6F30, func_021E6F3C, func_021E6F8C, func_021E6F98, func_021E6FBC
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
 *   func_0689CA5C  0x0689CA5C  thumb
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C8114  0x021C8114  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F26C4     0x021F26C4  data    a4
 *   d_021F262C     0x021F262C  data   ov093  a4
 *   d_021F251C     0x021F251C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021D7704(int a, int b);
extern u16 func_021C8114(u8 *p);
extern int func_0689CA5C(int id);
extern int func_021C8030(u8 *p, int v, u16 k);
extern int func_021D76BC(int key, u32 val);
void func_021E6F14(int a, int b, int c);
int *func_021E6F30(int *p);
void func_021E6F3C(int x, int a, int c);
int *func_021E6F8C(int *p);
void func_021E6F98(int a, int b, int c);
int *func_021E6FBC(int *p);
extern int d_021F26C4[];
extern int d_021F262C[];
extern int d_021F251C[];


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
        if (id != 0 && func_0689CA5C(id) == 0) {
            r = func_021C8030((u8 *)a, c, id);
            func_021D76BC(0x12, id);
            func_021D76BC(0xd, r);
        }
    }
}


int *func_021E6F8C(int *p)
{
    *p = 1;
    return d_021F262C;
}


void func_021E6F98(int a, int b, int c)
{
    if (c == func_021D775C(4) && c == func_021D775C(3))
        func_021D76BC(0x1f, 10);
}


int *func_021E6FBC(int *p)
{
    *p = 1;
    return d_021F251C;
}
