/*
 * function: func_021C2FEC
 * address:  0x021C2FEC
 * packet:   pkt_ov208_021C2FEC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0204B3B4(u32 v);
extern void func_0204ADA4(u32 v);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);

struct S {
    u8 pad[0x3c];
    u32 a3c[2];
    u32 a44[2];
    u32 a4c[2];
    u32 a54[2];
};

void func_021C2FEC(void *unused, struct S *p, u32 unused2, u32 i)
{
    if (p->a54[i] != 0) {
        func_0204B3B4(p->a54[i]);
        p->a54[i] = 0;
        func_0204ADA4(p->a3c[i]);
        func_0204A8D4(p->a44[i]);
        func_0204AFD8(p->a4c[i]);
    }
}
