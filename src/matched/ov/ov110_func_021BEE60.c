/*
 * function: func_021BEE60
 * address: 0x021BEE60
 * packet: pkt_ov110_021BEE60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF208 0x021BF208 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BF444 0x021BF444 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021BF208(u8 *,u32);
extern void func_020061E4(u32);
extern void func_021B9BEC(u8 *,int);
extern int func_021BE4C0(u8 *,void *);
extern int func_021BD894(u8 *,void *);
extern int func_021BF444(u8 *);
void func_021BEE60(u8 *p,u32 *q) {
    switch(func_021BF208(p+0x54,*(u16 *)(p+0x38))) {
    case 1: func_020061E4(1352); func_021B9BEC(*(u8 **)(p+0x14),19); return;
    case 2: func_020061E4(1352); func_021B9BEC(*(u8 **)(p+0x14),20); *q=1; return;
    case 3: func_020061E4(1352); func_021B9BEC(*(u8 **)(p+0x14),20); func_021B9BEC(*(u8 **)(p+0x14),19); *q=2; return;
    }
    if(*(u16 *)(p+0x34)&2) {
        func_020061E4(1361); func_021B9BEC(*(u8 **)(p+0x14),13);
        *(Handler *)(p+0x28)=func_021BE4C0; *q=4; return;
    } else if(*(u16 *)(p+0x34)&1) {
        if(*(u16 *)(p+0x60)!=0) {
            func_020061E4(1361); func_021B9BEC(*(u8 **)(p+0x14),13);
            *(Handler *)(p+0x28)=func_021BE4C0; *q=4; return;
        } else {
            func_020061E4(1356); *(u16 *)(p+0x62)=65535;
            func_021BF444(p);
            func_021B9BEC(*(u8 **)(p+0x14),34); func_021B9BEC(*(u8 **)(p+0x14),14);
            *(Handler *)(p+0x28)=func_021BD894; *q=4;
        }
    }
}
