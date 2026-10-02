/*
 * function: func_021C5BE0
 * address:  0x021C5BE0
 * packet:   pkt_ov136_021C5BE0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C5BE0 0x021C5BE0 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020307B0(void *p);
void func_021C5BE0(u8 *p)
{
    u32 i;
    for (i = 0; i < 0x14; i++)
        func_020307B0(*(void **)(*(u8 **)(p + 8) + i * 4 + 0x298));
}
