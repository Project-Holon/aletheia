# A separate context local per print restores the spill slot order

summary: repeated print calls that reload one context field can be byte-correct except for swapped spill slots when one pointer local is reused; naming the second and, when needed, third context values separately restores descending slot order without moving any load or call.

Found in: `src/matched/ov/ov198_func_0220D6DC.c`, `src/matched/ov/ov198_func_0220CDF0.c`, and `src/matched/ov/ov198_func_0220C714.c`.

Each print loads the context before a surface getter, so the context survives a call and spills. A single reused `void *context` left `0220D6DC` and `0220CDF0` at their original sizes with four concrete bytes out: the second and third context stores/reloads used each other's stack slots. Giving only the second print a separately declared `void *secondContext` made both EXACT at fixed `dsi/1.1p1 -O4,p` flags.

```c
void *context;
void *secondContext;
/* ... */
context = *(void **)(p + 0x1EAC);
print(context, get_surface(first), /* ... */);
/* ... */
secondContext = *(void **)(p + 0x1EAC);
print(secondContext, get_surface(second), /* ... */);
/* ... */
context = *(void **)(p + 0x1EAC);
print(context, get_surface(third), /* ... */);
```

`0220C714` needed a third separately declared context local as well. Splitting only the second moved its spill into place but left the third context and final message pointer swapped (five concrete bytes out); splitting the third closed the diff. The loaded values have disjoint lifetimes, unlike the dependent narrow assignments in `a-spilled-local-assigned-twice-occupies-two-stack-slots.md`.

Do not cache the context across a print call: keep every original field reload. In `0220D6DC`, changing the outer pointer to `const char *` instead changed scheduling and worsened the four-byte residue to 38 bytes.
