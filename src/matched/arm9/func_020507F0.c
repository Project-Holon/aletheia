/*
 * function: func_020507F0
 * address:  0x020507F0
 * packet:   pkt_020507F0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_020507F0(void *p, int idx, u32 v)
{
    char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40);
    *(u32 *)(e + 24) = v;
}
