/*
 * function: func_021E219C
 * address: 0x021E219C
 * packet: pkt_ov119_021E219C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * control: the pool-hole call func_021E35A0 is written in both arms (x==0, then flag != 0); the compiler cross-jumps the first copy into a b.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02015C48 0x02015C48 thumb
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E2054 0x021E2054 thumb ov119
 *   func_021E35A0 0x021E35A0 thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E14DC 0x021E14DC thumb ov119
 *   func_021E1594 0x021E1594 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E1718 0x021E1718 thumb ov119
 *   func_021E1778 0x021E1778 thumb ov119
 *   func_021E17E8 0x021E17E8 thumb ov119
 *   func_021E1880 0x021E1880 thumb ov119
 *   func_021E194C 0x021E194C thumb ov119
 *   func_021E198C 0x021E198C thumb ov119
 *   func_021E1A44 0x021E1A44 thumb ov119
 *   func_021E1AA8 0x021E1AA8 thumb ov119
 *   func_021E1CA8 0x021E1CA8 thumb ov119
 *   func_021E1CC8 0x021E1CC8 thumb ov119
 *   func_021E2140 0x021E2140 thumb ov119
 *   func_021E5DFC 0x021E5DFC thumb ov119
 *   func_021E5F14 0x021E5F14 thumb ov119
 *   func_021E60BC 0x021E60BC thumb ov119
 *   func_021E0E68 0x021E0E68 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02015C48(void *,u32 *);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
extern void func_0201DD78(u32,u32,u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Obj;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021E2054(char *,void *,int,int);
extern void func_021E35A0(char *,int,int,void *,int);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E14DC(void *,void *,int,int,int,char *);
extern void func_021E1594(void *,void *,int,int,int,char *);
extern void func_021E15F8(void *,void *,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E1718(int a, int b, int x, int y, char *p);
extern void func_021E1778(int a, int b, int x, int y, char *p);
extern void func_021E17E8(int a, int b, int x, int y, char *p);
extern void func_021E1880(int a, int b, int c, int d, char *p);
extern void func_021E194C(int a, int b, int x, int y, char *p);
extern void func_021E198C(int a, int b, int x, int y, char *p);
extern void func_021E1A44(int a, int b, int x, int y, char *p);
extern void func_021E1AA8(int a, int b, int x, int y, char *p);
extern void func_021E1CA8(char *p);
extern void func_021E1CC8(char *p);
extern void func_021E2140(char *p, int a);
extern void func_021E5DFC(char *,int,void *);
extern void func_021E5F14(char *,int,int,void *);
extern void func_021E60BC(char *,void *,int);
extern void func_021E0E68(char *,void *,int,int,int,int,u16,int);
#define I(k) (*(int *)(p+(k)))
#define Q ((void **)(p+0x844))
#define P(k) (*(void **)(p+(k)))
void func_021E219C(char *p,void *mon,int side,int flag)
{
    u32 flag76;
    u32 v[3];
    int i;
    flag76=func_02017E1C(mon,76,0);
    func_021E2054(p,mon,side,flag);
    func_02049B40(23,5,0,448,32,*(u16 *)(p+0x5f4));
    if(Q[side]==0)
        func_021E35A0(p,side,1,mon,0);
    else if(flag!=0)
        func_021E35A0(p,side,1,mon,0);
    v[0]=0xe<<14;
    v[1]=1<<14;
    v[2]=0;
    func_02015C48(Q[side],v);
    func_02015EB0(Q[side]);
    if(*(void **)(p+(1-side)*4+0x844))
        func_02015EA0(*(void **)(p+(1-side)*4+0x844));
    func_0201DD78(15,2,0);
    i=0;
    P(0x6b4)=(void *)func_020450F0(3,1,0,31,24,14,0);
    func_021E1430(mon,func_02045770(P(0x6b4)),16,0,flag76,0,p);
    if(flag76==0) {
        func_021E14DC(mon,func_02045770(P(0x6b4)),0,16,flag76,p);
        func_021E1594(mon,func_02045770(P(0x6b4)),56,16,flag76,p);
        func_021E15F8(mon,func_02045770(P(0x6b4)),96,i,p);
        func_021E1670(mon,func_02045770(P(0x6b4)),80,i,p,i,i);
        func_021E1718((int)mon,(int)P(0x6b4),0,32,p);
        for(i=0;i<2;i++) {
            func_02045CAC(P(0x720),i+36,P(0x730));
            func_0201C7A4(func_02045770(P(0x6b4)),0,i*16+0x88,P(0x730),P(0x728));
        }
        func_021E17E8((int)mon,(int)P(0x6b4),56,32,p);
        func_021E1880((int)mon,(int)P(0x6b4),72,48,p);
        func_021E1A44((int)mon,(int)P(0x6b4),56,136,p);
        func_021E1AA8((int)mon,(int)P(0x6b4),56,152,p);
        func_021E1778((int)mon,(int)P(0x6b4),40,168,p);
        func_021E194C((int)mon,(int)P(0x6b4),152,113,p);
        func_021E198C((int)mon,(int)P(0x6b4),152,128,p);
        func_021E2140(p,(int)mon);
        func_021E5DFC(p,2,mon);
        func_021E0E68(p+0x8c4,mon,I(0x9c4),12,7,0,*(u16 *)(p+0x5f4),12);
    } else {
        if(P(0x960)) func_0204B3DC(P(0x960),i);
        func_021E1CC8(p);
        func_021E1CA8(p);
    }
    func_021E60BC(p,mon,flag76);
    func_021E5F14(p,0,1,mon);
    func_02045374(P(0x6b4));
    func_02045334(P(0x6b4));
    func_02041B6C(3);
}
