/*
 * function: func_021BBB28
 * address: 0x021BBB28
 * packet: pkt_ov223_021BBB28
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C60 return consumed at BB B2, as in matched BB0B0, despite own void forwarding declaration.
 * symbols:
 *   func_021B9914 0x021B9914 thumb ov223
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B9914(char *);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);
extern void func_020061E4(u32);
extern void func_0207D63C(u32,int,int,int,int);
int func_021BBB28(char *p,u32 *state)
{
    int changed=0;
    switch(*state) {
    case 0: func_021B9914(p);if(*(u32 *)(p+0x50)==134) ++*state;break;
    case 1:
        if(*(u8 *)(p+0x268)<8) {++*(u8 *)(p+0x268);changed=1;}
        func_021B9914(p);if(*(u32 *)(p+0x50)==138) ++*state;break;
    case 2:
        if(*(u8 *)(p+0x268)<8) {++*(u8 *)(p+0x268);changed=1;}
        else {*(u32 *)(p+0x24)|=1;++*state;}
        break;
    case 3: ++*state;break;
    case 4:
        if((func_020362DC()&3)!=0||func_02035C60()!=0) {
            if((func_020362DC()&3)!=0) *(u32 *)(p+8)=0;
            else *(u32 *)(p+8)=1;
            func_020061E4(1356);++*state;
        }
        break;
    case 5:
        *(u32 *)(p+0x24)|=2;
        if(*(u8 *)(p+0x268)!=0) {--*(u8 *)(p+0x268);changed=1;}
        ++*state;break;
    case 6:
        if(*(u8 *)(p+0x268)!=0) {--*(u8 *)(p+0x268);changed=1;}
        if(*(u8 *)(p+0x268)==4) ++*state;break;
    case 7:
        if(*(u8 *)(p+0x268)!=0) {--*(u8 *)(p+0x268);changed=1;}
        func_021B9914(p);
        if(*(u32 *)(p+0x50)==180) func_020061E4(1956);
        if(*(u32 *)(p+0x50)==199) {*(u32 *)(p+0x10)=0;return 5;}
        break;
    }
    if(changed) func_0207D63C(0x04000050,5,63,*(u8 *)(p+0x268),16-*(u8 *)(p+0x268));
    ++*(u32 *)(p+0x10);
    return 4;
}
