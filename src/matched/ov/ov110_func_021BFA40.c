/*
 * function: func_021BFA40
 * address: 0x021BFA40
 * packet: pkt_ov110_021BFA40
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
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_021BFF60(u8 *);
extern void func_021BFF7C(u8 *,unsigned,unsigned);
extern unsigned func_021BF734(u8 *);
void func_021BFA40(u8 *p,unsigned a) {
    unsigned y,i,n;
    func_02043B5C(func_02045770((struct Descriptor *)*(unsigned *)(p+12)),0);
    func_021BFF60(p);
    *(unsigned *)(p+0x98)=a*2;
    n=func_021BF734(*(u8 **)(p+4));
    if(n>16) n=16;
    i=0;
    y=*(unsigned *)(p+0x94);
    for(;i<n;i++) {
        func_021BFF7C(p,*(unsigned *)(p+0x98)+i,y);
        if(i&1) y+=24;
    }
    func_02045334((struct Descriptor *)*(unsigned *)(p+12));
}
