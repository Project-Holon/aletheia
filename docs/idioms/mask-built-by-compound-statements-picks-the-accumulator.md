# A mask built by compound statements on one local picks a different accumulator register

summary: `t = w + K1; t &= ~w; t &= K2;` and the single expression `(w + K1) & ~w & K2` compile to the same three instructions but not the same destination register for the middle `and`; MSL's word-at-a-time string routines use the statement form, and only that form reproduces the image.

Found in: src/matched/func_02094798.c (0x02094798)

MSL strcpy's word loop tests for a zero byte with the Mycroft mask.  Written as
one expression (in a while condition, through a named temp, with any grouping),
1.1p1 emits `add r4,r5,r3; mvn lr,r5; and r4,r4,lr; tst r4,ip`: the `and`
accumulates into the register holding w + K1.  The image has `and lr,r4,lr`,
accumulating into the register holding ~w.  Spelling the mask the way MSL's
string.c does, one local assigned then narrowed by two compound assignments,
with `if (t) goto adjust;` inside `do { } while (1)`, gives the image's
register and closed the function (2 bytes out for three waves, permuter could
not move it).  When a word-at-a-time MSL routine is one destination register
out in its null-byte test, write the test as MSL writes it before anything else.
