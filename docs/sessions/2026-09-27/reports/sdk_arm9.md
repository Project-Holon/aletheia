# sdk_arm9 lane report (2026-09-27)

Tool: `tools/sdkobj.py` (new). Name or address in, archive member out: disassembly beside the image
bytes with every relocation named and resolved to its image address and status, a declaration block
with callee prototypes from the callee's own DWARF, house-header `symbols:` lines, struct layouts
(`--types`), the object's `.comment` stamp mapped to a tools/mwccarm front end, `--open` for the open
SDK rows of a region, `--selftest` (PASS).

Three trees, 14 functions, all EXACT/EXACT*, all dsi/1.1p1 (no pins):

| tree root | functions | verdicts |
|---|---|---|
| STD_TVSNPrintf 0x0208D834 (2012 B) | string_put_char, string_fill_char, string_put_string, root | EXACT x3, string_put_string EXACT* |
| STD_TVSScanf 0x0208CFD8 (1840 B) | STDi_IsSpace, STDi_FillBitset, root | EXACT x3 |
| RtcCommonCallback 0x02088A04 (1112 B) | RtcBCD2HEX, RTC_GetDayOfWeek, RTCi_WriteRawStatus2Async, OS_IsRunOnTwl, root | EXACT x4, RtcBCD2HEX EXACT* |

What closed them: first drafts from the DWARF names and types; STD_TVSNPrintf's sign test is
`(val >> 32) & 0x80000000`; STD_TVSScanf needed a top-tested `for(;;)` for the '[' set loop,
`dst`/`dst_bak` assigned together, and `matchcond` at function scope ahead of `stored` (spill slot
order); STDi_IsSpace needs a result local preset to 0; RtcCommonCallback's date-time arm reads the year
as `*(u32 *)raw & 0xFF`.

Shards verified twice (second pass 0 rewritten): pkt_0208D708, 0208D734, 0208D788, 0208D834,
0208CF5C, 0208CF84, 0208CFD8, 02088E5C, 02088F1C, 02089274, 02085D3C, 02088A04. `manifest --check`
clean.

Next roots (biggest open arm9 SDK): WmReceiveFifo 0x0208E5BC, NVRAMi_WriteCallback 0x020839E8,
MTX_Concat44 0x0207BE14, ProcessBlock 0x02080D68, FSi_InvokeCommand 0x02077758, FSi_GetPathDefault
0x0207976C, MTX_Inverse43 0x0207B67C, CARDi_IdentifyBackupCore2 0x020766D8.

Integrator: all TwlSDK members seen carry stamp 4.0.0.1024 = dsi/1.1p1 (default). TwlDWC members carry
4.0.0.1025, which no tools/mwccarm build writes (1.1p1 = 1024, 1.2 = 1026). EXACT* on string_put_string
and RtcBCD2HEX comes from unlabelled followers at 0x0208D7E0 (already matched, seeded 4 bytes late) and
0x02088EC4.
