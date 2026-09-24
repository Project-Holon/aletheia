# An arithmetic loop-carried definition colours last, unless it goes through a copy

summary: when a pointer local takes the image's first callee-saved register everywhere except once it is re-defined in a loop by an arithmetic result (`m = base + (m - bias)`, even `m = m + 4`), 1.1p1 colours it after every other local whatever the declaration order. Compute the new value into a second local and end with a plain copy (`n = ...; m = n;`): the loop-carried definition is then a copy, and m is coloured in declaration order again.

Found in: src/matched/sub_0201DB20.c (0x0201DB20, printsys.c)

The image walks a chain of code maps, rebasing each `pNext` from a file
offset into the loaded block, with `m` in r4, `lo` in r5 and `hi` in r6.
The wave 15 source declared them in that order and still compiled `m` into
r6 (lo r4, hi r5): 15 bytes out.  Over waves 15 to 21 every declaration
order (120 of them), `m` as a parameter, the loop in an inline, a named
local for `pNext`, joined webs and the permuter all stayed at 15 or 18.

Cutting the function down found the cause.  With `m` declared first, `m`
takes r4 in every reduction until its loop-carried definition becomes an
arithmetic result; from then on it is coloured last:

    outer loop, `m = m->pNext; if (m == 0) return 0;`    m first
    outer loop with the rebase                           m LAST
    rebase replaced by `m = (u8 *)m + 4`                 m last
    rebase replaced by `m = (u8 *)m - f->unk68`          m last

Source that matches (dsi/1.1p1, EXACT*, the 2-byte pad in the extent):

    struct CMap *m, *n;
    u32 lo, hi;
    ...
        n = m->pNext;
        if (n != 0)
            n = (struct CMap *)(*(u8 **)((u8 *)f + 0x88) + ((u8 *)n - f->unk68));
        else
            return 0;
        m = n;

The copy keeps `n` a short web that dies at `m = n;`, so the rebase's
arithmetic belongs to `n` and `m`'s own loop-carried definition is a move,
which the allocator coalesces rather than treating as a new expensive web.
A named `n` holding only `pNext` with `m = rebase(n)` (the arithmetic still
defining `m`) does not help: it measured 15.  With the copy, the declaration
orders m/lo/hi/n, n/m/lo/hi and m/n/lo/hi are all EXACT*; m/hi/lo is 7 and
hi/lo/m is 15, so declaration order decides again.

Tell: a pointer (or index) that the image keeps in the lowest callee-saved
register across a loop, compiled into the last one under every declaration
order, where its value is recomputed each iteration by arithmetic rather
than loaded.  Reduce first: drop the arithmetic and see whether it comes
back to declaration order; if it does, route the arithmetic through a
second local and a copy.  Related: the dying-local idiom in
docs/idioms/a-result-computed-in-a-dying-local-takes-that-locals-register.md.
