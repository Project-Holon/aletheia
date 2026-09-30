# A first field read through the object keeps a later subblock base apart

summary: When a function keeps `t = (Tail *)(q + K)` for later uses but originally loads the first index through `q + K + 4`, spell that early load through the object itself. Using `t->index` everywhere moves the subblock base setup early and removes the separate base-plus-offset loads.

Found in: src/matched/ov/ov112_func_021F7C90.c (0x021F7C90), src/matched/ov/ov112_func_021F7E2C.c (0x021F7E2C), src/matched/ov/ov112_func_021F7AEC.c (0x021F7AEC).

These functions keep a pointer to a subblock at `q + 0xf0` in r4. Later index loads are `ldr r1, [r4, #4]`, but the first load uses a temporary base at `q + 0xf4`. In the two setup functions a second early load also uses that temporary base.

The matching spelling is:

```c
Tail *t = (Tail *)(q + 0xf0);
char *r = func_021F5450(*(char **)(q + 0x58), *(int *)(q + 0xf4));
/* Later calls use t->index. */
```

Using `t->index` in the first call gives the same values, but hoists the r4 setup and uses `[r4,#4]` there too. The two setup functions compiled six or eight bytes short, and the animation function four bytes short of its matching code length. The raw first load (and raw second early load in the setup functions) restores those instructions while preserving the later subblock accesses.
