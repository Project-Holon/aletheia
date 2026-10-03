# A signed call result bound to a halfword local truncates before the argument shuffle

summary: When Thumb uses `lsls r0,r0,#16; asrs r1,r0,#16` after a wide-returning call, bind that result to an s16 local before passing it to the next call. An inline cast or a narrow receiving parameter adds a move into r1 before the shifts.

Found in: `src/matched/ov/ov218_func_021B9CDC.c`, `src/matched/ov/ov218_func_021B9D10.c`.

Both callers read the int result of `func_021B8AB8`, narrow it to signed halfword, and call `func_021BA680` with their owner pointer in r0 and the narrowed result in r1. The callee itself also narrows its incoming word at 021BA68A/021BA68C.

```c
extern int get_value(unsigned char *);
extern void set_value(unsigned char *, int);
signed short y;
y = get_value(source);
set_value(owner, y);
```

With fixed dsi/1.1p1, -O4,p, Thumb, c99, this emits the original two shifts directly from r0 into r1. Declaring the setter's second parameter s16, or spelling `set_value(owner, (s16)get_value(source))`, emits `adds r1,r0,#0; lsls r1,r1,#16; asrs r1,r1,#16`, two bytes longer. The named s16 local removed that extra move in both callers, yielding EXACT* and EXACT respectively.
