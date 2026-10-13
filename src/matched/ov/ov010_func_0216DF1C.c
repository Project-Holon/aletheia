/*
 * function: FLDMMDL_SysDeleteZoneChangeMmdl
 * address:  0x0216DF1C
 * packet:   pkt_ov010_0216DF1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern u16 FLDMMDL_GetObjId(void *p);
extern void FLDMMDL_DeleteMmdl(u8 *o);

void FLDMMDL_SysDeleteZoneChangeMmdl(u32 x)
{
    int n;
    u8 *o;
    u32 k = 0x20;

    n = 0;
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (FLDMMDL_CheckStatusBit((int)o, k) == 0) {
            FLDMMDL_GetObjId(o);
            FLDMMDL_DeleteMmdl(o);
        }
    }
}
