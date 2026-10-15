/*
 * function: FIELD_FK_SOUND_ANIME_Delete
 * address:  0x021F408C
 * packet:   pkt_ov056_021F408C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * extent:   EXACT* covers only the 2-byte alignment pad at 0x021F409E;
 *           the follower 0x021F40A0 is separately matched (pkt_021F40A0).
 *
 * symbols:
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   GFL_HEAP_Free   0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime;

extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern u32 GFL_HEAP_Free(void *p);

void FIELD_FK_SOUND_ANIME_Delete(struct IcaAnime **pp)
{
    ICA_ANIME_Delete(*pp);
    GFL_HEAP_Free(pp);
}
