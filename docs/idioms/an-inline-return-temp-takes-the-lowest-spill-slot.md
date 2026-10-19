# An inline return temp takes the lowest spill slot

summary: The return temp of a static inline helper is created after all declared locals and takes
the lowest spill slot. Write the helper out by hand with a declared local.

Seen in ov125 func_021D6B40 (wave D9r, 2026-10-05).

## Symptom
A `static inline` helper gives the right block layout, but a spilled value that the helper's
result is copied into (`ret = helper(p);`) sits in the lowest spill slot. The image has it above
other spilled locals, at the slot its declaration order gives.

## Cause
mwcc creates the inline's return temp after all declared locals. The copy `ret = temp`
coalesces, and the merged value keeps the temp's late identity, so it gets the lowest slot.

## Fix
Write the helper out by hand with the same control flow, with a declared local in place of the
return temp:

    r = 0;                     /* the helper's local initialiser */
    switch (sel) {
    case 0: r = f0(); break;
    case 1: r = f1(); break;
    case 2: r = f2(); break;
    case 3: t = f3(); goto join;   /* was `return f3();` */
    }
    t = r;                     /* was `return r;` */
join:
    ret = t;

Declare `t` where the image's slot order needs it (here, first). Block layout stays as with the
helper; the slot now follows declaration order.
