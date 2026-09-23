# Wave 13: NitroSystem residues lane

**Result: 10 EXACT and 2 DIFF.** One DIFF went from 12 bytes out to 2. The other stays at 10. Nothing is committed.

The NitroSystem source for rev 21c8fd0 (the g2d library, its includes and g2di_RendererMtxStack.hpp) is in `scratchpad/w13nns/`. That is outside the repo. The work files are in `scratchpad/w13n/`.

## EXACT (filed in src/matched, full headers, compiler ../2.0/sp2; sp2p2 gives the same bytes)
| addr | NNS function | file | shard | was |
|---|---|---|---|---|
| 0x02066620 | g2d_Renderer.c NNS_G2dRotZ | src/matched/func_02066620.c | pkt_02064B68 | 17 |
| 0x020664CC | g2d_Renderer.c NNS_G2dScale | src/matched/func_020664CC.c | pkt_02064B68 | 46 |
| 0x02064EDC | g2di_RendererMtxState.h NNSi_G2dMCMStoreCurrentMtxToMtxCache | src/matched/func_02064EDC.c | pkt_02064B68 | 28 |
| 0x02065DB4 | g2d_Renderer.c NNS_G2dDrawMultiCell | src/matched/func_02065DB4.c | pkt_02064B68 | 23 |
| 0x02063378 | g2d_OAM.c NNS_G2dEntryOamManagerAffine | src/matched/func_02063378.c | pkt_02063000 | 4 |
| 0x02063640 | g2d_OAM.c NNS_G2dResetOamManagerBuffer | src/matched/func_02063640.c | pkt_02063000 | 19 |
| 0x0206343C | g2d_OAM.c NNS_G2dApplyOamManagerToHW | src/matched/func_0206343C.c | pkt_02063000 | 99 |
| 0x02068430 | g2d_CharCanvas.c LetterChar | src/matched/func_02068430.c | pkt_020682DC | 119 |
| 0x02068670 | g2d_CharCanvas.c DrawGlyphLine | src/matched/func_02068670.c | pkt_020682DC | 238 |
| 0x02068808 | g2d_CharCanvas.c DrawGlyph1D | src/matched/func_02068808.c | pkt_020682DC | 168 |

- Eight of the ten matched on the first compile of the library body with its inlines. The earlier "mla destination wall" and "register rotation" residues were inline boundaries. The permuter cannot move an inline boundary.
- **New lever: which object a static belongs to.** The renderer rows needed the object layout to be modelled correctly.
  - g_02147B88 holds the renderer's file statics, pooled in one block:
    - currentMtxCachePos_ at +0, groupID_ at +2, bDonotUseSRTransform at +4, pCurrentInstance_ at +8, stackPos_ at +0xc
    - fxZStack_ at +0x10, mtxStateStack_ at +0x90, mtxStack_ at +0x190, mtxStackFor2DHW_ at +0x490, mtxCacheBuffer_ at +0x790
  - Declaring a member inside that object or as its own extern changes what the compiler may schedule across it:
    - RotZ and Scale need mtxStateStack_ inside the block.
    - StoreCurrentMtxToMtxCache needs mtxStateStack_ and mtxCacheBuffer_ as separate objects.
  - Each file keeps the declaration that matches, and its header says why.
- **All relocations resolve** by label, literal or data_table. None are wildcarded.
- **Front ends:** 1.1p1 is SIZE-off on every row except 0x02064EDC, which is EXACT under all three front ends.

## DIFF
- **0x02067080 DoAffineTransforme_: 12 → 2 bytes out**, 704/704.
  - Inside the adjust inline, the negated accumulator takes one product. The second product is added in the store expression: `dx = -(halfW<<12); dx += _00*halfW; pV->x += dx + _10*halfH;`, and the same for y.
  - x now matches byte for byte. The remaining 2 bytes are the register for the y read (the image puts _11 in r0 and y in r6).
  - The permuter was flat on the function body and on the inline (retargeted through a scratch copy): hill 800 + anneal 2000 each.
  - Appended to docs/notes/pkt_02066E30.c.txt with the marker. Permuter line: `best DIFF asm=10 bytes-out=2 size=704/704`.
- **0x020681E4 is still at 10 bytes out.** It is g2d_CharCanvas.c GetCharIndex1D, not g2d_Font.c.
  - The verbatim library body gives 18 bytes out. log_w and log_h land in each other's registers. Evaluating w first is the library's own order.
  - The permuter was flat at 18: hill 800 + anneal 900 on the body, plus hill on the GetMaxObjectSize and MATH_ILog2 inlines. This needed a scratch copy that swaps the clz asm for a placeholder.
  - The wave-11 source (10 bytes out) stays the best. I re-verified it and appended it to docs/notes/pkt_02067FE4.c.txt. Permuter line: `best DIFF asm=50 bytes-out=10 size=248/248`.

## Identifications (in the cluster headers)
- **cluster_02064B68.h:**
  - Full g2d_Renderer.c map of the pooled statics block.
  - g_020A81F8 (.data) = { firstSRTransformedMtxIdx_, currenVramTransferHandle_, mtxI_ }.
  - g_02148718 = mcRenderState_.
  - Callee names: MtxConcat32, PushMtx, PopMtx, Translate, FX_Inv, the OamSoftEmu auto-Z calls, DrawCellAnimationImpl_, DrawNode_.
- **cluster_02063000.h:**
  - Bank = OamCache, g_02146BC8 = oamCache_[3], g_02146BC4 = numRegisterdInstance_.
  - g_020A84C0 = GXi_DmaId. GX_GetDefaultDMA clamps values above 3 to GX_DMA_NOT_USE.
  - g_020A81E4 = funcTbl. DMA and cache callee names.
- **cluster_020682DC.h:** the whole range is g2d_CharCanvas.c:
  - 020682DC OBJSizeToShape, 020682F8 ClearChar, 430 LetterChar, 670 DrawGlyphLine, 808 DrawGlyph1D
  - A18 ClearContinuous, A68 ClearLine, AE8 ClearAreaLine, C84 ClearArea1D
  - 020681E4 GetCharIndex1D, 02069BA0 NNSi_G2dBitReaderRead
  - Surface = NNSG2dCharCanvas, Blit = LC_INFO
- **cluster_02066740.h and cluster_02067FE4.h:** wave-13 addenda.

Closing sections are appended to the notes: pkt_02064B68, pkt_02063078, pkt_020682F8, pkt_02068808.

## Gates
- `manifest --verify --shard pkt_02064B68`: 20 entries, all EXACT.
- `manifest --verify --shard pkt_02063000`: 7 entries, all EXACT.
- `manifest --verify --shard pkt_020682DC`: 3 entries, all EXACT. This shard file is new.

## Integrator: seed
None (no unlabelled leaves found).

## Other
- The permuter needs a small change: allow mutating an inline (a MUTFUNC-style option) and round-trip `asm {}` blocks. I did both in a scratch copy (`w13n/perm2.py`); tools/ is untouched.
- One anneal (02067080 inline) ran past the 5-minute limit and went to the background, and one (020681E4) was killed.
- The untracked files in src/matched outside these three packets are not mine.
