/*
 * function: func_021BE3B8
 * address: 0x021BE3B8
 * packet: pkt_ov110_021BE3B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021B9C74(unsigned int a);
extern void func_020061E4(u32);
extern void func_021B9BEC(u8 *,int);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF608(u8 *,u32 *);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BD894(u8 *,void *);
int func_021BE3B8(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 **)(p+0x14)))) {
            if(*(u16 *)(p+0x34)&64) {
                func_020061E4(1352);
                if(*(u16 *)(p+0x48)) { *(u16 *)(p+0x48)^=1; func_021B9BEC(*(u8 **)(p+0x14),17); }
                else { func_021B9BEC(*(u8 **)(p+0x14),9); *q=0; }
            } else if(*(u16 *)(p+0x34)&128) {
                func_020061E4(1352);
                if(*(u16 *)(p+0x48)) { func_021B9BEC(*(u8 **)(p+0x14),9); *q=0; }
                else { *(u16 *)(p+0x48)^=1; func_021B9BEC(*(u8 **)(p+0x14),17); }
            } else if(*(u16 *)(p+0x34)&8) {
                func_020061E4(1352); *(u16 *)(p+0x48)=0; func_021B9BEC(*(u8 **)(p+0x14),17);
            } else if(*(u16 *)(p+0x34)&1) {
                func_020061E4(1356);
                if(*(u16 *)(p+0x48)==0) *q=1; else *q=2;
            } else if(*(u16 *)(p+0x34)&2) { func_020061E4(1356); *q=2; }
        }
        break;
    case 1: *q=3; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 3:
    case 4: *q=0; break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 **)(p+0x14)))) func_021BD7A0(p,func_021BD894); break;
    }
    return 0;
}
