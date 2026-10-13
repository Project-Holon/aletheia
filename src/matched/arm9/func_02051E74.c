/*
 * function: func_02051E74
 * address:  0x02051E74
 * packet:   pkt_02051E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MTX_Rot22_       0x0207AD64  thumb
 *   MTX_ScaleApply22 0x0207AD70  arm
 *   FX_Inv    0x0207C778  arm
 *   tbl_020A1B38     0x020A1B38  data
 *
 * Scaled 2x2 rotation: convert the angle to a 16-bit turn fraction (mode 1:
 * (ang * 0xFFFF) >> 8; mode 2: degrees, (ang * 0xFFFF) / 360, the umull by
 * 0x6C16C16D with the add-and-halve fix-up), rotate with the sin/cos pair
 * from the shared table at index ang >> 4 (FX_SinIdx/FX_CosIdx shape), then
 * scale by the two vector magnitudes.  EXACT* because the 24-byte leaf that
 * follows at 0x02051F1C (struct copy of three words plus a fourth store) has
 * no label.
 *
 * Wave 9: closed by writing the two conversions as the plain unsigned
 * expressions (the wave-7 note hand-expanded the division and kept a 19-byte
 * register residue) and the table as the extern data symbol; the old
 * "label wall" on MTX_Rot22_/MTX_ScaleApply22 is now carried by the sdk class.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef signed int    s32;
typedef signed short  s16;

struct Mtx22 { s32 m[4]; };

extern s16 tbl_020A1B38[];
extern void MTX_Rot22_(struct Mtx22 *mtx, s32 sinVal, s32 cosVal);
extern void MTX_ScaleApply22(const struct Mtx22 *src, struct Mtx22 *dst, s32 x, s32 y);
extern long FX_Inv(long v);

void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode)
{
    if (mode == 1)
        ang = (u16)((ang * 0xFFFF) >> 8);
    else if (mode == 2)
        ang = (u16)((ang * 0xFFFF) / 360);

    MTX_Rot22_(mtx, tbl_020A1B38[((s32)ang >> 4) * 2], tbl_020A1B38[((s32)ang >> 4) * 2 + 1]);
    MTX_ScaleApply22(mtx, mtx, FX_Inv((long int)v1), FX_Inv((long int)v2));
}
