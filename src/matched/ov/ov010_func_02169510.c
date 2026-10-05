/*
 * function: func_02169510
 * address:  0x02169510
 * packet:   pkt_ov010_02169510
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (blocker of ov021 func_0218C724).  Copies the 12 bytes
 * at src+4 to dst.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V3 {
    u32 a, b, c;
} V3;

void func_02169510(u8 *src, V3 *dst)
{
    *dst = *(V3 *)(src + 4);
}
