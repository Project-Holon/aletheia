# The last labelled function in an overlay has no follower, so show reports a 64-byte stub extent

summary: `match.py show` sizes a function by the next `func_` label;
when the function is the last labelled one in the overlay there is no next
label, `target_extent` returns nothing, and `show` silently falls back to
`0x40`.  The real extent runs to the literal pool (and its 4-byte
alignment nop), found by following the return path or passing `--size`.

Found in: src/matched/func_02202B20.c (0x02202B20)

`show` prints the extent it is going to disassemble in its first line:

```
ov135 02202B20..02202B60 (64 bytes, Thumb)
```

That `0x40` is not the function.  `cmd_show` calls
`target_extent(addr, region)`, and when that cannot find a next `func_`
label it returns `None`, at which point `show` substitutes a flat `0x40`
(`if size is None: size = 0x40` in `tools/match.py`).  A function in the
middle of an overlay always has a following label, so the fallback never
fires there; it fires exactly on the last labelled function of a region.
In ov135 that is `func_02202B20`, whose header advertises the range
`0x021F4580..0x02203F80` (0xFA00 bytes) and which sits at `0x02202B20`
with no `func_` label after it at all.

The true extent is 140 bytes (`0x02202B20..0x02202BAC`): the body ends at
the two-instruction epilogue, then a `mov r8, r8` alignment nop at
`+0x82`, then the function's own two-word literal pool at `+0x84`
(`0x3DC8`) and `+0x88` (`0x02203F74`).  Everything past the pool belongs
to the next data block, not to this function.

Two ways to see it:

```
python tools/match.py show --addr 0x02202B20 --region ov135 --size 0x84
```

or follow the return paths: both epilogues are `pop {r3, r4, r5, r6, r7,
pc}`, and the `ldr r0, [pc, ...]` near the tail names the pool.  `match.py
one` is not fooled: it sizes the original from the compiled function and
reported the full 140 bytes here, so only the writing aid under-reads.

The general rule: a `show` line whose end address is exactly
`start + 0x40` is the fallback, not a discovered extent.  Check for a
following `func_` label before trusting it, and pass `--size` when you
are working the last function of a region.
