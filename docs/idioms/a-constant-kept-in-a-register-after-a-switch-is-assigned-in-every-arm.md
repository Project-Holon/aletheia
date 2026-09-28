# A constant held in a register or frame slot after a switch join is a variable assigned the same value in every arm

summary: when the image materialises a small constant once right after a switch's arms rejoin (`movs r0, #0x28; str r0, [sp, #0x14]`, `movs r6, #1`) and then reads it from that slot or register at every use, the source assigned it in each arm (`level = 40; flag = 1;` in both cases), and the compiler tail-merged the identical assignments to the join without folding the constant; one `level = 40;` after the switch is propagated and rematerialised at each use instead (229 concrete bytes out, 12 bytes short).

Found in: src/matched/ov010_func_0215E440.c (0x0215E440)

The image (Thumb, 1.1p1 -O4,p), after `switch (which)` whose two arms load
only the species pool word into r7:

    movs  r0, #0x28
    str   r0, [sp, #0x14]      ; level, spilled, read back at both uses
    movs  r6, #1               ; flag, held in a callee-saved register
    ...
    ldr   r2, [sp, #0x14]      ; func_0200D50C(rec, 6, level)
    adds  r2, r6, #0           ; func_0200D50C(rec, 9, flag)
    ...
    ldr   r2, [sp, #0x14]      ; func_02017588(mon, species, level, ...)

The C that reproduces it:

    switch (which) {
    case 0:
        species = 642;
        level = 40;
        flag = 1;
        break;
    case 1:
        species = 641;
        level = 40;
        flag = 1;
        break;
    default:
        return;
    }

`level = 40;` written once after the switch (or passed as a literal) is
constant-propagated, and every use becomes its own `movs r2, #0x28`: 308 bytes
against 320, with the frame and the push list one slot smaller. The ../2.0/sp2
pin does not help, so this is not the "kept constants" pin tell; check for
per-arm assignments before reaching for a pin. In the same function the species
had to be `u32` (it is truncated with `lsls/lsrs #16` at the u16 call argument),
which is the other sign that these are variables rather than literals.
