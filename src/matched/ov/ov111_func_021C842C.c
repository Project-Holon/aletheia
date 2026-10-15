/*
 * function: VIEWER_ACTOR_HandleTouchDrag
 * address:  0x021C842C
 * packet:   pkt_ov111_021C842C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_021C83DC  0x021C83DC  thumb  ov111
 *   func_021C840C  0x021C840C  thumb  ov111
 *   func_021C8414  0x021C8414  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

extern unsigned int TOUCHPANEL_GetPointCont(u32 *a, u32 *b);
extern void func_021C83DC(u8 *p, int value);
extern void func_021C840C(u8 *p);
extern void func_021C8414(u8 *p, int idx);

typedef struct {
    u8 pad0[0x17C];
    u8 active[8];
    u8 pad184[4];
    int count[8];
    u8 pad1A8[0x10];
    u8 cursor[2];
    s8 sx;
    s8 sy;
    u8 pad1BC[4];
    u32 prevX;
    u32 prevY;
} Work;

#define PREV_X (p->prevX)

static inline int Delta(s8 *dir, u32 prev, u32 cur)
{
    int d;

    if (prev > cur) {
        d = prev - cur;
        *dir = -1;
    } else {
        d = cur - prev;
        *dir = 1;
    }
    return d;
}
#define PREV_Y (p->prevY)

void VIEWER_ACTOR_HandleTouchDrag(Work *p, int idx)
{
    int hit = 0;
    u32 x = 0xFFFF;
    u32 y = 0xFFFF;
    int dx, dy;
    s8 s;

    TOUCHPANEL_GetPointCont(&x, &y);
    if (x != 0xFFFF && y != 0xFFFF && PREV_X != 0xFFFF && PREV_Y != 0xFFFF && idx != -1
        && (u32)idx < 8 && p->active[idx] != 0) {
        dx = Delta(&p->sx, PREV_X, x);
        if (dx >= 3 && dx <= 40) {
            dy = Delta(&p->sy, PREV_Y, y);
            if (dy <= 40) {
                hit = 1;
                func_021C83DC(p->cursor, p->count[idx]);
            } else {
                func_021C840C(p->cursor);
            }
        } else if (dx <= 40) {
            dy = Delta(&p->sy, PREV_Y, y);
            if (dy >= 3 && dy <= 40) {
                hit = 1;
                func_021C83DC(p->cursor, p->count[idx]);
            } else {
                func_021C840C(p->cursor);
            }
        }
        if (hit) {
            func_021C8414((u8 *)p, idx);
        }
    }
    PREV_X = x;
    PREV_Y = y;
}
