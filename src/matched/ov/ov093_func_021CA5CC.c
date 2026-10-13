/*
 * function: BTL_SERVER_FLOW_ProcHandExGroundPokes
 * address: 0x021CA5CC
 * packet: pkt_ov093_021CA5CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: C7F68 returns its normalized u8 j, and u8 n restores the count reload.
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   BTL_SERVER_FLOW_TryClearContFlag 0x021C5418 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   func_0203EFC8 0x0203EFC8 arm
 *   BTL_SERVER_FLOW_QueryPokeGroundedEvent 0x021C6F34 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_SERVER_FLOW_CureSick 0x021C5620 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cmd { u32 a:8; u32 id:5; u32 b:19; };
struct Unk021D62A8;
struct UtilWork;
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
typedef signed int     s32;
struct Slot;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_TryClearContFlag(u8 *, u8 *, int);
extern u8 BTL_POKEPARAM_GetCounter(u8 *, int);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int BTL_SERVER_FLOW_QueryPokeGroundedEvent(u8 *, u8 *, int);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
int BTL_SERVER_FLOW_ProcHandExGroundPokes(const u8 *p, const struct Cmd *q)
{
    u8 buf[8];
    u8 n;
    u8 i;
    u8 *a;
    int changed;
    u8 t;
    n = BTL_SERVER_FLOW_CollectAlivePokeIds((int *)p, (u16)(BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, (u8)q->id) | 0x800), buf);
    i = 0;
    if (i >= n) goto done;
loop:
    {
        a = (u8 *)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, buf[i]);
        changed = 0;
        if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, 3)) {
            BTL_SERVER_FLOW_TryClearContFlag((u8 *)p, a, 3);
            t = BTL_POKEPARAM_GetCounter(a, 4);
            if (!(t && (t = (u8)(t - 1)) < 24)) t = 31;
            if (t != 31) func_0203EFC8(p, a, 1);
            changed = 1;
        }
        if (BTL_SERVER_FLOW_QueryPokeGroundedEvent((u8 *)p, a, 1)) changed = 1;
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 30)) {
            BTL_SERVER_FLOW_CureSick((u8 *)p, a, 30, 0);
            changed = 1;
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 32)) {
            BTL_SERVER_FLOW_CureSick((u8 *)p, a, 32, 0);
            changed = 1;
        }
        if (changed) BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x43b, buf[i], 0xffff0000);
    }
    i++;
    if (i < n) goto loop;
done:
    return 1;
}
