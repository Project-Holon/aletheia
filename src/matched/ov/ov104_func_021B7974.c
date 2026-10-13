/*
 * function: IRC_RHYTHM_GetScreenActorUnit
 * address:  0x021B7974
 * packet:   pkt_ov104_021B7974
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_RHYTHM_GetActorUnit in ov104 (pkt_ov104_021B7D24).
 *
 * symbols:
 *   IRC_RHYTHM_GetActorUnit  0x021B7D24  thumb  ov104
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 IRC_RHYTHM_GetActorUnit(u32 *p);
u32 IRC_RHYTHM_GetScreenActorUnit(u8 *p) { return IRC_RHYTHM_GetActorUnit((u32 *)(p + 4)); }
