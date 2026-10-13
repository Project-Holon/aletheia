/*
 * function: UNION_COMMAND_RecvColosseumEntry
 * address:  0x02173BFC
 * packet:   pkt_ov012_02173BFC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02034714  0x02034714  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   COMM_ENTRY_MENU_AddMember  0x021CD624  thumb  ov021
 */
#include "../include/Obj12447.h"
#include "../include/Obj19256.h"

typedef unsigned char u8;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void OS_GetMacAddress(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void COMM_ENTRY_MENU_AddMember(u8 *p, int i, u32 a, u32 b, void *c);

void UNION_COMMAND_RecvColosseumEntry(int a, int x, u8 *b, u8 *p)
{
    int *r4;
    int r7;
    int buf[2];

    r4 = *(int * *)&((struct Obj12447 *)p)->f355C;
    r7 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj19256 *)(*(u8 * *)&((struct Obj12447 *)p)->f0))->fC));
    if (r4 == 0 || r4[0] == 0 || r4[0x5a] == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    OS_GetMacAddress(buf);
    COMM_ENTRY_MENU_AddMember((u8 *)r4[0x5a], a, (int)GAME_DATA_GetMyStatus((void *)r7), b[0x27], buf);
}
