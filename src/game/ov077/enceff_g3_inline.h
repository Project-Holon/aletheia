#ifndef ALETHEIA_OV077_ENCEFF_G3_INLINE_H
#define ALETHEIA_OV077_ENCEFF_G3_INLINE_H

/*
 * Geometry engine command ports and the immediate-mode helpers that the
 * encounter effects draw with (grid of quads in ov077, wave in ov078).
 * Writes to the ports are stores only, so the ports are volatile.
 */

/* The includer must include enceff_base_types.h first. */

#define REG_MTX_PUSH       (*(vu32 *)0x04000444)
#define REG_MTX_POP        (*(vu32 *)0x04000448)
#define REG_MTX_SCALE      (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS      (*(vu32 *)0x04000470)
#define REG_NORMAL         (*(vu32 *)0x04000484)
#define REG_TEXCOORD       (*(vu32 *)0x04000488)
#define REG_VTX_16         (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR   (*(vu32 *)0x040004A4)
#define REG_DIF_AMB        (*(vu32 *)0x040004C0)
#define REG_SPE_EMI        (*(vu32 *)0x040004C4)
#define REG_LIGHT_COLOR    (*(vu32 *)0x040004CC)
#define REG_BEGIN_VTXS     (*(vu32 *)0x04000500)
#define REG_END_VTXS       (*(vu32 *)0x04000504)

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

#endif
