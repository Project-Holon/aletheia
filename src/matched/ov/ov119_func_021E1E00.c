/*
 * function: func_021E1E00
 * address: 0x021E1E00
 * packet: pkt_ov119_021E1E00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: side is assigned 0/1 by the original signed p+f54 comparison; both Pair.v[2] snapshots are initialized by complete table copies.
 * arithmetic: ROM b={0,128} makes b.v[side]+16 equal 16/144; mode is forwarded unchanged and no input domain is added.
 * interface: 020450F0's second argument is explicitly narrowed to u8 at 021E1E5A/60; its own body accepts u32.
 * symbols:
 *   d_021E7944 0x021E7944 data a4
 *   d_021E793C 0x021E793C data a4
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E6294 0x021E6294 thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 *   func_021E1718 0x021E1718 thumb ov119
 *   func_021E1778 0x021E1778 thumb ov119
 *   func_021E17E8 0x021E17E8 thumb ov119
 *   func_021E1880 0x021E1880 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E5DFC 0x021E5DFC thumb ov119
 *   func_021E5F14 0x021E5F14 thumb ov119
 *   func_021E0E68 0x021E0E68 thumb ov119
 *   func_021E0E4C 0x021E0E4C thumb ov119
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 *   func_021E194C 0x021E194C thumb ov119
 *   func_021E198C 0x021E198C thumb ov119
 *   func_021E1A44 0x021E1A44 thumb ov119
 *   func_021E1AA8 0x021E1AA8 thumb ov119
 *   func_021E40EC 0x021E40EC thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int v[2]; } Pair;
extern const Pair d_021E7944, d_021E793C;
struct Descriptor;
struct Cfg;
struct MsgBank;
extern void func_020452E8(struct Descriptor *);
extern u32 func_020450F0(u32,u8,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_02041B6C(u32);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_0201DD78(u32,u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_021E6294(char *,int,u32);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E15F8(void *,void *,int,int,char *);
extern void func_021E1718(int,int,int,int,char *);
extern void func_021E1778(int,int,int,int,char *);
extern void func_021E17E8(int,int,int,int,char *);
extern void func_021E1880(int,int,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E5DFC(char *,int,void *);
extern void func_021E5F14(char *,int,int,void *);
extern void func_021E0E68(char *,void *,int,int,int,int,u16,int);
extern void func_021E0E4C(void *);
extern void func_021E5EF8(void *);
extern void func_021E194C(int,int,int,int,char *);
extern void func_021E198C(int,int,int,int,char *);
extern void func_021E1A44(int,int,int,int,char *);
extern void func_021E1AA8(int,int,int,int,char *);
extern void func_021E40EC(void *,int,int);
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
void func_021E1E00(char *p,int mode,void *mon)
{
    Pair a=d_021E7944;
    Pair b=d_021E793C;
    int side=0;
    u32 flag;
    if(I(0xf54)<128) side=1;
    func_021E6294(p,11,4);
    if(P(0x6b4)) func_020452E8(P(0x6b4));
    I(0x6b4)=func_020450F0(6,a.v[side],0,16,18,11,0);
    func_0201DD78(14,15,0);
    flag=func_02017E1C(mon,76,0);
    if(mode==0) {
        func_021E1430(mon,func_02045770(P(0x6b4)),32,0,flag,0,p);
        if(flag==0) {
            func_021E15F8(mon,func_02045770(P(0x6b4)),32,16,p);
            func_021E1718((int)mon,I(0x6b4),8,32,p);
            func_021E1778((int)mon,I(0x6b4),24,128,p);
            func_021E17E8((int)mon,I(0x6b4),64,32,p);
            func_021E1880((int)mon,I(0x6b4),80,48,p);
            func_021E1670(mon,func_02045770(P(0x6b4)),96,0,p,0,0);
            func_021E5DFC(p,side,mon);
            func_021E5F14(p,side,0,mon);
            func_021E0E68(p+0x8c4,mon,I(0x9c4),b.v[side]+16,16,1,*(u16 *)(p+0x5f4),13);
        } else {
            func_021E0E4C(p+0x8c4);
        }
    } else {
        func_021E0E4C(p+0x8c4);
        func_021E5EF8(p+0x950);
        func_021E5EF8(p+0x964);
        func_021E5EF8(p+0x978);
        if(flag==0) {
            func_021E194C((int)mon,I(0x6b4),8,0,p);
            func_021E198C((int)mon,I(0x6b4),16,16,p);
            func_02045CAC(P(0x720),36,P(0x730));
            func_0201C7A4(func_02045770(P(0x6b4)),8,80,P(0x730),P(0x728));
            func_021E1A44((int)mon,I(0x6b4),16,96,p);
            func_02045CAC(P(0x720),37,P(0x730));
            func_0201C7A4(func_02045770(P(0x6b4)),8,112,P(0x730),P(0x728));
            func_021E1AA8((int)mon,I(0x6b4),16,128,p);
        }
    }
    func_021E40EC(p,side,mode);
    func_02045374(P(0x6b4));
    func_02045334(P(0x6b4));
    func_02041B6C(6);
}
