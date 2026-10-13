/*
 * function: BTL_SERVER_FLOW_ProcSickDamage
 * address: 0x021C4A64
 * packet: pkt_ov093_021C4A64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_CalcSickDamage 0x021C4B3C thumb ov093
 *   BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed 0x021C20BC thumb ov093
 *   BTL_SERVER_FLOW_PushPokeEffectAnim 0x021C5480 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021C4B2C 0x021C4B2C thumb ov093
 *   BTL_SERVER_FLOW_ProcAbsorbRecovery 0x021C20D0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_CalcSickDamage(u8 *, u8 *, u32, u32);
extern int BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(u8 *, u8 *, int);
extern void BTL_SERVER_FLOW_PushPokeEffectAnim(u8 *, u8 *, int);
extern void func_021C8810(u8 *);
extern void func_021C4B2C(u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_ProcAbsorbRecovery(u8 *p, u8 *a, int c, u8 *l);
void BTL_SERVER_FLOW_ProcSickDamage(u8 *p, u8 *a, u32 b, u32 c)
{
    u32 lock;
    int r;
    lock = func_021CC8D8(p + 0x1d74, 0x261b);
    r = BTL_SERVER_FLOW_CalcSickDamage(p, a, b, c);
    if (r && BTL_SERVER_FLOW_CheckAbsorbRecoverAllowed(p, a, r)) {
        switch (b) {
        case 0: case 1: case 2: case 3: break;
        case 5: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 0x257); break;
        case 4: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 0x258); break;
        case 6: case 7: case 8: break;
        case 10: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 0x273); break;
        case 9: BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 0x274); break;
        }
        func_021C8810(p + 0x1ae4);
        func_021C4B2C(p + 0x1ae4, a, b);
        BTL_SERVER_FLOW_ProcAbsorbRecovery(p, a, r, p + 0x1ae4);
    }
    func_021CC95C((u32 *)(p + 0x1d74), lock, 0x263b);
}
