# sdk9_gxfx: ARM9 SDK libgx and libfx

Lane territory: the 99 open arm9 SDK rows in libgx.TWL.HYB.a and libfx.TWL.HYB.a.
All work from `tools/sdkobj.py` / `tools/match.py show` only; no file under `sdk/` was opened.
Every object checked carries stamp 4.0.0.1024 (dsi/1.1p1); flags `-O4,p`, lang `c99` throughout.

## Totals

- 93 functions filed under `src/matched/arm9_sdk/func_<ADDR>.c`, 8,216 bytes: 85 EXACT, 8 EXACT*.
  Each has its own shard `layout/matched/arm9/pkt_<ADDR>.json`; `manifest --verify --shard` run
  twice per shard, second pass rewrote 0, and a final re-verify of all 93 rewrote 0. Header
  `status:` equals the shard verdict for every file. `manifest --check` shows no arm9 duplicate
  (its 6 duplicates are overlay shards, not this lane).
- 4 functions left in `src/pending/arm9_sdk/` with status DIFF and a notes line.
- 2 catalog rows not taken: they are not SDK code (see below).

## Matched (address, symbol, object, isa, bytes, verdict)

| address | symbol | object | isa | bytes | verdict |
|---|---|---|---|---|---|
| 0x0207AD40 | MTX_Identity22_ | fx_mtx22.o | arm | 24 | EXACT |
| 0x0207AD58 | MTX_Scale22_ | fx_mtx22.o | thumb | 12 | EXACT |
| 0x0207AD70 | MTX_ScaleApply22 | fx_mtx22.o | arm | 84 | EXACT |
| 0x0207ADC4 | MTX_Identity33_ | fx_mtx33.o | arm | 36 | EXACT |
| 0x0207ADE8 | MTX_Copy33To44_ | fx_mtx33.o | arm | 60 | EXACT* |
| 0x0207AE24 | MTX_Scale33_ | fx_mtx33.o | thumb | 18 | EXACT |
| 0x0207AE38 | MTX_ScaleApply33 | fx_mtx33.o | arm | 200 | EXACT |
| 0x0207AF50 | MTX_RotAxis33 | fx_mtx33.o | arm | 340 | EXACT |
| 0x0207B51C | MTX_MultVec33 | fx_mtx33.o | arm | 124 | EXACT |
| 0x0207B598 | MTX_Identity43_ | fx_mtx43.o | arm | 40 | EXACT |
| 0x0207B5C0 | MTX_Copy43To44_ | fx_mtx43.o | arm | 52 | EXACT |
| 0x0207B60C | MTX_ScaleApply43 | fx_mtx43.o | arm | 52 | EXACT* |
| 0x0207B640 | MTX_RotY43_ | fx_mtx43.o | thumb | 26 | EXACT |
| 0x0207BC08 | MTX_MultVec43 | fx_mtx43.o | arm | 152 | EXACT |
| 0x0207BCA0 | MTX_LookAt | fx_mtx43.o | arm | 276 | EXACT |
| 0x0207C788 | FX_InvFx64c (catalog: FX_DivFx64c) | fx_cp.o | arm | 44 | EXACT |
| 0x0207C7B4 | FX_Sqrt | fx_cp.o | arm | 52 | EXACT |
| 0x0207C7E8 | FX_InvSqrt | fx_cp.o | arm | 96 | EXACT |
| 0x0207C8A0 | FX_InvAsync | fx_cp.o | arm | 48 | EXACT |
| 0x0207C904 | FX_GetSqrtResult | fx_cp.o | arm | 44 | EXACT |
| 0x0207C994 | FX_ModS32 | fx_cp.o | arm | 60 | EXACT |
| 0x0207C9D0 | VEC_Add | fx_vec.o | arm | 48 | EXACT |
| 0x0207CA00 | VEC_Subtract | fx_vec.o | arm | 48 | EXACT |
| 0x0207CA30 | VEC_Fx16Add | fx_vec.o | arm | 56 | EXACT |
| 0x0207CA68 | VEC_DotProduct | fx_vec.o | arm | 60 | EXACT |
| 0x0207CAA4 | VEC_Fx16DotProduct | fx_vec.o | arm | 68 | EXACT |
| 0x0207CAE8 | VEC_CrossProduct | fx_vec.o | arm | 128 | EXACT |
| 0x0207CB68 | VEC_Fx16CrossProduct | fx_vec.o | arm | 104 | EXACT |
| 0x0207CBD0 | VEC_Mag | fx_vec.o | arm | 96 | EXACT* |
| 0x0207CC30 | VEC_Fx16Mag | fx_vec.o | arm | 116 | EXACT |
| 0x0207CEE4 | VEC_MultAdd | fx_vec.o | arm | 88 | EXACT |
| 0x0207CF3C | VEC_Distance | fx_vec.o | arm | 124 | EXACT |
| 0x0207D14C | FX_Modf | fx.o | arm | 56 | EXACT |
| 0x0207D184 | FX_AcosIdx | fx_asinacosidx.o | arm | 128 | EXACT |
| 0x0207D384 | GX_SetVCountEqVal | gx.o | arm | 40 | EXACT |
| 0x0207D534 | GXx_SetMasterBrightness_ | gx.o | arm | 40 | EXACT |
| 0x0207D658 | G2x_SetBlendBrightness_ | g2.o | arm | 36 | EXACT |
| 0x0207D67C | G2x_SetBlendBrightnessExt_ | g2.o | arm | 68 | EXACT* |
| 0x0207D6C0 | G2x_ChangeBlendBrightness_ | g2.o | arm | 68 | EXACT |
| 0x0207D704 | G3i_PerspectiveW_ | g3_util.o | arm | 92 | EXACT |
| 0x0207D760 | G3i_FrustumW_ | g3_util.o | arm | 100 | EXACT |
| 0x0207D7C4 | G3i_LookAt_ | g3_util.o | arm | 76 | EXACT |
| 0x0207D810 | G3_RotX | g3_util.o | arm | 60 | EXACT* |
| 0x0207D84C | G3_RotY | g3_util.o | arm | 60 | EXACT |
| 0x0207D888 | G3_RotZ | g3_util.o | arm | 60 | EXACT |
| 0x0207D950 | G3_MultTransMtx33 | g3imm.o | arm | 56 | EXACT |
| 0x0207D988 | G3X_Init | g3x.o | arm | 260 | EXACT |
| 0x0207DA8C | G3X_Reset | g3x.o | arm | 108 | EXACT |
| 0x0207DAF8 | G3X_ClearFifo | g3x.o | arm | 36 | EXACT |
| 0x0207DB1C | G3X_InitMtxStack | g3x.o | arm | 152 | EXACT |
| 0x0207DBB4 | G3X_ResetMtxStack | g3x.o | arm | 144 | EXACT |
| 0x0207DC44 | G3X_SetFog | g3x.o | arm | 84 | EXACT |
| 0x0207DC98 | G3X_GetClipMtx | g3x.o | arm | 48 | EXACT |
| 0x0207DCC8 | G3X_GetVectorMtx | g3x.o | arm | 48 | EXACT* |
| 0x0207DD24 | G3X_SetClearColor | g3x.o | arm | 40 | EXACT |
| 0x0207DD4C | G3X_InitTable | g3x.o | arm | 228 | EXACT |
| 0x0207DE30 | G3X_GetMtxStackLevelPV | g3x.o | arm | 44 | EXACT |
| 0x0207DE5C | G3X_GetMtxStackLevelPJ | g3x.o | arm | 44 | EXACT* |
| 0x0207DE88 | G3X_SetDisp1DotDepth | g3x.o | arm | 28 | EXACT |
| 0x0207DEA4 | G3X_GetBoxTestResult | g3x.o | arm | 40 | EXACT |
| 0x0207DECC | GXi_NopClearFifo128_ | g3x.o | arm | 148 | EXACT |
| 0x0207E008 | G2_GetBG2ScrPtr | gx_bgcnt.o | arm | 132 | EXACT |
| 0x0207E08C | G2S_GetBG2ScrPtr | gx_bgcnt.o | arm | 116 | EXACT |
| 0x0207E100 | G2_GetBG3ScrPtr | gx_bgcnt.o | arm | 132 | EXACT |
| 0x0207E184 | G2S_GetBG3ScrPtr | gx_bgcnt.o | arm | 116 | EXACT |
| 0x0207E2A0 | G2_GetBG2CharPtr | gx_bgcnt.o | arm | 80 | EXACT |
| 0x0207E2F0 | G2S_GetBG2CharPtr | gx_bgcnt.o | arm | 64 | EXACT |
| 0x0207E330 | G2_GetBG3CharPtr | gx_bgcnt.o | arm | 88 | EXACT |
| 0x0207E388 | G2S_GetBG3CharPtr | gx_bgcnt.o | arm | 72 | EXACT |
| 0x02080100 | GX_SetBankForBGExtPltt | gx_vramcnt.o | arm | 248 | EXACT |
| 0x020801F8 | GX_SetBankForOBJExtPltt | gx_vramcnt.o | arm | 156 | EXACT |
| 0x0208040C | GX_SetBankForTexPltt | gx_vramcnt.o | arm | 220 | EXACT |
| 0x020804E8 | GX_SetBankForClearImage | gx_vramcnt.o | arm | 256 | EXACT |
| 0x020805E8 | GX_SetBankForARM7 | gx_vramcnt.o | arm | 164 | EXACT |
| 0x020806B0 | GX_SetBankForSubBG | gx_vramcnt.o | arm | 156 | EXACT |
| 0x0208074C | GX_SetBankForSubOBJ | gx_vramcnt.o | arm | 112 | EXACT |
| 0x020807BC | GX_SetBankForSubBGExtPltt | gx_vramcnt.o | arm | 128 | EXACT |
| 0x0208083C | GX_SetBankForSubOBJExtPltt | gx_vramcnt.o | arm | 128 | EXACT |
| 0x020808BC | resetBankForX_ | gx_vramcnt.o | arm | 56 | EXACT |
| 0x02080A18 | disableBankForX_ | gx_vramcnt.o | arm | 192 | EXACT* |
| 0x02080AD8 | GX_DisableBankForBG | gx_vramcnt.o | arm | 20 | EXACT |
| 0x02080AEC | GX_DisableBankForOBJ | gx_vramcnt.o | arm | 20 | EXACT |
| 0x02080B00 | GX_DisableBankForBGExtPltt | gx_vramcnt.o | arm | 36 | EXACT |
| 0x02080B24 | GX_DisableBankForOBJExtPltt | gx_vramcnt.o | arm | 36 | EXACT |
| 0x02080B48 | GX_DisableBankForTex | gx_vramcnt.o | arm | 20 | EXACT |
| 0x02080B5C | GX_DisableBankForTexPltt | gx_vramcnt.o | arm | 20 | EXACT |
| 0x02080B70 | GX_DisableBankForClearImage | gx_vramcnt.o | arm | 20 | EXACT |
| 0x02080B84 | GX_DisableBankForARM7 | gx_vramcnt.o | arm | 20 | EXACT |
| 0x02080BD4 | GX_DisableBankForSubBGExtPltt | gx_vramcnt.o | arm | 40 | EXACT |
| 0x02080BFC | GX_DisableBankForSubOBJExtPltt | gx_vramcnt.o | arm | 40 | EXACT |
| 0x02080C84 | GX_SendFifo48B | gxasm.o | arm | 36 | EXACT |
| 0x02080CA8 | GX_SendFifo64B | gxasm.o | arm | 28 | EXACT |
| 0x02080CC4 | GX_InitGXState | gxstate.o | arm | 96 | EXACT |

EXACT* rows: 0x0207ADE8 and 0x0207CBD0 (listing extent longer than the function), 0x0207B60C,
0x0207D67C, 0x0207D810, 0x0207DCC8, 0x0207DE5C, 0x02080A18: verdict as the manifest gave it.

## asm bodies (evidence line in each header)

- 0x02080C84 GX_SendFifo48B, 0x02080CA8 GX_SendFifo64B: gxasm.o is an asm-only object; fixed-register ldm/stm block copy into the FIFO.
- 0x0207DECC GXi_NopClearFifo128_: fixed-register `stmia r0, {r1, r2, r3, r12}` x32 into the geometry FIFO.
- 0x0207AD40 MTX_Identity22_, 0x0207AD58 MTX_Scale22_ (thumb), 0x0207ADC4 MTX_Identity33_, 0x0207AE24 MTX_Scale33_ (thumb),
  0x0207B598 MTX_Identity43_, 0x0207B640 MTX_RotY43_ (thumb): fixed-register `stm rN!` writeback stores.
- 0x0207ADE8 MTX_Copy33To44_, 0x0207B5C0 MTX_Copy43To44_: fixed-register ldm/stm block copy with writeback.

## Pending (src/pending/arm9_sdk/)

- 0x0207C8D0 FX_SqrtAsync, DIFF 31 bytes: the image if-converts both arms and shares the high-word
  store (`str r0, [r1, #0xc]`); every C spelling tried ends the gt arm with `bxgt lr`. Permuter seeds
  12602, 12603 did not close it.
- 0x0207CCA4 VEC_Normalize, DIFF 24 bytes, scheduling only: the image computes the high word of
  `t << 2` after the divider denominator low-word store; this C hoists it above the DIVCNT write.
  Tried macro vs inline setters, `t * 4`, a pre-computed u64, `t <<= 2`. Permuter seed 12601 flat.
- 0x0207CDB8 VEC_Fx16Normalize, DIFF 19 bytes, same scheduling residue as VEC_Normalize.
- 0x0207D59C G2x_SetBGyAffine_, DIFF 38 bytes, register allocation only (identical instruction
  shapes and order). 12 variants of statement order / operand order / locals tried; permuter seed
  12606 got worse.

## Files written

- `src/matched/arm9_sdk/func_<ADDR>.c` and `layout/matched/arm9/pkt_<ADDR>.json` for the 93
  addresses in the table above.
- `src/pending/arm9_sdk/func_0207C8D0.c`, `func_0207CCA4.c`, `func_0207CDB8.c`, `func_0207D59C.c`.
- Pending files at my addresses replaced by my own work from the object (not read, not salvaged):
  deleted `src/pending/arm9_sdk/func_0207ADC4.c`, `func_0207B598.c`, `func_0207C7E8.c`,
  `func_0207E008.c`, `func_0207E08C.c`, `func_0207E100.c`, `func_0207E184.c`, `func_0207E2A0.c`,
  `func_0207E2F0.c`, `func_0207E330.c`, `func_0207E388.c` (superseded by the matched func_ files),
  and `mtx_identity22.c` (0x0207AD40), `MTX_RotAxis33.c` (0x0207AF50),
  `VEC_Fx16Normalize.c` (0x0207CDB8, replaced by my pending draft).

## Integrator attention: orphan matched files at my addresses

These files sit in `src/matched/arm9_sdk/` with a header address in my territory but no shard entry
(which is why the rows were open). I did not read or touch them; they now duplicate my verified
func_ files and should be removed:
`fx_divfx64c.c` (0x0207C788), `fx_sqrt.c` (0x0207C7B4), `fx_invasync.c` (0x0207C8A0),
`fx_sqrtasync.c` (0x0207C8D0, my version is still pending), `fx_getsqrtresult.c` (0x0207C904),
`vec_add.c` (0x0207C9D0), `vec_subtract.c` (0x0207CA00), `vec_fx16add.c` (0x0207CA30),
`g3x_clearfifo.c` (0x0207DAF8), `g3x_getclipmtx.c` (0x0207DC98), `g3x_getvectormtx.c` (0x0207DCC8),
`g3x_setclearcolor.c` (0x0207DD24), `g3x_getmtxstacklevelpv.c` (0x0207DE30),
`g3x_getmtxstacklevelpj.c` (0x0207DE5C), `g3x_getboxtestresult.c` (0x0207DEA4),
`gx_setvcounteqval.c` (0x0207D384), `gxx_setmasterbrightness.c` (0x0207D534).

## Catalog and DWARF name disagreements

- 0x0207C788: catalog FX_DivFx64c. The image calls FX_InvAsync (0x0207C8A0) with one argument, so
  the object symbol at this offset is FX_InvFx64c (44 bytes, same size, unlocated in the catalog).
  Filed with that name in the header. The vendor FX_DivFx64c reloc names FX_DivAsync, which is
  actually 0x0207C930.
- gx_vramcnt.o: the catalog carries two addresses for each GX_DisableBankFor* name (0x02080908..
  0x020809f0, already matched, and 0x02080ad8..0x02080bfc). The 0x02080ad8 run calls
  disableBankForX_ (0x02080A18) and is the real Disable family; the earlier matched run is most
  likely the GX_ResetBankFor* family (resetBankForX_ at 0x020808BC). The matched file named
  `GX_DisableBankForBGExtPltt.c` at 0x0208091C is therefore probably GX_ResetBankForBGExtPltt.
- 0x0207C554: catalog/matched label MTX_OrthoW, but G3i_FrustumW_ relocates to MTX_FrustumW there.
  A second label named MTX_FrustumW also exists at 0x0207C1D0 (the `label` resolver picked it
  until the symbols block pinned 0x0207C554).
- 0x02084A28 GX_GetBankForLCDC and 0x0208AF08 GX_GetBankForOBJExtPltt: byte-pattern false
  positives. They load from 0x02150FC8 / 0x02152FA4, not gGXState (0x02150E4C); they sit outside
  gx_vramcnt.o's span. Not SDK; should be dropped from symbols_sdk and left to game lanes.

## Next pass

Only the four pending rows remain in this territory: FX_SqrtAsync (if-conversion shape),
VEC_Normalize and VEC_Fx16Normalize (one scheduling residue, likely one fix closes both),
G2x_SetBGyAffine_ (register allocation). Unused permuter seeds: 12607 to 12699.
