/*
 * function: SCRCMD_MMDL_ICA_ApplyFrame
 * address:  0x021D1988
 * packet:   pkt_ov021_021D1988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   ICA_ANIME_GetRotate  0x02011638  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

struct IcaAnime;
struct Rec12;
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *a, struct Rec12 *out);
extern u32 ICA_ANIME_GetRotate(struct IcaAnime *a, struct Rec12 *out);
extern void func_0207C9D0(Vec3 *a, Vec3 *b, Vec3 *c);
extern void FLDMMDL_SetPos(u32 a, Vec3 *v);
extern int FLDMMDL_SetDirAll(int a0, int a1);

void SCRCMD_MMDL_ICA_ApplyFrame(u32 a, u32 b, Vec3 *c)
{
    Vec3 v1;
    Vec3 v0;

    ICA_ANIME_GetTranslate((struct IcaAnime *)a, (struct Rec12 *)&v1);
    ICA_ANIME_GetRotate((struct IcaAnime *)a, (struct Rec12 *)&v0);
    func_0207C9D0(&v1, c, &v1);
    FLDMMDL_SetPos(b, &v1);
    if (v0.y == 0) {
        FLDMMDL_SetDirAll(b, 1);
    } else if (v0.y == 0x5A000) {
        FLDMMDL_SetDirAll(b, 3);
    } else if (v0.y == 0xB4000) {
        FLDMMDL_SetDirAll(b, 0);
    } else if (v0.y == 0x10E000) {
        FLDMMDL_SetDirAll(b, 2);
    }
}
