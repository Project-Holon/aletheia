/*
 * file:     btlv_effvm_p62.c
 * unit:     yes
 * function: func_021FF3F4, func_021FF3FC
 * address:  0x021FF3F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022018A8  0x022018A8  thumb  ov094
 *   d_0220A050  0x0220A050  data  ov094
 *   d_0220A080  0x0220A080  data  ov094
 *   d_0220A158  0x0220A158  data  ov094
 *   d_0220A1A0  0x0220A1A0  data  ov094
 */
typedef struct {
    int x, y, z;
} Vec3;

extern void func_022018A8(void *obj, void *out, int idx);
void func_021FF3F4(void *obj, void *out, int idx);
void func_021FF3FC(const Vec3 *def, Vec3 *out, int idx, int kind);
extern const Vec3 d_0220A050[];
extern const Vec3 d_0220A080[];
extern const Vec3 d_0220A158[];
extern const Vec3 d_0220A1A0[];


void func_021FF3F4(void *obj, void *out, int idx)
{
    func_022018A8(obj, out, idx);
}


/*
 * Unlabelled: no func_ label in the listing (leaf, saves no lr); reached
 * by bl from func_021FD1CC.
 */
void func_021FF3FC(const Vec3 *def, Vec3 *out, int idx, int kind)
{
    switch (idx) {
    case 0:
    case 1:
        def = &d_0220A050[idx];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (kind == 3)
            def = &d_0220A1A0[idx - 2];
        else if (kind == 2)
            def = &d_0220A158[idx - 2];
        else
            def = &d_0220A080[idx - 2];
        break;
    case 6:
    case 7:
        if (kind == 3)
            def = &d_0220A1A0[idx - 2];
        else
            def = &d_0220A158[idx - 2];
        break;
    }
    out->x = def->x;
    out->y = def->y;
    out->z = def->z;
}
