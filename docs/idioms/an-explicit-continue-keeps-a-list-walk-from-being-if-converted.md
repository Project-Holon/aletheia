# A linked-list walk whose test is the increment is if-converted unless the source says `continue`

summary: `p = p->next; if (p == 0) break;` at the tail of a `for(;;)` /
`while (1)` loop compiles with the update and the test fused into
`ldrne`/`cmpne`/`beq`; writing it as `p = p->next; if (p != 0) continue;
break;` keeps two separate instructions and the plain `bne <top>` / `b <end>`
pair the object has.  A `do { ... } while ((p = p->next) != 0)` does **not**
reproduce it either.

Found in: `src/pending/ov_sdk/ov114_func_021BD7E8.c` (0x021BD7E8,
`NHTTPi_ThreadSendProc`), scan of `req_p->datalist_p`.

The object walks the datalist and stops on a sentinel:

```
ldr  r2, [r2, #4]      @ p = p->next
cmp  r2, #0
bne  <loop top>
b    <after loop>
```

`p = p->next; if (p == 0) break;` gives instead the if-converted

```
ldrne r2, [r2, #4]
cmpne r2, #0
beq   <after loop>
b     <loop top>
```

one instruction (four bytes) shorter.  Spelling the same control flow out
with an explicit `continue` restores the two-instruction form:

```c
datalist_p = datalist_p->next;
if (datalist_p != 0) {
    continue;
}
break;
```

This is the same shape family as
`docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md`: the front end
will merge a store and a test across a loop back-edge when the source does not
separate them, and the merge changes the function size.
