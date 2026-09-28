/*
 * function: func_021E0BA4
 * address:  0x021E0BA4
 * packet:   pkt_021E0BA4
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021E0BA4(char *p, char *q)
{
    char *r = p + 0x8D0 + *(int *)(q + 0x10) * 0x68;

    *(int *)r = 1;
    *(char **)(r + 0x64) = q;
}
