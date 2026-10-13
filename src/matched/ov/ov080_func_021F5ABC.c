/*
 * function: ENCEFF_StartGridColumnFlip
 * address:  0x021F5ABC
 * packet:   pkt_ov080_021F5ABC
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
 *   ENCEFF_StepGridColumnFlip  0x021F5AE8  thumb  ov080
 *   ENCEFF_UpdateGridColumnFlipCell  0x021F5B44  thumb  ov080
 * Addresses are Black-image addresses.
 */

typedef struct {
    int w;
    int h;
    void (*init)(void *);
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

typedef unsigned char  u8;
struct Param;
extern void *ENCEFF_StartCellGrid(void *task, const struct Param *p, int flag);
extern void ENCEFF_StepGridColumnFlip(u8 *w);
extern int ENCEFF_UpdateGridColumnFlipCell(int *o);

void ENCEFF_StartGridColumnFlip(void *a)
{
    Cfg c;

    c.w = 2;
    c.h = 2;
    c.init = 0;
    c.step = (void (*)(void *))ENCEFF_StepGridColumnFlip;
    c.done = (int (*)(void *))ENCEFF_UpdateGridColumnFlipCell;
    ENCEFF_StartCellGrid(a, (const struct Param *)(&c), 1);
}
