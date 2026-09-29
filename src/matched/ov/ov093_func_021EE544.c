/*
 * function: func_021EE544
 * address:  0x021EE544
 * packet:   pkt_ov093_021EE544
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02045730  0x02045730  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02040618  0x02040618  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct C {
    u8 pad00[0x8];
    void *f08;
};

extern u8 func_02045730(void *d);
extern u8 func_02045738(void *d);
extern u8 func_02045740(void *d);
extern u8 func_02045758(void *d);
extern u8 func_02045760(void *d);
extern void func_020409B4(u8 id);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern void func_020061E4(int a);
extern void func_02040618(int a, int b, int c);

int func_021EE544(int *st, struct C *c)
{
    int a;
    int b;
    int e;
    int f;
    u8 id;

    switch (*st) {
    case 0:
        a = func_02045758(c->f08) - 1;
        b = func_02045760(c->f08) - 1;
        e = func_02045738(c->f08) + 2;
        f = func_02045740(c->f08) + 2;
        id = func_02045730(c->f08);
        func_02041300(id, 0, (u8)a, (u8)b, (u8)e, (u8)f, 0);
        func_020409B4(id);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 1:
        func_02040618(3, 0, -0x90);
        func_02040618(3, 3, 0);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
