/*
 * function: func_02196454
 * address:  0x02196454
 * packet:   pkt_ov021_02196454
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02051C6C  0x02051C6C  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Descriptor;
extern void func_02051C6C(void *p);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 a);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020452E8(struct Descriptor *d);

void func_02196454(u8 *p)
{
    int i;

    if (*(u32 *)(p + 0x24) != 0)
        func_02051C6C((void *)(*(u32 *)(p + 0x24)));
    *(u32 *)(p + 0x24) = 0;
    for (i = 0; i < 4; i++) {
        u32 *q = (u32 *)p + i;
        if (q[5] != 0) {
            func_020456F8((struct Descriptor *)q[5]);
            func_02041B6C(5);
            func_0201F7A8((void *)q[5], 2);
            func_020452E8((struct Descriptor *)q[5]);
        }
        q[5] = 0;
    }
    *(u32 *)(p + 0x2F4) = 0;
}
