/*
 * function: func_0202AF74
 * address:  0x0202AF74
 * packet:   pkt_0202AF74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0202AFAC  0x0202AFAC  thumb
 *   func_0202AFFC  0x0202AFFC  thumb
 *   func_0202B04C  0x0202B04C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *
 * The head of the three-axis attenuation family: multiplies the X, Y and
 * Z band responses (func_0202AFAC / func_0202AFFC / func_0202B04C, each a
 * 0..127 level) and renormalises by 127*127 == 0x3f01, so the product of
 * three 7-bit levels comes back as one 7-bit level.  The result is
 * truncated to u8 by the caller-visible return type.
 *
 * Blocked at MATCH: every concrete byte is right.  The three THM_CALL
 * sites at +0x06, +0x10 and +0x1a have no witness outside
 * 0x0202AF74..0x0202AFAC -- this is the only caller of any of the three
 * axis routines in the whole image, so `label` refuses them and `matched`
 * has nothing to point at while func_0202AFAC / func_0202AFFC /
 * func_0202B04C stay unfiled (each is a 6-to-13 byte scheduling near
 * miss, see docs/notes/func_0202AFAC.c.txt and its two twins).
 * --suggest-split cannot help: the compared range is one function.
 * Blocking evidence class: none available (needs an EXACT manifest entry
 * at 0x0202AFAC / 0x0202AFFC / 0x0202B04C, or a second caller).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AF74.c \
 *       --func func_0202AF74 --addr 0x0202AF74 --cc 1.1p1 --thumb
 */

typedef int           s32;
typedef unsigned int  u32;
typedef unsigned char u8;

extern u8 func_0202AFAC(u8 *obj, s32 *pos);
extern u8 func_0202AFFC(u8 *obj, s32 *pos);
extern u8 func_0202B04C(u8 *obj, s32 *pos);

u8 func_0202AF74(u8 *obj, s32 *pos)
{
    s32 x;
    s32 y;
    s32 z;

    x = func_0202AFAC(obj, pos);
    y = func_0202AFFC(obj, pos);
    z = func_0202B04C(obj, pos);

    return (u8)(z * (x * y) / 0x3f01);
}
