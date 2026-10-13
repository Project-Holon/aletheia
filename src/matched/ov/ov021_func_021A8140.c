/*
 * function: func_021A8140
 * address:  0x021A8140
 * packet:   pkt_ov021_021A8140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetMoveOffsetInDir  0x021A3484  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 */

typedef struct V {
    int x;
    int y;
    int z;
} V;

typedef unsigned short u16;
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
typedef signed int     s32;
extern void FIELD_PLAYER_GetMoveOffsetInDir(unsigned char **a, int b, s32 *c);
extern void func_0207CEE4(int a, V *b, V *c, V *d);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_MOVE_GetMapHeight(void *p, V *in, int *out);

void func_021A8140(void *a, V *out)
{
    void *ctx;
    int k;
    V v0;
    V v1;
    V v2;
    int t;

    ctx = FIELDMAP_GetFieldPlayer(a);
    k = FIELD_PLAYER_GetDirDisp(ctx);
    FIELD_PLAYER_GetPos(ctx, (struct VecFx32 *)&v0);
    FIELD_PLAYER_GetMoveOffsetInDir(ctx, k, (s32 *)(&v1));
    func_0207CEE4(0x10000, &v1, &v0, &v2);
    FLDMMDL_MOVE_GetMapHeight(FIELD_PLAYER_GetMmdl(ctx), &v2, &t);
    v2.y = t;
    *out = v2;
}
