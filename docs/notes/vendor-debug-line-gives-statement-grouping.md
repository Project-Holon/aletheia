# A vendor archive member also carries .debug_line: use it for statement grouping

summary: every SDK archive member under `sdk/` has a `.debug_line` alongside the
`.debug_info` that `tools/sdkobj.py` already reads. It maps each instruction offset
to the *vendor's own* `file:line:column`, one sequence per function, so the original
statement boundaries and statement order are readable for any row whose object is
byte-identical to the image. Nothing in the tree reads it yet; a working parser is in
`scratch/laneU55/dwarf_line.py` (rows) and `scratch/laneU55/analyze.py`
(disassembly tagged with line numbers).

What it answers, and what it does not:

* It answers "is this instruction the load of statement 3 or of statement 5?" - which
  is the whole question for a scheduling/allocation residue. Rows tagged with the same
  line are one statement; a statement's instruction range tells you its extent even
  when the scheduler moved the instructions apart.
* It does not answer "why did this front end pick r1 and ours r0". Register churn from
  a genuinely different build stays unexplained, but you stop guessing at source shape:
  `DWCi_USBAPlEnd` 0x021D0CEC has `ldr r1,[r0,#0xb90]` / `cmp r1,#0` against our
  coalesced `ldr r0,...` / `cmp r0,#0` at +0094/+0098, and the line table shows the
  guard is a single one-line `if (MemUsb->task) DWCi_TSKlDeleteEx(0);` at L217 covering
  +0088..+00A4 exactly. There is no statement split to re-spell, so that residue is the
  front end, not the source.
* It corroborates `docs/idioms/dwarf-lists-locals-in-reverse-declaration-order.md`: the
  `variable` order sdkobj prints is the reverse of declaration order, so a declaration
  reorder that contradicts it is known wrong before you compile it (three 021C26xx /
  021D657C / 021C9A94 rewrites here changed nothing and were discarded on that basis).

CodeWarrior's DWARF-2 variant, the four things that cost the most time:

1. The header is `unit_length u32, version u16, header_length u32, min_inst u8,
   default_is_stmt u8, line_base u8, line_range u8, opcode_base u8`, then
   `opcode_base-1` standard-opcode-length bytes, then the dir list (NUL-terminated
   strings, empty string ends it), then the file list. **`line_base` is signed**
   (0xff = -1); reading it unsigned adds 256 to every special-opcode advance.
2. File entries are `name\0` followed by **three ULEB128s** (dir, mtime, length), not
   the 1+4+4 of some writers. A header with ~300 entries is normal.
3. The extended opcode is `0x00`, a **ULEB128** length, then sub-opcode(s). Do not scan
   the sub-opcode list for a zero byte: the operand that follows can be `0x00`
   (`00 05 02 <addr32>` is set_address with length 5, not length 0x0205). Walk
   sub-opcodes by their own operand sizes, bounded by the extended block end.
4. `advance_pc` (2) and `set_column` (5) take ULEB128; `advance_line` (3) takes
   **SLEB128** (`03 d9 00` is +89, not -39).

Anchoring it to a function: each sequence starts with `04 ac 02 00 05 02 <addr32>` and
the `<addr32>` is the only relocated word, so `.rel.debug_line` carries one relocation
per function. `r_info >> 8` is the symbol index; that symbol's `st_shndx` is the
function's own `.text` section (one section per function in these objects). Sequences
and relocations are in the same ascending order, so zip them.

Worked example: `scanFirst` (usbap.o) - `prm [fb+0]`, `j r6`, `i r11`, `info r7`, and
the image's `str r0,[sp]` at +0004 with `i` in r11 afterwards. Same phenomenon as
`SetFrameData` (atermset.o): the vendor front end homes an incoming parameter to its
frame slot, which none of the nine `tools/mwccarm` trees does for the same source, so
both rows are parked on the same residue rather than on a spelling.
