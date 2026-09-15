# A loop inside a switch case leaves through `break` twice, not through `return`

summary: when a case's loop and the default arm both end in the same return
value, the original shares one epilogue only if the loop exits with `break`
out of the loop and then `break` out of the switch; writing `return v` at
either site splits the tail into two copies and costs four bytes.

Found in: `src/matched/unit_0201126C.c` (0x02011298)

The script VM's step function dispatches on a state byte, and state 1 is an
interpreter loop that yields when a command handler asks it to. The original
ends like this:

```
        blx  r2               /* cmds[op](vm, user) */
        cmp  r0, #1
        beq  .ret1            /* yield: jump forward to the shared tail */
        b    .loop            /* otherwise fetch the next opcode */
.dflt:  movs r0, #0
        strb r0, [r5, #0xd]   /* the default arm: state = 0 */
.ret1:  movs r0, #1
        pop  {r4, r5, r6, pc}
```

Two things are being reused at once: the default arm falls into the same
`movs r0, #1; pop` that the yield jumps to, and the yield is a forward branch
to a block placed after the loop rather than an epilogue of its own. Written
the obvious way,

```c
        if (vm->params.cmds[op](vm, vm->user) == 1) {
            return 1;
        }
    }
default:
    vm->state = 0;
    return 1;
```

the compiler inverts the test (`bne .loop`), emits `movs r0, #1; pop` in
place, and emits a second copy of it for the default arm: same logic, 142
bytes instead of 138, and the branch displacement of every earlier arm shifts
with it. The shape that reproduces the original spells both exits as `break`
and puts the single `return` after the switch:

```c
            if (vm->params.cmds[op](vm, vm->user) == 1) {
                break;          /* leaves the for */
            }
        }
        break;                  /* leaves the switch */
    default:
        vm->state = 0;
        break;
    }

    return 1;
```

The reverse reading is the useful one. A `beq` that skips over a short block
and lands on a bare `movs rN, #k; pop` says the block above it is another arm
of the same statement that falls into that return, and that the source has
one `return` reached by two `break`s, not two `return`s the compiler failed
to merge. This compiler does cross-jump identical tails inside one arm (see
`switch-arms-tail-merge.md`), but it will not move a `return` that is
physically in the middle of the function down to the end to merge it with a
later one.
