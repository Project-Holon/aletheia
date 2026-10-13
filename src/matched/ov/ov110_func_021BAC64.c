/*
 * function: PMS_INPUT_VIEW_GetUiRes
 * address: 0x021BAC64
 * packet: pkt_ov110_021BAC64
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { unsigned a,b,c; } Triple;
void PMS_INPUT_VIEW_GetUiRes(unsigned p, Triple *out,unsigned i) { *out=*(Triple *)(p+i*12+0x24); }
