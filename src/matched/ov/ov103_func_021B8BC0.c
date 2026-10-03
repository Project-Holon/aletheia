/*
 * function: func_021B8BC0
 * address: 0x021B8BC0
 * packet: pkt_ov103_021B8BC0
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 words[54];} Copy;
void func_021B8BC0(u8 *p,Copy *q) {*q=*(Copy *)(p+8);}
