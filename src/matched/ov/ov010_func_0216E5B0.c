/*
 * function: FLDMMDL_CheckMovedPosAtMapPos
 * address:  0x0216E5B0
 * packet:   pkt_ov010_0216E5B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Whether the map cell under pos (x, z in whole tiles of 16 units) holds a
 * hit whose check returns 1.
 *
 * symbols:
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FLDMMDL_HasMovedPos  0x0216E51C  thumb  ov010
 */

typedef short s16;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *FLDMMDL_SysSearchGridPosHeight(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern int FLDMMDL_HasMovedPos(void *hit);

int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos)
{
    void *hit = FLDMMDL_SysSearchGridPosHeight((u32)map, (s16)((pos->x >> 4) / 4096), (s16)((pos->z >> 4) / 4096), pos->y, 0x20000, (int)0);

    if (hit != 0 && FLDMMDL_HasMovedPos(hit) == 1)
        return 1;
    return 0;
}
