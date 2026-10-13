/*
 * function: INTRUDE_COMM_GetPartnerSlot
 * address:  0x021767A0
 * packet:   pkt_ov011_021767A0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8  pad[0x86];
    u16 v : 3;
} Rec;

struct BigObj;
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);

u8 INTRUDE_COMM_GetPartnerSlot(void *a, void *b)
{
    u8 x;
    u8 y;
    Rec *r;

    x = (int)GAME_DATA_GetExitMode(b);
    r = (Rec *)INTRUDE_COMM_GetWorkIfRunning((int)a);
    if (func_0200FB24()) {
        y = (int)GAME_DATA_GetIntrudeId(b);
        if (y == x) {
            return 4;
        }
        return y;
    }
    if (r != 0) {
        if (r->v == x) {
            return 4;
        }
        return r->v;
    }
    return 4;
}
