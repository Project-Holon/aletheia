/*
 * function: func_021F0A04
 * address: 0x021F0A04
 * packet: pkt_ov031_021F0A04
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: enum byte-offset locals, product by 0xE0 then separate <<= 1, recover sequential source/destination scaling and entry copies; integer offsets and enum halfword indexes do not.
 * extent: 154 instruction bytes followed by two zero alignment bytes; func_021F0AA0 is separately matched.
 * symbols:
 *   func_021F0A04  0x021F0A04  thumb
 *   func_0204162C  0x0204162C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0202DD24  0x0202DD24  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043814  0x02043814  arm
 *   func_02045334  0x02045334  arm
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_021F07AC  0x021F07AC  thumb  ov031
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef enum { RowZero } RowOffset;

typedef struct {
    char pad[0x4C];
    u32 h[3];
    int k[3];
    char pad2[0x7C - 0x64];
    int f7c;
} O;

extern u16 *func_0204162C(u8 bg);
extern void func_02082D44(void *dst, const void *src, int n);
extern void func_02041B6C(u32 bit);
extern void func_0202DD24(int, int, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043814(u32, u32);
extern void func_02045334(u32);
extern u8 *func_021BBC2C(void *, int);
extern void func_021F07AC(O *, u8 *, int);

void func_021F0A04(O *o, int a, int b, void *c, int d)
{
    u16 *base;
    u16 *src;
    u16 *dst;
    RowOffset sourceOffset;
    RowOffset destOffset;

    base = func_0204162C(6);
    sourceOffset = b * 0xE0;
    sourceOffset <<= 1;
    destOffset = a * 0xE0;
    destOffset <<= 1;
    src = (u16 *)((u32)base + sourceOffset);
    dst = (u16 *)((u32)base + destOffset);
    func_02082D44(dst, src, 0x1C0);
    func_02041B6C(6);
    if (o->k[a] == 0 && o->k[b] == 0) {
        func_0202DD24(o->f7c, a, b);
        return;
    }
    if (o->k[a] == 1 && o->k[b] == 1) {
        func_02043814((u32)func_02045770((struct Descriptor *)o->h[a]), (u32)func_02045770((struct Descriptor *)o->h[b]));
        func_02045334(o->h[b]);
        return;
    }
    func_021F07AC(o, func_021BBC2C(c, d - 2 + a), b);
}
