/*
 * function: SODATEYA_SetAbilityFromSlot
 * address:  0x021C3DE4
 * packet:   pkt_ov021_021C3DE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *POKE_PERSONAL_Create(u32 a, int b, u32 heap);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);

void SODATEYA_SetAbilityFromSlot(u32 *a, u32 *p, u32 heap)
{
    u32 s[3];
    u32 x = (u32)POKE_PERSONAL_Create((u16)p[0], (u16)p[1], heap);

    s[0] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1a);
    s[1] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1b);
    s[2] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1c);
    POKE_PERSONAL_Delete((void *)x);
    if (p[0x13] < 2) {
        p[4] = s[p[0x13]];
        if (p[4] == 0)
            p[4] = s[0];
    }
}
