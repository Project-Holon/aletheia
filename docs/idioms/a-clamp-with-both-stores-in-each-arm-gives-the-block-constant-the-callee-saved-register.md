# A clamp with both stores in each arm gives the block constant the callee-saved register

summary: a long-lived value (a getter result used in every case of a switch) sits in a
callee-saved register in the build, while the image spills it and uses that register for a
per-case constant. The fix was not about the long-lived value. It was the shape of one clamp
in one case: an if/else that writes both following stores in each arm.

Found in: src/matched/ov/ov041_func_021F3884.c (0x021F3884), open for seven waves.

## Symptom

- The image spills `s` (13 reloads of `[sp,#0x24]`) and keeps a per-case value in r7 (case 1: a
  pool constant 0x708, with 0x714/0x71A/0x71C/0x71E built as `r7 + K`). The build keeps `s` in r7
  and rematerialises or spills the constant.
- The image's clamp has `blt L; adds; subs; b L; L:`, a branch to the next instruction (an
  empty arm after tail merging).

## What closed it

```c
c = tbl[idx].c;          /* loaded first, as in the image */
len = tbl[idx].d;
n = *(u16 *)(w + 0x71A);
if (c + len >= n) {
    *(u16 *)(w + 0x71C) = n - (len + 1);
    *(u16 *)(w + 0x71E) = len;
} else {
    *(u16 *)(w + 0x71C) = c;
    *(u16 *)(w + 0x71E) = len;
}
```

The repeated stores add uses of the block constant (r7 + 0x14, r7 + 0x16) in each arm. The
constant then ranks above `s`, takes r7, and `s` spills. Tail merging later folds the two arms
into one join store, so the image shows one store and an empty arm. A ternary, an if-set of `c`,
or one store per arm with the 0x71E store after the join all keep `s` in r7.

## Other parts of the same close

- `v = call(...);` then `v / 4096` at each compare (not the divide in the assignment): the image
  computes the table index before the divide.
- Aggregate locals (Vec, request structs) declared in the block where they are used: their stack
  slots follow the order of appearance (first used = highest), and `Vec p = {0, 0, 0};` gives the
  `add rN,sp,#K; movs r0,#0; str r0,[rN]; str r0,[rN,#4]; ...` zeroing form.
- `if (w[2] == 0) return 0;` that the image compiles as a branch to the final epilogue is
  `if (w[2] != 0) { ... } return 0;`.

## Steps

When a long-lived value wins a callee-saved register that the image gives to a block constant,
look for a nearby if/else or ternary whose following stores use that constant. Write those
stores in each arm.
