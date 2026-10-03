/*
 * function: func_021F9754
 * address:  0x021F9754
 * packet:   pkt_ov132_021F9754
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: An enum-typed one stays in r3 while unsigned address/index reuse
 * stays in r1.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef enum { ENABLED = 1 } Enabled;
void func_021F9754(char *p, u32 i, int v)
{
    Enabled one;
    one = ENABLED;
    i = (u32)p + i * 4;
    *(int *)(i + 0xFC) = one;
    *(int *)(i + 0x10C) = v;
}
