/*
 * function: func_021C0BE8
 * address:  0x021C0BE8
 * packet:   pkt_ov021_021C0BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020520FC  0x020520FC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   d_021DA0E0     0x021DA0E0  data  a4
 *   func_0218C7F0  0x0218C7F0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mtx33;
extern void func_020520FC(int a, int b, int c, struct Mtx33 *m);
extern void func_0207C9D0(u8 *a, u8 *b, int *c);
extern u8 d_021DA0E0;
extern u32 func_0218C7F0(u32 a, u32 b, void *c);
extern void func_020061E4(u32 se);

void func_021C0BE8(u8 *p)
{
    struct {
        int pos[3];
        int scale[3];
        int mtx[9];
    } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mtx);
        func_0207C9D0(p + 8, &d_021DA0E0 + i * 12, s.pos);
        *(u32 *)(p + 0x1c + i * 4) = func_0218C7F0(*(u32 *)(p + 0x18), 0x62, &s);
        p[0x15]++;
        func_020061E4(0x568);
    }
}
