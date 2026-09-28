# A dead second branch on the same flags is a nested if that tests the variable again

summary: `cmp rN, #0; bne A; bne B` (the second branch can never be taken) comes from an inner test of the same variable inside the outer test's arm, such as `if (ret == 0) { if (ret != 0 || x == 1) break; }`; the flattened `if (ret == 0 && x == 1)` and the other nestings drop the second branch or point it at the wrong block.

Found in: src/matched/ov016_func_021B62C0.c (0x021B62C0)

AOSS_Init_old (aoss.o, ../2.0/sp1p2) has two retry loops around AOSSi_WLANConnect. In the image
each loop body tests the result as

```
cmp r0, #0
bne <sleep and retry>
bne <loop exit>          ; dead: the flags still say "equal"
ldr r0, [r7, #0xc]       ; linkInfo->LinkStat
...
```

The front end does not fold the inner `ret != 0` test away even though the outer test
decides it, and the branch it emits for the inner `||` goes to the `break` target. Each
spelling below was 2 bytes short per loop, or had the second branch pointing at the sleep
block: `if (ret == 0 && LinkStat == 1)`, `if (ret == 0) { if (LinkStat == 1) break; }`,
`if (ret == 0) { if (ret == 0 && LinkStat == 1) break; }`,
`if (ret != 0) {} else if (...)`, and a nested `if (ret == 0)` pair.
`if (ret == 0) { if (ret != 0 || LinkStat == 1) break; }` gives both branches and both targets.
