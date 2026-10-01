/*
 * function: func_021F8950
 * address: 0x021F8950
 * packet: pkt_ov135_021F8950
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_020200CC(void *p);
extern void func_020202EC(void *p, u16 *out);
extern void func_020061E4(u32 id);
int func_021F8950(void *p, u16 *old)
{
    u16 current;
    int result;
    result = func_020200CC(p);
    func_020202EC(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) func_020061E4(0x548);
        *old = current;
    }
    return result;
}
