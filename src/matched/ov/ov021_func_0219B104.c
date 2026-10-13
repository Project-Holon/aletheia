/*
 * function: FLDMMDL_MOVECODE_GetRandomDirFromSet
 * address:  0x0219B104
 * packet:   pkt_ov021_0219B104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_MOVECODE_GetDirSet  0x0219B120  thumb  ov021
 *   FLDMMDL_MOVECODE_FindTableEnd  0x0219B0D8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 *FLDMMDL_MOVECODE_GetDirSet(u32);
extern int FLDMMDL_MOVECODE_FindTableEnd(u32 *, u32);
extern u32 func_020056EC(u32 v);

u32 FLDMMDL_MOVECODE_GetRandomDirFromSet(u32 a, u32 b)
{
    u32 *t = FLDMMDL_MOVECODE_GetDirSet(a);
    return t[func_020056EC(FLDMMDL_MOVECODE_FindTableEnd(t, b))];
}
