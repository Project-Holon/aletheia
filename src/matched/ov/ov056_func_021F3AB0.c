/*
 * function: func_021F3AB0
 * address:  0x021F3AB0
 * packet:   pkt_ov056_021F3AB0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ED14  0x0218ED14  thumb  ov021
 *   d_021F426C     0x021F426C  data  a4
 */

typedef unsigned int u32;
typedef signed int   s32;

extern s32 d_021F426C[];

extern void func_02011B8C(u32 a, u32 b);
extern void func_02048AE8(u32, s32 *);
extern void func_02048B0C(u32, s32 *);
extern void func_02048B30(u32, s32 *);
extern void func_0207C9D0(s32 *a, s32 *b, s32 *c);
extern void func_0218ECF4(u32 a, s32 *b);
extern void func_0218EC90(u32 a, s32 *b);
extern void func_0218ED14(u32 a, s32 *b);

void func_021F3AB0(u32 *p)
{
    s32 v2[3];
    s32 v1[3];
    s32 v3[3];

    func_02011B8C(p[1], p[0]);
    func_02048AE8(p[1], v1);
    func_02048B30(p[1], v2);
    func_02048B0C(p[1], v3);
    func_0207C9D0(v1, d_021F426C, v1);
    func_0207C9D0(v2, d_021F426C, v2);
    func_0218ECF4(p[2], v1);
    func_0218EC90(p[2], v2);
    func_0218ED14(p[2], v3);
}
