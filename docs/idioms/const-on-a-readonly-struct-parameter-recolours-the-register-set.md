# `const` on a read-only struct parameter recolours the whole parameter register SET

summary: when every instruction of a function already matches but the
callee-saved register each incoming parameter is homed into is wrong, `const`
on the struct parameter the body only reads is a real lever, not a front-end
tie. The vendor's own header declared it const; adding the qualifier (and
relaxing the callees that receive `param->field` to accept a const source)
recolours the set and can make the entire prologue and body match. Check the
vendor prototype before concluding a register set "cannot be forced".

Found in: `src/pending/ov_sdk/ov009_func_0217E504.c` (0x0217E504, ov009,
gsiLargeIntMultM, gslargeint.o). Was 149 concrete bytes at WAVE8 start, now
107.

The GameSpy upstream prototype is

```c
gsi_bool gsiLargeIntMultM(gsLargeInt_t *x, gsLargeInt_t *y,
                          const gsLargeInt_t *m, gsi_u32 modPrime,
                          gsLargeInt_t *dest);
```

i.e. the modulus is `const` and never written. The parked source had it
non-const. Making `m` const immediately dropped 149 -> 108 and made the
prologue byte-identical to the image:

```
image:  mov r5, r1   /* y -> r5 */   mov r4, r2   /* m -> r4 */   mov r7, r0   /* x -> r7 */
before: mov r4, r2   /* m -> r4 */   mov r7, r1   /* y -> r7 */   mov r8, r0   /* x -> r8 */
after:  mov r5, r1   /* y -> r5 */   mov r4, r2   /* m -> r4 */   mov r7, r0   /* x -> r7 */
```

`const` changed the allocator's live-range/alias model enough to move `y` off
`r7` onto `r5`, exactly what the earlier lane had declared a "vendor front end
allocator tie" (see
`vendor-front-end-parameter-register-set-cannot-be-forced.md`). That older
idiom is only right once every *candidate* source lever is exhausted; a
qualifier is a candidate.

Practical recipe: the C compiler rejects passing `const T *->field` to a
non-const callee parameter, so declare the receiving externs' array
parameters const (and any `T *` local that points into the const object, e.g.
`lastnptr`/`nptr`) before judging the verdict -- the raw `const m` edit alone
reports `CCERR`, which is easy to mistake for "const is not viable".

Rule: before parking a register-set-only residue, grep the vendor object's
defining header/source in `scratch/` for the exact prototype. A missing
`const` there is a first-class source lever. This is the same family as
`const-on-a-readonly-source-parameter-settles-a-register-tie.md`.
