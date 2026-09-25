# A call to a function nested in a unit still needs an explicit symbols line

summary: match.py's name lookup (`matched_symbols()`) indexes only an entry's
own name and address, never the nested `functions` list a `game_unit` entry
carries, so `func_XXXXXXXX`-named calls to a unit member fail to resolve; the
fix is an explicit `symbols:` line pinning the member at its address.

Found in: src/matched/ov096_func_021893DC.c (0x021893DC), and
src/matched/ov098_unit_021B6910.c (0x021B6910)

A `game_unit` manifest entry records its covered addresses twice: as the unit's
own `address`, and as the `functions` list of member names. The byte comparison
pins all of them, so a member is evidence of the same strength as a standalone
entry — `matched_index()` even spreads each member address into the per-address
map so `attest_matched()` can use it as a witness.

What is not spread the same way is the *name*: `matched_symbols()` builds
`{entry name -> (address, thumb)}` and ignores `functions` entirely. So for a
call spelled with the address-bearing convention,

```c
extern int func_021B6140(int);   /* member of unit_021B613C, EXACT */
...
func_021B6140(b);
```

`symbol_address()` matches `_ADDR_NAME_RE`, finds no label for the member
(unlabelled leaf, or the label is only in the unit's own listing), and falls
back through `sdk_symbols()` and `matched_symbols()` — both of which answer
`None` because neither indexes the nested list. The site stays wildcarded and
the function caps at `MATCH` even though the target is proven `EXACT` a few
files away.

The cure is to spell the extern so the `decls` (first) branch of
`symbol_address()` fires: put the member on its own `symbols:` line with its
address and ISA.

```c
/*
 * symbols:
 *   func_021B6140  0x021B6140  thumb  ov098
 */
```

Then `attest()` resolves the site through the `matched` class (or `label`, if
an outside branch exists) and the function reaches `EXACT`. Note the ISA must
be right: a wrong tag raises the usual ISA-conflict diagnostic rather than
silently mismatching.

Observed in the ov096/ov112/ov098 clusters that call `func_0201134C` (member of
`unit_02011330`) or `func_021B6140` (member of `unit_021B613C`): each such call
site is the only blocker between the caller and `EXACT`.
