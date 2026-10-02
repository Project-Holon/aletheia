/*
 * function: func_021B9C80
 * address: 0x021B9C80
 * packet: pkt_ov092_021B9C80
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: named record pointer schedules base-plus-index before the second index load.
 * symbols:
 *   func_02048F60 0x02048F60 arm
 *   func_020307B0 0x020307B0 arm
 * Prototype width: incoming heap value forwarded without truncation; widen legacy u16.
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void *func_02048F60(u32, unsigned short, u32);
extern void func_020307B0(void *);
u32 func_021B9C80(u32 p, u32 heap)
{
    void *data;
    u32 result;
    u8 *record;
    data = func_02048F60(0x98, 0, heap);
    record = (u8 *)data + *(u32 *)p * 0x24;
    result = *(record + *(u32 *)(p + 4) + 0x13);
    func_020307B0(data);
    return result;
}
