# A loaded overlay descriptor needs the loader's id as its data hint

summary: A byte-correct call to `func_02031348` with a pooled overlay id and callback descriptor can cap at MATCH until the descriptor's `symbols:` line names the overlay selected by that id.

Found in: `src/matched/ov/ov170_func_021DF288.c`, `src/matched/ov/ov170_func_021DF38C.c`.

Both wrappers call the overlay loader with an absolute overlay-id symbol in r1 and a three-callback descriptor address in r2. The literal ids 0x83 and 0xC2 compile as `movs`; declaring `ov131_id` and `ov194_id` as extern byte arrays and passing their addresses restores the original pool loads. The `overlay_id` evidence class validates those ids at the call to `func_02031348`.

The descriptors are in the newly loaded overlays, rather than the caller's ov170. The ov131 listing at 0x021DC800 contains callback pointers 0x021D6325, 0x021D65BD, and 0x021D657D. The ov194 listing at 0x021F5580 contains 0x021F1441, 0x021F1745, and 0x021F168D. Their overlay-loading calls prove the intended regions.

The bare declarations `d_021DC800 0x021DC800 data a4` and `d_021F5580 0x021F5580 data a4` had no outside witness. Adding `ov131` and `ov194`, respectively, allowed `sole-ref` to validate the descriptors and gave EXACT. A resolving hint is justified here by the loader's id and the matching descriptor listing.
