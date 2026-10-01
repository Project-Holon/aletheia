/*
 * function: func_021BA3F0
 * address: 0x021BA3F0
 * packet: pkt_ov110_021BA3F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: CF70 forwards its legacy third argument only to CE48, whose full
 *   body ignores it and calls D0F8(p,7,0); original A448 sets only r0/r1.
 * symbols:
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BCF70 0x021BCF70 thumb ov110
 *   func_021BF7E0 0x021BF7E0 thumb ov110
 *   func_021BCC58 0x021BCC58 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BB8D8 0x021BB8D8 thumb ov110
 *   func_021BB8B8 0x021BB8B8 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BB954 0x021BB954 thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021BCEE4(u8 *,int);
extern void func_021BB9C0(u8 *,int);
extern int func_021BBB0C(u8 *,int);
extern int func_021BCF38(u8 *,int);
extern void func_021BCF70(u8 *,int);
extern void func_021BF7E0(u8 *);
extern void func_021BCC58(u8 *);
extern void func_021BB658(u8 *,int);
extern void func_021BB8D8(u8 *);
extern void func_021BB8B8(u8 *);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB958(u8 *);
extern void func_021BAD68(u8 *,int);
extern int func_021BB954(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *,unsigned);
extern void func_021B9CBC(u8 *);
void func_021BA3F0(void *unused,u8 *p) {
    u8 *q=*(u8 **)p;
    int a,b;
    switch(*(int *)(p+0x14)) {
    case 0:
        func_021BCEE4(*(u8 **)(q+0x64),1);
        func_021BB9C0(*(u8 **)(q+0x58),0);
        ++*(int *)(p+0x14);
        break;
    case 1:
        a=func_021BBB0C(*(u8 **)(q+0x58),0);
        b=func_021BCF38(*(u8 **)(q+0x64),1);
        if(a && b) {
            func_021BCF70(*(u8 **)(q+0x64),1);
            func_021BF7E0(*(u8 **)(p+4));
            func_021BCC58(*(u8 **)(q+0x64));
            func_021BB658(*(u8 **)(q+0x58),0);
            func_021BB8D8(*(u8 **)(q+0x58));
            func_021BB8B8(*(u8 **)(q+0x58));
            if(func_021BF6DC(*(u8 **)(p+4))==1) func_021BB958(*(u8 **)(q+0x58));
            if(func_021BF6DC(*(u8 **)(p+4))==0) func_021BAD68(p,2);
            else func_021BAD68(p,4);
            ++*(int *)(p+0x14);
        }
        break;
    case 2:
        if(func_021BB954(*(u8 **)(q+0x58))) ++*(int *)(p+0x14);
        break;
    case 3:
        func_021BB6A0(*(u8 **)(q+0x58),func_021BF724(*(u8 **)(q+0x18)));
        func_021BB658(*(u8 **)(q+0x58),1);
        func_021B9CBC(p);
        break;
    }
}
