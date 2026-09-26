# Omitting an overlay hint can attest where naming the overlay cannot

summary: A data symbol in overlapping overlay bss is accepted by
`sole-ref/data` when the `symbols:` line carries no overlay token (the
function's own region then disambiguates), but is refused as "hint
contested" when the line explicitly names that same overlay.

Found in: src/matched/ov114_func_021C87FC.c (0x021C87FC)

The function loads the address `0x021D3D40`, which sits in bss shared by
several overlays.  Declaring it

```
 *   d_021D3D40   0x021D3D40  data  ov114  a4
```

gives

```
    0x021D3D40: the ov114 hint is contested (another overlay in the window
    starts an object there) and this function loads no overlay ov114 through
    an overlay_id site
```

and the verdict caps at `MATCH`.  Dropping the token, so the line reads

```
 *   d_021D3D40   0x021D3D40  data  a4
```

resolves the same site as `[sole-ref x1]` and the function reaches `EXACT`:
with no hint, the rule "the overlay the function under test itself lives
in, when its window holds the address" picks the overlay the whole file is
already in.

So for an overlay-resident function referencing a data address in its own
overlay's bss, do **not** add the `ovNNN` token.  The hint is only useful
when the symbol is deliberately in a *different* overlay than the one being
compiled.
