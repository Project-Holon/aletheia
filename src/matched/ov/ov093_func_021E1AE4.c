/*
 * function: func_021E1AE4
 * address:  0x021E1AE4
 * packet:   pkt_ov093_021E1AE4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Ent { u16 a; u16 b; u8 c; u8 d; u8 e; u8 f; } Ent;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int func_021B9A24(u32 a, u32 b);
extern int WAZA_TOOL_GetDamageType(int a);

int func_021E1AE4(void *m, int x, Ent *out)
{
    u8 q = BTL_POKEPARAM_GetPokeId(m);
    u8 i = 0;
    while (BTL_POKEPARAM_GetHitRecord(m, 0, i++, (u16 *)out)) {
        if (func_021B9A24(q, out->d) == 0) {
            if (x == 0 || x == WAZA_TOOL_GetDamageType(out->a))
                return 1;
        }
    }
    return 0;
}
