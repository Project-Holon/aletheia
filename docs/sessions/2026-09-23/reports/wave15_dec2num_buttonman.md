# Wave 15: __dec2num and the button_man.c region residues

__dec2num 0x0209739C: DIFF, 721 -> 718 concrete bytes out (1520 of 1524, 1.1p1). Lever: `decimal *px = &x64;` declared in the refinement loop body and used for num2dec and the is_low less(); pre-loop registers now match the image (&feval r7, &dec r4, &guess r5, is_low r6, is_high r7). The residue is only the three invariants (&x64, found-block &dec, the `& 1` zero) placed at +0x2A0 instead of the preheader.
Diagnosis sharpened: not a loop barrier and not branch frequency (inserted loops, diamonds and exits all crossed); it is register pressure over +0x2A0..+0x3A4 resolved by allocator splitting. Three extra live values there (diagnostic volatile stores) reproduce the image's &dec split at the preheader; the image shows no such values, so their source is still unknown. Rejected: sign local, exponent/digit copies, first_guess not address-taken, fl pointer, chunk loop as inline helper (740; with u8 398 at 1524, compensation), u8 counter, do-while/goto chunk loop, early guess, block-scoped swap temp. All in docs/notes/pkt_0209739C.c.txt with the new best source.

EXACT 8 (7 under ../2.0/sp2 with FRONTEND-PINS.md rows, 1 under 1.1p1):
- 0x020637BC (register-held sentinel tell), 0x02061B2C (re-read tell; EXACT*), 0x02061BD0 and 0x02060FA4 (store/load interleave), 0x02067A60 (kept constants).
- 0x020611D4 NNS_FndFreeByStateToFrmHeap and 0x020606D0 NNSi_FndInitHeapHead: needed the NitroSystem fnd heap shape (0x24-byte NNSiFndHeapHead, GetFrmHeapHeadPtrFromHeapHead and SetOptForHeap as inlines) plus the pin.
- 0x02062F90 g2d animation-controller reset: library shape (IsForward/frame begin/end inlines) plus the pin.
- 0x020610E0 (1.1p1): the third parameter passes straight through in r2, and the sum is spelled size + mem.
Moved from src/pending (DIFF) to src/matched: 0x020637BC, 0x02061BD0.
MATCH 0.
DIFF 4, unchanged, notes appended: 0x0209739C (718), 0x02067080 (2: y-read ip/r6 tie, 7 more spellings), 0x020681E4 (10), 0x02051C88 (19: game code, 2.0 is worse).

Integrator: seed 0x02061B5C (ARM, src/matched/func_02061B5C.c, pkt_0206123C), the unlabelled follower that makes 0x02061B2C EXACT*. 0x020637BC was the chain blocker for 0x0204A9D0 and 0x0204AA94 (docs/notes/band_129_256_p1_lane3_verdicts.c.txt).
Shards verified twice: pkt_020637BC, pkt_02061B2C, pkt_020610E0, pkt_02060FA4, pkt_02061BD0, pkt_02067A60, pkt_020611D4, pkt_02062F90, pkt_020606D0 (all entries EXACT; 0x02061B2C EXACT*).
Also written: 8 rows in docs/FRONTEND-PINS.md, closure lines in the eight notes.
