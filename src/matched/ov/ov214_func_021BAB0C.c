/*
 * function: func_021BAB0C
 * address: 0x021BAB0C
 * packet: pkt_ov214_021BAB0C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int f0;u32 f4;int f8,fC,f10,f14,f18;u8 b1c,b1d,b1e;} In;
extern int func_0201BC3C(void);
extern u32 func_0201BABC(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void func_021B6208(void*,In*,int,u16);
extern int func_021B629C(void*,int,u16,u16,u8,u16);
extern void func_0204B84C(int,u32);
struct Node;
struct Obj;
extern void func_0204B800(struct Node *node, u32 val);
struct Obj;
extern void func_0204B92C(struct Obj *,u32);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
int func_021BAB0C(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m)
{
    In in;
    int actor;
    in.f0=c;
    in.f4=1;
    in.f8=7;
    in.fC=func_0201BC3C();
    in.f10=func_0201BABC(e,f,g,h);
    in.f14=func_0201BC40();
    in.f18=func_0201BCB4();
    in.b1c=d;
    in.b1d=0;
    in.b1e=3;
    func_021B6208(x,&in,a,b);
    actor=func_021B629C(x,a,i,j,k,b);
    func_0204B84C(actor,l);
    func_0204B800((struct Node *)actor,m);
    func_0204B92C((struct Obj *)actor,1);
    func_0204B6F4((struct Obj *)actor,func_0201BB5C(e,f,g,h),0);
    return actor;
}
