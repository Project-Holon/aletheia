/*
 * function: STARTMENU_Demo3dDelete
 * address:  0x021B9E54
 * packet:   pkt_ov088_021B9E54
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (40) runs 2 bytes past the compiled function (38);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_LIGHT_DeleteSlots  0x02048C4C  arm
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_UTIL_Delete  0x02047E54  arm
 */

typedef unsigned int   u32;
struct Ctx;
struct IcaAnime;
struct Rec;
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_LIGHT_DeleteSlots(int);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern void G3D_UTIL_Delete(struct Rec *p);

void STARTMENU_Demo3dDelete(int *p)
{
    ICA_ANIME_Delete((struct IcaAnime *)p[3]);
    G3D_CAMERA_Delete((void *)p[4]);
    G3D_LIGHT_DeleteSlots(p[2]);
    G3D_UTIL_RemoveUnit((struct Ctx *)p[0], ((unsigned short *)p)[2]);
    G3D_UTIL_Delete((struct Rec *)p[0]);
}
