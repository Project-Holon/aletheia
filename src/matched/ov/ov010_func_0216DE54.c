/*
 * function: FLDMMDL_SysSearchMoveCode
 * address:  0x0216DE54
 * packet:   pkt_ov010_0216DE54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * First object of the given kind in the map (FLDMMDL_SysSearchUseMmdl walks it),
 * or NULL.
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 FLDMMDL_GetMoveCode(void *obj);

void *FLDMMDL_SysSearchMoveCode(void *map, u32 kind)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(map, (struct Rec **)(&obj), &iter) == 1) {
        if (FLDMMDL_GetMoveCode(obj) == kind)
            return obj;
    }
    return 0;
}
