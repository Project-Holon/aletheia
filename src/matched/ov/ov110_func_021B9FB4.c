/*
 * function: func_021B9FB4
 * address: 0x021B9FB4
 * packet: pkt_ov110_021B9FB4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021BA058 reads hardware register 0x04000304 before updating it.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_021BBCF0 0x021BBCF0 thumb ov110
 *   func_021BB2CC 0x021BB2CC thumb ov110
 *   func_021BF8BC 0x021BF8BC thumb ov110
 *   func_020403F4 0x020403F4 arm
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern void func_020452E8(void *);
extern void func_021BBCF0(void *);
extern void func_021BB2CC(void *);
extern void func_021BF8BC(void *);
extern void func_0201D83C(void *);
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_020403F4(int);
extern void func_021B9CBC(u8 *);
void func_021B9FB4(int unused, u8 *p) {
    u8 *q = *(u8 **)p;
    switch (*(int *)(p+0x14)) {
    case 0:
        func_0202208C(0,0,0,0,5,1,42);
        ++*(int *)(p+0x14);
        break;
    case 1:
        if (func_020221A4()) {
            func_020452E8(*(void **)(*(u8 **)p+0x6C));
            func_021BBCF0(*(void **)(*(u8 **)p+0x54));
            func_021BB2CC(*(void **)(*(u8 **)p+0x58));
            func_021BF8BC(*(void **)(*(u8 **)p+0x5C));
            func_0201D83C(*(void **)(q+0x80));
            func_0201C6EC(*(void **)(q+0x7C));
            func_0201C4C0(*(void **)(q+0x7C));
            *(void **)(q+0x7C) = 0;
            func_020403F4(0);
            func_020403F4(1);
            func_020403F4(2);
            func_020403F4(3);
            func_020403F4(4);
            func_020403F4(5);
            func_020403F4(6);
            *(volatile u16 *)0x04000304 |= 0x8000;
            func_021B9CBC(p);
        }
        break;
    }
}
