/*
 * function: DWC_RAP_StoreAllowConnect
 * address:  0x02156D70
 * packet:   pkt_02156D70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the low byte of v at 0x7A5 of the ov009 work block.
 *
 * symbols:
 *   _pRapWork  0x021A8264  data  ov009  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    char pad0[0x758];
    u32 err;
    char pad75C[0x76C - 0x75C];
    u32 f76c;
    char pad770[0x7A5 - 0x770];
    u8 b7a5;
    char pad7A6[0x7AC - 0x7A6];
} G;

extern G *_pRapWork;

void DWC_RAP_StoreAllowConnect(u32 v)
{
    _pRapWork->b7a5 = v;
}
