/*
 * function: func_021E1E34
 * address: 0x021E1E34
 * packet: pkt_ov170_021E1E34
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_021EAB50 0x021EAB50 thumb ov170
 *   func_021EBF74 0x021EBF74 thumb ov170
 *   d_021EFA7C 0x021EFA7C data a4
 */
#include "../include/Obj03847.h"
#include "../include/Obj23885.h"
#include "../include/Obj23886.h"
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void func_021EAB50(unsigned char *w);
extern void func_021EBF74(char *);
extern int (*const d_021EFA7C[])(char *);
int func_021E1E34(char *p, int *state)
{
    if (!*(char * *)&((struct Obj03847 *)p)->f2C || !((struct Obj23885 *)(*(char * *)&((struct Obj03847 *)p)->f2C))->f8C || PRINTSYS_QUE_IsFinished(((struct Obj23886 *)(*(char * *)&((struct Obj03847 *)p)->f2C))->f8C))
        *state = d_021EFA7C[*state](p);
    if (*state == 0x69)
        return 0;
    if (*(char * *)&((struct Obj03847 *)p)->f2C) {
        func_021EAB50((unsigned char *)(*(char * *)&((struct Obj03847 *)p)->f2C));
        func_021EBF74(*(char * *)&((struct Obj03847 *)p)->f2C);
    }
    return 1;
}
