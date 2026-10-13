/*
 * function: ISS_CITY_UNIT_CalcVolumeFromAxes
 * address:  0x0202AF74
 * packet:   pkt_0202AF74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_CITY_UNIT_CalcVolumeX  0x0202AFAC  thumb
 *   ISS_CITY_UNIT_CalcVolumeY  0x0202AFFC  thumb
 *   ISS_CITY_UNIT_CalcVolumeZ  0x0202B04C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *
 * The head of the three-axis attenuation family: multiplies the X, Y and
 * Z band responses (ISS_CITY_UNIT_CalcVolumeX / ISS_CITY_UNIT_CalcVolumeY / ISS_CITY_UNIT_CalcVolumeZ, each a
 * 0..127 level) and renormalises by 127*127 == 0x3f01, so the product of
 * three 7-bit levels comes back as one 7-bit level.  The result is
 * truncated to u8 by the caller-visible return type.
 *
 * Blocked at MATCH: every concrete byte is right.  The three THM_CALL
 * sites at +0x06, +0x10 and +0x1a have no witness outside
 * 0x0202AF74..0x0202AFAC -- this is the only caller of any of the three
 * axis routines in the whole image, so `label` refuses them and `matched`
 * has nothing to point at while ISS_CITY_UNIT_CalcVolumeX / ISS_CITY_UNIT_CalcVolumeY /
 * ISS_CITY_UNIT_CalcVolumeZ stay unfiled (each is a 6-to-13 byte scheduling near
 * miss, see docs/notes/ISS_CITY_UNIT_CalcVolumeX.c.txt and its two twins).
 * --suggest-split cannot help: the compared range is one function.
 * Blocking evidence class: none available (needs an EXACT manifest entry
 * at 0x0202AFAC / 0x0202AFFC / 0x0202B04C, or a second caller).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeFromAxes.c \
 *       --func ISS_CITY_UNIT_CalcVolumeFromAxes --addr 0x0202AF74 --cc 1.1p1 --thumb
 */

typedef int           s32;
typedef unsigned int  u32;
typedef unsigned char u8;

extern u8 ISS_CITY_UNIT_CalcVolumeX(const u8 *obj, const s32 *pos);
extern u8 ISS_CITY_UNIT_CalcVolumeY(const u8 *obj, const s32 *pos);
extern u8 ISS_CITY_UNIT_CalcVolumeZ(const u8 *obj, const s32 *pos);

u8 ISS_CITY_UNIT_CalcVolumeFromAxes(u8 *obj, s32 *pos)
{
    s32 x;
    s32 y;
    s32 z;

    x = ISS_CITY_UNIT_CalcVolumeX(obj, pos);
    y = ISS_CITY_UNIT_CalcVolumeY(obj, pos);
    z = ISS_CITY_UNIT_CalcVolumeZ(obj, pos);

    return (u8)(z * (x * y) / 0x3f01);
}
