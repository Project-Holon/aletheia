/*
 * function: FLD_SCENEAREA_LOADER_CheckSector
 * address:  0x021AB890
 * packet:   pkt_ov021_021AB890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *
 * Lever: `const Range *` together with the inline VecSet helper gives the
 * y, x, z load order of the 12-byte vector fill; either alone does not.
 */
typedef struct Vec { int x, y, z; } Vec;
typedef struct Range { unsigned long lo, hi; int min, max; Vec dir; } Range;

extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *v);
extern void VEC_Normalize(const Vec *v, Vec *out);
extern unsigned long func_0207CFB8(int x, int z);

static inline void VecSet(Vec *v, int x, int y, int z) { v->x = x; v->y = y; v->z = z; }

int FLD_SCENEAREA_LOADER_CheckSector(void *self, const Range *r, Vec *ref)
{
    Vec out;
    Vec a;
    int d;
    unsigned long ang;

    VecSet(&a, r->dir.x, r->dir.y, r->dir.z);
    func_0207CA00(ref, &a, &out);
    out.y = 0;
    d = func_0207CBD0(&out);
    VEC_Normalize(&out, &out);
    ang = func_0207CFB8(out.x, out.z);
    if (r->min <= d && r->max > d) {
        if (r->hi < r->lo) {
            if (r->hi >= ang || (ang < 0x10000 && ang >= r->lo))
                return 1;
        } else {
            if (r->lo <= ang && r->hi > ang)
                return 1;
        }
    }
    return 0;
}
