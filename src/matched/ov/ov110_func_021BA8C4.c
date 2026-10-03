/*
 * function: func_021BA8C4
 * address: 0x021BA8C4
 * packet: pkt_ov110_021BA8C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFC20 0x021BFC20 thumb ov110
 *   func_021BFB7C 0x021BFB7C thumb ov110
 *   func_021BFBA0 0x021BFBA0 thumb ov110
 *   func_021BB804 0x021BB804 thumb ov110
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_021BB870 0x021BB870 thumb ov110
 *   func_021BB8AC 0x021BB8AC thumb ov110
 *   func_021BB814 0x021BB814 thumb ov110
 *   func_021BB82C 0x021BB82C thumb ov110
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BFC20(u32,int);
extern void func_021BFB7C(u8 *p);
extern int func_021BFBA0(u8 *p);
extern void func_021BB804(void *);
extern void func_021BAD2C(u8 *,int);
extern void func_021BB870(u8 *p);
extern int func_021BB8AC(u8 *p);
extern void func_021BB814(u8 *p);
extern int func_021BB82C(u8 *p);
extern void func_021BC23C(void *);
extern void func_021BC704(u8 *p, u32 flag);
extern void func_021B9CBC(u8 *);
void func_021BA8C4(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 **)p;
    switch(*(u32 *)(p+0x14)) {
    case 0:
        func_021BFC20(*(u32 *)(q+0x5c),0);
        func_021BFB7C(*(void **)(q+0x5c));
        ++*(u32 *)(p+0x14); break;
    case 1:
        if(func_021BFBA0(*(void **)(q+0x5c))) {
            func_021BB804(*(void **)(q+0x58));
            func_021BAD2C(*(u8 **)p,0);
            func_021BB870(*(void **)(q+0x58));
            ++*(u32 *)(p+0x14);
        } break;
    case 2:
        if(func_021BB8AC(*(void **)(q+0x58))) {
            func_021BB814(*(void **)(q+0x58));
            ++*(u32 *)(p+0x14);
        } break;
    case 3:
        if(func_021BB82C(*(void **)(q+0x58))) {
            func_021BC23C(*(void **)(q+0x54));
            func_021BC704(*(u8 **)(q+0x54),0);
            func_021B9CBC(p);
        } break;
    }
}
