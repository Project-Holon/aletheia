/*
 * function: func_021B6490
 * address:  0x021B6490
 * packet:   pkt_021B6490
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 */
typedef unsigned int u32;

extern int func_020221A4(void);

u32 func_021B6490(char *p)
{
    if (func_020221A4() == 1)
        return *(u32 *)(p + 0x6054);
    return 2;
}
