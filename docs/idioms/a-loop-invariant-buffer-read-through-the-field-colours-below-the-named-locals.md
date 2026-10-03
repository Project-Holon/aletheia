# A loop-invariant buffer read through the field colours below the named locals

summary: in a Thumb stream decoder, `q->buf[pos]` inside the loop (hoisted by
the compiler) takes a lower register than a named `buf` local. Named locals are
coloured after compiler temporaries, so the declaration order of the remaining
locals then sets the rest.

Found in: src/matched/ov/ov093_func_021EE830.c (0x021EE830)

The original keeps pos in r1, size in r2, buf in r3, the header byte in r4 and
count in r5. The draft with `u8 *buf = q->buf;` and locals declared
pos, count, size, buf gave a full register rotation (30 bytes).

What closed it:

- Read the buffer as `q->buf[pos]` in both places. The compiler hoists the
  load into the loop preheader as a temporary.
- Declare `count` first and `pos`, `size` last; assign `pos = 0; count = 0;
  size = q->n;` as statements, not initialisers (initialisers in a different
  order change the code).
- Put `pos++` directly after the byte load. With `pos++` after the field
  extraction, the `adds` and one `lsrs` swap (4 bytes).

Declaration order mattered here, unlike in the earlier note on this draft,
because the named-local set changed: with `buf` gone, only pos, size and count
compete for the colours above the temporaries.
