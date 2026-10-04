/*
 * function: func_021C09B0
 * address:  0x021C09B0
 * packet:   pkt_ov021_021C09B0
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
 *   func_0218C7F0  0x0218C7F0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   d_021DA098  0x021DA098  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Mtx33;
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_0207C9D0(u8 *dst, u8 *src, int *v);
struct Blk;
extern u8 *func_0218C7F0(u8 *owner, u32 x, struct Blk *src);
extern void func_020061E4(u32 a);
extern u8 d_021DA098[];

void func_021C09B0(u8 *p)
{
    struct { int out[3]; int scale[3]; int mat[9]; } s;
    u32 i;

    i = p[0x15];
    if (p[0x14] > i) {
        s.scale[0] = 0x1000;
        s.scale[1] = 0x1000;
        s.scale[2] = 0x1000;
        func_020520FC(0, 0, 0, (struct Mtx33 *)s.mat);
        func_0207C9D0(p + 8, d_021DA098 + i * 12, s.out);
        *(u32 *)(p + 0x1c + i * 4) = (u32)func_0218C7F0((u8 *)(*(u32 *)(p + 0x18)), 0x62, (struct Blk *)s.out);
        p[0x15] = p[0x15] + 1;
        func_020061E4(0x568);
    }
}
