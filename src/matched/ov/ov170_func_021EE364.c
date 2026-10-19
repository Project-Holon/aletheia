/*
 * function: BOX2_UI_MoveCursor
 * address:  0x021EE364
 * packet:   pkt_ov170_021EE364
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   BOX2_UI_DeleteCursorMove 0x021EE3CC thumb
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   BOX2_UI_UpdateCursor 0x021EE408 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   d_021F02F0 0x021F02F0 data
 */
#include "../include/Obj24031.h"
#include "../include/Obj24032.h"
#include "../include/Obj24033.h"
#include "../include/Obj24034.h"

typedef struct { unsigned a; unsigned b; } Pair;
typedef unsigned int   u32;
struct Sound;
struct Struct_02025D1C;
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void BOX2_UI_DeleteCursorMove(int *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void CURSOR_MOVE_EnableInput(struct Struct_02025D1C *obj);
extern void BOX2_UI_UpdateCursor(char *p, int v);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern const Pair d_021F02F0[];

void BOX2_UI_MoveCursor(char **p, int idx, int v)
{
    int r = CURSOR_MOVE_GetState(((struct Obj24031 *)(p[11]))->f70);
    BOX2_UI_DeleteCursorMove((int *)p);
    ((struct Obj24032 *)(p[11]))->f70 = CURSOR_MOVE_Create(d_021F02F0[idx].a, d_021F02F0[idx].b, (u32)p, r, v, 0x4C);
    CURSOR_MOVE_EnableInput(((struct Obj24033 *)(p[11]))->f70);
    BOX2_UI_UpdateCursor((char *)p, v);
    BOX2_SEQ_SetCursorDraw(p, r);
    ((struct Obj24034 *)(p[11]))->fA168 = v;
}
