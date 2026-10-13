/*
 * function: FLDMMDL_SysSearchObjId
 * address:  0x0216DE94
 * packet:   pkt_ov010_0216DE94
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * First free object (FLDMMDL_CheckStatusBitAlias zero) with the given id in the map,
 * or NULL (FLDMMDL_SysSearchMoveCode is the by-kind twin).
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBitAlias  0x0216DBB4  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckStatusBitAlias(void *obj);
extern u16 FLDMMDL_GetObjId(void *obj);

void *FLDMMDL_SysSearchObjId(void *map, u32 id)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(map, (struct Rec **)(&obj), &iter) == 1) {
        if (FLDMMDL_CheckStatusBitAlias(obj) == 0 && FLDMMDL_GetObjId(obj) == id)
            return obj;
    }
    return 0;
}
