/*
 * function: BTLV_INPUT_BgScrollTaskMain
 * address:  0x02204438
 * packet:   pkt_ov094_02204438
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MTX_Scale22_  0x0207AD58  thumb
 *   func_02040820  0x02040820  arm
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 */
typedef unsigned int u32;

typedef struct Ctx {
    char *main;
    int cur;
    int target;
    int step;
    int ang;
} Ctx;

extern void MTX_Scale22_(void *dst, int a, int b);
extern void func_02040820(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_BgScrollTaskMain(int a0, Ctx *c)
{
    int m[4];

    c->cur = c->cur + c->step;
    if (c->step > 0)
        c->ang = c->ang - 2;
    else if (c->step < 0)
        c->ang = c->ang + 2;
    MTX_Scale22_(m, c->cur, c->cur);
    func_02040820(7, 0, 0x80, (u32)m, 0x100, 0x100);
    func_02040820(7, 3, c->ang, (u32)m, 0x100, 0x100);
    if (c->cur == c->target)
        BTLV_INPUT_DeleteTask(c->main, (void *)a0);
}
