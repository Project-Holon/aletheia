/*
 * function: func_021E6F8C, func_021E6F98, func_021E6FBC
 * address:  0x021E6F8C
 * packet:   pkt_ov093_021E6F98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F262C     0x021F262C  data   ov093  a4
 *   d_021F251C     0x021F251C  data   ov093  a4

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);

extern int d_021F262C[];
int *func_021E6F8C(int *p);

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


extern int d_021F251C[];
int *func_021E6FBC(int *p);

int *func_021E6FBC(int *p)
{
    *p = 1;
    return d_021F251C;
}
