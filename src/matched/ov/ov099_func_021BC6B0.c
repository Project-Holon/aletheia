/*
 * function: func_021BC6B0
 * address:  0x021BC6B0
 * packet:   pkt_ov099_021BC6B0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   KEY_GetTrg  0x020362DC  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(char *p, int v);
extern u32 KEY_GetTrg(void);

int func_021BC6B0(char *p, int v)
{
    if (func_021BA928(p, v) == 0)
        return v;
    if (KEY_GetTrg() == 0)
        return v;
    if (*(u32 *)(p + 0x135C) - 3 <= 1u)
        *(u8 *)(p + 0x1353) = 0x90;
    else
        *(u8 *)(p + 0x1353) = 0x97;
    *(u32 *)(p + 0x1CC) = 0x8A;
    return v;
}
