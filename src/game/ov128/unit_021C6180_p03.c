/*
 * file:     unit_021C6180_p03.c
 * unit:     yes
 * function: func_021C66A8, func_021C6790, func_021C67A8, func_021C68C4, func_021C692C, func_021C6980
 * address:  0x021C66A8
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040B94 0x02040B94 arm
 *   func_0204152C 0x0204152C arm
 *   func_02040588 0x02040588 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   d_021CA664 0x021CA664 data a4
 *   d_021CA718 0x021CA718 data a4
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02049238 0x02049238 arm
 *   d_020A1448 0x020A1448 data a4
 *   d_021CA5CC 0x021CA5CC data a4
 *   d_021CA7D0 0x021CA7D0 data a4
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 */
#include "../../matched/include/Obj04504.h"
#include "../../matched/include/Obj01936.h"
#include "../../matched/include/Obj00725.h"
#include "../../matched/include/Obj05377.h"

struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {u32 a,b,c,d;} DispConfig;

typedef signed int     s32;

typedef struct {u32 a,b;u8 c,d,e,f;u32 g;u16 h[6];} Config;

typedef signed short s16;

extern void func_0203F8F4(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040B94(u8,u32,u32,u32);
extern void func_0204152C(int channel, u16 val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B68(void *,u32,u32,u32,u32,u32);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u32);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u32);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern int func_0204A6C8(void *,u32,u32,u32,u32);
extern int func_0204ABF0(void *,u32,u32,u32,u32);
extern int func_0204AF28(void *,u32,u32,u32);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32,u32);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_02049238(void *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B084(u32);
extern void func_0204A5AC(void);
extern void func_0201DD68(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0203101C(unsigned,unsigned,unsigned,unsigned);
extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
void func_021C66A8(char *p,int heap);
void func_021C6790(u8 *a0);
void func_021C67A8(char *p,int heap);
void func_021C68C4(char *p);
void func_021C692C(u8 *p, int heap);
void func_021C6980(u8 *p);
extern const DispConfig d_021CA664;
extern const u8 d_021CA718[][32];
extern const Config d_020A1448;
extern u8 d_021CA5CC[],d_021CA7D0[];

void func_021C66A8(char *p,int heap)
{
    DispConfig config;
    int i;
    func_0203F8F4(heap);
    config=d_021CA664;
    func_0203FC28((struct DispConfig *)(&config));
    for(i=0;i<5;i++) {
        func_0203FCA0((u8)i,(const struct BgTemplate *)d_021CA718[i],0);
        func_02040B94(i,32,0,heap);
        func_0204152C((u8)i,0);
        func_02040588(i,1);
    }
    func_02049B68(((struct Obj04504 *)p)->f8,0,0,0,192,heap);
    func_02049B68(((struct Obj04504 *)p)->f8,0,4,0,192,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,0,0,0,0,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,2,0,0,0,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,4,0,0,0,heap);
    func_020498F4(((struct Obj04504 *)p)->f8,5,0,0,0,0,heap);
    func_020498F4(((struct Obj04504 *)p)->f8,14,4,0,0,0,heap);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C6790(u8 *a0)
{
    int i;
    for (i = 0; i < 5; i++)
        func_020403F4((u8)i);
    func_0203F9B4();
}

void func_021C67A8(char *p,int heap)
{
    Config config=d_020A1448;
    void *bank,*archive;
    u32 first,second;
    config.c=16;
    config.d=112;
    func_0204A48C((const struct Cfg *)(&config),(u32)d_021CA5CC,heap);
    bank=func_0204B100(32,0,heap);
    ((struct Obj01936 *)p)->f138=bank;
    func_0204B270(bank);
    ((struct Obj01936 *)p)->f140=func_0204B034(d_021CA7D0,1,heap);
    bank=func_0204B100(18,1,heap);
    ((struct Obj01936 *)p)->f13C=bank;
    func_0204B258(bank,((struct Obj01936 *)p)->f140);
    ((struct Obj01936 *)p)->f144=func_0204A6C8(((struct Obj01936 *)p)->f8,4,0,0,heap);
    ((struct Obj01936 *)p)->f14C=func_0204ABF0(((struct Obj01936 *)p)->f8,1,0,0,heap);
    ((struct Obj01936 *)p)->f154=func_0204AF28(((struct Obj01936 *)p)->f8,15,16,heap);
    archive=func_020490F4(func_020275E4(),heap);
    ((struct Obj01936 *)p)->f148=func_0204A6C8(archive,func_02027618(),0,0,heap);
    ((struct Obj01936 *)p)->f150=func_0204ABF0(archive,func_02027614(),0,96,heap);
    first=func_0202761C(2);
    second=func_02027620(2);
    ((struct Obj01936 *)p)->f158=func_0204AF28(archive,first,second,heap);
    func_02049238(archive);
}

void func_021C68C4(char *p)
{
    unsigned i;
    for(i=0;i<2;i++) func_0204A8D4(*(u32 *)(p+i*4+0x144));
    for(i=0;i<2;i++) func_0204ADA4(*(u32 *)(p+i*4+0x14c));
    for(i=0;i<2;i++) func_0204AFD8(*(u32 *)(p+i*4+0x154));
    func_0204B1CC((struct Bank *)(((struct Obj00725 *)p)->f13C));
    func_0204B084(((struct Obj00725 *)p)->f140);
    func_0204B1CC((struct Bank *)(((struct Obj00725 *)p)->f138));
    func_0204A5AC();
}

void func_021C692C(u8 *p, int heap)
{
    func_0201DD68();
    ((struct Obj05377 *)p)->f0=func_0201EC64(heap);
    ((struct Obj05377 *)p)->f4=func_02045B38(0,2,211,heap);
    ((struct Obj05377 *)p)->f17C=func_0201D7EC(23,0,0,0,heap);
    ((struct Obj05377 *)p)->f28=func_0203101C(heap,heap,3,256);
    ((struct Obj05377 *)p)->f2C=0;
    ((struct Obj05377 *)p)->f34=(void *)func_0201C440((void *)heap);
}

void func_021C6980(u8 *p)
{
    func_0201C6EC(((struct Obj00725 *)p)->f34);
    func_0201C4C0(((struct Obj00725 *)p)->f34);
    ((struct Obj00725 *)p)->f34=0;
    if (((struct Obj00725 *)p)->f2C) {
        func_0201CE48(((struct Obj00725 *)p)->f2C);
        ((struct Obj00725 *)p)->f2C=0;
    }
    func_02031140(((struct Obj00725 *)p)->f28);
    ((struct Obj00725 *)p)->f28=0;
    func_0201D83C(((struct Obj00725 *)p)->f17C);
    func_02045C04(((struct Obj00725 *)p)->f4);
    func_0201ED04(((struct Obj00725 *)p)->f0);
}
