/*
 * function: BTL_SERVER_FLOW_TryThrowBall
 * address: 0x021CBA40
 * packet: pkt_ov093_021CBA40
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate six-byte selection and two-byte output arrays reproduce
 * the unaligned stack base; a u16 third parameter pins its early home store.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_MAIN_DecodeMessageCode 0x021B8778 thumb ov093
 *   BTL_SIDE_GetPokeAtPosThunk 0x021B98A4 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_SERVER_FLOW_CalcCaptureShakes 0x021CBB34 thumb ov093
 *   BTL_MAIN_CheckZukanSeen 0x021B8724 thumb ov093
 *   BTL_EVENT_StartClientPalAnm 0x021D6E24 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj02784.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
struct Unk021B8CB0;
extern u8 BTL_MAIN_DecodeMessageCode(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *BTL_SIDE_GetPokeAtPosThunk(char *const *q, u8 b);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern int BTL_SERVER_FLOW_CalcCaptureShakes(u8 *p, void *q, void *m, u16 mode, u8 *out, u8 *flag);
extern int BTL_MAIN_CheckZukanSeen(char *p, void *m);
extern void BTL_EVENT_StartClientPalAnm(void **p, int value);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
int BTL_SERVER_FLOW_TryThrowBall(u8 *p, void *a, u16 b)
{
    void *m = 0;
    u8 chosen = 6;
    u8 buf[6];
    u8 out[2];
    u8 count;
    u8 i;
    u8 result;
    u8 flag;
    count = BTL_MAIN_DecodeMessageCode(((struct Obj02784 *)p)->f4, (unsigned short)((chosen << 8) | BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj02784 *)p)->f4, ((struct Obj02784 *)p)->f8, BTL_POKEPARAM_GetPokeId(a))), buf);
    for (i = 0; i < count; i++) {
        m = BTL_SIDE_GetPokeAtPosThunk(*(char *const * *)&((struct Obj02784 *)p)->f8, buf[i]);
        if (!BTL_POKEPARAM_IsFainted(m)) { chosen = buf[i]; break; }
    }
    if (!BTL_MAIN_GetCompetitor(((struct Obj02784 *)p)->f4)) {
        if (chosen != 6) {
            result = BTL_SERVER_FLOW_CalcCaptureShakes(p, a, m, b, &out[1], &out[0]);
            if (result) {
                ((struct Obj02784 *)p)->f14 = 6;
                p[0x784] = chosen;
                flag = BTL_MAIN_CheckZukanSeen(((struct Obj02784 *)p)->f4, m) == 0 ? 1 : 0;
                BTL_EVENT_StartClientPalAnm(m, b);
            } else { flag = 0; }
            BTL_SERVER_CMD_Push(((struct Obj02784 *)p)->fC, 0x46, chosen, out[1], result, flag, out[0], b);
        }
        return 1;
    }
    if (chosen != 6) BTL_SERVER_CMD_Push(((struct Obj02784 *)p)->fC, 0x47, chosen, b);
    return 0;
}
