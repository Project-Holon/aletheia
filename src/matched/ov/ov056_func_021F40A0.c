/*
 * function: FIELD_FK_SOUND_ANIME_Step
 * address:  0x021F40A0
 * packet:   pkt_021F40A0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unblocked (2026-09-26 recursive MATCH unblocker, arm9 0x0200..0x0202):
 *   both wildcarded relocations are now `matched`.
 *   - ICA_ANIME_GetFrameNum: EXACT, src/matched/ICA_ANIME_GetFrameNum.c (pkt_02011608).
 *   - ICA_ANIME_GetScale: already an EXACT member of the game_unit
 *     src/matched/unit_02011610.c (pkt_020113F0); that unit's `function:`
 *     header now lists all three copies, so the manifest covers 0x02011660.
 *   All 23 relocations resolve; EXACT* because the extent runs to the next
 *   unlabelled follower.
 *
 * symbols:
 *   ICA_ANIME_GetFrameNum  0x02011608  thumb
 *   ICA_ANIME_SetFrame  0x020115EC  thumb
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   ICA_ANIME_GetScale  0x02011660  thumb
 *   ICA_ANIME_GetRotate  0x02011638  thumb
 *   FIELD_FK_SOUND_ANIME_PlaySe  0x021F4224  thumb  ov056
 *   FIELD_FK_SOUND_ANIME_StopSe  0x021F423C  thumb  ov056
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj11244;
extern u32 ICA_ANIME_GetFrameNum(struct Obj11244 *p);
typedef signed int     s32;
struct IcaAnime;
struct Rec12;
extern void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v);
struct IcaAnime;
struct Rec12;
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *p, struct Rec12 *dst);
extern u32 ICA_ANIME_GetScale(struct IcaAnime *p, struct Rec12 *dst);
extern u32 ICA_ANIME_GetRotate(struct IcaAnime *p, struct Rec12 *dst);
extern void FIELD_FK_SOUND_ANIME_PlaySe(u8 *p, u32 idx);
extern void FIELD_FK_SOUND_ANIME_StopSe(u8 *p, u32 idx);

int FIELD_FK_SOUND_ANIME_Step(int *p)
{
    int flag;
    int a[3], b[3], c[3];
    int x = ICA_ANIME_GetFrameNum((struct Obj11244 *)p[0]) << 12;

    if (x <= p[1]) {
        flag = 1;
        p[1] = x - 0x1000;
    } else {
        flag = 0;
    }
    ICA_ANIME_SetFrame((struct IcaAnime *)p[0], p[1]);
    ICA_ANIME_GetTranslate((struct IcaAnime *)p[0], (struct Rec12 *)a);
    ICA_ANIME_GetScale((struct IcaAnime *)p[0], (struct Rec12 *)b);
    ICA_ANIME_GetRotate((struct IcaAnime *)p[0], (struct Rec12 *)c);
    if (a[0] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 0); else if (a[0] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 0);
    if (a[1] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 1); else if (a[1] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 1);
    if (a[2] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 2); else if (a[2] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 2);
    if (b[0] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 3); else if (b[0] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 3);
    if (b[1] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 4); else if (b[1] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 4);
    if (b[2] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 5); else if (b[2] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 5);
    if (c[0] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 6); else if (c[0] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 6);
    if (c[1] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 7); else if (c[1] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 7);
    if (c[2] == 0x1000) FIELD_FK_SOUND_ANIME_PlaySe((u8 *)p, 8); else if (c[2] == 0x2000) FIELD_FK_SOUND_ANIME_StopSe((u8 *)p, 8);
    p[1] += 0x1000;
    return flag;
}
