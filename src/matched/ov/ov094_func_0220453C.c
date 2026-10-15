/*
 * function: BTLV_INPUT_BgWipeTaskMain
 * address:  0x0220453C
 * packet:   pkt_ov094_0220453C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 */
typedef struct Ctx {
    char *main;
    int state;
    int a8;
    int ac;
    int d10;
    int cnt;
} Ctx;

typedef unsigned int   u32;
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_BgWipeTaskMain(int a0, Ctx *c)
{
    if (c->state == 0) {
        BG_SYS_FillScrollArea(4, 0, c->a8);
        BG_SYS_FillScrollArea(4, 3, c->ac);
        c->state = c->state + 1;
        return;
    }
    c->ac = c->ac + c->d10;
    BG_SYS_FillScrollArea(4, 3, c->ac);
    c->cnt = c->cnt - 1;
    if (c->cnt == 0)
        BTLV_INPUT_DeleteTask(c->main, (void *)a0);
}
