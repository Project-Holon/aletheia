/*
 * function: func_021C8F24
 * address:  0x021C8F24
 * packet:   pkt_ov093_021C8F24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C8F94  0x021C8F94  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_ChangeHp  0x021C5B74  thumb  ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction  0x021C195C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021C8F94(int a, u8 b);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_SERVER_FLOW_ChangeHp(u8 *p, u8 *a, int c, int d);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);

typedef struct {
    u32 w; u8 n; u8 b5; u8 b6; u8 ids[9]; u32 v[4];
} Ent;

typedef struct { int pad0; int pad1; char *f8; } P;

int func_021C8F24(P *pp, const Ent *e)
{
    int p = (int)pp;
    int r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        if (func_021C8F94(p + 0x1ab8, e->ids[i])) {
            a = func_021B9934(pp->f8, e->ids[i]);
            if (BTL_POKEPARAM_IsFainted(a) == 0) {
                BTL_SERVER_FLOW_ChangeHp((u8 *)p, a, e->v[i], !e->b5);
                if (e->b6 == 0)
                    BTL_SERVER_FLOW_ProcDamagedItemReaction((u8 *)p, a, 1);
                r = 1;
            }
        }
    }
    return r;
}
