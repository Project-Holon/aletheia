/*
 * function: func_021B916C
 * address: 0x021B916C
 * packet: pkt_ov091_021B916C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G8L7. The only residue of the old draft was the 0xa1/0xa0 getter arm (case 16..19): the image keeps n (the 0xa1 getter result) in a stack word at [sp,#4] below the two item tables and keeps the pooled zero in r7, frame 0x28. With n as a plain local the allocator rematerialised the zero instead and kept n in r7 (frame 0x24, 122 bytes off). A local aggregate that holds n together with the two item tables (tables address-taken for func_021BBAF8) keeps n in memory at that place with no other change: EXACT in c99 and c. A volatile n and a one-field struct n give EXACT and the old residue respectively; the aggregate is the form kept. The original may have used another aggregate that holds one count next to the lists; the layout shows only that one word sits below table b. Held for integrator review of the form.
 * symbols:
 *   func_021B8F68 0x021B8F68 thumb ov091
 *   func_021B8FC4 0x021B8FC4 thumb ov091
 *   func_021BB714 0x021BB714 thumb ov091
 *   func_021BB7E8 0x021BB7E8 thumb ov091
 *   func_021BBAF8 0x021BBAF8 thumb ov091
 *   func_021B8418 0x021B8418 thumb ov091
 *   func_021BB4A0 0x021BB4A0 thumb ov091
 *   func_021BB440 0x021BB440 thumb ov091
 *   func_021BB43C 0x021BB43C thumb ov091
 *   func_021BBE5C 0x021BBE5C thumb ov091
 *   func_021BA394 0x021BA394 thumb ov091
 *   func_021B99E4 0x021B99E4 thumb ov091
 *   func_0215EA14 0x0215EA14 thumb ov010
 *   func_02013E04 0x02013E04 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021BEC0C 0x021BEC0C data a4
 *   d_021BEC1C 0x021BEC1C data a4
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021BBDEC 0x021BBDEC thumb ov091
 *   func_021B7B98 0x021B7B98 thumb ov091
 *   func_021BC1B4 0x021BC1B4 thumb ov091
 *   func_021BC1D0 0x021BC1D0 thumb ov091
 *   func_021BC2C8 0x021BC2C8 thumb ov091
 *   func_021BA65C 0x021BA65C thumb ov091
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021BAFA0 0x021BAFA0 thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_021B9F34 0x021B9F34 thumb ov091
 *   func_021BA004 0x021BA004 thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
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
extern int func_021BDCC0(char *p);
extern void func_021BDD58(u32 p, void *m);
extern void func_021BC30C(int p);
extern u32 func_021B9BF4(u8 *p, void *mon, u32 param);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9AC(u8 *,u32,u32,u16);
extern void func_021BB9BC(int a, u32 b, u32 c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(char *p);
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
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5);
extern void func_021B7B98(u8 *);
extern int func_021BC1B4(unsigned short *p, void *id);
extern int func_021BC1D0(u8 *);
extern void func_021BC2C8(int p);
extern u32 func_021BA65C(u8 *p, u16 id);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
extern int func_021BDC5C(u8 *,u32);
extern void func_021BDCA0(u32 p, void *m);
extern void func_021B9F34(u8 *p);
extern void func_021BA004(u8 *p);
extern void func_021B9E20(u8 *p);
extern void func_021B8F68(u8 *,int);
extern void func_021B8FC4(u8 *,int);
extern void func_021BB714(void *,u32 *,u32);
extern void func_021BB7E8(u8 *,u32 *,u32);
extern void func_021BBAF8(u8 *,u8 *,int *);
extern void func_021B8418(u8 *);
extern int func_021BB4A0(u8 *,int *);
extern void func_021BB440(u8 *p, u32 *q, int v);
extern int func_021BB43C(int *);
extern void func_021BBE5C(int,int);
extern void func_021BA394(u8 *p);
extern int func_021B99E4(void *,u8);
extern u32 func_0215EA14(int,u8 *);
extern u32 func_02013E04(u32 id);
extern void func_0204B3DC(struct Obj *p, u32 v);
typedef struct { int v[4]; } Four;
extern const Four d_021BEC0C,d_021BEC1C;
#define A (*(int **)((p+W(0x2c)*4)+0x160))
void func_021B916C(u8 *p)
{
    struct { u32 n; Four b; Four a; } L;
    u32 old;
    int r,level;
    u32 flag;
    u8 i;
    u8 *q;
    if (S[0x63] == 1) { p[0xc]=19; return; }
    switch (W(0x3c)) {
    case 6:
        func_021B8F68(p,W(0x2c)); W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    case 3:
        func_021B8F68(p,W(0x2c)); func_021B8FC4(p,W(0x2c));
        W(0x30)=W(0x2c); p[0xc]=3; W(0x38)=0; W(0x14)=0;
        func_021BB714(p,(u32 *)W(0x150),0); func_021BB7E8(p,(u32 *)W(0x150),11);
        func_021B8418(p); return;
    case 4:
        L.a=d_021BEC0C;
        func_021B907C(p); func_021BB714(p,(u32 *)W(0x150),2);
        func_021BB7E8(p,(u32 *)W(0x150),19);
        func_021BBAF8(p,(u8 *)W(0x154),L.a.v); func_020409B4(0); return;
    case 5:
        L.b=d_021BEC1C;
        func_021B907C(p); func_021BB714(p,(u32 *)W(0x150),2);
        func_021BB7E8(p,(u32 *)W(0x150),19);
        func_021BBAF8(p,(u8 *)W(0x154),L.b.v); func_020409B4(0); return;
    case 0:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=1; return;
    case 20:
        q=(u8 *)T(0x14); flag=0;
        r=func_021BB4A0(p,A);
        if (r == 0) {
            func_021BB440(p,(u32 *)A,p[0x105]); p[0x105]=p[0x105]+1;
            func_021B7B98(p);
            if (p[0x105] == q[3]) flag=1;
            p[0xc]=2;
        } else if (r == 2) {
            func_021B9788(p,0x90,1,(int)func_021B9E20); func_020061E4(0x557);
        } else if (r == 3) {
            func_021B9788(p,0x91,1,(int)func_021B9E20); func_020061E4(0x557);
        } else if (r == 4) {
            func_021B9788(p,q[3]+0x5c,1,(int)func_021B9E20); func_020061E4(0x557);
        }
        W(0x38)=0;
        if (flag==1) {
            func_021BAFA0(p,(u8 *)((u32)A),0); W(0x2c)=6;
            if (W(8)==0) {
                func_021BBE5C(*(int *)((p+(u8)(W(0x2c)-6)*4)+0x108),1);
                func_0204B3DC((struct Obj *)W(0x1d8),0); return;
            }
        } else if (W(8)==0) func_021B8F68(p,W(0x2c));
        return;
    case 21:
        level=func_021BB43C(A);
        for (i=0; i<6; i++) {
            r=func_021BB43C(*(int **)((p+i*4)+0x160));
            if (r <= 5 && r > level) func_021BB440(p,(u32 *)(*(int **)((p+i*4)+0x160)),r-1);
        }
        func_021BB440(p,(u32 *)A,6); p[0x105]=p[0x105]-1;
        if (W(8)==0) func_021B8F68(p,W(0x2c));
        W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    case 10:
        old=func_02017E1C((void *)W(0x38),6,0);
        func_021BC24C(p,(void *)W(0x38),0); func_021BC288((int)p,(int)((void *)W(0x38)),0);
        if (old==0) {
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021B9788(p,0x3d,1,(int)func_021B9E20); func_021BB98C(p,W(0x150)); return;
        }
        if (func_021BA65C(p,old)==999) {
            func_021B9788(p,0x3f,1,(int)func_021B9E20); return;
        }
        func_021BA624(p,(void *)W(0x38),0); func_021BB2C0(p,(u8 *)((u32)A));
        func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9AC(p,W(0x150),1,old);
        if (func_021BDC5C(p,W(0x38))==1) {
            func_021BDCA0((u32)p,(void *)W(0x38)); func_021B9788(p,0x3e,1,(int)func_021BA4E4); W(0x264)=2;
        } else func_021B9788(p,0x3e,1,(int)func_021B9E20);
        func_021BB98C(p,W(0x150)); return;
    case 11:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 9:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=3; return;
    case 12:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=7; return;
    case 13:
        func_021B9788(p,0x17,0,(int)func_021BA394); return;
    case 7:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 16: case 17: case 18: case 19:
        if (T(0x34)==5) {
            if (func_021BDD78((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),*(u16 *)p)==1) {
                old=func_02017E1C((void *)W(0x38),W(0x3c)+0x26,0);
                func_020409B4(0); func_021BC350(p,old);
                func_021BE2B4((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),H(0x30),*(u16 *)p);
                func_021BB2C0(p,(u8 *)((u32)A)); func_021BA670(p,H(0x44)); func_020061E4(0x56f);
            } else func_021BC30C((int)p);
            return;
        }
        r=func_021B99E4((void *)W(0x38),W(0x3c)-16);
        if ((u32)(r-22)<=1) {
            if (func_02013E04(H(0x30))==0) {
                func_021B9788(p,0x50,1,(int)func_021B9E20); return;
            }
            L.n=func_02017E1C((void *)W(0x38),0xa1,0);
            old=func_02017E1C((void *)W(0x38),0xa0,0);
            if (old > L.n/5) {
                func_021B8F68(p,W(0x2c)); func_021B8FC4(p,W(0x2c)); W(0x34)=W(0x2c);
                p[0xc]=4; W(0x38)=0; W(0x14)=0;
                func_021BB714(p,(u32 *)W(0x150),0); func_021BB7E8(p,(u32 *)W(0x150),17);
                func_021B8418(p);
            } else func_021B9788(p,0x6b,1,(int)func_021B9E20);
            return;
        }
        switch (func_0215EA14(r-11,S+0x1c)) {
        case 0: p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=r; return;
        case 1: func_021B9788(p,0x50,1,(int)func_021B9E20); return;
        case 2: func_021B9788(p,0x38,1,(int)func_021B9E20); return;
        case 3: func_021B9788(p,0x9f,1,(int)func_021B9E20); return;
        case 4: func_021B9788(p,0x4f,1,(int)func_021B9E20); return;
        }
        return;
    default:
        func_021B8F68(p,W(0x2c)); W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    }
}
