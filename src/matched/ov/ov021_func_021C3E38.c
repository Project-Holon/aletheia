/*
 * function: SODATEYA_SetBaseFriendship
 * address:  0x021C3E38
 * packet:   pkt_ov021_021C3E38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reads personal-data field 0x15 for the species/form pair (EXACT*: pad).
 *
 * symbols:
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb  arm9
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb  arm9
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *POKE_PERSONAL_Create(u32 a, int b, u32 heap);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *h);

void SODATEYA_SetBaseFriendship(u32 *p, u32 heap)
{
    void *h = POKE_PERSONAL_Create((u16)p[0], (u16)p[1], heap);
    u32 v = POKE_PERSONAL_GetParam(h, 0x15);

    POKE_PERSONAL_Delete(h);
    p[5] = v;
}
