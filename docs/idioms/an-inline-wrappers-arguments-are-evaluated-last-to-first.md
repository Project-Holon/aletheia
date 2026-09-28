# An inline wrapper's arguments are evaluated last to first

summary: a load of the destination that sits BEFORE the source call, with the size call before both, is `GFL_STD_MemCopy(src(), dst, size())` through a `static inline` wrapper of MI_CpuCopy8: the inline's arguments are evaluated right to left. Calling MI_CpuCopy8 directly evaluates the calls left to right and sinks every plain load after them, and a block-scope `dst` local is forward-substituted past the call too.

Found in: src/pending/ov119_func_021E049C.c (0x021E049C), src/matched/ov119_func_021E0138.c (0x021E0138)

The image, at 0x021E05B2..0x021E05CC:

```
bl   sub_02007A9C          ; size
ldr  r1, [r4, #8]
adds r7, r0, #0
adds r5, #0x30
subs r0, r6, #4
ldrh r1, [r1, #0x28]
ldr  r5, [r4, r5]          ; dst = p->f624, loaded before the source call
ldr  r0, [r4, r0]
bl   sub_02007AF4          ; src
adds r1, r5, #0
adds r2, r7, #0
blx  MI_CpuCopy8
```

`MI_CpuCopy8(sub_02007AF4(save, box), p->f624, size)` with `size` bound to a
local first gives the same instructions but with `ldr r1, [r4, r5]` AFTER the
`bl sub_02007AF4` (4 bytes of a 1100-byte function out, everything behind it
shifted). Binding `dst` to a block-scope or function-scope local, before or
after `size`, does not move the load: the compiler substitutes the single-use
load into the argument. Passing `sub_02007A9C()` inline to MI_CpuCopy8 calls
the source first and the size second.

With the GameFreak wrapper

```c
static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

GFL_STD_MemCopy(sub_02007AF4(save, box), p->f624, sub_02007A9C());
```

the arguments are evaluated size call, destination load, source call, which is
the image. The same wrapper closes the three out-of-line copy leaves of this
file (0x021E0138, 0x021E01A0, 0x021E0200), where the size call precedes the
source call; there a hoisted `size` local also works, so the wrapper is the one
spelling that fits every site.
