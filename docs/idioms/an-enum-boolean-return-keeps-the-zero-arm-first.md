# An enum Boolean return keeps the zero arm first

summary: A Thumb function returning enum FALSE/TRUE keeps the source's zero-return arm before the one-return arm. An int or unsigned int return folds the same if/else to one-first Boolean materialisation and changes three bytes.

Found in: src/matched/ov/ov010_func_0215F630.c (0x0215F630), src/matched/ov/ov010_func_02160DDC.c (0x02160DDC)

Both originals end in `cmp; bne one; movs r0,#0; pop; one: movs r0,#1; pop`.
Under dsi/1.1p1 -O4,p, this spelling preserves that order:

```c
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
BOOL predicate(void *p) {
    if (condition) return FALSE;
    else return TRUE;
}
```

The function return type and return constants are enum-typed. The int and
unsigned int versions emit `beq one; movs r0,#1; pop; one: movs r0,#0; pop`,
even when the if condition and arms are reversed or the function returns a
relational expression directly. Both enum versions are EXACT. Wave49 S16
run1/run2/run3 and check3a logs record the three-byte int/unsigned differences;
check4b records the paired EXACT verdicts. A one-case switch on the halfword
also fixed 02160DDC, but switching on the computed comparison at 0215F630
added ten bytes, so the enum return is the shared spelling.
