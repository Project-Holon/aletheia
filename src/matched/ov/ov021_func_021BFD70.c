/*
 * function: EVENT_DISAPPEAR_CreateSpinZoom
 * address:  0x021BFD70
 * packet:   pkt_ov021_021BFD70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x7C-byte task (callback EVENT_DISAPPEAR_RunSpinZoom).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_DISAPPEAR_RunSpinZoom  0x021C00C8  thumb  ov021
 */

typedef unsigned int   u32;
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);
int EVENT_DISAPPEAR_RunSpinZoom(void *task, int *state, void **q);

void *EVENT_DISAPPEAR_CreateSpinZoom(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, EVENT_DISAPPEAR_RunSpinZoom, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}
