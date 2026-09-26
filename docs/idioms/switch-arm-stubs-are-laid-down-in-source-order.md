# Switch arm stubs are laid down in source order, not case order

summary: when several case labels share one body, mwcc emits each arm at its
source position and tail-merges the duplicates into a `b` stub to the last
copy, so the arm addresses (and therefore the jump-table stubs) appear in the
order the cases were written; a non-monotonic source list can be the only
spelling that reproduces the image.

Found in: src/matched/func_021C8EB4.c (0x021C8EB4)

`func_021C8EB4` is a small switch on an argument that maps a request kind to a
DWC result code.  Three result codes appear in several cases, so the compiler
emits one real body per code and makes the other cases a one-instruction
`b` to it.  The real `-15` body lands at `0x021C8EE4` (cases 0,1,2 fall into
it); the real `-14` body is the `default` at `0x021C8F04`; case 7's `-13` body
sits at `0x021C8EFC`.  The stubs between them are:

```
021C8EEC  b 0x021C8F04   case 3  (-14)
021C8EF0  b 0x021C8F04   case 5  (-14)
021C8EF4  b 0x021C8EE4   case 4  (-15)
021C8EF8  b 0x021C8F04   case 6  (-14)
```

The jump table is indexed by value (`case 3` at table slot 3, `case 4` at slot
4), but the stubs are in *source* order: 3, 5, 4, 6.  Writing the cases in
numeric order compiles to `... EEC(case3) EF0(case4) EF4(case5) EF8(case6)`,
which is an eight-byte DIFF in the two swapped stubs (`+0x20`, `+0x24`) even
though every count, constant and call is already right.  Listing `case 5`
before `case 4` is the whole fix; nothing about the semantics changes.

The tell is a switch whose consecutive-arm diffs are only branch targets
pointing at each other's bodies.  Before changing any expression, try
re-ordering the case labels to match where the stubs sit.
