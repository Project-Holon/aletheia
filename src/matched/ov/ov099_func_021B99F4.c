/*
 * function: WIFICLUBACTOR_StartDespawn
 * address:  0x021B99F4
 * packet:   pkt_ov099_021B99F4
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
 *   WF2DMAP_OBJDRAW_SetFrameDefault  0x021C57DC  thumb  ov127
 *   WIFICLUBACTOR_QueueActorMove  0x021BA5B4  thumb
 */
typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    short fc;
    short pad2;
    int f10;
    int f14;
    int f18;
} Ent;

typedef unsigned char  u8;
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v);
extern void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *p);
extern void WIFICLUBACTOR_QueueActorMove(void *a, int b, u8 **p);

void WIFICLUBACTOR_StartDespawn(void *o, Ent *e)
{
    WF2DMAP_OBJ_GetSlot(e->f0, 6);
    e->f10 = 0x021BA521;
    e->f8 = 0;
    e->f18 = 0x021BA2D5;
    e->fc = 2;
    WF2DMAP_OBJDRAW_SetActive(e->f4, 0);
    WF2DMAP_OBJDRAW_SetFrameDefault(e->f4);
    WIFICLUBACTOR_QueueActorMove(o, 4, (u8 **)e);
}
