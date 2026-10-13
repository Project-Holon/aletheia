/*
 * function: BTL_POKEPARAM_SetSickCont
 * address: 0x021D6034
 * packet: pkt_ov093_021D6034
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   BTL_POKEPARAM_ClearMajorStatus 0x021D61F0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct UtilSlots;
extern int BTL_CALC_HasDefaultSickCont(int);
extern void BTL_POKEPARAM_ClearMajorStatus(struct UtilSlots *);
void BTL_POKEPARAM_SetSickCont(struct UtilSlots *p, int k, struct Slot v)
{
    if (BTL_CALC_HasDefaultSickCont(k)) BTL_POKEPARAM_ClearMajorStatus(p);
    ((struct Slot *)((u8 *)p + 0x1c))[(u32)k] = v;
    ((u8 *)p + (u32)k)[0xac] = 0;
}
