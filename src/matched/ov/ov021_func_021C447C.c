/*
 * function: SODATEYA_CanLearnTm
 * address:  0x021C447C
 * packet:   pkt_ov021_021C447C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 */

typedef unsigned int u32;

extern u32 FILE_UTIL_IsMachineItem(u32 a);
extern void *POKE_PERSONAL_Create(u32 species, int form, u32 heap);
extern u32 FILE_UTIL_GetId(u32 a);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);

int SODATEYA_CanLearnTm(u32 a, u32 b, u32 c, u32 d)
{
    u32 y, x, v;

    if (b >= 0x289)
        return 0;
    if (FILE_UTIL_IsMachineItem(d) == 0)
        return 0;
    x = (u32)POKE_PERSONAL_Create(b, c, a);
    y = FILE_UTIL_GetId(d);
    if (y < 0x20) {
        v = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x27);
    } else if (y < 0x40) {
        v = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x28);
        y -= 0x20;
    } else if (y < 0x60) {
        v = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x29);
        y -= 0x40;
    } else {
        v = POKE_PERSONAL_GetParam((const struct Personal *)x, 0x2a);
        y -= 0x60;
    }
    POKE_PERSONAL_Delete((void *)x);
    return v & (1 << y);
}
