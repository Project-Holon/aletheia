# Repeated print blocks are one static inline with the first argument bound first

summary: when a function repeats the same four-call block (fetch a string,
print it into a window bitmap, set a dirty byte, free the string) and the
original loads the print call's first argument (`ldr r6, [r5, #0x68]`)
between the `adds r0, #0xf0` and the `ldr r0, [r0]` of the nested
bitmap-getter call, and rematerialises the colour constant (`movs r0, #0x11;
lsls r0, #6`) in every block, write the block once as a `static inline`
helper that binds that first argument to a local before the call; written
out flat, every block loads it after the nested call and the colour is kept
in a callee-saved register, which shifts every register in the function.

Found in: `src/matched/ov/ov088_func_021BBBAC.c`,
`src/matched/ov/ov088_func_021BBD80.c` (and the single-block variant in
`src/matched/ov/ov088_func_021BBE48.c`, written flat with the same local).

The spelling:

```c
static inline void print_line(char *p, u32 id, u32 y, u16 color)
{
    u32 s = func_02045EC0(*(u32 *)(p + 0x5c), id);
    u32 a = *(u32 *)(p + 0x68);
    func_0201C724(a, func_02045770(*(u32 *)(p + 0xf0)), 0, y, s,
                  *(u32 *)(p + 0x58), color);
    *(u8 *)(p + 0xf4) = 1;
    func_02045808(s);
}
```

Called as `print_line(p, 0x16, 0, 0x14c0); print_line(p, 0x17, 0x18, 0x440);
...`.

What the other spelling gave: the four blocks written out flat with
`*(u32 *)(p + 0x68)` inline in the call gave a same-size DIFF from +0x04 on
(r4/r5 swapped for `p` and the string, the 0x68 load after the getter call,
and `0x440` held in r7 across blocks). The inline helper with the local
closed it in one compile.
