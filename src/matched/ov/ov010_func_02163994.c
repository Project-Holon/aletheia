/*
 * function: FLDMMDL_MOVE_HitCheckMoveCurrent
 * address: 0x02163994
 * packet: pkt_ov010_02163994
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x021639BE before FLDMMDL_MOVE_HitCheckMoveDir.
 * symbols:
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   FLDMMDL_MOVE_HitCheckMove 0x021638CC thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x, y, z; } VecFx32;
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *p, struct VecFx32 *out);
struct Obj;
extern u32 FLDMMDL_MOVE_HitCheckMove(void *m, struct Obj *o, s16 x, s16 y, int z, u16 kind);
u32 FLDMMDL_MOVE_HitCheckMoveCurrent(void *p, s16 x, s16 y, int z, u16 kind)
{
    VecFx32 pos;
    FLDMMDL_GetPos((const struct Actor *)p, (struct VecFx32 *)&pos);
    return FLDMMDL_MOVE_HitCheckMove(p, (struct Obj *)(&pos), x, y, z, kind);
}
