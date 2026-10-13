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
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021C57DC  0x021C57DC  thumb  ov127
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
extern int func_021C49A4(u8 *p, unsigned int i);
extern void func_021C57D8(u8 *p, int v);
extern void func_021C57DC(u8 *p);
extern void WIFICLUBACTOR_QueueActorMove(void *a, int b, u8 **p);

void WIFICLUBACTOR_StartDespawn(void *o, Ent *e)
{
    func_021C49A4(e->f0, 6);
    e->f10 = 0x021BA521;
    e->f8 = 0;
    e->f18 = 0x021BA2D5;
    e->fc = 2;
    func_021C57D8(e->f4, 0);
    func_021C57DC(e->f4);
    WIFICLUBACTOR_QueueActorMove(o, 4, (u8 **)e);
}
