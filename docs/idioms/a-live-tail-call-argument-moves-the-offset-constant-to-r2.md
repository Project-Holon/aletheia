# A live tail-call argument keeps r1 and moves the offset constant to r2

summary: When a stored parameter is still live at the tail call, the compiler
cannot reuse r1 for a large field offset and reaches for the pool scratch
register r2 instead; dropping the forwarded argument frees r1 and changes only
the register name, one instruction, and the whole function reads as DIFF.

Found in: src/matched/ov197_func_0220D974.c (0x0220D974)

The original is

    ldr r2, [pc, #0xc]        ; offset 0x598 from the pool
    ldr r3, [pc, #0x10]       ; func_0220AFDC
    str r1, [r0, r2]
    movs r2, #0x52            ; 0x148
    lsls r2, r2, #2
    ldr r0, [r0, r2]
    bx r3

The second parameter `b` is stored to `a+0x598` and is still in r1 when the
tail call is set up. Because r1 is live, the compiler has to build 0x148 in r2
(the same register it just used for the 0x598 pool load). Writing the callee as
taking only the field value

    void func_0220D974(char *a, int b)
    {
        *(int *)(a + 0x598) = b;
        func_0220AFDC(*(int *)(a + 0x148));
    }

lets the compiler reuse the now-dead r1 for 0x148:

    movs r1, #0x52
    lsls r1, r1, #2
    ldr r0, [r0, r1]

which is a one-instruction register-name diff against the original. Forwarding
the same live parameter through the tail call

    func_0220AFDC(*(int *)(a + 0x148), b);

keeps r1 occupied and reproduces the original exactly. So an otherwise
unexplained r2-vs-r1 choice for a large constant is often a hidden live
argument, not a different expression.
