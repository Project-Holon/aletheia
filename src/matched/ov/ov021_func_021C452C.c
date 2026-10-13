/*
 * function: SODATEYA_GetAbilitySlot
 * address:  0x021C452C
 * packet:   pkt_ov021_021C452C
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
typedef unsigned char u8;

extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);

u8 SODATEYA_GetAbilitySlot(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[3];
    u32 x = (u32)POKE_PERSONAL_Create(a, b, d);
    u32 i;

    s[0] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1a);
    s[1] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1b);
    s[2] = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x1c);
    POKE_PERSONAL_Delete((void *)x);
    for (i = 0; i < 3; i++) {
        if (c == s[i])
            break;
    }
    if (i >= 3)
        i = 0;
    return i;
}
