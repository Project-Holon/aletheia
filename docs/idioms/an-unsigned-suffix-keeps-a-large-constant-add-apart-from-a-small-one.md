# An unsigned suffix keeps a large constant add apart from a small one

summary: when Thumb code adds a small immediate and then a separately built
large constant (`adds r1,#0x20; movs r0,#1; lsls r0,#20; adds r1,r0`) instead
of loading their sum from the pool, the large constant is an unsigned literal
(`+ 0x20 + 0x100000u`); with a plain int literal mwcc folds the two into one
pool word.

Found in: `src/matched/ov/ov023_func_02184D30.c` (0x02184D30)

The original stores a halfword position built as

```
lsls r1, r6, #5        ; i * 32
movs r0, #1
adds r1, #0x20
lsls r0, r0, #0x14     ; 0x100000
adds r1, r1, r0
strh r1, [r0, #2]
```

Every int spelling folds `0x20 + 0x100000` into one pool word
(`ldr r0, [pc, #..]` = 0x100020, then one `adds`), whatever the order or
parenthesisation: `i * 0x20 + 0x20 + 0x100000`, `i * 0x20 + 0x100000 + 0x20`,
`0x100000 + i * 0x20 + 0x20`, `0x20 + i * 0x20 + 0x100000`,
`(i * 0x20 + 0x20) + 0x100000` and `+ (1 << 20)` all gave the same 97-line
diff. `(i + 1) * 0x20 + 0x100000` came within 3 lines but still differed.

```c
pos.y = i * 0x20 + 0x20 + 0x100000u;   /* EXACT */
```

The unsigned literal makes the outer add an unsigned operation on an int
sum, so the reassociation that would merge the two constants does not
happen, and the large constant is built in a register with `movs; lsls` as a
standalone value.
