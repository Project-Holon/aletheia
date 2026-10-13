/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId
 * address:  0x021F4020
 * packet:   pkt_ov046_021F4020
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 */

typedef unsigned int u32;
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
typedef unsigned short u16;
extern u16 FLDMMDL_GetObjId(void *p);

int FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId(u32 a, int b)
{
    int s1 = 0;
    int s0;
    void *it = FIELDMAP_GetMmdlSys((void *)a);

    while (FLDMMDL_SysSearchUseMmdl(it, (struct Rec **)(&s0), (u32 *)(&s1)) == 1) {
        if (b == FLDMMDL_GetObjId((void *)s0))
            return s0;
    }
    return 0;
}
