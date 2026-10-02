/*
 * function: func_021BE580
 * address: 0x021BE580
 * packet: pkt_ov110_021BE580
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: BAF7C reads the selection still live in r1 from E6A6 through the ordinary-mode arm.
 * symbols:
 *   func_021BB054 0x021BB054 thumb ov110
 *   func_021BD868 0x021BD868 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BAFAC 0x021BAFAC thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BEB44 0x021BEB44 thumb ov110
 *   func_021BAF7C 0x021BAF7C thumb ov110
 *   func_021BEB60 0x021BEB60 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021BB054(u8 *);
extern void func_021BD868(u8 *);
extern void func_020061E4(u32);
extern void func_021B9BEC(u8 *,int);
extern void func_021BF82C(u8 *);
extern int func_021BAFAC(u8 *);
extern int func_021BD894(u8 *,void *);
extern int func_021BEB44(u8 *);
extern void func_021BAF7C(u8 *,int);
extern int func_021BEB60(u8 *);
void func_021BE580(u8 *p,u32 *q)
{
    if((*(u16 *)(p+0x34)&8) && p[0x69]==1) {
        *(u16 *)(p+0x4c)=252;
        if(func_021BB054(*(u8 **)(p+0x1c))) {
            func_021BD868(p);
            *q=2;
            return;
        }
        func_020061E4(1367);
        func_021B9BEC(*(u8 **)(p+0x14),18);
        return;
    }
    if(*(u32 *)(p+0x3c)==0 || (*(u16 *)(p+0x34)&4)) {
        func_020061E4(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 **)(p+0x14),25);
        *q=4;
        return;
    }
    if(*(u16 *)(p+0x34)&2) {
        if(p[0x69]==1 && func_021BAFAC(*(u8 **)(p+0x1c))) {
            *(u16 *)(p+0x50)=*(u16 *)(p+0x4c);
            *q=1;
            if(*(u16 *)(p+0x4c)!=253) {
                *(u16 *)(p+0x4c)=253;
                func_021B9BEC(*(u8 **)(p+0x14),18);
            }
            func_020061E4(1363);
            func_021B9BEC(*(u8 **)(p+0x14),32);
            func_021BB054(*(u8 **)(p+0x1c));
            func_021B9BEC(*(u8 **)(p+0x14),30);
            return;
        }
        if(p[0x69]==1 && *(u16 *)(p+0x4c)!=254) {
            *(u16 *)(p+0x4c)=254;
            func_021B9BEC(*(u8 **)(p+0x14),18);
        }
        func_020061E4(1361);
        func_021B9BEC(*(u8 **)(p+0x14),11);
        *(Handler *)(p+0x28)=func_021BD894;
        *q=2;
        return;
    }
    if(*(u16 *)(p+0x34)&1) {
        if(*(u16 *)(p+0x4c)==252) {
            if(func_021BB054(*(u8 **)(p+0x1c))) {
                func_021BD868(p);
                *q=2;
                return;
            }
            func_020061E4(1367);
            return;
        } else if(*(u16 *)(p+0x4c)==253) {
            if(p[0x69]==1 && func_021BAFAC(*(u8 **)(p+0x1c))) {
                *(u16 *)(p+0x50)=*(u16 *)(p+0x4c);
                *q=1;
                func_020061E4(1363);
                func_021B9BEC(*(u8 **)(p+0x14),32);
                func_021BB054(*(u8 **)(p+0x1c));
                func_021B9BEC(*(u8 **)(p+0x14),30);
                return;
            }
            func_020061E4(1367);
            return;
        } else if(*(u16 *)(p+0x4c)==254) {
            func_020061E4(1361);
            func_021B9BEC(*(u8 **)(p+0x14),11);
            *(Handler *)(p+0x28)=func_021BD894;
            *q=2;
            return;
        } else if(p[0x69]==0) {
            func_021B9BEC(*(u8 **)(p+0x14),33);
            if(func_021BEB44(p)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            func_020061E4(1367);
            return;
        } else {
            func_021BAF7C(*(u8 **)(p+0x1c),*(u16 *)(p+0x4c));
            func_020061E4(1356);
            func_021BB054(*(u8 **)(p+0x1c));
            func_021B9BEC(*(u8 **)(p+0x14),30);
            func_021B9BEC(*(u8 **)(p+0x14),33);
            return;
        }
    }
    if(func_021BEB60(p)) {
        func_020061E4(1352);
        func_021B9BEC(*(u8 **)(p+0x14),18);
    }
}
