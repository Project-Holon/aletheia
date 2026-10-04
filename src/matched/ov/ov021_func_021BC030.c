/*
 * function: func_021BC030
 * address:  0x021BC030
 * packet:   pkt_ov021_021BC030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219C98C  0x0219C98C  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xF];
    void *f20;
    int pad24;
    char f28[1];
} Obj;

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0219C98C(u32 a, u16 *b);

void func_021BC030(int a0, Obj *p)
{
    if (p->b10) {
        p->b10 = 0;
        func_0219C98C((u32)p->f20, (u16 *)p->f28);
    }
}
