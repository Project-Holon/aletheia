/*
 * function: func_021B8BB4
 * address: 0x021B8BB4
 * packet: pkt_ov133_021B8BB4
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Inline coordinate conversion with an enum offset keeps the zero subtract and matching spill homes.
 * symbols:
 *   func_021F4AF0 0x021F4AF0 thumb ov112
 *   func_021F5450 0x021F5450 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef enum { I_ZERO = 0, I_LIMIT = 9 } Index;
extern int func_021F4AF0(void *, int);
extern u8 *func_021F5450(u8 *, int);
static inline int coordinate(int value, Index offset)
{
    return (int)((float)value / 4096.0f) - offset;
}
int func_021B8BB4(u8 *p, void *manager, const int *pos, u16 *limit)
{
    u16 distance;
    int best;
    int x;
    Index i;
    int enabled, y, dx, dy, n;
    u8 *q;
    distance = *limit * *limit;
    best = 10;
    for (i = I_ZERO; i < I_LIMIT; i++) {
        if (manager == 0) enabled = 1;
        else enabled = func_021F4AF0(manager, i);
        q = func_021F5450(*(u8 **)(p + 0x1880), i);
        if (*(int *)q == 1 && enabled == 1) {
            x = coordinate(*(int *)(q + 4) + *(int *)(q + 16), I_ZERO);
            y = coordinate(*(int *)(q + 8) + *(int *)(q + 20), (Index)16);
            dx = pos[0] - x;
            dy = pos[1] - y;
            n = dx * dx + dy * dy;
            if (n < distance) { distance = n; best = i; }
        }
    }
    *limit = distance;
    return best;
}
