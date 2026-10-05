/*
 * function: func_0200A908
 * address:  0x0200A908
 * packet:   pkt_0200A908
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf: reads record i (28 bytes) and writes its u16, u8
 * and two bitfields to four out pointers.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[24]; u16 n; u8 a; u8 b : 6, c : 1, d : 1; } Entry;
void func_0200A908(const Entry *p, u32 i, u16 *n, u8 *a, u8 *b, u8 *c)
{
    *n = p[i].n;
    *a = p[i].a;
    *b = p[i].b;
    *c = p[i].c;
}
