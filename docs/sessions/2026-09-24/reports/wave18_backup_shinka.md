# Wave 18, lane 18C (backup_shinka)

## 0x0201B2B0 (shinka_check.c, sub_0201B2B0): 12 -> 0, EXACT*
Closed by the heap id's width: seventh parameter `u16 heap` AND
func_02020FE4's third parameter `u16`. With both u32 the gate's
`ldr r2, [sp, #0x68]` is hoisted above the pidHigh spill store (the 12
bytes); u16 on the parameter alone is 1120 bytes, on the prototype alone
1128. The callee masks that argument to 15 bits and ORs 0x8000 (temporary
heap id); unit_02007CB0.c already declares it u16. EXACT* because the listing
extent includes the 12-byte follower unit_0201B70C. 7 measurements.
Filed src/matched/sub_0201B2B0.c; `manifest --verify --shard pkt_0201B038`
run twice (second and third pass: 0 rewritten).

## 0x02031FE0 (backup_system.c, ARM): 9 -> 9, DIFF
17 measurements plus the permuter (anneal, --types, 1500, seed 1801: 9).
Everything on the untried list is flat or worse: dsi/1.2 9; CRC table as
a pointer walk 1712 bytes; CRC hoisted into an int local 9; the accessor
results as one struct 22; the record walk split into a static inline helper
34; `cur + AB` 21; the AB / A copy spellings 9; AB reused for the post-walk
id and the last loop's counter 9; `!= || !=` CRC tests 1700 / 1680 bytes;
u16 heap with a u16 allocator 1700 bytes. AB always takes the group's last
register (r8). The image's loop registers (AB r4, B r8, A r7) equal heap's,
mode's and gen's entry registers. Allocation tie; best source unchanged.

## Files
- src/matched/sub_0201B2B0.c (new)
- layout/matched/arm9/pkt_0201B038.json (manifest verify)
- docs/idioms/a-u16-stack-parameter-passed-to-a-u16-callee-stays-behind-a-spill-store.md (new)
- docs/notes/sub_0201B2B0.c.txt, docs/notes/pkt_02031FE0.c.txt (appended)

## For the integrator
- Wave 17 filed 0x0201FDA0 and 0x02013528 in the same "parameter stack
  load scheduled across a stack store" family. Try u16 on the late parameter
  and on the callee parameter it feeds, both at once, before anything else.
- The shared scratchpad is not lane-private. Another lane overwrote this
  lane's `m.sh` in the middle of the run (its copy passes --thumb by
  default). Lanes should use a subdirectory named after the lane.
- Seeds: none new.
