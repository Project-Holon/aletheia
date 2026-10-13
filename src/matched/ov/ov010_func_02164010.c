/*
 * function: FLDMMDL_MOVE_UpdateHeight
 * address:  0x02164010
 * packet:   pkt_ov010_02164010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb
 *   FLDMMDL_CheckStatusBitHeightGetOff  0x0216DB68  thumb
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb
 *   FLDMMDL_SetPos  0x0216D89C  thumb
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb
 */

typedef short s16;
typedef struct { int v[3]; } Vec3;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *p);
extern int FLDMMDL_CheckStatusBit(int a, int b);
typedef unsigned int   u32;
extern int FLDMMDL_CheckStatusBitHeightGetOff(void *a0);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_GetMapHeight(int a, Vec3 *p, int *out);
extern void FLDMMDL_SetPos(int a, Vec3 *p);
extern int FLDMMDL_GetGridNowY(void *p);
extern void FLDMMDL_SetGridOldY(int a, int b);
extern void FLDMMDL_SetGridNowY(void *p, int v);

int FLDMMDL_MOVE_UpdateHeight(int a)
{
    Vec3 cur;
    Vec3 next;
    int out;
    int r;

    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&cur);
    next = cur;
    if (FLDMMDL_CheckStatusBit(a, 0x2000) != 0)
        return 0;
    if (FLDMMDL_CheckStatusBitHeightGetOff((void *)a) == 1) {
        FLDMMDL_ClearMoveBit((char *)a, 0x1000);
        return 0;
    }
    r = FLDMMDL_MOVE_GetMapHeight(a, &next, &out);
    if (r == 1) {
        cur.v[1] = out;
        FLDMMDL_SetPos(a, &cur);
        FLDMMDL_SetGridOldY(a, FLDMMDL_GetGridNowY((void *)a));
        FLDMMDL_SetGridNowY((void *)a, (s16)((out >> 4) / 4096));
        FLDMMDL_ClearMoveBit((char *)a, 0x1000);
    } else {
        FLDMMDL_SetMoveBit((void *)a, 0x1000);
    }
    return r;
}
