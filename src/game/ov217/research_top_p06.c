/*
 * file:     research_top_p06.c
 * unit:     yes
 * function: func_021BA388, func_021BA3B0, func_021BA3B4, func_021BA3D0, func_021BA3D8, func_021BA3E0, func_021BA3E8, func_021BA40C, func_021BA41C, func_021BA434, func_021BA4C8, func_021BA4CC, func_021BA4D0, func_021BA4D4, func_021BA4E0, func_021BA4FC, func_021BA504, func_021BA560, func_021BA5B4, func_021BA5BC, func_021BA5D8, func_021BA5E4, func_021BA5F8, func_021BA624, func_021BA63C, func_021BA674, func_021BA67C, func_021BA68C, func_021BA698, func_021BA748, func_021BA768, func_021BA7B4, func_021BA7B8, func_021BA7D0, func_021BA7E0, func_021BA82C, func_021BA830, func_021BA848, func_021BA858, func_021BA86C, func_021BA8E0, func_021BA8FC, func_021BA910, func_021BA960, func_021BA978, func_021BA9D0, func_021BA9E8, func_021BA9FC, func_021BAA28, func_021BAA40, func_021BAA48, func_021BAAB8, func_021BAAC4, func_021BAAD8, func_021BAAF4, func_021BAB0C, func_021BAB38
 * address:  0x021BA388
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C29F8  0x021C29F8  thumb  ov217
 *   d_021C3008  0x021C3008  data  a4
 *   d_021C3004  0x021C3004  data  a4
 *   func_021C2A00  0x021C2A00  thumb  ov217
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *   func_021C09B4 0x021C09B4 thumb ov217
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_021C09F8  0x021C09F8  thumb  ov217
 *   func_021C09C8 0x021C09C8 thumb ov217
 *   func_021C09CC 0x021C09CC thumb ov217
 *   func_0201D83C  0x0201D83C  thumb
 *   d_021C2ED8  0x021C2ED8  data  a4
 *   func_02045C04  0x02045C04  arm
 *   d_021C2EE0  0x021C2EE0  data  a4
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02045088 0x02045088 arm
 *   d_021C2EEC 0x021C2EEC data a4
 *   d_021C2F78 0x021C2F78 data a4
 *   d_021C2F18 0x021C2F18 data a4
 *   d_021C2F38 0x021C2F38 data a4
 *   d_021C2F58 0x021C2F58 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_021C0EF4 0x021C0EF4 thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C2F98 0x021C2F98 data a4
 *   func_021C0F48  0x021C0F48  thumb  ov217
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   d_021C2ED2  0x021C2ED2  data  a4
 *   d_021C2ED0  0x021C2ED0  data  a4
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021C2EFC 0x021C2EFC data a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *   d_021C2FF8  0x021C2FF8  data  a4
 */
#include "../../matched/include/Obj00511.h"
#include "../../matched/include/Obj25821.h"
#include "../../matched/include/Obj25823.h"
#include "../../matched/include/Obj25824.h"
#include "../../matched/include/Obj25825.h"
#include "../../matched/include/Obj25826.h"
#include "../../matched/include/Obj03376.h"
#include "../../matched/include/Obj25827.h"
#include "../../matched/include/Obj25828.h"
#include "../../matched/include/Obj14725.h"
#include "../../matched/include/Obj25829.h"
#include "../../matched/include/Obj25830.h"
#include "../../matched/include/Obj25832.h"
#include "../../matched/include/Obj14726.h"
#include "../../matched/include/Obj25834.h"
#include "../../matched/include/Obj14727.h"
#include "../../matched/include/Obj14728.h"
#include "../../matched/include/Obj14729.h"
#include "../../matched/include/Obj10954.h"
#include "../../matched/include/Obj10955.h"
#include "../../matched/include/Obj25835.h"
#include "../../matched/include/Obj25837.h"
#include "../../matched/include/Obj01785.h"
#include "../../matched/include/Obj25838.h"

struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct DispConfig;
struct BgTemplate;
struct ArcFile;
struct Config;
struct Record;
struct Bank;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

typedef struct {
    u32 w[5];
    u32 a;
} Rec;

struct Desc {u8 a,b,c,d,e,f,g,h,i,j,k;unsigned data;};

struct Entry_021BA86C {struct Desc desc;unsigned mode,data;};

struct Context {void *owner;u16 heap,pad6;char gap8[0x54];int slots[6];};

struct Vec {short x,y,z;unsigned char a,b;};

struct Entry_021BAA48 {struct Vec vec;unsigned first,second,third,fourth;u16 arg,pad;};

struct Ent { u32 a; u32 b; u8 c; u8 pad[11]; };

extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern void func_021C2A00(u32 a0);
extern void func_021C29F0(int);
extern unsigned func_021C09B4(void *);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned func_020142E8(void *,int);
extern u32 func_021C09F8(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern unsigned func_021C09C8(void *);
extern unsigned func_021C09CC(void *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern int func_021C0E08(int a0, int a1);
extern void func_021C0E3C(void *p);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(unsigned,const struct BgTemplate *,unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);
extern void func_02045088(u16);
extern u32 func_020403F4();
extern void func_020450C8(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *,unsigned,unsigned);
extern int func_02062B30(void *,void **);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char);
extern void func_020409B4(unsigned);
extern void func_02049238(void *);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_020414EC();
extern void func_02040DA8(u32, u32, u32);
extern struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
extern unsigned func_021C0F5C(unsigned,unsigned);
extern void func_021C0F48(u8 *p);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204AFD8();
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_021C29C8(u32 a0);
extern u32 func_021C29D8(void *a0);
extern void func_021C29E8(void *p, u32 b, u32 c, u32 d);
extern int func_021C2A08(char *p);
void func_021BA388(char *self, int d);
void func_021BA3B0(void *p, u32 v);
u32 func_021BA3B4(u32 a0, u32 a1);
u32 func_021BA3D0(void *p, u32 i);
u32 func_021BA3D8(void *p, u32 i);
u32 func_021BA3E0(void *p, u32 i);
void func_021BA3E8(char *self, int i);
void func_021BA40C(u8 *a0, u32 a1);
void func_021BA41C(int *p);
unsigned char func_021BA434(char *p);
u32 func_021BA4C8(void *p);
void func_021BA4CC(void *p, u32 v);
void func_021BA4D0(void *p, u32 v);
u32 func_021BA4D4(void *p);
u32 func_021BA4E0(u32 a0);
u32 func_021BA4FC(void *a0);
void func_021BA504(char *p);
void func_021BA560(char *p);
void func_021BA5B4(void *p);
void func_021BA5BC(u32 a0);
void func_021BA5D8(u8 *a0);
void func_021BA5E4(void *p);
void func_021BA5F8(char *self);
void func_021BA624(int *p);
void func_021BA63C(u8 *self);
void func_021BA674(void *p);
void func_021BA67C(u32 a0);
void func_021BA68C(Rec *p);
void func_021BA698(char *p);
u32 func_021BA748(void);
void func_021BA768(char *p);
void func_021BA7B4(void);
u32 func_021BA7B8(void *a0);
void func_021BA7D0(u32 a0, u32 a1, u32 a2);
void func_021BA7E0(char *p);
void func_021BA82C(void);
u32 func_021BA830(void *a0);
void func_021BA848(u32 a0, u32 a1, u32 a2);
void func_021BA858(void *p);
void func_021BA86C(char *p);
void func_021BA8E0(int *p);
void func_021BA8FC(void *p);
void func_021BA910(struct Context *p);
u32 func_021BA960(u32 a0);
void func_021BA978(struct Context *p);
u32 func_021BA9D0(u32 a0);
void func_021BA9E8(void *p);
void func_021BA9FC(char *self);
void func_021BAA28(int *p);
void func_021BAA40(void *p);
void func_021BAA48(char *p);
void func_021BAAB8(u8 *a0);
void func_021BAAC4(void *p);
void func_021BAAD8(char *p);
void func_021BAAF4(int *p);
void func_021BAB0C(char *self);
void func_021BAB38(char *self);
extern u8 d_021C3008[];
extern u8 d_021C3004[];
extern u32 d_021C2ED8[];
extern u8 d_021C2EE0[];
extern struct DispConfig d_021C2EEC;
extern const struct BgTemplate d_021C2F78,d_021C2F18,d_021C2F38,d_021C2F58;
extern const struct Entry_021BA86C d_021C2F98[];
extern u16 d_021C2ED2[];
extern u8 d_021C2ED0[];
extern const struct Entry_021BAA48 d_021C2EFC;
extern struct Ent d_021C2FF8[];


void func_021BA388(char *self, int d)
{
    int n = *(int *)&((struct Obj00511 *)self)->f28;
    do {
        n = (n + d + 2) % 2;
    } while (!func_021BA3B4((u32)self, n));
    *(int *)&((struct Obj00511 *)self)->f28 = n;
}


/*
 * Field setter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA3B0(void *p, u32 v)
{
    ((struct Obj25821 *)p)->f28 = v;
}

u32 func_021BA3B4(u32 a0, u32 a1)
{
    if (a1 == 0) {
    if (func_021BA434((char *)a0) > 1) {
    return 1;
    }
    return 0;
    }
    return 1;
}


/*
 * Indexed u32 read: element i of the table at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3D0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x5c);
}


/*
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3D8(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x74);
}


/*
 * Indexed u32 read: element i of the table at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3E0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x7c);
}


void func_021BA3E8(char *self, int i)
{
    func_021C29F8(*(void **)(self + i * 4 + 0x38),
                  *(u32 *)(d_021C3004 + i * 0x14),
                  *(u16 *)(d_021C3008 + i * 0x14));
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 56)), (a1)*4 to func_021C2A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA40C(u8 *a0, u32 a1)
{
    func_021C2A00((u32)(*(u32*)(a0 + (a1)*4 + 56)));
}


void func_021BA41C(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        func_021C29F0(p[i + 0x0E]);
}

/*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 */
unsigned char func_021BA434(char *p)
{
    void *bitmap=(void *)func_0201296C((const struct BigObj *)func_021C09B4(((struct Obj25823 *)p)->f0));
    int count=1;
    if(func_020142E8(bitmap,240)==1)count++;
    if(func_020142E8(bitmap,241)==1)count++;
    if(func_020142E8(bitmap,242)==1)count++;
    if(func_020142E8(bitmap,243)==1)count++;
    if(func_020142E8(bitmap,244)==1)count++;
    if(func_020142E8(bitmap,245)==1)count++;
    if(func_020142E8(bitmap,246)==1)count++;
    if(func_020142E8(bitmap,247)==1)count++;
    if(func_020142E8(bitmap,248)==1)count++;
    return count;
}


u32 func_021BA4C8(void *p)
{
    return ((struct Obj25824 *)p)->f0;
}


void func_021BA4CC(void *p, u32 v)
{
    ((struct Obj25825 *)p)->f0 = v;
}


/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA4D0(void *p, u32 v)
{
    ((struct Obj25826 *)p)->f4 = v;
}

u32 func_021BA4D4(void *p)
{
    return func_021C09F8((void *)func_021BA4C8(p));
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA4E0(u32 a0)
{
    return (u32)func_02030734(a0, 144, 0, (const char *)0x21C3FEC, 1486);
}


u32 func_021BA4FC(void *a0)
{
    return func_020307B0(a0);
}

/*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 */
void func_021BA504(char *p)
{
    ((struct Obj03376 *)p)->f80=0;((struct Obj03376 *)p)->f84=0;((struct Obj03376 *)p)->f88=0;
    ((struct Obj03376 *)p)->f18=0;((struct Obj03376 *)p)->f20=0;((struct Obj03376 *)p)->f24=0;
    ((struct Obj03376 *)p)->f28=0;((struct Obj03376 *)p)->f8C=2;((struct Obj03376 *)p)->f1C=0;
    func_021BA8FC(p);func_021BA674(p);func_021BA5E4(p);func_021BA5B4(p);
    func_021BA858(p);func_021BA9E8(p);func_021BAA40(p);func_021BAAC4(p);
}

void func_021BA560(char *p)
{
    void *owner=((struct Obj25827 *)p)->f0;
    unsigned a=func_021C09C8(owner),b=func_021C09CC(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        func_021BA3B0(p,mode);
    } else {
        if(func_021BA3B4((unsigned)p,0)!=0) func_021BA3B0(p,0);
        else func_021BA3B0(p,1);
    }
}


void func_021BA5B4(void *p)
{
    ((struct Obj25828 *)p)->f8 = 0;
}

void func_021BA5BC(u32 a0)
{
    u8 s[4];
    ((struct Obj14725 *)(((u8*)a0)))->f8 = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct Obj14725 *)(((u8*)a0)))->f4));
}


void func_021BA5D8(u8 *a0)
{
    func_0201D83C((void *)((u32)(((struct Obj25829 *)a0)->f8)));
}


/*
 * Clear two u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA5E4(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}


void func_021BA5F8(char *self)
{
    int i = 0;
    do {
        int o = i * 4;
        *(u32 *)(self + o + 0xc) = (u32)func_02045B38((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + o)), (u16)(((struct Obj25830 *)self)->f4));
        i++;
    } while (i < 2);
}


void func_021BA624(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_02045C04((struct Rec *)p[i + 3]);
}


void func_021BA63C(u8 *self)
{
    int i = 0;
    do {
        int o = i * 4;
        u8 *t = d_021C2EE0 + o;
        self[o + 0x2e] = t[0];
        self[o + 0x2f] = t[1];
        self[o + 0x2c] = t[2];
        self[o + 0x2d] = t[3];
        i++;
    } while (i < 3);
}


void func_021BA674(void *p)
{
    ((struct Obj25832 *)p)->f14 = 0;
}

void func_021BA67C(u32 a0)
{
    ((struct Obj14726 *)(((u8*)a0 + 0)))->f14 = func_021C0E08(10, ((struct Obj14726 *)(((u8*)a0 + 0)))->f4);
}


void func_021BA68C(Rec *p)
{
    func_021C0E3C((void *)p->a);
}

void func_021BA698(char *p)
{
    func_0203FC28(&d_021C2EEC);
    func_0203FCA0(6,&d_021C2F78,0);func_0203FCA0(7,&d_021C2F18,0);
    func_0203FCA0(2,&d_021C2F38,0);func_0203FCA0(3,&d_021C2F58,0);
    func_02040588(4,1);func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040588(1,1);func_02040588(2,1);func_02040588(3,1);
    func_0207D63C((volatile unsigned *)0x04001050,2,1,7,15);
    func_0207D63C((volatile unsigned *)0x04000050,4,2,16,5);
    func_02045088(((struct Obj25834 *)p)->f4);
}

u32 func_021BA748(void)
{
    func_020450C8();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(7);
    return func_020403F4(6);
}

void func_021BA768(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct Obj14727 *)p)->f4);
    void *file=func_02049250(arc,13,((struct Obj14727 *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(6,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(6);func_020307B0(file);func_02049238(arc);
}


void func_021BA7B4(void)
{
}

u32 func_021BA7B8(void *a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}


void func_021BA7D0(u32 a0, u32 a1, u32 a2)
{
    func_02040DA8(7, 1, 0);
}

void func_021BA7E0(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct Obj14728 *)p)->f4);
    void *file=func_02049250(arc,4,((struct Obj14728 *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(2,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(2);func_020307B0(file);func_02049238(arc);
}


void func_021BA82C(void)
{
}

u32 func_021BA830(void *a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}


void func_021BA848(u32 a0, u32 a1, u32 a2)
{
    func_02040DA8(3, 1, 0);
}


void func_021BA858(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x4c) = 0;
}

void func_021BA86C(char *p)
{
    struct Desc desc;
    int i;
    for(i=0;i<4;i++) {
        const struct Entry_021BA86C *s=&d_021C2F98[i];
        desc.a=s->desc.a;desc.b=s->desc.b;desc.c=s->desc.c;desc.d=s->desc.d;
        desc.e=s->desc.e;desc.f=s->desc.f;desc.g=s->desc.g;desc.h=s->desc.h;
        desc.i=s->desc.i;desc.j=s->desc.j;desc.k=s->desc.k;desc.data=s->data;
        *(unsigned *)(p+i*4+0x4c)=(unsigned int)func_021C0EF4((const struct Config *)(&desc),((struct Obj14729 *)p)->f8,*(unsigned *)(p+s->desc.data*4+0xc),((struct Obj14729 *)p)->f4);
        func_021C0F5C(*(unsigned *)(p+i*4+0x4c),s->mode);
    }
}


void func_021BA8E0(int *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_021C0F48((u8 *)p[i + 0x13]);
        p[i + 0x13] = 0;
    }
}


/*
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA8FC(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x5c) = 0;
}

/*
 * trailing: 021BA95E..021BA960 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * ABF0 forwards AC18's returned r0; caller stores it at +0x6c.
 */
void func_021BA910(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=func_0204A6C8((void *)((unsigned)arc),15,0,1,heap);
    int b=func_0204ABF0((void *)arc,16,1,0,heap);
    int c=func_0204AF28((void *)((unsigned)arc),14,17,heap);
    p->slots[3]=a;p->slots[4]=b;p->slots[5]=c;
    func_02049238(arc);
}

u32 func_021BA960(u32 a0)
{
    func_0204A8D4(((struct Obj10954 *)(((u8*)a0)))->f68);
    func_0204ADA4(((struct Obj10954 *)(((u8*)a0)))->f6C);
    return func_0204AFD8(((struct Obj10954 *)(((u8*)a0)))->f70);
}

void func_021BA978(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=func_0204A6C8((void *)((unsigned)arc),15,0,0,heap);
    int b=func_0204AC18((void *)((unsigned)arc),16,0,192,0,4,heap);
    int c=func_0204AF28((void *)((unsigned)arc),14,17,heap);
    p->slots[0]=a;p->slots[1]=b;p->slots[2]=c;
    func_02049238(arc);
}

u32 func_021BA9D0(u32 a0)
{
    func_0204A8D4(((struct Obj10955 *)(((u8*)a0)))->f5C);
    func_0204ADA4(((struct Obj10955 *)(((u8*)a0)))->f60);
    return func_0204AFD8(((struct Obj10955 *)(((u8*)a0)))->f64);
}


void func_021BA9E8(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x74) = 0;
}


void func_021BA9FC(char *self)
{
    int i = 0;
    do {
        *(u32 *)(self + i * 4 + 0x74) = (u32)func_0204B100(d_021C2ED2[i], d_021C2ED0[i], ((struct Obj25835 *)self)->f4);
        i++;
    } while (i < 2);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BAA28(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_0204B1CC((struct Bank *)p[i + 0x1D]);
}


/*
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAA40(void *p)
{
    ((struct Obj25837 *)p)->f7C = 0;
}

/*
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
void func_021BAA48(char *p)
{
    struct Vec vec;
    unsigned first,second,third,fourth;
    vec.x=d_021C2EFC.vec.x;vec.y=d_021C2EFC.vec.y;vec.z=d_021C2EFC.vec.z;
    vec.a=d_021C2EFC.vec.a;vec.b=d_021C2EFC.vec.b;
    first=func_021BA3D8(p,d_021C2EFC.first);
    second=func_021BA3D0(p,d_021C2EFC.second);
    third=func_021BA3D0(p,d_021C2EFC.third);
    fourth=func_021BA3D0(p,d_021C2EFC.fourth);
    *(unsigned *)&((struct Obj01785 *)p)->f7C=(unsigned)func_0204B294((void *)first,second,third,fourth,&vec,d_021C2EFC.arg,((struct Obj01785 *)p)->f4);
    func_0204B3DC(*(struct Obj * *)&((struct Obj01785 *)p)->f7C,0);
}


void func_021BAAB8(u8 *a0)
{
    func_0204B3B4((struct Obj *)((u32)(((struct Obj25838 *)a0)->f7C)));
}


/*
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAAC4(void *p)
{
    int i;
    for (i = 0; i < 5; i++)
        *(u32 *)((char *)p + i * 4 + 0x38) = 0;
}


void func_021BAAD8(char *p)
{
    int i;
    for (i = 0; i < 5; i++)
        ((int *)(p + 0x38))[i] = func_021C29C8(((struct Obj01785 *)p)->f4);
}


void func_021BAAF4(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        func_021C29D8((void *)p[i + 0x0E]);
}


void func_021BAB0C(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_021C29E8((void *)(*(int *)(self + i * 4 + 0x38)), d_021C2FF8[i].a, d_021C2FF8[i].b, d_021C2FF8[i].c);
    }
}


void func_021BAB38(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_021C2A08((char *)(*(int *)(self + i * 4 + 0x38)));
    }
}
