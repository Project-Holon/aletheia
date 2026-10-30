# A block-local for a reloaded field swaps two colours that no declaration order can

summary: when two short-lived values in one block of a long function have each other's
callee-saved registers, and they are compiler temporaries (`@NNNN` in a mwccdbg regalloc capture,
not named variables), declaring one of them as a local inside a `{ }` block around that block
can give the image's colours. Declaration order of the function's own locals does not change
the order of these temporaries.

Found in: src/game/ov088/startmenu.c STARTMENU_CreateRowWindows (black_ja, 0x021BABA8).

The location row (message 16, zone name, print queue) came out with the message in r6 and the
zone name in r4; Japanese has the message in r4, the zone name in r6 and the print system in r6.
`mwccdbg regalloc` showed two allocation rounds; in the second the message and the print system
were temporaries v66 (@3677) and v61 (@3687). `regalloc-replay --round 1 --renumber 66,61`
(the message temporary numbered first) gave the image colours exactly; six declaration orders of
the function's locals, block copies of the message and of the zone name, and all eight
per-function pragmas did not.

The source form that does it reads the print system into a local of the block:

```c
    {
        /* the location row has a print system local of its own */
        void *locationPrintSys;

        msgStr = MSGDATA_AllocString(work->msgBank, 16);
        ...
        locationPrintSys = work->printSys;
        PRINTSYS_PrintQueColor(locationPrintSys, BMP_WIN_GetBmp(work->windows[2].window), ...);
        ...
    }
```

English Black keeps the same bytes with this form, so it needs no language guard.

How to use it: for a colour swap between temporaries, run `regalloc-replay --renumber` on the
pairs first. If renumbering fixes it, try a block-local for the value whose temporary must move.
