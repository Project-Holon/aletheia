# tree_ov135 (ov135, then ov208)

## Trees

- ov135: only one root is 1024 B or larger. Root 0x021F9260 (1024 B, a 7-case window-layout switch) has no open callees. It came out EXACT\* on the first draft. The five rodata tables resolve by sole-ref. ov135 still has 313 open functions below 1024 B.
- ov208: root 0x021C6E98 (1456 B, soft-float). The tree has about 40 open functions once pool-word code pointers are counted. 30 of them are closed. The root itself is not attempted.

## Filed EXACT/EXACT\* (31, each shard verified twice, second pass 0 rewritten)

- ov135: 021F9260.
- ov208: 021BD330, 021BD360, 021BD3CC, 021BD404, 021BD444, 021BD574, 021BDBA0, 021BDBAC, 021BDBEC, 021BDC48, 021BE128, 021BE170, 021BE82C, 021BE920, 021BE9CC, 021C47C4, 021C4B60, 021C4E54, 021C4EAC, 021C4F30, 021C50F8, 021C535C, 021C57A4, 021C68D4, 021C6A10, 021C6AFC, 021C6D6C, 021C6E30, 021C7534, 021C7FF8.

Shards are pkt_ov135_021F9260 and pkt_ov208_<addr>. `manifest --check` is clean.

## Levers that closed functions

- Integer address arithmetic for the element address (021BD404, new idiom file).
- u16 truncation happening at the call instead of in the callee (021BD574, 021BD444). 021BD444 declares the u16 heap parameter of 021BD574 as u32.
- Writing the `show` flag again in the case 0 arm keeps its compare live (021C6A10).
- Writing `p + 0x148 + idx * 16` stops the base+offset address from being kept in a register (021C47C4).
- The initialised table becomes a struct copy from an extern const (021BE920).
- FX_F32_TO_FX32 with the runtime names _fgr and _ffix (021C7FF8).

## Near misses (src/pending, notes in docs/notes/pkt_ov208_*.c.txt)

- 021BD634: DIFF, 8 bytes, a scheduling residue. It blocks 021BD148 (its only caller).
- 021C4D68: DIFF, 3 bytes. The image converts the constant 0x11 at run time.
- 021C5CF0: DIFF, 19 bytes, register rotation around the `% 2`.

## Next lane

021C6E98 (the root), 021C5F34 (808), 021C7D80 (244), 021BD148 (after 021BD634), 021BDD98 (528), 021BE3C4 (280), 021BE504 (380), 021BDCF8, 021BDAAC. The three near misses above. The parent of the root is 021C3D3C (1372). Other ov208 roots: 021C4298, 021C625C, 021C7860, 021BF9B0.

## Seeds / integrator

- 0x021BD360 is labelled ARM in the listing but it is Thumb (the pool word 0x021BD361 sits at 0x021BDBA8). It is now EXACT as Thumb.
- Unlabelled starts filed EXACT: 0x021BDBAC (thunk after 021BDBA0) and 0x021BD360.
- Still unlabelled: 0x021BEA00 (after 021BE9CC); 0x021BE840, 0x021BE844, 0x021BE854 and 0x021BE864 (after 021BE82C); 0x021BDAD0 and 0x021BDAD4 (after 021BDAAC).
- The old pending ov208_func_021BD404.c (DIFF from wave 9) is now matched. Its function is renamed ov208_func_021BD404.
- Permuter seeds used: 8201, 8202.
