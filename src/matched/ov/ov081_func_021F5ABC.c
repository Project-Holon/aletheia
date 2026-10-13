/*
 * function: ENCEFF_StartGridSpread
 * address:  0x021F5ABC
 * packet:   pkt_ov081_021F5ABC
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENCEFF_StartCellGrid  0x021F5620  thumb  ov077
 *   ENCEFF_InitGridSpread  0x021F5AEC  thumb  ov081
 *   ENCEFF_StepGridSpread  0x021F5B30  thumb  ov081
 *   ENCEFF_UpdateGridSpreadCell  0x021F5B94  thumb  ov081
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
extern void ENCEFF_InitGridSpread(u8 *w);
extern void ENCEFF_StepGridSpread(u8 *w);
extern int ENCEFF_UpdateGridSpreadCell(int *o);

void ENCEFF_StartGridSpread(void *a)
{
    Cfg c;

    c.w = 2;
    c.h = 2;
    c.init = (void (*)(void *))ENCEFF_InitGridSpread;
    c.step = (void (*)(void *))ENCEFF_StepGridSpread;
    c.done = (int (*)(void *))ENCEFF_UpdateGridSpreadCell;
    ENCEFF_StartCellGrid(a, (const struct Param *)(&c), 1);
}
