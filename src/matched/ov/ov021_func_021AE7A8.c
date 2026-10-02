/*
 * function: func_021AE7A8
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
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_021AA900  0x021AA900  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern void func_0216D828(u32 a, Vec3s *out);
extern s16 func_021641E8(u32 dir);
extern s16 func_021641F8(u32 dir);
extern int func_02163994(u32 a, int x, int y, int z, u32 dir);
extern int func_021AA900(void *p, Vec3s *pos);

int func_021AE7A8(u32 a, u32 dir, int n, void *p)
{
    Vec3s pos;
    s16 dx;
    s16 dz;
    int i;

    if (n != 0) {
        i = 0;
        func_0216D828(a, &pos);
        dx = func_021641E8(dir);
        dz = func_021641F8(dir);
        pos.x += dx;
        pos.z += dz;
        for (; i < n - 1; i++) {
            if ((func_02163994(a, pos.x, pos.y, pos.z, dir) & ~1) != 0)
                return 1;
            if (p != 0 && func_021AA900(p, &pos) != 0)
                return 1;
            pos.x += dx;
            pos.z += dz;
        }
        if ((func_02163994(a, pos.x, pos.y, pos.z, dir) & ~1) != 4)
            return 1;
        if (p != 0 && func_021AA900(p, &pos) != 0)
            return 1;
    }
    return 0;
}
