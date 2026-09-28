/*
 * function: func_021DEB40
 * address:  0x021DEB40
 * packet:   pkt_021DEB40
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049DB4  0x02049DB4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

extern void *func_02049DB4(u32 a, u32 b, u32 c, void **out, u32 d);
extern void func_02040B1C(u32 a, u32 b, u32 c, void *d);
extern void func_020307B0(void *p);

void func_021DEB40(u32 a, u32 b, void *c)
{
    void *out;
    void *r;

    r = func_02049DB4(0x74, b + 0xe, 1, &out, 0x4c);
    func_02040B1C(3, *(u32 *)((char *)out + 0x14), *(u32 *)((char *)out + 0x10), c);
    func_020307B0(r);
}
