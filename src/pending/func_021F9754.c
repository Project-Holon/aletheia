/*
 * function: func_021F9754
 * address:  0x021F9754
 * packet:   pkt_021F9754
 * region:   ov132
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  5 bytes differ; pointer base register (r1 vs r3).
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021F9754(char *p, int i, int v)
{
    i = (int)p + i * 4;
    *(int *)(i + 0xFC) = 1;
    *(int *)(i + 0x10C) = v;
}
