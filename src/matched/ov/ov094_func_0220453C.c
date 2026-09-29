/*
 * function: func_0220453C
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
 *   func_02040618  0x02040618  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef struct Ctx {
    char *main;
    int state;
    int a8;
    int ac;
    int d10;
    int cnt;
} Ctx;

extern void func_02040618(int a, int b, int c);
extern void func_0220687C(char *p, int v);

void func_0220453C(int a0, Ctx *c)
{
    if (c->state == 0) {
        func_02040618(4, 0, c->a8);
        func_02040618(4, 3, c->ac);
        c->state = c->state + 1;
        return;
    }
    c->ac = c->ac + c->d10;
    func_02040618(4, 3, c->ac);
    c->cnt = c->cnt - 1;
    if (c->cnt == 0)
        func_0220687C(c->main, a0);
}
