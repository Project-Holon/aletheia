/*
 * function: func_021B7CC4
 * address: 0x021B7CC4
 * packet: pkt_ov091_021B7CC4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes at 021B817E are alignment padding.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B907C 0x021B907C thumb ov091
 *   func_021B8180 0x021B8180 thumb ov091
 *   func_021BC17C 0x021BC17C thumb ov091
 *   func_021BDD78 0x021BDD78 thumb ov091
 *   func_021BC350 0x021BC350 thumb ov091
 *   func_021BE2B4 0x021BE2B4 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BA670 0x021BA670 thumb ov091
 *   func_021BDCC0 0x021BDCC0 thumb ov091
 *   func_021BDD58 0x021BDD58 thumb ov091
 *   func_021BC30C 0x021BC30C thumb ov091
 *   func_021B9BF4 0x021B9BF4 thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9AC 0x021BB9AC thumb ov091
 *   func_021BB9BC 0x021BB9BC thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021B9AC8 0x021B9AC8 thumb ov091
 *   func_021BA5B4 0x021BA5B4 thumb ov091
 *   func_021BA60C 0x021BA60C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021BA4E4 0x021BA4E4 thumb ov091
 *   func_021BA098 0x021BA098 thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub02008F80Obj;
extern void func_020409B4(u32 index);
extern void func_020061E4(u32);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_02017E40(void *,u32,u32);
extern void func_020307B0(void *);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void func_021B907C(u8 *);
extern void func_021B8180(u8 *);
extern int func_021BC17C(unsigned short *p, int id);
extern int func_021BDD78(void *a, u32 id, int slot, u32 heap);
extern int func_021BC350(u8 *,int);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void func_021BB200(u8 *a, u8 *s, int p, int q);
extern void func_021BB2C0(u8 *a, u8 *s);
extern u32 func_021BA670(u8 *p, u16 id);
extern int func_021BDCC0(u8 *,u32);
extern void func_021BDD58(u32 p, void *m);
extern void func_021BC30C(int p);
extern u32 func_021B9BF4(u8 *p, void *mon, u32 param);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021BB9BC(int a, u32 b, u32 c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(u8 *,u32);
extern void func_021BDC3C(u32 p, void *m);
extern int func_021B9AC8(u8 *p, void *mon, u8 bit);
extern u32 func_021BA5B4(u8 *p, void *q);
extern void func_021BA60C(u8 *p, void *q);
extern void func_021B9E3C(void);
extern void func_021BA4E4(u8 *p);
extern void func_021BA098(u8 *p);
extern void func_021B9EB0(u8 *p);
#define W(k) (*(u32 *)(p+(k)))
#define S (*(u8 **)(p+0x280))
#define H(k) (*(u16 *)(S+(k)))
#define T(k) (*(u32 *)(S+(k)))
void func_021B7CC4(u8 *p)
{
    u32 old,buf;
    int r;
    if (S[0x63] == 1) { p[0xc]=0x13; return; }
    switch (T(0x34)) {
    case 0: case 1: case 18: case 21: case 22: case 23: case 25:
        func_021B907C(p); func_020409B4(0); func_021B8180(p); return;
    case 5:
        if (func_021BC17C((short unsigned int *)p,H(0x44)) == 1) {
            func_021B907C(p); func_021B8180(p); return;
        }
        if (func_021BDD78((void *)W(0x38),(u16)H(0x44),0,(u16)(((struct Obj00009 *)p)->f0)) == 1) {
            r=func_021BC350(p,0);
            func_021BE2B4((void *)W(0x38),H(0x44),(int)0,H(0x30),(u16)(((struct Obj00009 *)p)->f0));
            if (r == 2) func_021BB200(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
            else if (r == 19 || r == 13) {
                func_021BB200(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
                func_020061E4(0x56f);
            } else {
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                func_020061E4(0x56f);
            }
            func_021BA670(p,H(0x44)); return;
        }
        if (H(0x44)==0x1d2 && func_021BDCC0(p,W(0x38))==1) {
            func_021BDD58((u32)p,(void *)W(0x38)); T(0x40)=10; p[0xc]=14; W(0x264)=3; return;
        }
        func_021BC30C((int)p); return;
    case 16:
        if (func_021B9BF4(p,(void *)W(0x38),H(0x44)) != 0) {
            func_021BA670(p,H(0x44)); p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=8;
        } else func_021B9788(p,0x51,1,(int)func_021B9E3C);
        return;
    case 9:
        old=func_02017E1C((void *)W(0x38),6,0);
        if (old == 0) {
            if (func_0202136C(H(0x44)) == 1) {
                p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=6; return;
            }
            T(0x40)=10;
            func_021BA624(p,(void *)W(0x38),H(0x44));
            func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            func_021BB97C((u16 *)p,W(0x150));
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,W(0x150),1,H(0x44));
            func_021BC24C(p,(void *)W(0x38),(u16)H(0x44));
            func_021BC288((int)p,(int)((void *)W(0x38)),H(0x44));
            if (func_021BDBF8(p,W(0x38)) == 1) {
                func_021BDC3C((u32)p,(void *)W(0x38));
                func_021B9788(p,0x56,1,(int)func_021BA4E4); W(0x264)=1;
            } else func_021B9788(p,0x56,1,(int)func_021B9E3C);
            func_021BB98C(p,W(0x150)); return;
        }
        if (func_0202136C(old)==1) {
            T(0x40)=10; func_021B9788(p,0x39,1,(int)func_021B9E3C); return;
        }
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9BC((int)p,W(0x150),1,(u16)old);
        func_021B9788(p,0x3a,0,(int)func_021BA098);
        func_021BB98C(p,W(0x150)); return;
    case 14:
        if (func_02017E1C((void *)W(0x38),6,0) == 0) {
            buf=(u32)func_02009050((void *)T(8),0,H(0x5c),((struct Obj00009 *)p)->f0);
            func_02017E40((void *)W(0x38),0xa7,buf); func_020307B0((void *)buf);
            func_02017E40((void *)W(0x38),6,H(0x44));
            func_0200902C((void *)T(8),0,H(0x5c));
            func_021B9788(p,0x62,1,(int)func_021B9E3C);
        } else func_021B9788(p,0x63,1,(int)func_021B9E3C);
        return;
    case 6:
        switch ((u32)func_021B9AC8(p,(void *)W(0x38),T(0x3c))) {
        case 0:
            T(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x29,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150));
            func_021BA5B4(p,(void *)W(0x38)); func_021BA60C(p,(void *)W(0x38)); return;
        case 1:
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x20,0,(int)func_021B9EB0); func_021BB98C(p,W(0x150)); return;
        case 2:
            T(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x2a,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150)); return;
        case 3:
            T(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x2b,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150)); return;
        }
        return;
    case 3:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    default:
        func_021B907C(p); func_021B8180(p); return;
    }
}
