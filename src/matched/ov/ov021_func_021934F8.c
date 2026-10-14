/*
 * function: FIELD_G3D_MAP_BLOCK_QueryOnePlaneBuffered
 * address:  0x021934F8
 * packet:   pkt_ov021_021934F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_G3D_MAPPER_GetTilePlane  0x021D14C4  thumb  ov021
 */

typedef struct { int w[0x41]; } B104;

extern void MI_CpuFill8(void *, int, int);
struct Map021D14C4;
struct Plane021D14C4;
struct VecFx32_021D14C4;
extern void FIELD_G3D_MAPPER_GetTilePlane(struct Plane021D14C4 *out, int idx, struct Map021D14C4 *map, struct VecFx32_021D14C4 *pos, int size, int base);

void FIELD_G3D_MAP_BLOCK_QueryOnePlaneBuffered(B104 *dst, const int *src, void *c, int d, int e)
{
    B104 buf;

    MI_CpuFill8(&buf, 0, sizeof(buf));
    FIELD_G3D_MAPPER_GetTilePlane((struct Plane021D14C4 *)(&buf), 0, (struct Map021D14C4 *)((char *)src + src[2]), c, d, e);
    *dst = buf;
    dst->w[0x40] = 1;
}
