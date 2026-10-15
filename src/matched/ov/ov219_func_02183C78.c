/*
 * function: BEACON_DETAIL_Main
 * address: 0x02183C78
 * packet: pkt_ov219_02183C78
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   func_02183D14 0x02183D14 thumb ov219
 *   func_02185B74 0x02185B74 thumb ov219
 *   func_02183CEC 0x02183CEC thumb ov219
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj10973.h"
typedef unsigned int   u32;
struct PrintSys;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
typedef unsigned char  u8;
extern int func_02183D14(u8 *p, int *state);
extern void func_02185B74(char *);
extern void func_02183CEC(u8 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int BEACON_DETAIL_Main(void *unused, char *state, int unused2, char *ctx)
{
    int result;
    TCBL_Main(((struct Obj10973 *)ctx)->fC0A4);
    result = func_02183D14((u8 *)ctx, (int *)state);
    if (((struct Obj10973 *)ctx)->fC3A4 != 0)
        func_02185B74(ctx);
    func_02183CEC((u8 *)ctx);
    PRINTSYS_QUE_Main(((struct Obj10973 *)ctx)->fC080);
    return result;
}
