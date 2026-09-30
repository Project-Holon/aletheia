/*
 * function: func_021BAA8C
 * address: 0x021BAA8C
 * packet: pkt_ov110_021BAA8C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BCD80 0x021BCD80 thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BF7FC(u8 *);
extern void func_021BCD80(u8 *);
extern void func_021BB958(u8 *);
extern void func_021BB9C0(u8 *,int);
extern int func_021BBB0C(u8 *,int);
extern void func_021B9CBC(u8 *);
void func_021BAA8C(void *unused,u8 *p) {
    u8 *q;
    u32 x;
    q=*(u8 **)p;
    x=func_021BF7FC(*(u8 **)(p+4));
    switch(*(u32 *)(p+0x14)) {
    case 0:
        func_021BCD80(*(u8 **)(q+0x64));
        func_021BB958(*(u8 **)(q+0x58));
        func_021BB9C0(*(u8 **)(q+0x58),x!=0);
        ++*(u32 *)(p+0x14);
        break;
    case 1:
        if(func_021BBB0C(*(u8 **)(q+0x58),x!=0)) ++*(u32 *)(p+0x14);
        break;
    case 2: func_021B9CBC(p); break;
    }
}
