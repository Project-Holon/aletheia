/*
 * function: func_021AC8E4
 * address:  0x021AC8E4
 * packet:   pkt_ov021_021AC8E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Blk { u32 w[9]; } Blk;
typedef struct B { u32 f0; Blk blk; u16 f28[4]; u16 f30; } B;

struct BbActSys;
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);

void func_021AC8E4(u32 a, B *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);

    if (b->f30 != 0xFFFF)
        func_02050468((struct BbActSys *)h, b->f30, 1);
}
