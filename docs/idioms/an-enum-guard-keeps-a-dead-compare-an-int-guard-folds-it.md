# An enum guard keeps a dead compare an int guard folds, and it costs no instruction to do it

summary: an image that tests a value it has just set to a known constant, and
branches on the result, is reproduced by typing the tested value as an enum, not
by re-assigning the constant in the guarded arm.  Under `-enum int` mwccarm does
not propagate an enum-typed value, so `cmp rN,#0 / b<cc>` survives with no store
anywhere near it.  With an `int` the whole guard chain is constant-propagated
and the branch is deleted.  It is the *type* of the tested value that does it:
the guard's own constant may be an enumerator or a bare `0`.

Found in: `src/matched/ov_sdk/ov175_func_021DFD24.c` (0x021DFD24, ov175, ARM)

`scReportSetPlayerData` zeroes an accumulator at +0x0C, never writes it again on
the path that reaches the first setter, and then still tests it four times:

```
021DFD30  mov  r0, #0            <- aResult = 0
...
021DFD74  ldr  r1, [r6, #0x10]   <- the new-team arm, 9 instructions
...
021DFD98  cmp  r0, #0            <- DEAD: r0 is 0 on every path that arrives
021DFD9C  bne  0x021dfdac
021DFDA0  mov  r0, r6
021DFDA4  mov  r1, r5
021DFDA8  bl   sciReportSetPlayerConnectionId
```

The object was built with Metrowerks 4.0.0.1025, which emitted the dead test.
1.1p1 folds it, and the residue is four bytes.

## What does not work: buying the test back with a store

The obvious way to stop 1.1p1 folding a test on a known-constant value is to
write the constant again inside the guarded arm, so the test is no longer
provably dead:

```c
if (isNewTeam) {
    n = aReport->mNumTeamsReported + 1;
    aReport->mNumTeamsReported = n;
    aResult = 0;                 /* redundant, and it does keep the test */
    if (n > 64)
        return 5;
    aReport->mTeamIds[n - 1] = thePlayerTeamId;
}
if (aResult == 0)
    aResult = func_021DFF78(...);
```

The redundant `aResult = 0` does keep `cmp r0,#0 / bne` — 1.1p1 does not
dead-store-eliminate it across the branch — but it spends a `mov r0,#0` in the
arm, and the arm here has exactly nine instruction slots.  Adding the fourth
gives 220 bytes.  That is the shape of a wall that is not structural: the arm
was never required to hold a re-zero, only to hold the value the test needs to
be opaque *by construction*.

## What does work: the type

```c
typedef enum { RESULT_OK = 0, RESULT_BAD = 1 } TResult;

TResult aResult;
...
aResult = RESULT_OK;
...
if (aResult == RESULT_OK)
    aResult = func_021DFF78(aReport, thePlayerIndex, thePlayerConnectionId);
```

216 bytes, EXACT, all four relocations resolved, and nothing in the arm changes.
The re-zero is gone, so the four bytes the object spends there on the fresh
count read are free for the reload.

Measured on this function, one variable changed per row, everything else held at
the EXACT source:

| accumulator | guard constant | verdict |
| --- | --- | --- |
| `TResult` | `RESULT_OK` | **EXACT**, 216 B |
| `TResult` | `0` | **EXACT**, 216 B |
| `int` | `RESULT_OK` | DIFF, 204 B, 174 concrete out |
| `int` | `0` | DIFF, 204 B, 174 concrete out |

So the enumerator is irrelevant and the type is the whole lever.  The `int`
rows do not merely lose four bytes: constant propagation reaches through the
three call results, so all four guards collapse into a straight-line chain and
the loop rotates as well, which is why they are 204 and not 212.

## The generalisation, and the trap

A dead `cmp`/`b<cc>` against a known constant is a **typing** residue, not a
scheduling or a dead-code one, whenever the value tested is a plain integer the
front end can propagate.  Reach for the type before reaching for a store: the
store costs an instruction in the guarded arm, the type costs nothing.

The trap is measuring the type lever on a baseline that already unfolds the test
for another reason.  A build that keeps the redundant re-zero cannot show any
difference from making the accumulator an enum, because the test survives either
way — which is exactly how this row was recorded as "enum-typed `aResult` is
codegen-neutral under `-enum int`".  Drop the re-zero first, then the type is
visible.  The two levers are not alternatives to be weighed against one
baseline; each is invisible until the other is removed.

The same lever closed `src/matched/arm9/func_02066998.c`, where the dead compare
is a loop-entry test rather than a guard on an accumulator, and the DWARF's
`enum @enum` spelling of the tested variable is usually the hint that the type is
the missing piece.  See also
`an-enum-type-keeps-values-out-of-constant-folding.md` and
`an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-folded.md`, which are
the same mwcc behaviour on a loop counter and on a zero's register allocation.
