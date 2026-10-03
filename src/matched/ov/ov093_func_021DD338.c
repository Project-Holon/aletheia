/*
 * function: func_021DD338
 * address: 0x021DD338
 * packet: pkt_ov093_021DD338
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D67B8(u8 *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
u8 func_021DD338(void *a, int b)
{
    void *m;
    u8 slot;
    m = func_021C7CF4(a, b);
    slot = func_021D5778(m, func_021D67B8(m));
    if (slot != 4 && func_021D5584(m, slot) == 0) return slot;
    return 4;
}
