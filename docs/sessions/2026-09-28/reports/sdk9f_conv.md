# sdk9f_conv: DWCi_BACKUPlConvWifiInfo

| address | function (object) | bytes | verdict |
|---|---|---|---|
| 0x02058904 | DWCi_BACKUPlConvWifiInfo (dwc_backup.o) | 192 (listing extent 204) | EXACT* (was DIFF 62), filed |

## Files and shards

- Matched: `src/matched/arm9_sdk/func_02058904.c`
- Shard (new): `layout/matched/arm9/pkt_02058904.json`, status EXACT*, evidence `sole-ref self:0x02146A90`.
  `manifest --verify --force --shard arm9/pkt_02058904` then a plain `--verify`: both passes report
  EXACT* and 0 rewritten after the header status was copied.
- Pending deleted: `src/pending/arm9_sdk/func_02058904.c` (this session's draft, continued: the
  matched file keeps its struct overlay and statement order).
- Scratch: `scratchpad/sdk9f_conv/` (`gen.py` driver, variant files `a*` to `m*`).

No asm bodies. No permuter runs (seeds 14401 to 14499 unused).

## What closed it

Two changes to the 62-byte draft, both needed:

1. **`const DWCWiFiInfo *info`.** This is the existing idiom "const on a read-only source parameter
   settles a register tie" (MATCHING.md). Without const, mwcc assumes the byte stores through the
   Address overlay may clobber `*info`, and that constraint changes the schedule of the whole
   function: the Wifi literal load goes before the notAttestedId load, and the low tmp store
   goes before the `strb`. With const, the first block and the middle block match exactly
   (62 to 4 bytes). The DWARF prototype reads `struct tagDWCWiFiInfo *`, but this compiler's
   DWARF drops const: the same object's declaration of MI_CpuCopy8 reads `void * srcp`, and the
   SDK prototype is `const void *`. So the DWARF is consistent with const.
2. **Natural operand order of the Wifi[5] byte:**
   `((info->attestedUserId >> 40) & 7) | ((tmp & 0x1F) << 3)`. sdk9w3_dwc's swap (67 to 62)
   was only a gain without const. With const, the swapped order leaves a 4-byte register
   residue in the `and/and/orr`, and the natural order closes it. `(u32)` casts on both
   operands also verify EXACT*, but the plain form was kept. The `(u64)` cast on the tmp load is
   no longer needed and was dropped.

The "alias" hypothesis in the earlier reports pointed the wrong way. The object does not treat
the Wifi[5] store as aliasing `tmp`. What was missing was the proof that the stores do not alias
`*info`.

## Side findings (for the integrator and other lanes)

- **Raw relocation.** The second pool word of this function is `R_ARM_ABS32 .bss+0`, the
  section symbol, not `Address`. The only other `.bss+0` user in dwc_backup.o is
  DWCi_BACKUPlWriteChild, which reads it as the u32 `Address`. The Wifi stores at
  `[base,#9/#0xE/#0xF]` therefore really come off the Address/.bss base. The
  `{u32 Address; u8 Wifi[14];}` overlay (named Address) is the spelling that reproduces this.
  I read this from the archive's ELF relocation table, not from any source.
- **Scalar-address casts are opaque.** `((u8 *)&scalar_u32)[k]` on a u32 extern or static
  makes mwcc treat the store as a generic pointer store, which clobbers `*info` and
  address-taken locals. The same cast off a struct, an array or a struct member does not.
  Seen in variants b*, e_mix*, g*, i*.
- The DWARF drops const, so a prototype without const in `sdkobj.py` output does not rule out
  a const parameter. Try const on read-only pointer params whenever a near miss shows loads or
  stores reordered around unrelated stores.

## Next pass

Nothing left in this territory.
