# tree_ov135_2 (ov135, roots of 256 bytes and up, biggest first)

## Trees closed (23 functions, about 7.5 KB, all EXACT/EXACT\*, each shard verified twice, second pass 0 rewritten)

- 021F5420 (860): a sprite-setup leaf. Every callee was already closed.
- 021FE338 (724, menu input root), with 021FE9B0, 021FF4D0\*, 021FEAE0 and 021FE9DC.
- 021F6FD4 (660, two-state trade step), with 021F7338 and 021F7374\*.
- 021F68A4 (656, box/party icon build), with 021F66F0, 021F67A8, 021F6DB4 and 021F6754 (the VBlank upload callback it installs at +0xEBC).
- Menu cursor handlers: 021F9CDC (528), 021FA514 (588) and 021F9A88 (552), with 021F9A1C (touch dispatch) and 021F9CB0.
- 021F9660\* (560, window redraw switch).
- 021FF6A4 (524), with 021FFC18.
- 021F49F8 (468, OBJ resource load).

\* marks EXACT\*. The only difference is trailing alignment padding.

Files: src/matched/func_<addr>.c and layout/matched/ov135/pkt_<addr>.json for each of the 23 addresses above. `manifest --check` is clean.

## Levers that closed functions (all already in the index, no new idiom file)

- Declaration order for stack slots and registers: 021F67A8, 021F68A4, 021F6754 and 021F49F8.
- Statement order inside the arms: 021F49F8.
- `switch` instead of an if-chain, so the compare chain comes out sorted: 021FE338.
- Source-order fall-through: 021F9CB0.
- The shared final `return -1`, reached through an `||` guard: 021F9CDC.
- Callee parameters declared u32 where the call site does not truncate (021F4FF4, 021F4EA0): 021F9CDC and 021FF6A4.
- `(u8)` cast on a u32 return: 021F49F8.
- Overlay-id symbols `ov067_id` and `ov195_id`, plus an `ov195` hint on d_02208C40: 021F6FD4. The hint is accepted because the function loads ov195.

The permuter was not used, and there are no near misses.

## Next lane (open roots of 256 bytes and up, biggest first)

- 021FCC40 (548). Its open callees: 021FC8CC (448), 021FCA8C, 021FCB54, 021FD08C, 021FD104, 021FD270, 021FD5F0, 021FD760, 021FD790 and 021FFD1C.
- 021FD924 (448). Its open callees: 021FDDA8 (340), 021FDF2C (400), 021FF384, 021F9890, 021F7F9C, 021F8010, 021F8098, 021F8154, 021FE118, 021FF474, 02200B34 and 02200BAC.
- Then 022010BC, 0220189C, 022005EC, 021F6E58, 021FAFF0, 021F9FF0, 021FA85C and 021FA394.

## Seeds / integrator

- No new unlabelled starts.
- The matched 021FE254 is declared `void`, but it returns func_02035C08's result, which 021FE338 uses. Likewise, 021F66C8 and 02202608 return their allocations. The callers' TUs declare the real returns.
- Stage these explicitly: the 23 source files and the 23 shards named above.
