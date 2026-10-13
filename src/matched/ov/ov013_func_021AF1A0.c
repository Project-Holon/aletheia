/*
 * function: VCT_MAIN_Exit
 * address:  0x021AF1A0
 * packet:   pkt_ov013_021AF1A0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gVctWork     0x021B3C80  data  ov013
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_0208B480  0x0208B480  arm
 *   func_0208B528  0x0208B528  arm
 *   func_02073AB4  0x02073AB4  arm
 *   func_02073898  0x02073898  arm
 *   VCT_Exit  0x021B3844  arm  ov013
 *   func_0208BEF0  0x0208BEF0  arm
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb  ov009
 */

#include "../include/G_Work.h"

typedef unsigned char u8;

typedef struct Work Work;

extern struct Work *gVctWork;
typedef unsigned int   u32;
extern u32 func_0202EB0C(void);
extern int func_0208B480(void);
extern int func_0208B528(void);
extern void func_02073AB4(void *p);
struct X;
extern void func_02073898(struct X *x);
extern void VCT_Exit(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern void DWC_RAPCOMMON_Free(u32 a, void *p, int b);

void VCT_MAIN_Exit(void)
{
    void (*cb)(void);

    if (gVctWork == 0) {
        return;
    }
    cb = gVctWork->f1984;
    if (func_0202EB0C() == 0) {
        func_0208B480();
    } else {
        func_0208B528();
    }
    func_02073AB4(gVctWork->f19B8);
    func_02073898((struct X *)gVctWork->f19B8);
    VCT_Exit();
    func_0208BEF0(0);
    DWC_RAPCOMMON_Free(0, gVctWork->f880, 0);
    DWC_RAPCOMMON_Free(0, gVctWork, 0);
    gVctWork = 0;
    if (cb) {
        cb();
    }
}
