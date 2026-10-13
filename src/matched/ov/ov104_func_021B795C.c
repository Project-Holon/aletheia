/*
 * function: IRC_RHYTHM_DrawScreen
 * address:  0x021B795C
 * packet:   pkt_ov104_021B795C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 IRC_RHYTHM_DrawActorSystem          -> unresolved: 021B7D0C (arm, from name) has no witness outside 021B795C..021B7968; 16 overlays overlap this address (ov016, ov021, ov067, ov070, ov071, ov091, ov093, ov102, ov103, ov104, ov105, ov106, ov133, ov172, ov173, ov180), none resolvable without a region hint on the symbols: line
 
 * symbols:
 *   IRC_RHYTHM_DrawActorSystem  0x021B7D0C  thumb  ov104
 *
 * UNBLOCKED: IRC_RHYTHM_DrawActorSystem is now an EXACT entry in layout/matched/ov104;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void IRC_RHYTHM_DrawActorSystem(int x);
void IRC_RHYTHM_DrawScreen(u8 *p) { IRC_RHYTHM_DrawActorSystem((int)(p + 4)); }
