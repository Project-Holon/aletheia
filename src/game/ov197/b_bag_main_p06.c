/*
 * file:     b_bag_main_p06.c
 * unit:     yes
 * function: func_0220C6E8, func_0220C6F8, func_0220C714, func_0220C724, func_0220C834, func_0220C914, func_0220C980, func_0220CAAC, func_0220CBB4, func_0220CBE8, func_0220CC18, func_0220CD50, func_0220CFA4, func_0220CFF0, func_0220D024, func_0220D11C, func_0220D214, func_0220D234, func_0220D254, func_0220D274, func_0220D29C, func_0220D2AC, func_0220D328, func_0220D358, func_0220D370, func_0220D39C, func_0220D3B0, func_0220D464, func_0220D5C0, func_0220D6B8, func_0220D6DC, func_0220D798, func_0220D7D0, func_0220D7F0, func_0220D848, func_0220D884, func_0220D89C, func_0220D8B0, func_0220D8C4, func_0220D914, func_0220D924, func_0220D974, func_0220D98C, func_0220D9A8
 * address:  0x0220C6E8
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02209B30 0x02209B30 thumb
 *   func_02209B60  0x02209B60  thumb  ov094
 *   func_02209C18 0x02209C18 thumb
 *   func_0220C4D4 0x0220C4D4 thumb ov197
 *   func_0204B878 0x0204B878 arm
 *   d_0220E0E0 0x0220E0E0 data a1
 *   func_02030734 0x02030734 arm
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_0200829C 0x0200829C thumb
 *   func_020082B0 0x020082B0 thumb
 *   func_020082B4 0x020082B4 thumb
 *   func_0220B9A4 0x0220B9A4 thumb ov197
 *   func_0220BF40 0x0220BF40 thumb ov197
 *   func_0220B980 0x0220B980 thumb ov197
 *   func_020310C4 0x020310C4 arm
 *   func_0202CD94 0x0202CD94 thumb
 *   d_0220DF40 0x0220DF40 data a4
 *   d_04001050 0x04001050 data a2
 *   func_0207D534 0x0207D534 arm
 *   sub_0203101C 0x0203101C arm
 *   func_0220AF40 0x0220AF40 thumb ov196
 *   func_0220BB78 0x0220BB78 thumb ov197
 *   func_0220BA2C 0x0220BA2C thumb ov197
 *   func_0220B120 0x0220B120 thumb ov197
 *   func_0220B1B0 0x0220B1B0 thumb ov197
 *   func_0220B990 0x0220B990 thumb ov197
 *   func_0220BBE4 0x0220BBE4 thumb ov197
 *   func_0220BD24 0x0220BD24 thumb ov197
 *   func_0220C034 0x0220C034 thumb ov197
 *   func_0220C4EC 0x0220C4EC thumb ov197
 *   func_0220AFDC 0x0220AFDC thumb ov196
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0202173C 0x0202173C thumb
 *   func_0220BB1C 0x0220BB1C thumb ov197
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_0220BF20 0x0220BF20 thumb ov197
 *   func_0220B9D8 0x0220B9D8 thumb ov197
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_020260E0 0x020260E0 thumb
 *   func_0220B520 0x0220B520 thumb ov197
 *   func_0220B584 0x0220B584 thumb ov197
 *   func_0220BBD8 0x0220BBD8 thumb ov197
 *   func_02045CAC 0x02045CAC arm
 *   func_0220B904 0x0220B904 thumb ov197
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020221B8 0x020221B8 thumb
 *   func_0220BD14 0x0220BD14 thumb ov197
 *   func_0220C448 0x0220C448 thumb ov197
 *   func_0220B1A0 0x0220B1A0 thumb ov197
 *   func_02031140 0x02031140 arm
 *   func_0220AF64 0x0220AF64 thumb ov196
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02209C2C 0x02209C2C thumb
 *   func_0203FC6C 0x0203FC6C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02043598 0x02043598 arm
 *   d_0220DEB0 0x0220DEB0 data a4
 *   d_0220DEE0 0x0220DEE0 data a4
 *   d_0220DF20 0x0220DF20 data a4
 *   d_0220DF00 0x0220DF00 data a4
 *   d_0220DEC0 0x0220DEC0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02021640 0x02021640 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045808 0x02045808 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02041570 0x02041570 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_02025D24 0x02025D24 thumb
 *   d_0220DF90 0x0220DF90 data a4
 *   d_0220DF9C 0x0220DF9C data a4
 *   func_02025D14  0x02025D14  thumb
 *   func_0202616C  0x0202616C  thumb
 *   func_0220B000  0x0220B000  thumb  ov196
 */
#include "../../matched/include/Obj25045.h"
#include "../../matched/include/Obj25046.h"
#include "../../matched/include/Obj25047.h"
#include "../../matched/include/Obj00846.h"
#include "../../matched/include/Obj25048.h"
#include "../../matched/include/Obj25049.h"
#include "../../matched/include/Obj25050.h"
#include "../../matched/include/Obj00736.h"
#include "../../matched/include/Obj25051.h"
#include "../../matched/include/Obj25052.h"
#include "../../matched/include/Obj25053.h"
#include "../../matched/include/Obj25054.h"
#include "../../matched/include/Obj25055.h"
#include "../../matched/include/Obj25057.h"
#include "../../matched/include/Obj25058.h"
#include "../../matched/include/Obj01076.h"
#include "../../matched/include/Obj25059.h"
#include "../../matched/include/Obj25060.h"
#include "../../matched/include/Obj25061.h"
#include "../../matched/include/Obj25062.h"
#include "../../matched/include/Obj25064.h"
#include "../../matched/include/Obj14547.h"
#include "../../matched/include/Obj25065.h"
#include "../../matched/include/Obj10835.h"
#include "../../matched/include/Obj25066.h"
#include "../../matched/include/Obj25067.h"
#include "../../matched/include/Obj25068.h"
#include "../../matched/include/Obj02244.h"
#include "../../matched/include/Obj25069.h"
#include "../../matched/include/Obj25070.h"
#include "../../matched/include/Obj25071.h"
#include "../../matched/include/Obj25072.h"
#include "../../matched/include/Obj00389.h"
#include "../../matched/include/Obj25073.h"
#include "../../matched/include/Obj25074.h"
#include "../../matched/include/Obj25075.h"
#include "../../matched/include/Obj25076.h"
#include "../../matched/include/Obj25077.h"
#include "../../matched/include/Obj25078.h"
#include "../../matched/include/Obj25079.h"
#include "../../matched/include/Obj25080.h"
#include "../../matched/include/Obj00314.h"
#include "../../matched/include/Obj10837.h"
#include "../../matched/include/Obj02245.h"
#include "../../matched/include/Obj25081.h"
#include "../../matched/include/Obj25082.h"
#include "../../matched/include/Obj25083.h"
#include "../../matched/include/Obj25084.h"
#include "../../matched/include/Obj25085.h"
#include "../../matched/include/Obj25086.h"
#include "../../matched/include/Obj14548.h"
#include "../../matched/include/Obj14549.h"
#include "../../matched/include/Obj14550.h"
#include "../../matched/include/Obj10838.h"
#include "../../matched/include/Obj25087.h"
#include "../../matched/include/Obj03346.h"
#include "../../matched/include/Obj25088.h"
#include "../../matched/include/Obj14551.h"
#include "../../matched/include/Obj25089.h"
#include "../../matched/include/Obj25090.h"
#include "../../matched/include/Obj25091.h"
#include "../../matched/include/Obj25092.h"
#include "../../matched/include/Obj25093.h"
#include "../../matched/include/Obj25095.h"
#include "../../matched/include/Obj25097.h"
#include "../../matched/include/Obj00688.h"
#include "../../matched/include/Obj25098.h"
#include "../../matched/include/Obj25099.h"
#include "../../matched/include/Obj25100.h"
#include "../../matched/include/Obj14552.h"
#include "../../matched/include/Obj25101.h"
#include "../../matched/include/Obj25102.h"
#include "../../matched/include/Obj02914.h"
#include "../../matched/include/Obj25103.h"
#include "../../matched/include/Obj25104.h"
#include "../../matched/include/Obj25105.h"
#include "../../matched/include/Obj25106.h"
#include "../../matched/include/Obj25107.h"
#include "../../matched/include/Obj25108.h"
#include "../../matched/include/Obj25109.h"
#include "../../matched/include/Obj03906.h"
#include "../../matched/include/Obj25110.h"
#include "../../matched/include/Obj25111.h"
#include "../../matched/include/Obj25112.h"
#include "../../matched/include/Obj25113.h"
#include "../../matched/include/Obj08356.h"
#include "../../matched/include/Obj25114.h"
#include "../../matched/include/Obj25115.h"
#include "../../matched/include/Obj25116.h"
#include "../../matched/include/Obj25118.h"
#include "../../matched/include/Obj25120.h"
#include "../../matched/include/Obj03347.h"
#include "../../matched/include/Obj25121.h"
#include "../../matched/include/Obj25122.h"
#include "../../matched/include/Obj06649.h"

struct Obj;
struct MyItemSave;
struct Tcbl;
struct WinMgr;
struct Node;
struct PalAnmSlot;
struct PrintSys;
struct Sound;
struct MsgBank;
struct Rec;
struct Rec3;
struct S02031140;
struct WordSet;
struct U16Vec;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_0220C6F8;

typedef signed char    s8;

struct Pair { short x,y; };

typedef signed short   s16_0220C834;

typedef short s16_0220D370;

typedef struct PalAnmObj PalAnmObj;

struct BgVramReq {u32 a,b,c,d;};

struct BgTemplate {u32 a,b,size,c;u8 d,e,f,g;u32 h;u8 i,j,k,l;u32 m;};

typedef signed short s16_0220D884;

typedef signed int s32;

typedef signed short   s16_0220D914;

typedef signed short s16_0220D924;

typedef signed short   s16_0220D98C;

extern void func_02209B30(int);
extern void func_02209B60(u32, u32, u32, u32, u32, u32);
extern void func_02209C18(int);
extern void func_0220C4D4(int,int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_021F86D4(void);
extern int func_021F86E0(void);
extern void *func_02030DA8(void *, u32, void *, u32);
extern void func_0200829C(const struct MyItemSave *p, int i, s16_0220C834 *a, s16_0220C834 *b);
extern u16 func_020082B0(const struct MyItemSave *p);
extern u16 func_020082B4(const struct MyItemSave *p);
extern int func_0220B9A4(char *p);
extern void func_0220BF40(char *);
extern int func_0220B980(char *);
extern void func_020310C4(struct Tcbl *);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *func_0220AF40(u16 v);
extern void func_0220BB78(char *);
extern void func_0220BA2C(u8 *p);
extern void func_0220B120(char *);
extern void func_0220B1B0(char *,int);
extern unsigned func_0220B990(u8 *);
extern void func_0220BBE4(char *),func_0220BD24(char *,int),func_0220C034(char *),func_0220C4EC(char *,int);
extern void func_0220AFDC(char *,void *);
extern void func_0220D8C4(u8 *,unsigned,unsigned),func_0203D34C(unsigned,unsigned);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern int func_0202173C(void *,u16,u16,short,u8,u8,u16,void *);
extern void func_0220BB1C(char *);
extern void func_0220BBE4(char *);
extern void func_0220BD24(char *, int);
extern void func_0220C034(char *);
extern unsigned func_0201C6B4(const struct PrintSys *);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned func_020221A4(void);
extern u32 func_02021ED8(const char *ptr);
extern int func_02025DE8(struct Sound *obj);
extern void func_0220BF20(char *, int);
extern void func_0220B9D8(u8 *p);
extern unsigned func_0220BB98(const char *p, unsigned n);
extern u8 func_020260E0(struct Sound *obj);
extern void func_0220B520(char *);
extern void func_0220B584(char *p);
extern int func_0220BBD8(u32 key);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0220B904(char *);
extern unsigned func_02020FE4(void *, unsigned, unsigned);
extern void func_0201F7A8(void *desc, u32 kind);
extern unsigned func_0201CE30(void *);
extern void func_0201CE5C(struct Rec *, int);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_0201C6EC(struct PrintSys *);
extern void func_020221B8(void);
extern void func_0220BD14(char *);
extern void func_0220C448(char *);
extern void func_0220B1A0(char *);
extern void func_02031140(struct S02031140 *);
extern void func_0220AF64(void *);
extern void func_02030EAC(struct Node *);
extern u32 func_020307B0(void *p);
extern int func_02209C2C(void *);
extern void func_0203FC6C(const struct BgVramReq *,u32);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041B6C(u32);
extern void func_02043598(u32,u32);
extern void func_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049238(void *);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_02021640(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct WordSet *func_0201EC64(unsigned);
extern unsigned func_0201C440(void *);
extern struct U16Vec *func_020457B0(unsigned,unsigned);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C4C0(struct PrintSys *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02041EE4(unsigned int, unsigned int, unsigned int);
extern void func_02041570(int channel, u16 val);
extern void func_020061E4(u32 a);
extern struct Struct_02025CD0 *func_02025CD0(u32, u32, u32, u32, u8, u16);
extern void func_02025D1C(struct Struct_02025D1C *);
extern void func_02025D24(struct Struct_02025D24 *);
extern u32 func_02025D14(void *a0);
extern void *func_0202616C(void **obj, u32 idx);
extern void func_0220B000(int *p, u8 *q);
void func_0220C6E8(char *a);
void func_0220C6F8(u8 *p, u32 a, u32 b);
void func_0220C714(char *a);
void func_0220C724(char *p,u16 slot,u8 a,u8 b,const struct Pair *src);
void func_0220C834(u8 *arg);
void func_0220C914(void *task, char *p);
int func_0220C980(char *p);
int func_0220CAAC(char *p);
int func_0220CBB4(char *p);
int func_0220CBE8(char *p);
int func_0220CC18(char *p);
int func_0220CD50(char *p);
int func_0220CFA4(char *p);
int func_0220CFF0(char *p);
int func_0220D024(char *p);
int func_0220D11C(char *p);
int func_0220D214(char *p);
int func_0220D234(char *p);
int func_0220D254(char *p);
int func_0220D274(char *p);
int func_0220D29C(char *a);
int func_0220D2AC(char *p);
int func_0220D328(char *p);
int func_0220D358(char *p);
int func_0220D370(char *p);
int func_0220D39C(char *a);
int func_0220D3B0(struct Node *task, char *p);
int func_0220D464(char *p);
void func_0220D5C0(char *p);
void func_0220D6B8(void);
void func_0220D6DC(char *p);
void func_0220D798(char *p);
void func_0220D7D0(char *p);
void func_0220D7F0(void *unused, int mode);
void func_0220D848(char *p,int mode);
int func_0220D884(char **p);
void func_0220D89C(char **a, int b);
void func_0220D8B0(char **a, int b);
void func_0220D8C4(u8 *p, u32 index, u32 value);
u32 func_0220D914(u8 *p);
void func_0220D924(u8 *p, int state, int value);
void func_0220D974(char *a, int b);
void func_0220D98C(u8 *p, u32 idx);
void func_0220D9A8(u8 *p,u32 i);
void func_0220D9BC(char *p);
void func_0220D9C8(char *p);
void func_0220D9D4(u8 *p,u32 i);
extern const char d_0220E0E0[];
extern u16 d_04001050[];
extern const struct BgVramReq d_0220DEB0;
extern const struct BgTemplate d_0220DEE0,d_0220DF20,d_0220DF00,d_0220DEC0;
extern const u32 d_0220DF90[], d_0220DF9C[];


void func_0220C6E8(char *a)
{
    func_02209B30(((struct Obj25045 *)a)->f14C);
}


/*
 * Addresses are Black-image addresses.
 */
void func_0220C6F8(u8 *p, u32 a, u32 b)
{
    func_02209B60(((struct Obj25046 *)p)->f14C, a, b, 2, 6, 0x14);
}


void func_0220C714(char *a)
{
    func_02209C18(((struct Obj25047 *)a)->f14C);
}

/*
 * matching: pair aggregate copy emits two unsigned halfword transfers;
 *   explicit objects base keeps the first indexed address split correctly.
 */
void func_0220C724(char *p,u16 slot,u8 a,u8 b,const struct Pair *src)
{
    struct Pair v;
    u16 i;
    s8 left,right;
    void **objects=(void **)(p+0x424);
    func_0220C4D4((int)objects[slot],(int)src);
    func_0204B878(objects[slot],a);
    slot++;
    left=a;
    right=b;
    v=*src;
    v.x+=12;
    for(i=0;i<7;i++) {
        if(left<=0) {
            if(right<=0) func_0204B878(*(void **)(p+slot*4+0x424),15);
            else if(right==1) {func_0204B878(*(void **)(p+slot*4+0x424),19);right--;}
            else {func_0204B878(*(void **)(p+slot*4+0x424),20);right-=2;}
        } else if(left==1) {
            if(right==0) func_0204B878(*(void **)(p+slot*4+0x424),16);
            else if(right>0) {func_0204B878(*(void **)(p+slot*4+0x424),18);right--;}
            left--;
        } else {func_0204B878(*(void **)(p+slot*4+0x424),17);left-=2;}
        func_0220C4D4(*(int *)(p+slot*4+0x424),(int)&v);
        v.x+=8;
        slot++;
    }
}


/*
 * lever: Size constant held in a local (offsets derived from it), the 0x533 store repeated in each arm instead of one shared tail, and no row-pointer local in the first loop (*(u8 **)p re-read per argument).
 */
void func_0220C834(u8 *arg)
{
    u8 *p;
    u8 *q;
    int z;
    u32 i;
    int v;
    int sz = 0x5A4;
    p = func_02030734(*(u16 *)(arg + 0xc), sz, 1, d_0220E0E0, 0xB1);
    q = func_02030DA8(func_021F86D4(), (u32)func_0220C914, p, 0x64);
    *(u8 **)p = arg;
    *(void **)(p + 8) = (void *)func_021F86E0();
    z = 0;
    *(int *)(p + sz - 4) = z;
    if (*(int *)(*(u8 **)p + 8) == 1) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = 1;
        p[sz - 0x71] = z;
    } else if (*(int *)(*(u8 **)p + 8) == 3) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = z;
        z = 2;
        p[sz - 0x71] = z;
    } else {
        p[sz - 0x72] = z;
        p[sz - 0x74] = z;
        p[sz - 0x71] = z;
    }
    if (*(int *)(*(u8 **)p + 8) != 1) {
        for (i = 0; i < 4; i++) {
            func_0200829C((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)), (u16)i, (s16_0220C834 *)(*(u8 **)p + 0x30 + i * 2), (s16_0220C834 *)(*(u8 **)p + 0x38 + i * 2));
        }
        *(u16 *)(p + 0x540) = func_020082B0((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        p[0x542] = func_020082B4((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        func_0220B9A4((char *)p);
    } else {
        for (i = 0; i < 4; i++) {
            *(u16 *)(*(u8 **)p + i * 2 + 0x30) = 0;
            *(u16 *)(*(u8 **)p + i * 2 + 0x38) = 0;
        }
    }
}

extern int (*const d_0220DF40[])(char *);

void func_0220C914(void *task, char *p)
{
    if (((struct Obj25048 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) {
        ((struct Obj25049 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f16 = 0;
        ((struct Obj25050 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f18 = 0;
        ((struct Obj00846 *)p)->f530 = 20;
    }
    if (((struct Obj00846 *)p)->f530 != 20) ((struct Obj00846 *)p)->f530 = d_0220DF40[*(u8 *)(p + 0x530)](p);
    if (((struct Obj00846 *)p)->f530 == 20 && func_0220D3B0(task, p) == 1) return;
    func_020310C4(*(struct Tcbl * *)&((struct Obj00846 *)p)->f4);
    func_0220BF40(p);
    func_0202CD94(*(struct WinMgr * *)&((struct Obj00846 *)p)->f520);
    func_0220B980(p);
}

/*
 * lever: word-address arithmetic reuses the MMIO pool base, as in matched ov197 0220CAAC.
 */
int func_0220C980(char *p)
{
    d_04001050[0]=0;
    func_0207D534((u16 *)((unsigned)d_04001050+0x1c),-16);
    ((struct Obj00736 *)p)->f4=sub_0203101C(((struct Obj25051 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC,((struct Obj25052 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC,1,4);
    ((struct Obj00736 *)p)->f148=func_0220AF40(((struct Obj25053 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC);
    func_0220D5C0(p);
    func_0220D6DC(p);
    func_0220D798(p);
    if(((struct Obj25054 *)(*(char * *)&((struct Obj00736 *)p)->f0))->f8==2) func_0220BB78(p);
    else func_0220BA2C((u8 *)p);
    func_0220B120(p);
    func_0220B1B0(p,((struct Obj00736 *)p)->f532);
    func_0220B990((u8 *)p);
    func_0220BBE4(p);
    func_0220BD24(p,((struct Obj00736 *)p)->f532);
    func_0220C034(p);
    func_0220C4EC(p,((struct Obj00736 *)p)->f532);
    if(**(u8 * *)&((struct Obj25055 *)(*(char * *)&((struct Obj00736 *)p)->f0))->f2C==1) ((struct Obj00736 *)p)->f598=(void *)1;
    else ((struct Obj00736 *)p)->f598=0;
    func_0220AFDC(*(char * *)&((struct Obj00736 *)p)->f148,((struct Obj00736 *)p)->f598);
    if(((struct Obj00736 *)p)->f532==0) func_0220D8C4((u8 *)p,((struct Obj00736 *)p)->f532,((struct Obj00736 *)p)->f542);
    else func_0220D8C4((u8 *)p,((struct Obj00736 *)p)->f532,0);
    func_0203D34C(0,((struct Obj25057 *)(*(char * *)&((struct Obj00736 *)p)->f0))->fC);
    func_020216D4(((struct Obj00736 *)p)->f8,3,224,32);
    func_0202173C(((struct Obj00736 *)p)->f8,10,65535,0,16,0,0,func_021F86D4());
    if(((struct Obj25058 *)(*(char * *)&((struct Obj00736 *)p)->f0))->f8==3) func_0220D7F0(p,((struct Obj00736 *)p)->f532);
    ((struct Obj00736 *)p)->f5A0=1;
    return 2;
}

/*
 * lever: word-address arithmetic reuses MMIO pool base for +0x1c; typed pointer addition pools a second word.
 */
int func_0220CAAC(char *p)
{
    d_04001050[0] = 0;
    func_0207D534((u16 *)((unsigned)d_04001050 + 0x1c), -16);
    ((struct Obj01076 *)p)->f4 = sub_0203101C(((struct Obj25059 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC, ((struct Obj25060 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC, 1, 4);
    ((struct Obj01076 *)p)->f148 = func_0220AF40(((struct Obj25061 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC);
    func_0220D5C0(p);
    func_0220D6DC(p);
    func_0220D798(p);
    func_0220BB1C(p);
    func_0220D7F0(p, ((struct Obj01076 *)p)->f532);
    func_0220B120(p);
    func_0220B1B0(p, ((struct Obj01076 *)p)->f532);
    func_0220B990((u8 *)p);
    func_0220BBE4(p);
    func_0220BD24(p, ((struct Obj01076 *)p)->f532);
    func_0220C034(p);
    func_0220C4EC(p, ((struct Obj01076 *)p)->f532);
    if (**(u8 * *)&((struct Obj25062 *)(*(char * *)&((struct Obj01076 *)p)->f0))->f2C == 1) ((struct Obj01076 *)p)->f598 = (void *)1;
    else ((struct Obj01076 *)p)->f598 = 0;
    func_0220AFDC(*(char * *)&((struct Obj01076 *)p)->f148, ((struct Obj01076 *)p)->f598);
    func_0220D8C4((u8 *)p, ((struct Obj01076 *)p)->f532, 0);
    func_0203D34C(0, ((struct Obj25064 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC);
    func_020216D4(((struct Obj01076 *)p)->f8, 3, 0xe0, 0x20);
    func_0202173C(((struct Obj01076 *)p)->f8, 0xa, 0xffff, 0, 0x10, 0, 0, func_021F86D4());
    ((struct Obj01076 *)p)->f5A0 = 1;
    return 2;
}

int func_0220CBB4(char *p){if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj14547 *)p)->f18)==1){func_0202208C((void *)4,1,1,0,6,1,((struct Obj25065 *)(*(char * *)&((struct Obj14547 *)p)->f0))->fC);return 3;}return 2;}

int func_0220CBE8(char *p){if(func_020221A4()==1){if(((struct Obj25066 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==2)return 17;if(((struct Obj25067 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==1)return 5;if(((struct Obj25068 *)(*(char * *)&((struct Obj10835 *)p)->f0))->f8==3)return 5;return 4;}return 3;}

int func_0220CC18(char *p)
{
    unsigned sel;
    if (func_02021ED8(((struct Obj02244 *)p)->f8) != 0) goto done;
    if (func_0220D884((char **)p) == 1) return 0x12;
    sel = func_02025DE8(((struct Obj02244 *)p)->f144);
    switch (sel) {
    case 0: case 1: case 2: case 3:
        func_0220D89C((char **)p, 0x54d);
        ((struct Obj02244 *)p)->f533 = (u8)sel;
        ((struct Obj02244 *)p)->f531 = 8;
        func_0220BF20(p, (u8)sel);
        return 0x10;
    case 4:
        if (((struct Obj02244 *)p)->f540 != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj02244 *)p)->f533 = ((struct Obj02244 *)p)->f542;
            ((struct Obj02244 *)p)->f531 = 9;
            func_0220B9D8((u8 *)p);
            func_0220BF20(p, 0xd);
            return 0x10;
        }
        break;
    case 5:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj25069 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f16 = 0;
        ((struct Obj25070 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f2A = 4;
        func_0220BF20(p, 0xa);
        return 0x12;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj25071 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f16 = 0;
        ((struct Obj25072 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f2A = 4;
        func_0220BF20(p, 0xa);
        return 0x12;
    case (unsigned)-4: case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-6:
    case (unsigned)-5: case (unsigned)-1:
        break;
    }
done:
    return 4;
}

int func_0220CD50(char *p)
{
    unsigned sel;
    if (func_02021ED8(((struct Obj00389 *)p)->f8) != 0) goto done;
    if (func_0220D884((char **)p) == 1) return 0x12;
    sel = func_02025DE8(((struct Obj00389 *)p)->f144);
    switch (sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if (func_0220BB98(p, sel) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = (u8)sel;
            ((struct Obj00389 *)p)->f531 = 9;
            func_0220BF20(p, (u8)(sel + 4));
            return 0x10;
        }
        break;
    case 6:
        func_0220D89C((char **)p, 0x552);
        func_0220BF20(p, 0xa);
        if (((struct Obj25073 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 1 || ((struct Obj25074 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 3) {
            ((struct Obj25075 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f16 = 0;
            ((struct Obj25076 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f2A = 4;
            return 0x12;
        }
        ((struct Obj00389 *)p)->f531 = 7;
        return 0x10;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        func_0220BF20(p, 0xa);
        if (((struct Obj25077 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 1 || ((struct Obj25078 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 3) {
            ((struct Obj25079 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f16 = 0;
            ((struct Obj25080 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f2A = 4;
            return 0x12;
        }
        ((struct Obj00389 *)p)->f531 = 7;
        return 0x10;
    case 7:
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00389 *)p)->f531 = 0xb;
            *(signed char *)&((struct Obj00389 *)p)->f534 = -1;
            func_0220BF20(p, 0xb);
            return 0x10;
        }
        break;
    case 8:
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00389 *)p)->f531 = 0xb;
            ((struct Obj00389 *)p)->f534 = 1;
            func_0220BF20(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-4: case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-6:
        func_020260E0(((struct Obj00389 *)p)->f144);
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00389 *)p)->f531 = 0xb;
            *(signed char *)&((struct Obj00389 *)p)->f534 = -1;
            func_0220BF20(p, 0xb);
            return 0x10;
        }
        break;
    case (unsigned)-5:
        func_020260E0(((struct Obj00389 *)p)->f144);
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00389 *)p)->f531 = 0xb;
            ((struct Obj00389 *)p)->f534 = 1;
            func_0220BF20(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-1:
        break;
    }
done:
    return 5;
}

/*
 * lever: narrow value load then compound add before reading maximum fixes r0/r6 swap.
 */
int func_0220CFA4(char *p)
{
    unsigned index = ((struct Obj00314 *)p)->f533;
    short *values = (short *)(*(char * *)&((struct Obj00314 *)p)->f0 + 0x38);
    s8 value = (s8)values[index];
    u8 maximum;
    value += ((struct Obj00314 *)p)->f534;
    maximum = *(u8 *)(p + index + 0x539);
    if (value > maximum) value = 0;
    else if (value < 0) {
        values[index] = maximum;
        goto done;
    }
    values[index] = value;
done:
    func_0220B520(p);
    func_0220B584(p);
    return 12;
}

int func_0220CFF0(char *p){if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj10837 *)p)->f18)==1){func_0220B990((unsigned char *)p);func_0220C4EC(p,((struct Obj10837 *)p)->f532);func_0220BD24(p,((struct Obj10837 *)p)->f532);return 5;}return 12;}

int func_0220D024(char *p)
{
    if (func_0220D884((char **)p) == 1) return 0x12;
    switch ((unsigned)func_02025DE8(((struct Obj02245 *)p)->f144)) {
    case 0:
        func_0220D89C((char **)p, 0x54d);
        ((struct Obj25081 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16 = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj02245 *)p)->f0 + ((struct Obj02245 *)p)->f533 * 2 + 0x30));
        ((struct Obj25082 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f2A = ((struct Obj02245 *)p)->f533;
        if (((struct Obj25083 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f8 == 1)
            ((struct Obj25085 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = func_0220BBD8(((struct Obj25084 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16);
        else
            ((struct Obj25086 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = 0;
        func_0220BF20(p, 0xd);
        return func_0220D11C(p);
    case 1:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        func_0220BF20(p, 0xa);
        return 0x10;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        func_0220BF20(p, 0xa);
        return 0x10;
    case (unsigned)-4:
    case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-6:
    case (unsigned)-5:
    case (unsigned)-1:
        break;
    }
    return 6;
}

/*
 * Owner unit_02045C44.c omits func_02045CAC in function:. Verified EXACT344 C
 * below copied from ov173_func_021B71C4.c, prior ov070 fixed-flag --arm one.
 * abi: BBD8 returns a zero-extended u16; int extern preserves the original signed bge against the u8 field, unlike older unsigned caller externs.
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
int func_0220D11C(char *p)
{
    char *q = *(char **)p;
    if (*(int *)(q + 8) == 1 && *(u8 *)(q + 0x14) < func_0220BBD8(*(u16 *)(q + 0x16))) {
        func_02045CAC(*(void **)(p + 0xc), 0x31, *(void **)(p + 0x14));
        func_0220B904(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    if (*(u8 *)(p + 0x533) == 2) {
        if (*(u8 *)(q + 0x28) == 1) {
            func_02045CAC(*(void **)(p + 0xc), 0x2d, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 2) {
            func_02045CAC(*(void **)(p + 0xc), 0x2c, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 3) {
            func_02045CAC(*(void **)(p + 0xc), 0x33, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 4) {
            func_02045CAC(*(void **)(p + 0xc), 0x2f, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
    }
    if (*(u8 *)(q + 0x29) == 0 && func_02020FE4((void *)(unsigned)*(u16 *)(q + 0x16), 7, *(u16 *)(q + 0xc)) == 3) {
        func_02045CAC(*(void **)(p + 0xc), 0x32, *(void **)(p + 0x14));
        func_0220B904(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    return 0x12;
}

int func_0220D214(char *p){func_0220B1B0(p,0);((struct Obj14548 *)p)->f532=0;((struct Obj14548 *)p)->f531=4;return 10;}

int func_0220D234(char *p){func_0220B1B0(p,1);((struct Obj14549 *)p)->f532=1;((struct Obj14549 *)p)->f531=5;return 10;}

int func_0220D254(char *p){func_0220B1B0(p,2);((struct Obj14550 *)p)->f532=2;((struct Obj14550 *)p)->f531=6;return 10;}

int func_0220D274(char *p){if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj10838 *)p)->f18)==1){func_0220D848(p,((struct Obj10838 *)p)->f532);return ((struct Obj10838 *)p)->f531;}return 10;}


int func_0220D29C(char *a)
{
    func_0201F7A8((void *)(((struct Obj25087 *)a)->f24), 0);
    return 6;
}

int func_0220D2AC(char *p)
{
    switch (func_0201CE30(*(struct Rec * *)&((struct Obj03346 *)p)->f1C)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3)) func_0201CE5C(*(struct Rec * *)&((struct Obj03346 *)p)->f1C, 0);
        ((struct Obj03346 *)p)->f20 = 0;
        break;
    case 1:
        if (!((struct Obj03346 *)p)->f20 && (func_02035C60() == 1 || (func_020362DC() & 3))) {
            func_0220D8B0((char **)p, 0x547);
            func_0201CE38(*(struct Rec * *)&((struct Obj03346 *)p)->f1C);
            ((struct Obj03346 *)p)->f20 = 1;
        }
        break;
    case 2:
        func_0201CE48(*(struct Rec3 * *)&((struct Obj03346 *)p)->f1C);
        *(int *)&((struct Obj03346 *)p)->f1C = 0;
        ((struct Obj03346 *)p)->f20 = 0;
        return 15;
    }
    return 14;
}

/*
 * trailing: larger follower filed as ov197_func_0220D358.c (parent cleared).
 */
int func_0220D328(char *p)
{
    if (func_0220D884((char **)p) == 1) return 18;
    if ((func_020362DC() & 3) || func_02035C60() == 1)
        return ((struct Obj25088 *)p)->f531;
    return 15;
}

/*
 * lever: explicit else preserves the nonzero arm after the field-return arm.
 * leaf: parent-cleared 24-byte follower in D328 extent.
 */
int func_0220D358(char *p)
{
    if (((struct Obj14551 *)p)->f527 == 0) {
        return ((struct Obj14551 *)p)->f531;
    } else {
        return 16;
    }
}

int func_0220D370(char *p){func_0202173C(*(PalAnmObj * *)&((struct Obj25089 *)p)->f8,10,65535,0,0,16,0,func_021F86D4());return 19;}


int func_0220D39C(char *a)
{
    if (func_02021ED8((const char *)(((struct Obj25090 *)a)->f8)) == 0)
        return 0x14;
    return 0x13;
}

/*
 * lever: explicit if/else field stores preserve one-first branch and shared store.
 */
int func_0220D3B0(struct Node *task, char *p)
{
    if (((struct Obj00846 *)p)->f5A0 == 1) {
        if (func_0201C6B4(*(struct PrintSys * *)&((struct Obj00846 *)p)->f18) == 0) {
            if (((struct Obj25091 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) func_0201C6EC(*(struct PrintSys * *)&((struct Obj00846 *)p)->f18);
            else return 0;
        }
        if (func_020221A4() == 0) {
            if (((struct Obj25092 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f24 == 1) func_020221B8();
            else return 0;
        }
        if (*(struct Rec3 * *)&((struct Obj00846 *)p)->f1C) func_0201CE48(*(struct Rec3 * *)&((struct Obj00846 *)p)->f1C);
        func_0220BD14(p);
        func_0220C448(p);
        func_0220B1A0(p);
        func_0220D7D0(p);
        func_0220D6B8();
        func_02031140(*(struct S02031140 * *)&((struct Obj00846 *)p)->f4);
        func_0220D914((u8 *)p);
        func_0220AF64(((struct Obj00846 *)p)->f148);
        if (((struct Obj00846 *)p)->f598 == 1) {
            **(u8 * *)&((struct Obj25093 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f2C = 1;
        } else {
            **(u8 * *)&((struct Obj25095 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f2C = 0;
        }
    }
    ((struct Obj25097 *)(*(char * *)&((struct Obj00846 *)p)->f0))->f19 = 1;
    func_02030EAC(task);
    func_020307B0(p);
    return 1;
}

int func_0220D464(char *p)
{
    switch (((struct Obj00688 *)p)->f53D) {
    case 0:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00688 *)p)->f533 = 2;
            ((struct Obj00688 *)p)->f531 = 0x11;
            func_0220BF20(p, 2);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 1:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 0) {
            func_0220D234(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00688 *)p)->f531 = 0x11;
            func_0220BF20(p, 4);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 3:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 0) {
            func_0220D254(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj25098 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f16 = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30));
            ((struct Obj25099 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f2A = ((struct Obj00688 *)p)->f533;
            ((struct Obj25100 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f18 = 0;
            func_0220BF20(p, 0xd);
            ++((struct Obj00688 *)p)->f53D;
        }
        break;
    case 5:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 0) return func_0220D11C(p);
        break;
    }
    return 0x11;
}

void func_0220D5C0(char *p)
{
 struct BgVramReq req=d_0220DEB0;
 struct BgTemplate b7,b6,b5,b4;
 func_0203FC6C(&req,1);
 b7=d_0220DEE0;func_0203FCA0(7,&b7,0);
 b6=d_0220DF20;func_0203FCA0(6,&b6,0);
 b5=d_0220DF00;func_0203FCA0(5,&b5,0);func_020414EC(5);
 b4=d_0220DEC0;func_0203FCA0(4,&b4,0);func_020414EC(4);
 func_02040B94(5,32,0,((struct Obj25101 *)(*(char * *)&((struct Obj14552 *)p)->f0))->fC);
 func_02040B94(4,32,0,((struct Obj25102 *)(*(char * *)&((struct Obj14552 *)p)->f0))->fC);
 func_02041B6C(5);func_02041B6C(4);func_02043598(15,1);
}


void func_0220D6B8(void)
{
    func_02043598(0x1f, 0);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}

void func_0220D6DC(char *p)
{
    void *handle = func_020490F4(99,(u16)((((struct Obj25103 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC & 0x7fff) | 0x8000));
    func_02049658(handle, 0, 6, 0, 0, 1, ((struct Obj25104 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020498F4(handle, 3, 6, 0, 0, 1, ((struct Obj25105 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020498F4(handle, 2, 7, 0, 0, 1, ((struct Obj25106 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020216B4(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, (void *)((u32)handle), 1, ((struct Obj25107 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC, 1, 224, 0);
    func_02049238(handle);
    func_0201F5BC(4, 1, 11, 0, ((struct Obj25108 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, 1, 176, 32);
    func_02021640(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, 23, 5, ((struct Obj25109 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC, 1, 32, 192);
}

void func_0220D798(char *p){*(struct MsgBank * *)&((struct Obj03906 *)p)->fC=func_02045B38(0,2,17,((struct Obj25110 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);*(struct WordSet * *)&((struct Obj03906 *)p)->f10=func_0201EC64(((struct Obj25111 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);((struct Obj03906 *)p)->f18=func_0201C440((void *)((struct Obj25112 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);*(struct U16Vec * *)&((struct Obj03906 *)p)->f14=func_020457B0(512,((struct Obj25113 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);}

/*
 * Tail: two zero alignment bytes at 0x0220D7EE.
 */
void func_0220D7D0(char *p){func_02045C04(((struct Obj08356 *)p)->fC);func_0201ED04(*(struct WordSet * *)&((struct Obj08356 *)p)->f10);func_0201C4C0(*(struct PrintSys * *)&((struct Obj08356 *)p)->f18);func_02045808(((struct Obj08356 *)p)->f14);}

/*
 * trailing: 2 zero alignment bytes at 0x0220D846.
 */
void func_0220D7F0(void *unused, int mode)
{
    switch (mode) {
    case 0:
        func_02041EE4(6, 0, 0);
        func_02041EE4(6, 3, 0);
        break;
    case 1:
        func_02041EE4(6, 0, 256);
        func_02041EE4(6, 3, 0);
        break;
    case 2:
        func_02041EE4(6, 0, 0);
        func_02041EE4(6, 3, 256);
        break;
    }
}

void func_0220D848(char *p,int mode){func_0220D7F0(p,mode);func_02041570(4,0);func_02041570(5,0);func_0220B990((unsigned char *)p);func_0220BD24(p,mode);func_0220D924((unsigned char *)p,mode,0);func_0220C4EC(p,mode);}


int func_0220D884(char **p)
{
    if (((struct Obj25114 *)(*p))->f20 == 1) {
        ((struct Obj25115 *)(*p))->f16 = 0;
        ((struct Obj25116 *)(*p))->f18 = 0;
        return 1;
    }
    return 0;
}


void func_0220D89C(char **a, int b)
{
    if (((struct Obj25118 *)(*a))->f40 == 1)
        func_020061E4(b);
}


void func_0220D8B0(char **a, int b)
{
    if (((struct Obj25120 *)(*a))->f40 == 1)
        func_020061E4(b);
}

void func_0220D8C4(u8 *p, u32 index, u32 value)
{
    *(struct Struct_02025CD0 * *)&((struct Obj03347 *)p)->f144 = func_02025CD0(d_0220DF9C[index], d_0220DF90[index], (u32)p, ((struct Obj03347 *)p)->f598, (u8)value, ((struct Obj25121 *)(*(u8 * *)&((struct Obj03347 *)p)->f0))->fC);
    func_02025D1C(*(struct Struct_02025D1C * *)&((struct Obj03347 *)p)->f144);
    func_02025D24(*(struct Struct_02025D24 * *)&((struct Obj03347 *)p)->f144);
    func_0220D98C(p, value);
}


/*
 *   traced func_ label), so neither label nor sole-ref/code can attest it;
 *   byte-correct otherwise.  Not resolvable from this packet.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0220D914(u8 *p)
{
    return func_02025D14((void *)(((struct Obj25122 *)p)->f144));
}

/*
 * lever: an outer switch preserves the unconditional default-arm branch.
 */
void func_0220D924(u8 *p, int state, int value)
{
    switch (*(int *)&((struct Obj03347 *)p)->f598) {
    case 0: value = 0; break;
    default:
        switch (state) {
        case 0: value = p[0x533]; break;
        case 1: value = *(s16_0220D924 *)(*(char * *)&((struct Obj03347 *)p)->f0 + p[0x533] * 2 + 0x30); break;
        case 2: value = 0; break;
        }
        break;
    }
    func_0220D914(p);
    func_0220D8C4(p, state, value);
}


void func_0220D974(char *a, int b)
{
    ((struct Obj06649 *)a)->f598 = b;
    func_0220AFDC((char *)(*(int *)&((struct Obj06649 *)a)->f148), (void *)b);
}


void func_0220D98C(u8 *p, u32 idx)
{
    void *t = func_0202616C(*(void ** *)&((struct Obj06649 *)p)->f144, idx);

    func_0220B000((int *)(((struct Obj06649 *)p)->f148), (u8 *)((u32)t));
}

void func_0220D9A8(u8 *p,u32 i){func_0220D98C(p,i);func_0220D974((char *)p,1);}

void func_0220D9BC(char *p){func_0220D974(p,0);}

void func_0220D9C8(char *p){func_0220D974(p,0);}

void func_0220D9D4(u8 *p,u32 i){func_0220D98C(p,i);}
