/*
 * function: func_021C2194
 * address:  0x021C2194
 * packet:   pkt_ov217_021C2194
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u32 func_021C2194(void *p)
{
    s32 i;
    for (i = 0; i < *(u8 *)((char *)p + 0x298); i++) {
        if (*(u32 *)((char *)p + 0x28 + i * 0x18) == 0)
            return 0;
    }
    return 1;
}
