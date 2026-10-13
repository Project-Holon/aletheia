/*
 * function: FLDMMDL_StoreMovedPos
 * address: 0x0216E57C
 * packet: pkt_ov010_0216E57C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: binding the getter's pointer result to tmp restores the base
 * load before the stride, while retaining the unsigned raw address sum.
 * Context shape: matched CC58 allocates 0x48 and stores input c at +44.
 * E4EC returns 30 unless E4FA compares equal to 1, then returns E4B0's
 * halfword or 30. Thus i <=65535 and i*12 <=786420; no Vec array bound
 * is assumed. D88C unconditionally initializes all 12 bytes of v.
 * symbols:
 *   FLDMMDL_GetMovedPosSlot 0x0216E4EC thumb ov010
 *   FLDMMDL_GetMmdlSys 0x0216D67C thumb ov010
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 */

typedef struct
{
    int x;
    int y;
    int z;
} Vec;
typedef struct
{
    char pad00[44];
    unsigned int raw44;
} Context;
extern int FLDMMDL_GetMovedPosSlot(int a0, int a1);
extern void *FLDMMDL_GetMmdlSys(void *a0);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);

void FLDMMDL_StoreMovedPos(void *a, int a1)
{
    int i;
    Vec *p;
    Vec v;
    Context *tmp;
    i = FLDMMDL_GetMovedPosSlot((int)a, a1);
    if (i != 30)
    {
        tmp = FLDMMDL_GetMmdlSys(a);
        p = (Vec *) (tmp->raw44 + (i * 12));
        FLDMMDL_GetPos(a, (struct VecFx32 *)&v);
        *p = v;
    }
}
