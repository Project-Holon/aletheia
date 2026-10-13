/*
 * function: CROWD_UpdatePlayerAwarePerson
 * address:  0x021F41F0
 * packet:   pkt_ov055_021F41F0
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetEventId  0x0216D5B4  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   CROWD_IsMmdlInFront  0x021F4318  thumb  ov055
 *   CROWD_FindBlockingMmdl  0x021F42AC  thumb  ov055
 *   CROWD_SidestepPerson  0x021F3DD4  thumb  ov055
 *   CROWD_RemovePerson  0x021F3DBC  thumb  ov055
 *   CROWD_MakePersonSolid  0x021F3D90  thumb  ov055
 */
#include "../include/Obj00204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckEndAcmd();
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern void FLDMMDL_SetEventId(void *p, u16 v);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int CROWD_IsMmdlInFront(const u8 *a, void *b, u16 c, u16 d);
extern int CROWD_FindBlockingMmdl(u8 *a, void *b, u32 *c, u16 d, u16 e);
extern void CROWD_SidestepPerson(u8 *a, u32 b);
extern void CROWD_RemovePerson(u8 *a);
extern void CROWD_MakePersonSolid(u8 *a);

void CROWD_UpdatePlayerAwarePerson(u8 *a, u32 b, u32 c)
{
    u32 loc;
    void *x;

    switch (a[1]) {
    case 0:
        if (FLDMMDL_CheckEndAcmd(*(u32 *)&((struct Obj00204 *)a)->fC) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (((struct Obj00204 *)a)->f4 == 0) {
            a[1] = 2;
            return;
        }
        x = (void *)FIELD_PLAYER_GetMmdl((void *)c);
        c = 1;
        if (CROWD_IsMmdlInFront(a, x, 1, 1)) {
            FLDMMDL_SetEventId((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), ((struct Obj00204 *)a)->f6);
            return;
        }
        if (CROWD_FindBlockingMmdl(a, (void *)b, &loc, c, 0)) {
            CROWD_SidestepPerson(a, loc);
            FLDMMDL_SetEventId((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
            CROWD_MakePersonSolid(a);
        } else {
            FLDMMDL_SetAcmd((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
            FLDMMDL_SetEventId((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
        }
        a[1] = 0;
        return;
    case 2:
        CROWD_RemovePerson(a);
        return;
    }
}
