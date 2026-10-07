/*
 * file:     dup_fitting_item_p10.c
 * unit:     yes
 * function: func_021B98A0, func_021B9990, func_021B9A88, func_021B9AC0, func_021B9B48, func_021B9BD0, func_021B9C08, func_021B9C90, func_021B9CBC, func_021B9D54, func_021B9DE8, func_021B9F24, func_021B9F5C, func_021BA098, func_021BA0C8, func_021BA0CC, func_021BA0F8, func_021BA100, func_021BA124, func_021BA148, func_021BA184, func_021BA188, func_021BA18C, func_021BA19C, func_021BA1D8, func_021BA1EC, func_021BA208, func_021BA20C, func_021BA210, func_021BA214, func_021BA218, func_021BA21C, func_021BA228, func_021BA22C, func_021BA238, func_021BA23C, func_021BA240, func_021BA244, func_021BA248, func_021BA24C, func_021BA250, func_021BA254, func_021BA258, func_021BA25C
 * address:  0x021B98A0
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
 *   func_021B987C 0x021B987C thumb ov133
 *   func_0204B404 0x0204B404 arm
 *   func_021B75E0 0x021B75E0 thumb ov133
 *   a1 0x021BA558 data a4
 *   b1 0x021BA560 data a4
 *   a2 0x021BA550 data a4
 *   b2 0x021BA548 data a4
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B765C 0x021B765C thumb ov133
 *   table 0x020A1B38 data a2
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffixu 0x0209C4C8 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F5158 0x021F5158 thumb ov112
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020416D4 0x020416D4 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_02030734 0x02030734 arm
 *   d_021BA610 0x021BA610 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_021F4C1C 0x021F4C1C thumb ov112
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4D74 0x021F4D74 thumb ov112
 *   func_021F4F04 0x021F4F04 thumb ov112
 *   func_021F4EFC 0x021F4EFC thumb ov112
 *   func_021F4EE0 0x021F4EE0 thumb ov112
 *   _ffix 0x0209C494 arm
 *   d_020A1B38 0x020A1B38 data a4
 */
#include "../../matched/include/Obj00228.h"
#include "../../matched/include/Obj02197.h"
#include "../../matched/include/Obj06501.h"
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj23324.h"
#include "../../matched/include/Obj23325.h"
#include "../../matched/include/Obj14153.h"
#include "../../matched/include/Obj01062.h"
#include "../../matched/include/Obj14154.h"
#include "../../matched/include/Obj06502.h"
#include "../../matched/include/Obj10572.h"
#include "../../matched/include/Obj06503.h"
#include "../../matched/include/Obj04523.h"
#include "../../matched/include/Obj05410.h"
#include "../../matched/include/Obj23326.h"
#include "../../matched/include/Obj03827.h"
#include "../../matched/include/Obj14155.h"
#include "../../matched/include/Obj06504.h"
#include "../../matched/include/Obj06505.h"
#include "../../matched/include/Obj23327.h"
#include "../../matched/include/Obj23328.h"
#include "../../matched/include/Obj14156.h"
#include "../../matched/include/Obj14157.h"
#include "../../matched/include/Obj23329.h"
#include "../../matched/include/Obj14158.h"
#include "../../matched/include/Obj14159.h"
#include "../../matched/include/Obj23330.h"
#include "../../matched/include/Obj23331.h"
#include "../../matched/include/Obj23332.h"
#include "../../matched/include/Obj23333.h"
#include "../../matched/include/Obj23334.h"
#include "../../matched/include/Obj23335.h"
#include "../../matched/include/Obj23336.h"
#include "../../matched/include/Obj23337.h"
#include "../../matched/include/Obj23338.h"
#include "../../matched/include/Obj23339.h"
#include "../../matched/include/Obj23340.h"
#include "../../matched/include/Obj23341.h"
#include "../../matched/include/Obj23342.h"
#include "../../matched/include/Obj04524.h"

struct Obj;
struct Vec2;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct WordSet;
struct Actor;
struct Object;
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B98A0;

typedef struct {int x,y;} Pair_021B98A0;

typedef struct {s16_021B98A0 x,y;} Pos_021B98A0;

typedef unsigned int   u32;

typedef short s16_021B9990;

typedef short s16_021B9DE8;

typedef struct {s16_021B9DE8 x,y,index;u8 a,b;} Params;

typedef unsigned long long u64;

typedef short s16_021B9F5C;

typedef struct { s16_021B9F5C x, y; } Pos_021B9F5C;

typedef struct {short x,y;} Pos_021BA098;

typedef signed char s8;

typedef signed short s16_021BA18C;

typedef signed int s32;

typedef struct {u32 a,b;} Pair_021BA21C;

typedef struct {u32 a,b;} Pair_021BA22C;

typedef short s16_021BA25C;

typedef struct { int x, y; } Offset;

typedef struct { u16 lo : 2; u16 flag : 1; u16 hi : 13; } Flags;

extern void func_021B987C(u8 *);
extern void func_021B75E0(u8 *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_021B765C(u8 *p, u16 base, s16_021B9990 speed, u16 rx, u16 ry);
extern int _s32_div_f(int,int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern u32 func_0201C440(void *p);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045C04(void *);
extern void func_0201D83C(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EEF4(void *,unsigned int,void *);
extern void func_0201ED04(void *);
extern unsigned int func_021F4F10(u8 *p);
extern u8 func_021F5158(void *, int);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern u8 func_020416D4(u32);
extern void func_0204B84C(void *, u32);
extern u32 func_0203F0A8(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B9A0(struct Actor*);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern u32 func_020307B0(void *p);
extern struct Entry *func_021F4C1C(struct Object*,int,u32,int*);
extern void func_021F4D40(u8*,u8*);
extern void func_021F4D74(u8*,u8*,int,u16);
extern void func_021F4F04(u8 *, Offset *);
extern int func_021F4EFC(int, Flags *);
extern void func_021F4EE0(int, u16 *, u16 *);
void func_021B98A0(u8 *p);
void func_021B9990(u8 *p,u16 a,int delta,u16 duration);
void func_021B9A88(unsigned char *p,unsigned int limit);
void func_021B9AC0(u8 *p, int *a, int *b, u16 duration);
void func_021B9B48(u8 *p);
void func_021B9BD0(unsigned char *p);
void func_021B9C08(u8 *p, unsigned int index, void *object);
void func_021B9C90(unsigned char *p);
void func_021B9CBC(u8 *p, u8 *entry);
void func_021B9D54(u8 *p, int state);
void func_021B9DE8(u8 *p);
void func_021B9F24(unsigned char *p);
void func_021B9F5C(u8 *p);
void func_021BA098(u8*p);
void func_021BA0C8(void);
u8 *func_021BA0CC(u16 heap, int n);
void func_021BA0F8(void *p);
void func_021BA100(u8*p,u8*q);
void func_021BA124(u8*p,u8*q);
void func_021BA148(u8*p,u8*q);
void *func_021BA184(char *p);
unsigned short func_021BA188(char *p);
int func_021BA18C(char *p);
u8 *func_021BA19C(u16 heap, struct Object*q, u8*r, int*v);
void func_021BA1D8(u8*p,u8*q);
void func_021BA1EC(u8*p,u8*q,u8*r);
u32 func_021BA208(u8 *p);
u32 func_021BA20C(u8 *p);
void func_021BA210(u8 *p, u32 value);
u32 func_021BA214(u8 *p);
u32 func_021BA218(u8 *p);
void func_021BA21C(u8 *p, const u8 *src);
u8 * func_021BA228(u8 *p);
void func_021BA22C(u8 *p, const u8 *src);
u8 * func_021BA238(u8 *p);
void func_021BA23C(u8 *p, u32 value);
u32 func_021BA240(u8 *p);
void func_021BA244(u8 *p, u32 value);
int func_021BA248(char *p);
void func_021BA24C(char *p, u32 v);
u16 func_021BA250(char *p);
void func_021BA254(char *p, int v);
u32 func_021BA258(char *p);
int func_021BA25C(u8 *p, int x, int y);
extern const Pair_021B98A0 a1,b1,a2,b2;
extern const s16_021B9990 table[];
extern const char d_021BA610[];
extern const s16_021BA25C d_020A1B38[];

void func_021B98A0(u8 *p)
{
    Pair_021B98A0 firstA,firstB,secondA,secondB;
    Pos_021B98A0 pos;
    switch(p[0x1846]) {
    case 0: break;
    case 1: func_021B9990(p,p[0x1847]*4681,p[0x1847]*4681,p[0x1847]*15); break;
    case 2: func_021B9A88(p,30); break;
    case 3: func_021B9990(p,-(u16)(p[0x1847]*4681),-(p[0x1847]*4681),p[0x1847]*15); break;
    case 4: func_021B9A88(p,30); break;
    case 5: firstA=a1; firstB=b1; func_021B9AC0(p,&firstA.x,&firstB.x,60); break;
    case 6: func_021B9A88(p,30); break;
    case 7: secondA=a2; secondB=b2; func_021B9AC0(p,&secondA.x,&secondB.x,60); break;
    case 8: func_021B9A88(p,30); break;
    case 9: func_021B987C(p); return;
    }
    pos.x=((struct Obj00228 *)p)->f1C; pos.y=((struct Obj00228 *)p)->f20;
    func_0204B404(((struct Obj00228 *)p)->f1854,(const struct Vec2 *)(&pos),0);
    func_021B75E0(p);
}

void func_021B9990(u8 *p,u16 a,int delta,u16 duration)
{
    int step,index;
    ((struct Obj00228 *)p)->f18=0;
    ((struct Obj00228 *)p)->f14=0;
    func_0204B3DC(((struct Obj00228 *)p)->f1854,1);
    step=_s32_div_f(delta,duration);
    index=((u16)((int)((unsigned)a-(unsigned)step*((struct Obj00228 *)p)->f1844+65536)%65536)>>4)*2;
    *(unsigned *)&((struct Obj00228 *)p)->f1C=(unsigned)((float)(72*table[index]+0x80000)/4096.0f);
    *(unsigned *)&((struct Obj00228 *)p)->f20=(unsigned)((float)(48*table[index+1]+0x50000)/4096.0f);
    ((struct Obj00228 *)p)->f182C-=(u16)step;
    func_021B765C(p,((struct Obj00228 *)p)->f182C,step,72,48);
    ++((struct Obj00228 *)p)->f1844;
    if(((struct Obj00228 *)p)->f1844>duration) {
        ((struct Obj00228 *)p)->f1844=0;
        ++p[0x1846];
    }
}

void func_021B9A88(unsigned char *p,unsigned int limit) {*(unsigned int *)&((struct Obj00228 *)p)->f18=0;*(unsigned int *)&((struct Obj00228 *)p)->f14=0;(((struct Obj00228 *)p)->f1844)++;func_0204B3DC(((struct Obj00228 *)p)->f1854,0);if(((struct Obj00228 *)p)->f1844>limit){((struct Obj00228 *)p)->f1844=0;(((struct Obj00228 *)p)->f1846)++;}}

void func_021B9AC0(u8 *p, int *a, int *b, u16 duration)
{
    int x, y;
    int count;
    ((struct Obj00228 *)p)->f18 = 1;
    if (((struct Obj00228 *)p)->f1844 == 0) ((struct Obj00228 *)p)->f14 = 1;
    else ((struct Obj00228 *)p)->f14 = 0;
    count = ((struct Obj00228 *)p)->f1844;
    y = a[1] + (b[1] - a[1]) * count / (int)duration;
    x = a[0] + (b[0] - a[0]) * count / (int)duration;
    ((struct Obj00228 *)p)->f1C = x;
    ((struct Obj00228 *)p)->f20 = y;
    func_0204B3DC(((struct Obj00228 *)p)->f1854, 1);
    (((struct Obj00228 *)p)->f1844)++;
    if (((struct Obj00228 *)p)->f1844 > duration) {
        ((struct Obj00228 *)p)->f1844 = 0;
        (((struct Obj00228 *)p)->f1846)++;
    }
}

void func_021B9B48(u8 *p)
{
    ((struct Obj02197 *)p)->f18E4 = func_0201D7EC(23, 0, 0, 0, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18D8 = func_02045B38(0, 2, 33, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18DC = func_02045B38(0, 2, 79, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18E0 = func_02045B38(0, 2, 75, ((struct Obj02197 *)p)->f0);
    func_02049B40(23, 5, 4, 448, 32, ((struct Obj02197 *)p)->f0);
    ((struct Obj02197 *)p)->f18E8 = (void *)func_0201C440((void *)(((struct Obj02197 *)p)->f0));
    func_0201F5BC(7, 128, 12, 0, ((struct Obj02197 *)p)->f0);
}

void func_021B9BD0(unsigned char *p) {func_0201C4C0(((struct Obj06501 *)p)->f18E8);func_02045C04(((struct Obj06501 *)p)->f18DC);func_02045C04(((struct Obj06501 *)p)->f18E0);func_02045C04(((struct Obj06501 *)p)->f18D8);func_0201D83C(((struct Obj06501 *)p)->f18E4);}

void func_021B9C08(u8 *p, unsigned int index, void *object)
{
    void *text = func_02045EC0(((struct Obj00004 *)p)->f18D8, index);
    void *copy;
    func_0201C6EC(((struct Obj00004 *)p)->f18E8);
    func_02043B5C(func_02045770(((struct Obj00004 *)p)->f18EC), 15);
    if (object) {
        copy = func_020457B0(128, ((struct Obj00004 *)p)->f0);
        func_0201F250(object, copy, text);
        func_02045808(text);
        text = copy;
    }
    func_0201C724(((struct Obj00004 *)p)->f18E8, (u32)func_02045770(((struct Obj00004 *)p)->f18EC), 2, 2, (u32)text, (u32)(((struct Obj00004 *)p)->f18E4), 1088);
    func_02045808(text);
    *(int *)&((struct Obj00004 *)p)->f18CC = 1;
}

void func_021B9C90(unsigned char *p) {void *r=func_0201EC64(((struct Obj00004 *)p)->f0);func_0201EEF4(r,0,((struct Obj23325 *)(*(unsigned char * *)&((struct Obj23324 *)(*(unsigned char * *)&((struct Obj00004 *)p)->f4))->f4))->f4);func_021B9C08(p,0,r);func_0201ED04(r);}

void func_021B9CBC(u8 *p, u8 *entry)
{
    void *manager = (void *)func_021F4F10(*(u8 * *)&((struct Obj00004 *)p)->f1884);
    u8 *data = (u8 *)func_021BA20C(entry);
    int index = func_021F5158(manager, ((struct Obj14153 *)data)->f0);
    void *obj = func_0201EC64(((struct Obj00004 *)p)->f0);
    void *a = func_02045EC0(((struct Obj00004 *)p)->f18DC, ((struct Obj14153 *)data)->f0 + 3);
    void *b = func_02045EC0(((struct Obj00004 *)p)->f18E0, index + 16);
    func_0201EE0C(obj, 0, a, 0, 1, 2);
    func_0201EE0C(obj, 1, b, 0, 1, 2);
    func_021B9C08(p, 3, obj);
    func_02045808(b);
    func_02045808(a);
    func_0201ED04(obj);
}

void func_021B9D54(u8 *p, int state)
{
    int index;
    void *w;
    void *str;
    if (state == 8) {
        func_021B9C08(p, 5, 0);
        return;
    }
    index = 0;
    switch (state) {
    case 0:
    case 1: index = 0x10; break;
    case 2: index = 0x11; break;
    case 3: index = 0x17; break;
    case 4: index = 0x14; break;
    case 5: index = 0x15; break;
    case 6:
    case 7: index = 0x16; break;
    }
    w = func_0201EC64(((struct Obj00004 *)p)->f0);
    str = func_02045EC0(((struct Obj00004 *)p)->f18E0, index);
    func_0201EE0C(w, 0, str, 0, 1, 2);
    func_021B9C08(p, 4, w);
    func_02045808(str);
    func_0201ED04(w);
}

void func_021B9DE8(u8 *p)
{
    Params configs[2];
    int a,b,c,d,e,f,g,h;
    u8 i;
    i=0;
    a=0x1860;
    b=0x186c;
    c=0x1878;
    d=0x1890;
    e=0x1890;
    f=0x1890;
    g=0x1890;
    h=0x18b8;
    do {
        configs[1].x=0;configs[1].y=0;configs[1].index=0;configs[1].a=0;configs[1].b=0;
        *(void **)(p+(unsigned)i*4+d)=func_0204B294((void *)((struct Obj01062 *)p)->f1848,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&configs[1],1,((struct Obj01062 *)p)->f0);
        func_0204B3DC(*(void **)(p+(unsigned)i*4+e),1);
        func_0204B92C(*(void **)(p+(unsigned)i*4+f),1);
        func_0204B688(*(void **)(p+(unsigned)i*4+g),0);
        p[(unsigned)i+h]=0;
        ++i;
    } while(i<8);
    configs[0].x=128;configs[0].y=96;configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct Obj01062 *)p)->f18B0=func_0204B294((void *)((struct Obj01062 *)p)->f1848,((struct Obj01062 *)p)->f185C,((struct Obj01062 *)p)->f1868,((struct Obj01062 *)p)->f1874,&configs[0],0,((struct Obj01062 *)p)->f0);
    func_0204B3DC(((struct Obj01062 *)p)->f18B0,0);
    func_0204B92C(((struct Obj01062 *)p)->f18B0,1);
    configs[0].index=2;
    ((struct Obj01062 *)p)->f18B4=func_0204B294((void *)((struct Obj01062 *)p)->f1848,((struct Obj01062 *)p)->f185C,((struct Obj01062 *)p)->f1868,((struct Obj01062 *)p)->f1874,&configs[0],0,((struct Obj01062 *)p)->f0);
    func_0204B3DC(((struct Obj01062 *)p)->f18B4,0);
    func_0204B92C(((struct Obj01062 *)p)->f18B4,1);
}

void func_021B9F24(unsigned char *p) {unsigned char i;for(i=0;i<8;i++)func_0204B3B4(*(void **)((unsigned int)p+(unsigned int)i*4+0x1890));func_0204B3B4(((struct Obj14154 *)p)->f18B4);func_0204B3B4(((struct Obj14154 *)p)->f18B0);}

/*
 * lever: Pointer addition for timer stores and unsigned address addition for the guard preserve four independent offset homes and the decrement reload. Uniform integer addition gave 292 bytes; uniform pointer addition gave 304.
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`a = 0x1890;` before `a = 0x18b8;`; `b = 0x1890;` before `b = 0x18b8;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021B9F5C(u8 *p)
{
    int a, b, delay, c, d;
    Pos_021B9F5C pos;
    u8 i;
    u8 *q, *t;
    a = 0x18b8;
    b = 0x18b8;
    delay = 0x190;
    c = 0x18b8;
    d = 0x18b8;
    for (i = 0; i < 8; i++) {
        q = p + i * 4;
        func_0204B84C(((struct Obj06502 *)q)->f1890, func_020416D4(4));
        func_0204B688(((struct Obj06502 *)q)->f1890, 0);
        t = p + i;
        if (*(u8 *)((u32)p+(u32)i+(u32)d) == 0) {
            pos.x = ((u64)func_0203F0A8() * 56) >> 32;
            if ((u32)(((u64)func_0203F0A8() * 2) >> 32) == 1) pos.x = 256 - pos.x;
            pos.y = ((u64)func_0203F0A8() * 192) >> 32;
            func_0204B404(((struct Obj06502 *)q)->f1890, (const struct Vec2 *)(&pos), 1);
            if (pos.y > 90) func_0204B878(((struct Obj06502 *)q)->f1890, ((u64)func_0203F0A8() * 2) >> 32);
            else func_0204B878(((struct Obj06502 *)q)->f1890, (((u64)func_0203F0A8() * 2) >> 32) + 2);
            t[c] = (((u64)func_0203F0A8() * 200) >> 32) + delay;
        } else {
            t[b] = t[a] - 1;
        }
    }
    if (func_0204B3F4(((struct Obj10572 *)p)->f18B4) == 1 && func_0204B98C(((struct Obj10572 *)p)->f18B4) == 0) {
        func_0204B3DC(((struct Obj10572 *)p)->f18B4, 0);
    }
}

void func_021BA098(u8*p){Pos_021BA098 pos;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;func_0204B9A0(*(struct Actor* *)&((struct Obj00004 *)p)->f18B4);func_0204B3DC(*(void* *)&((struct Obj00004 *)p)->f18B4,1);func_0204B404(*(void* *)&((struct Obj00004 *)p)->f18B4,(const struct Vec2 *)(&pos),0);}

void func_021BA0C8(void){}

u8 *func_021BA0CC(u16 heap, int n){u8 *p;p=func_02030734(heap,16,0,d_021BA610,76);((struct Obj06503 *)p)->f0=heap;((struct Obj06503 *)p)->f4=0;((struct Obj06503 *)p)->f6=n;((struct Obj06503 *)p)->f8=0;((struct Obj06503 *)p)->fC=0;return p;}

void func_021BA0F8(void *p){func_020307B0(p);}

void func_021BA100(u8*p,u8*q){if(((struct Obj04523 *)p)->f4<((struct Obj04523 *)p)->f6){if(!*(u8* *)&((struct Obj04523 *)p)->f8)*(u8* *)&((struct Obj04523 *)p)->f8=q;else *(u8* *)&((struct Obj23326 *)(*(u8* *)&((struct Obj04523 *)p)->fC))->f30=q;*(u8* *)&((struct Obj04523 *)p)->fC=q;*(u8* *)&((struct Obj05410 *)q)->f30=0;(((struct Obj04523 *)p)->f4)++;}}

void func_021BA124(u8*p,u8*q){if(((struct Obj03827 *)p)->f4<((struct Obj03827 *)p)->f6){if(!*(u8* *)&((struct Obj03827 *)p)->f8){*(u8* *)&((struct Obj03827 *)p)->f8=q;*(u8* *)&((struct Obj03827 *)p)->fC=q;*(u8* *)&((struct Obj14155 *)q)->f30=0;}else{*(u8* *)&((struct Obj14155 *)q)->f30=*(u8* *)&((struct Obj03827 *)p)->f8;*(u8* *)&((struct Obj03827 *)p)->f8=q;}(((struct Obj03827 *)p)->f4)++;}}

void func_021BA148(u8*p,u8*q){u8 *prev;u8 *cur;prev=0;cur=*(u8* *)&((struct Obj06504 *)p)->f8;while(cur!=q && cur){prev=cur;cur=*(u8* *)&((struct Obj06505 *)cur)->f30;}if(cur){if(prev)*(u8* *)&((struct Obj06505 *)prev)->f30=*(u8* *)&((struct Obj06505 *)cur)->f30;else *(u8* *)&((struct Obj06504 *)p)->f8=*(u8* *)&((struct Obj06505 *)cur)->f30;if(*(u8* *)&((struct Obj06504 *)p)->fC==q)*(u8* *)&((struct Obj06504 *)p)->fC=prev;*(u8* *)&((struct Obj06505 *)cur)->f30=0;(((struct Obj06504 *)p)->f4)--;}}

void *func_021BA184(char *p){return *(void* *)&((struct Obj23327 *)p)->f8;}

unsigned short func_021BA188(char *p){return ((struct Obj23328 *)p)->f4;}


int func_021BA18C(char *p)
{
    return ((struct Obj14156 *)p)->f4 == ((struct Obj14156 *)p)->f6;
}

u8 *func_021BA19C(u16 heap, struct Object*q, u8*r, int*v){u8*p;p=func_02030734(heap,52,0,d_021BA610,204);*(u32 *)&((struct Obj05410 *)p)->f30=0;*(u8* *)&((struct Obj05410 *)p)->f4=r;*(struct Entry* *)&((struct Obj05410 *)p)->fC=func_021F4C1C(q,((struct Obj14157 *)r)->f0,((struct Obj14157 *)r)->f4,v);((struct Obj05410 *)p)->f1C=0;((struct Obj05410 *)p)->f20=10;return p;}

void func_021BA1D8(u8*p,u8*q){func_021F4D40(q,*(u8* *)&((struct Obj23329 *)p)->fC);func_020307B0(p);}

void func_021BA1EC(u8*p,u8*q,u8*r){*(u8* *)&((struct Obj14158 *)p)->f4=r;func_021F4D74(q,*(u8* *)&((struct Obj14158 *)p)->fC,((struct Obj14159 *)r)->f0,((struct Obj14159 *)r)->f4);}

u32 func_021BA208(u8 *p)
{
    return ((struct Obj23330 *)p)->f30;
}

u32 func_021BA20C(u8 *p)
{
    return ((struct Obj23331 *)p)->f4;
}

void func_021BA210(u8 *p, u32 value)
{
    ((struct Obj23332 *)p)->f8=value;
}

u32 func_021BA214(u8 *p)
{
    return ((struct Obj23333 *)p)->f8;
}

u32 func_021BA218(u8 *p)
{
    return ((struct Obj23334 *)p)->fC;
}

void func_021BA21C(u8 *p, const u8 *src)
{
    *(Pair_021BA21C *)(p+16)=*(const Pair_021BA21C *)src;
}

u8 * func_021BA228(u8 *p)
{
    return p+16;
}

void func_021BA22C(u8 *p, const u8 *src)
{
    *(Pair_021BA22C *)(p+36)=*(const Pair_021BA22C *)src;
}

u8 * func_021BA238(u8 *p)
{
    return p+36;
}

void func_021BA23C(u8 *p, u32 value)
{
    ((struct Obj23335 *)p)->f2C=value;
}

u32 func_021BA240(u8 *p)
{
    return ((struct Obj23336 *)p)->f2C;
}

void func_021BA244(u8 *p, u32 value)
{
    ((struct Obj23337 *)p)->f18=value;
}

int func_021BA248(char *p) { return ((struct Obj23338 *)p)->f18; }

void func_021BA24C(char *p, u32 v) { ((struct Obj23339 *)p)->f1C=v; }

u16 func_021BA250(char *p) { return ((struct Obj23340 *)p)->f1C; }

void func_021BA254(char *p, int v) { ((struct Obj23341 *)p)->f20=v; }

u32 func_021BA258(char *p) { return ((struct Obj23342 *)p)->f20; }

int func_021BA25C(u8 *p, int x, int y)
{
    s16_021BA25C s;
    int pos[2];
    u16 angle;
    s16_021BA25C c;
    int dx, dy;
    s16_021BA25C rx, ry;
    func_021F4F04(((struct Obj04524 *)p)->fC, (Offset *)pos);
    if (func_021F4EFC(0, ((struct Obj04524 *)p)->fC) == 1) {
        func_021F4EE0(0, ((struct Obj04524 *)p)->fC, &angle);
        s = d_020A1B38[(angle >> 4) * 2];
        c = d_020A1B38[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct Obj04524 *)p)->f10 - dx - x;
        ry = ((struct Obj04524 *)p)->f14 - dy - y;
    } else {
        rx = ((struct Obj04524 *)p)->f10 - x;
        ry = ((struct Obj04524 *)p)->f14 - y;
    }
    if (rx < 16 && rx > -16 && ry < 16 && ry > -16) return 1;
    return 0;
}
