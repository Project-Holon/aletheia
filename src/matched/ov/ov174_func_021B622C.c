/*
 * function: func_021B622C
 * address: 0x021B622C
 * packet: pkt_ov174_021B622C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: SDK 256x16-affine inline order; word byte offset and address retain queue register allocation.
 * volatile: BG2CNT/BG3CNT read/write at 021B62D0..021B62FC.
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021B6A90 0x021B6A90 thumb ov174
 *   func_021B6F2C 0x021B6F2C thumb ov174
 *   func_021B6F24 0x021B6F24 thumb ov174
 *   func_021B6D3C 0x021B6D3C thumb ov174
 *   func_021B687C 0x021B687C thumb ov174
 *   func_0204A600 0x0204A600 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef enum { SZ0=0,SZ1=1,SZ2=2,SZ3=3 } GXBGScrSize256x16Pltt;
typedef enum { OVER0=0,OVER1=1 } GXBGAreaOver;
typedef enum { SB0=0,SB31=31 } GXBGScrBase;
typedef enum { CB0=0,CB15=15 } GXBGCharBase;
static inline void G2_SetBG2Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000C=(u16)((*(volatile u16 *)0x0400000C &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}
static inline void G2_SetBG3Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000E=(u16)((*(volatile u16 *)0x0400000E &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern void func_021B6A90(u8 *);
extern int func_021B6F2C(int,char *);
extern void func_021B6F24(u8 *,u8 *,int);
extern void func_021B6D3C(u8 *,u8 *);
extern void func_021B687C(u8 *);
extern void func_0204A600(void);
int func_021B622C(u8 *p)
{
    GXBGCharBase a,b;
    unsigned state;
    u8 i;
    switch(p[12]) {
    case 0:
        func_0202208C(0,1,1,0,6,1,*(u16 *)p);
        p[12]=1;
        break;
    case 1:
        if(func_020221A4()==1) p[12]=4;
        break;
    case 2:
        func_0202208C(0,0,0,0,6,1,*(u16 *)p);
        p[12]=3;
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        func_021B6A90(p);
        break;
    }
    if(p[14]<20) p[14]++;
    if(*(int *)(p+44)==0 && *(int *)(p+20)==4) {
        if(p[13]==0) {a=4;b=10;} else {a=7;b=13;}
        G2_SetBG2Control256x16Affine(SZ1,OVER1,(GXBGScrBase)13,a);
        G2_SetBG3Control256x16Affine(SZ1,OVER1,(GXBGScrBase)14,b);
        p[13]=p[13]==0?1:0;
        *(int *)(p+20)=0;
        p[14]=0;
    }
    if(*(char **)(p+44)!=0 && func_021B6F2C((int)p,*(char **)(p+44))==1)
        *(char **)(p+44)=0;
    if(*(int *)(p+44)==0) {
        state=*(unsigned *)(p+20);
        switch(state) {
        case 0: case 1: case 2: case 3: {
            u32 index=(u8)state*4;
            u32 table=(u32)p+28;
            if(*(u8 **)(table+index)!=0) {
                func_021B6F24(p,*(u8 **)(table+index),p[13]);
                *(u8 **)(p+44)=*(u8 **)(table+index);
                if(*(int *)(p+8)==2 && *(int *)(p+20)==1) *(int *)(p+20)=4;
                else (*(int *)(p+20))++;
            } else *(int *)(p+20)=state+1;
            break;
        }
        }
    }
    for(i=0;i<*(int *)(p+8);i++) {
        if(*(u8 **)(p+28+i*4)!=0) func_021B6D3C(p,*(u8 **)(p+28+i*4));
    }
    func_021B687C(p);
    func_0204A600();
    return 0;
}
