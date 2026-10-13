/*
 * function: FIELD_MSGBG_BlockQueryTwoPlane
 * address:  0x02193498
 * packet:   pkt_ov021_02193498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   FIELD_G3D_MAPPER_GetTilePlane  0x021D14C4  thumb  ov021
 */

typedef struct { int w[0x41]; } B104;

extern void func_02082BCC(void *, int, int);
struct Map021D14C4;
struct Plane021D14C4;
struct VecFx32_021D14C4;
extern void FIELD_G3D_MAPPER_GetTilePlane(struct Plane021D14C4 *out, int idx, struct Map021D14C4 *map, struct VecFx32_021D14C4 *pos, int size, int base);

void FIELD_MSGBG_BlockQueryTwoPlane(B104 *dst, const int *src, void *c, int d, int e)
{
    B104 buf;

    func_02082BCC(&buf, 0, sizeof(buf));
    FIELD_G3D_MAPPER_GetTilePlane((struct Plane021D14C4 *)(&buf), 0, (struct Map021D14C4 *)((char *)src + src[2]), c, d, e);
    FIELD_G3D_MAPPER_GetTilePlane((struct Plane021D14C4 *)(&buf), 1, (struct Map021D14C4 *)((char *)src + src[3]), c, d, e);
    *dst = buf;
    dst->w[0x40] = 2;
}
