# A far bcc written as a merged tail adds four estimated pool bytes

summary: the Thumb pool pass estimates a `bcc` at 6 bytes and a `b` at 4. A
far `beq X` in pcode is emitted as `bne +2; b X` (4 final bytes, estimate 6).
The same final bytes also come from pcode `bne L; b X; L:` (estimate 10). That
form appears when the jump to X is a duplicate of X's block that the branch
tail merge folds after the bcc-over-b fold already ran. Use it to move a
mid-function pool by a few estimated bytes with no change to the image.

Found in: `src/game/ov006/event_wificlub.c` (EVENT_WIFICLUB_Main, case 17,
Japanese target, dsi/1.1p1, Thumb). See also
a-thumb-mid-function-pool-goes-at-the-last-branch-after-the-last-new-entry.md.

## Shape

```c
case 17:
    if (!GFL_NET_GetRunState()) {
        EVENT_WIFICLUB_ResetSound(work);   /* same as the cleanup: label */
        *seq = 9;
        break;
    }
```

With `goto cleanup;` the pcode holds one far `beq cleanup` (estimate 6). With
the cleanup statements repeated, the pcode holds `bne L; b cleanup` (estimate
10): the duplicate block becomes `b cleanup` in the tail merge, too late for the
fold. The final bytes are the same in both, so English stays exact, and the
Japanese pool moves back to the end of case 18.

## How to find the site

List final `bcc +2; b far` pairs between the pool's first reference and the
trigger. Map them to the pool pass estimates (breakpoint 0x52C483, insn offset
in [ebx+0x24]): a pair whose estimates are 6 then the next instruction is a
single pcode bcc; 6 then 4 is already the explicit form.
