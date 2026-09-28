/*
 * function: ov208_func_021C7FF8
 * address:  0x021C7FF8
 * packet:   pkt_ov208_021C7FF8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fgr      0x0209BBB0  arm
 *   _fmul     0x0209C77C  arm
 *   _fadd     0x0209C95C  arm
 *   _fsub     0x0209CB8C  arm
 *   _ffix     0x0209C494  arm
 */

typedef signed int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    float x;
    float y;
    float z;
} Ov208VecF;

struct Ov208Mdl {
    unsigned int obj;
    unsigned int f4;
    Ov208VecF pos[1];
};

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void ov208_func_021C7FF8(struct Ov208Mdl *m, int i, VecFx32 *out)
{
    out->x = FX_F32_TO_FX32(m->pos[i].x);
    out->y = FX_F32_TO_FX32(m->pos[i].y);
    out->z = FX_F32_TO_FX32(m->pos[i].z);
}
