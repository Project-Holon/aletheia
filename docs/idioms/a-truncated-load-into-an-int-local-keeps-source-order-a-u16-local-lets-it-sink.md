# A truncated field load into an int local keeps its source order; the same load into a u16 local can sink

summary: `x0 = (u16)k[1];` with `int x0` and `u16 x0; x0 = k[1];` emit the
same `ldr / lsls #16 / lsrs #16`, but with the u16 local mwccarm moved the
load below the later loads, re-dealt every spill slot and (in a smaller
frame) kept a 64-bit ratio in a register pair the original spills. When a
run of truncated loads comes out in the wrong order or the wrong slots, make
the locals `int` and cast at the load.

Found in: src/matched/ov/ov021_func_021BACA8.c (0x021BACA8),
src/matched/ov/ov021_func_021BA348.c (0x021BA348), both 2026-09-29, lane B9.

Both functions lerp two 16-bit angles and a scalar between two keyframe
records:

```c
int x0, y0, z0, y1, z1;          /* not u16 */
...
x0 = (u16)k0[1];
y0 = (u16)k0[2];
z0 = k0[3];
y1 = (u16)k1[2];
z1 = k1[3];
dx = (u16)k1[1] - x0;            /* then wrapped into +-0x8000 */
```

The original loads x0, y0, z0, y1, z1 in that order into descending stack
slots (0x1C, 0x18, 0x14, 0x10, 0xC in func_021BACA8). With the same body
written with `u16 x0, y0, y1`, the x0 load moved down next to the k1[1] load,
the slots came out as 8, 0x1C, 0x18, 0x14, 0xC (31 bytes wrong in
func_021BACA8), and in func_021BA348 the ratio from func_0207C768 stayed in a
register pair where the original spills it to [sp]/[sp+4] (239 bytes wrong,
4 bytes short). Changing only the local types to `int`, with the casts
written at the loads, made both EXACT; no other change was needed.

Related: [a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register.md](a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register.md)
(the width changes the colouring without changing an instruction); this is
the scheduling and spill-slot side of the same effect.
