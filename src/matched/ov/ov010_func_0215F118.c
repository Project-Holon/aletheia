/*
 * function: func_0215F118
 * address:  0x0215F118
 * packet:   pkt_ov010_0215F118
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Area {
    u16 x;              /* 0x00 */
    u16 z;              /* 0x02 */
    u16 w;              /* 0x04 */
    u16 h;              /* 0x06 */
} Area;

extern u32 func_02188C80(void *p);
extern void *func_020120F4(u32 v);
extern void *func_0201296C(void *p);
typedef signed int     s32;
extern u32 func_020142E8(void *bitmap, s32 id);

int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (func_020142E8(func_0201296C(func_020120F4(func_02188C80(field))), flag) != 0)
        return 0;
    dx = a->x - x;
    dz = a->z - z;
    if (dx < 0)
        dx = -dx;
    if (dx < a->w) {
        if (dz < 0)
            dz = -dz;
        if (dz < a->h)
            return 1;
    }
    return 0;
}
