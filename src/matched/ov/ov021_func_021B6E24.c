/*
 * function: SCRCMD_POKEMON_FLD_FindDeliveryMmdl
 * address:  0x021B6E24
 * packet:   pkt_ov021_021B6E24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *FIELDMAP_GetMmdlSys(u8 *p);
typedef unsigned int   u32;
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 FLDMMDL_GetObjCode(void *p);

void *SCRCMD_POKEMON_FLD_FindDeliveryMmdl(void *a)
{
    unsigned long it = 0;
    void *rec;
    void *list;

    list = FIELDMAP_GetMmdlSys(a);
    while (FLDMMDL_SysSearchUseMmdl(list, (struct Rec **)(&rec), (u32 *)(&it)) == 1) {
        if (FLDMMDL_GetObjCode(rec) == 0x46)
            return rec;
    }
    return 0;
}
