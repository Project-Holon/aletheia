/*
 * function: IRC_RHYTHM_GetScreenActor
 * address:  0x021B7968
 * packet:   pkt_ov104_021B7968
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRC_RHYTHM_GetActor  0x021B7D1C  thumb  ov104
 *
 * Target leaf IRC_RHYTHM_GetActor filed EXACT in src/matched; this thunk now attests.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int IRC_RHYTHM_GetActor(u8 *p, int i);
int IRC_RHYTHM_GetScreenActor(u8 *p, int i) { return IRC_RHYTHM_GetActor(p + 4, i); }
