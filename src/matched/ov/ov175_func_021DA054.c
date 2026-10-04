/*
 * function: func_021DA054
 * address: 0x021DA054
 * packet: pkt_ov175_021DA054
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB3A4 0x021DB3A4 thumb ov175
 *   func_021DB478 0x021DB478 thumb ov175
 *   func_021DBFA4 0x021DBFA4 thumb ov175
 *   func_021DBFB4 0x021DBFB4 thumb ov175
 */
#include "../include/Obj00629.h"
extern void func_021DB3A4(char *, unsigned long, int, unsigned long);
extern int func_021DB478(char *);
extern void func_021DBFA4(char *);
extern int func_021DBFB4(char *);
int func_021DA054(char *ctx)
{
    int result;
    switch (((struct Obj00629 *)ctx)->f128) {
    case 0:
        func_021DB3A4(ctx, -1, 2, *(unsigned long *)&((struct Obj00629 *)ctx)->f1464);
        ((struct Obj00629 *)ctx)->f128 = 1;
        break;
    case 1:
        result = func_021DB478(ctx);
        if (result == 1) {
            if (**(int * *)&((struct Obj00629 *)ctx)->f1464 != 0) ((struct Obj00629 *)ctx)->f128 = 4;
            else ((struct Obj00629 *)ctx)->f128 = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        func_021DBFA4(ctx);
        ((struct Obj00629 *)ctx)->f128 = 3;
        break;
    case 3:
        result = func_021DBFB4(ctx);
        if (result == 1) ((struct Obj00629 *)ctx)->f128 = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}
