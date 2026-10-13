/*
 * file:     wifibattlematch_sys.c
 * unit:     yes
 * function: func_02212560, func_0221268C, func_022126F4, func_02212740, func_022127F0, func_02212854, func_0221290C, func_02212988, func_02212A90, func_02212AF8, func_02212E74, func_02212FD8, func_0221303C, func_02213078, func_022130D4, func_02213134, func_0221320C, func_02213234, func_02213278, func_022132C4, func_02213338, func_0221336C, func_022133D0, func_022133E4, func_022135CC, func_02213684, func_022136E4, func_0221372C, func_02213754, func_02213800, func_02213804, func_02213808, func_0221380C, func_02213814, func_02213850
 * address:  0x02212560
 * region:   ov199
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02082D44 0x02082D44 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0201A920 0x0201A920 thumb
 *   func_0200B400 0x0200B400 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201A918 0x0201A918 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 *   d_02213C58 0x02213C58 data a4 ov199
 *   func_0200B424 0x0200B424 thumb
 *   func_02012704 0x02012704 thumb
 *   func_02087BCC 0x02087BCC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02005D28 0x02005D28 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_02030734 0x02030734 arm
 *   func_02005C44 0x02005C44 thumb
 *   func_02005D90 0x02005D90 thumb
 *   d_02213D04 0x02213D04 data a1 ov199
 *   func_0200E9F4 0x0200E9F4 thumb
 *   func_0200EA04 0x0200EA04 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_0201A354 0x0201A354 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_0201A2A8 0x0201A2A8 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   ov093_id 0x0000005D data
 *   func_0200B480 0x0200B480 thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020399A8 0x020399A8 arm
 *   func_02013790 0x02013790 thumb
 *   func_020137C0 0x020137C0 thumb
 *   func_02013864 0x02013864 thumb
 *   func_02013894 0x02013894 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_02013128 0x02013128 thumb
 *   func_02013160 0x02013160 thumb
 *   func_02013980 0x02013980 thumb
 *   func_0200BA58 0x0200BA58 thumb
 *   func_021EEE78 0x021EEE78 thumb ov188
 *   func_0200BA68 0x0200BA68 thumb
 *   func_020130DC 0x020130DC thumb
 *   func_0200BA38 0x0200BA38 thumb
 *   func_021EEEA8 0x021EEEA8 thumb ov188
 *   func_02013930 0x02013930 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_02031324 0x02031324 arm
 *   func_0203133C 0x0203133C arm
 *   func_02031330 0x02031330 arm
 *   func_02031348 0x02031348 arm
 *   func_02005E30 0x02005E30 thumb
 *   func_0203A5E4 0x0203A5E4 arm
 */
#include "../../matched/include/Obj01177.h"
#include "../../matched/include/Obj25291.h"
#include "../../matched/include/Obj03352.h"
#include "../../matched/include/Obj08367.h"
#include "../../matched/include/Obj08368.h"
#include "../../matched/include/Obj06657.h"
#include "../../matched/include/Obj01078.h"
#include "../../matched/include/Obj02537.h"
#include "../../matched/include/Obj01007.h"
#include "../../matched/include/Obj03909.h"
#include "../../matched/include/Obj10857.h"
#include "../../matched/include/Obj08370.h"
#include "../../matched/include/Obj14575.h"
#include "../../matched/include/Obj25293.h"
#include "../../matched/include/Obj10858.h"
#include "../../matched/include/Obj08371.h"
#include "../../matched/include/Obj25294.h"
#include "../../matched/include/Obj02248.h"
#include "../../matched/include/Obj25295.h"
#include "../../matched/include/Obj14576.h"
#include "../../matched/include/Obj14577.h"
#include "../../matched/include/Obj14578.h"
#include "../../matched/include/Obj01819.h"
#include "../../matched/include/Obj08373.h"
#include "../../matched/include/Obj14579.h"
#include "../../matched/include/Obj06660.h"
#include "../../matched/include/Obj25296.h"
#include "../../matched/include/Obj25297.h"
#include "../../matched/include/Obj06661.h"
#include "../../matched/include/Obj14584.h"
#include "../../matched/include/Obj25299.h"
#include "../../matched/include/Obj25300.h"
#include "../../matched/include/Obj25301.h"
#include "../../matched/include/Obj25303.h"
#include "../../matched/include/Obj25304.h"
#include "../../matched/include/Obj06662.h"

struct Big;
struct BigObj;
struct Party;
struct Obj0203159C;
struct S020315D4;
struct S;
struct Rec160;
struct Rec534;
struct Sub0200852CObj;
struct Entry;
struct Reg;
struct Reg2;
struct ZoneData;
struct Obj;
struct S020314B8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32_02212560;

typedef unsigned int   u32_0221268C;

typedef unsigned int   u32_022126F4;

typedef unsigned int   u32_02212740;

typedef enum { tag_2740 = 0x24f } Offset2740;

typedef unsigned int   u32_022127F0;

typedef enum { tag_2854 = 0x2c0 } Offset2854;

typedef unsigned int   u32_0221290C;

typedef unsigned int   u32_02212988;

typedef unsigned int   u32_02212A90;

typedef unsigned int   u32_02212AF8;

typedef signed int     s32;

struct Sub { u32_02212AF8 a0; u32_02212AF8 a4; u8 pad[1]; };

struct Row { u8 pad[0x44]; u32_02212AF8 f44; };

struct In {
    u32_02212AF8 f0; void *f4; s32 f8; u8 padc[0x1c - 0xc]; s32 f1c; u8 pad20[0x28 - 0x20];
    struct Row *f28; struct Row *f2c; void *f30; void *f34; u8 pad38[0x8ac - 0x38]; s32 f8ac;
};

struct Pair { u32_02212AF8 f0; struct Row *f4; u8 f8; u8 f9; u8 pada[6]; };

struct R8 {
    struct Pair a; struct Pair b; u8 pad_b[0x48 - 0x20];
    s32 f48; u8 pad4c[4]; s32 f50; void *f54;
};

struct W4 {
    u8 pad0[8]; s32 f8; s32 fc; u8 pad10[8]; u16 f18; u16 f1a;
    u8 pad1c[0xc1 - 0x1c]; u8 fc1;
};

struct Out { void *f0; struct W4 *f4; struct R8 *f8; };

typedef struct Flag { u8 bit:1; u8 rest:7; } Flag;

typedef struct Bytes_02212E74 { u8 a,b,c; } Bytes_02212E74;

typedef unsigned int   u32_02212E74;

typedef unsigned int   u32_0221303C;

typedef unsigned int   u32_02213078;

typedef unsigned int   u32_022130D4;

typedef unsigned int   u32_02213134;

typedef unsigned int   u32_0221320C;

typedef unsigned int   u32_02213234;

typedef unsigned int   u32_02213278;

typedef unsigned int   u32_022132C4;

typedef unsigned int   u32_02213338;

typedef unsigned int   u32_0221336C;

typedef unsigned int   u32_022133D0;

typedef signed short   s16;

typedef signed char    s8;

typedef unsigned u32_022133E4;

typedef struct Flags { u32_022133E4 year:7, month:4, day:5, hour:5, minute:6, rest:4, enabled:1; } Flags;

typedef struct Nibbles { u8 a:4,b:4; } Nibbles;

typedef struct Triple { int a,b,c; } Triple;

typedef struct Date { int a,b,c,weekday; } Date;

typedef struct Bytes_022133E4 { u8 a,b; } Bytes_022133E4;

typedef unsigned int   u32_022135CC;

typedef unsigned int   u32_022136E4;

typedef unsigned int   u32_0221372C;

typedef struct S {
    int f0;
    int f4;
    unsigned short f8;
    int fc;
    char *f10;
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
    unsigned char f1b;
    int f1c;
} S;

typedef unsigned int   u32_02213850;

extern void func_02034714(const char *expr, u32_02212560 line, const char *file);
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, u32_02212560 size, u32_02212560 heap);
extern void func_02082BCC(void *, int, unsigned);
extern void func_02082D44(const void *, void *, unsigned);
extern void *func_020124F4(u16);
extern struct Party *func_0201A920(u32_02212560 heap);
extern void func_0200B400(unsigned);
extern void *func_02012934(const struct BigObj *p);
extern int func_0201A918(void);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern u32_02212560 func_020307B0(void *p);
extern void func_0200B424(void);
extern void func_02012704(u8 *p);
extern void func_02087BCC(u32_0221268C parameter);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32_0221268C);
extern void func_02005D28(void);
extern u32_022126F4 func_0200F7B8(u32_022126F4 a0);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern u16 func_02005C44(void);
extern void func_02005D90(unsigned, unsigned);
extern void *func_0200E9F4(void *p);
extern int func_0200EA04(int);
extern void func_0201A948(struct Party *p);
extern void *func_0201A354(int, int);
extern void *func_0200AE14(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32_02212988 index);
extern void *func_0200B358(void *);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_0201A2A8(void *, void *);
extern void *func_020084F4(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0200B480(void);
extern void *func_02012F2C(int *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(int);
extern struct Entry *func_020399A8(void);
extern void func_02013790(void *, void *, int, int, u32_02212AF8);
extern void func_020137C0(void *, void *, int, int, u32_02212AF8);
extern void func_02013864(void *, void *, int, int, u32_02212AF8);
extern void func_02013894(void *, void *, int, int, u32_02212AF8);
extern u32_02212AF8 func_0200AE54(struct Reg *p, u32_02212AF8 id);
extern s32 func_0200B078(struct Reg2 *p, u32_02212AF8 id);
extern void func_02013128(void *, void *, int);
extern void func_02013160(u8 *o, void *a1, u32_02212AF8 a2);
extern void func_02013980(struct ZoneData *o, u32_02212AF8 heap);
extern void func_0200BA58(void);
extern void func_021EEE78(void *);
extern void func_0200BA68(void);
extern void func_020130DC(void *);
extern unsigned func_0200BA38(unsigned);
extern void func_020130C4(u8 *p);
extern void func_020138C4(char *, void *, int);
extern void func_021EEEA8(void *p, u32_022132C4 c);
extern void func_02013930(struct Obj *p);
extern u32_022133E4 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern int func_02167ED8(void *date, void *time);
extern void *func_02031324(int);
extern void func_0203133C(struct S020314B8 *p);
extern int func_02031330(int);
extern int func_02031348(int, int, int, int);
extern void func_02005E30(unsigned);
extern void func_0203A5E4(u32_02213850 key);
int func_02212560(void *a, int unused, u8 *arg);
int func_0221268C(void *sys, int unused, void *data, char *p);
int func_022126F4(int unused,int *state,int unused2,char *p);
int *func_02212740(void *obj, unsigned heap, char *ctx);
int func_022127F0(void *obj, int *command, int *ctx);
int *func_02212854(int unused, unsigned heap, char *ctx);
int func_0221290C(void *obj, int *command, int *ctx);
u8 *func_02212988(int unused, unsigned heap, u8 *p);
int func_02212A90(void *obj, int *command, int *ctx);
struct Out *func_02212AF8(int unused, u32_02212AF8 heap, struct In *p);
int func_02212E74(void *manager, u8 *arg, u8 *p);
int *func_02212FD8(int unused, unsigned heap, char *ctx);
int func_0221303C(char *p, char *q, char *work);
void *func_02213078(void *unused, int heap, char *p);
int func_022130D4(char *a, char *work, char *p);
unsigned *func_02213134(int unused, unsigned heap, u8 *p);
int func_0221320C(char *p, char *q, char *work);
void *func_02213234(void *unused, int heap, char *p);
int func_02213278(char *a, void *work, char *p);
void *func_022132C4(void *unused, int heap, char *p);
int func_02213338(char *p, char *q);
void func_0221336C(char *p, int heap);
void func_022133D0(u8 *p);
void func_022133E4(u8 *p,void *party1,void *party2,u8 *save,void *reg,int setting,u8 *record,void *other,int mode);
void func_022135CC(unsigned char *p, unsigned char *a, unsigned char *b);
void func_02213684(const unsigned char *p, unsigned char *a, unsigned char *b);
void *func_022136E4(void *a, void *b, void *c, int heap);
void func_0221372C(char *p);
int func_02213754(S *s);
int func_02213800(char *p);
unsigned char func_02213804(char *p);
void func_02213808(char *p, int value);
void func_0221380C(unsigned char *p);
int func_02213814(struct Obj0203159C *p,int unused,char *q);
int func_02213850(void *a, void *b, void *c, char *work);
extern const char d_02213D00[];
extern const unsigned d_02213C58[];
extern const char d_02213D00[], d_02213D04[];
extern const char ov093_id[];

/*
 * lever: case 1 precedes case 0 to preserve the backward shared assignment.
 * ABI exception: 3159C legacy void callee leaves allocator pointer in r0;
 * caller immediately uses this result as its workspace.
 */
int func_02212560(void *a, int unused, u8 *arg)
{
    u8 *p;
    void *v;
    u8 *dst;
    unsigned kind;
    switch (((struct Obj25291 *)arg)->f8) {
    case 1: kind = 1; break;
    case 0: kind = 1; break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_0203064C(kind, 0x56, 0x8000);
    p = func_0203159C(a, 0x8b0, 0x56);
    func_02082BCC(p, 0, 0x8b0);
    func_02082D44(arg, p + 4, 0x14);
    ((struct Obj01177 *)p)->f20 = 0;
    if (((struct Obj01177 *)p)->f4 == 0) {
        ((struct Obj01177 *)p)->f4 = func_020124F4(1);
        ((struct Obj01177 *)p)->f0 = 1;
    }
    ((struct Obj01177 *)p)->f30 = func_0201A920(0x56);
    ((struct Obj01177 *)p)->f34 = func_0201A920(0x56);
    ((struct Obj01177 *)p)->f38 = func_0201A920(0x56);
    ((struct Obj01177 *)p)->f3C = func_0201A920(0x56);
    func_0200B400(0x56);
    func_0221336C((char *)p, 0x56);
    ((struct Obj01177 *)p)->f18 = func_022136E4((void *)d_02213C58, (void *)9, p, 0x56);
    switch (((struct Obj01177 *)p)->fC) {
    case 0:
        ((struct Obj01177 *)p)->f1C = 0;
        func_02213808(((struct Obj01177 *)p)->f18, 0);
        break;
    case 1:
        ((struct Obj01177 *)p)->f1C = 2;
        func_02213808(((struct Obj01177 *)p)->f18, 4);
        break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    dst = *(u8 * *)&((struct Obj01177 *)p)->f28;
    switch (((struct Obj01177 *)p)->f10) {
    case 0:
        v = func_02012934(((struct Obj01177 *)p)->f4);
        func_02082D44(v, dst + 0xd4, func_0201A918());
        break;
    case 1:
        v = func_0200BAF4((int)func_0200BAC8(func_02012EBC(((struct Obj01177 *)p)->f4)), 0x8056);
        func_02082D44(v, dst + 0xd4, func_0201A918());
        func_020307B0(v);
        break;
    }
    return 1;
}

int func_0221268C(void *sys, int unused, void *data, char *p)
{
    func_0221372C(((struct Obj03352 *)p)->f18);
    func_022133D0((u8 *)p);
    func_0200B424();
    func_020307B0(((struct Obj03352 *)p)->f3C);
    func_020307B0(((struct Obj03352 *)p)->f38);
    func_020307B0(((struct Obj03352 *)p)->f34);
    func_020307B0(((struct Obj03352 *)p)->f30);
    if (((struct Obj03352 *)p)->f0) func_02012704(((struct Obj03352 *)p)->f4);
    if (((struct Obj03352 *)p)->fC != 1) func_02087BCC(0);
    if (((struct Obj03352 *)p)->f14) func_020307B0(data);
    func_020315D4(sys);
    func_020306F0(0x56);
    func_02005D28();
    return 1;
}

int func_022126F4(int unused,int *state,int unused2,char *p)
{
    switch(*state) {
    case 0:
        if(func_02213754((struct S *)(((struct Obj08367 *)p)->f18))) *state=1;
        if(((struct Obj08367 *)p)->f1CC) --((struct Obj08367 *)p)->f1CC;
        {
            int x=func_02213800((char *)(((struct Obj08367 *)p)->f18));
            if(x==2 || x==0) func_0200F7B8(0);
        }
        break;
    case 1: return 1;
    }
    return 0;
}

/*
 * ABI: allocator tag is u16; passing symbolic tag_2740 directly avoids truncating
 * the live offset variable and preserves the original instruction shape.
 * lever: enum tag 0x24F remains live and becomes offset 0x1B4.
 */
int *func_02212740(void *obj, unsigned heap, char *ctx)
{
    Offset2740 offset = tag_2740;
    int *p = func_02030734(heap, 0x18, 0, d_02213D04, tag_2740);
    func_02082BCC(p, 0, 0x18);
    p[0] = ((struct Obj08368 *)ctx)->f4;
    offset -= 0x9b;
    p[3] = ((struct Obj08368 *)ctx)->f28;
    p[4] = ((struct Obj08368 *)ctx)->f2C;
    p[5] = (int)(ctx + offset);
    switch (func_02213804(obj)) {
    case 4: case 7: p[1] = 1; break;
    case 8: p[1] = 6; break;
    case 3: p[1] = 4; break;
    case 6: p[1] = 5; break;
    case 0: p[1] = 0; break;
    case 1: case 2: case 5:
    default:
        if (((struct Obj08368 *)ctx)->f1C0) p[1] = 6;
        else func_02034714(d_02213D00, 0, d_02213D00);
        break;
    }
    if (func_02005C44() != 0x487) func_02005D90(0x487, 0xffff);
    return p;
}

int func_022127F0(void *obj, int *command, int *ctx)
{
    switch (command[2]) {
    case 0: func_0221380C(obj); break;
    case 1: ctx[7] = 0; func_02213808(obj, 4); break;
    case 2: ctx[7] = 1; func_02213808(obj, 2); break;
    case 3: ctx[7] = 1; func_02213808(obj, 6); break;
    case 4: ctx[7] = 1; func_02213808(obj, 8); break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_020307B0(command);
    return 1;
}

/*
 * ABI: EA04 consumes the live return register from E9F4, with no new setup.
 * lever: derive an integer offset before adding the base, then reduce the enum.
 */
int *func_02212854(int unused, unsigned heap, char *ctx)
{
    Offset2854 offset = tag_2854;
    int *p = func_02030734(heap, 0x44, 0, d_02213D04, tag_2854);
    func_02082BCC(p, 0, 0x44);
    p[2] = (int)(ctx + 4);
    p[3] = ((struct Obj06657 *)ctx)->f20;
    p[0] = ((struct Obj06657 *)ctx)->f1C - 2;
    p[5] = ((struct Obj06657 *)ctx)->f28;
    p[6] = ((struct Obj06657 *)ctx)->f2C;
    p[7] = (int)(ctx + 0x40);
    p[8] = (int)(ctx + (offset - 0xf4));
    offset -= 0xf0;
    p[9] = (int)(ctx + offset);
    p[15] = (int)(ctx + 0x7d4);
    p[10] = (int)(ctx + 0x8a8);
    p[11] = (int)(ctx + 0x1b4);
    p[12] = (int)(ctx + 0x224);
    p[13] = (int)(ctx + 0x22c);
    p[14] = (int)(ctx + 0x778);
    p[16] = (int)(ctx + 0x8ac);
    {
        void *q = func_02012EBC(((struct Obj06657 *)ctx)->f4);
        p[4] = func_0200EA04((int)func_0200E9F4(q));
    }
    if (func_02005C44() != 0x487) func_02005D90(0x487, 0xffff);
    return p;
}

/*
 * lever: case 4 stores the flag and falls through to case 0's shared call.
 */
int func_0221290C(void *obj, int *command, int *ctx)
{
    switch (command[0]) {
    case 0: ctx[7] = 2; break;
    case 1: ctx[7] = 3; break;
    case 2: break;
    case 3: ctx[7] = 3; break;
    }
    switch (command[1]) {
    case 1: func_02213808(obj, 2); break;
    case 2: func_02213808(obj, 6); break;
    case 3: ctx[0x220 / 4] = 1; func_02213808(obj, 4); break;
    case 4: ctx[9] = 1;
    case 0: func_02213808(obj, 7); break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_020307B0(command);
    return 1;
}

/*
 * ABI exception: AE14 and 084F4 empty callees preserve live pointer r0;
 * caller consumes it after their BL, despite legacy void(void).
 */
u8 *func_02212988(int unused, unsigned heap, u8 *p)
{
    u8 *out;
    u8 *row;
    unsigned id;
    func_0201A948(((struct Obj01078 *)p)->f30);
    func_0201A948(((struct Obj01078 *)p)->f34);
    out = func_02030734(heap, 0x24, 0, d_02213D04, 0x32f);
    func_02082BCC(out, 0, 0x24);
    if (((struct Obj01078 *)p)->f1C == 2 || ((struct Obj01078 *)p)->f1C == 3) {
        switch (((struct Obj01078 *)p)->f8) {
        case 0: id = 15; break;
        case 1: id = 16; break;
        case 2: id = 17; break;
        case 3: id = 18; break;
        case 4: id = 19; break;
        default: func_02034714(d_02213D00, 0, d_02213D00); break;
        }
        ((struct Obj02537 *)out)->f0 = func_0201A354(id, heap);
    } else if (((struct Obj01078 *)p)->f1C == 0) {
        ((struct Obj02537 *)out)->f0 = func_0200AE14(func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj01078 *)p)->f4)), 0));
    } else if (((struct Obj01078 *)p)->f1C == 1) {
        ((struct Obj02537 *)out)->f0 = func_0200AE14(func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj01078 *)p)->f4)), 1));
    } else {
        func_02034714(d_02213D00, 0, d_02213D00);
    }
    ((struct Obj02537 *)out)->f1C = ((struct Obj01078 *)p)->f30;
    ((struct Obj02537 *)out)->f14 = ((struct Obj01078 *)p)->f4;
    func_0201AC2C((const struct Rec534 *)(*(u8 * *)&((struct Obj01078 *)p)->f28 + 0xd4), ((struct Obj01078 *)p)->f38);
    func_0201A2A8(((struct Obj02537 *)out)->f0, ((struct Obj01078 *)p)->f38);
    ((struct Obj02537 *)out)->f4 = ((struct Obj01078 *)p)->f38;
    row = *(u8 * *)&((struct Obj01078 *)p)->f2C;
    func_0201AC2C((const struct Rec534 *)(row + 0xd4), ((struct Obj01078 *)p)->f3C);
    func_0201A2A8(((struct Obj02537 *)out)->f0, ((struct Obj01078 *)p)->f3C);
    ((struct Obj02537 *)out)->f8 = func_020084F4(row);
    ((struct Obj02537 *)out)->f10 = ((struct Obj01078 *)p)->f3C;
    out[0xc] = func_02008550((const struct Sub0200852CObj *)row);
    return out;
}

/*
 * tail: 02212AF6..02212AF8 is zero alignment padding.
 */
int func_02212A90(void *obj, int *command, int *ctx)
{
    if (ctx[7] == 1) {
        switch (command[8]) {
        case 0: func_02213808(obj, 5); break;
        case 2: ctx[0x1c0 / 4] = 1; func_02213808(obj, 0); break;
        }
    } else {
        switch (command[8]) {
        case 0: func_02213808(obj, 5); break;
        case 1: ctx[0x220 / 4] = 1; func_02213808(obj, 4); break;
        case 3: ctx[8] = 2; func_02213808(obj, 1); break;
        }
    }
    if ((unsigned)(ctx[7] - 2) <= 1) func_020307B0((void *)command[0]);
    func_020307B0(command);
    return 1;
}

/*
 * matching: a switch default written as its own copy of case 0 leaves the b stub the
 *   original has; explicit copies per index (0 and 1) instead of a helper; y*2+0x21+x add order.
 */
struct Out *func_02212AF8(int unused, u32_02212AF8 heap, struct In *p)
{
    struct Out *out;
    void *v;
    void *sys;
    int id;
    int a;
    int flag = 0;
    sys = func_0200B358(func_02012EBC(p->f4));
    out = func_02030734(heap, 0x10, 0, d_02213D04, 0x3e0);
    func_02082BCC(out, 0, 0x10);
    out->f0 = p->f4;
    func_0200B480();
    func_02082BCC((u8 *)p + 0x1b4, 0, 0x18);
    out->f8 = func_02030734(heap, 0x58, 0, d_02213D04, 0x3eb);
    func_02082BCC(out->f8, 0, 0x58);
    out->f8->f54 = func_02012F2C(p->f4);
    out->f8->f50 = 0;
    {
        struct R8 *r = out->f8;
        r->a.f4 = p->f28;
        r->a.f0 = (u32_02212AF8)p->f30;
        r->a.f9 = p->f28->f44;
    }
    {
        struct R8 *r = out->f8;
        struct Pair *b = &r->b;
        b->f4 = p->f2c;
        r->b.f0 = (u32_02212AF8)p->f34;
        b->f9 = p->f2c->f44;
    }
    out->f4 = func_02030734(heap, 0xf0, 0, d_02213D04, 0x403);
    func_02082BCC(out->f4, 0, 0xf0);
    func_02034AC4((int)ov093_id);
    if (p->f1c == 2 || p->f1c == 3) {
        id = 16;
        switch (p->f8) {
        case 0: default: id = 15; func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 1: func_020137C0(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 2: id = 17; func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 3: id = 18; func_02013894(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 4: id = 19; func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        }
        v = func_0201A354(id, heap);
        flag = 1;
    } else if (p->f1c == 0) {
        v = func_0200AE14(func_0200B1D4(sys, 0));
        switch (func_0200AE54(v, 0x15)) {
        case 0: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 1: func_020137C0(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 2: func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 3: func_02013894(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        default: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        }
    } else if (p->f1c == 1) {
        v = func_0200AE14(func_0200B1D4(sys, 1));
        switch (func_0200AE54(v, 0x15)) {
        case 0: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 1: func_020137C0(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 2: func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 3: func_02013894(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        default: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        }
    } else {
        func_02034714(d_02213D00, flag, d_02213D00);
    }
    if (p->f1c == 3) a = p->f8 + 0x17;
    else if (p->f1c == 2) a = p->f8 + 0x1c;
    else {
        int x = func_0200AE54(v, 0xd);
        int y = func_0200AE54(v, 0x15);
        if (x >= 2) x = 1;
        a = y * 2 + 0x21 + x;
    }
    out->f8->f48 = a;
    if (p->f1c == 2 || p->f1c == 3) {
        out->f4->f18 = 0x490;
        out->f4->f1a = 0x47d;
    } else if (p->f1c == 0) {
        void *e = func_0200B1D4(sys, 0);
        int m = func_0200B078(e, 0xb);
        int r = func_0200AE54(func_0200AE14(e), 0x12);
        if (m == 1) { out->f4->f18 = 0x48d; out->f4->f1a = 0x480; }
        else { out->f4->f18 = 0x46b; out->f4->f1a = 0x47d; }
        if ((u32_02212AF8)(r - 2) <= 1) {
            out->f4->fc = 0xe;
            out->f4->f8 = 0x12;
            out->f8->f50 = 1;
        }
    } else if (p->f1c == 1) {
        void *e = func_0200B1D4(sys, 1);
        int m = func_0200B078(e, 0xb);
        int r = func_0200AE54(func_0200AE14(e), 0x12);
        if (m == 1) { out->f4->f18 = 0x48d; out->f4->f1a = 0x480; }
        else { out->f4->f18 = 0x46b; out->f4->f1a = 0x47d; }
        if ((u32_02212AF8)(r - 2) <= 1) {
            out->f4->fc = 0xe;
            out->f4->f8 = 0x12;
            out->f8->f50 = 1;
        }
    }
    func_02013128(out->f4, p->f30, 0);
    func_02013160((u8 *)out->f4, v, (u16)((heap & 0x7fff) | 0x8000));
    if (p->f8ac) out->f4->fc1 |= 4;
    func_02013980((struct ZoneData *)out->f4, heap);
    func_02034A5C((int)ov093_id);
    if (flag) func_020307B0(v);
    return out;
}

int func_02212E74(void *manager, u8 *arg, u8 *p)
{
    u8 *record = *(u8 * *)&((struct Obj03909 *)arg)->f4;
    int state = ((struct Obj03909 *)arg)->fC;
    Bytes_02212E74 bytes;
    void *rules,*reg,*created;
    int setting;
    ((struct Obj01007 *)p)->f1B8 = ((struct Obj10857 *)record)->f4;
    ((struct Obj01007 *)p)->f1B4 = ((struct Obj10857 *)record)->f8C;
    ((struct Obj01007 *)p)->f1C4 = ((Flag *)(record + 0xc1))->bit;
    ((struct Obj01007 *)p)->f1B4 = ((struct Obj10857 *)record)->f8C;
    func_022135CC(*(u8 * *)&((struct Obj03909 *)arg)->f4, &bytes.b, &bytes.c);
    p[0x1bc] = bytes.c;
    func_02213684(*(u8 * *)&((struct Obj03909 *)arg)->f4, &bytes.a, p + 0x1bd);
    func_0200BA58();
    func_021EEE78(((struct Obj03909 *)arg)->f4);
    func_0200BA68();
    if (((struct Obj01007 *)p)->f1C == 0) {
        rules = func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj01007 *)p)->f4)),0);
        reg = func_0200AE14(rules);
        setting = func_0200B078(rules,2);
        if (state == 0) func_022133E4(p + 0x1d0,((struct Obj01007 *)p)->f30,((struct Obj01007 *)p)->f34,((struct Obj01007 *)p)->f2C,reg,setting,record,p + 0x1b4,0);
    } else if (((struct Obj01007 *)p)->f1C == 2) {
        created = func_0201A354(((struct Obj01007 *)p)->f8 + 0xf,0x56);
        if (state == 0) func_022133E4(p + 0x1d0,((struct Obj01007 *)p)->f30,((struct Obj01007 *)p)->f34,((struct Obj01007 *)p)->f2C,created,0,record,p + 0x1b4,2);
        func_020307B0(created);
    }
    func_020130DC(((struct Obj03909 *)arg)->f4);
    func_020307B0(((struct Obj03909 *)arg)->f4);
    func_020307B0(((struct Obj03909 *)arg)->f8);
    func_020307B0(arg);
    if (((struct Obj01007 *)p)->f1C == 1) {
        switch(state) {
        case 0: func_02213808(manager,0);break;
        case 1: ((struct Obj01007 *)p)->f1C0=1;func_02213808(manager,0);break;
        }
    } else {
        switch(state) {
        case 0: ((struct Obj01007 *)p)->f20=1;func_02213808(manager,1);break;
        case 2: ((struct Obj01007 *)p)->f220=1;func_02213808(manager,4);break;
        case 3: ((struct Obj01007 *)p)->f20=2;func_02213808(manager,1);break;
        }
    }
    return 1;
}

int *func_02212FD8(int unused, unsigned heap, char *ctx)
{
    int zero = 0;
    int *p = func_02030734(heap, 0x28, zero, d_02213D04, 0x588);
    func_02082BCC(p, zero, 0x28);
    p[0] = ((struct Obj08370 *)ctx)->f4;
    p[1] = zero;
    p[2] = 1;
    p[4] = (int)(ctx + 0x40);
    if (((struct Obj08370 *)ctx)->fC == 0) p[3] = 0x24;
    else p[3] = 0x34;
    if (((struct Obj08370 *)ctx)->f220) {
        ((struct Obj08370 *)ctx)->f220 = zero;
        p[5] = 1;
    } else p[5] = zero;
    return p;
}

int func_0221303C(char *p, char *q, char *work)
{
    int mode = ((struct Obj25293 *)q)->f1C;
    func_020307B0(q);
    switch (mode) {
    case 0:
        ((struct Obj14575 *)work)->f20 = 0;
        func_02213808(p, 1);
        break;
    case 1:
        if (((struct Obj14575 *)work)->fC == 0) func_02213808(p, 0);
        else func_0221380C((unsigned char *)p);
        break;
    }
    return 1;
}

void *func_02213078(void *unused, int heap, char *p)
{
    unsigned int *work = func_02030734(heap, 0x1c, 0, d_02213D04, 0x5dc);
    func_02082BCC(work, 0, 0x1c);
    work[0] = (unsigned int)(p + 4);
    work[3] = ((struct Obj10858 *)p)->f30;
    work[4] = ((struct Obj10858 *)p)->f34;
    work[5] = (unsigned int)(p + 0x7d4);
    work[6] = (unsigned int)(p + 0x8a8);
    if (((struct Obj10858 *)p)->f1C == 1)
        work[1] = 1;
    else
        work[1] = 0;
    return work;
}

int func_022130D4(char *a, char *work, char *p)
{
    int state = ((struct Obj25294 *)work)->f8;
    func_020307B0(work);
    if (((struct Obj08371 *)p)->f1C == 1) {
        switch (state) {
        case 0: func_02213808(a, 3); break;
        case 2: ((struct Obj08371 *)p)->f1C0 = 1; func_02213808(a, 0); break;
        }
    } else {
        switch (state) {
        case 0: func_02213808(a, 3); break;
        case 1: ((struct Obj08371 *)p)->f220 = 1; func_02213808(a, 4); break;
        case 3: ((struct Obj08371 *)p)->f20 = 2; func_02213808(a, 1); break;
        }
    }
    return 1;
}

/*
 * ABI exception: empty AE14 preserves its input pointer in r0, consumed here.
 */
unsigned *func_02213134(int unused, unsigned heap, u8 *p)
{
    unsigned *out;
    unsigned index, id, flag;
    unsigned zero = 0;
    void *reg;
    int a;
    unsigned b;
    out = func_02030734(heap, 0x18, 0, d_02213D04, 0x637);
    func_02082BCC(out, 0, 0x18);
    if (((struct Obj02248 *)p)->f1C == 3) {
        id = ((struct Obj02248 *)p)->f8 + 0x17;
    } else if (((struct Obj02248 *)p)->f1C == 2) {
        id = ((struct Obj02248 *)p)->f8 + 0x1c;
    } else {
        if (((struct Obj02248 *)p)->f1C == 0) index = zero;
        else if (((struct Obj02248 *)p)->f1C == 1) index = 1;
        else func_02034714(d_02213D00, zero, d_02213D00);
        reg = func_0200AE14(func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj02248 *)p)->f4)), index));
        a = func_0200AE54(reg, 0xd);
        b = func_0200AE54(reg, 0x15);
        if (a >= 2) a = 1;
        id = a + (b * 2 + 0x21);
    }
    flag = 1;
    out[0] = *(unsigned *)&((struct Obj02248 *)p)->f4;
    out[1] = flag;
    out[2] = 0;
    out[4] = id;
    out[5] = 0;
    if (((struct Obj02248 *)p)->f1C == 1) {
        out[3] = flag;
    } else {
        if (((struct Obj02248 *)p)->f1C4 == 0 && ((struct Obj02248 *)p)->f1C8 == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        out[3] = flag;
    }
    if (func_0200BA38((u8)((struct Obj25295 *)(*(u8 * *)&((struct Obj02248 *)p)->f2C))->f44) != 0) out[1] = 1;
    else out[1] = 0;
    return out;
}

int func_0221320C(char *p, char *q, char *work)
{
    func_020307B0(q);
    if (((struct Obj14576 *)work)->f1C == 1) func_02213808(p, 0);
    else {
        ((struct Obj14576 *)work)->f20 = 3;
        func_02213808(p, 1);
    }
    return 1;
}

void *func_02213234(void *unused, int heap, char *p)
{
    unsigned int *work = func_02030734(heap, 0x1c, 0, d_02213D04, 0x6b2);
    func_02082BCC(work, 0, 0x1c);
    work[0] = ((struct Obj14577 *)p)->f4;
    work[1] = 0;
    work[2] = 1;
    if (((struct Obj14577 *)p)->f24 != 0)
        work[4] = 0x12;
    return work;
}

int func_02213278(char *a, void *work, char *p)
{
    switch (((struct Obj14578 *)p)->f1C) {
    case 0:
        if (((struct Obj14578 *)p)->f24 != 0)
            func_0221380C((unsigned char *)a);
        else
            func_02213808(a, 0);
        break;
    case 1:
        func_02034714(d_02213D00, 0, d_02213D00);
        break;
    case 2:
    case 3:
        func_0221380C((unsigned char *)a);
        break;
    }
    func_020307B0(work);
    return 1;
}

/*
 * Scratch-only tails each EXACT 16B; blocker-0200BA58.log and blocker-0200BA68.log.
 * TU/suggest-split MATCH: no viable partition; the integrator owns ARM9 filing.
 * Verified blocker C (symbols: ov188_id 0x000000BC data a1;
 * func_02034AC4 0x02034AC4 arm; func_02034A5C 0x02034A5C arm):
 * extern const char ov188_id[];
 * extern void func_02034AC4(const void *);
 * extern void func_02034A5C(const void *);
 * void func_0200BA58(void) { func_02034AC4(ov188_id); }
 * void func_0200BA68(void) { func_02034A5C(ov188_id); }
 */
void *func_022132C4(void *unused, int heap, char *p)
{
    char *work = func_02030734(heap, 0xf0, 0, d_02213D04, 0x6f4);
    func_02082BCC(work, 0, 0xf0);
    func_02034AC4((s32)ov093_id);
    func_020130C4((u8 *)work);
    func_020138C4(work, *(void **)(p + 4), heap);
    func_02034A5C((s32)ov093_id);
    func_0200BA58();
    func_021EEEA8(work, heap);
    func_0200BA68();
    func_02034AC4((s32)ov093_id);
    func_02005D28();
    func_02005D90(*(unsigned short *)(work + 0x18), 0xffff);
    return work;
}

int func_02213338(char *p, char *q)
{
    func_02005D28();
    func_020307B0(((struct Obj01819 *)q)->f34);
    func_02013930((struct Obj *)q);
    func_020307B0(q);
    func_02034A5C((int)ov093_id);
    func_02213808(p, 0);
    return 1;
}

void func_0221336C(char *p, int heap)
{
    int size;
    ((struct Obj08373 *)p)->f28 = func_02030734(heap, func_0201A918() + 0xd4, 0, d_02213D04, 0x72d);
    size = func_0201A918() + 0xd4;
    func_02082BCC(((struct Obj08373 *)p)->f28, 0, size);
    ((struct Obj08373 *)p)->f2C = func_02030734(heap, func_0201A918() + 0xd4, 0, d_02213D04, 0x72f);
    size = func_0201A918() + 0xd4;
    func_02082BCC(((struct Obj08373 *)p)->f2C, 0, size);
}


/*
 * Addresses are Black-image addresses.
 */
void func_022133D0(u8 *p)
{
    func_020307B0((void *)(((struct Obj14579 *)p)->f28));
    func_020307B0((void *)(((struct Obj14579 *)p)->f2C));
}

void func_022133E4(u8 *p,void *party1,void *party2,u8 *save,void *reg,int setting,u8 *record,void *other,int mode)
{
    int i;
    unsigned zero = 0;
    void *mon;
    Date date;
    Triple time;
    Bytes_022133E4 bytes;
    func_02082BCC(p,0,0x50);
    ((struct Obj06660 *)p)->f0=func_0200853C((const struct Sub0200852CObj *)save);
    ((struct Obj06660 *)p)->f4=((struct Obj25296 *)save)->f48;
    for(i=0;i<(int)func_0201AA18(party2);i++) {
        mon=func_0201AB28(party2,i);
        if(func_02017E1C(mon,0xa9,0)) {
            *(u16 *)((unsigned)p+i*2+8)=func_02017E1C(mon,5,0);
            *(u8 *)((unsigned)p+i+0x14)=func_02017E1C(mon,0x6f,0);
            *(u8 *)((unsigned)p+i+0x1a)=func_02017E1C(mon,0x9e,0);
            *(u8 *)((unsigned)p+i+0x20)=func_02017E1C(mon,0x6e,0);
        }
    }
    for(i=0;i<(int)func_0201AA18(party1);i++) {
        mon=func_0201AB28(party1,i);
        if(func_02017E1C(mon,0xa9,zero)) {
            *(u16 *)((unsigned)p+i*2+0x26)=func_02017E1C(mon,5,zero);
            *(u8 *)((unsigned)p+i+0x32)=func_02017E1C(mon,0x6f,zero);
            *(u8 *)((unsigned)p+i+0x38)=func_02017E1C(mon,0x9e,zero);
            *(u8 *)((unsigned)p+i+0x3e)=func_02017E1C(mon,0x6e,zero);
        }
    }
    if(func_02167ED8(&date,&time)==0) func_02034714(d_02213D00,0,d_02213D00);
    ((Flags *)(p + 0x44))->year=date.a;
    ((Flags *)(p + 0x44))->month=date.b;
    ((Flags *)(p + 0x44))->day=date.c;
    ((Flags *)(p + 0x44))->hour=time.a;
    ((Flags *)(p + 0x44))->minute=time.b;
    ((struct Obj06660 *)p)->f48=setting;
    p[0x4c]=((struct Obj25297 *)record)->f8C;
    func_022135CC(record,&bytes.a,&bytes.b);
    ((Nibbles *)(p + 0x4e))->a=bytes.a;
    ((Nibbles *)(p + 0x4e))->b=bytes.b;
    p[0x4d]=func_0200AE54(reg,0x15);
    ((Flags *)(p + 0x44))->enabled=func_0200AE54(reg,0xd);
}

void func_022135CC(unsigned char *p, unsigned char *a, unsigned char *b)
{
    int i, index, j, count;
    int side, flags;
    i = 0;
    flags = p[0x21];
    *a = 0;
    *b = 0;
    side = flags & 1;
    for (; i <= 1; i++) {
        if ((i & 1) == side) {
            if (side != 0)
                index = (i & 2) + 1;
            else
                index = i & 2;
            count = func_0201AA18(*(void **)(p + 0x24 + index * 4));
            for (j = 0; j < count; j++) {
                if (p[0xc8 + index * 6 + j] != 2)
                    (*a)++;
            }
        } else {
            if (side != 0)
                index = i & 2;
            else
                index = (i & 2) + 1;
            count = func_0201AA18(*(void **)(p + 0x24 + index * 4));
            for (j = 0; j < count; j++) {
                if (p[0xc8 + index * 6 + j] != 2)
                    (*b)++;
            }
        }
    }
}

void func_02213684(const unsigned char *p, unsigned char *a, unsigned char *b)
{
    int i, index;
    int side, flags;
    flags = p[0x21];
    *a = 0;
    *b = 0;
    side = flags & 1;
    for (i = 0; i <= 1; i++) {
        if ((i & 1) == side) {
            if (side != 0)
                index = (i & 2) + 1;
            else
                index = i & 2;
            *a = *(unsigned int *)(p + 0xe0 + index * 4);
        } else {
            if (side != 0)
                index = i & 2;
            else
                index = (i & 2) + 1;
            *b = *(unsigned int *)(p + 0xe0 + index * 4);
        }
    }
}

void *func_022136E4(void *a, void *b, void *c, int heap)
{
    char *work = func_02030734(heap, 0x20, 0, d_02213D04, 0x846);
    func_02082BCC(work, 0, 0x20);
    ((struct Obj06661 *)work)->f0 = func_02031324(heap);
    ((struct Obj06661 *)work)->fC = c;
    ((struct Obj06661 *)work)->f10 = a;
    ((struct Obj06661 *)work)->f14 = b;
    ((struct Obj06661 *)work)->f8 = heap;
    return work;
}

void func_0221372C(char *p)
{
    if (((struct Obj14584 *)p)->f4) func_02034714(d_02213D00, 0, d_02213D00);
    func_0203133C(((struct Obj14584 *)p)->f0);
    func_020307B0(p);
}


/*
 * lever: case 3 as if (h) { if (h(..) != 0) { f4 = 0; f1b = 4; } } else { f1b = 4; }
 * gives the lone branch to the next instruction; the case 1 second veneer
 * argument is written `f10 + 4 + (f1a << 4)` so its add follows the first load.
 */
int func_02213754(S *s)
{
    switch (s->f1b) {
    case 0:
        s->f18 = s->f1a;
        s->f1a = s->f19;
        s->f1b = 1;
        break;
    case 1: {
        int (*r)(S *, int, int);
        r = *(int (**)(S *, int, int))((char *)s->f10 + (s->f1a << 4) + 8);
        if (r)
            s->f4 = r(s, s->f8, s->fc);
        else
            s->f4 = 0;
        func_02031348(s->f0,
                        *(int *)((char *)s->f10 + (s->f1a << 4)),
                        *(int *)((char *)s->f10 + 4 + (s->f1a << 4)),
                        s->f4);
        s->f1b = 2;
        break;
    }
    case 2:
        s->f1c = func_02031330(s->f0);
        if (s->f1c == 0)
            s->f1b = 3;
        break;
    case 3: {
        int (*h)(S *, int, int);
        h = *(int (**)(S *, int, int))((char *)s->f10 + (s->f1a << 4) + 0xc);
        if (h) {
            if (h(s, s->f4, s->fc) != 0) {
                s->f4 = 0;
                s->f1b = 4;
            }
        } else {
            s->f1b = 4;
        }
        break;
    }
    case 4:
        if (s->f19 == 0xff)
            s->f1b = 5;
        else
            s->f1b = 0;
        break;
    case 5:
        return 1;
    }
    return 0;
}

int func_02213800(char *p)
{
    return ((struct Obj25299 *)p)->f1C;
}

unsigned char func_02213804(char *p)
{
    return ((struct Obj25300 *)p)->f18;
}

void func_02213808(char *p, int value)
{
    ((struct Obj25301 *)p)->f19 = value;
}

/*
 * extent: final two bytes are alignment padding.
 */
void func_0221380C(unsigned char *p){p[0x19]=255;}

int func_02213814(struct Obj0203159C *p,int unused,char *q){void *r;func_0203064C(1,88,336);r=func_0203159C(p,16,88);func_02082BCC(r,0,16);((struct Obj25303 *)q)->fC=0;((struct Obj25304 *)r)->f0=func_02031324(88);func_02005E30(16);return 1;}

int func_02213850(void *a, void *b, void *c, char *work)
{
    if (((struct Obj06662 *)work)->f8) {
        func_02034A5C((int)ov093_id);
        ((struct Obj06662 *)work)->f8 = 0;
    }
    if (((struct Obj06662 *)work)->fC) {
        func_0203A5E4(0x100);
        ((struct Obj06662 *)work)->fC = 0;
    }
    func_0203133C(((struct Obj06662 *)work)->f0);
    func_020315D4(a);
    func_020306F0(0x58);
    return 1;
}
