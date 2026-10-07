/*
 * file:     comm_player_p07.c
 * unit:     yes
 * function: func_02167BFC, func_02167CB4
 * address:  0x02167BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02167B44  0x02167B44  thumb
 *   func_02167B9C  0x02167B9C  thumb
 *   func_02167BB4  0x02167BB4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02167BCC  0x02167BCC  thumb
 *   func_02167BD8  0x02167BD8  thumb
 *   func_02167BE4  0x02167BE4  thumb
 *   func_02167BF0  0x02167BF0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */
#include "../../matched/include/Obj00116.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

typedef struct Obj_02167BFC {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x20];
} Obj_02167BFC;

typedef struct Obj_02167CB4 {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x1C];
} Obj_02167CB4;

extern void func_02167B44(Obj_02167BFC *o, void *t);
extern void func_02167B9C(Obj_02167BFC *o);
extern void func_02167BB4(Obj_02167BFC *o, u32 v);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *a, void *b);
extern void func_02167BCC(Obj_02167BFC *o);
extern void func_02167BD8(Obj_02167BFC *o, u32 v);
extern void func_02167BE4(Obj_02167BFC *o, u32 v);
extern void func_02167BF0(Obj_02167BFC *o, u32 v);
extern u32 func_0200FB24(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02167BFC(Obj_02167BFC *o, u32 cmd, u32 arg);
int func_02167CB4(Obj_02167CB4 *o);


/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void func_02167BFC(Obj_02167BFC *o, u32 cmd, u32 arg)
{
    void *t;

    t = ((struct Obj00116 *)o)->f6C;
    switch (cmd) {
    case 0:
        o->h12 = 0x2C00;
        func_02167B44(o, t);
        return;
    case 1:
        o->h12 = 0x2C01;
        func_02167B9C(o);
        return;
    case 2:
        o->h12 = 0x2C02;
        func_02167BB4(o, arg);
        return;
    case 3:
        o->h12 = 0x2C03;
        func_02008494(func_02012944(t), o->b668);
        return;
    case 4:
        o->h12 = 0x2C04;
        func_02167BCC(o);
        return;
    case 5:
        o->h12 = 0x2C05;
        func_02167BD8(o, arg);
        return;
    case 6:
        o->h12 = 0x2C06;
        func_02167BE4(o, arg);
        return;
    case 7:
        o->h12 = 0x2C07;
        func_02167BF0(o, arg);
        return;
    default:
        o->h12 = 0x2C08;
        return;
    }
}


int func_02167CB4(Obj_02167CB4 *o)
{
    u16 h;

    if (func_0200FB24() != 0)
        return 1;
    h = o->h12;
    if (h >= 0x2C08)
        return 1;
    if (func_0203D3A8(func_020399A8(), h, 0x46, (u32)o->b668) == 1)
        return 1;
    return 0;
}
