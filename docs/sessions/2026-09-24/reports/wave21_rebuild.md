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
- `twl`: the first run left the key path as a placeholder, so the DSi
  region's bytes were skipped in the listing step. A second run at 405f67d
  with the real key file decrypted it (stream consumed exactly, 0x32DB4
  bytes -> extract/arm9i_dec.bin, 305 functions in the twl listing) and
  reproduced the same SHA-1 and figures. The check therefore covers the
  DSi region too.
- The single pending MATCH is src/pending/func_020863E0.c, as expected.

## g2d DoAffineTransforme_ (dd57986)

Commit dd57986 added 0x02067080 (closed by the online research lane) labelled
UNVERIFIED. The owner then ran `wave.py foldin` natively with the DSi key at
dd57986:

    [figures]  exact coverage 99.8986% (399900 / 400306 bytes, 4421 functions)
    [rom]      sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5
    FIGURES 99.90 99.90 4421

The ROM still matches the cartridge, so dd57986 is verified. The fold-in outputs
(coverage maps, worklist) were committed as 0acd895. One function is left
open: blink_palanm 0x0202E1F0, 2 bytes out.
