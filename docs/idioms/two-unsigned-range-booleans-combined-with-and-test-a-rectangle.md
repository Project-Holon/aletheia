# Two unsigned range booleans combined with AND test a rectangle

summary: two subtract-and-unsigned-compare sequences that each materialise
0 or 1 before an AND are independent inclusive range tests combined with
bitwise `&`; preserve both materialised booleans rather than short-circuiting.

Found in: `src/matched/ov/ov183_func_021DD27C.c`,
`src/matched/ov/ov183_func_021DD2BC.c`,
`src/matched/ov/ov183_func_021DD2FC.c`,
`src/matched/ov/ov183_func_021DD33C.c`.
Their existing twin is `src/matched/ov/ov183_func_021E3228.c`.

```c
int ok = ((unsigned int)(a - x) <= width) &
         ((unsigned int)(b - y) <= height);
if (ok) {
    int args[2];
    args[0] = a;
    args[1] = b;
    send(object, 1, args);
}
return ok;
```

Each comparison produces a separate boolean, followed by `ands` and a
single branch. The unsigned subtraction rejects coordinates below the
lower bound as well as above the upper bound. Logical `&&` expresses a
short-circuit dependency absent from this listing; signed comparisons
would admit negative differences. All four sources matched on their first
fixed-compiler run using the twin's spelling.
