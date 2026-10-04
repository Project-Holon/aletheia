/*
 * function: func_020245A0
 * address:  0x020245A0
 * packet:   pkt_020245A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 *
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
void func_020245A0(u8 *p,unsigned i,u16 v) {
    if(i<2) *(u16 *)(p+4+2*i)=v;
}
