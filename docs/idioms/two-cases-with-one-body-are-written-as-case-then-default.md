# Two case labels that assign the same value are one arm with the default fallen into

summary: when the image's compare chain has one `cmp` per distinct case value
but only one block for several of them, the C has the extra label written as a
fall-through into `default:`; giving the two arms their own identical
assignment instead leaves the second one inline in the chain and adds an
unconditional branch past it.

Found in: `src/matched/ov_sdk/ov172_func_021C2B74.c` (0x021C2B74,
SSP_StartJpegEncoder, jpegenc.o)

`option & 0x104` picks one of two colour converters, and the image dispatches
with two compares and two blocks:

```asm
021C2BC4  cmp  r0, #4
021C2BC8  beq  0x021c2bd8        /* <- the shared block, below the chain */
021C2BCC  cmp  r0, #0x100
021C2BD0  ldreq r8, [pc, #0xfc]  /* the 0x100 arm, inline in the chain */
021C2BD4  beq  0x021c2bdc
021C2BD8  ldr  r8, [pc, #0xf8]   /* case 4 and default, one block */
021C2BDC  cmp  sl, #0            /* the join */
```

The two arms that assign the same function, written as two blocks:

```c
    switch (option & 0x104) {
    case 0x100: convFunc = func_021C2050; break;
    case 4:     convFunc = func_021C1F04; break;
    default:    convFunc = func_021C1F04; break;
    }
```

compile to a *four*-instruction tail and one word more of function: this
compiler does not merge the two identical arms, so it predicates the default
into the chain next to the `0x100` arm and lays `case 4` out as a block of its
own, which then needs a branch over the default's load.

```asm
        beq  <case-4 block>
        cmp  r0, #0x100
        ldreq r8, [pc, #0xfc]
        beq  <join>
        ldrne r8, [pc, ...]      /* the default, inline in the chain */
        b    <join>
<case-4 block>
        ldr  r8, [pc, #0xf8]
<join>
```

Falling the label through into `default:` gives the image's two blocks and its
chain exactly:

```c
    switch (option & 0x104) {
    case 0x100: convFunc = func_021C2050; break;
    case 4:
    default:    convFunc = func_021C1F04; break;
    }
```

This is the same finding as
`docs/idioms/a-switch-compare-chain-is-sorted-but-the-blocks-are-source-order.md`
read from the other side. There, the compare order is sorted and only the block
addresses carry the source order; here the *block count* is the evidence, and it
is the count of labels sharing a body, not the number of `case` keywords. A
switch that compares against N values and has N-1 bodies was written with a
fallen-through label, and the compare chain is still sorted, so a diff that is
one instruction short at the dispatch and one word long overall is this and not
a mis-spelled arm.
