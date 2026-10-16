/*
 * function: GF_OVERLAY_RegisterPanicHandlers
 * address:  0x02034978
 * packet:   pkt_02034714
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034768  0x02034768  arm
 *   GF_OVERLAY_PanicPrint  0x020348A4  arm
 *   func_02034900  0x02034900  arm
 *   SAVEDATA_SetPanicHandlers  0x020346EC  arm
 *
 * The default-handler registration trampoline: tail-calls SAVEDATA_SetPanicHandlers
 * (pkt_020345F8, the "register" half of the assert/panic hook: see
 * src/matched/unit_020346EC.c) with the addresses of this packet's own
 * three biggest functions, none of which is matched yet.
 *
 * Every concrete byte matches; the three ABS32 sites naming those
 * functions have no witness anywhere else in the ARM9 image (each of
 * those addresses is a function that no `bl`/`label` site reaches), so
 * they stay unresolved under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GF_OVERLAY_RegisterPanicHandlers.c \
 *       --func GF_OVERLAY_RegisterPanicHandlers --addr 0x02034978 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02034768(void);
extern void GF_OVERLAY_PanicPrint(char *s);
extern void func_02034900(void);
extern void SAVEDATA_SetPanicHandlers(u32 a, u32 b, u32 c);

void GF_OVERLAY_RegisterPanicHandlers(void)
{
    SAVEDATA_SetPanicHandlers((u32)func_02034768, (u32)GF_OVERLAY_PanicPrint, (u32)func_02034900);
}
