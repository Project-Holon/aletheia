/*
 * function: BTL_SERVER_FLOW_ExecCmdRaiseLoweredStatStages
 * address: 0x021C9448
 * packet: pkt_ov093_021C9448
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 50 bytes; 021C947A..021C947C is alignment padding.
 * note: caller consumes live r0 after void-declared BTL_POKEPARAM_RaiseLoweredStatStages;
 *       return interface follows its explicit u8 truncation at 021C9470.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_POKEPARAM_RaiseLoweredStatStages 0x021D5EFC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_POKEPARAM_RaiseLoweredStatStages(char *);
int BTL_SERVER_FLOW_ExecCmdRaiseLoweredStatStages(u8 *p, u8 *e)
{
    char *a;
    a = (char *)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, e[4]);
    if (BTL_POKEPARAM_IsFainted(a) == 0) {
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 12, e[4]);
        return (u8)BTL_POKEPARAM_RaiseLoweredStatStages(a);
    }
    return 0;
}
