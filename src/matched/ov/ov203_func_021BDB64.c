/*
 * function: DEMO3D_Main
 * address: 0x021BDB64
 * packet: pkt_ov203_021BDB64
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_UpdateContext 0x021BDD30 thumb ov203
 *   DEMO3D_GRAPHIC_Draw 0x021BDF00 thumb ov203
 *   DEMO3D_ENGINE_Update 0x021BE538 thumb ov203
 *   DEMO3D_CheckSkip 0x021BDC88 thumb ov203
 *   DEMO3D_ENGINE_GetFrame 0x021BE620 thumb ov203
 *   DEMO3D_ENGINE_SetMode 0x021BE638 thumb ov203
 *   DEMO3D_StartWipe 0x021BDC20 thumb ov203
 *   d_02FFFC3C 0x02FFFC3C data
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj01433.h"
extern void DEMO3D_UpdateContext(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void DEMO3D_GRAPHIC_Draw(unsigned char *);
struct Context;
extern int DEMO3D_ENGINE_Update(const struct Context *ctx, u32 frames);
extern int DEMO3D_CheckSkip(char *);
extern int DEMO3D_ENGINE_GetFrame(char *p);
extern void DEMO3D_ENGINE_SetMode(char *p, int a);
extern u32 WIPE_SYS_EndCheck(void);
extern int DEMO3D_StartWipe(void *ctx, unsigned mode, unsigned heap);
extern unsigned int d_02FFFC3C;
int DEMO3D_Main(void *unused, int *state, void *c, char *work)
{
    int result;
    unsigned int now, delta;
    DEMO3D_UpdateContext(*(char * *)&((struct Obj01433 *)work)->f1C);
    PRINTSYS_QUE_Main(((struct Obj01433 *)work)->f10);
    DEMO3D_GRAPHIC_Draw(*(unsigned char * *)&((struct Obj01433 *)work)->fC);
    result = DEMO3D_ENGINE_Update(((struct Obj01433 *)work)->f18, ((struct Obj01433 *)work)->f24);
    now = d_02FFFC3C;
    delta = now - ((struct Obj01433 *)work)->f20;
    ((struct Obj01433 *)work)->f24 = 0;
    if (((struct Obj01433 *)work)->f20 != 0 && delta > 1)
        ((struct Obj01433 *)work)->f24 = delta - 1;
    ((struct Obj01433 *)work)->f20 = now;
    ((struct Obj01433 *)work)->f28 = ((struct Obj01433 *)work)->f28 + ((struct Obj01433 *)work)->f24;
    switch (*state) {
    case 0:
        if (DEMO3D_CheckSkip(work) != 0 || result != 0) {
            (*(int **)(work + 4))[4] = DEMO3D_ENGINE_GetFrame(((struct Obj01433 *)work)->f18) >> 12;
            (*(int **)(work + 4))[5] = result + 1;
            DEMO3D_ENGINE_SetMode(((struct Obj01433 *)work)->f18, (*(int **)(work + 4))[5]);
            (*state)++;
        }
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            if (DEMO3D_StartWipe((void *)((unsigned char)(*(int **)(work + 4))[1]), 0, ((struct Obj01433 *)work)->f0))
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
