# A store moved below the table loads recolours the values it computes

summary: When the schedule hoists table loads above a computed store regardless
of source order, the store's source position still decides the colouring order
of its operands; moving it below the loads can rotate three registers into place.

Found in: src/matched/func_0204EEC8.c (0x0204EEC8)

The image computes `sb = (fmt & 0x70) >> 4`, `sb + 3` and the constant 1 for
`dst->f04 = 1 << (sb + 3)` in ip / lr / r5, then loads three table words.
With the f04 store written first in the source, the instruction stream is the
same but the three values colour lr / r5 / ip (14 bytes out). Earlier sweeps of
all 720 orders of the other six stores kept f04 first and found nothing;
declaration position of named `sb3` / `one` locals and their use counts were
all inert.

Writing `dst->f04 = ...` after the three table stores (f14, f18, f1c) closes
it: the schedule still emits the shift first, but the operands now colour as
the image. Any position after the last table store works; positions before it
do not. When a store sweep finds a floor, sweep the position of the store you
held fixed as well.
