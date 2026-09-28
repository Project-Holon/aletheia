/*
 * function: func_02178F30
 * address:  0x02178F30
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reads a word back out of a 0x14-byte frame filled by func_02058FB4.
 *
 * symbols:
 *   func_02058FB4  0x02058FB4  arm

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_02178F30(void)
{
    void func_02058FB4(void *);
    char buf[0x14];
    func_02058FB4(buf);
    return *(int *)(buf + 0x10);
}
