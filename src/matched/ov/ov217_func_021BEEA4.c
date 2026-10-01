/*
 * function: func_021BEEA4
 * address: 0x021BEEA4
 * packet: pkt_ov217_021BEEA4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * C11DC forwards r0/r1 through C1AC0; caller's narrowed index remains in its prototype.
 * C20CC overwrites incoming r1 with 1 before forwarding to C218C; legacy unused trailing parameter omitted.
 * symbols:
 *   func_021C20D8 0x021C20D8 thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_021C11FC 0x021C11FC thumb ov217
 *   func_021C20B4 0x021C20B4 thumb ov217
 *   func_021C20CC 0x021C20CC thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021C20D8(unsigned);
extern unsigned func_021BF810(char *);
extern unsigned func_021BF76C(void *);
extern unsigned func_021BF7F4(void *);
extern unsigned func_021C11DC(unsigned,u8);
extern unsigned func_021C11FC(unsigned,u8,unsigned,unsigned);
extern void func_021C20B4(unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021C20CC(unsigned);
void func_021BEEA4(char *p)
{
    unsigned object,index,x,y;
    func_021C20D8(*(unsigned *)(p+0x2d0));
    if (*(unsigned *)(p+0x3d0)==1) return;
    if (*(unsigned *)(p+0x3c8)==0) return;
    if (func_021BF810(p)==0) return;
    object=func_021BF76C(p);
    index=func_021BF7F4(p);
    if (func_021C11DC(object,index)==0) return;
    if (*(unsigned *)(p+0x3c8)!=0) {
        object=func_021BF76C(p);
        index=func_021BF7F4(p);
        func_021C11FC(object,index,(unsigned)&x,(unsigned)&y);
        func_021C20B4(*(unsigned *)(p+0x2d0),104,34,x,y);
        func_021C20CC(*(unsigned *)(p+0x2d0));
    }
}
