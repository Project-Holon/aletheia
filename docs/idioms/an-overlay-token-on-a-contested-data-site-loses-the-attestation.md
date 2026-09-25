# An explicit overlay token on a contested data site costs the attestation; drop it

summary: When a pool word names a data object inside an overlay, naming the
overlay on the `symbols:` line can turn a resolvable site into an unresolved
one, because a *hint* is refused as soon as a second overlapping overlay also
starts an object at the address.  Omitting the token lets the function's own
region fix the choice and the site resolves.

Found in: src/matched/func_021841C8.c (0x021841C8, ov168).

The function loads a base pointer from a pool word (`d_02184964`,
`ldr r4,[pc,...]`) and reads a byte `[base + i*0x24 + 0x20]` five times.  The
first spelling declared the object with its owner:

```
 *   d_02184964     0x02184964  data  ov168  a1
```

and `match.py one` reported

```
+0028 ABS32 d_02184964 -> unresolved: 02184964: the ov168 hint is contested
(another overlay in the window starts an object there) and this function loads
no overlay ov168 through an overlay_id site
```

0x02184964 is a `.word 0x00000000` data run in ov168, but ov219's listing also
starts a `pool_02184964` there.  `_hint_contested()` therefore rejects the
`ov168` token outright, and `sole-ref/self`'s contested path wants the function
to load that overlay through an `overlay_id` site, which it does not.  The site
stays wildcarded and the file caps at `MATCH`.

The fix is to **not** give a hint at all:

```
 *   d_02184964     0x02184964  data  a1
```

`attest_sole_ref_overlay_data()` then fixes the overlay from the region the
function under test lives in (`site_region`), the hint is `None`, `_hint_contested`
is false, and the site resolves as `sole-ref/data` -- `EXACT`.

This is the mirror image of the tail-call rule (a pooled `func_` target in an
overlapping window *needs* its owner token).  For a **data** target the two
situations want opposite spellings: add the token when the object start is
ambiguous and the function itself is the only witness; omit it when the token
would be contested and the function's own region can pick the object.
