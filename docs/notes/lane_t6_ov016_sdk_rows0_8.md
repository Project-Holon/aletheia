# Lane T6 - ov016 open SDK rows 0..8 (the 9 smallest)

Slice: `python scratch/a2/open_rows.py ov016 0 9`. Nine parked rows, 1,534 bytes.

| # | address | bytes | name (libdwcutil) | verdict |
|---|---------|-------|-------------------|---------|
| 0 | 0x021D3638 | 120 | DWCi_MOV_WH_Initialize | parked, 5 concrete bytes |
| 1 | 0x021D06A4 | 144 | taskEnd0 | parked, 12 concrete bytes |
| 2 | 0x021D0DE0 | 148 | cbWm | capped: EXACT at -O1 only |
| 3 | 0x021D04BC | 156 | taskBegin4 | parked, 12 concrete bytes |
| 4 | 0x021B97A8 | 164 | InitAtermApcNetwork | parked, 117 diffs, **pin corrected to ../2.0/sp1p2** |
| 5 | 0x021C78A0 | 192 | drawAddress | **EXACT, filed** |
| 6 | 0x021D15F0 | 192 | taskMove | parked, 184 vs 192 B |
| 7 | 0x021B9FE0 | 196 | SetFrameData | parked, 186 vs 196 B |
| 8 | 0x021BC820 | 204 | DWCi_ANIMElInitEx | parked, size-exact, 73 concrete bytes |

## Filed

`src/matched/ov_sdk/ov016_func_021C78A0.c` @ 0x021C78A0, 192 bytes, **EXACT**
(shard `layout/matched/ov016/pkt_ov016_021C78A0.json`, dsi/1.1p1, -O4,p, c99, arm).

The lever: `drawAddress` builds a local `AREA` that the object keeps
**memory-resident** (every field re-read from the stack frame per iteration).
Four field assignments written as statements get the struct promoted to
registers and the function compiles 28 bytes short (164 vs 192). What keeps it
in memory is an **aggregate initialiser**:

```c
AREA a = { g_021DA5E8.x, g_021DA5E8.y, 11, 16 };
int i;
unsigned short buf[2];

a.w = 11;          /* dead: 1.1p1 removes both stores, but their presence */
a.h = 16;          /* re-schedules the initialiser stores into x,y,w,h  */
```

The two following statements are dead and the compiler deletes them, but they
are required for EXACT: drop either and the row goes back to 142/150 concrete
diffs. Tested 16 other shapes (aggregate init alone, compound literal, partial
init, `volatile AREA`, declaration orders) - none of them equals.

## Parked, with the first divergence

Every row below was re-swept (nine pins x seven flag sets, `--extra` for row 0)
and no cell matches. A sweep is only reported here as a residue, not as a lever.

- **0x021D3638** - 5 B, first at +0068. Object `moveq r0,r5 / movne r0,r4`,
  ours `movne r5,r4 / mov r0,r5`. The select's result coalesces into the r5
  zero constant instead of landing in r0. 14 re-spellings; all the if/return and
  ternary forms flip the constant assignment to r4=0/r5=1, the `int r = 0; if
  (c) r = 1; return r;` family keeps the object's ordering but coalesces.

- **0x021D06A4 / 0x021D04BC** - 12 B each, same window at +0060/+0068. Object
  `ldr r0,[r4,#4] / str r2,[sp,#4] / ldr r0,[r0,#0x10] / sub r1,r2,#0x99`, ours
  `str r2,[sp,#4] / ldr r0,[r4,#4] / sub r1,r2,#0x99 / ldr r0,[r0,#0x10]`. Only
  the else arm's four-instruction schedule differs; the taken arm matches.

- **0x021D0DE0 (cbWm)** - the row that matches **only at -O1** (148 B EXACT in
  all nine pins; -O1 is excluded by project rules). At -O4,p it is 144 B with
  the `st != 0` arm if-converted (`moveq r0,#2 / strbeq`) where the object
  branches (`popne {r3,pc} / mov r0,#2 / strb / pop`). Five guard spellings
  (early return, store-then-return, nested braces, goto to one shared set-label,
  `volatile st`) all compile to the same predicated 144 B. Capped.

- **0x021B97A8 (InitAtermApcNetwork)** - **pin correction**: this is
  `atermset.o`, the same vendor object as SetFrameData (0x021B9FE0), which
  already pins `../2.0/sp1p2`. Under that pin the row goes from 188 B / 164
  concrete diffs (dsi/1.1p1) to **160 B / 117** (image 164 B). Two residues:
  (a) object keeps `maxap` in r6 and `t = maxap*0xd0` in r7, this build swaps
  them; (b) both `& -32` masks: object materialises -0x20 as
  `movs r1,#0x1f / adds r0,r1,#0 / subs r0,#0x3f` and uses `ands`, this build
  folds each to `movs r3,#0x1f / bics` - that fold is exactly the 4-byte size
  gap. Tried: four declaration orders, five mask spellings (incl.
  `0xffffffe0u`), an `int mask = -32;` local shared by both masks, `int t`
  mid-block, `unsigned int t` - all byte-identical at 160 B.

- **0x021D15F0 (taskMove)** - 184 vs 192 B. Object branches on the type test
  (`cmp r0,#5 / bne / ldr r1,[pc,A] / b / ldr r1,[pc,B]`); this build
  if-converts the function-pointer select (`movne r1,...`), and that branch is
  the missing 8 bytes. Object also keeps the 0 constant in r4 (live across the
  GetPosition call). Nine spellings of the select (fn-pointer local by ternary
  and by if/else both senses, `void *`/`unsigned long` with a cast at the call,
  leading default then one if, switch, call duplicated per arm) all re-fold to
  180 B.

- **0x021B9FE0 (SetFrameData)** - 186 vs 196 B. Object runs a real frame
  (`sub sp,#8`) spilling `id` to [sp,#4] and reloading `lpkey` from [sp,#0x20],
  and interleaves the eight ELEMENTHEADER byte stores with the FullLength
  SWAP16 chain; this build does the lpkey/copy branch first, needs no frame, and
  emits both SWAP16 chains after it. The extra live value forcing the object's
  spill is the structural gap.

- **0x021BC820 (DWCi_ANIMElInitEx)** - size-exact 204 B, 73 concrete diffs.
  First diff +0000: object `push {r4,r5,r6,lr} / mov r6,r0 (color) / mov r4,#0`,
  ours `push {r3,r4,r5,r6,r7,lr} / mov r4,r0 / mov r7,#0` - one register too
  many. Consequence: object reads `pal = g_021D9FF8[color]` early (into lr,
  right after the obj store) and this build sinks it past the w0 store; the
  early pal load is what frees the register. Tried: declaration swap, pal
  assigned before the obj call and right after the color store, no `o` local,
  `o` cached from the obj assignment - 73 to 133 diffs, size stays 204, all nine
  pins 73.

## Leads for the next lane on these rows

1. 0x021B97A8 proves the pin for `atermset.o` rows is `../2.0/sp1p2`, not
   dsi/1.1p1. Any other atermset.o row parked on 1.1p1 should be re-tested
   under that pin before its body is touched.
2. 0x021B97A8 and 0x021BC820 are both pure register-number permutations of a
   correct body (no structural difference) - permuter territory if the permuter
   can be pointed at them.
3. 0x021D15F0 and 0x021D0DE0 are both "the object branches where this build
   if-converts"; a shape that defeats if-conversion of a pointer select is the
   shared unlock.
