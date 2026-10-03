/*
 * function: func_021BF608
 * address: 0x021BF608
 * packet: pkt_ov110_021BF608
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF6CC 0x021BF6CC thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BAC0C 0x021BAC0C thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BF4C4 0x021BF4C4 thumb ov110
 *   func_021BF500 0x021BF500 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BF6CC(u8 *,u8,u8);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021BAC0C(u8 *p);
extern int func_021B9C74(void *);
extern void func_021BD7A0(u8 *,void (*)(void));
extern void func_021BF4C4(void);
extern void func_021BF500(u8 *);
void func_021BF608(u8 *p,u32 *q) {
    switch(*q) {
    case 0: func_021BF6CC(p+107,1,1); *(u16 *)(p+72)=1; func_021B9BEC(*(void **)(p+20),21); *q=1; break;
    case 1:
        switch(func_021BAC0C(*(void **)(p+20))) {
        case 0: func_021B9BEC(*(void **)(p+20),23); *q=2; break;
        case 1: func_021BD7A0(p,func_021BF4C4); *q=2; break;
        }
        break;
    case 2: if(func_021B9C74(*(void **)(p+20))) func_021BF500(p); break;
    }
}
