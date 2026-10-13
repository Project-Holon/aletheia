/*
 * function: SWEET_SCENT_FadeMain
 * address:  0x021C622C
 * packet:   pkt_ov021_021C622C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SWEET_SCENT_FadeSetup  0x021C62F0  thumb  ov021
 *   SWEET_SCENT_FadeCleanup  0x021C6368  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLD_VREQ_SetMainBlendAlphaEv  0x021D3288  thumb  ov021
 *   FLD_VREQ_SetMainBlendAlpha  0x021D325C  thumb  ov021
 *   FLD_VREQ_SetBgVisible  0x021D3244  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    void *f4;
} Ctx;

extern void SWEET_SCENT_FadeSetup(u8 *p);
extern void SWEET_SCENT_FadeCleanup(u8 *p);
typedef unsigned int   u32;
struct St021D3244;
struct St021D325C;
extern void func_020061E4(u32 a);
extern void FLD_VREQ_SetMainBlendAlphaEv(void *a, int b, int c);
extern void FLD_VREQ_SetMainBlendAlpha(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void FLD_VREQ_SetBgVisible(struct St021D3244 *p, int i, u8 v);

int SWEET_SCENT_FadeMain(void *unused, int *st, Ctx *c)
{
    switch (*st) {
    case 0:
        SWEET_SCENT_FadeSetup((u8 *)c);
        func_020061E4(0x683);
        *st = *st + 1;
        break;
    case 1:
        if (c->f3++ >= c->f2) {
            c->f1++;
            FLD_VREQ_SetMainBlendAlphaEv(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 >= 8) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (c->f3++ < 0x1e) {
            *st = *st + 1;
        }
        break;
    case 3:
        if (c->f3++ >= c->f2) {
            c->f1--;
            FLD_VREQ_SetMainBlendAlphaEv(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 == 0) {
            *st = *st + 1;
        }
        break;
    case 4:
        FLD_VREQ_SetMainBlendAlpha(c->f4, 0, 0, 0, 0x1f);
        FLD_VREQ_SetBgVisible(c->f4, c->f0, 0);
        *st = *st + 1;
        break;
    default:
        SWEET_SCENT_FadeCleanup((u8 *)c);
        return 1;
    }
    return 0;
}
