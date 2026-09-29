/*
 * unit:     yes
 * function: func_021CF1AC
 * function: func_021CF214
 * address:  0x021CF1AC
 * packet:   pkt_ov021_021CF1AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_02008494 (arm9 unlabelled leaf, Ilias's; no witness outside
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void func_02082D44(const void *a, void *b, unsigned n);  (arm)
 *   void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 * func_021CF214 (unlabelled) is a tail-call stub into func_021CF110.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02008494  0x02008494  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CF110  0x021CF110  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 name[0x20];
    u8 x[8];
} B;

extern void func_02082BCC(void *dst, int v, u32 n);
extern void func_02008494(u32 name, void *dst);
extern void func_02087C6C(void *p);
extern u32 func_020399A8(void);
extern void func_0203D3F8(u32, u32, u32, u32, void *, u32, u32, u32);
extern void func_021CF110(u32, u32, u32);

void func_021CF1AC(u32 a, u32 b, u32 c)
{
    B buf;

    func_02082BCC(&buf, 0, 0x28);
    func_02008494(a, &buf);
    func_02087C6C(buf.x);
    buf.x[6] = b;
    if (c == 1)
        func_0203D3F8(func_020399A8(), 0xff, 0x2700, 0x28, &buf, 0, 0, 0);
    else
        func_0203D3F8(func_020399A8(), 0, 0x2700, 0x28, &buf, 0, 0, 0);
}

void func_021CF214(u32 a, u32 b, u32 c, u32 d)
{
    func_021CF110(d, 1, c);
}
