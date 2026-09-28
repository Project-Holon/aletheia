/*
 * function: func_02033BAC
 * address:  0x02033BAC
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   str_020A78CC   0x020A78CC  data
 *   str_020A793C   0x020A793C  data
 *   func_02034714  0x02034714  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A78CC[];
extern const u8 str_020A793C[];
extern void func_02034714(const u8 *file, int line, const u8 *msg);

u32 func_02033BAC(u8 *p, u32 i)
{
    if (i >= *(u32 *)(p + 4)) {
        func_02034714(str_020A78CC, 0xd6, str_020A793C);
    }
    return *(u32 *)(*(u32 *)(p + 0x14) + i * 0xc + 4);
}
