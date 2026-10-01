# An empty case label at the tree's split point forces the two-node switch tree

summary: a sparse switch {1,2,9} that 1.1p1 lowers as a linear compare chain
becomes the image's two-node decision tree (`cmp #8 / bgt` to a lone `cmp #9`,
`popge`, then the {1,2} chain) only when an *empty* `case 8:` label is present
to give the split a real value; and adding that label breaks the
`case 0:`/`default:` tail merge, so `case 0:` has to be written as the leading
label of `default:` to keep one shared epilogue.

Found in: src/pending/ov_sdk/ov016_func_021D2450.c (0x021D2450)

The image's case-13 body dispatches on `userInfo->f0` over {1,2,9} - one shared
`ChangeState(7)` - as:

```
ldrh r0, [r7]
cmp  r0, #8
bgt  <cmp #9>
popge                    ; 8 -> exit
cmp  r0, #2
popgt                    ; 3..7 -> exit
cmp  r0, #1
poplt                    ; 0 -> exit
cmpne r0, #2
beq  <arm>               ; 1 or 2
```

Written as `case 9: case 1: case 2:` with a `default:`, 1.1p1 emits a 20-byte
shorter linear chain (`cmp #1 / cmpne #2 / beq / cmp #9 / popne`).  Adding an
empty `case 8: break;` (which shares the `break` with `default` and changes no
behaviour) gives the tree its second label and reproduces the image exactly.
The empty label and a hole at 8 are indistinguishable in the dispatch - the
`popge` sends both to the exit - but only the explicit label makes 1.1p1 build
the tree.  This is the counterpart of
`a-short-switchs-interior-gap-still-needs-an-empty-arm.md`, where the same
repair restores a *table*; here it restores a *tree*.

Two side effects, both learned here.  An empty arm that reaches `break` and a
hole that reaches the exit compile the same, so add the label without touching
the other arms.  And once the switch has the extra label the function no longer
tail-merges the outer `case 0: OS_Terminate(); break;` with `default:
OS_Terminate(); break;`, emitting OS_Terminate twice (8 bytes long).  Merging
them `case 0: default: OS_Terminate(); break;` puts the extent back to the
image's 796 bytes and is the idiomatic reading anyway
(`a-switch-compare-chain-is-sorted-but-the-blocks-are-source-order.md`).

When a sparse switch in the image is a small two-node decision tree and your
compile is a linear chain, try adding an empty case label at the boundary the
tree splits on (here the gap between the dense low run and the outlier); then
re-check any case0/default tail merge the extra label disturbed.
