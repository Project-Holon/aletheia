# A one-initialised return flag preserves one in the upper saved register

summary: For a Thumb caller that stores zero and one before a call and returns its truth value, `int ok=1; ... if (!call(...)) ok=0; return ok;` keeps zero in r4 and one in r5. Initialising the flag to zero and conditionally setting it to one swaps those registers and reverses the branch, producing six differing bytes.

Found in: src/matched/ov/ov123_func_021D5CF8.c (0x021D5CF8), src/matched/ov/ov123_func_021D5D24.c (0x021D5D24).

Both callers store zero at +0xb0, one at +0xcc and zero at +0xd0 before a three-argument call. Under dsi/1.1p1 -O4,p, use:

```c
int ok=1;
*(int *)(p+0xb0)=0;
*(int *)(p+0xcc)=1;
*(int *)(p+0xd0)=0;
if (!call(...)) ok=0;
return ok;
```

The matching form retains `movs r4,#0`, `movs r5,#1`, and `bne join; adds r5,r4,#0`. The zero-initialised form emits the same stores and call, with r4/r5 exchanged and `beq join`. Wave65 S26 logs 021D5CF8-1.log/2.log and 021D5D24-1.log/2.log record the paired fixed-flag DIFF and EXACT*/EXACT verdicts.
