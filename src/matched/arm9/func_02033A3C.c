/*
 * function: func_02033A3C
 * address:  0x02033A3C
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   str_020A78CC   0x020A78CC  data
 *   str_020A78D8   0x020A78D8  data
 *   func_02034714  0x02034714  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef u32 (*FP)(void);

extern const u8 str_020A78CC[];
extern const u8 str_020A78D8[];
extern void func_02034714(const char *expr, u32 line, const char *file);

u32 func_02033A3C(u32 *p, u32 i)
{
    FP fp;
    u32 base = p[0];

    if (i >= p[1]) {
        func_02034714((const char *)str_020A78CC, 0x85, (const char *)str_020A78D8);
    }
    fp = *(FP *)(base + i * 0xc + 4);
    return (fp() + 3) & ~3;
}
