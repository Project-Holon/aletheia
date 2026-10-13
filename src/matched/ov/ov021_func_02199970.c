/*
 * function: FLDMMDL_ACMD_HopMove
 * address:  0x02199970
 * packet:   pkt_ov021_02199970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_AddGridNowX  0x0216D848  thumb  ov010
 *   FLDMMDL_AddGridNowY  0x0216D860  thumb  ov010
 *   FLDMMDL_AddGridNowZ  0x0216D87C  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8  count;
    u8  axis;
    u8  moveAxis;
    u8  negate;
    int speed;
    int accum;
    u16 angle;
    u16 step;
} State;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void FLDMMDL_SetPos(u32, Vec *);
extern int *d_021DDBD4[2];
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern int FLDMMDL_GetGridNowX(void *p);
extern u32 FLDMMDL_SetGridOldX(u32, u32);
extern int FLDMMDL_GetGridNowY(void *p);
extern u32 FLDMMDL_SetGridOldY(u32, u32);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u32 FLDMMDL_SetGridOldZ(u32, u32);
extern void FLDMMDL_AddGridNowX(char *p, short v);
extern void FLDMMDL_AddGridNowY(char *p, short v);
extern void FLDMMDL_AddGridNowZ(char *p, short v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_HopMove(u32 a)
{
    State *p;
    Vec v;
    int t;
    int s;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (p->moveAxis) {
    case 0:
        v.x += p->speed;
        break;
    case 1:
        v.y += p->speed;
        break;
    case 2:
        v.z += p->speed;
        break;
    }
    FLDMMDL_SetPos(a, &v);
    t = p->speed;
    if (t < 0)
        t = -t;
    p->accum += t;
    p->angle += p->step;
    if (p->angle > 0xF00)
        p->angle = 0xF00;
    {
    Vec w = { 0, 0, 0 };
    s = d_021DDBD4[1][(u16)(p->angle / 256)];
    if (p->negate == 1)
        s = -s;
    switch (p->axis) {
    case 0:
        w.x = s;
        break;
    case 1:
        w.y = s;
        break;
    case 2:
        w.z = s;
        break;
    }
    FLDMMDL_SetDrawOffset(a, &w);
    }
    p->count--;
    if (p->accum >= 0x10000 && p->count != 0) {
        int b;
        int dir;

        p->accum -= 0x10000;
        dir = 1;
        b = p->speed;
        FLDMMDL_SetGridOldX(a, FLDMMDL_GetGridNowX((void *)a));
        FLDMMDL_SetGridOldY(a, FLDMMDL_GetGridNowY((void *)a));
        FLDMMDL_SetGridOldZ(a, FLDMMDL_GetGridNowZ((void *)a));
        switch (p->moveAxis) {
        case 0:
            if (b < 0)
                dir = -1;
            FLDMMDL_AddGridNowX((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            FLDMMDL_AddGridNowY((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            FLDMMDL_AddGridNowZ((char *)a, dir);
            break;
        }
    }
    if (p->count != 0)
        return 0;
    {
        Vec z = { 0, 0, 0 };
        FLDMMDL_SetDrawOffset(a, &z);
    }
    FLDMMDL_SetMoveBit((void *)a, 0x540);
    FLDMMDL_MOVE_UpdateOldGridPos(a);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
