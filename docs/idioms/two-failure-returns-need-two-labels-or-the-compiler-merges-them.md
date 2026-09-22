# Two failure returns need two distinct labels, or the compiler merges them into one predicated tail

summary: when the image carries two near-identical `mov r0,#0` / `pop` blocks,
one per guard, a plain `return 0;` in each guard (or one shared `fail:` label)
is cross-jumped into a single predicated `moveq r0,#0` / `popeq` and the
function comes out four bytes short; two DISTINCT labels at the end of the
function, one per guard, is what keeps both copies.

Found in: `docs/notes/sub_02063138.c.txt` (0x02063138, `../2.0/sp2`),
measured 2026-09-22 in `cluster_02063000`.

`func_02063138` reserves a span in each of two free-slot tables and returns 0
if either check fails. The image spends two full copies of the failure tail,
at 0x020631E0 and 0x02063270, each reached by a real `beq` over the success
path:

```
    cmp  r0, #0
    beq  .fail1          /* 0x020631A0 -> 0x020631E0 */
    ...success path 1...
    b    .next
.fail1: mov r0, #0
        pop {r4, r5, r6, r7, r8, pc}
.next:  ...
    cmp  r0, #0
    beq  .fail2          /* 0x02063244 -> 0x02063270 */
    ...success path 2...
    b    .done
.fail2: mov r0, #0
        pop {r4, r5, r6, r7, r8, pc}
```

Four source shapes were measured against those 348 bytes, all under the same
front end:

```c
if (ok == 0) return 0;          /* 344 bytes: predicated moveq/popeq inline */
if (ok == 0) { return 0; }      /* 344 bytes: identical, braces change nothing */
if (ok == 0) goto fail;         /* 344 bytes: ONE label, both gotos, merged */
if (ok == 0) goto faila;        /* 348 bytes: two labels, both copies kept  */
```

with the two labels written as the last statements of the function:

```c
    return 1;
faila:
    return 0;
failb:
    return 0;
}
```

This is the exact inverse of
[a shared exit block is written out in each arm](a-shared-exit-block-is-written-out-in-each-arm.md).
That idiom's lesson is to write the shared statements out in every arm and let
the compiler cross-jump them; the lesson here is that when the image did NOT
cross-jump, writing one copy behind one label is what makes the compiler merge
too far. The two idioms are the two directions of the same decision, and which
one applies is read off the image: count the `mov r0,#0` / `pop` blocks. Two
blocks in the listing means two labels in the source.

Note that `goto fail;` with one label and `return 0;` in each guard produce the
IDENTICAL output here, which is the tell that the compiler is merging rather
than that the goto is being taken literally: the merge happens on the CFG after
the source shape is gone, so the only thing that survives it is two distinct
targets.
