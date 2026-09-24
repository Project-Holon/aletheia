# Wave 21 rebuild check

Commit a967cd6 was pushed labelled UNVERIFIED: its 11 new exact functions
had passed `match.py` shards, but no full ROM rebuild had been run.

It has now been verified. On a native Windows checkout at a796f5c, the owner ran
`delink.py`, `disasm.py` (arm9 --split, overlay --all, twl, ov230d) and
`wave.py foldin`:

    [pending re-verify]  verified 1 pending files (dry): {'MATCH': 1}
    [figures]            exact coverage 99.7297% (399224 / 400306 bytes, 4420 functions)
    [rom]                sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5
    FIGURES 99.73 99.73 4420

The rebuilt ROM hashes to the cartridge SHA-1, so wave 21 is verified. The
figures match the ones in the commit message.

Notes from the run:

- `ov230d`: 5 initialisers, 28 ranges decrypted and checked (0x1AA0 bytes).
  The `tools/ovcrypt.py` path works outside the session container.
- `twl`: the key path was left as a placeholder, so the DSi region's bytes
  were skipped in the listing step. None of the wave 21 functions lie in
  the twl region (0x02700000..), so this does not affect them, and the
  ROM hash still matched.
- The single pending MATCH is src/pending/func_020863E0.c, as expected.
