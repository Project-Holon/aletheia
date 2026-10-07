/*
 * file:     gsync_state_p03.c
 * unit:     yes
 * function: func_021D4FAC, func_021D4FB8, func_021D4FEC, func_021D5020, func_021D504C, func_021D50F8, func_021D5120, func_021D5128, func_021D5320, func_021D53D0, func_021D54E0, func_021D54F4, func_021D562C, func_021D5644, func_021D56FC
 * address:  0x021D4FAC
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4EF0 0x021D4EF0 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_02041570 0x02041570 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021D4E64 0x021D4E64 thumb ov123
 *   func_021D4440 0x021D4440 thumb ov123
 *   func_021D4E7C 0x021D4E7C thumb ov123
 *   func_02012DAC 0x02012DAC thumb
 *   func_020414EC 0x020414EC arm
 *   func_021D4384 0x021D4384 thumb ov123
 *   func_021D4AFC 0x021D4AFC thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 *   func_021D4DA4 0x021D4DA4 thumb ov123
 *   func_0204A648 0x0204A648 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D534 0x0207D534 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020355D8 0x020355D8 arm
 *   func_021D424C 0x021D424C thumb ov123
 *   func_021D4884 0x021D4884 thumb ov123
 *   d_021DA9F0 0x021DA9F0 data a4
 *   d_021DA680 0x021DA680 data a4
 *   d_021DA658 0x021DA658 data a4
 *   d_021DAA20 0x021DAA20 data a1
 *   func_02012204 0x02012204 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02040618 0x02040618 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021D4A64 0x021D4A64 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021DAA30 0x021DAA30 data a1
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D584C 0x021D584C thumb ov123
 *   func_0203FB44 0x0203FB44 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj00273.h"
#include "../../matched/include/Obj22939.h"
#include "../../matched/include/Obj00590.h"
#include "../../matched/include/Obj06459.h"
#include "../../matched/include/Obj01733.h"
#include "../../matched/include/Obj00772.h"
#include "../../matched/include/Obj22940.h"
#include "../../matched/include/Obj10436.h"
#include "../../matched/include/Obj00499.h"
#include "../../matched/include/Obj13971.h"
#include "../../matched/include/Obj01154.h"
#include "../../matched/include/Obj01933.h"

struct MsgBank;
struct Big;
struct Sub020071E4Ctrl;
struct TaskMenu;
struct Obj0203159C;
struct Bank;
struct R;
struct Tcbl;
struct DispConfig;
struct DispVram;
struct Cfg;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Descriptor;
struct Node;
struct Obj;
struct Rec3;
struct S02031140;
struct S020315D4;
struct TaskMenuState;
struct GfFont;
struct U16Vec;
struct WordSet;
struct Rec;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Config { u32 words[4]; };

typedef signed int     s32;

extern void func_021D4EF0(char *,int,int);
extern void func_021D4D40(char *,int);
extern void func_02041570(int channel, u16 val);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D4244(char *,void *,int);
extern int func_02012DD0(u8 *p);
extern void func_021D4E64(u8 *p);
extern void func_021D4440(void *);
extern int func_021D4E7C(char *);
extern int func_02012DAC(int a0);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void *func_02012EBC(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void func_020414EC(u32 i);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D4384(u8 *p);
extern void func_021D4AFC(char *);
extern void func_021D4A04(char *);
extern void func_021D4DA4(char *);
extern void func_0204A648(void);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u8,u32);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020056A0(void *,void *,int);
extern void func_021D424C(char *);
extern void func_021D4884(char *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u32);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_0203D34C(u32,u32);
extern void func_020355D8(u8 v);
extern void func_02027974(void *);
extern int func_0203CD98(void);
extern u32 func_0201058C(void *key);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A600(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_020221A4(void);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(unsigned int,unsigned int);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_021D4A64(char *);
extern u32 func_020307B0(void *p);
extern int func_02028604(int a0);
extern void func_020403F4(u32 i);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_02051C6C(void *);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_021D584C(char *);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201DD68(void);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern signed char func_02012FFC(void);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D4FAC(char *p);
void func_021D4FB8(char *p);
void func_021D4FEC(char *p);
void func_021D5020(char *p);
void func_021D504C(char *p);
void func_021D50F8(char *p);
void func_021D5120(void);
int func_021D5128(void *a,int b,u8 *q);
int func_021D5320(int a,int b,int c,char *p);
int func_021D53D0(void *a,int b,u8 *out,char *p);
void func_021D54E0(u8 *p);
u8 *func_021D54F4(u32 heap,u32 bank);
void func_021D562C(char *p);
void func_021D5644(char *p);
void func_021D56FC(char *p,int mode);
extern const struct Config d_021DA680;
extern const u32 d_021DA9F0[], d_021DA658[];
extern const char d_021DAA20[];
extern const char d_021DAA30[];

void func_021D4FAC(char *p) { func_021D4EF0(p,4,1); }

/*
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
void func_021D4FB8(char *p) { func_021D4D40(p,1); func_02041570(5,0); func_02045CAC(*(void **)(p+36),3,*(void **)(p+56)); func_021D4FAC(p); func_021D4244(p,func_021D50F8,0x4d0); }

void func_021D4FEC(char *p) { if(func_02012DD0(((struct Obj00273 *)p)->f260)==2) { func_021D4E64((u8 *)p); func_021D4D40(p,0); func_021D4244(p,func_021D4440,0x4ea); } }

void func_021D5020(char *p) { if(func_021D4E7C(p)) { func_02012DAC((int)(((struct Obj22939 *)p)->f260)); func_021D4244(p,func_021D4FEC,0x4fa); } }

void func_021D504C(char *p)
{
    if (func_020279E8(((struct Obj00273 *)p)->f238)) {
        if (!func_02027A04(((struct Obj00273 *)p)->f238)) {
            if (func_020071F0(func_02012EBC(((struct Obj00273 *)p)->f260))) {
                func_02045CAC(((struct Obj00273 *)p)->f24,46,((struct Obj00273 *)p)->f38);
                func_021D4FAC(p);
                func_021D4244(p,func_021D4AFC,0x50d);
            } else {
                func_02045CAC(((struct Obj00273 *)p)->f24,6,((struct Obj00273 *)p)->f38);
                func_021D4EF0(p,4,0);
                func_021D4384((u8 *)p);
                func_021D4244(p,func_021D5020,0x519);
            }
        } else {
            func_020414EC(5);
            ((struct Obj00273 *)p)->f8=0;
            func_021D4244(p,func_021D4A04,0x51f);
            func_021D4D40(p,0);
        }
        func_02027858(((struct Obj00273 *)p)->f238);
        ((struct Obj00273 *)p)->f238=0;
    }
}

void func_021D50F8(char *p){if(func_021D4E7C(p)){func_021D4DA4(p);func_021D4244(p,func_021D504C,0x536);}}

/*
 * evidence: root claimed this sole blocker of 021D5128; target's matched
 * definition and original body read no incoming argument registers.
 */
void func_021D5120(void)
{
    func_0204A648();
}

/*
 * evidence: sole callback blocker ov123 021D5120 filed and verified before
 * caller recheck; ABS32 at +01E0 now resolves through its matched shard.
 * volatile: display register 04001000 read/write at 021D5198/021D519C.
 * interface: 0203159C leaves its allocation result in r0, which is used
 * throughout this caller; its legacy matched definition is void.
 */
int func_021D5128(void *a,int b,u8 *q)
{
    char *p;
    int bright;
    int color;
    struct Config cfg;
    func_0203064C(1,31,0x18000);
    p=func_0203159C(a,0x2b4,31);
    func_02082BCC(p,0,0x2b4);
    ((struct Obj00590 *)p)->fC=31;
    ((struct Obj00590 *)p)->f260=((struct Obj06459 *)q)->f4; ((struct Obj00590 *)p)->f264=((struct Obj06459 *)q)->f0;
    func_0204363C(1);
    if(((struct Obj06459 *)q)->f2C8) bright=16; else bright=-16;
    func_0207D534((void *)0x0400006c,bright); func_0207D534((void *)0x0400106c,bright);
    *(volatile u32 *)0x04001000|=0x10000; func_0207D46C();
    func_0203F8F4(((struct Obj00590 *)p)->fC); func_02045088(((struct Obj00590 *)p)->fC); func_0201DD60();
    func_020433E0((const struct DispVram *)d_021DA9F0);
    cfg=d_021DA680; func_0203FC28((struct DispConfig *)(&cfg));
    func_02043534(0); func_020435F4(0);
    func_0204A48C((const struct Cfg *)d_021DA658,(u32)d_021DA9F0,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f2AC=func_0204B100(40,0,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f2B0=func_020056A0(func_021D5120,p,0);
    func_021D424C(p); func_021D4884(p);
    ((struct Obj00590 *)p)->f280=func_02030734(((struct Obj00590 *)p)->fC,0x200,0,d_021DAA20,0x5a6);
    ((struct Obj00590 *)p)->f284=func_02030734(((struct Obj00590 *)p)->fC,0x200,0,d_021DAA20,0x5a7);
    ((struct Obj00590 *)p)->f230=func_0203101C(((struct Obj00590 *)p)->fC,((struct Obj00590 *)p)->fC,3,0);
    ((struct Obj00590 *)p)->f22C=func_02028590(15,0,1,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f234=func_0201C440((void *)(u32)((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f254=func_02027F60(5,9,((struct Obj00590 *)p)->f30,((struct Obj00590 *)p)->f234,((struct Obj00590 *)p)->fC);
    func_0207D63C((void *)0x04001050,4,1,15,4);
    color=0; if(((struct Obj06459 *)q)->f2C8) color=0x7fff;
    func_0202208C(0,1,1,(u16)color,6,1,((struct Obj00590 *)p)->fC);
    *(u32 *)&((struct Obj06459 *)q)->f2C8=0; func_020435F4(31);
    func_021D4244(p,func_021D4A04,0x5bf);
    ((struct Obj00590 *)p)->f258=q;
    func_0203D34C(0,((struct Obj00590 *)p)->fC); func_020355D8(1);
    return 1;
}

/*
 * extent: two bytes zero alignment padding follow the return.
 */
int func_021D5320(int a,int b,int c,char *p)
{
    int result=1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result=0;
    }
    if (((struct Obj01733 *)p)->f238) func_02027974(((struct Obj01733 *)p)->f238);
    if (func_0203CD98()) {
        ((struct Obj01733 *)p)->f27C=((struct Obj01733 *)p)->f278;
        ((struct Obj01733 *)p)->f278=func_0201058C(0);
    }
    func_020310C4(((struct Obj01733 *)p)->f230);
    func_0201C4E4(((struct Obj01733 *)p)->f234);
    func_02040618(4,3,((struct Obj01733 *)p)->f268);
    --((struct Obj01733 *)p)->f268;
    func_0204A600();
    if (!((struct Obj01733 *)p)->f28C) func_020121CC(((struct Obj01733 *)p)->f264);
    if (func_020221A4() && func_02012204(((struct Obj01733 *)p)->f264)) {
        ((struct Obj01733 *)p)->f8=0;
        result=1;
        func_0202223C(0,0);
        func_0202223C(1,0);
    }
    return result;
}

/*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 */
int func_021D53D0(void *a,int b,u8 *out,char *p)
{
    int i;
    if(!func_020221A4()) return 0;
    for(i=0;i<3;i++) func_0204B3B4(*(void **)(p+i*4+0x2a0));
    func_0204ADA4((u32)(((struct Obj00772 *)p)->f290));
    func_0204A8D4((u32)(((struct Obj00772 *)p)->f294));
    func_0204AFD8((u32)(((struct Obj00772 *)p)->f298));
    func_02030EAC(((struct Obj00772 *)p)->f2B0);
    func_0204B1CC(((struct Obj00772 *)p)->f2AC); func_0204A5AC();
    if(((struct Obj00772 *)p)->f288) { func_0202F038(((struct Obj00772 *)p)->f288); ((struct Obj00772 *)p)->f288=0; }
    if(((struct Obj00772 *)p)->f228) func_0201CE48(((struct Obj00772 *)p)->f228);
    if(((struct Obj00772 *)p)->f238) { func_02027858(((struct Obj00772 *)p)->f238); ((struct Obj00772 *)p)->f238=0; }
    func_021D4A64(p);
    ((struct Obj22940 *)out)->f1C8=((struct Obj00772 *)p)->f8;
    func_020307B0(((struct Obj00772 *)p)->f280); func_020307B0(((struct Obj00772 *)p)->f284);
    func_02028604((int)(((struct Obj00772 *)p)->f22C)); func_020403F4(5);
    func_0201C6EC(((struct Obj00772 *)p)->f234); func_0201C4C0(((struct Obj00772 *)p)->f234);
    if(((struct Obj00772 *)p)->f224) func_020452E8(((struct Obj00772 *)p)->f224);
    func_02031140(((struct Obj00772 *)p)->f230); func_02027FD8(((struct Obj00772 *)p)->f254);
    func_020450C8(); func_0203F9B4(); func_020315D4(a); func_020306F0(31);
    return 1;
}


void func_021D54E0(u8 *p)
{
    if (((struct Obj10436 *)p)->f1C) {
        func_02051C6C(((struct Obj10436 *)p)->f1C);
        *(u32 *)&((struct Obj10436 *)p)->f1C = 0;
    }
}

u8 *func_021D54F4(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DAA30,0x96);
    ((struct Obj00499 *)p)->fB0=heap;
    ((struct Obj00499 *)p)->f24=func_0201EC64(((struct Obj00499 *)p)->fB0);
    func_02045088(((struct Obj00499 *)p)->fB0); func_0201DD60();
    ((struct Obj00499 *)p)->f84=func_0203101C(((struct Obj00499 *)p)->fB0,((struct Obj00499 *)p)->fB0,2,0);
    ((struct Obj00499 *)p)->f88=func_0201C440((void *)(u32)((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f2C=func_020457B0(400,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f30=func_020457B0(400,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f28=func_0201D7EC(23,0,0,0,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f20=func_02045B38(0,2,(u16)bank,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f40=func_02028590(15,1,1,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->fA4=func_02027F60(5,9,*(u32 *)&((struct Obj00499 *)p)->f28,((struct Obj00499 *)p)->f88,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f8=func_0201F5DC((void *)5,12,0,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f4=func_0201F5DC((void *)6,12,0,((struct Obj00499 *)p)->fB0);
    func_02049B40(23,5,4,352,32,((struct Obj00499 *)p)->fB0);
    func_02049B40(23,5,0,352,32,((struct Obj00499 *)p)->fB0);
    return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D562C(char *p)
{
    func_020310C4(((struct Obj13971 *)p)->f84);
    func_0201C4E4(((struct Obj13971 *)p)->f88);
}

/*
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 */
void func_021D5644(char *p)
{
    int i;
    u32 a;
    func_021D584C(p);
    if (((struct Obj01154 *)p)->f44) func_020452E8(((struct Obj01154 *)p)->f44);
    if (((struct Obj01154 *)p)->f48) func_020452E8(((struct Obj01154 *)p)->f48);
    for(i=0;i<12;i++) {
        if (*(void **)(p+0x4c+i*4)) func_020452E8(*(void **)(p+0x4c+i*4));
    }
    a=((struct Obj01154 *)p)->f8>>16;
    func_0203FB44((int)5,(u16)(((struct Obj01154 *)p)->f8),(u16)a);
    a=((struct Obj01154 *)p)->f4>>16;
    func_0203FB44((int)6,(u16)(((struct Obj01154 *)p)->f4),(u16)a);
    func_021D54E0((u8 *)p);
    func_02028604((int)(((struct Obj01154 *)p)->f40));
    func_0201ED04(((struct Obj01154 *)p)->f24);
    func_0201DD68();
    func_02045C04(((struct Obj01154 *)p)->f20);
    func_0201D83C(((struct Obj01154 *)p)->f28);
    func_02045808(((struct Obj01154 *)p)->f2C);
    func_02045808(((struct Obj01154 *)p)->f30);
    func_02027FD8(((struct Obj01154 *)p)->fA4);
    func_0201C6EC(((struct Obj01154 *)p)->f88);
    func_0201C4C0(((struct Obj01154 *)p)->f88);
    func_02031140(((struct Obj01154 *)p)->f84);
    func_020450C8();
    func_020307B0(p);
}

void func_021D56FC(char *p,int mode)
{
    void *q;
    if (!((struct Obj01933 *)p)->f44) ((struct Obj01933 *)p)->f44=(void *)func_020450F0((int)5,(int)1,(u8)1,(int)30,4,11,1);
    q=((struct Obj01933 *)p)->f44;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    if (mode) {
        func_0201C7A4(func_02045770(q),0,0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28);
    } else {
        ((struct Obj01933 *)p)->f80=func_0201CCE4(q,(int)0,(int)0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28,(int)func_02012FFC(),((struct Obj01933 *)p)->f84,(int)2,((struct Obj01933 *)p)->fB0,15);
        func_02028470((u8 *)(p+0xa8),(int)6);
    }
    func_0201F73C(q,1,(u16)(((struct Obj01933 *)p)->f8),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}
