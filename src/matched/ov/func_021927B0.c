/*
 * function: FIELD_MSGBG_DeleteCursor
 * address:  0x021927B0
 * packet:   pkt_021927B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FIELD_MSGBG_ExitCursor  0x021927E8  thumb  ov021
 *   ENV_SetResourceSet  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FIELD_MSGBG_ExitCursor(u32 *p);
extern void ENV_SetResourceSet(void *p);

void FIELD_MSGBG_DeleteCursor(u8 *p)
{
    FIELD_MSGBG_ExitCursor((u32 *)p);
    ENV_SetResourceSet(p);
}
