/*
 * function: FIELD_GetPlayerAreaZoneId
 * address:  0x021CD440
 * packet:   pkt_ov021_021CD440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FIELD_GetAreaZoneId  0x021CD400  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u32 FIELD_GetAreaZoneId(u32 a, int b, int c);

int FIELD_GetPlayerAreaZoneId(void *a, u16 *out)
{
    u16 x;
    void *o;
    u16 h;
    u16 w;

    x = FIELDMAP_GetZoneId(a);
    o = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(a));
    h = FLDMMDL_GetGridNowX(o);
    w = FLDMMDL_GetGridNowZ(o);
    *out = FIELD_GetAreaZoneId(x, h, w);
    if (*out != 0x1ab)
        return 1;
    *out = x;
    return 0;
}
