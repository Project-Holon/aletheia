/*
 * function: func_0206EA58
 * address:  0x0206EA58
 * packet:   pkt_0206E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206EACC    0x0206EACC  arm
 *
 * Bucket search in a BTX0-style table: the signed halfword at +4 of the block
 * func_0206EACC returns scales the key, the result is a fixed-point index, and
 * the two walks that follow step it down over entries >= v and then up over
 * entries <= v, returning the entry address.
 *
 * The entry stride is four *bytes* and is spelled through a byte pointer, and
 * the two walks are one `while` each: the emitted shape is the rotated form
 * the compiler produces for a conjunction whose second term loads.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206EA58.c \
 *       --func func_0206EA58 --addr 0x0206EA58 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u8 *func_0206EACC(void *p, u32 idx);

u16 *func_0206EA58(u16 *p, u32 arg, u32 v)
{
    u8 *h = func_0206EACC(p, arg);
    s16 n = *(s16 *)(h + 4);
    u8 *t = (u8 *)p + *(u16 *)(h + 6);
    u32 i = (u32)(n * v) >> 12;

    while (i != 0 && *(u16 *)(t + i * 4) >= v)
        i--;
    while (i + 1 < *(u16 *)h && *(u16 *)(t + 4 + i * 4) <= v)
        i++;
    return (u16 *)(t + i * 4);
}
