/*
 * function: FIELD_FK_DEMO_StepCamera
 * address:  0x021F3A78
 * packet:   pkt_ov056_021F3A78
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     twin of the head of FIELD_FK_SOUND_ANIME_Step (same clock read and clamp),
 *           with the frame counter at +0x28. EXACT* = 54 bytes of code plus
 *           2 bytes of alignment padding before matched FIELD_FK_DEMO_ApplyCameraAnime.
 * symbols:
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   ICA_ANIME_SetFrame  0x020115EC  thumb
 *   FIELD_FK_DEMO_ApplyCameraAnime  0x021F3AB0  thumb  ov056
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct IcaAnime;
struct Obj11244;
extern u32 ICA_ANIME_GetFrameNum(struct Obj11244 *p);
extern void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v);
extern void FIELD_FK_DEMO_ApplyCameraAnime(u32 *p);

int FIELD_FK_DEMO_StepCamera(u8 *p)
{
    int flag;
    s32 x = ICA_ANIME_GetFrameNum((struct Obj11244 *)(*(struct IcaAnime **)(p + 0x0))) << 12;
    s32 y = *(s32 *)(p + 0x28) + 0x1000;

    if (x <= y) {
        flag = 1;
        *(s32 *)(p + 0x28) = x - 0x1000;
    } else {
        flag = 0;
        *(s32 *)(p + 0x28) = y;
    }
    ICA_ANIME_SetFrame(*(struct IcaAnime **)(p + 0x0), *(s32 *)(p + 0x28));
    FIELD_FK_DEMO_ApplyCameraAnime((u32 *)p);
    return flag;
}
