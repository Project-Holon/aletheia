/*
 * file:     mictest_p01.c
 * unit:     yes
 * function: func_02183B60, func_02183C50, func_02183CCC, func_02183D0C, func_02183D1C, func_02183D34, func_02183D3C, func_02183D40, func_02183D44, func_02183D4C, func_02183DAC, func_02183E18, func_02183E60, func_02183EC0, func_02183ED4, func_02183F08, func_02183F30, func_02183F40, func_02183F6C, func_02183F98, func_02183FA0, func_02183FC4
 * address:  0x02183B60
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0218414C 0x0218414C thumb ov168
 *   func_021841F8 0x021841F8 thumb ov168
 *   func_021842BC 0x021842BC thumb ov168
 *   func_02184398 0x02184398 thumb ov168
 *   func_021844C8 0x021844C8 thumb ov168
 *   func_02005E30 0x02005E30 thumb
 *   d_02184A20 0x02184A20 data a4
 *   func_02184408  0x02184408  thumb  ov168
 *   func_02184138  0x02184138  thumb  ov168
 *   func_02184360  0x02184360  thumb  ov168
 *   func_021841C8  0x021841C8  thumb  ov168
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020312F8  0x020312F8  arm
 *   ov088_id       0x00000058  data  a1
 *   d_021BD574     0x021BD574  data  a4
 *   func_021841F4   0x021841F4  thumb
 *   func_0218441C   0x0218441C  thumb
 *   func_02030D28   0x02030D28  arm
 *   func_0202208C   0x0202208C  thumb
 *   func_020221A4   0x020221A4  thumb
 *   func_02184470   0x02184470  thumb
 *   func_0218448C   0x0218448C  thumb
 *   func_0218484C   0x0218484C  thumb
 *   func_02006D94   0x02006D94  thumb
 *   func_020061E4   0x020061E4  thumb
 *   func_0204B878   0x0204B878  arm
 *   func_0204B98C   0x0204B98C  arm
 *   func_02184818  0x02184818  thumb  ov168
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_02022224  0x02022224  thumb
 *   func_020433E0  0x020433E0  arm
 *   func_02061C44  0x02061C44  arm
 *   func_02184144  0x02184144  thumb  ov168
 *   func_021842B4  0x021842B4  thumb  ov168
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021848D4     0x021848D4  data  ov168  a4
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204B8D4  0x0204B8D4  arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204B100 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 *   func_0204B604 0x0204B604 arm
 *   d_02184910 0x02184910 data a4
 *   d_021848AC 0x021848AC data a4
 */
#include "../../matched/include/Obj02210.h"
#include "../../matched/include/Obj23813.h"
#include "../../matched/include/Obj14257.h"
#include "../../matched/include/Obj23817.h"
#include "../../matched/include/Obj14259.h"
#include "../../matched/include/Obj23818.h"
#include "../../matched/include/Obj01262.h"
#include "../../matched/include/Obj10642.h"

struct Obj0203159C;
struct Ctx;
struct Node;
struct S020315D4;
struct Actor;
struct Obj;
struct DispVram;
struct Cfg;
struct Bank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum {OBJECT_SIZE=0x150} Size;

enum Result {DONE=1};

typedef void (*fn_02183D1C)(int *, int *);

typedef struct {u32 group,id,config;} Row;

typedef struct {short x,y,id;u8 a,b;} Config;

typedef signed int     s32;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020056A0(u32,u32,u32);
extern void func_0218414C(char *,int);
extern void func_021841F8(void *,int);
extern void func_021842BC(void **,int);
extern void func_02184398(u8 *p, int heap, u32 b, u32 c);
extern void func_021844C8(int event, char *p);
extern void func_02005E30(u32 a);
extern void func_02184408(int *p);
extern void func_02184138(char *p);
extern void func_02184360(char *p);
extern void func_021841C8(void *);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(int);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02005DF8(u32 a);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern void func_021841F4(char *);
extern void func_0218441C(int *p);
extern void func_02030D28(struct Ctx *c);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_02184470(int *p);
extern void func_0218448C(int *p);
extern int func_0218484C(void);
extern u32 func_02006D94(void);
extern void func_020061E4(u32 a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B98C(struct Actor *a);
extern void func_02184818(char *p);
extern void func_020434CC(void);
extern void func_02043588(void);
extern u32 func_02022224(void *win);
extern void func_020433E0(const struct DispVram *c);
extern void func_02061C44(void);
extern void func_02184144(void *p);
extern void func_021842B4(void *p);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204A5AC(void);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern void func_0204A600(void);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_020275E4(void);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
enum Result func_02183B60(void *obj);
int func_02183C50(int a, int b, int c, void *p);
int func_02183CCC(int a, int b, int c, char *p);
void func_02183D0C(int *p, int a, int b);
void func_02183D1C(int *p);
void func_02183D34(unsigned int *p,unsigned int v);
unsigned int func_02183D3C(unsigned int *p);
int func_02183D40(unsigned int *p);
void func_02183D44(unsigned int *p);
void func_02183D4C(int a, int *state);
void func_02183DAC(int a, int *state);
void func_02183E18(int a, int *state);
void func_02183E60(int a, int *state);
void func_02183EC0(int *p);
void func_02183ED4(int a0);
void func_02183F08(void);
void func_02183F30(void);
void func_02183F40(void *unused, char *p);
void func_02183F6C(int unused, u32 b);
void func_02183F98(void *a0);
void func_02183FA0(void **p);
void func_02183FC4(char *p,u16 heap);
extern const char d_02184A20[];
extern char ov088_id[];
extern char d_021BD574[];
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
extern const Row d_02184910[];
extern const Config d_021848AC[];

enum Result func_02183B60(void *obj)
{
    u8 *p;
    Size size;
    int result=1;
    func_0203064C(1,73,0x70000);
    size=OBJECT_SIZE;
    p=func_0203159C(obj,size,73);
    func_02082BCC(p,0,size);
    ((struct Obj02210 *)((unsigned)p))->f14C=73;
    func_02183ED4(73);
    func_02183F30();
    ((struct Obj02210 *)p)->f140=func_02030734((u16)((struct Obj02210 *)((unsigned)p))->f14C,func_02030CB0(5),0,d_02184A20,0x21d);
    ((struct Obj02210 *)((unsigned)p))->f144=func_02030CBC(5,((struct Obj02210 *)p)->f140);
    ((struct Obj02210 *)((unsigned)p))->f148=func_020056A0((u32)func_02183F40,(u32)p,1);
    func_0218414C((char *)p+0xe4,((struct Obj02210 *)((unsigned)p))->f14C);
    func_021841F8(p+0xe4,((struct Obj02210 *)((unsigned)p))->f14C);
    func_021842BC((void **)(p+0xe4),((struct Obj02210 *)((unsigned)p))->f14C);
    func_02183F6C((int)p,*(u32 *)&((struct Obj02210 *)((unsigned)p))->f14C);
    func_02183FC4((char *)p,((struct Obj02210 *)((unsigned)p))->f14C);
    func_02184398((u8 *)(p+0xf8),((struct Obj02210 *)((unsigned)p))->f14C,(int)func_021844C8,(int)p);
    func_02183D0C((int *)((unsigned)p+0x130),(int)p,(int)func_02183D4C);
    func_02005E30(10);
    return result;
}


int func_02183C50(int a, int b, int c, void *p)
{
    unsigned short v;

    func_02184408((int *)((char *)p + 0xf8));
    func_02030EAC((struct Node *)(*(int *)((char *)p + 0x148)));
    func_02030DA4(*(int *)((char *)p + 0x144));
    func_020307B0((void *)(*(int *)((char *)p + 0x140)));
    func_02184138(p);
    func_02183F98(p);
    func_02184360((char *)p + 0xe4);
    func_021841C8((char *)p + 0xe4);
    func_02183F08();
    v = (unsigned short)*(int *)((char *)p + 0x14c);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(v);
    func_02005DF8(0xa);
    func_020312F8((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}


/*
 * Gate on p+0x130, then run the four init/teardown helpers and the
 *   word at p+0x144 through func_02030D28.
 */
int func_02183CCC(int a, int b, int c, char *p)
{
    if (func_02183D40((unsigned int *)(p + 0x130)))
        return 1;
    func_02183D1C((int *)(p + 0x130));
    func_02183FA0((void **)p);
    func_021841F4(p + 0xE4);
    func_0218441C((int *)(p + 0xF8));
    func_02030D28((struct Ctx *)(((struct Obj23813 *)p)->f144));
    return 0;
}


void func_02183D0C(int *p, int a, int b)
{
    *p = a;
    ((struct Obj14257 *)p)->fC = 0;
    func_02183D34((unsigned int *)p, b);
}


void func_02183D1C(int *p)
{
    if (func_02183D40((unsigned int *)p) == 0)
        ((fn_02183D1C)(*(void **)((char *)p + 4)))(p, (int *)((char *)p + 8));
}

void func_02183D34(unsigned int *p,unsigned int v) { p[1]=v; p[2]=0; }

unsigned int func_02183D3C(unsigned int *p) { return p[0]; }

int func_02183D40(unsigned int *p) { return p[3]; }

/*
 * extent: 6-byte body followed by two bytes of zero alignment padding.
 */
void func_02183D44(unsigned int *p) { p[3]=1; }


void func_02183D4C(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj23817 *)x)->f14C);
        *state = 1;
        break;
    case 1:
        if (func_020221A4())
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183DAC);
        break;
    }
}


void func_02183DAC(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_02184470((int *)(x + 0xF8));
        *state = 1;
        break;
    case 1:
        if (func_0218484C() && func_02006D94()) {
            func_020061E4(0x551);
            *state = 2;
        }
        break;
    case 2:
        func_0218448C((int *)(x + 0xF8));
        *state = 3;
        break;
    case 3:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183E18);
        break;
    }
}


/*
 * Three-state step over the object at *(x+0xC): start on 0, poll on 1,
 *   install 0x2183E60 on 2.
 */
void func_02183E18(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_0204B878((struct Obj *)(((struct Obj14259 *)x)->fC), 1);
        *state = 1;
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(((struct Obj14259 *)x)->fC)) == 0)
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183E60);
        break;
    }
}


/*
 * Step a two-slot state machine: publish through func_0202208C on state 0,
 *   poll func_020221A4 on 1, install func_02183EC0 on 2.
 */
void func_02183E60(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj23818 *)x)->f14C);
        *state = 1;
        break;
    case 1:
        if (func_020221A4())
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183EC0);
        break;
    }
}


void func_02183EC0(int *p)
{
    func_02184818((char *)func_02183D3C((unsigned int *)((int)p)));
    func_02183D44((unsigned int *)p);
}


void func_02183ED4(int a0)
{
    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
    func_02022224((void *)0);
    func_02022224((void *)1);
}


void func_02183F08(void)
{
    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
}


void func_02183F30(void)
{
    func_020433E0((void *)0x021848D4);
}


void func_02183F40(void *unused, char *p)
{
    func_02061C44();
    func_02184144(p);
    func_021842B4(p + 0xe4);
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}


void func_02183F6C(int unused, u32 b)
{
    func_0204A48C((void *)0x020A1448, (u32)((void *)0x021848D4), (u16)b);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

void func_02183F98(void *a0) { func_0204A5AC(); }


void func_02183FA0(void **p)
{
    u16 i;

    for (i = 0; i < 7; i++)
        func_0204B8D4(p[i], 0x1000);
    func_0204A600();
}

/*
 * abi: ABF0 and B294 results remain live and are stored by this caller; their extern return types reflect that use.
 */
void func_02183FC4(char *p,u16 heap)
{
    void *first,*second;
    u16 i;
    const Row *r;
    char *q;
    i=0;
    ((struct Obj01262 *)p)->f1C=func_0204B100(32,0,heap);
    first=func_020490F4(106,heap);
    second=func_020490F4(func_020275E4(),heap);
    ((struct Obj01262 *)p)->f24=func_0204ABF0(first,6,0,0,heap);
    ((struct Obj01262 *)p)->f20=func_0204A6C8(first,7,0,0,heap);
    ((struct Obj01262 *)p)->f28=func_0204AF28(first,8,9,heap);
    ((struct Obj01262 *)p)->f30=func_0204ABF0(first,10,0,32,heap);
    ((struct Obj01262 *)p)->f2C=func_0204A6C8(first,11,0,0,heap);
    ((struct Obj01262 *)p)->f34=func_0204AF28(first,12,13,heap);
    ((struct Obj01262 *)p)->f3C=func_0204ABF0(first,14,0,64,heap);
    ((struct Obj01262 *)p)->f38=func_0204A6C8(first,15,0,0,heap);
    ((struct Obj01262 *)p)->f40=func_0204AF28(first,16,17,heap);
    ((struct Obj01262 *)p)->f48=func_0204ABF0(second,31,1,0,heap);
    ((struct Obj01262 *)p)->f44=func_0204A6C8(second,32,0,1,heap);
    ((struct Obj01262 *)p)->f4C=func_0204AF28(first,18,19,heap);
    func_02049238(second);
    func_02049238(first);
    do{
        r=&d_02184910[i];
        q=p+r->group*4;
        *(void **)(p+i*4)=func_0204B294((void *)*(u32 *)&((struct Obj01262 *)p)->f1C,((struct Obj10642 *)q)->f20,((struct Obj10642 *)q)->f24,((struct Obj10642 *)q)->f28,&d_021848AC[r->config],r->id,heap);
        func_0204B92C(*(void **)(p+i*4),1);
        ++i;
    }while(i<7);
    for(i=0;i<3;i++)func_0204B3DC(*(void **)(p+i*4+0x10),0);
    func_0204B570(((struct Obj01262 *)p)->f0,0);
    func_0204B604(((struct Obj01262 *)p)->f0,1,1);
    ((struct Obj01262 *)p)->fE0=10;
}
