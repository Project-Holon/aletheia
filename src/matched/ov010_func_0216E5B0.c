/*
 * function: func_0216E5B0
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
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 */

typedef short s16;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

extern void *func_0216DDDC(void *map, s16 x, s16 z, fx32 y, fx32 h, int flag);
extern int func_0216E51C(void *hit);

int func_0216E5B0(void *map, const VecFx32 *pos)
{
    void *hit = func_0216DDDC(map, (pos->x >> 4) / 4096, (pos->z >> 4) / 4096, pos->y, 0x20000, 0);

    if (hit != 0 && func_0216E51C(hit) == 1)
        return 1;
    return 0;
}
