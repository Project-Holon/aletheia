/*
 * function: WIFI_BSUBWAY_GRAPHIC_CancelBt
 * address: 0x021D7AA8
 * packet: pkt_ov116_021D7AA8
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 (pengy overlay, no witness).
 * blocker: ov114 ARM 021C93D0 has no outside code-start witness. It is vendor/integrator-owned: adjacent SDK EXT_TestResetCounter at 021C93BC (libext/ext_scrntest.o) uses same datum 021D4084; no SDK row exists for query leaf. TU/split cannot produce a viable partition.
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: DPW_BT_IsAsyncEnd (ov114 ARM, SDK-side
 *   libext code, no witness). Nothing source-side to change.
 * symbols:
 *   DPW_BT_IsAsyncEnd 0x021C93D0 arm ov114
 *   DPW_BT_CancelAsync 0x021C9634 arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 */

/*
 * 2026-10-04 (wave D2 lane05): MATCH, rechecked: one relocation unresolved, DPW_BT_IsAsyncEnd (ov114 ARM, same leaf as in func_021D70EC). Blocked on a matched witness for that leaf; ov114 belongs to pengy.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int DPW_BT_IsAsyncEnd(void);
extern void DPW_BT_CancelAsync(void);
extern void func_021D70E4(u8 *);
void WIFI_BSUBWAY_GRAPHIC_CancelBt(u8 *p)
{
    if (DPW_BT_IsAsyncEnd() == 0) {
        DPW_BT_CancelAsync();
        func_021D70E4(p + 0x182c);
    }
}
