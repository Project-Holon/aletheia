/*
 * function: FIELD_SUBSCREEN_UpdateUnionNoTransition
 * address:  0x021A13C0
 * packet:   pkt_ov021_021A13C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   UNION_MAIN_IsIdle  0x0217394C  thumb  ov012
 *   UNION_SUBDISP_Update  0x021F00D4  thumb  ov031
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern int UNION_MAIN_IsIdle(const struct Ctx *p);
extern void UNION_SUBDISP_Update(char *p, int mode);

void FIELD_SUBSCREEN_UpdateUnionNoTransition(u32 *p, u32 a)
{
    u32 h = (u32)FIELDMAP_GetGameSystem((void *)p[5]);
    if (a == 1 && UNION_MAIN_IsIdle((const struct Ctx *)h) == 0)
        a = 0;
    UNION_SUBDISP_Update((char *)p[8], a);
}
