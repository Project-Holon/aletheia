/*
 * function: IRC_COMPATIBLE_MENU_UpdateFloater
 * address: 0x021B8874
 * packet: pkt_ov102_021B8874
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 021B88F6.
 * lever: sign declared before start fixes r6/r7; diff * counter avoids a move.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   IRC_COMPATIBLE_MENU_ResetFloaterPath 0x021B88F8 thumb ov102
 */
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void IRC_COMPATIBLE_MENU_ResetFloaterPath(int *);
void IRC_COMPATIBLE_MENU_UpdateFloater(u32 *p)
{
    u16 xy[2];
    int sign;
    int start, diff, magnitude, start2, diff2, magnitude2;
    s8 sign2;
    start = p[2];
    diff = (int)p[0] - start;
    magnitude = diff < 0 ? -diff : diff;
    sign = (s8)(diff / magnitude);
    if (diff < 0) diff = -diff;
    xy[0] = start + sign * (((u32)diff * (u32)p[4]) / (u32)p[5]);
    start2 = p[3];
    diff2 = (int)p[1] - start2;
    magnitude2 = diff2 < 0 ? -diff2 : diff2;
    sign2 = diff2 / magnitude2;
    if (diff2 < 0) diff2 = -diff2;
    xy[1] = start2 + sign2 * (((u32)diff2 * (u32)p[4]) / (u32)p[5]);
    CLACT_AddActorSurfacePos((struct Obj *)p[6], (const struct Vec2 *)xy, 1);
    if ((p[4])++ > (u32)p[5]) IRC_COMPATIBLE_MENU_ResetFloaterPath((int *)p);
}
