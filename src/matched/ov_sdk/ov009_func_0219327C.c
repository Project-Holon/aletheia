/*
 * function: strzcpy
 * address:  0x0219327C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the byte one before the sum of the block and the count.
 *
 * symbols:
 *   strncpy  0x02094860  arm  arm9

 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *strncpy(u8 *dest, const u8 *src, u32 n);

void strzcpy(char *p, int b, int n)
{
    strncpy((u8 *)p, (const u8 *)b, n);
    *(char *)(p + n - 1) = 0;
}

