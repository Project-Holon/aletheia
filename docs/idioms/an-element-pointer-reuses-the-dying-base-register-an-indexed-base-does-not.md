# An element pointer reuses the dying base register; an indexed base does not

summary: two stores into one array element through the element's address
(`e = &g->arr[k]; e->a = ..; e->b = ..;`, or `*(u32 *)&b[k]`) compile the
base add in place and put the stored values in dying temporaries' registers;
the same stores as member accesses on an indexed base (`b[k].a = ..; b[k].b =
..;`) give the same instructions but three fresh registers and a wider push.

Found in: src/matched/func_0204E914.c (0x0204E914)

The image (ARM, 1.1p1 -O4,p), inner loop of a 4 x 3 OAM grid builder:

    ldr   r8, [r6]              ; g
    add   r8, r8, #0xc          ; &g->oam[0], in place
    orr   r7, lr, r7, lsr #7    ; attr01 into the dying lsl temporary
    add   r4, r4, r0, lsl #5    ; attr2 into the dying x/8 register
    str   r7, [r8, ip, lsl #3]  ; oam[k].attr01
    add   r7, r8, ip, lsl #3
    orr   r4, r4, #0xf000
    strh  r4, [r7, #4]          ; oam[k].attr2

`oam = g->oam; oam[k].f.attr01 = ...; oam[k].f.attr2 = ...;` produces the
same eight instructions with `add sb, r8, #0xc`, attr01 in r8 and attr2 in
r7, so the function pushes r3 and sb as well (15 bytes out after every
declaration order was tried). Writing `oam = &g->oam[k]; oam->f.attr01 =
...; oam->f.attr2 = ...;` (or `g->oam + k`) is EXACT: the addressing is
still scaled-register, the difference is only in how the allocator colours
the base and the two values. Also EXACT: `*(u32 *)&oam[k]` /
`((u16 *)&oam[k])[2]` stores over an indexed base, so the lever is the
address-of on the element, not the arrow. Not EXACT: `oam[k].w[0]` for the
first store (15).

When an allocator residue is confined to a loop that writes several fields of
one indexed element, try the element pointer before declaration orders.
