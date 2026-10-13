/*
 * function: BTL_MAIN_RestartBattle
 * address:  0x021BA73C
 * packet:   pkt_ov093_021BA73C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BTL_CLIENT_SetView takes two arguments (its own file: `p->v = v`), and the
 * value passed second is the BTLV_CORE_Create result just stored at p + 4:
 * that is the `adds r1, r0, #0` the one-argument prototype could not
 * produce (twin: ov093_func_021B835C).
 *
 * symbols:
 *   BTL_MAIN_IsCommCompetitor  0x021B6818  thumb  ov093
 *   BTL_CALC_SetRngState  0x021D787C  thumb  ov093
 *   BTL_MAIN_InitClientParties  0x021B68D8  thumb  ov093
 *   BTL_SIDE_Clear  0x021B9424  thumb  ov093
 *   BTL_MAIN_IsClientUsed  0x021B8B9C  thumb  ov093
 *   BTL_SIDE_SetupClientParty  0x021B9460  thumb  ov093
 *   BTL_CLIENT_StartRemoteStep  0x021CD984  thumb  ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   BTLV_CORE_ResetDisplay  0x021E8E28  thumb  ov093
 *   BTLV_CORE_Create  0x021E8F20  thumb  ov093
 *   BTL_CLIENT_SetView  0x021CD95C  thumb  ov093
 *   BTL_SERVER_Restart  0x021BAB40  thumb  ov093
 */
#include "../include/Obj02131.h"
#include "../include/Obj21020.h"
#include "../include/Obj21021.h"

typedef unsigned char u8;

struct T;
extern unsigned int BTL_MAIN_IsCommCompetitor(unsigned int *p);
extern void BTL_CALC_SetRngState(void *);
extern void BTL_MAIN_InitClientParties(u8 *s, struct T *t);
typedef unsigned int   u32;
struct QA;
extern void BTL_SIDE_Clear(char *p);
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern void BTL_SIDE_SetupClientParty(char *a, char *b, u8 c);
extern void BTL_CLIENT_StartRemoteStep(void *, int);
typedef unsigned short u16;
struct Scene;
extern void func_021E9034(char *p);
extern void BTLV_CORE_ResetDisplay(void *p);
extern struct Scene *BTLV_CORE_Create(void *a, void *b, u32 c, int d, u16 heap);
extern void BTL_CLIENT_SetView(struct QA *p, u32 v);
extern void BTL_SERVER_Restart(char *p);

void BTL_MAIN_RestartBattle(char *p, int x)
{
    unsigned int i;
    int t;

    t = BTL_MAIN_IsCommCompetitor((unsigned int *)(*(int * *)&((struct Obj02131 *)p)->f0));
    BTL_CALC_SetRngState(p + 0x3f0);
    BTL_MAIN_InitClientParties((u8 *)p, ((struct Obj02131 *)p)->f0);
    BTL_SIDE_Clear(p + 0xc8);
    BTL_SIDE_Clear(p + 0x1b0);
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed((unsigned char *)p, i)) {
            BTL_SIDE_SetupClientParty(p + 0x1b0, p, i);
            BTL_SIDE_SetupClientParty(p + 0xc8, p, i);
            BTL_CLIENT_StartRemoteStep(*(void **)(p + i * 4 + 0x10), x);
        }
    }
    func_021E9034((char *)(((struct Obj02131 *)p)->f4));
    BTLV_CORE_ResetDisplay((void *)0x13);
    ((struct Obj02131 *)p)->f4 = (int)BTLV_CORE_Create(p, *(void **)(p + (((struct Obj21020 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), (u32)(p + 0xc8), t, 0x13);
    BTL_CLIENT_SetView(*(void **)(p + (((struct Obj21021 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), ((struct Obj02131 *)p)->f4);
    BTL_SERVER_Restart((char *)(((struct Obj02131 *)p)->f8));
}
