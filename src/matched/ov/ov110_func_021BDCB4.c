/*
 * function: func_021BDCB4
 * address: 0x021BDCB4
 * packet: pkt_ov110_021BDCB4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: The decoded table assigns the first callback arm to case 6 and the second to case 5.
 * symbols:
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BE3B8 0x021BE3B8 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021B9C74(unsigned int a);
extern void func_020061E4(u32);
extern void func_021B9BEC(u8 *,int);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF608(u8 *,u32 *);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF82C(u8 *);
extern int func_021BF680(u8 *);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BE3B8(u8 *,u32 *);
extern int func_021BE4C0(u8 *,u32 *);
int func_021BDCB4(u8 *p,u32 *q)
{
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 **)(p+0x14)))) {
            if(*(u16 *)(p+0x34)&64) {
                func_020061E4(1352);
                *(u16 *)(p+0x48)=1;
                func_021B9BEC(*(u8 **)(p+0x14),7);
                *q=1;
            } else if(*(u16 *)(p+0x34)&136) {
                func_020061E4(1352);
                *(u16 *)(p+0x48)=0;
                func_021B9BEC(*(u8 **)(p+0x14),7);
                *q=1;
            } else if(*(u16 *)(p+0x34)&32) {
                if(*(u16 *)(p+0x4a)!=0) {
                    func_020061E4(1352);
                    *(u16 *)(p+0x4a)=0;
                    func_021B9BEC(*(u8 **)(p+0x14),16);
                }
            } else if(*(u16 *)(p+0x34)&16) {
                if(*(u16 *)(p+0x4a)==0) {
                    func_020061E4(1352);
                    *(u16 *)(p+0x4a)=1;
                    func_021B9BEC(*(u8 **)(p+0x14),16);
                }
            } else if(*(u16 *)(p+0x34)&2) {
                func_020061E4(1361);
                func_021BF4F8(p,(u32)func_021BF608);
            } else if(*(u16 *)(p+0x34)&1) {
                func_020061E4(1356);
                func_021BF82C(p);
                func_021B9BEC(*(u8 **)(p+0x14),10);
                *q=5;
            }
        }
        break;
    case 1:
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
                if(*(u16 *)(p+0x48)==0) {
                    if(func_021BF680(p)) func_020061E4(1356);
                    else func_020061E4(1367);
                    *q=2;
                } else { func_020061E4(1361); *q=3; }
            } else if(*(u16 *)(p+0x34)&2) { func_020061E4(1361); *q=3; }
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=1; break;
    case 6: if(func_021B9C74((unsigned int)(*(u8 **)(p+0x14)))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 **)(p+0x14)))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}
