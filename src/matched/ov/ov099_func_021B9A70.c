/*
 * function: WIFICLUBACTOR_StartTurn
 * address:  0x021B9A70
 * packet:   pkt_ov099_021B9A70
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActive  0x021C57D8  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetFrameZero  0x021C5864  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActorPos  0x021C5814  thumb  ov127
 *   WIFICLUBACTOR_QueueMoveCommand  0x021BA594  thumb
 */
typedef struct {
    short x, y;
} Pos;

typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    unsigned short fc;
    unsigned short fe;
    int f10;
    int f14;
    int f18;
} Ent;

typedef unsigned char  u8;
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v);
extern void WF2DMAP_OBJDRAW_SetFrameZero(u8 *p, int b);
extern void WF2DMAP_OBJDRAW_SetActorPos(void *p, Pos pos);
extern void WIFICLUBACTOR_QueueMoveCommand(char *p, int a, int b, int c);

void WIFICLUBACTOR_StartTurn(void *o, Ent *e, int n)
{
    Pos s;

    e->f14 = e->f10;
    e->f10 = 0x021BA591;
    e->fe = e->fc;
    e->fc = 5;
    WIFICLUBACTOR_QueueMoveCommand(o, 0, n, WF2DMAP_OBJ_GetSlot(e->f0, 4));
    WF2DMAP_OBJDRAW_SetActive(e->f4, 0);
    WF2DMAP_OBJDRAW_SetFrameZero(e->f4, n);
    s.x = WF2DMAP_OBJ_GetSlot(e->f0, 0);
    s.y = WF2DMAP_OBJ_GetSlot(e->f0, 1);
    WF2DMAP_OBJDRAW_SetActorPos(e->f4, s);
}
