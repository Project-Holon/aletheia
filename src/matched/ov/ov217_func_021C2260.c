/*
 * function: func_021C2260
 * address:  0x021C2260
 * packet:   pkt_ov217_021C2260
 * region:   ov217
 * compiler: dsi/1.1p1
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

extern void func_0204B3DC(u32 a, u32 b);

void func_021C2260(void *p)
{
    s32 i;
    s32 n = *(u8 *)((char *)p + 0x298);
    for (i = 0; i < n; i++)
        func_0204B3DC(*(u32 *)((char *)p + 0x3c + i * 0x18), 0);
}
