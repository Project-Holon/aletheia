/*
 * function: func_02024230
 * address:  0x02024230
 * packet:   pkt_02024230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   _ll_mul        0x0209C054  arm
 *   tbl_020A1B38   0x020A1B38  data
 *
 * pmsi_param.c: fill out[0..count) with amp * sin(phase), phase advancing
 * by step through 16 bits.  The table is FX_SinCosTable_ at 0x020A1B38
 * (sin/cos s16 pairs, hence the stride of two halfwords: the SDK's
 * FX_SinIdx); the old notes misread the pool word as 0x02021B38.
 *
 * The last byte of docs/notes/func_02024230.c.txt was the phase type: it is
 * a plain u16.  The wrap is then `lsrs` (u16 narrowing) and the index is
 * still `asrs` because the u16 promotes to int before the shift.  The s64
 * temporary for the widened table value is the permuter's find from wave 5.
 */

typedef unsigned short   u16;
typedef signed short     s16;
typedef signed int       s32;
typedef unsigned int     u32;
typedef signed long long s64;

extern const s16 tbl_020A1B38[];

void func_02024230(s16 *out, u32 count, u16 step, s32 amp)
{
    u32 i;
    u16 phase;

    phase = 0;
    i = 0;
    while (i < count) {
        s64 v = (s64)tbl_020A1B38[(phase >> 4) * 2];
        s64 prod = v * (s64)amp;

        out[i] = (s16)((s32)((prod + 0x800) >> 12) >> 12);
        i++;
        phase = (u16)(phase + step);
    }
}
