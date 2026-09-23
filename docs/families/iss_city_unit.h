/*
 * docs/families/iss_city_unit.h -- the iss_city_unit.c family, around
 * 0x0202AEEC..0x0202B1D0 in the ARM9 image (__FILE__ anchor 0x020A76F8 at
 * 0x0202AF24).  Edges fuzzy by a function.
 *
 * REFERENCE DOCUMENT ONLY; nothing includes it.  Written 2026-09-23 (wave 15
 * tail lane) from the matched sources func_0202AF28/AF34/AF74, sub_0202AF30,
 * sub_0202AF3C, func_0202B0A4, func_0202B0D4 and the near-miss notes
 * docs/notes/func_0202AFAC.c.txt, func_0202AFFC.c.txt, func_0202B04C.c.txt.
 *
 * The object is a byte table read with flat offsets (u8 *obj):
 *   +0x10  u8 level[]   per distance band
 *   +0x16  u8 radius[]  band radius, first axis, in 1/16 units (<< 4)
 *   +0x1C  u8 radius2[] band radius, second axis
 *
 * The three axis routines 0x0202AFAC, 0x0202AFFC, 0x0202B04C share one shape:
 *   cur = band index for the distance; prev = cur ? (u8)(cur - 1) : 0;
 *   if (cur == prev) return obj[0x10 + cur];
 *   d = |(pos[k] >> 12) - own coordinate|;
 *   return (u8)func_0202B194(pc[0x16] << 4, pc[0x10], pp[0x16] << 4, pp[0x10], d);
 * CLOSED 2026-09-23 (wave 15): all three EXACT* once the pointers are const
 * (const u8 *obj, const s32 *pos, const-pointee callees).  The old residue:
 * the image stores the stacked fifth argument d to
 * [sp] after the pp/pc address computations, 1.1p1, sp2 and sp2p2 all store
 * it first (6 bytes) when the pointers are not const.
 * func_0202AF74 (matched) is their caller.
 */

#ifndef ISS_CITY_UNIT_H
#define ISS_CITY_UNIT_H

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

extern u32 func_0202B0A4(const u8 *obj, const s32 *pos);   /* band index, axis 1 */
extern u32 func_0202B0D4(const u8 *obj, const s32 *pos);   /* band index, axis 2 */
extern s32 func_0202B134(const u8 *obj);             /* own X */
extern s32 func_0202B154(const u8 *obj);             /* own second coordinate */
extern s32 func_0202B194(s32 r_hi, s32 v_hi, s32 r_lo, s32 v_lo, s32 d); /* lerp */

extern u8 func_0202AFAC(const u8 *obj, const s32 *pos);
extern u8 func_0202AFFC(const u8 *obj, const s32 *pos);
extern u8 func_0202B04C(const u8 *obj, const s32 *pos);

#endif /* ISS_CITY_UNIT_H */
