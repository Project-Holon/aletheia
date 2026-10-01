# A loop-peeled entry test under a short guard is not if-converted by 1.1p1

summary: when an `if (scalar > 0)` wraps a `for (i = 0; i < count; i++)` and
`count` is read through a pointer, the image can predicate the whole peeled
prologue -- load `count`, `cmp count, #0`, plus the loop's `i = 0` -- into the
guard's condition, collapsing `scalar > 0` and `count > 0` into one unpredicated
`ble`. `dsi/1.1p1` keeps the entry test as its own branch even though the
peeled block is only five instructions, so the guard-arms predication budget
does not apply to a block the compiler reached by loop rotation rather than by
spelling an arm.

Found in: `src/pending/ov_sdk/ov114_func_021C7644.c` (`DWCi_Ndi_response_list`,
0x021C7644, 648 bytes against 640, still open)

The original, 0x021C76C0..0x021C76DC:

```
cmp   r4, #0          ; bodyLen
ldrgt r0, [sp]        ; req
movgt r5, #0          ; p = 0
ldrgt r0, [r0, #0x10] ; req->size
strgt r5, [sp, #8]    ; n = 0
cmpgt r0, #0          ; n < size
ble   done            ; taken when bodyLen <= 0 OR size <= 0
```

`dsi/1.1p1` at `-O4,p` emits the same five instructions but as an unpredicated
block behind a leading `ble`, then a second `ble`/`bls` for the entry test:

```
cmp  r4, #0
ble  done
ldr  r0, [sp]
mov  r5, #0
ldr  r0, [r0, #0x10]
str  r5, [sp, #8]
cmp  r0, #0
bls  done
```

`an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md` says the
front end predicates a five-instruction arm; that budget is measured on the arm
*as written*. Here the arm is the whole outer loop, and the five predicated
instructions are the rotation's peeled prologue, which 1.1p1 does not fold.
`docs/idioms/predication-of-short-guard-arms-is-the-front-end-not-the-shape.md`
is the general rule; this is its loop-rotation instance. Levers tried and
measured, all `648`-`652` bytes, none predicated: folding the size test into the
guard with `&&` (652), moving `p = 0` outside the guard (648), spelling the
prologue as a nested `if` (652). Treat the residue as compiler-owned rather than
as an unfinished spelling.
