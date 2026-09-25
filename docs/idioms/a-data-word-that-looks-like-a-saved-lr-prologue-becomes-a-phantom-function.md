# A high-entropy data blob whose first word looks like a saved-lr prologue becomes a phantom `func_`

summary: `disasm.py` auto-labels a `func_` whenever the bytes at a `.word`
boundary decode as a prologue that saves `lr`, so a certificate/string blob
at the end of an overlay whose first data word happens to encode
`push {..., lr}` is published as a real function and the worklist lists the
whole blob as one ~20 kB `open` extent; the tell is that nothing in the image
branches to or pools the address, and the "body" decodes to ASCII strings and
certificate DER.

Found in: `asm/overlays/ov009.s` (`func_021A3248`, 0x021A3248,
`func_021A2CEC`, 0x021A2CEC; overlay `ov009`)

`ov009` allocates `code_size 0x53100` and `ram_start 0x02155160`, so its
loaded image runs to `0x021A8260`. The last real function is
`func_021A1928`, which is ARM and ends at `0x021A1974`:

```
021A196C  00 00 a0 e3  mov r0, #0
021A1970  10 80 bd e8  pop {r4, pc}
021A1974  25 73 20 3d  ...  "%s = '%s'\0"
```

Everything after `0x021A1974` is data, but two words in that data decode as an
lr-saving Thumb prologue and are therefore emitted as function labels:

```
021A2CEC  4a b5  push {r1, r3, r6, lr}    <- actually GlobalSign cert data
021A3248  c2 b5  push {r1, r6, r7, lr}    <- actually "VeriSign ..." string data
```

`match.py show --addr 0x021A3248 --region ov009` duly reports
`5xxxx bytes, Thumb` and follows "branches" into the middle of an X.509
distinguished name; the extent it prints is not a function, it is the rest of
the overlay. `func_021A3248` ends with a bare `bx r0` that never restores the
`lr` it "pushed", and its body is the ASCII run
`"US, VeriSign, Inc., Class 3 Public Primary Certification Authority - G2, (c) 1998 VeriSign, Inc.,"`.

The decisive test is outside-reference fan-in, not the prologue:

```
grep -rn '\.word\s*0x021A3248' asm        # no hits: no literal pool names it
grep -rn 'func_021A3248' asm              # only the .global/.type/label lines
```

Zero `bl`/`blx` and zero pool words image-wide. A real function of a 20 kB
extent has callers; this has none because it is `const` rodata. The general
procedure:

1. If an `open` address shows zero `label`/`literal`/`sole-ref` witnesses after
   a full-image search, suspect the label itself.
2. Dump 32-64 bytes and look at them: a run of NUL-terminated printable ASCII,
   or repeated 4-byte `.word` records, is data. A certificate blob (DER with
   `0x30 0x82` SEQUENCE headers, `2a 86 48 86 f7 0d` OIDs, base64-ish
   randomness) is a dead giveaway.
3. Only after those two checks treat a prologue-shaped word as a function.
   Do not write C for it, and do not spend the packet budget on its "callees"
   (there are none: the decodes are literal-pool and branch bytes read out of
   text).
