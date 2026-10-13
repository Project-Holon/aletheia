/*
 * function: ENCEFF_StartBlockFlip
 * address:  0x021F5ABC
 * packet:   pkt_ov079_021F5ABC
 * region:   ov079
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
 *   ENCEFF_StepBlockFlip  0x021F5AE4  thumb  ov079
 *   ENCEFF_StepFlipCell  0x021F5B24  thumb  ov079
 * Addresses are Black-image addresses.
 */

typedef struct {
    int w;
    int h;
    int z;
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

typedef unsigned char  u8;
struct Param;
extern void *ENCEFF_StartCellGrid(void *task, const struct Param *p, int flag);
extern void ENCEFF_StepBlockFlip(u8 *w);
extern int ENCEFF_StepFlipCell(int *o);

void ENCEFF_StartBlockFlip(void *a)
{
    Cfg c;

    c.w = 4;
    c.h = 4;
    c.z = 0;
    c.step = (void (*)(void *))ENCEFF_StepBlockFlip;
    c.done = (int (*)(void *))ENCEFF_StepFlipCell;
    ENCEFF_StartCellGrid(a, (const struct Param *)(&c), 0);
}
