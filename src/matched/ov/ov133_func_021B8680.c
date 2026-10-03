/*
 * function: func_021B8680
 * address: 0x021B8680
 * packet: pkt_ov133_021B8680
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Unsigned word state local restores the state/sprite register pair; int and long left DIFF7.
 * ABI: func_021F4B24 declared int here: its forwarded func_021F50D0 returns 0/1; original compares the returned r0 despite legacy void declarations.
 * symbols:
 *   d_021BA57C 0x021BA57C data a4
 *   d_021BA5AC 0x021BA5AC data a4
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA22C 0x021BA22C thumb ov133
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA24C 0x021BA24C thumb ov133
 *   func_021B8254 0x021B8254 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021B8444 0x021B8444 thumb ov133
 *   func_021BA238 0x021BA238 thumb ov133
 *   func_021B82E8 0x021B82E8 thumb ov133
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _fdiv 0x0209CE10 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { int x,y; } Pair;
typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;
extern const Vec d_021BA57C,d_021BA5AC;
extern u8 *func_021BA218(u8 *);
extern void func_021BA22C(u8 *,const Pair *);
extern void func_021F4E8C(int,int,Vec *);
extern void func_021BA21C(u8 *,const Pair *);
extern void func_021BA24C(u8 *,u16);
extern void func_021B8254(u8 *);
extern int func_021BA258(u8 *);
extern u8 *func_021F5450(u8 *,int);
extern int func_021F4B24(u8 *);
extern void func_021F4EE8(int,Flags *,int);
typedef unsigned int   u32;
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021B8444(u8 *);
extern u8 *func_021BA238(u8 *p);
extern void func_021B82E8(u8 *,int);
void func_021B8680(u8 *p)
{
    Vec a,b,c;
    Pair posA,currentB,posB,posC;
    unsigned int state;
    u8 *sprite,*record;
    u16 flag;
    if(*(int *)(p+0x40)==2) {
        a=d_021BA57C;
        sprite=func_021BA218(*(u8 **)(p+0x38));
        posA.x=*(int *)(p+0x1C); posA.y=*(int *)(p+0x20);
        if(*(int *)(p+0x44)>0) a.x=(int)(0.5f+(float)(*(int *)(p+0x44)<<12));
        else a.x=(int)((float)(*(int *)(p+0x44)<<12)-0.5f);
        if(*(int *)(p+0x48)>0) a.y=(int)(0.5f+(float)(*(int *)(p+0x48)<<12));
        else a.y=(int)((float)(*(int *)(p+0x48)<<12)-0.5f);
        func_021BA22C(*(u8 **)(p+0x38),&posA);
        func_021F4E8C(*(int *)(p+0x1884),(int)sprite,&a);
        func_021BA21C(*(u8 **)(p+0x38),(const Pair *)(p+0x44));
        func_021BA24C(*(u8 **)(p+0x38),10);
        func_021B8254(p);
        return;
    } else if(*(int *)(p+0x40)==3) {
        u8 *spriteB;
        spriteB=func_021BA218(*(u8 **)(p+0x38));
        state=func_021BA258(*(u8 **)(p+0x38));
        record=func_021F5450(*(u8 **)(p+0x1880),state);
        posB.x=(int)((float)(*(int *)(record+4)+*(int *)(record+0x10))/4096.0f)+128;
        posB.y=(int)((float)(*(int *)(record+8)+*(int *)(record+0x14))/4096.0f)+96;
        if(posB.x>0) b.x=(int)(0.5f+(float)(posB.x<<12));
        else b.x=(int)((float)(posB.x<<12)-0.5f);
        if(posB.y>0) b.y=(int)(0.5f+(float)(posB.y<<12));
        else b.y=(int)((float)(posB.y<<12)-0.5f);
        if(func_021F4B24(spriteB)==1) b.z=102<<10;
        else if(func_021BA258(*(u8 **)(p+0x38))==7 || func_021BA258(*(u8 **)(p+0x38))==8) b.z=222<<10;
        else b.z=202<<10;
        flag=*(u16 *)(record+0x36);
        func_021F4EE8(*(int *)(p+0x1884),(Flags *)spriteB,1);
        func_021F4E8C(*(int *)(p+0x1884),(int)spriteB,&b);
        func_021F4ED4(*(int *)(p+0x1884),(int)func_021BA218(*(u8 **)(p+0x38)),flag);
        func_021BA21C(*(u8 **)(p+0x38),&posB);
        currentB.x=*(int *)(p+0x1C); currentB.y=*(int *)(p+0x20);
        func_021BA22C(*(u8 **)(p+0x38),&currentB);
        func_021BA24C(*(u8 **)(p+0x38),10);
        *(int *)(p+0x34)=state;
        func_021B8444(p);
        *(int *)(p+0x34)=10;
        return;
    } else if(*(int *)(p+0x40)==1) {
        func_021BA238(*(u8 **)(p+0x38));
        c=d_021BA5AC;
        sprite=func_021BA218(*(u8 **)(p+0x38));
        func_021BA21C(*(u8 **)(p+0x38),(const Pair *)(p+0x44));
        func_021BA24C(*(u8 **)(p+0x38),10);
        posC.x=*(int *)(p+0x1C); posC.y=*(int *)(p+0x20);
        if(*(int *)(p+0x44)>0) c.x=(int)(0.5f+(float)(*(int *)(p+0x44)<<12));
        else c.x=(int)((float)(*(int *)(p+0x44)<<12)-0.5f);
        if(*(int *)(p+0x48)>0) c.y=(int)(0.5f+(float)(*(int *)(p+0x48)<<12));
        else c.y=(int)((float)(*(int *)(p+0x48)<<12)-0.5f);
        func_021BA22C(*(u8 **)(p+0x38),&posC);
        func_021F4E8C(*(int *)(p+0x1884),(int)sprite,&c);
        func_021B82E8(p,1);
        return;
    }
    func_021B82E8(p,0);
}
