/*
 * function: FIELD_GIMMICK_D06_AttachStone
 * address: 0x021F3B88
 * packet: pkt_ov051_021F3B88
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F3BC2 follows the return.
 * symbols:
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   FIELDMAP_GetEffect 0x02188CD0 thumb ov021
 *   FLDEFF_D06DENKI_StartFollow 0x021C9064 thumb ov021
 *   FLDEFF_D06DENKI_FollowFreezeLoop 0x021C909C thumb ov021
 *   FIELD_GIMMICK_D06_IsStoneNextToPanel 0x021F3C98 thumb ov051
 * note: FLDEFF_D06DENKI_StartFollow's result is stored and read by caller; extern preserves r0 despite its void definition.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 x,y,z; } V;
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern u32 FIELDMAP_GetEffect(u8 *);
extern u32 FLDEFF_D06DENKI_StartFollow(u32, V *, u32);
extern void FLDEFF_D06DENKI_FollowFreezeLoop(u32);
extern int FIELD_GIMMICK_D06_IsStoneNextToPanel(int *a, int *b);
void FIELD_GIMMICK_D06_AttachStone(int *a, u32 *out, int c)
{
    V v;
    out[0]=c;
    FLDMMDL_GetPos((const struct Actor *)c,(struct VecFx32 *)&v);
    out[1]=FLDEFF_D06DENKI_StartFollow(FIELDMAP_GetEffect((u8 *)a[2]),&v,out[0]);
    if(FIELD_GIMMICK_D06_IsStoneNextToPanel(a,(int *)out)==1) FLDEFF_D06DENKI_FollowFreezeLoop(out[1]);
}
