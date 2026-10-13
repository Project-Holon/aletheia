/*
 * function: SODATEYA_WithdrawPokemon
 * address:  0x021C3270
 * packet:   pkt_ov021_021C3270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   SODATEYA_GrantExp  0x021C3530  thumb  ov021
 *   SODATEYA_ReturnHeldItem  0x021C32BC  thumb  ov021
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC88  0x0200BC88  thumb
 *   SODATEYA_CompactSlots  0x021C36B0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_0200BCA8(u32, u32);
extern u32 func_0200BC2C(u32, u32);
typedef signed int     s32;
struct Obj;
extern u32 func_0200BCD8(struct Obj *p, u32 i);
extern void SODATEYA_GrantExp(void *mon, u32 b);
extern void SODATEYA_ReturnHeldItem(void **p, void *mon);
struct Party;
struct PartyMon;
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0200BC88(struct Obj *p, s32 i);
extern void SODATEYA_CompactSlots(void *e);

void SODATEYA_WithdrawPokemon(u32 *p, u32 b, u32 c)
{
    u32 m;

    if (func_0200BCA8(p[2], b) == 1) {
        m = func_0200BC2C(p[2], b);
        SODATEYA_GrantExp((void *)m, func_0200BCD8((struct Obj *)p[2], b));
        SODATEYA_ReturnHeldItem((void **)p, (void *)m);
        func_0201A98C((void *)c, (void *)m);
        func_0200BC88((struct Obj *)p[2], b);
        SODATEYA_CompactSlots((void *)p[2]);
    }
}
