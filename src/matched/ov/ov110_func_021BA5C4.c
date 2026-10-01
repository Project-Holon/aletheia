/*
 * function: func_021BA5C4
 * address: 0x021BA5C4
 * packet: pkt_ov110_021BA5C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 246 matched bytes, then two zero alignment bytes at 021BA6BA.
 * symbols:
 *   func_021BBC10 0x021BBC10 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BB838 0x021BB838 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BB854 0x021BB854 thumb ov110
 *   func_021BCC88 0x021BCC88 thumb ov110
 *   func_021BF9F0 0x021BF9F0 thumb ov110
 *   func_021BFAA0 0x021BFAA0 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BFB58 0x021BFB58 thumb ov110
 *   func_021BF784 0x021BF784 thumb ov110
 *   func_021BFC64 0x021BFC64 thumb ov110
 *   func_021BF7AC 0x021BF7AC thumb ov110
 *   func_021BF7B8 0x021BF7B8 thumb ov110
 *   func_021BFDB0 0x021BFDB0 thumb ov110
 *   func_021BFC20 0x021BFC20 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
extern int func_021BBC10(u8 *);
extern void func_021BB658(u8 *,int);
extern void func_021BCEE4(u8 *,int);
extern int func_021BCF38(u8 *,int);
extern void func_021BB838(u8 *);
extern void func_021BB9C0(u8 *,int);
extern int func_021BBB0C(u8 *,int);
extern int func_021BB854(u8 *);
extern void func_021BCC88(u8 *);
extern void func_021BF9F0(u8 *);
extern void func_021BFAA0(u8 *);
extern u8 func_021BF6DC(u8 *);
extern void func_021BAD68(u8 *,int);
extern int func_021BFB58(u8 *);
extern unsigned func_021BF784(u8 *);
extern void func_021BFC64(u8 *,unsigned);
extern unsigned func_021BF7AC(u8 *);
extern unsigned func_021BF7B8(u8 *);
extern void func_021BFDB0(u8 *,unsigned,unsigned);
extern void func_021BFC20(u8 *,unsigned);
extern void func_021B9CBC(u8 *);
void func_021BA5C4(void *unused,u8 *p) {
    u8 *q=*(u8 **)p;
    int a,b;
    switch(*(int *)(p+0x14)) {
    case 0:
        ++*(int *)(p+0x14);
        break;
    case 1:
        if(func_021BBC10(*(u8 **)(q+0x58))) {
            func_021BB658(*(u8 **)(q+0x58),0);
            func_021BCEE4(*(u8 **)(q+0x64),3);
            ++*(int *)(p+0x14);
        }
        break;
    case 2:
        if(func_021BCF38(*(u8 **)(q+0x64),3)) {
            func_021BB838(*(u8 **)(q+0x58));
            func_021BB9C0(*(u8 **)(q+0x58),0);
            ++*(int *)(p+0x14);
        }
        break;
    case 3:
        a=func_021BBB0C(*(u8 **)(q+0x58),0);
        b=func_021BB854(*(u8 **)(q+0x58));
        if(a && b) {
            func_021BCC88(*(u8 **)(q+0x64));
            func_021BF9F0(*(u8 **)(q+0x5c));
            func_021BFAA0(*(u8 **)(q+0x5c));
            if(func_021BF6DC(*(u8 **)(p+4))==0) func_021BAD68(p,3);
            else func_021BAD68(p,5);
            ++*(int *)(p+0x14);
        }
        break;
    case 4:
        if(func_021BFB58(*(u8 **)(q+0x5c))) {
            unsigned x;
            func_021BFC64(*(u8 **)(q+0x5c),func_021BF784(*(u8 **)(q+0x18)));
            x=func_021BF7AC(*(u8 **)(q+0x18));
            func_021BFDB0(*(u8 **)(q+0x5c),x,func_021BF7B8(*(u8 **)(q+0x18)));
            func_021BFC20(*(u8 **)(q+0x5c),1);
            func_021B9CBC(p);
        }
        break;
    }
}
