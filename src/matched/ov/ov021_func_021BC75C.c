/*
 * function: func_021BC75C
 * address:  0x021BC75C
 * packet:   pkt_ov021_021BC75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_021BD094  0x021BD094  thumb  ov021
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x2C];
    void *f2C;
} Obj;

extern u16 func_021BD090(Obj *p);
extern u16 func_021BD094(Obj *p);
extern void *func_0204AC18(int a, int b, int c, int d, int e, int f, int g);

void func_021BC75C(Obj *p)
{
    u16 a = func_021BD090(p);
    u16 b = func_021BD094(p);

    p->f2C = func_0204AC18(b, 3, 0, 0x20, 0, 1, a);
}
