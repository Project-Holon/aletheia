/*
 * file:     mystery_net_p03.c
 * unit:     yes
 * function: func_021DDC58, func_021DDCF8, func_021DDD64, func_021DDF5C, func_021DDF84, func_021DE014, func_021DE024, func_021DE0AC, func_021DE0DC, func_021DE128, func_021DE154, func_021DE2A0, func_021DE2F0, func_021DE300, func_021DE308, func_021DE3E0, func_021DE4DC, func_021DE500, func_021DE550, func_021DE570, func_021DE5D8, func_021DE5F8, func_021DE618, func_021DE61C, func_021DE690, func_021DE6F8, func_021DE70C, func_021DE7BC, func_021DE7FC, func_021DE830, func_021DE8D0, func_021DE910, func_021DE958, func_021DEDC8, func_021DEE14, func_021DEE38, func_021DEE68, func_021DEE84, func_021DEE90, func_021DEEA4, func_021DEEAC, func_021DEED0, func_021DEEF8, func_021DEF38, func_021DEF54, func_021DEF6C
 * address:  0x021DDC58
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DC064 0x021DC064 thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 *   func_021DBF10 0x021DBF10 thumb ov121
 *   func_021DBF40 0x021DBF40 thumb ov121
 *   func_021DBF9C 0x021DBF9C thumb ov121
 *   func_021DBF70 0x021DBF70 thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_02082A48 0x02082A48 arm
 *   func_0204B5F4 0x0204B5F4 arm
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021DDC30 0x021DDC30 arm ov121
 *   func_021DDC44 0x021DDC44 arm ov121
 *   func_02082A60 0x02082A60 arm
 *   func_021DA4A8 0x021DA4A8 thumb ov121
 *   func_021DA318 0x021DA318 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020414EC 0x020414EC arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021DF858 0x021DF858 data a2
 *   d_021DF822 0x021DF822 data a1
 *   d_021DF82D 0x021DF82D data a1
 *   d_021DF944 0x021DF944 data a4
 *   _s32_div_f 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02030734 0x02030734 arm
 *   d_021DFBC0 0x021DFBC0 data ov121 a1
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D798 0x0203D798 arm
 *   func_020103E4 0x020103E4 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CA98 0x0203CA98 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_02059F18 0x02059F18 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_0200FA84 0x0200FA84 thumb
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02010360 0x02010360 thumb
 *   func_0203D010 0x0203D010 arm
 *   d_021DFABC 0x021DFABC data a4
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02010498  0x02010498  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_021576D0 0x021576D0 thumb ov010
 *   func_021578A0 0x021578A0 thumb ov010
 *   d_0209DF0C 0x0209DF0C data
 *   func_02157938 0x02157938 thumb ov010
 *   func_0203D210 0x0203D210 arm
 *   func_02157928 0x02157928 thumb ov010
 *   func_02157910 0x02157910 thumb ov010
 *   func_02157DD8 0x02157DD8 thumb ov010
 *   func_02157E34 0x02157E34 thumb ov010
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_02157E78 0x02157E78 thumb ov010
 *   func_02157E6C 0x02157E6C thumb ov010
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021C5928 0x021C5928 arm ov114
 *   func_021C5C04 0x021C5C04 arm ov114
 *   func_021C5C38 0x021C5C38 arm ov114
 *   func_021C5CFC 0x021C5CFC arm ov114
 *   func_021C5AB8 0x021C5AB8 arm ov114
 *   func_021C5E14 0x021C5E14 arm ov114
 *   func_021C5DB4 0x021C5DB4 arm ov114
 *   func_0203F0A8 0x0203F0A8 arm
 *   func_0203C9AC 0x0203C9AC arm
 *   _ull_mul 0x0209C054 arm
 *   d_021DFBD8 0x021DFBD8 data a4
 *   d_021DFBD0 0x021DFBD0 data a4
 *   d_021DFBF8 0x021DFBF8 data a4
 *   d_021DFBEC 0x021DFBEC data a4
 *   d_021DFC00 0x021DFC00 data a4
 *   func_021C5B80 0x021C5B80 arm ov114
 *   d_021DFA8C 0x021DFA8C data a1
 *   func_02045A98 0x02045A98 arm
 *   func_021DEFAC 0x021DEFAC thumb ov121
 */
#include "../../matched/include/Obj10421.h"
#include "../../matched/include/Obj22908.h"
#include "../../matched/include/Obj01931.h"
#include "../../matched/include/Obj22910.h"
#include "../../matched/include/Obj22911.h"
#include "../../matched/include/Obj08098.h"
#include "../../matched/include/Obj08099.h"
#include "../../matched/include/Obj13959.h"
#include "../../matched/include/Obj22912.h"
#include "../../matched/include/Obj22913.h"
#include "../../matched/include/Obj10422.h"
#include "../../matched/include/Obj22914.h"
#include "../../matched/include/Obj10424.h"
#include "../../matched/include/Obj08100.h"
#include "../../matched/include/Obj22915.h"
#include "../../matched/include/Obj08101.h"
#include "../../matched/include/Obj22916.h"
#include "../../matched/include/Obj10427.h"
#include "../../matched/include/Obj06455.h"
#include "../../matched/include/Obj22917.h"
#include "../../matched/include/Obj08102.h"
#include "../../matched/include/Obj22918.h"
#include "../../matched/include/Obj08104.h"
#include "../../matched/include/Obj22920.h"
#include "../../matched/include/Obj13960.h"
#include "../../matched/include/Obj22922.h"
#include "../../matched/include/Obj22925.h"

#define Q(k) (*(u32 *)(q+(k)))
#define W(k) (*(u32 *)(p+(k)))
struct Obj;
struct Actor;
struct Req;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef struct {s16 x,y;} Point_021DDC58;

typedef struct { u16 x,y; } Point_021DE0DC;

typedef signed char s8;

typedef struct { int x, y; } Pair;

typedef struct {
    u16 value, previous, next;
    s8 direction;
    u8 state;
    u16 index, count;
    u32 frame, frames;
    int startx, starty;
    Pair target, current;
} State;

typedef signed int     s32;

typedef struct { u32 kind;u8 flag,pad;u16 heap;u32 bytes;void *data;u32 lang,align;u8 reserved[96];u32 last;} Config;

typedef struct Descriptor {
    int kind;
    u16 zero, heap;
    int size;
    void *data;
    int setting;
    int flags;
    u8 pad[0x60];
    int enabled;
} Descriptor;

typedef unsigned long long u64;

typedef struct { char pad[0x6e0];u32 flag; } Flag;

typedef enum { NO_DIGIT = -1 } Digit;

extern int func_021DC064(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void func_02049238(void *);
extern void *func_021DBF10(void *,u16);
extern u32 func_021DBF40(void *);
extern int func_021DBF9C(void *);
extern u32 func_021DBF70(void *);
extern int func_021DC024(void *);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204AA94(int,void *,u32,int,int);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(void *,const Point_021DDC58 *,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204ADEC(u32,void *,u32);
extern void func_02082A48(u32,void *,u32);
extern void func_0204B5F4(struct Actor *actor, u16 value);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0204B84C(void *,u8);
extern void func_021DDC30(int,int);
extern void func_021DDC44(int,int);
extern void func_02082A60(void *,const void *,int);
extern void func_021DA4A8(u8 *p);
extern void func_021DA318(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020056A0(u32,u32,u32);
extern void func_020414EC(unsigned);
extern void func_02082BCC(void *,int,u32);
extern int _s32_div_f(int, int);
extern u32 _u32_div_f(u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_0203CD98(void);
extern char *func_0203D798(void);
extern void func_020103E4(u8 *);
extern void func_0200FBA0(void);
extern u32 func_0200FB24(void);
extern u32 func_0203CA98(void);
extern void func_0203CA04(void);
extern void func_02059F18(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
extern void func_0200FA84(void);
extern void func_0203CBAC(struct Req *req, unsigned int a2, unsigned int a3);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0203D34C(unsigned, unsigned);
extern u8 *func_02010360(int idx, void *heap);
extern void func_0203D010(void);
extern int func_0203CEAC(int);
extern void func_02010498(void);
extern u32 func_0201058C(void *key);
extern void *func_021576D0(u8 *p);
extern int func_021578A0(u32 *);
extern int func_02157938(void *a0);
extern unsigned func_0203D210(void);
extern void func_02157928(u8 *);
extern int func_02157910(u8 *);
extern void *func_02157DD8(u8 *p);
extern int func_02157E34(void *);
extern int func_02157E8C(void *a0);
extern void func_02157E78(u8 *p);
extern unsigned char func_02157E6C(char *p);
extern void func_02156DE0(int,int);
extern int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int func_021C5C04(char *,char *,char *);
extern int func_021C5C38(void *,u32,u32);
extern int func_021C5CFC(void *,char *,u32);
extern void func_021C5AB8(void);
extern int func_021C5E14(u32 *,u32 *);
extern int func_021C5DB4(void);
extern u32 func_0203F0A8(void);
extern void func_0203C9AC(int,u32,u32,u32);
extern int func_021C5B80(void);
extern unsigned short func_02045A98(void);
extern int func_021DEFAC(struct Rec *r, void *gs, u16 heap);
void func_021DDC58(const unsigned *p,void *context,u16 heap);
void func_021DDCF8(unsigned *p,void *context,u16 heap);
void func_021DDD64(char *p,char *q,u16 heap);
void func_021DDF5C(u8 *p);
void func_021DDF84(char *p);
int func_021DE014(char *p);
void func_021DE024(void *unused,char *p);
void func_021DE0AC(u8 *p,u32 b);
void func_021DE0DC(char *p);
void func_021DE128(u8 *p,u16 b,int c,int d);
int func_021DE154(State *p, u16 *out, Pair *position);
void *func_021DE2A0(void *arg,int heap);
void func_021DE2F0(u8 *p);
void func_021DE300(char *p);
void func_021DE308(char *p, unsigned action);
int func_021DE3E0(void *p);
void *func_021DE4D8(char *p);
int func_021DE4DC(u8 *p, void *a, u32 b);
int func_021DE500(void *p);
void func_021DE550(char *p);
int func_021DE570(char *p);
int func_021DE5D8(void *a0);
int func_021DE5F8(void *a0);
void func_021DE618(void);
void func_021DE61C(void *a, int *state, char *p);
void func_021DE690(void *a, int *state, char *p);
void func_021DE6F8(int a, int b, char *c);
void func_021DE70C(void *a,int *state,char *p);
void func_021DE7BC(void *a, int *state, char *p);
void func_021DE7FC(void *a,int b,char *p);
void func_021DE830(void *a, int *state, char *p);
void func_021DE8D0(void *a, int *state, char *p);
void func_021DE910(void *a, int *state, char *p);
void func_021DE958(void *task,int *state,char *p);
void func_021DEDC8(void *a, int *state, char *p);
void func_021DEE14(char *p, int *state, int value);
void func_021DEE38(u32 p,int a,int *state,int b,int c);
void func_021DEE68(void *p, int a, void *b);
void func_021DEE84(void *p);
void func_021DEE90(char *p);
void func_021DEEA4(u32 *p,void *f);
int func_021DEEAC(int *p, int value);
void *func_021DEEBC(char *p);
int func_021DEEC0(void);
int func_021DEEC4(int a, int b);
void func_021DEED0(char *p);
void func_021DEED8(int a, int b);
void func_021DEEEC(void);
int func_021DEEF8(const signed char *p);
int func_021DEF38(const unsigned *p, unsigned size);
int func_021DEF54(char *p, int unused, int type);
int func_021DEF6C(char *p, void *a, unsigned short b);
extern u16 d_021DF858[];
extern const s8 d_021DF822[];
extern s8 d_021DF82D[];
extern const Pair d_021DF944[];
extern const char d_021DFBC0[];
extern unsigned d_021DFABC[];
extern u8 d_0209DF0C;
extern char d_021DFBD8[],d_021DFBD0[],d_021DFBF8[],d_021DFBEC[];
extern int d_021DFC00[];
extern const signed char d_021DFA8C[][2];





/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: initialize resource after the first guard; const source orders loads before stack argument stores.
 */
void func_021DDC58(const unsigned *p,void *context,u16 heap)
{
    int which=0;
    int resource;
    u16 id;
    void *arc;
    if (p[0]>=4) which=4;
    resource=26;
    if (p[0]<=3) resource=27;
    id=func_021DC064(context);
    arc=func_020490F4(34,heap);
    func_02049BDC(arc,4,which,id*32,p[2]*32,32,heap);
    func_02049658(arc,13,p[0],0,0,0,heap);
    func_020498F4(arc,(u16)resource,p[0],0,0,0,heap);
    func_020413B0((u8)p[0],0,0,34,24,p[2]);
    func_020409B4((u8)p[0]);
    func_02049238(arc);
}





/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DDCF8(unsigned *p,void *context,u16 heap)
{
    int which=0;
    u16 id;
    void *arc;
    if (p[0]>=4) which=4;
    id=func_021DC064(context);
    arc=func_020490F4(34,heap);
    func_02049BDC(arc,4,which,id*32,p[2]*32,32,heap);
    func_020413B0((u8)p[0],0,0,34,24,p[2]);
    func_020409B4((u8)p[0]);
    func_02049238(arc);
}





static inline void *palette(u32 off, int mode)
{
    if (mode==0) return (void *)(off+0x05000200);
    else return (void *)(off+0x05000600);
}





/*
 * lever (wave 82, lane R10, retry): the palette base is an inline that adds
 *   the byte offset inside each arm (`if (mode==0) return off+0x05000200;
 *   else return off+0x05000600;`); the shared add cross-jumps into the
 *   `adds r1,r0,r1` join. A base-only inline plus `+ offset` at the call site,
 *   or a ternary on the base, if-converts to a default load plus override and
 *   misschedules the q+0xb0/q+0x98 loads (431 B). The heap stays u16 as in
 *   matched ov121 func_021DBF10 and matched caller func_021DE024: the earlier
 *   u32-heap owner gate does not apply.
 */
void func_021DDD64(char *p,char *q,u16 heap)
{
    void *arc;
    void *allocation;
    void *allocation2;
    void *res;
    void *res2;
    Point_021DDC58 pt;
    u16 *dest;
    u32 offset;
    int i;
    arc=func_021DBF10(p,heap);
    allocation=func_02049F78(arc,(int)func_021DBF40(p),(u32)(&res),(u16)(*(u16 *)(p+0x118)));
    offset=*(u32 *)(q+0xb0)*32;
    func_02082D44(*(void **)((char *)res+12),palette(offset,*(u32 *)(q+0x98)),96);
    func_020307B0(allocation);
    allocation2=func_02049E74(arc,(int)func_021DBF9C(p),(int)0,(u32)(&res2),*(u16 *)(p+0x118));
    func_0204AA94(*(int *)(q+8),*(void **)((char *)res2+20),512,0,*(int *)(q+0x98));
    func_020307B0(allocation2);
    func_02049238(arc);
    pt.x=216; pt.y=22;
    if (func_021DC024(p)==2) {pt.x+=4;pt.y+=8;}
    func_0204B6F4(*(void **)(q+28),(u8)func_021DBF70(p),0);
    func_0204B404(*(void **)(q+28), (const Point_021DDC58 *)&pt, *(u32 *)(q+0x98));
    func_0204B3DC(*(void **)(q+28),1);
    if (func_021DC024(p)==1) {
        func_0204ADEC(*(u32 *)(q+16),*(void **)(*(char **)(p+0x140)+12),1);
        func_02082D44(*(void **)(*(char **)(p+0x140)+12),q+0x64,32);
        func_02082A48(0,q+0x44,32);
        func_0204AA94(*(int *)(q+20),*(void **)(*(char **)(p+0x138)+20),0x1200,0,*(int *)(q+0x98));
        func_0204B5F4(*(void **)(q+32),0);
        func_0204B3DC(*(void **)(q+32),1);
        if (*(u32 *)(q+0xa0)<4) dest=(u16 *)((u32)func_0204AEF4(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000200);
        else dest=(u16 *)((u32)func_0204AEF4(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000600);
        for(i=0;i<16;i++) dest[i]=*(u16 *)(q+0x44+i*2);
        if (*(u32 *)(q+0xa0)<4)
            func_0207D63C((void *)0x04000050,0,(1<<(u8)*(u32 *)(q+0xa0))|(1<<(u8)*(u32 *)(q+0xa4)),2,12);
        else
            func_0207D63C((void *)0x04001050,0,(1<<(u8)(*(u32 *)(q+0xa0)-4))|(1<<(u8)(*(u32 *)(q+0xa4)-4)),2,12);
    } else func_0204B3DC(*(void **)(q+32),0);
}





void func_021DDF5C(u8 *p) { if(func_021DC024(p)==1 && ((struct Obj10421 *)p)->fDC==0) { ((struct Obj10421 *)p)->fDC=1; ((struct Obj10421 *)p)->fDE=0; } }





void func_021DDF84(char *p)
{
    char *palette;
    void (*blend)(int,int);
    if (func_021DC024(p)==1) {
        *(u16 *)(p+0xdc)=0;
        *(u16 *)(p+0xde)=0;
        func_0204B84C(*(void **)(*(char **)(p+0x11c)+0x20),*(unsigned *)(*(char **)(p+0x11c)+0x8c));
        if (*(int *)(*(char **)(p+0x11c)+0x84)) {
            palette=(char *)(func_0204AEF4((u32)(*(void **)(*(char **)(p+0x11c)+0x10)),*(int *)(*(char **)(p+0x11c)+0x98))+0x05000200);
            blend=func_021DDC30;
        } else {
            palette=(char *)(func_0204AEF4((u32)(*(void **)(*(char **)(p+0x11c)+0x10)),*(int *)(*(char **)(p+0x11c)+0x98))+0x05000600);
            blend=func_021DDC44;
        }
        blend(2,12);
        func_02082A48(0,*(char **)(p+0x11c)+0x44,32);
        func_02082A60(*(char **)(p+0x11c)+0x44,palette,32);
    }
}





int func_021DE014(char *p)
{
    if (((struct Obj22908 *)p)->fDC==0) return 1;
    return 0;
}





void func_021DE024(void *unused,char *p)
{
    if (((struct Obj01931 *)p)->f12C) return;
    ((struct Obj01931 *)p)->f12C=1;
    switch (((struct Obj01931 *)p)->f130) {
    case 0: func_021DDC58((unsigned *)(*(char * *)&((struct Obj01931 *)p)->f11C+0xa0),p,((struct Obj01931 *)p)->f118); break;
    case 1: func_021DDCF8((unsigned *)(*(char * *)&((struct Obj01931 *)p)->f11C+0xa0),p,((struct Obj01931 *)p)->f118); break;
    }
    func_021DDD64(p,((struct Obj01931 *)p)->f11C,((struct Obj01931 *)p)->f118);
    func_021DA4A8(((struct Obj01931 *)p)->f144);
    func_021DA318(**(void ** *)&((struct Obj01931 *)p)->f11C);
    func_02040588((u8)(((struct Obj22910 *)(*(char * *)&((struct Obj01931 *)p)->f11C))->f96),(int)1);
    func_02040588((u8)(((struct Obj22911 *)(*(char * *)&((struct Obj01931 *)p)->f11C))->f94),(int)1);
}





void func_021DE0AC(u8 *p,u32 b) { ((struct Obj08098 *)p)->f130=b; if(*(u32 *)&((struct Obj08098 *)p)->f128==0) ((struct Obj08098 *)p)->f128=func_020056A0((u32)func_021DE024,(u32)p,0); else ((struct Obj08098 *)p)->f12C=0; }




void func_021DE0DC(char *p)
{
    Point_021DE0DC pt;
    func_020414EC(4);
    func_020409B4(4);
    func_0204B3DC(((struct Obj08099 *)p)->f1C,0);
    pt.x=184;
    pt.y=112;
    func_0204B404(((struct Obj08099 *)p)->f20, (const Point_021DDC58 *)&pt, ((struct Obj08099 *)p)->f98);
    func_0204B3DC(((struct Obj08099 *)p)->f20,0);
    func_02040588(6,0);
}




/*
 * note pass 2 2026-10-06 P2L16: closed from 7/44. The function returns void (the only
 *   caller, ov121 021DD9CC, declares it void) and the +0 halfword is a direct copy
 *   `*(u16 *)p = *(u16 *)(p+2)` at its store position; the scheduler hoists the ldrh.
 *   The 11 store after the two b stores gives the image colours (b r7, c r4, d r6).
 *   The earlier u16 t local and return form stayed at 7 for every variant.
 */
void func_021DE128(u8 *p,u16 b,int c,int d)
{
    func_02082BCC(p,0,44);
    *(u16 *)(p+2)=b;
    *(u16 *)(p+4)=b;
    *(u16 *)(p+10)=11;
    *(int *)(p+20)=c;
    *(int *)(p+24)=d;
    *(int *)(p+28)=c;
    *(int *)(p+32)=d;
    *(u16 *)p=*(u16 *)(p+2);
    *(int *)(p+36)=c;
    *(int *)(p+40)=d;
}




#pragma opt_propagation off




/*
 * prior-checks: 1 runtime quotient helpers take two full-word arguments; no residual call setup; 2 ov121 search found no interpolation twin; 3 const char table reduced 13 to 9 bytes, State mutable and widths decoded from loads; 4 aggregate/cast/struct-copy idioms did not resolve residue; 5 fresh directory and ov121/ov122 neighbours reread, no stack aggregate residue.
 * budget: 8 iteration runs; first nonshrinking r3, 6 runs since, consecutive r6-r8=3; reorder/temporary cap 2/2; check 3 used 1/2; baseline emission check 1; once-only permuter 300 exhausted, no improvement.
 * residual: 332/332 bytes, 9 concrete bytes differ in scheduling at +0036..0040; seven relocations resolved by fixed one.
 * permuter: macro-free emitted baseline confirmed by fixed one; search best stayed 9 bytes, exit 1; no candidate accepted.
 * wave77-runs: const Pair table cast 9/332; const signed-byte tables 9/332; direct target member assignment 9/332; check3 State *const 9/332. Three consecutive nonshrinking changes; four fixed one runs; prior 300 search not repeated.
 * checks: 1 runtime helpers remain two word arguments; 2 DE308 and sibling table callers refreshed, no interpolation twin; 3 named u16 index and State *const compiled flat9; 4 long-index/coordinate-copy scheduling idioms read; 5 fresh full directory plus DE2F0/DE300 refreshed, no stack scratch-object residue. Next hypothesis: table-index shift scheduling tie, no sweep authorized.
 * wave78: FINAL retry exhausted; named signed-long index, unsigned-long index, u16 index and State *const all flat9/332, four runs. Three nonshrinking changes; prior once300 consumed, not repeated. Best prior C retained.
 * recoup 2026-10-05 (P21L9): 332 B real extent (lane size 60 was a label gap). Residue: only +0036..0040, the case-0 shift 'lsls r2,r0,#3' (index*8) is issued before 'ldr r1,[r4,#0x1c]' in ours, after 'ldrsb' direction in the original, so startx is in r2 instead of r1. Tried, all 9 B unless noted: six per-function pragmas (lifetimes, propagation, common_subs, dead_assignments, scheduling, peephole); const on the three small tables; __restrict on out/position; Pair-array extern with p->target = tbl[i] (13 B); Pair start struct copy p->start = p->target (17 B); target.x/.y as two table reads (16 B); non-const char table (13 B); source order startx,starty first (20 B) or direction,frames first (15 B); row pointer local with struct copy (9 B) or two field copies (22 B). Idioms read: a-load-scheduled-above-an-unrelated-store, a-const-source-pointer-pulls-field-loads-up, a-local-declared-at-its-first-use, a-data-pair-load-hoisted-into-locals, a-field-read-from-a-table-folds-the-field-offset. Twin search: grep -rl _s32_div_f src/matched/ov and grep -rl 021DF944 src/matched found no interpolation twin.
 * recoup 2026-10-05 P30R2: callees (_s32_div_f, _u32_div_f) are runtime helpers, no void/arity issue. Residue unchanged, 9 B at +0036..0040 (shift index*8 issued before ldr target.x). Tried, 11 compiles: byte-offset index (d + (index << 3)) with struct copy 9 B; two int-word reads 252 B; u64 copy 31 B; copy placed before direction/frames 33 B, between direction and frames 34 B, last with starty early 20 B; frame = 0 moved after the copy 29 B or after next 21 B; startx read into a local at case start 17 B, both start locals 40 B. Best honest form kept (9 B). Idioms read again: a-load-scheduled-above-an-unrelated-store, a-local-declared-at-its-first-use. Twin search: grep -rl _s32_div_f src/matched/ov (no interpolation twin).
 * final push 2026-10-05 G3L6: 33 compiles, still 9 B (+0036..0040). New: table as 'extern const Pair' with p->target = tbl[p->index] is 9 B and replaces the char cast; non-const int/u32/u8/u16/Pair tables 13 B (final two stores swap); memcpy for the pair 340 B; inline helpers (copy, whole case 0, row accessor) 9 B; Pair start member 9 B; p->start = p->target 19 B; row pointer or local Pair at case start 259-274 B; target pointer local 270 B. Finding: shift index*8 goes late only when startx/starty stores follow the dir/frames stores (p->start = p->target), which then moves str startx late; orig has str startx at +003C and shift after the dir load, so no source order tried gives both. Pre-RA scheduler (docs/SCHEDULER.md in inspiredrobot/mwcc): shift wins on height over the target.x load in ours. Matched-asm search for the adds/ldr[r,r]/ldr[r,#4] pair plus shift and ldrsb: no twin in any listing.
 * pass 2 2026-10-06 P2L20: 40 compiles, 3 rounds, best still 9 B (form kept). Finding: the late 'lsls r2,r0,#3' in the original is a register (WAR) wait on r2, which holds target.x until 'str startx'. Closest new shape: 'x = p->target.x;' read right after the next store, startx stored after the direction statement (10 B): ldr target.x lands at +0036 in r2 as in the original, but str startx comes after strb direction, so the shift waits to +0044. Tried, all worse or equal: x/y locals before next 38-40 B; temp for next 17 B; startx later 28-31 B; startx right after x 9 B (copy propagated); x read before next 17-19 B; s8 dir temp 16 B; comma 9 B; u32 start or Pair 9-10 B; u16 index local, opt_lifetimes/opt_propagation off, function-scope x, frame after previous 10 B; Pair pos[2] 9 B; int start[2] 9 B; fieldwise table copy 22 B; int target arrays 46 B; unused label 9 B; block split before the if 265 B; #pragma scheduling off identical. Research in scratchpad wD9r/p2_P2L20/research.md.
 * pass 3 2026-10-06 P3L10: EXACT. The direction table is read through a named const table pointer
 *   assigned after x = p->target.x and before the startx store, under opt_propagation off, with the
 *   direction table extern declared const. The live table pointer holds r1 at the startx store, so x
 *   takes r2 and the index*8 shift waits for the store. Non-const table or pointer: 8 B; no pointer: 9 B.
 * division: explicit runtime quotient preserves admitted zero-delta division.
 */
int func_021DE154(State *p, u16 *out, Pair *position)
{
    int result = 0;
    switch (p->state) {
    case 0: {
        const s8 *t;
        int x;
        p->frame = 0;
        p->previous = p->next;
        p->next = d_021DF858[p->index];
        x = p->target.x;
        t = d_021DF822;
        p->startx = x;
        p->direction = t[p->index];
        p->frames = d_021DF82D[p->index];
        p->starty = p->target.y;
        p->target = d_021DF944[p->index];
        if (p->direction > 0) {
            p->previous = p->previous == 0xffff ? 0 : p->previous;
            p->next = p->next == 0 ? 0xffff : p->next;
        } else {
            p->previous = p->previous == 0 ? 0xffff : p->previous;
            p->next = p->next == 0xffff ? 0 : p->next;
        }
        p->state++;
        break;
    }
    case 1: {
        int x = p->startx;
        int delta = p->target.x - x;
        int sign = _s32_div_f(delta < 0 ? -delta : delta, delta);
        int y, dy;
        if (delta < 0) delta = -delta;
        p->current.x = x + sign * _u32_div_f(p->frame * delta, p->frames);
        y = p->starty;
        dy = p->target.y - y;
        if (dy < 0) dy = -dy;
        p->current.y = y + sign * _u32_div_f(p->frame * dy, p->frames);
        if (p->frame++ >= p->frames) {
            p->value = p->next;
            p->current = p->target;
            p->state++;
        }
        break;
    }
    case 2:
        p->index++;
        if (p->index < p->count) p->state = 0;
        else p->state++;
        break;
    case 3:
        result = 1;
        break;
    }
    if (out) *out = p->value;
    if (position) *position = p->current;
    return result;
}




#pragma opt_propagation reset




void *func_021DE2A0(void *arg,int heap)
{
    char *p;
    p=func_02030734(heap,0x17a8,0,d_021DFBC0,315);
    func_02082BCC(p,0,0x17a8);
    ((struct Obj13959 *)p)->f58=heap;
    ((struct Obj13959 *)p)->f794=arg;
    func_021DEE68(p,(int)p,func_021DE618);
    return p;
}





/*
 * Addresses are Black-image addresses.
 */
void func_021DE2F0(u8 *p)
{
    func_021DEE84(p);
    func_020307B0(p);
}




void func_021DE300(char *p) {func_021DEE90(p);}


void func_021DE308(char *p, unsigned action)
{
    switch (action) {
    case 1:
        if (func_021DEEAC((int *)p, (int)func_021DE618)) func_021DEEA4((u32 *)p, func_021DE61C);
        break;
    case 3:
        if (func_021DEEAC((int *)p, (int)func_021DE6F8)) func_021DEEA4((u32 *)p, func_021DE690);
        break;
    case 4:
        if (func_021DEEAC((int *)p, (int)func_021DE618)) func_021DEEA4((u32 *)p, func_021DE958);
        break;
    case 5:
        if (func_021DEEAC((int *)p, (int)func_021DE958)) ((struct Obj22912 *)p)->f76C = 1;
        break;
    case 6: func_021DEEA4((u32 *)p, func_021DEDC8); break;
    case 7: func_021DEEA4((u32 *)p, func_021DE70C); break;
    case 9: func_021DEEA4((u32 *)p, func_021DE7BC); break;
    case 10: func_021DEEA4((u32 *)p, func_021DE830); break;
    case 12: func_021DEEA4((u32 *)p, func_021DE8D0); break;
    case 0: func_021DEEA4((u32 *)p, func_021DE618); break;
    }
}




int func_021DE3E0(void *p)
{
    if (func_021DEEAC(p, (int)func_021DE618)) return 0;
    if (func_021DEEAC(p, (int)func_021DE61C)) return 1;
    if (func_021DEEAC(p, (int)func_021DE6F8)) return 2;
    if (func_021DEEAC(p, (int)func_021DE690)) return 3;
    if (func_021DEEAC(p, (int)func_021DE958)) return 4;
    if (func_021DEEAC(p, (int)func_021DEDC8)) return 6;
    if (func_021DEEAC(p, (int)func_021DE70C)) return 7;
    if (func_021DEEAC(p, (int)func_021DE7FC)) return 8;
    if (func_021DEEAC(p, (int)func_021DE7BC)) return 9;
    if (func_021DEEAC(p, (int)func_021DE830)) return 10;
    if (func_021DEEAC(p, (int)func_021DE910)) return 11;
    if (func_021DEEAC(p, (int)func_021DE8D0)) return 12;
    return 0;
}




void *func_021DE4D8(char *p)
{
    return ((struct Obj22913 *)p)->f54;
}




int func_021DE4DC(u8 *p, void *a, u32 b)
{
    int s = *(int *)(p + 0x17A4);
    if (s == 1) {
        func_02082D44(p + 0x7A4, a, b);
        return 1;
    }
    return s;
}




int func_021DE500(void *p)
{
    int result=0;
    if (func_0203CD98()) {
        switch (*(unsigned char *)(func_0203D798()+0x65)) {
        case 0: case 5: result=func_021DE5D8(p); break;
        case 1: result=func_021DE570(p); break;
        case 3: result=func_021DE5F8(p); break;
        case 2: case 4: default: break;
        }
    }
    return result;
}




void func_021DE550(char *p) {if(*(u8 * *)&((struct Obj10422 *)p)->f10) {func_020103E4(*(u8 * *)&((struct Obj10422 *)p)->f10); *(int *)&((struct Obj10422 *)p)->f10=0;} func_021DE308(p,0); func_0200FBA0();}




int func_021DE570(char *p)
{
    int result=0;
    if (func_0200FB24()) {
        switch (*(unsigned *)(func_0203CA98()+4)) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            if (((struct Obj22914 *)p)->f790==1) return result;
            func_0203CA04();
            func_02059F18();
            func_0200FBB0();
            func_0200F83C();
            func_0200FBA0();
            result=1; break;
        case 7:
            func_0203CA04();
            func_0200FA84();
            result=3; break;
        case 0: default: break;
        }
    }
    return result;
}



int func_021DE5D8(void *a0) {int r=0; if(func_0200FB24()) {func_0200FBB0();func_0200F83C();func_0200FBA0();r=1;} return r;}



int func_021DE5F8(void *a0) {int r=0; if(func_0200FB24()) {func_0200FBB0();func_0200F83C();func_0200FBA0();r=1;} return r;}



/*
 * extent: empty callback followed by zero alignment padding then labelled 021DE61C.
 */
void func_021DE618(void) {}



void func_021DE61C(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_0203CBAC((struct Req *)d_021DFABC, 0, (unsigned)p);
        func_02043598(0x10, 0);
        *state = 1;
        break;
    case 1:
        if (func_0203CD98()) {
            func_0203D34C(1, ((struct Obj10424 *)p)->f58);
            ((struct Obj10424 *)p)->f10 = func_02010360(4, (void *)(((struct Obj10424 *)p)->f58));
            func_0203D010();
            *state = 2;
        }
        break;
    case 2:
        func_02043598(0x10, 1);
        func_021DEEA4(a, func_021DE6F8);
        break;
    }
}



void func_021DE690(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_020103E4(((struct Obj08100 *)p)->f10);
        *(int *)&((struct Obj08100 *)p)->f10 = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203CEAC((int)func_021DEED0)) *state = 2;
        else *state = 3;
        break;
    case 2:
        if (((struct Obj08100 *)p)->f5C) {
            ((struct Obj08100 *)p)->f5C = 0;
            *state = 3;
        }
        break;
    case 3:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}




void func_021DE6F8(int a, int b, char *c)
{
    func_02010498();
    ((struct Obj22915 *)c)->f54 = func_0201058C(0);
}



void func_021DE70C(void *a,int *state,char *p) {Config cfg;u32 h; switch(*state) {case 0: func_02082BCC(&cfg,0,124);cfg.kind=9;cfg.bytes=720;cfg.data=p+1956;cfg.lang=d_0209DF0C;cfg.align=2097152;cfg.last=1;cfg.flag=0;cfg.heap=((struct Obj08101 *)p)->f58;h=(u32)func_021576D0((u8 *)(&cfg));((struct Obj08101 *)p)->f798=h;func_021578A0((u32 *)h);func_02043598(16,0);((struct Obj08101 *)p)->f17A4=0;*state=1;break;case 1:if(func_0203CD98()) {func_0203D34C(1,((struct Obj08101 *)p)->f58);func_02043598(16,1);*state=2;}break;case 2:func_021DEEA4(a,func_021DE7FC);break;} }



void func_021DE7BC(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_02157938((void *)(((struct Obj22916 *)p)->f798));
        *state = 1;
        break;
    case 1:
        if (func_0203D210()) *state = 2;
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}



void func_021DE7FC(void *a,int b,char *p) {func_02157928(*(u8 * *)&((struct Obj10427 *)p)->f798);if(func_02157910(*(u8 * *)&((struct Obj10427 *)p)->f798)) {((struct Obj10427 *)p)->f17A4=1;func_021DEEA4(a,func_021DE7BC);}}



void func_021DE830(void *a, int *state, char *p)
{
    Descriptor d;
    switch (*state) {
    case 0:
        func_02082BCC(&d, 0, 0x7c);
        d.kind = 9;
        d.size = 0x2d0;
        d.data = p + 0x7a4;
        d.zero = 0;
        d.heap = ((struct Obj06455 *)p)->f58;
        d.setting = d_0209DF0C;
        d.enabled = 1;
        d.flags = 0x200000;
        ((struct Obj06455 *)p)->f79C = func_02157DD8((u8 *)(&d));
        func_02157E34(((struct Obj06455 *)p)->f79C);
        ((struct Obj06455 *)p)->f17A4 = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203CD98()) {
            func_0203D34C(1, ((struct Obj06455 *)p)->f58);
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE910);
        break;
    }
}



void func_021DE8D0(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_02157E8C((void *)(((struct Obj22917 *)p)->f79C));
        *state = 1;
        break;
    case 1:
        if (func_0203D210()) *state = 2;
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}



void func_021DE910(void *a, int *state, char *p)
{
    int result;
    func_02157E78(((struct Obj08102 *)p)->f79C);
    result = func_02157E6C(((struct Obj08102 *)p)->f79C);
    if (result != 0) {
        switch (result) {
        case 1: ((struct Obj08102 *)p)->f17A4 = 1; break;
        case 2:
        case 3: ((struct Obj08102 *)p)->f17A4 = 2; break;
        }
        func_021DEEA4(a, func_021DE8D0);
    }
}



void func_021DE958(void *task,int *state,char *p)
{
    char *q=p+0x60;
    int i,n,j,valid;
    u32 rnd,t,ratio;
    switch(*state) {
    case 0:
        func_02156DE0((int)func_021DEF54,(int)q);
        func_02082BCC(q,0,0x734);
        Q(0x70c)=0;Q(0x710)=0;Q(0x724)=0;Q(0x728)=(u32)(p+0x7a4);
        W(0x17a4)=0;
        if(!func_021C5928((void (*)(int,int,int))func_021DEED8,d_021DFBD0,d_021DFBD8)) {
            W(0x17a4)=2;*state=9;
        } else {Q(0x730)=1;func_021DEE14(q,state,1);}
        break;
    case 1:
        if(Q(0x710)) {W(0x17a4)=2;func_021DEE38((u32)q,3,state,7,7);}
        else if(!func_021C5C04(d_021DFBEC,d_021DFBF8,d_021DFBF8)) {
            W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);
        } else *state=3;
        break;
    case 3:
        if(!func_021C5C38(q,0,10)) {W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);}
        else func_021DEE14(q,state,2);
        break;
    case 2:
        for(i=0;i<10;i++) {
            if(!func_021DEF38((const unsigned *)(q+0xb0*i),0xb0)) {
                if(func_021DEEF8((const signed char *)(q+0xb0*i+0x93))&0x200000)
                    ((Flag *)((u32)q+(u32)i*4))->flag=1;
                else ((Flag *)((u32)q+(u32)i*4))->flag=0;
            } else ((Flag *)((u32)q+(u32)i*4))->flag=0;
        }
        Q(0x714)=0;
        for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) Q(0x714)++;
        *state=4;break;
    case 4:
        n=Q(0x714);
        if(n==1) {
            for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) {Q(0x724)=i;break;}
        } else if(n>1) {
            j=0;rnd=func_0203F0A8();
            if(n) rnd=(u32)(((u64)rnd*(u32)n)>>32);
            for(i=0;i<10;i++) {
                if(((Flag *)((u32)q+(u32)i*4))->flag) {
                    if(j==rnd) {Q(0x724)=i;break;}
                    j++;
                }
            }
            Q(0x724)=i;
        } else {W(0x17a4)=2;func_021DEE38((u32)q,1,state,8,8);break;}
        *state=5;break;
    case 5:
        if(!func_021C5CFC(q+Q(0x724)*0xb0,(char *)Q(0x728),0x1000)) {
            W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);
        } else {
            Q(0x718)=0;d_021DFC00[1]=0;d_021DFC00[3]=0;Q(0x72c)=0;*state=6;
        }break;
    case 6:
        func_021C5AB8();
        if(Q(0x72c)++>7200) {
            func_0203C9AC(0,0,0,0x3f5);W(0x17a4)=2;func_021DEE38((u32)q,3,state,7,7);
        }
        if(!d_021DFC00[1]) {
            if(Q(0x70c)) {W(0x17a4)=2;func_021DEE38((u32)q,3,state,7,7);break;}
            if(func_021C5E14((u32 *)(q+0x71c),(u32 *)(q+0x720))==1) {
                ratio=Q(0x71c)*100/Q(0x720);
                if(Q(0x718)!=ratio) Q(0x718)=ratio;
            }
        } else if(d_021DFC00[3]) {W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);}
        else if(!Q(0x710)) {W(0x17a4)=1;func_021DEE38((u32)q,1,state,8,8);}
        else {W(0x17a4)=2;func_021DEE38((u32)q,3,state,8,8);}
        break;
    case 7:func_021C5DB4();*state=8;break;
    case 8:*state=9;break;
    case 9:Q(0x730)=0;func_02156DE0(0,0);func_021DEEA4(task,func_021DEDC8);break;
    case 100:
        func_021C5AB8();
        if(Q(0x72c)++>7200) {
            func_0203C9AC(0,0,0,0x3f5);W(0x17a4)=2;func_021DEE38((u32)q,3,state,9,9);
        }
        if(d_021DFC00[1]) {
            d_021DFC00[1]=0;
            if(d_021DFC00[3]) {W(0x17a4)=2;func_021DEE38((u32)q,3,state,9,9);}
            else *state=Q(0x708);
        } else if(Q(0x70c)) Q(0x710)=1;
        break;
    case 200:
        func_021C5AB8();
        if(Q(0x72c)++>7200) {func_0203C9AC(0,0,0,0x3f5);*state=Q(0x708);}
        if(d_021DFC00[0]) {d_021DFC00[0]=0;*state=Q(0x708);}
        else if(Q(0x70c)) Q(0x710)=1;
        break;
    }
}



/*
 * extent: Follower 021DEE14 is filed separately and verified.
 */
void func_021DEDC8(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        if (func_0203CEAC(0)) *state = 1;
        else *state = 2;
        break;
    case 1:
        if (func_0203CD98() == 0) {
            ((struct Obj22918 *)p)->f5C = 0;
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}



void func_021DEE14(char *p, int *state, int value)
{
    d_021DFC00[1] = 0;
    d_021DFC00[3] = 0;
    ((struct Obj08104 *)p)->f708 = value;
    ((struct Obj08104 *)p)->f72C = 0;
    *state = 100;
}



void func_021DEE38(u32 p,int a,int *state,int b,int c) {d_021DFC00[0]=0;d_021DFC00[3]=a;((struct Obj08104 *)p)->f708=b;((struct Obj08104 *)p)->f72C=0;*state=200;if(func_021C5B80()==0)*state=c;}




void func_021DEE68(void *p, int a, void *b)
{
    func_02082BCC(p, 0, 0x10);
    ((struct Obj22920 *)p)->fC = (u32)a;
    func_021DEEA4(p, b);
}



void func_021DEE84(void *p) {func_02082BCC(p,0,16);}




void func_021DEE90(char *p)
{
    if (((struct Obj13960 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13960 *)p)->fC);
}



void func_021DEEA4(u32 *p,void *f) {p[0]=(u32)f;p[2]=0;}



int func_021DEEAC(int *p, int value)
{
    return *p == value;
}



void *func_021DEEBC(char *p)
{
    return p + 0x14;
}



int func_021DEEC0(void)
{
    return 0x20;
}



int func_021DEEC4(int a, int b)
{
    return a == b;
}



void func_021DEED0(char *p)
{
    ((struct Obj22922 *)p)->f5C = 1;
}



void func_021DEED8(int a, int b)
{
    d_021DFC00[1] = 1;
    d_021DFC00[3] = b;
    func_021DEEEC();
}



void func_021DEEEC(void)
{
    d_021DFC00[0] = 1;
}



/*
 * lever: Assign the sentinel before the signed-byte load to retain movs/mvns.
 */
int func_021DEEF8(const signed char *p)
{
    unsigned i;
    Digit digit;
    int result;
    int value;
    result = 0;
    for (;;) {
        digit = NO_DIGIT;
        value = *p;
        for (i = 0; i < 23; i++) {
            if (value == d_021DFA8C[i][0]) {
                digit = d_021DFA8C[i][1];
                break;
            }
        }
        if (digit == -1) break;
        result = (result << 4) + digit;
        p++;
    }
    return result;
}



/*
 * extent: Next follower 021DEF54 has its own file.
 */
int func_021DEF38(const unsigned *p, unsigned size)
{
    unsigned i;
    for (i = 0; i < size / 4; i++) {
        if (p[i] != 0) return 0;
    }
    return 1;
}



/*
 * extent: Ends at labelled function 021DEF6C.
 */
int func_021DEF54(char *p, int unused, int type)
{
    switch (type) {
    case 3:
    case 5:
    case 6:
        return ((struct Obj22925 *)p)->f730;
    }
    return 0;
}



int func_021DEF6C(char *p, void *a, unsigned short b)
{
    int count = 0;
    int found = 1;
    int i;
    for (i = 0; i < 253; i++) {
        if (*(unsigned short *)(p + i * 2 + 0xd0) == func_02045A98()) found = 0;
    }
    if (found) count++;
    return count + func_021DEFAC((struct Rec *)p, a, b);
}
