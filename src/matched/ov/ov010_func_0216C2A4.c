/*
 * function: NAMEIN_SETUP_SnapObjToGrid
 * address:  0x0216C2A4
 * packet:   pkt_ov010_0216C2A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object.
 *
 * pass 6 2026-10-06 P6L05: closed from a capture of the compiler's register
 * colouring (debugger break at the colour select step of mwccarm). The
 * graph showed y with a long live range (stored after the x snap) was
 * coloured early and took r3. Storing v.y first makes y short-lived, so it
 * is coloured late, after x; reading z, y, x (x snapped first, its load
 * hoisted) gives the image's load order x, z, y. EXACT in c99 and c.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 */

typedef unsigned char u8;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Work {
    u8 pad00[8];
    void *field;        /* 0x08 */
} Work;

extern int FIELDMAP_GetExpObj(int *p);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *p, int a, int b);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);

#pragma opt_propagation off
void NAMEIN_SETUP_SnapObjToGrid(Work *w)
{
    VecFx32 v;
    const VecFx32 *pos;
    void *q;
    fx32 x;
    fx32 y;
    fx32 z;
    fx32 k;

    pos = FLD_EXP_OBJ_GetModelStatus((void *)FIELDMAP_GetExpObj(w->field), 0, 0);
    q = FIELDMAP_GetFieldPlayer(w->field);
    z = pos->z;
    y = pos->y;
    x = pos->x;
    k = 0x20000;
    z = z + k;
    v.y = y;
    v.x = (((x >> 12) / 16) << 16) + 0x8000;
    v.z = (((z >> 12) / 16) << 16) + 0x8000;
    FIELD_PLAYER_SetPos(q, &v);
}
#pragma opt_propagation reset
