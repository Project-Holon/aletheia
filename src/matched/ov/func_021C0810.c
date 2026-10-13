/*
 * function: EVENT_COMM_ERROR_SubProcEnd
 * address:  0x021C0810
 * packet:   pkt_021C0810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v);

int EVENT_COMM_ERROR_SubProcEnd(u32 a, u32 b, u32 c, u32 d)
{
GAMESYSTEM_SetFieldMapState((struct Ctx *)c, 0);
return 1;
}

