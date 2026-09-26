# An 8-byte pair copy loads both words before either store

summary: An 8-byte `struct { int x, y; }` assignment compiles as two loads then two stores, which two separate `out[0]`/`out[1]` stores do not; the load-then-store shape and the scratch-register order are the register-colouring tell.

Found in: src/matched/ov106_func_021B9414.c (0x021B9414)

The image for mode 0 of `func_021B9414` is:

    ldr r1, [r5, #0xc]
    ldr r0, [r5, #0x10]
    str r1, [r4]
    str r0, [r4, #4]

Writing the obvious `out[0] = o->fc; out[1] = o->f10;` produces an interleaved
load-store-load-store (`ldr r0; str r0; ldr r0; str r0`) and never matches;
assigning through two named temporaries gets the "load both then store both"
shape but pins the *first* stored word to r0 and the second to r1, leaving a
four-byte register swap (`ldr r1`/`ldr r0` vs the image's `ldr r0`/`ldr r1`).
Neither declaration order, `register` locals, an array view
(`((int *)o)[3]`), nor reversed statement order changes it — the allocator
canonicalises the two independent loads to a fixed register pair.

Spelling it as a single 8-byte aggregate assignment is what reproduces the
image exactly:

    typedef struct { int x, y; } Pair;

    *(Pair *)out = *(Pair *)((char *)o + 0xc);

The struct copy makes both words live simultaneously, so the compiler emits
both loads before either store *and* orders the loaded words to r1 then r0,
matching the image byte for byte. So when a two-word move out of a struct
shows up as load/load/store/store in the listing, write it as an 8-byte struct
assignment rather than two member stores.
