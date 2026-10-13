/*
 * function: func_021CC0F8
 * address:  0x021CC0F8
 * packet:   pkt_ov093_021CC0F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_POKEPARAM_SetContFlag  0x021D5FE4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_AddCritStage  0x021D5F38  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj09981.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S;
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_POKEPARAM_SetContFlag(u8 *p, unsigned int n);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_POKEPARAM_AddCritStage(struct S *p, int n);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

int func_021CC0F8(char *p, void *m, int c, int n)
{
    int flag;

    flag = 0;
    if (BTL_POKEPARAM_TestContFlag(m, 9) == 0) {
        BTL_POKEPARAM_SetContFlag(m, 9);
        BTL_SERVER_CMD_Push(((struct Obj09981 *)p)->fC, 0x19, BTL_POKEPARAM_GetPokeId(m), 9);
        flag = 1;
    }
    if (n > 1) {
        if (BTL_POKEPARAM_AddCritStage(m, n - 1) != 0) {
            BTL_SERVER_CMD_Push(((struct Obj09981 *)p)->fC, 0xe, BTL_POKEPARAM_GetPokeId(m), n - 1);
            flag = 1;
        }
    }
    if (flag) {
        BTL_SERVER_CMD_PushVariable(((struct Obj09981 *)p)->fC, 0x5b, 0x411, BTL_POKEPARAM_GetPokeId(m), 0xffff0000);
        return 1;
    }
    return 0;
}
