Byte-correct but MATCH-capped sources.

Every concrete byte of these functions reproduces the original; the entry
is capped at MATCH because one or more relocation targets have no witness
outside the compared range (see the honesty rule in docs/MATCHING.md).
They are parked here, OUT of the manifest, until coverage growth or an
attestation extension supplies an outside witness. The manifest and the
build must contain EXACT entries only.

Being parked here is also what keeps the `matched` class honest: an entry
in the manifest was verified without ever consulting a file in this
directory, so a file that graduates depends only on entries that already
stood without it.

## The graduation path

Three things close a parked file, and they are tried in this order.

1. **A cut.** `python tools/match.py tu --src ... --suggest-split` reports
   which re-cuts of the range would give every relocation a witness outside
   it. Only useful when the witness exists and is merely inside the range.
2. **The `matched` class.** If the blocking target is covered by an EXACT
   manifest entry whose source is some other file, the site resolves with no
   cut and no second caller: our own byte-verified proof of that entry says
   what lives at the address. This is the one that moves with coverage, so a
   parked file is worth re-running after every wave. See "The matched class"
   in docs/MATCHING.md for why one-way dependence on an already-verified
   entry is not circular.
3. **A second caller, or a second reference to the object.** For a target
   nothing else in the image names, and for the private data tables the
   `matched` class deliberately does not cover, this is still the only way.

Re-verify a parked file with `match.py one` (or `tu` for a unit). When it
comes out EXACT:

* move it to `src/matched/`,
* put its header in the house format: `unit:` / `function:`, a bare
  `address:`, a `packet:` id, and `status: EXACT`,
* say in the header what closed it, not just what used to hold it open,
* write its shard with
  `python tools/match.py manifest --verify --shard pkt_XXXXXXXX`.

When it is still capped, update the header's evidence note with what was
tried and why it did not reach, and leave the file here. Nothing is ever
forced: a file only moves because a byte comparison came out EXACT.


Evidence tier: files here are DIFF-annotated analysis records, NOT byte-correct
sources. src/pending/ holds only byte-correct MATCH-capped sources; anything
short of that lives in docs/notes/ as .c.txt so no tool ever compiles it.
