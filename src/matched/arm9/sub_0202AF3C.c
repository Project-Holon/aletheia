/*
 * function: func_0202AF3C
 * address:  0x0202AF3C
 * packet:   pkt_0202AF34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MyStruct {
    u16 unk00;
    u16 pad02;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8  a[6];
    u8  b[6];
    u8  c[6];
    u8  d[6];
};

void func_0202AF3C(const struct MyStruct *src, struct MyStruct *dst)
{
    int i;

    dst->unk00 = src->unk00;
    dst->unk04 = src->unk04;
    dst->unk08 = src->unk08;
    dst->unk0C = src->unk0C;

    for (i = 0; i < 6; i++) {
        dst->a[i] = src->a[i];
        dst->b[i] = src->b[i];
        dst->c[i] = src->c[i];
        dst->d[i] = src->d[i];
    }
}
