/*
 * function: func_021B99B8
 * address:  0x021B99B8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Frees the owned buffer, empties the record and clears the 0x021CF960 global.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0203D7FC(int);

void func_021B99B8(u8 *p)
{
    if (p != 0) {
        if (*(u32 *)p != 0)
            func_0203D7FC(*(u32 *)p);
        *(u32 *)p = 0;
        *(u32 *)(p + 4) = 0;
    }
    *(u32 *)0x021CF960 = 0;
}
