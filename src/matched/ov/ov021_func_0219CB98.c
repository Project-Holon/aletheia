/*
 * function: FLDMMDL_BLACT_DeleteRes
 * address:  0x0219CB98
 * packet:   pkt_ov021_0219CB98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_BLACT_FindResIndex  0x0219CA98  thumb  ov021
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   FLDMMDL_BLACT_DeleteVramSlot  0x0219C52C  thumb  ov021
 *   FLDMMDL_BLACT_RemoveResIndex  0x0219CA6C  thumb  ov021
 */
#include "../include/Obj00429.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;
typedef struct { int n; Ent *e; } Tbl;
extern int FLDMMDL_BLACT_FindResIndex(u32 *o, u32 key, u16 *a, u16 *b);
struct BbActSys;
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);
extern void FLDMMDL_BLACT_DeleteVramSlot(u32 a, u32 b);
extern void FLDMMDL_BLACT_RemoveResIndex(Tbl *t, u16 k);

void FLDMMDL_BLACT_DeleteRes(u8 *s, u16 k)
{
    u16 t[2];
    FLDMMDL_BLACT_FindResIndex((u32 *)(s + 0x14), k, &t[0], &t[1]);
    if (t[1] & 2) {
        BILLBOARD_ACT_DeleteSlots((struct BbActSys *)(((struct Obj00429 *)s)->f4), t[0], 1);
    } else {
        FLDMMDL_BLACT_DeleteVramSlot(((struct Obj00429 *)s)->f4, t[0]);
    }
    FLDMMDL_BLACT_RemoveResIndex((Tbl *)(s + 0x14), k);
}
