/*
 * function: FIELD_EVENT_CHECK_CheckPosEventAtPlayer
 * address:  0x0218A76C
 * packet:   pkt_ov021_0218A76C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tries FIELD_EVENT_CHECK_CheckPosEventCenterTile, then FIELD_EVENT_CHECK_CheckPosEventForDir with direction 9.
 *
 * symbols:
 *   FIELD_EVENT_CHECK_CheckPosEventCenterTile  0x0218A8BC  thumb
 *   FIELD_EVENT_CHECK_CheckPosEventForDir  0x0218A784  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx784;
struct FieldCtx;
extern int FIELD_EVENT_CHECK_CheckPosEventCenterTile(struct FieldCtx *p);
extern int FIELD_EVENT_CHECK_CheckPosEventForDir(struct Ctx784 *c, int a);

int FIELD_EVENT_CHECK_CheckPosEventAtPlayer(void *p)
{
    int r = FIELD_EVENT_CHECK_CheckPosEventCenterTile(p);

    if (r != 0)
        return r;
    return FIELD_EVENT_CHECK_CheckPosEventForDir(p, 9);
}
