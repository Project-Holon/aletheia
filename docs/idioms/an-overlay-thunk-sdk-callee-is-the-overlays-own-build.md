# An overlay thunk's SDK callee can be the overlay's own build, not the catalogued address

summary: when an overlay SDK thunk's source object relocates its tail-call pool
word against a named SDK routine but the linked word lands on a `func_` label
elsewhere in the overlay, declare the extern at that overlay address (with
`thumb ovNNN`); the catalogued `symbols_sdk` address belongs to a different SDK
build and writing the canonical name resolves to the wrong word.

Found in: src/matched/ov093_func_021C4C40.c (0x021C4C40, CallbackForJpeg,
libaes/aes_util.o).

`CallbackForJpeg` is a 16-byte Thumb tail-call thunk. Its archive member
relocates the pool word against `OS_SignalEvent` (libos/os_event.o), whose
catalogued address is the ARM9 `0x02088398`. In the game image the same pool
word holds `0x021C4C51`:

```
021C4C40  adds r2, r0
021C4C42  adds r0, r1
021C4C44  ldr r3, [pc, #4]     ; pool at 021C4C4C = 0x021C4C51
021C4C46  adds r1, r2
021C4C48  bx r3
021C4C4C  .word 0x021C4C51     ; -> func_021C4C50 (thumb), same overlay
```

Naming the extern `OS_SignalEvent` makes `match.py one` resolve the site to
`0x02088398` and the entry comes out DIFF; the overlay statically linked its
own build of the signaller at `0x021C4C50` instead (the archive's Thumb
`OS_SignalEvent` is a different 2-argument body). The fix is to name the
extern after the overlay's own label and pin it in the header:

```
 * symbols:
 *   func_021C4C50  0x021C4C50  thumb  ov093
```

then `match.py one` reports `EXACT` with the site resolved by `label` (there is
an outside `bl` at 0x021C98D8). The explicit `symbols:` entry also supplies the
Thumb ISA that the bare `func_XXXXXXXX` name cannot infer (see
[a-pooled-tail-call-target-needs-a-thumb-region-symbols-hint.md](a-pooled-tail-call-target-needs-a-thumb-region-symbols-hint.md)):
without it the ABS32 word is written even and the disk/flash bytes differ.

The general rule: the archive member names the relocation, but the linked
overlay word is the ground truth. When the two disagree, follow the word to the
overlay listing and declare that address, not the SDK table's.
