/*
 * function: func_021B99C4
 * address: 0x021B99C4
 * packet: pkt_ov110_021B99C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two-byte zero alignment padding follows the compiled function.
 */

unsigned short func_021B99C4(unsigned int a,unsigned int b,unsigned int c) { unsigned int value; value=*(unsigned int *)(a+b*4+0x38); return *(unsigned short *)(a+(value+c)*2+0x68); }
