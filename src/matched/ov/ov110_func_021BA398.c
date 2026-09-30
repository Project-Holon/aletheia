/*
 * function: func_021BA398
 * address: 0x021BA398
 * packet: pkt_ov110_021BA398
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCC58 0x021BCC58 thumb ov110
 *   func_021BB8D8 0x021BB8D8 thumb ov110
 *   func_021BB8B8 0x021BB8B8 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BB954 0x021BB954 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
extern void func_021BCC58(u8 *);
extern void func_021BB8D8(u8 *);
extern void func_021BB8B8(u8 *);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB958(u8 *);
extern int func_021BB954(u8 *);
extern void func_021B9CBC(u8 *);
void func_021BA398(int unused, u8 *p) {
    u8 *q = *(u8 **)p;
    switch (*(int *)(p+0x14)) {
    case 0:
        ++*(int *)(p+0x14);
    case 1:
        func_021BCC58(*(u8 **)(q+0x64));
        func_021BB8D8(*(u8 **)(q+0x58));
        func_021BB8B8(*(u8 **)(q+0x58));
        if (func_021BF6DC(*(u8 **)(p+4)) == 1) func_021BB958(*(u8 **)(q+0x58));
        ++*(int *)(p+0x14);
        break;
    case 2:
        if (func_021BB954(*(u8 **)(q+0x58))) func_021B9CBC(p);
        break;
    }
}
