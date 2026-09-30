/*
 * function: func_021BAB0C
 * address: 0x021BAB0C
 * packet: pkt_ov110_021BAB0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BF72C 0x021BF72C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BCEE4(u8 *,int);
extern int func_021BCF38(u8 *,int);
extern void func_021BCF7C(u8 *,u8,int);
extern u16 func_021BF724(u8 *);
extern u16 func_021BF72C(u8 *);
extern void func_021B9CBC(u8 *);
void func_021BAB0C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 **)p;
    switch(*(u32 *)(p+0x14)) {
    case 0:
        func_021BCEE4(*(u8 **)(q+0x64),2);
        ++*(u32 *)(p+0x14);
        break;
    case 1:
        if(func_021BCF38(*(u8 **)(q+0x64),2)) {
            if(**(u32 **)(q+0x78)==0 && func_021BF724(*(u8 **)(q+0x18))==253 && func_021BF72C(*(u8 **)(q+0x18))==253)
                func_021BCF7C(*(u8 **)(q+0x64),1,1);
            else func_021BCF7C(*(u8 **)(q+0x64),0,0);
            func_021B9CBC(p);
        }
        break;
    }
}
