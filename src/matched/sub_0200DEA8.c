/*
 * function: sub_0200DEA8
 * address:  0x0200DEA8
 * packet:   pkt_0200DEA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082D44(void *dst, const void *src, u32 n);

void sub_0200DEA8(u8 *base, u8 *out, int idx)
{
    u8 *rec = base + 0x104 + idx * 0xf0;

    *(u32 *)out = 0xffff;
    *(u16 *)(out + 4) = rec[0xd5];
    func_02082D44(rec + 0xb4, out + 8, 0x10);
    func_02082D44(rec + 0xd6, out + 0x18, 8);
    func_02082D44(rec + 0xde, out + 0x20, 8);
    func_02082D44(rec + 0xe6, out + 0x28, 8);
    func_02082D44(rec, out + 0x30, 0xb4);
}
