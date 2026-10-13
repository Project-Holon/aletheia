/*
 * function: BTL_SERVER_FLOW_ProcTurnCheck
 * address: 0x021C446C
 * packet: pkt_ov093_021C446C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: unlabelled thunk 021C4B8C and veneers 021C45E4, 021C45F4,
 * 021C4604 have no attested targets. The thunk loads target 0x06898D54;
 * the veneers load 0x0689CC84, 0x0689CC8C, 0x0689CC8C respectively,
 * outside every image region. Its 376 compiled bytes are concrete-correct.
 * Trailing extent holds Thumb linker veneers 021C45E4, 021C45F4, 021C4604.
 * 2026-10-05 (D9 lane 02): 021C4B8C is `adds r1,r0,#0; ldr r0,[pc]; ldr r3,[pc]; bx r3` with pool words 0x021C4B9D and 0x06898D55: a linker thunk to a function outside the image, not C
 *   (a C call through the constant gives push/blx/pop, 14 bytes differ). The veneers are the same kind. Stays MATCH*.
 * 2026-10-05 (D9r lane16): 021C4B8C is NOT a linker thunk. It is C: a Thumb
 *   tail call `func_06898D54(BTL_SERVER_FLOW_OnSideEffectExpired, p)` into the matched ov095 walker
 *   (ov095 lives in VRAM at 0x0689xxxx). BTL_SERVER_FLOW_OnSideEffectExpired (new EXACT witness,
 *   src/matched/ov/ov093_func_021C4B9C.c) is the callback that swaps args and
 *   tail calls BTL_SERVER_FLOW_PushSideEffectExpireMessage. BTL_SERVER_FLOW_ProcSideEffectsExpire itself verifies MATCH (pending
 *   file) only because the ABS32 to 021C4B9C needs a manifest witness; it is
 *   EXACT once the integrator writes the 021C4B9C shard. 021C45E4, 021C45F4,
 *   021C4604 are real linker veneers (bx pc; nop; ldr ip,[pc]; bx ip) to the
 *   matched ov095 functions 0x0689CC84 / 0x0689CC8C / 0x0689CC8C; the harness
 *   already attests them (veneer class). After the shards land, the only
 *   residue here should be the 4B8C call. Concrete bytes unchanged.
 * symbols:
 *  BTL_SERVER_FLOW_CollectActivePokes 0x021C43F0 thumb ov093
 *  BTL_SERVER_FLOW_ProcPlayerSupportHeal 0x021C4744 thumb ov093
 *  BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *  BTL_SERVER_FLOW_ProcWeatherTurnCheck 0x021C4D1C thumb ov093
 *  BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *  BTL_SERVER_FLOW_ProcTurnCheckPhase 0x021C4838 thumb ov093
 *  BTL_SERVER_FLOW_ProcTurnCheckSickness 0x021C493C thumb ov093
 *  BTL_SERVER_FLOW_ProcSideEffectsExpire 0x021C4B8C thumb ov093
 *  BTL_SERVER_FLOW_ProcFieldEffectsExpire 0x021C4C24 thumb ov093
 *  func_021C45E4 0x021C45E4 thumb ov093
 *  func_021C45F4 0x021C45F4 thumb ov093
 *  func_021C4604 0x021C4604 thumb ov093
 *  BTL_POKEPARAM_AdvanceTurn 0x021D6408 thumb ov093
 *  BTL_EVENT_ClearClientReservedChoice 0x021D6E88 thumb ov093
 *  BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *  BTL_SERVER_FLOW_ProcTripleShift 0x021C4614 thumb ov093
 *  BTL_EVENT_RemoveDeadFactors 0x021D701C thumb ov093
  * note 2026-10-05 (D8 lane16): re-verified MATCH*. Callee 0x021C4B8C is a Thumb thunk to 0x06898D54 (veneer-like, outside every image region) and 021C45E4/F4/604 are veneers; not C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_FLOW_CollectActivePokes(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcPlayerSupportHeal(u8 *);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_SERVER_FLOW_ProcWeatherTurnCheck(u8 *p, void *it);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *);
extern int BTL_SERVER_FLOW_ProcTurnCheckPhase(u8 *, u8 *, u8 *);
extern int BTL_SERVER_FLOW_ProcTurnCheckSickness(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcSideEffectsExpire(u8 *);
extern void BTL_SERVER_FLOW_ProcFieldEffectsExpire(u8 *);
extern void func_021C45E4(u8 *);
extern u8 *func_021C45F4(u8 *);
extern u8 *func_021C4604(u8 *);
extern void BTL_POKEPARAM_AdvanceTurn(u8 *);
extern void BTL_EVENT_ClearClientReservedChoice(u8 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern void BTL_SERVER_FLOW_ProcTripleShift(u8 *);
extern void BTL_EVENT_RemoveDeadFactors(void);
int BTL_SERVER_FLOW_ProcTurnCheck(u8 *p)
{
    u8 *a;
    u8 *q;
    int result = 0;
    a = *(u8 **)(p + 0x854);
    if (p[0x77e] == 0) {
        BTL_SERVER_FLOW_CollectActivePokes(p, a);
        p[0x77e] = 1;
        BTL_SERVER_FLOW_ProcPlayerSupportHeal(p);
    }
    switch (p[0x77e]) {
    case 0: break;
    case 1:
        p[0x77e]++;
        BTL_SERVER_CMD_Push(*(void **)(p + 12), 0x56, 0);
        result = 0;
        if (BTL_SERVER_FLOW_ProcWeatherTurnCheck(p, a)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(p)) return 0;
    case 2:
        p[0x77e]++;
        if (BTL_SERVER_FLOW_ProcTurnCheckPhase(p, a, (u8 *)0x76)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(p)) return 0;
    case 3:
        p[0x77e]++;
        if (BTL_SERVER_FLOW_ProcTurnCheckSickness(p, a)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(p)) return 0;
    case 4:
        p[0x77e]++;
        BTL_SERVER_FLOW_ProcSideEffectsExpire(p);
        BTL_SERVER_FLOW_ProcFieldEffectsExpire(p);
    case 5:
        p[0x77e]++;
        if (BTL_SERVER_FLOW_ProcTurnCheckPhase(p, a, (u8 *)0x77)) { result = 1; break; }
        if (BTL_SERVER_FLOW_CheckShowdown(p)) return 0;
    case 6:
        BTL_SERVER_FLOW_ProcTurnCheckPhase(p, a, (u8 *)0x78);
        p[0x77e]++;
        func_021C45E4(a);
        q = func_021C45F4(a);
        while (q) {
            BTL_POKEPARAM_AdvanceTurn(q);
            BTL_EVENT_ClearClientReservedChoice(q);
            BTL_SERVER_CMD_Push(*(void **)(p + 12), 0x2e, BTL_POKEPARAM_GetPokeId(q));
            q = func_021C4604(a);
        }
        BTL_SERVER_FLOW_ProcTripleShift(p);
        BTL_EVENT_RemoveDeadFactors();
        if (*(u32 *)(p + 16) < 9999) (*(u32 *)(p + 16))++;
        p[0x77e] = 0;
        *(u32 *)(p + 0x774) = 0;
        return 0;
    default: break;
    }
    return result;
}
