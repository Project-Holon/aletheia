/*
 * function: BSUBWAY_COMM_SetSendData
 * address:  0x02167BFC
 * packet:   pkt_ov010_02167BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BSUBWAY_COMM_SetSendPlayerData  0x02167B44  thumb
 *   BSUBWAY_COMM_SetSendTrainerData  0x02167B9C  thumb
 *   BSUBWAY_COMM_SetSendRetireSelect  0x02167BB4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   BSUBWAY_COMM_SetSendPlayMode  0x02167BCC  thumb
 *   BSUBWAY_COMM_SetSendWord5  0x02167BD8  thumb
 *   BSUBWAY_COMM_SetSendWord6  0x02167BE4  thumb
 *   BSUBWAY_COMM_SetSendWord7  0x02167BF0  thumb
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
#include "../include/Obj00116.h"

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

typedef struct Obj {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x20];
} Obj;

extern void BSUBWAY_COMM_SetSendPlayerData(Obj *o, void *t);
extern void BSUBWAY_COMM_SetSendTrainerData(Obj *o);
extern void BSUBWAY_COMM_SetSendRetireSelect(Obj *o, u32 v);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *a, void *b);
extern void BSUBWAY_COMM_SetSendPlayMode(Obj *o);
extern void BSUBWAY_COMM_SetSendWord5(Obj *o, u32 v);
extern void BSUBWAY_COMM_SetSendWord6(Obj *o, u32 v);
extern void BSUBWAY_COMM_SetSendWord7(Obj *o, u32 v);

void BSUBWAY_COMM_SetSendData(Obj *o, u32 cmd, u32 arg)
{
    void *t;

    t = ((struct Obj00116 *)o)->f6C;
    switch (cmd) {
    case 0:
        o->h12 = 0x2C00;
        BSUBWAY_COMM_SetSendPlayerData(o, t);
        return;
    case 1:
        o->h12 = 0x2C01;
        BSUBWAY_COMM_SetSendTrainerData(o);
        return;
    case 2:
        o->h12 = 0x2C02;
        BSUBWAY_COMM_SetSendRetireSelect(o, arg);
        return;
    case 3:
        o->h12 = 0x2C03;
        MYSTATUS_Copy(GAME_DATA_GetMyStatus(t), o->b668);
        return;
    case 4:
        o->h12 = 0x2C04;
        BSUBWAY_COMM_SetSendPlayMode(o);
        return;
    case 5:
        o->h12 = 0x2C05;
        BSUBWAY_COMM_SetSendWord5(o, arg);
        return;
    case 6:
        o->h12 = 0x2C06;
        BSUBWAY_COMM_SetSendWord6(o, arg);
        return;
    case 7:
        o->h12 = 0x2C07;
        BSUBWAY_COMM_SetSendWord7(o, arg);
        return;
    default:
        o->h12 = 0x2C08;
        return;
    }
}
