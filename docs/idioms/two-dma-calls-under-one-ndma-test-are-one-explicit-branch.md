# Two DMA calls that share one NDMA test are one explicit branch, not two MI_Dma inlines

summary: when two DMA fills or copies in a row reload `GXi_DmaId` but test `dmaNo > 3` only once, with the statement between them duplicated into both arms, the source branched on the channel itself (`MI_NDmaFill` in one arm, `MIi_DmaFill32` in the other); two calls through the `MI_DmaFill32` inline test the channel twice and come out 20 bytes longer.

Found in: src/matched/GX_Init.c (0x0207D204)

The image, after `if (GXi_DmaId != GX_DMA_NOT_USE)`:

    cmp   r0, #3
    bls   dma
    ...   bl MI_NDmaFill        ; BG0CNT.., 0x60
    strh  r7, [r6, #0x6c]       ; MASTER_BRIGHT = 0
    ldr   r0, [r4, #4]          ; GXi_DmaId reloaded
    sub   r0, r0, #4            ; but not retested
    ...   bl MI_NDmaFill        ; DB_DISPCNT.., 0x70
    b     done
dma:
    ...   bl MIi_DmaFill32
    strh  r7, [r6, #0x6c]
    ...   bl MIi_DmaFill32      ; again no test

The reload after the first call shows mwcc did not know the value, so it
cannot have threaded a second `if (dmaNo > 3)` away. Writing

    if (GXi_DmaId > 3) {
        MI_NDmaFill(GXi_DmaId - 4, ...);
        reg_GX_MASTER_BRIGHT = 0;
        MI_NDmaFill(GXi_DmaId - 4, ...);
    } else {
        MIi_DmaFill32(GXi_DmaId, ..., 1);
        reg_GX_MASTER_BRIGHT = 0;
        MIi_DmaFill32(GXi_DmaId, ..., 1);
    }

is EXACT; the two-inline spelling compiles to 404 bytes against 384.
