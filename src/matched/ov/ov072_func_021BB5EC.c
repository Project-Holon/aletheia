/*
 * function: TOWNMAP_GRH_UpdateTouch
 * address:  0x021BB5EC
 * packet:   pkt_ov072_021BB5EC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Mag  0x0207CBD0  arm
 */
typedef unsigned int u32;

struct V { int x; int y; int z; };
struct Obj {
    struct V a;
    struct V b;
    int f18;
    int f1c;
    int f20;
    struct V c;
};

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void VEC_Subtract(struct V *a, struct V *b, struct V *c);
extern int VEC_Mag(struct V *a);

void TOWNMAP_GRH_UpdateTouch(struct Obj *p)
{
    u32 y;
    u32 x;

    p->f1c = 0;
    if (TOUCHPANEL_GetPointTrg(&y, &x)) {
        if (x <= 0xA8) {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
        return;
    }
    if (TOUCHPANEL_GetPointCont(&y, &x)) {
        if (x <= 0xA8) {
            if (p->f20 != 0) {
                p->a = p->b;
                p->f20 = 0;
            }
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
            VEC_Subtract(&p->b, &p->a, &p->c);
            if (VEC_Mag(&p->c) >= 0x1000) {
                p->f1c = 1;
            }
        } else {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
    }
}
