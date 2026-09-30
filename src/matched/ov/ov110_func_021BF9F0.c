/*
 * function: func_021BF9F0
 * address: 0x021BF9F0
 * packet: pkt_ov110_021BF9F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021BFF60 0x021BFF60 thumb ov110
 *   func_021BFF7C 0x021BFF7C thumb ov110
 *   func_021BF734 0x021BF734 thumb ov110
 */
typedef unsigned char u8;
extern void *func_02045770(unsigned);
extern void func_02043B5C(void *,u8);
extern void func_02045334(unsigned);
extern void func_021BFF60(u8 *);
extern void func_021BFF7C(u8 *,unsigned,unsigned);
extern unsigned func_021BF734(u8 *);
void func_021BF9F0(u8 *p) {
    unsigned y,i,n;
    func_02043B5C(func_02045770(*(unsigned *)(p+12)),0);
    func_021BFF60(p);
    n=func_021BF734(*(u8 **)(p+4));
    if(n>16) n=16;
    i=0;
    y=*(unsigned *)(p+0x94);
    for(;i<n;i++) {
        func_021BFF7C(p,i,y);
        if(i&1) y+=24;
    }
    func_02045334(*(unsigned *)(p+12));
}
