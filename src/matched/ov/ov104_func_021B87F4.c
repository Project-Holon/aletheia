/*
 * function: func_021B87F4
 * address: 0x021B87F4
 * packet: pkt_ov104_021B87F4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 words[33]; } Record;
void func_021B87F4(u8 *p,Record *out) { *out=*(Record *)(p+8); }
