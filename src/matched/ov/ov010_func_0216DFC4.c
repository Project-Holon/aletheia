/*
 * function: FLDMMDL_CheckSameObjCodeOther
 * address:  0x0216DFC4
 * packet:   pkt_ov010_0216DFC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a);
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 FLDMMDL_GetObjCode(void *p);

int FLDMMDL_CheckSameObjCodeOther(void *a, u32 id)
{
    u32 iter = 0;
    void *out;
    void *ctx;

    ctx = FLDMMDL_GetMmdlSys(a);
    while (FLDMMDL_SysSearchUseMmdl(ctx, (struct Rec **)(&out), &iter) == 1) {
        if (out != a) {
            u32 v = FLDMMDL_GetObjCode(out);
            if (v != 0xFFFF && v == id)
                return 1;
        }
    }
    return 0;
}
