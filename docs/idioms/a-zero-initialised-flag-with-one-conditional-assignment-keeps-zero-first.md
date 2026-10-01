# A zero-initialised local flag with one conditional assignment keeps zero first

summary: `int flag = 0; if (field) flag = 1;` emits `movs #0; cmp; beq; movs #1` in these Thumb callers; `int flag = field != 0;` emits the opposite one-first materialisation and differs by three bytes.

Found in: src/matched/ov/ov206_func_021BB184.c (0x021BB184), src/matched/ov/ov206_func_021BB23C.c (0x021BB23C)

Both callers derive a wide flag from the word at object offset 0x1c and keep it across calls. Under dsi/1.1p1 -O4,p the relational initializer gives `movs rN,#1; cmp r0,#0; bne join; movs rN,#0`. Initializing the local to zero and setting it to one only in the nonzero arm gives the image's `movs rN,#0; cmp r0,#0; beq join; movs rN,#1`, with every other instruction unchanged. The complete matching logs are Wave31 S21 021BB184-one-3.log and 021BB23C-one-2.log; the relational forms are their one-1 logs.
