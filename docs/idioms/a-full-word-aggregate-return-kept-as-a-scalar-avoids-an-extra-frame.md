# A full-word aggregate return kept as a scalar avoids an extra frame

summary: When a four-byte aggregate getter returns the complete word in r0 and a restore function stores that unchanged word from r1, a proven scalar u32 interface can preserve the original register save while an aggregate local adds frame words.

Found in: src/matched/ov/ov093_func_021BCEFC.c (0x021BCEFC), src/matched/ov/ov093_func_021BD518.c (0x021BD518), src/matched/ov/ov093_func_021BDC2C.c (0x021BDC2C), src/matched/ov/ov093_func_021BE994.c (0x021BE994).

The own matched getter 021CC8D8 returns a four-byte Lock bitfield aggregate. Its original loads the complete old word at 021CC8DA and returns that word unchanged in r0 at 021CC900, while updating the pointed-to lock. The complete restore body at 021CC95C is `str r1,[r0]; bx lr`; its callers also visibly supply the line argument in r2. Existing matched callers 021BC568, 021BD708 and 021BDD7C retain the full payload as u32.

These callers save the whole returned register across another call and restore every bit. Using an aggregate or union local introduced extra frame words; a scalar interface and local preserve the original save and call/store order:

```c
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
u32 old;
old = func_021CC8D8(lock, line);
/* Original intervening call. */
func_021CC95C(lock, old, next_line);
```

Paired dsi/1.1p1 -O4,p Thumb c99 verdicts changed DIFF/60 to EXACT/56 bytes at CEFC, DIFF/64 to EXACT/60 at D518, DIFF/52 to EXACT/44 at DC2C, and DIFF/64 to EXACT/60 at E994. Sources record the original register/body evidence; lane reports and unique logs retain both spellings. Each final shard is verified independently.

This interface spelling requires primary proof of the complete return payload, scalar register ABI, restore reads, and every visibly forwarded input. Preserve getter side effects and all payload bits. Do not apply it to wider aggregates, partial reads, hidden return pointers or unproved padding; do not change the callee's owned source to force a caller match. The existing one-word-struct-result temporary idiom describes aggregate frame allocation; this case additionally proves a scalar register interface for the full word.
