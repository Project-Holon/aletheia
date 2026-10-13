/*
 * function: BEACON_VIEW_LoadNextRecord
 * address:  0x021F0140
 * packet:   pkt_ov032_021F0140
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_TablePop  0x021658D4  thumb  ov010
 *   func_021F1268  0x021F1268  thumb  ov032
 *   GAME_BEACON_ACCESSOR_IsInfoInvalid  0x02165B5C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_TableRingAdd  0x02165A10  thumb  ov010
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex  0x021659F0  thumb  ov010
 *   func_021F0F44  0x021F0F44  thumb  ov032
 *   func_0200C1E0  0x0200C1E0  thumb
 */
#include "../include/Obj00188.h"
#include "../include/Obj20414.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk34;
struct Queue;
struct Rec;
extern int GAME_BEACON_ACCESSOR_TablePop(struct Queue *q, struct Rec *out, u16 *tag);
extern void func_021F1268(char *this);
extern int GAME_BEACON_ACCESSOR_IsInfoInvalid(struct Rec *r);
extern int GAME_BEACON_ACCESSOR_TableRingAdd(struct Queue *q, struct Rec *rec, u16 tag, int *flag);
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, int a);
extern u32 func_0200C1E0(struct Blk34 *p);

int BEACON_VIEW_LoadNextRecord(u8 *p)
{
    u8 t;

    if (GAME_BEACON_ACCESSOR_TablePop((struct Queue *)(((struct Obj00188 *)p)->f38), (struct Rec *)(((struct Obj00188 *)p)->f4C), (u16 *)(p + 0x4A)) == 0) {
        func_021F1268((char *)p);
        return 0;
    }
    if (GAME_BEACON_ACCESSOR_IsInfoInvalid((struct Rec *)(((struct Obj00188 *)p)->f4C)) != 0)
        return 0;
    p[0x54] = GAME_BEACON_ACCESSOR_TableRingAdd((struct Queue *)(((struct Obj00188 *)p)->f3C), (struct Rec *)(((struct Obj00188 *)p)->f4C), ((struct Obj00188 *)p)->f4A, (int *)(p + 0x5C));
    p[0x55] = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(((struct Obj00188 *)p)->f3C), p[0x54]);
    if (((struct Obj00188 *)p)->f5C == 0) {
        *(u8 * *)&((struct Obj00188 *)p)->f50 = func_021F0F44(p, p[0x55]);
    } else {
        *(u8 * *)&((struct Obj00188 *)p)->f50 = 0;
        ((struct Obj00188 *)p)->f2D4 = func_0200C1E0((struct Blk34 *)(((struct Obj00188 *)p)->f14));
    }
    if (*(u8 * *)&((struct Obj00188 *)p)->f50 != 0 && ((struct Obj20414 *)(*(u8 * *)&((struct Obj00188 *)p)->f50))->f2C != 0)
        ((struct Obj00188 *)p)->f6C = 0;
    else
        ((struct Obj00188 *)p)->f6C = 1;
    t = p[0x7B];
    p[0x57] = t;
    if (t < 0x1E) {
        p[0x7B] += (u8)((struct Obj00188 *)p)->f5C;
        if (p[0x7B] <= 4)
            p[0x7D] = p[0x7B];
    }
    return 1;
}
