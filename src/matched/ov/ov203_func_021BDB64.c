/*
 * function: func_021BDB64
 * address: 0x021BDB64
 * packet: pkt_ov203_021BDB64
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDD30 0x021BDD30 thumb ov203
 *   func_021BDF00 0x021BDF00 thumb ov203
 *   func_021BE538 0x021BE538 thumb ov203
 *   func_021BDC88 0x021BDC88 thumb ov203
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_021BE638 0x021BE638 thumb ov203
 *   func_021BDC20 0x021BDC20 thumb ov203
 *   d_02FFFC3C 0x02FFFC3C data
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj01433.h"
extern void func_021BDD30(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021BDF00(unsigned char *);
struct Context;
extern int func_021BE538(const struct Context *ctx, u32 frames);
extern int func_021BDC88(char *);
extern int func_021BE620(char *p);
extern void func_021BE638(char *p, int a);
extern u32 WIPE_SYS_EndCheck(void);
extern int func_021BDC20(void *ctx, unsigned mode, unsigned heap);
extern unsigned int d_02FFFC3C;
int func_021BDB64(void *unused, int *state, void *c, char *work)
{
    int result;
    unsigned int now, delta;
    func_021BDD30(*(char * *)&((struct Obj01433 *)work)->f1C);
    PRINTSYS_QUE_Main(((struct Obj01433 *)work)->f10);
    func_021BDF00(*(unsigned char * *)&((struct Obj01433 *)work)->fC);
    result = func_021BE538(((struct Obj01433 *)work)->f18, ((struct Obj01433 *)work)->f24);
    now = d_02FFFC3C;
    delta = now - ((struct Obj01433 *)work)->f20;
    ((struct Obj01433 *)work)->f24 = 0;
    if (((struct Obj01433 *)work)->f20 != 0 && delta > 1)
        ((struct Obj01433 *)work)->f24 = delta - 1;
    ((struct Obj01433 *)work)->f20 = now;
    ((struct Obj01433 *)work)->f28 = ((struct Obj01433 *)work)->f28 + ((struct Obj01433 *)work)->f24;
    switch (*state) {
    case 0:
        if (func_021BDC88(work) != 0 || result != 0) {
            (*(int **)(work + 4))[4] = func_021BE620(((struct Obj01433 *)work)->f18) >> 12;
            (*(int **)(work + 4))[5] = result + 1;
            func_021BE638(((struct Obj01433 *)work)->f18, (*(int **)(work + 4))[5]);
            (*state)++;
        }
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            if (func_021BDC20((void *)((unsigned char)(*(int **)(work + 4))[1]), 0, ((struct Obj01433 *)work)->f0))
                return 1;
            (*state)++;
        }
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    return 0;
}
