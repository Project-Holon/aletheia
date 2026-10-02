# Table loads held in temporaries before the stores are read through a cast pointer

summary: when the image loads all three components of a table triple (often
in z, y, x order, one spilled, the table's pool word reloaded for each) and
only then stores them, but your compile interleaves load, store, load, store,
read the table through a pointer cast (`((s16 *)tbl)[k + 2]`) of an object
declared with another type. mwccarm treats a plain extern array element as
unable to alias a store through a pointer parameter and sinks each load to its
store; through the cast it must keep the loads above the stores, so an inline
setter's right-to-left arguments survive as temporaries.

Found in: src/matched/ov/ov021_func_021D14C4.c (0x021D14C4)

The image (0x021D1578..0x021D15A6):

```
adds r1, r0, #2 ; lsls r3, r1, #1 ; ldr r1, =tbl ; ldrsh r1, [r1, r3] ; rsbs r3, r1, #0   ; -t[k+2]
adds r1, r0, #1 ; lsls r5, r1, #1 ; ldr r1, =tbl ; ldrsh r1, [r1, r5] ; str r1, [sp, #0x18] ; t[k+1]
...             ; ldr r0, =tbl    ; ldrsh r0, [r0, r1] ; strh r0, [r4, r6]                 ; t[k]
ldr r0, [sp, #0x18] ; strh r0, [r5, #2] ; ... ; strh r3, [r5, #4]
```

`vset(&out[i], t[k], t[k + 1], -t[k + 2])` with `extern s16 t[]` (any
temporaries, any order, s16/int parameter types) gives x load, x store, y
load, y store, z load, z store with one pool load. With
`extern Norm t[]` (a 6-byte struct) and `#define T(i) ((s16 *)t)[i]`, the same
call compiles to the image. Declaring the table `const` does the opposite (it
lets loads move above stores): that is the lever for a separate table in the
same function whose load the image schedules above a store.
