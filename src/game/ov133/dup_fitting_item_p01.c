/*
 * file:     dup_fitting_item_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6294, func_021B63BC, func_021B6884, func_021B69AC
 * address:  0x021B6100
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021B6BA4 0x021B6BA4 thumb ov133
 *   func_021B6E74 0x021B6E74 thumb ov133
 *   func_021B6F00 0x021B6F00 thumb ov133
 *   func_021B9DE8 0x021B9DE8 thumb ov133
 *   func_021B9B48 0x021B9B48 thumb ov133
 *   func_020056A0 0x020056A0 thumb
 *   func_0202208C 0x0202208C thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021B9028 0x021B9028 thumb ov133
 *   func_0200A828 0x0200A828 thumb
 *   func_0200A834 0x0200A834 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_0203D34C 0x0203D34C arm
 *   d_021BA600 0x021BA600 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_0200A6F8 0x0200A6F8 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_021B9BD0 0x021B9BD0 thumb ov133
 *   func_021B9F24 0x021B9F24 thumb ov133
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021B7498 0x021B7498 thumb ov133
 *   func_021F5330 0x021F5330 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_021B9818 0x021B9818 thumb ov133
 *   func_021B8A30 0x021B8A30 thumb ov133
 *   func_021B98A0 0x021B98A0 thumb ov133
 *   func_021B75E0 0x021B75E0 thumb ov133
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_021B918C 0x021B918C thumb ov133
 *   func_021B940C 0x021B940C thumb ov133
 *   func_021B9784 0x021B9784 thumb ov133
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021FD6A4 0x021FD6A4 thumb ov132
 *   func_021B9F5C 0x021B9F5C thumb ov133
 *   func_021B8C6C 0x021B8C6C thumb ov133
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F4990 0x021F4990 thumb ov112
 *   func_0204A600 0x0204A600 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204F7DC 0x0204F7DC arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204152C 0x0204152C arm
 *   func_020450F0 0x020450F0 arm
 *   func_021B9C90 0x021B9C90 thumb ov133
 *   func_0201F73C 0x0201F73C thumb
 *   func_021BA0C8 0x021BA0C8 thumb ov133
 *   func_0204047C 0x0204047C arm
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021B9CBC 0x021B9CBC thumb ov133
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA214 0x021BA214 thumb ov133
 *   func_021BA1EC 0x021BA1EC thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021B7A18 0x021B7A18 thumb ov133
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_021F4D74 0x021F4D74 thumb ov112
 *   func_021F4AA4 0x021F4AA4 thumb ov112
 *   func_0204F32C 0x0204F32C arm
 *   func_0204F2E4 0x0204F2E4 arm
 *   func_0204F2FC 0x0204F2FC arm
 *   func_0204EDD0 0x0204EDD0 arm
 *   func_0204F044 0x0204F044 arm
 *   func_0204F1A0 0x0204F1A0 arm
 *   func_0204A648 0x0204A648 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204044C 0x0204044C arm
 *   func_021B6E4C 0x021B6E4C thumb ov133
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0204EBD4 0x0204EBD4 arm
 *   d_021BA518 0x021BA518 data a4
 *   d_021BA3F4 0x021BA3F4 data a4
 *   d_021BA40C 0x021BA40C data a4
 *   d_021BA400 0x021BA400 data a4
 *   d_021BA418 0x021BA418 data a4
 *   d_021BA428 0x021BA428 data a4
 *   d_021BA438 0x021BA438 data a4
 *   d_021BA458 0x021BA458 data a4
 *   d_021BA478 0x021BA478 data a4
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA498 0x021BA498 data a4
 *   d_021BA4B8 0x021BA4B8 data a4
 *   d_021BA4D8 0x021BA4D8 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021BA5C4 0x021BA5C4 data a4
 */
#include "../../matched/include/Obj01941.h"
#include "../../matched/include/Obj23308.h"

#define W(k) (*(u32 *)((u8 *)p+(k)))
#define H(k) (*(u16 *)((u8 *)p+(k)))
#define B(k) (*(u8 *)((u8 *)p+(k)))
#define P(k) (*(u8 **)((u8 *)p+(k)))
struct Big;
struct Obj;
struct Descriptor;
struct Bank;
struct Node;
struct Board;
struct Camera;
struct Cfg;
struct Lights;
struct O;
struct PrintSys;
struct Obj0204F1A0;
struct DispConfig;
struct DispVram;
struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 prefix[0x18c1]; u8 counter; u16 timer,pad18c4; u8 brightness,pad; u32 mode,busy,flag; u16 sentinel; u8 pad18d6[0x16]; u32 window; } Context;

typedef signed short s16;

typedef struct { u32 x,y,z; } Vec;

typedef struct { u32 words[2]; u8 a,b,c,d; u32 field; u16 dims[6]; } Config;

typedef enum { DISP_SUB_MAIN=0, DISP_MAIN_SUB=1 } DispSelect;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_021B6BA4(u8 *);
extern void func_021B6E74(u8 *);
extern void func_021B6F00(u8 *);
extern void func_021B9DE8(u8 *);
extern void func_021B9B48(u8 *);
extern void *func_020056A0(void *,void *,int);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021B9028(u8 *,int,u16);
extern u32 func_0200A828(struct Big *p);
extern void func_0200A834(struct Big *p, u8 value);
extern void func_02005D90(int,int);
extern void func_0203D34C(u32,u32);
extern void func_020355D8(u8);
extern void func_0200A6F8(struct Big *);
extern void func_02005D28(void);
extern void func_021B9BD0(unsigned char *p);
extern void func_021B9F24(unsigned char *p);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_021B7498(u8 *p);
extern void func_021F5330(int,int);
extern void func_021F51B0(int a);
extern void func_02030EAC(struct Node *);
extern void func_0204ED24(void *);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern u32 func_020307B0(void *p);
extern void func_020061E4(u32);
extern u32 func_020221A4(void);
extern int func_02005E50(void);
extern void func_02005E30(u32);
extern void func_021B9818(u8 *),func_021B8A30(u8 *),func_021B98A0(u8 *),func_021B75E0(u8 *);
extern void func_021B9C08(u8 *,u32,void *),func_021B918C(u8 *),func_021B9784(u8 *);
extern int func_021B940C(u8 *);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern int func_021FD6A4(char *p);
extern void func_021B9F5C(u8 *);
extern void func_021B8C6C(struct O *p);
extern void func_021F51E8(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F4990(void *);
extern void func_0204A600(void),func_02047964(void),func_020479D8(void),func_02047970(void);
extern void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void func_02041EE4(u32,u32,u32);
extern void func_0204152C(int,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_021B9C90(u8 *),func_0201F73C(void *,int,int,int),func_021BA0C8(u8 *,u8);
extern void func_0204047C(int,u16),func_0204989C(u32,u32,u32,u32,u32,u32,u16),func_02041B6C(u32);
extern void func_0201C6EC(struct PrintSys *p);
extern u32 func_021BA20C(u8 *p);
extern void func_021B9CBC(u8 *,u8 *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_0200FB24(void);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void *func_021BA184(char *p);
extern u32 func_021BA218(u8 *p);
extern u32 func_021BA214(u8 *p);
extern void func_021BA1EC(u8 *p, u8 *q, u8 *r);
extern u32 func_021BA208(u8 *p);
extern void func_021B7A18(u8 *);
extern u32 func_021F4F10(u8 *);
extern u8 *func_021F4F54(u8 *, int);
extern int func_021F4F70(int *);
extern void func_021F4D74(u8 *, u8 *, int, u16);
extern void func_021F4AA4(void *);
extern void func_0204F32C(int p0, int p1, int p2);
extern void func_0204F2E4(u8 *, int, u32 *);
extern void func_0204F2FC(u8 *p, int i, u32 value);
extern void func_0204EDD0(int, u16 *, u16 *);
extern int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern void func_0204F1A0(struct Obj0204F1A0 *a0, u32 a1);
extern void func_0204A648(void);
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *c);
extern void func_02046440(u32,u32,u32,u32,u16,u32,void (*)(void));
extern void func_02046BE0(u32,u32);
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec *,Vec *,Vec *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(void *);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0204044C(u32);
extern void func_021B6E4C(const void *t, unsigned int id);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void *func_0204EBD4(u8 *,void *);
u8 *func_021B6100(u8 *parent, int heap);
void func_021B6294(char *p);
int func_021B63BC(Context *p);
void func_021B6884(void *unused, u8 *p);
void func_021B69AC(u8 *p);
extern const char d_021BA600[];
extern u8 d_021BA518[],d_021BA418[],d_021BA428[],d_021BA438[],d_021BA458[],d_021BA478[],d_021BA4F8[],d_021BA498[],d_021BA4B8[],d_021BA4D8[];
extern Vec d_021BA3F4,d_021BA40C,d_021BA400;
extern Config d_020A1448,d_021BA5C4;

u8 *func_021B6100(u8 *parent, int heap)
{
    u8 *p = func_02030734(heap, 0x18f0, 1, d_021BA600, 0x1de);
    u32 t, m;
    *(u16 *)p = heap;
    *(u8 **)(p + 4) = parent;
    *(u32 *)(p + 0xc) = 7;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x18) = 0;
    *(u32 *)(p + 0x30) = 0;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x3c) = 0;
    *(u32 *)(p + 0x40) = 0;
    *(u32 *)(p + 0x98) = 0;
    *(u32 *)(p + 0xa4) = 8;
    *(u16 *)(p + 0x182c) = 0;
    *(u16 *)(p + 0x1838) = 0;
    *(u16 *)(p + 0x183a) = 0;
    *(u32 *)(p + 0x183c) = 0;
    *(u8 *)(p + 0x18c6) = 0;
    *(u32 *)(p + 0x18c8) = 0;
    *(u32 *)(p + 0x18d0) = 0;
    *(u32 *)(p + 0x18cc) = 0;
    *(u16 *)(p + 0x18d4) = 0xff;
    *(u8 *)(p + 0x18c1) = 0;
    *(u32 *)(p + 0x1834) = 0;
    *(u32 *)(p + 0x18ec) = 0;
    *(u16 *)(p + 0x182e) = 0;
    *(u32 *)(p + 0x34) = 10;
    func_021B69AC(p);
    func_021B6BA4(p);
    func_021B6E74(p);
    func_021B6F00(p);
    func_021B9DE8(p);
    func_021B9B48(p);
    *(void **)(p + 8) = func_020056A0((void *)func_021B6884, p, 8);
    func_0202208C((void *)2, 1, 1, 0x7fff, 18, 1, *(u16 *)p);
    t = *(u32 *)(p + 0x1834) + 0x18000;
    *(u16 *)(p + 0x18c2) = 10;
    m = *(u16 *)(p + 0xa8) * 0x1249;
    {
        u16 x;
        if (t >= m)
            x = (t - m) / 0x1249;
        else
            x = t / 0x1249;
        func_021B9028(p, 8, x);
    }
    *(u32 *)(p + 0xa4) = 8;
    *(u32 *)(p + 0x98) = 1;
    *(u32 *)(p + 0x9c) = 0;
    *(u32 *)(p + 0xa0) = *(u16 *)(p + 0x182c) % 0x1249 + 0x10000;
    if (func_0200A828((struct Big *)(*(u32 *)(*(u8 **)(p + 4) + 8))) == 0) {
        func_0200A834((struct Big *)(*(u32 *)(*(u8 **)(p + 4) + 8)), 1);
        *(u32 *)(p + 0x1840) = 1;
    } else {
        *(u32 *)(p + 0x1840) = 0;
    }
    func_02005D90(0x454, 0xffff);
    func_0203D34C(0, *(u16 *)p);
    return p;
}

void func_021B6294(char *p)
{
    u8 i;
    func_020355D8(1);
    func_0200A6F8(*(struct Big * *)&((struct Obj23308 *)(*(char * *)&((struct Obj01941 *)p)->f4))->f8);
    func_02005D28();
    func_021B9BD0((unsigned char *)p);
    func_021B9F24((unsigned char *)p);
    func_0204B3B4(*(struct Obj * *)&((struct Obj01941 *)p)->f184C);
    func_0204B3B4(*(struct Obj * *)&((struct Obj01941 *)p)->f1850);
    func_0204B3B4(*(struct Obj * *)&((struct Obj01941 *)p)->f1854);
    for(i=0;i<=2;i++) func_0204ADA4(*(u32 *)(p+0x1858+i*4));
    for(i=3;i<=5;i++) func_0204A8D4(*(u32 *)(p+0x1858+i*4));
    for(i=6;i<=8;i++) func_0204AFD8(*(u32 *)(p+0x1858+i*4));
    if(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC) func_020452E8(*(struct Descriptor * *)&((struct Obj01941 *)p)->f18EC);
    func_0204B1CC(*(struct Bank * *)&((struct Obj01941 *)p)->f1848);
    func_0204A5AC();
    func_021B7498((u8 *)p);
    func_021F5330(*(int *)&((struct Obj01941 *)p)->f187C,((struct Obj01941 *)p)->f1880);
    func_021F51B0(((struct Obj01941 *)p)->f187C);
    func_02030EAC(*(struct Node * *)&((struct Obj01941 *)p)->f8);
    func_0204ED24(((struct Obj01941 *)p)->f188C);
    func_02048AC4(((struct Obj01941 *)p)->f1888);
    func_02046788();
    func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
    func_020403F4(4);func_020403F4(6);func_020403F4(5);func_020403F4(7);
    func_020450C8();
    func_0203F9B4();
    func_020307B0(p);
}

static inline void brightness(u8 *value)
{
    func_02041EE4(6,0,128-*value);
    func_02041EE4(5,0,*value-128);
}

int func_021B63BC(Context *p)
{
    void *desc;
    switch(W(0x0c)) {
    case 7:
        func_020061E4(1358); W(0x0c)=8;
    case 8:
        if(func_020221A4()==1) {
            if(W(0x1840)==1) func_021B9818((u8 *)p);
            else W(0x0c)=1;
        }
        if(W(0x98)==1) func_021B8A30((u8 *)p);
        break;
    case 9:
        if(func_020221A4()==1 && func_02005E50()==0) return 2;
        break;
    case 0: func_021B98A0((u8 *)p); break;
    case 1: func_021B75E0((u8 *)p); break;
    case 2:
        W(0x10)+=6;
        if((int)W(0x10)>=192) {
            func_021B9C08((u8 *)p,1,0); W(0x10)=192; W(0x0c)=3;
            H(0x1838)=0; H(0x183a)=0; H(0x18c4)=0;
        }
        func_021B918C((u8 *)p); break;
    case 6:
        W(0x10)-=6;
        if((int)W(0x10)<0) { W(0x10)=0; W(0x0c)=1; }
        func_021B918C((u8 *)p); break;
    case 3:
        if(func_021B940C((u8 *)p)==2) { W(0x0c)=10; B(0x18c0)=0; func_0204B3DC((struct Obj *)P(0x18b0),1); }
        break;
    case 10:
        B(0x18c0)++; func_021B9784((u8 *)p);
        if(B(0x18c0)>60) {
            if(*(u32 *)P(4)==0) {
                func_0202208C(0,0,0,0x7fff,18,1,H(0)); func_02005E30(60); W(0x0c)=9; p->mode=1;
            } else {
                func_021B9C08((u8 *)p,2,0); func_021FCDEC(*(int *)P(4),69); W(0x0c)=4;
            }
        }
        break;
    case 4:
        if(func_021FCE00(*(void **)P(4),69)==1) W(0x0c)=5;
        break;
    case 5:
        if(func_021FD6A4(*(void **)P(4))==1) {
            func_0202208C(0,0,0,0x7fff,18,1,H(0)); func_02005E30(60); W(0x0c)=9; p->mode=1;
        }
        break;
    }
    func_021B9F5C((u8 *)p); func_021B8C6C((struct O *)p); func_021F51E8(P(0x187c));
    func_021F4990(P(0x1884)); func_0204A600(); func_02047964(); func_020479D8();
    func_021F51F4((void **)P(0x187c)); func_0204F7DC((struct Board *)P(0x188c),(struct Camera *)P(0x1888),0); func_02047970();
    p->counter++;
    if(p->counter>1) {
        p->counter=0;
        func_02041EE4(3,1,1); func_02041EE4(3,5,1);
    }
    if(p->mode==0) {
        if(p->brightness<128) { p->brightness+=8; brightness(&p->brightness); }
        else if(p->flag==0) {
            p->flag=1; func_0204152C(7,0);
            p->window=func_020450F0(7,1,19,30,4,14,1);
            if(W(0x1840)==0) func_021B9C90((u8 *)p); else func_021B9C08((u8 *)p,6,0);
            func_0201F73C((u8 *)p->window,1,128,12);
        }
    } else {
        if(p->flag==1) {
            func_021BA0C8((u8 *)p,2); p->flag=0;
            func_0204047C(7,3); func_0204047C(4,0); func_0204047C(5,1); func_0204047C(6,2);
            func_021BA0C8((u8 *)p,4); func_0204989C(46,13,7,0,0,0,H(0)); func_02041B6C(7);
            p->busy=0; func_0201C6EC((struct PrintSys *)P(0x18e8)); func_020452E8((struct Descriptor *)p->window); p->window=0; func_021BA0C8((u8 *)p,6);
        } else if(p->brightness!=0) {
            func_021BA0C8((u8 *)p,p->brightness+96); p->brightness-=8; brightness(&p->brightness);
        }
    }
    func_021BA0C8((u8 *)p,8);
    if(p->busy==0 && W(0x0c)==1) {
        if(P(0x38)!=0 && p->sentinel!=*(u16 *)func_021BA20C(P(0x38))) {
            func_021B9CBC((u8 *)p,P(0x38)); p->sentinel=*(u16 *)func_021BA20C(P(0x38));
        } else if(p->sentinel!=255 && P(0x38)==0) { func_021B9C90((u8 *)p); p->sentinel=255; }
    }
    func_021BA0C8((u8 *)p,10);
    if(p->busy==1 && func_0201C6B4((const struct PrintSys *)P(0x18e8))==1) {
        p->busy=0; desc=(u8 *)p->window;
        func_02045334(desc); func_02045374(desc); func_02041B6C(func_02045730(desc));
        func_0204047C(4,1); func_0204047C(5,2); func_0204047C(6,3); func_0204047C(7,0);
    }
    func_021BA0C8((u8 *)p,12);
    if(P(0x18e8)!=0) func_0201C4E4((struct PrintSys *)P(0x18e8));
    func_021BA0C8((u8 *)p,14);
    if(H(0x18c2)!=0) H(0x18c2)--;
    if(*(u32 *)P(4)!=0 && W(0x0c)!=7 && W(0x0c)!=8 && W(0x0c)!=9) {
        func_021BA0C8((u8 *)p,32);
        if(func_0200FB24()!=0) {
            func_021BA0C8((u8 *)p,34); func_0202208C(0,0,0,0x7fff,18,1,H(0)); func_02005E30(60);
            func_021BA0C8((u8 *)p,36); W(0x0c)=9; func_021BA0C8((u8 *)p,38);
        } else func_021BA0C8((u8 *)p,64);
    }
    func_021BA0C8((u8 *)p,16);
    return 0;
}

void func_021B6884(void *unused, u8 *p)
{
    u32 height, width;
    u16 sizes[2];
    int changed;
    u8 *e, *q, *r;
    u8 *table;
    int flags;
    u16 index;
    e = func_021BA184(*(void **)(p + 0x181c));
    changed = 0;
    while (e) {
        func_021BA218(e);
        q = (u8 *)func_021BA20C(e);
        r = (u8 *)func_021BA214(e);
        if (*(u16 *)q != *(u16 *)r) {
            func_021BA1EC(e, *(void **)(p + 0x1884), r);
            changed = 1;
        }
        e = (u8 *)func_021BA208(e);
    }
    if (changed == 1) func_021B7A18(p);
    if (*(u8 **)(p + 0x38)) {
        q = (u8 *)func_021BA20C(*(u8 **)(p + 0x38));
        if (*(u16 *)(p + 0x50) != *(u16 *)q) {
            table = (u8 *)func_021F4F10(*(u8 **)(p + 0x1884));
            *(u16 *)(p + 0x50) = *(u16 *)q;
            func_0204F32C((int)(*(void **)(p + 0x188c)), *(int *)(p + 0x54), (int)(&height));
            func_0204F2E4(*(u8 **)(p + 0x188c), *(int *)(q + 4), &width);
            func_0204F2FC(*(void **)(p + 0x188c), *(int *)(p + 0x54), width);
            flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + 0x50)));
            func_0204EDD0(flags, &sizes[1], &sizes[0]);
            index = func_0204F044(*(void **)(p + 0x188c), width, height, 0, flags, sizes[1], sizes[0]);
            func_021F4D74(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), *(u16 *)(p + 0x50), index);
            func_0204F1A0(*(void **)(p + 0x188c), *(u32 *)(p + 0x54));
            *(u32 *)(p + 0x54) = index;
        }
    }
    func_0204A648();
    func_021F4AA4(*(void **)(p + 0x1884));
}

static inline void visible_main(int plane)
{
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0x1f00u) | (plane << 8));
}

static inline void visible_sub(int plane)
{
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0x1f00u) | (plane << 8));
}

static inline void select_display(DispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000u) | (sel << 15));
}

void func_021B69AC(u8 *p)
{
    Config cfg, board;
    func_020434CC(); func_02043588();
    visible_main(0);
    visible_sub(0);
    func_0202223C(0,0); func_0202223C(1,0);
    func_02022224(0); func_02022224((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    select_display(DISP_SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021BA518);
    func_02046440(0,2,0,1,0,*(u16 *)p,0);
    func_02046BE0(0,1);
    *(u32 **)(p+0x1888) = func_02048A24(2,0xc000,0,0,0x10000,0x1000,0x3e8000,0,&d_021BA3F4,&d_021BA40C,&d_021BA400,*(u16 *)p);
    func_02048AD0(*(void **)(p+0x1888));
    func_0207DCF8(d_021BA418);
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    func_02046BE0(0,0);
    func_0203F8F4(*(u16 *)p); func_02045088(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021BA428); func_0204044C(1);
    func_021B6E4C(d_021BA438,1); func_021B6E4C(d_021BA458,2);
    func_021B6E4C(d_021BA478,3); func_021B6E4C(d_021BA4F8,7);
    func_021B6E4C(d_021BA498,4); func_021B6E4C(d_021BA4B8,5); func_021B6E4C(d_021BA4D8,6);
    func_02040588(0,1);
    func_0207D63C((void *)0x04001050,0,15,4,16);
    cfg = d_020A1448;
    cfg.a = 16; cfg.b = 112;
    func_0204A48C((const struct Cfg *)(&cfg),(u32)d_021BA518,*(u16 *)p);
    func_020434DC(16,1); func_02043598(16,1);
    *(void **)(p+0x1848) = func_0204B100(24,0,*(u16 *)p);
    func_0204B270(*(void **)(p+0x1848));
    board = d_021BA5C4;
    *(void **)(p+0x188c) = func_0204EBD4((u8 *)&board,(void *)*(u16 *)p);
}
