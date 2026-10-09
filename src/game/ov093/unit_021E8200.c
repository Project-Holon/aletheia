/*
 * file:     unit_021E8200.c
 * unit:     yes
 * function: func_021E8200, func_021E822C, func_021E8238, func_021E8264
 * address:  0x021E8200
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
 *   func_021E8B28  0x021E8B28  thumb  ov093
 *   d_021F2958     0x021F2958  data   ov093  a4
 *   d_021F26A4     0x021F26A4  data   ov093  a4
 */
union U;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void func_021E8B28(union U *p, u16 v);
void func_021E8200(int a, int b, int c);
int *func_021E822C(int *p);
void func_021E8238(int a, int b, int c);
int *func_021E8264(int *p);
extern int d_021F2958[];
extern int d_021F26A4[];


void func_021E8200(int a, int b, int c)
{
    u32 v;

    if (c == func_021D775C(3)) {
        v = func_021D775C(0x1e);
        func_021E8B28((union U *)(&v), 7);
        func_021D76BC(0x1e, v);
    }
}


int *func_021E822C(int *p)
{
    *p = 2;
    return d_021F2958;
}


void func_021E8238(int a, int b, int c)
{
    u32 v;

    if (c == func_021D775C(3)) {
        v = func_021D775C(0x1e);
        func_021E8B28((union U *)(&v), 0x10);
        func_021D76BC(0x1e, v);
    }
}


int *func_021E8264(int *p)
{
    *p = 1;
    return d_021F26A4;
}
