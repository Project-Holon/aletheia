/*
 * function: func_021BBF60
 * address: 0x021BBF60
 * packet: pkt_ov217_021BBF60
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware DISPCNT 04000000 and WIN0H/WIN0V/WINOUT/WININ 04000040/44/4A/48 accessed at 021BBF9E..021BBFFC.
 * definedness: each branch assigning active=1 also initializes all four coordinates; inactive paths never use them.
 * arity: BF3C/BF4C forward the visible r0/r1 into BF1C, despite legacy void declarations.
 * symbols:
 *   func_021BBF3C 0x021BBF3C thumb ov217
 *   func_021BBF4C 0x021BBF4C thumb ov217
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { PLANE_NONE=0,PLANE_OUT=31,PLANE_IN=19 } Plane;
typedef enum { FALSE=0,TRUE=1 } Bool;
extern int func_021BBF3C(unsigned char *p, unsigned char index);
extern int func_021BBF4C(u8 *p,u32 index);
static inline void outside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}
static inline void inside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x04000048=(u16)tmp;
}
void func_021BBF60(u8 *p)
{
    int active;
    int top,bottom;
    int x1,x2,y1,y2;
    active=0;
    top=func_021BBF3C(p,0);
    bottom=func_021BBF4C(p,9);
    if(top>0) {
        active=1;x1=0;x2=240;y1=0;y2=top-1;
    } else if(bottom<192) {
        active=1;x1=0;x2=240;y1=bottom+1;y2=192;
    }
    if(active) {
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & 0xFFFF1FFF)|0x2000;
        *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xFF00)|(x2&0xFF));
        *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xFF00)|(y2&0xFF));
        outside(PLANE_OUT,TRUE);
        inside(PLANE_IN,TRUE);
    } else {
        *(volatile u32 *)0x04000000=*(volatile u32 *)0x04000000 & 0xFFFF1FFF;
    }
}
