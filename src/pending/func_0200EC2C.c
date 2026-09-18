/*
 * function: func_0200EC2C
 * address:  0x0200EC2C
 * packet:   pkt_0200EA3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen, 76 concrete bytes: the 6/2-bit split of the byte at
 *           +0x13 wants the shift pair `lsls #26 / lsrs #26` plus a
 *           register-masked insert, which no bitfield or mask spelling
 *           reaches (Thumb has no immediate AND), and the destination byte
 *           load is scheduled twelve bytes earlier than the original's.
 *           See docs/notes/pkt_0200EA3C.c.txt section 2.
 *
 * symbols:
 *   func_02045994  0x02045994  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02045994(void *dst, const void *src, u32 n);

struct Src0200EC2C {
    u16 f0;             /* 0x00 */
    u8  f2;             /* 0x02 */
    u8  f3;             /* 0x03 */
    u32 f4;             /* 0x04 */
    u32 f8;             /* 0x08 */
    u8  b0c[0xb];       /* 0x0c */
    u8  pad17[0xb];     /* 0x17 */
    u8  b22[8];         /* 0x22 */
    u8  pad2a[8];       /* 0x2a */
    u16 arr32[4];       /* 0x32 */
    u8  pad3a[2];       /* 0x3a */
};

struct Bits0200EC2C {
    u8 a : 6;
    u8 b : 2;
};

struct Dst0200EC2C {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u16 f10;
    u8  f12;
    struct Bits0200EC2C b13;
    u16 arr14[4];
};

void func_0200EC2C(struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst)
{
    struct Src0200EC2C *s = base + idx;
    int i;

    dst->f10 = s->f0;
    dst->f12 = s->f2;
    dst->f8 = s->f4;
    dst->fc = s->f8;
    dst->b13.a = s->f3;
    dst->b13.b = s->f3 >> 6;

    func_02045994((void *)dst->f0, s->b0c, 0xb);
    func_02045994((void *)dst->f4, s->b22, 8);

    for (i = 0; i < 4; i++)
        dst->arr14[i] = s->arr32[i];
}
