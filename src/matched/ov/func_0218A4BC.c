/*
 * function: FIELD_EVENT_CHECK_Run
 * address:  0x0218A4BC
 * packet:   pkt_0218A4BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_EVENT_CHECK_RunGrid  0x0218A074  thumb  ov021
 *   FIELD_EVENT_CHECK_RunRail  0x0218A240  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_EVENT_CHECK_RunGrid(void *a, int b);
struct Obj00020;
extern int FIELD_EVENT_CHECK_RunRail(void *p, struct Obj00020 *pos);

int FIELD_EVENT_CHECK_Run(u32 a, u32 b, u32 c, u32 d)
{
if (FIELDMAP_GetMoveKind((u8 *)b) == 0) {
    return FIELD_EVENT_CHECK_RunGrid((void *)a, b);
}
return FIELD_EVENT_CHECK_RunRail((void *)a, (struct Obj00020 *)b);
}

