# ldrsh with a register offset is a signedness tell

summary: Thumb `ldrsh` has no immediate-offset form, so one register-offset
load among immediate `ldrh`s is the only evidence that that field is `s16`.

Found in: `src/matched/unit_02008828.c` (0x020088B8)

Thumb `ldrsh` exists only in the register-offset form. So a signed halfword
field read out of a struct costs an extra `movs rN, #imm` and a register-offset
load, sitting in a function where every neighbouring read is a plain
immediate-offset `ldrh`:

```
movs r0, #0x98
ldrsh r0, [r2, r0]
```

In `sub_020088B8` that one instruction is the only evidence anywhere that the
field at +0x98 is `s16` and the ones on either side of it are not. The function
going the other way, `sub_02008860`, stores it with a plain `strh` and says
nothing about signedness at all.

The same tell applies to `ldrsb`, which is also register-offset only.
