# Wave 11: bg_sys.c and g3d_system.c lane

Result: **7 exact** (6 EXACT, 1 EXACT*), all dsi/1.1p1, ARM. Nothing committed.

## Filed to src/matched (shards checked with manifest --verify)

| address | function | bytes | shard | verdict | what closed it |
|---|---|---|---|---|---|
| 0x0203FA08 | func_0203FA08 | 228+4 | pkt_0203FA08 | EXACT | arena base picked into a local before the direction test; `f = (size % t != 0)`; stride `t` is an **int** local (the permuter's `type:l(t:u32->int)`) |
| 0x02040618 | sub_02040618 | 464 | pkt_02040618 | EXACT* | `func_0203D814(x, y)` takes the scroll pair; scrollX is read before scrollY |
| 0x020426A0 | func_020426A0 | 584 | pkt_020426A0 (new shard) | EXACT | same declarations as 020428E8; EXACT on the first compile |
| 0x020428E8 | func_020428E8 | 572 | pkt_020428E8 | EXACT | written from scratch; **ch, sw, sh are u8 stack params** even though the image reads each with a full `ldr`; `func_02040F84(u8,u8,u8,u8)`; `u8 w, h;` |
| 0x02042B24 | func_02042B24 | 520 | pkt_02042B24 | EXACT | same declarations, plus `u8 y, x;`; the source row in mode 0 is the unwrapped `sy + y` |
| 0x02046440 | func_02046440 | 796+44 | pkt_02046440 | EXACT | written from scratch (the old note had it sized out); the stack buffers are declared s32, s36, r; the **heap param is s16** (permuter `type:p(heap:u16->s16)`) |
| 0x02046858 | func_02046858 | 572 | pkt_02046858 | EXACT | `u32 *hw = g_02148B4C;` before the dispatch, which puts it in r4 and pushes {r4, lr}; +0x38 picks between two calls per mode (0x1000 when zero); every arm returns on its own |

Each file's header explains what closed it.

## Integrator: seed

- `arm9 0x020407E8 arm`: the unlabelled follower of sub_02040618 (the source of the EXACT*). It is the leaf sub_020407E8, already EXACT in unit_020407E8.c. Its sibling leaf is at `arm9 0x02040804 arm`. Evidence: the `bx lr` at 0x020407FC and the pool word at 0x02040800 end the previous leaf.

## Left open (DIFF, appended to the existing notes)

- **0x02041FF4**: written from scratch. Now 548/548 with **42 bytes out**. Before this wave there was no recoverable source; the last recorded compile was 76 bytes short. What's left is one rotation of the callee-saved registers. Settled this wave:
  - a shared `fail:` exit;
  - an inverted `mode != 1` test, so the short arm gets if-converted;
  - func_02043130's first parameter is u16;
  - the sub-tile coordinates are new `u8 px` / `u16 py` locals.
  - Note: docs/notes/pkt_02041FF4.c.txt
- **0x0203FCA0** (1860 against 1876): the cross-jump persists. Neither a goto dispatch chain nor inlining the SDK G2 setters changes a single byte. A permuter run reached 1876 bytes, but only by putting dead statements between case labels, so I rejected it.
- **0x020433E0** (6 bytes): tried SDK-style inline OBJ-mode setters (29, 6, or 9 bytes out) and sp2 (6). The allocation cap stands.
- **0x02047564** (11 bytes): rewritten in readable C with real struct types, still 11. The residue is only the register that holds the 0x59D1 tag. The note lists every lever tried.
- **0x020479D8** (22 bytes, unchanged): an inline SetViews gives 30 bytes. Swept every available compiler: none beats 1.1p1, so the push list one register too wide is not a compiler-pin tell here.
- **0x02040EC0**: not work. Its bytes are already covered by unit_02040E78.c (EXACT, as sub_02040EBC). `src/pending/func_02040EC0.c` is a stale park of the same bytes that the integrator may want to remove.

## Family headers updated

- **docs/families/bg_sys.h**: the three tile-rect copiers' settled prototype. Includes the general rule "a u8 stack argument is read with `ldr`, don't infer u32" and func_02040F84's u8 w/h at the call site. Also the func_0203FA08 facts, the second-caller proof for func_0203D814, and func_02043130 u16 (best evidence).
- **docs/families/g3d_system.h**: the arities of func_0207C408 (7 args), func_0207C1D0 and func_0207C554 (8 args), with g_02148B54 as the last argument, and the `hw` local rule. Also the constructor's 7-parameter prototype (s16 heap), the context fields it fixes, the SDK callee names and the data sources.

## Lessons, for the brief

1. Narrow stack parameters (u8 read with `ldr`) and signed narrow ones (s16 heap) came up four times this wave. When the prologue's parameter-home order or a reload-versus-hold choice is the residue, try them first.
2. A register-held pointer to a hardware block (`hw`) that lives in a callee-saved register across calls has to be a named local taken before the calls.
3. Sibling functions sharing one prototype fall together: once 020428E8 closed, 020426A0 was EXACT on the first compile and 02042B24 in three.
