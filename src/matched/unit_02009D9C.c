/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x02009D9C
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009D9C, sub_02009DA4
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * alias: the head of the next file after wifilist.c, a 0xD54-byte record whose
 * rest is in pkt_02009DB8.  Same opening as every other record here: a four
 * byte function returning the size over its own pool word, then a constructor
 * that clears exactly that many bytes.
 *
 * Unlike the 0x23 block in src/matched/unit_02009448.c, this constructor
 * *calls* the size function instead of spelling the constant a second time, so
 * the two files differ in the source and not only in the bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009D9C.c \
 *       --addr 0x02009D9C --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

struct Sub02009D9CObj {
    u8 unk000[0xD54];
};

u32 sub_02009D9C(void);

u32 sub_02009D9C(void)
{
    return sizeof(struct Sub02009D9CObj);
}

void sub_02009DA4(struct Sub02009D9CObj *obj)
{
    MI_CpuFill8(obj, 0, sub_02009D9C());
}
