# A doubled loop entry guard is an explicit if in front of the for

summary: when the image tests a loop's entry condition twice in a row
(`adds/bmi` then `cmp #0/blt`, or `cmp` then `cmpgt` on the same register), the
source has an `if` with the loop condition in front of the loop. mwcc keeps
both the `if` and its own rotation guard, and it does not merge them.

Found in: src/matched/func_0209953C.c (0x0209953C, fdlibm __kernel_rem_pio2, dsi/1.2)

The image opens the f[] setup loop like this:

```
adds r8, r5, r0      <- m = jx+jk, then the rotation guard on its flags
bmi  skip
cmp  r8, #0          <- a second test of the same condition
blt  skip
```

and it opens the recompute distill loop with `cmp r0, #0` ... `cmpgt r0, #0` / `ble`.
The fdlibm text `for(i=0;i<=m;i++,j++)` and `for(i=0,j=jz,z=q[jz];j>0;i++,j--)`
compile to the single guard, which is 12 bytes short (2980 against 2992). This
spelling is exact:

```c
j = jv-jx; m = jx+jk; i = 0;
if(m>=0) for(;i<=m;i++,j++) f[i] = (j<0)? zero : (double) ipio2[j];
...
i=0; j=jz; z=q[jz]; if(j>0) for(;j>0;i++,j--) { ... }
```

The position of the hoisted `i = 0` matters. Written first (`i = 0; j = ...;`)
or kept in the for header, the bytes come out the same size, but i and j swap
registers in the later recompute loop (10 bytes out). No front end from 1.1 to
2.0 produces the second guard from the plain for loop.
