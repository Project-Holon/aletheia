# A byte step added into a byte field is a narrow parameter

summary: A wide step used only in byte additions can make mwcc hoist a signed-byte truncation onto the incoming step. Declaring the step s8 removes that extra shift pair.

Found in: src/matched/ov/ov171_func_021DD51C.c (0x021DD51C), src/matched/ov/ov171_func_021DD558.c (0x021DD558), src/matched/ov/ov171_func_021DD5D4.c (0x021DD5D4).

The original adds the incoming step directly to a signed byte loaded from an object, then stores the byte and reloads it for bounds checks. In the looping form, a signed byte local receives the sum and is narrowed after each addition.

With `int step`, mwcc first emits `lsls #24; asrs #24` on the step, increasing each of these functions by four bytes. Changing only the parameter to `s8 step` produced EXACT in all three, without an entry truncation. The field or local still narrows the result of the addition as required.
