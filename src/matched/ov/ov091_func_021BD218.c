/*
 * function: func_021BD218
 * address: 0x021BD218
 * packet: pkt_ov091_021BD218
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 y pins x's front spill; declare the u8 offset before gx to restore r7/r6 allocation.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202136C 0x0202136C thumb
 *   func_0204B878 0x0204B878 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021B9C1C 0x021B9C1C thumb ov091
 *   func_02018430 0x02018430 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021B9D58 0x021B9D58 thumb ov091
 *   func_0201ED04 0x0201ED04 thumb
 *   d_021BED48 0x021BED48 data ov091 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {u16 a,b,c;u8 d,e;} R;
extern u32 *func_02030734(u32,u32,u32,const char *,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_020185F4(int);
extern int func_0201BA68(int);
extern u32 func_0204A6C8(void *,int,int,int,u16);
extern void func_02049238(void *);
extern int func_0201BBE8(int);
extern u32 func_0204B294(u32,u32,u32,u32,R *,int,u16);
extern void func_0204B6F4(u32,int,int);
extern void func_0204B92C(u32,int);
extern void func_0204B3DC(u32,int);
extern u32 func_0202136C(u16);
extern void func_0204B878(u32,int);
extern u32 func_020450F0(int,u8,u8,int,u8,u8,u8);
extern void func_021B9C1C(u8 *,u32,u32,u16,s16,u16);
extern int func_02018430(int);
extern u32 func_0201EC64(u16);
extern void func_0201EFA4(u32,int,int,int,int,int);
extern void func_021B9D58(u8 *,u32,u32,u32,s16,s16,u16);
extern void func_0201ED04(u32);
extern const char d_021BED48[];
#define P(k) (*(u32 *)(p+(k)))
u32 *func_021BD218(u8 *p,void *mon,s16 x,u16 y)
{
    R a;
    R b;
    u32 *s;
    void *h;
    int species;
    int frame;
    u32 gender;
    u32 special;
    int level;
    int egg;
    int rem;
    u8 z;
    int gx;
    u32 gy;
    u32 text;
    s=func_02030734(*(u16 *)p,24,0,d_021BED48,0x199);
    egg=func_02017E1C(mon,0x4c,0);
    h=func_020490F4(7,*(u16 *)p);
    species=func_020185F4((int)mon);
    s[3]=func_0204A6C8(h,func_0201BA68(species),0,1,*(u16 *)p);
    func_02049238(h);
    frame=func_0201BBE8(species);
    a.a=x+16;a.b=y+8;a.c=1;a.d=16;a.e=2;
    {
        int obj=func_0204B294(P(0x1ec),s[3],P(0x194),P(0x1d0),&a,1,*(u16 *)p);
        s[4]=obj;
        func_0204B6F4(obj,frame,1);
    }
    func_0204B92C(s[4],1);
    gender=func_02017E1C(mon,6,0);
    b.a=x+32;b.b=y+16;b.c=0;b.d=8;b.e=2;
    s[5]=func_0204B294(P(0x1ec),P(0x1a8),P(0x184),P(0x1c4),&b,1,*(u16 *)p);
    if(gender!=0) {
        func_0204B3DC(s[5],1);
        if(func_0202136C(gender)==1) func_0204B878(s[5],1);
        else func_0204B878(s[5],0);
    } else func_0204B3DC(s[5],0);
    special=func_02017E1C(mon,0x6e,0);
    rem=x%8;
    z=rem;
    gy=(u32)y>>3;
    gx=(u32)x>>3;
    s[1]=func_020450F0(4,(u8)gx+3,gy,3,2,13,1);
    if(egg==0) {
        if(special==0) func_021B9C1C(p,s[1],7,z+4,0,0x14c0);
        else if(special==1) func_021B9C1C(p,s[1],8,z+4,0,0xc80);
    }
    level=func_02018430((int)mon);
    z=rem;
    s[2]=func_020450F0(4,(u8)gx,(u8)gy+3,6,1,14,1);
    if(egg==0) {
        text=func_0201EC64(*(u16 *)p);
        func_0201EFA4(text,0,level,3,0,1);
        func_021B9D58(p,s[2],text,2,z,0,0x3c40);
        func_0201ED04(text);
    }
    s[0]=1;
    return s;
}
