# wave 19, lane anime_4 (19V)

## 0x02011688 (ica_anime.c): 14 -> 14 bytes out, DIFF

Lever tried: lane 19L's dead definition (a redundant initialiser or a use
that makes the remainder's web span the _u32_div_f call). 17 compiles,
hand only (no permuter):

- `u32 i = 0;` then `i = idx % n;`: ret form 50/14 or 52/27 (depends only on
  whether the assignment precedes `ret = 0`), two-return form 52/31.
- call result in a separate local, `i = q`: 52/27, 52/31.
- i live into the call as the divisor (`u32 i = n; i = idx % i;`): 52/27,
  52/31. The call is the modulus, so "modulus before the call" has no
  literal spelling.
- `unsigned long i = 0;`: 50/14 or 52/27, 52/31.
- `u32 i = idx;` non-constant dead init, `i = i;`: no change.
- idx %= n homing plus a dead-initialised i: 50/25 each.

Reading: on this straight-line function the dead definition is folded by
constant/copy propagation before colouring, so the remainder still
coalesces with the r1 return. Lever exhausted; best stays the big_three
50/14 source.

## Files written
- docs/notes/pkt_02011688.c.txt (dated wave 19 anime_4 section, every
  measurement, best-source marker unchanged)
- this report

## Shards verified
None (nothing filed).

## Seeds
None.

## Integrator
Nothing to integrate. No idiom file written (lever did not close anything).
