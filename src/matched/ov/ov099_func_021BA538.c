/*
 * unit:     yes
 * function: WIFICLUBACTOR_UpdateIdleWander, WIFICLUBACTOR_UpdateBounce, WIFICLUBACTOR_UpdateNone
 * address:  0x021BA538
 * packet:   pkt_ov099_021BA538
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * WIFICLUBACTOR_UpdateBounce (counter reload leaf) and WIFICLUBACTOR_UpdateNone (returns 0) are
 * the unlabelled leaves after the lead function (seed function_starts
 * 0x021BA578, 0x021BA590).
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   WIFICLUBACTOR_QueueMoveCommand  0x021BA594  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
} S;

typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern void WIFICLUBACTOR_QueueMoveCommand(char *p, int a, int b, int c);

int WIFICLUBACTOR_UpdateIdleWander(void *w, S *s)
{
    int r;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        s->f8 = func_020056EC(0x400) + 0x100;
        r = func_020056EC(4);
        WIFICLUBACTOR_QueueMoveCommand(w, 0, r, WF2DMAP_OBJ_GetSlot(s->f0, 4));
    }
    return 0;
}

int WIFICLUBACTOR_UpdateBounce(void *w, S *s)
{
    s->f8 = s->f8 - 1;
    if (s->f8 < 0) {
        s->f8 = 0x1c;
    }
    return 0;
}

int WIFICLUBACTOR_UpdateNone(void)
{
    return 0;
}
