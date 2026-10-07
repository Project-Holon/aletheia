/*
 * file:     worldtrade_box_p01.c
 * unit:     yes
 * function: func_021F4580, func_021F46A8, func_021F47C0, func_021F4864
 * address:  0x021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02202608  0x02202608  thumb
 *   func_022026D8  0x022026D8  thumb
 *   func_021F489C  0x021F489C  thumb
 *   func_021F5074  0x021F5074  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   func_0203CD98 0x0203CD98 arm
 *   func_0205D074 0x0205D074 arm
 *   func_021F4EB4 0x021F4EB4 thumb ov135
 *   func_020370F4 0x020370F4 arm
 *   func_021C7C1C 0x021C7C1C arm ov114
 *   func_02031330 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02202770 0x02202770 thumb ov135
 *   func_021F49A8 0x021F49A8 thumb ov135
 *   func_020221A4 0x020221A4 thumb
 *   func_021FF6A4 0x021FF6A4 thumb ov135
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_021F4F84 0x021F4F84 thumb ov135
 *   func_0204A600 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_021F49A4 0x021F49A4 thumb ov135
 *   func_02045C04 0x02045C04 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203133C 0x0203133C arm
 *   func_02202744 0x02202744 thumb ov135
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../../matched/include/Obj02853.h"
#include "../../matched/include/Obj02854.h"

struct Ctx;
struct MsgBank;
struct WordSet;
struct Obj0203159C;
struct Rec;
struct S020314B8;
struct S020315D4;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args;

typedef struct {
    u8 pad0[0xB68];
    void *words;
    void *msg[5];
    u8 padB80[0xEA8 - 0xB80];
    void *mon;
    u8 padEAC[0xF94 - 0xEAC];
    void *rec;
    u8 padF98[0xF9C - 0xF98];
    void *recMem;
    u8 ctx[0x12F0 - 0xFA0];
    void *save;
    u8 pad12F4[0x132C - 0x12F4];
} Work_021F4580;

typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;

typedef void (*Cb)(void *p);

typedef struct {
    u8 pad0[0xEBC];
    Cb once;
    Cb every;
} Work_021F4864;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_02031324(int a0);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_022026D8(void *ctx, u32 arg);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021F489C(Work_021F4580 *p, Args *args);
extern void func_0204335C(u32 keep);
extern void func_021F5074(Work_021F4580 *p);
extern void func_02005DE4(void *p);
extern void func_02005D28(void);
extern int func_0203CD98(void);
extern int func_0205D074(void);
extern int func_021F4EB4(void);
extern u32 func_020370F4(u32);
extern void func_021C7C1C(void);
extern u32 func_02031330(void *);
extern void func_02030D28(struct Ctx *c);
extern void func_02202770(void *);
extern void func_021F49A8(void);
extern u32 func_020221A4(void);
extern void func_021FF6A4(u8 *);
extern void func_021FFB20(u8 *, int, int);
extern void func_021F4F84(u8 *);
extern void func_0204A600(void *);
extern void func_021F50EC(u8 *);
extern void func_021F49A4(void *a0);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02202744(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(s32 handle);
extern void func_020419E4(void);
extern void func_0204A648(void);
int func_021F4580(void *proc, int *seq, Args *args);
int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p);
int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p);
void func_021F4864(void *unused, Work_021F4864 *p);
extern u8 ov114_id[];
extern u8 ov067_id[];
extern Work_021F4580 *g_02203F80;
extern const char str_02203AF8[];
extern const Handler d_02203A80[];


int func_021F4580(void *proc, int *seq, Args *args)
{
    Work_021F4580 *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x48, 0x30100);
    p = func_0203159C(proc, sizeof(Work_021F4580), 0x48);
    func_02082BCC(p, 0, sizeof(Work_021F4580));
    g_02203F80 = p;
    p->mon = func_02202608(0x48);
    p->save = func_02031324(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec = func_02030CBC(8, p->recMem);
    func_022026D8(p->ctx, args->x20);
    p->words = func_0201EC74(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    func_021F489C(p, args);
    func_0204335C(0);
    func_021F5074(p);
    func_02005DE4(0);
    func_02005D28();
    return 1;
}

int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p)
{
    if (func_0203CD98() != 0) {
        func_0205D074();
        func_020370F4(func_021F4EB4());
    }
    func_021C7C1C();
    ((struct Obj02853 *)p)->f12F4 = func_02031330(((struct Obj02853 *)p)->f12F0);
    func_02030D28(((struct Obj02853 *)p)->fF94);
    func_02202770(p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[*(u32 *)(p + 16)].init(p, *state);
        func_021F49A8();
        break;
    case 1:
        if (func_020221A4() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[*(u32 *)(p + 16)].update(p, *state);
        break;
    case 3:
        if (func_020221A4() != 0) {
            *state = d_02203A80[*(u32 *)(p + 16)].finish(p, *state);
            if (((struct Obj02853 *)p)->fB8 != 0) {
                func_021FF6A4(p);
                func_021FFB20(p, ((struct Obj02853 *)p)->fD0, 0);
                ((struct Obj02853 *)p)->fB8 = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    func_021F4F84(p);
    if (*(u32 *)&((struct Obj02853 *)p)->fBC0 != 0) func_0204A600(((struct Obj02853 *)p)->fBC0);
    if (((struct Obj02853 *)p)->f12E8 > 0) ((struct Obj02853 *)p)->f12E8 -= 1;
    return 0;
}

int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p)
{
    func_02005D28();
    func_021F50EC(p);
    func_021F49A4(p);
    func_02045C04(((struct Obj02854 *)p)->fB70);
    func_02045C04(((struct Obj02854 *)p)->fB78);
    func_02045C04(((struct Obj02854 *)p)->fB74);
    func_02045C04(((struct Obj02854 *)p)->fB6C);
    func_02045C04(((struct Obj02854 *)p)->fB7C);
    func_0201ED04(((struct Obj02854 *)p)->fB68);
    func_02030DA4(((struct Obj02854 *)p)->fF94);
    func_020307B0(((struct Obj02854 *)p)->fF9C);
    func_0203133C(((struct Obj02854 *)p)->f12F0);
    func_020307B0(((struct Obj02854 *)p)->fEA8);
    func_02202744(p + 0xfa0);
    func_020315D4(ctx);
    func_020306F0(0x48);
    func_02034A5C((unsigned int)ov067_id);
    func_02034A5C((unsigned int)ov114_id);
    return 1;
}


void func_021F4864(void *unused, Work_021F4864 *p)
{
    func_020419E4();
    func_0204A648();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}
