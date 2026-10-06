# mwccdbg: look inside mwccarm while it compiles

`mwccdbg` runs the repo's CodeWarrior compiler (`tools/mwccarm/mwccarm/dsi/1.1p1/mwccarm.exe`)
under a small Win32 debugger written in Python (`dbg32.py`, ctypes only) and stops it at
known points in its register allocator, instruction scheduler, alias analysis and IRO
(front-end optimiser) passes. It prints what each phase decided and the data it decided
from. It can also change one decision at run time and show the result.

Use it when a near miss does not move with source changes and you need to know which
compiler decision makes the difference. The lanes of pass 6 (2026-10-06) closed
ov093 0x021D09E0, ov093 0x021D32E0, ov013 0x021AFABC, ov013 0x021AF494 and ov112 0x021F56BC
with it, and located the one-decision residue of ov013 0x021B3084.

## Requirements and setup

- Windows (the Win32 debug API drives the 32-bit compiler from 64-bit Python). No other
  debugger is needed.
- Python 3 with `capstone` (already needed by `tools/match.py`).
- The compiler build must be dsi/1.1p1. All addresses below are for that build. The tool
  checks the MD5 of the executable and warns when it differs.

The compile is the compile `match.py one` runs: compiler path, `BASE_FLAGS` and the SDK
include come from `tools/match.py`. Function, address, region, ISA, `-lang` and flags come
from the source header (`function:`, `address:`, `region:`, `isa:`, `lang:`, `flags:`).
`--func`, `--thumb`/`--arm`, `--lang`, `-O "<flags>"` and `--extra "<flags>"` override them.
Work files go to a temporary directory under `env.scratch_dir("mwccdbg")` and are deleted
after the run (`--keep` keeps them). The compiler file is never changed or copied:
breakpoints exist only in the running process.

After a compile, `regalloc`, `sched` and `edit` print the produced function and the
match.py verdict against the image (`EXACT`, `DIFF, n concrete byte(s) differ`, ...).

## Commands

All commands: `python tools/mwccdbg/mwccdbg.py <command> SRC.c [options]`.

| command | shows |
| --- | --- |
| `regalloc` | per colouring round: the pcode the allocator sees, every interference node (vreg, bound variable, spill cost, degree, flags, colour, neighbours), the simplify push order with sweeps and spill picks, the select pop order with the free colour set of each node, spill rounds. `--vregs` adds who created each GPR vreg, in order. `--json` saves the capture. |
| `regalloc-replay` | replays simplify and select on a capture (a `.json` or a fresh compile), says whether the model reproduces the stack and the colours, then tries one change: `--move V --after W` (pop V right after W) or `--renumber V1,V2,...` (give these vregs their sorted ids in this order: a declaration order change). Repeat `--renumber` for several groups. |
| `sched` | per scheduled block and pass: the DAG in program order (own latency, height, deadline, predecessors, successor edges with latency), the alias object of each memory operand, and for each cycle the ready list the pick routine saw and the node it chose. `--pass`, `--block`, `--json`. |
| `sched-replay` | without `--block`: checks the pick model on every block. With `--block`: replays one block, then the same block with `--add U:V:LAT`, `--remove U:V` or `--insert NAME:POS:OWN[:DESC]` (a new node before node POS; connect it with `--add`). |
| `alias` | per scheduled block: each instruction with its alias object, the unknown-memory set G, and every alias query the dependence builder asked, with its answer. `--window ON,OFF` instead logs the low-level predicate 0x574EF0 and its wrappers between two breakpoints. |
| `cse` | every CSE temp `@N` as IRO_CommonSubs names it: CSE run, IR node, expression. `--names LO-HI` instead lists every `@N` in the range with the return addresses on the stack. |
| `ir` | the IRO linear IR of the whole function as expression trees at the N-th hit of a pass entry (`--at cse --hit 2`) or any address. `--raw` prints the node words. |
| `passes` | the order of the IRO and backend passes with hit numbers, and the point names `ir --at` takes. |
| `edit` | compiles with one decision changed, prints which edits fired, the function and the verdict. See below. |
| `pe` | static look at mwccarm.exe: `secs`, `imports`, `strings REGEX`, `xref HEX` (code holding an immediate), `calls HEX` (call sites), `dis HEX [LEN]`. |

Block numbers are per function and per scheduler pass (`pre`, `post`), counted in the
order the scheduler visits the blocks; `sched`, `alias`, `sched-replay` and `edit` use the
same numbers. Node and instruction numbers are program order inside the block.

### edit

| option | effect |
| --- | --- |
| `--skip-sched pre\|post` | the scheduler pass does not run for the function |
| `--skip-block P:B` | block B of pass P stays in program order |
| `--set-ready P:B:N=C` | node N of block B gets ready cycle C after the DAG is built |
| `--force-alias P:B:I:J` | the alias query between instructions I and J answers 1 (a memory edge) |
| `--skip-call SITE[@H,..]` | steps over the 5-byte call at SITE with eax = 0 |
| `--skip-func ADDR[@H,..]` | the routine at ADDR returns 0 at once |
| `--jump FROM:TO[@H,..]` | execution continues at TO when FROM is reached |

`@H,..` limits an address edit to those hits (1-based, counted over the whole compile).
Example: the ov013 0x021B3084 residue is one pre-pass pick. Holding the d_021B3C50 pool
load back gives the original bytes:

    python tools/mwccdbg/mwccdbg.py edit src/pending/ov/ov013_func_021B3084.c --set-ready pre:16:9=8
    ...
    match.py verdict: EXACT

An edit result is evidence about the compiler, not a match. The source must still make
the compiler take the decision by itself.

## Measured rules

### Register allocator (Coloring.c)

- vreg numbering. Register-candidate locals (parameters, named locals, inline temps `@N`)
  get vregs before code generation, in the order of the function's local list. Code
  generation temps follow in emission order. Each inline copy's locals are consecutive in
  declaration order, and a later inline copy gets lower numbers.
- A local that is reused for several sequential values gets one vreg per live range; the
  extra ranges get late (temp-like) numbers.
- Simplify. K = 14 for ARM GPRs, 8 for Thumb. A sweep visits candidate vregs (virtual, not
  coalesced) in ascending number and pushes each node with degree < K; degree counts the
  precoloured neighbours, and a pair node removes 2. Sweeps repeat while they push. When a
  sweep pushes nothing, the spill pick takes the lowest cost/degree, scanning numbers in
  descending order with strict `<` (ties keep the highest number); nospill (0x80) and inf
  (0x400) nodes score as float max and half of it. Last pushed is coloured first, so inside
  one sweep a higher vreg is coloured earlier.
- Select. Each popped node takes the lowest free colour in the colour set. The set starts as
  {r0-r3, ip, lr} (Thumb: {r0-r3}). When nothing is free, the next callee-saved register
  (r4, r5, ...) is claimed and the node retries, so callee-saved numbers are handed out in
  pop order.
- A round can fail: spill code is inserted (constants and table addresses are
  rematerialised) and colouring restarts with new vregs. The output is the last round.
- The model in `regalloc.py` reproduces the stack and every colour of each capture it was
  checked on (ARM and Thumb). Pair and even rules (flags 0x200, 0x1000, 0x2000) are not
  modelled.

### Scheduler (Scheduler.c, SchedulerARM9.c)

- The driver 0x50D810 is called at 0x474976 (pass `pre`, before colouring, ARM at -O4 only)
  and at 0x474B5B (pass `post`, after peephole, final peephole and branch tail merge). Only
  switch-table optimisation runs after `post`. Thumb has only `post`.
- The driver skips blocks with flags & 0x11B (1 entry, 2 exit, 8 already scheduled, 0x10,
  0x100); a function of one block is not scheduled at all.
- The DAG is built by a backward walk. Volatile memory operations are chained with latency
  0; store to store alias edges have latency 1.
- Pick rule (checked on 165 blocks of 13 functions: 45 pre, 120 post, all reproduced):
  height = longest latency path to the block end, deadline = max height - height. Among
  ready nodes the pick prefers a node whose deadline is due, then the larger release count
  (successors for which it is the last predecessor), then the larger height, then in pass
  `pre` only the smaller desc field (node +0x12), then program order. A call holds the issue
  slot for its own latency.
- `#pragma scheduling off` gives a byte-identical object on this compiler.

### Alias analysis

- Alias objects are kind 0 (one object), 1 (object, offset, size; an overlap test) or 2
  (a set of AO indices). The predicate 0x574EF0 is a 3 x 3 table on the kinds: kind 0/1
  pairs alias only on the same object; kind 2 tests membership of the other AO's index.
- The analysis works on pcode and sees through casts: `((u32 *)p)[1]`, `(u8 *)p + 4` and
  `(u32)p + 4` all stay kind 1. Only a constant integer base gives kind 2.
- G (`[0x65C370]`) holds parameter pointees and globals. Spill stores get fresh kind 0 AOs
  after pointer analysis, outside every set, so a spilled register variable never aliases
  a pointer load.
- Word spills of narrow variables (u8, u16 locals stored as words) share one set; a narrow
  variable in that set gets memory edges an int variable does not.
- Taking the address of a local aggregate and passing it out turns a pointer parameter's
  pointee into the unknown object and puts the aggregate's AOs into G.
- Frame: spill slots are allocated from sp+0 upward; memory locals go above them.

### IRO and temps

- Spill slot order follows the creation order of temp objects: a lower `@N` gets a higher
  slot.
- IRO_CommonSubs can run more than once per function. Inside one run, a temp is named at
  the first reuse of the expression in program order.
- Expression propagation before the first CSE run removes a single-use index local; a
  multi-use local keeps its own temps.
- The backend local CSE (0x514630) does not call the alias predicates. It uses the memory
  operand's object: stores to the same object at other offsets do not kill a value; a call
  or a store not tied to an object does. Peephole forward (0x525C60) forwards values on its
  own as well.
- The pcode dump routine 0x5146E0 is a bare `ret`, so `#pragma dumpir` and the phase dumps
  write nothing. The hidden `opt_*` pragmas (ids 0x10000230..0x10000276) are accepted;
  those tried had no effect on the tested functions.

## Addresses and layouts (dsi/1.1p1, image base 0x400000)

### CodeGen

| address | what |
| --- | --- |
| 0x474557 | function name: eax = name node, text at +0xA (before IRO and the backend run) |
| 0x47474B..0x474D20 | backend pass list |
| 0x474976 / 0x474B5B | scheduler driver calls, pre and post |
| 0x47494C..0x474980 / 0x474B3A..0x474B60 | ranges `edit --skip-sched` jumps over |

### pcode

- Blocks: first block `*(0x65B038)`; block +0x00 next, +0x14 first instruction, +0x18 last
  instruction.
- Instruction: +0x00 next, +0x04 previous, +0x0C flags (2 load, 4 store, 0x8 call,
  0x80 volatile), +0x1C alias object, +0x28 opcode, +0x2A condition, +0x2C operand count,
  operands from +0x2E, 0xE bytes each.
- Operand: +0 kind, +1 register class. Kind 0 register: +2 effect (1 use, 2 def), +4
  register number (vN when >= the physical count). Other kinds: +2 s32 value, +6 object
  pointer. Kind 2 immediate, kind 4 memory or symbol, kind 6 branch label.
- Opcode names: table at 0x60DC04, 0x1C bytes per opcode, name pointer first.
- Object name: `*(obj + 8) + 0xA`.

### Register allocator

| address | what |
| --- | --- |
| 0x526D50 | colouring driver (per class; class byte at 0x6674A4) |
| 0x526D79 | per-class loop, class just stored |
| 0x526E2A | before the interference graph build, each round |
| 0x51AB90 | interference graph build |
| 0x526630 / 0x526645 | SimplifyGraph entry / eax = K |
| 0x5266F9, 0x52692C / 0x526869 | low-degree push (node in esi, edx) / spill pick push (esi) |
| 0x5269D0 | SelectColors, [esp+4] = stack head |
| 0x526A9E / 0x526AB8 | before a pick (ebx node, esi free mask) / after it |
| 0x526B34 | node marked spilled (ebx) |
| 0x526EA0 | round failed, spill code |
| 0x541370 / 0x50C420 | colour pick / claim next callee-saved register |
| 0x5B0D90 / 0x5B0420 | spill code / spill costs |

- Node array `*(0x65C274)`, 0x3C bytes per register, index = vreg: +0x00 stack link, +0x04
  object, +0x0C spill cost, +0x28 vreg, +0x2C colour (s16, -1 none), +0x2E flags (1
  spilled, 2 simplified, 4 coalesced, 0x80 nospill, 0x200 pair, 0x400 inf, 0x1000 even,
  0x2000 follows), +0x30 degree, +0x34 pair partner, +0x38 edge list.
- Edge: +0x04 next for the low end, +0x08 next for the high end, +0x0C low vreg, +0x10 high
  vreg.
- Counts: physical registers `int[class]` at 0x651158; registers including virtual
  `int[class]` at 0x65A820 (the vreg counter, watched by `--vregs`).

### Scheduler

| address | what |
| --- | --- |
| 0x50D810 | driver |
| 0x50D6A0 | per block, [esp+4] = block |
| 0x50CCD0 / 0x50D6E6 | node build / return, eax = node |
| 0x50D110 | dependences; 0x50D000 load, 0x50D060 store memory dependences |
| 0x50D72F | DAG complete |
| 0x50D4E0 | pick, [esp+4] = ready list, [esp+8] = cycle |
| 0x50D779 | pick returned, eax = chosen node (0: none this cycle) |

- Node: +0x00 next, +0x08 successor list, +0x0C instruction, +0x10 own latency, +0x12
  desc, +0x14 ready cycle, +0x16 deadline, +0x18 height, +0x1A predecessor count.
- Successor edge: +0x00 next, +0x04 target node, +0x08 latency (u16).

### Alias

| address | what |
| --- | --- |
| 0x575070 / 0x575085 | alias query between two instructions / return (al = result) |
| 0x574EF0 | AO predicate (wrappers 0x575090, 0x575100, 0x575120, 0x5751D0, 0x574340, 0x575180) |
| 0x65C370 | AO of the global unknown-memory set G |

- AO: +0x14 object, +0x18 offset, +0x1C size, +0x28 bit set (kind 2), +0x2C index, +0x30
  kind.

### IRO

| name | address | what |
| --- | --- | --- |
| looptop | 0x4FE76B | top of the IRO pass loop |
| copyprop | 0x5834B0 | copy propagation |
| exprprop | 0x583D20 | expression propagation |
| dclt | 0x569480 | IRO_DoCommonLoopTransformations (calls MIE at 0x5695FE) |
| mie | 0x59A670 | IRO_MoveInvariantExpressions |
| cse | 0x595500 | IRO_CommonSubs |
| csename | 0x595360 | CSE temp naming, one call per run; 0x595410: ebp = node, esi = block |
| sr | 0x5B40D0 | strength reduction |
| dotransf | 0x58CD00 | transformation driver |
| after-cse1 | 0x4FEBB5 | in the pass loop, right after the first CSE run |
| | 0x445730 | unique name generator; `@N` counter at 0x62586A |

- Blocks: first `*(0x65B094)`; block +0x18 first node, +0x1C last node, +0x38 next.
- Node (0x44 bytes): +0x00 kind (1 leaf, 2 unary, 3 binary), +0x01 ENode type, +0x1A CSE
  expression, +0x2A / +0x2E operands, +0x3E next. Leaf: ENode at +0x2A; INTCONST (0x34)
  value at ENode+0x1C, OBJREF (0x3B, printed `&x`) and other leaves object at ENode+0x18.
- Named ENode types: 0x04 `*` (indirection), 0x09 MUL, 0x0F ADD, 0x10 SUB, 0x11 SHL, 0x12
  SHR, 0x32 CAST. Others print as `opXX`.

Pass names other than the IRO_ ones come from the lanes' reading of the dump labels and
the call graph; treat them as labels, not as the compiler's own names.

## Limits

- Windows and dsi/1.1p1 only. Other builds have other addresses.
- The allocator model does not cover pair and even registers or the FPR class.
- `sched-replay` edits are graph edits on a model: an inserted node's own latency and desc
  are what you give. Check a promising graph with a real compile.
- Hit numbers (`ir --hit`, `edit ...@H`) count over the whole translation unit. Use
  `passes` to see which hits belong to which function.
- The IR printer names only the ENode types listed above.
- AO sets print the first 256 bits.
- `--vregs` uses the one hardware watchpoint (DR0).

## Files

- `mwccdbg.py`: command line.
- `common.py`: compile settings, temp directory, compiler checks, shared readers.
- `dbg32.py`: the debugger. `pe32.py`: static PE reader.
- `regalloc.py`, `scheduler.py`, `alias.py`, `iro.py` (CSE, IR), `passes.py`, `edit.py`:
  one module per capability.
- `tests/swap.c`: allocator check. `regalloc tools/mwccdbg/tests/swap.c --func swap2 --arm` gives
  t -> r4 and @11 -> r5, claimed in pop order, and the object has `add r4, r0, #1` /
  `add r5, r1, r1, lsl #1`.
