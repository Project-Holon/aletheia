# A self-move after a call is an add of a zero-valued local

summary: Adding a local that holds zero to a call result can survive register coalescing as a self-move; a literal addition of zero folds away before code generation.

Seen in ov021 func_02191830 (Thumb, -O4,p). The original keeps one
`adds r0, r0, #0` right after a call's result arrives in r0, while a sibling
value computed as `call() + 2` has none.

```c
u32 mx = 2, my = 0;
u32 tw = func_0201D304(a, b, 0) + mx;
u32 th = func_0201D42C(a, b) + my;   /* adds r0, r0, #0 */
```

The add of a local holding 0 survives register coalescing as an add and is
only folded to a plain move afterwards, so it is emitted as a self-move.
A literal `+ 0` (or `| 0`, `* 1`, `<< 0`) folds early and leaves nothing;
extra copies, chained assignments, retyped locals and inline helpers are all
coalesced away. When an original has an unexplained `adds rX, rX, #0` on a
fresh value, look for a margin, offset or padding term that is a zero-valued
local (often one of a symmetric pair whose other member is non-zero).
