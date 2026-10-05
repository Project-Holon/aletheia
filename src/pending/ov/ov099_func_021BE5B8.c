/*
 * function: func_021BE5B8
 * address:  0x021BE5B8
 * packet:   pkt_ov099_021BE5B8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note: 2026-10-05 (wD5 lane17): still 18 bytes. New test: the 0xB0 offset computed before the second call in a local (int o2 = k + 0xB0; store through p + o2): no change. Image copies the call result into r1 and builds the offset in r0; ours keeps the result in r0.
 *
 * note (2026-10-04): DIFF, 18 bytes, scheduling only. Original after the 0204B034 call does adds r1,r0 ; movs r0,#0x64 ; adds r0,#0xb0 ; str r1,[r5,r0] (value copied to r1, offset in r0); ours keeps the value in r0 and builds the offset in r1. Tried void *, u32 and int result locals and a Pair struct pointer; none changed it.
 *
 * note (2026-10-04, lane17): lane17 wave D2: also tried a struct with fields at 0x110/0x114 (p->a, p->b) and a temp; same 18 bytes. Residue is the copy adds r1,r0,#0 before the 0x114 store.
 *
 * note: 2026-10-05 (wD4 lane20): constant-in-a-local lever applied: int k = 0x64 used as the count argument and in p + k + 0xAC / p + k + 0xB0 (reproduces movs r1,#0x64; adds r1,#0xac and the live r4 = 0x64 for the final load). Remaining 18 bytes: the original copies the second call result with 'adds r1,r0,#0' and builds the 0xB4 offset in r0; ours keeps the result in r0 and the offset in r1. Tried inline store, int/u32/char* result locals, add operand orders, t declared at top, result locals for both calls.
 * symbols:
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   d_021C3740  0x021C3740  data  a4
 *   d_021C375C  0x021C375C  data  a4
 *   d_021C3AA0  0x021C3AA0  data  a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021C3740[];
extern u8 d_021C375C[];
extern u8 d_021C3AA0[];
extern void func_0204A48C(const void *a, const void *b, u32 heap);
extern void *func_0204B100(int count, u32 flag, u32 heap);
extern void *func_0204B034(const void *a, u32 b, u32 heap);
extern void func_0204B258(void *bank);

void func_021BE5B8(char *p)
{
    int k = 0x64;
    func_0204A48C(d_021C3740, d_021C3AA0, 0x21);
    *(void **)(p + k + 0xAC) = func_0204B100(k, 0, 0x21);
    void *t = func_0204B034(d_021C375C, 2, 0x21);
    *(void **)(p + k + 0xB0) = t;
    func_0204B258(*(void **)(p + k + 0xAC));
}
