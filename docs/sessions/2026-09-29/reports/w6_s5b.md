# Lane w6_s5b report (overlay SDK, 256 to 399 bytes, ov016 libdwcutil, the 8 rows w6_s5 did not reach)

Work from vendor objects via tools/sdkobj.py and tools/match.py only; no sdk/ source opened; no git commands.
8 rows assigned, all attempted: 6 verified, 2 near misses (no shard).

## Matched (6 functions, 1,992 B)

| region | address | bytes | vendor symbol | verdict |
|---|---|---|---|---|
| ov016 | 0x021CB978 | 296 | isEnd (scenesetsearch.o) | EXACT |
| ov016 | 0x021CC740 | 352 | procErase (scenesetselectap) | EXACT |
| ov016 | 0x021CC998 | 296 | DWCi_SceneSetSelectWay (scenesetselectwa) | EXACT |
| ov016 | 0x021CCEE4 | 308 | endScene2 (scenesetselectwa) | EXACT |
| ov016 | 0x021CCC84 | 380 | input (scenesetselectwa) | EXACT |
| ov016 | 0x021C7088 | 360 | DWCi_SceneSetEditAddress (sceneseteditaddr) | EXACT |

Files (src/matched/ov_sdk/): ov016_func_021CB978.c, ov016_func_021CC740.c, ov016_func_021CC998.c,
ov016_func_021CCEE4.c, ov016_func_021CCC84.c, ov016_func_021C7088.c

Shards (layout/matched/): ov016/pkt_ov016_021CB978, ov016/pkt_ov016_021CC740, ov016/pkt_ov016_021CC998,
ov016/pkt_ov016_021CCEE4, ov016/pkt_ov016_021CCC84, ov016/pkt_ov016_021C7088

Each verified with `manifest --verify --force --shard`, header status copied from the output, run twice.
No asm bodies, no name disagreements. Callees that are still open-sdk rows (DWCi_WINlInitEx, procError,
dispPush, dispPushClear, dispCaret, drawAddress, moveFocus, DWCi_FNTlFormBgEx, procInit) are labelled by
address with the ov016 token where same-overlay; a few of them resolve as sdk or label in the verifier.

## Near misses (2, pending, no shard)

- ov016 0x021CC0E8 button (288 B): DIFF, 2 lines. src/pending/ov_sdk/ov016_func_021CC0E8.c (header status
  says DIFF). Everything matches except the argument scheduling for `DWCi_WINlInitEx(0x46, 0, 1, MSG_IDX[lang], idx+1)`.
  Image order: `ldr r1,tbl; add ip,r5,#1; ldrsb r3,[r1,r0]; mov r2,r4 (dark); mov r0,#0x46; mov r1,#0; str ip`.
  Best draft (`lang = g_021DA724[DWCi_Language()];` as its own statement, then the call with `idx + 1`) gives
  `mov r2,r4` before `add ip` and the add after the ldrsb (2 lines). Tried about 14 forms: inline table index,
  lang local (int) before/after, num local before the Language call, `1 + idx`, `idx++`, dark as a local bool shared
  with the state store, pointer local to the table, extra terms on arg 3. Rest of the function is solved: unsigned
  compares come from using `g_021DE60C.FocusPos` (u8) directly in `>= 4` and `<= 2` (no idx local), case arms in
  image order (BTNlGet 0 arm first, then 1; Entry 0 arm, Entry 1 arm), tail `ChangeScene(endScene)` via break.
- ov016 0x021D5A58 DWCi_FNTlFormBgEx (360 B): DIFF, 15 lines, same residue as w5_s7 (`cmp r8,#1` hoist and the
  constant 1 in r1); pending draft src/pending/ov_sdk/ov016_func_021D5A58.c is w5_s7's, unchanged. About 8 new
  attempts, none repeating theirs: `f24 = f20 = 1` chained store, ternary scr, `lcd != 1` swapped arms, a
  `int sub = lcd == 1` local shared by both ifs (breaks the frame, 85 diffs), `lcd - 1 == 0`, and the scr call
  duplicated in an if/else around the whole func_02069078 call (the last is the same 15-line shape as the first).
  The image only needs separate g_021DAA74 and g_021DAA76 symbols once it matches.

## Levers found

- Cast-free struct copies with vendor tables: `struct FuncTab FUNC = g_021DB4C8;` (five function pointers)
  and `struct MsgTab MSG = g_021DA5E0;` (five bytes) reproduce the `ldm/stm` and the five ldrb/strb copies of
  the constant local arrays (DWCi_SceneSetEditAddress); local order FUNC, MSG, prm (reverse of DWARF).
- A local `p = g_021DE5E4` (declared between MSG and prm) assigned once after the indirect call, used by
  memcmp/state=3/MI_CpuFill8, with the state=0 store still through the global, reproduces the r7 pointer that
  survives the calls and the reload after MI_CpuFill8 (EditAddress; adds `r3` to the push list).
- Unsigned loop counter for a DWARF `int i` when the image compares with `blo` (input: `unsigned int i`),
  and unsigned u8 compares from using the byte global directly (button).
- Two literal spellings of the same array (g_021DA72C[].x and g_021DA72E[].x standing for C_CELL x and y)
  give the two literal-pool words (procErase); the struct with two cell arrays a[3], b[3] (obj+4, obj+0x10)
  gives `add r0,r0,r5,lsl#2; ldr r0,[r0,#0x10]`; cases in image order (WINlGet case 1 before case 0).
- Four R_FOCUS fields as four separate extern spellings (g_021DA858/5C/5A/5E) of a [4][4] rect table, each
  indexed `[DWCi_Flag(1)][Sel].v[0]` in the call arguments (SelectWay, input).

## Next pass

button and DWCi_FNTlFormBgEx remain (2 rows, 648 B). Both are single scheduling residues.
Helper scripts in scratchpad/w6b/ (gitignored).
