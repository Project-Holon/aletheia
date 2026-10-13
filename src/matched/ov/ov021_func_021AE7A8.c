/*
 * function: EVENT_TRAINER_EYE_IsPathBlocked
 * address:  0x021AE7A8
 * packet:   pkt_ov021_021AE7A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb  ov010
 *   EFFECT_ENCOUNT_IsSpotAt  0x021AA900  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern void FLDMMDL_GetGridNowPos(u32 a, Vec3s *out);
extern s16 FLDMMDL_MOVE_GetDirAddGridX(u32 dir);
extern s16 FLDMMDL_MOVE_GetDirAddGridZ(u32 dir);
extern int FLDMMDL_MOVE_HitCheckMoveCurrent(u32 a, int x, int y, int z, u32 dir);
struct Self;
extern int EFFECT_ENCOUNT_IsSpotAt(struct Self *self, short *pos);

int EVENT_TRAINER_EYE_IsPathBlocked(u32 a, u32 dir, int n, void *p)
{
    Vec3s pos;
    s16 dx;
    s16 dz;
    int i;

    if (n != 0) {
        i = 0;
        FLDMMDL_GetGridNowPos(a, &pos);
        dx = FLDMMDL_MOVE_GetDirAddGridX(dir);
        dz = FLDMMDL_MOVE_GetDirAddGridZ(dir);
        pos.x += dx;
        pos.z += dz;
        for (; i < n - 1; i++) {
            if ((FLDMMDL_MOVE_HitCheckMoveCurrent(a, pos.x, pos.y, pos.z, dir) & ~1) != 0)
                return 1;
            if (p != 0 && EFFECT_ENCOUNT_IsSpotAt(p, (short int *)(&pos)) != 0)
                return 1;
            pos.x += dx;
            pos.z += dz;
        }
        if ((FLDMMDL_MOVE_HitCheckMoveCurrent(a, pos.x, pos.y, pos.z, dir) & ~1) != 4)
            return 1;
        if (p != 0 && EFFECT_ENCOUNT_IsSpotAt(p, (short int *)(&pos)) != 0)
            return 1;
    }
    return 0;
}
