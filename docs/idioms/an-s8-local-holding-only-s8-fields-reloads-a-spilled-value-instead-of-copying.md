# An s8 local that only holds s8 fields reloads a spilled value where an int one copies it

summary: when a local is assigned only from s8 fields (a clipped coordinate), declaring it s8
instead of s32 is value-preserving and changes the allocator's choice: the clamp value is
reloaded from its spill slot instead of copied between registers, and later stack-argument
stores fall back into the image's order.

Found in: src/matched/func_0202CC70.c (0x0202CC70)

The clip `if (sy < win->ymin) { sy = win->ymin; oh -= (s8)(win->ymin - y); }` holds
win->ymin in a spilled CSE temporary. With `s32 sy` the compile stores it to sy's slot and
then copies it (`adds r6, r2, #0`) for the subtraction; the image stores it and reloads it
(`ldr r6, [sp, #0x10]`). Declaring `s8 sy` (sy is only ever win->y or win->ymin, so no value
changes) gives the reload, and the same change moves the call's `str r0, [sp, #8]` for the
constant stack argument ahead of the sx/sy argument reloads. No register, order or temporary
spelling reached either difference; the permuter found it (type mutation on sy) and the
minimisation showed the type alone closes both. Check the local's full value range before
narrowing: every assignment must come from a field or expression of the narrow type.
