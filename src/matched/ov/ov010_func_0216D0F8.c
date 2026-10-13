/*
 * function: FLDMMDL_SetGridPosFromHeader
 * address:  0x0216D0F8
 * packet:   pkt_ov010_0216D0F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * final push 2026-10-05 G4L4: EXACT in c99 and c. The last argument of FLDMMDL_SetGridInitY is
 * a named int local (t) set from the field just before the call, with
 * #pragma opt_propagation off around the function. With propagation on the local is folded
 * into the call and the object copy is born before the argument chain (chain in r1, 13 B);
 * with it off the chain is born first and takes r0, as in the image. s16 local with the
 * pragma gave 9 B; int local without the pragma gave 13 B.
 *
 * symbols:
 *   FLDMMDL_HasMovedPos  0x0216E51C  thumb  ov010
 *   FLDMMDL_GetMovedPos  0x0216E544  thumb  ov010
 *   FLDMMDL_SetGridInitX  0x0216D7F0  thumb  ov010
 *   FLDMMDL_SetGridInitY  0x0216D7F4  thumb  ov010
 *   FLDMMDL_SetGridInitZ  0x0216D800  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef int            s32;
typedef s32            fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Src {
    u16  x;
    u16  y;
    fx32 z;
} Src;

extern int FLDMMDL_HasMovedPos(void *a, int a1);
extern void FLDMMDL_GetMovedPos(void *obj, VecFx32 *out);
extern void FLDMMDL_SetGridInitX(void *obj, s16 v);
extern void FLDMMDL_SetGridInitY(void *obj, s16 v);
extern void FLDMMDL_SetGridInitZ(void *obj, s16 v);
extern void FLDMMDL_SetGridOldX(void *obj, s16 v);
extern void FLDMMDL_SetGridOldY(void *obj, s16 v);
extern void FLDMMDL_SetGridOldZ(void *obj, s16 v);
extern void FLDMMDL_SetGridNowX(void *obj, s16 v);
extern void FLDMMDL_SetGridNowY(void *p, int v);
extern void FLDMMDL_SetGridNowZ(int a0, int a1);
extern void FLDMMDL_SetPos(void *obj, const VecFx32 *v);

#pragma opt_propagation off
void FLDMMDL_SetGridPosFromHeader(void *obj, const u8 *a1)
{
    const Src *p = (const Src *)(a1 + 0x1c);
    VecFx32 v;
    s32 x;
    s32 y;
    fx32 z;

    if (FLDMMDL_HasMovedPos(obj, (int)a1) == 0) {
        x = p->x;
        y = p->y;
        z = p->z;
    } else {
        FLDMMDL_GetMovedPos(obj, &v);
        x = (v.x >> 4) / 4096;
        y = (v.z >> 4) / 4096;
        z = v.y;
    }
    v.x = (x << 16) + 0x8000;
    FLDMMDL_SetGridInitX(obj, p->x);
    FLDMMDL_SetGridOldX(obj, x);
    FLDMMDL_SetGridNowX(obj, x);
    {
        int t = (p->z >> 4) / 4096;
        FLDMMDL_SetGridInitY(obj, t);
    }
    v.y = z;
    x = (z >> 4) / 4096;
    FLDMMDL_SetGridOldY(obj, x);
    FLDMMDL_SetGridNowY(obj, (s16)x);
    v.z = (y << 16) + 0x8000;
    FLDMMDL_SetGridInitZ(obj, p->y);
    FLDMMDL_SetGridOldZ(obj, y);
    FLDMMDL_SetGridNowZ((int)obj, (s16)y);
    FLDMMDL_SetPos(obj, &v);
}
#pragma opt_propagation reset
