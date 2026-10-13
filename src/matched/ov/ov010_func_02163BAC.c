/*
 * function: FLDMMDL_MOVE_HitCheckOtherObjects
 * address:  0x02163BAC
 * packet:   pkt_ov010_02163BAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb
 *   FLDMMDL_MOVE_HitCheckObjectRect  0x02163AF0  thumb
 */

extern void *FLDMMDL_GetMmdlSys(void *a0);
typedef unsigned int   u32;
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_MOVE_HitCheckObjectRect(int a, int b, int c, int d, int e, int f);

int FLDMMDL_MOVE_HitCheckOtherObjects(int a, int b, int c, int d)
{
    int v;
    int cur;
    int it;

    v = 0;
    it = (int)FLDMMDL_GetMmdlSys((void *)a);
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)it, (struct Rec **)(&cur), (u32 *)(&v)) == 1) {
        if (a != cur) {
            if (FLDMMDL_MOVE_HitCheckObjectRect(a, cur, b, c, d, 1) == 1)
                return 1;
        }
    }
    return 0;
}
