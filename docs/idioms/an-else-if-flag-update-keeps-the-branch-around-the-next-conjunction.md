# An else-if flag update keeps the branch around the next conjunction

summary: Two conjunctions that assign the same flag need separate if/else-if arms when the original branches around the second test. Combining them with || threads that branch away and shortens the Thumb function by two bytes.

Found in: src/matched/ov/ov135_func_021F81C8.c (0x021F81C8), src/matched/ov/ov135_func_021F8290.c (0x021F8290)

The matching spelling is:

```c
if (index == 29 && mode == 2)
    show = 0;
else if (index == 32 && mode == 1)
    show = 0;
```

With dsi/1.1p1 -O4,p, the first conjunction emits two bne instructions followed by a branch to the shared zero assignment. The second conjunction follows that branch. Writing `if ((index == 29 && mode == 2) || (index == 32 && mode == 1)) show = 0;` instead gives a beq directly to the assignment and removes the intervening branch: 196 bytes rather than the matching 198 bytes. The second function uses the same control flow; both individual verdicts are EXACT* with two trailing padding bytes, and their combined scratch TU is EXACT.
