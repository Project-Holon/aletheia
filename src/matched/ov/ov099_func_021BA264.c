/*
 * function: WIFICLUBACTOR_SetIdleState
 * address:  0x021BA264
 * packet:   pkt_ov099_021BA264
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: n = 0x400 in a u32 local keeps 0x400>>2 a runtime lsrs.
 * WIFICLUBACTOR_NoOpAnim is the empty callback filed as its own ov099 leaf.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   WIFICLUBACTOR_QueueActorMove  0x021BA5B4  thumb  ov099
 *   WF2DMAP_OBJDRAW_SetActive  0x021C57D8  thumb  ov127
 *   WIFICLUBACTOR_UpdateIdleWander  0x021BA538  thumb  ov099
 *   WIFICLUBACTOR_NoOpAnim  0x021BA2D0  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
    void *f10;
    void *f14;
    void *f18;
} S;

extern u32 func_020056EC(u32 x);
extern void WIFICLUBACTOR_QueueActorMove(void *a, int b, u8 **p);
extern void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v);
extern int WIFICLUBACTOR_UpdateIdleWander(void *w, S *s);
extern void WIFICLUBACTOR_NoOpAnim(void);

void WIFICLUBACTOR_SetIdleState(void *w, S *s)
{
    u32 n;

    s->f10 = (void *)WIFICLUBACTOR_UpdateIdleWander;
    s->f18 = (void *)WIFICLUBACTOR_NoOpAnim;
    n = 0x400;
    s->f8 = func_020056EC(n) + (n >> 2);
    s->fc = 3;
    WIFICLUBACTOR_QueueActorMove(w, 0, (u8 **)s);
    WF2DMAP_OBJDRAW_SetActive(s->f4, 1);
}
