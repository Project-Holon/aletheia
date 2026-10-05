/*
 * function: func_021C9530
 * address: 0x021C9530
 * packet: pkt_ov114_021C9530
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * lang: c99
 * status: DIFF
 * 2026-10-05 (wave P11 lane Z1): 26 of 260 bytes differ (compiled 256).
 *   Callees match the ov114 siblings (021C94A0 etc): 021CA470 returns int,
 *   021C9EE4 and 021CA1B4 void, 02092344 returns a pointer. Block (0x3F00,
 *   388 bytes) is its own object; the pair destination 0x3FF8 and the second
 *   buffer 0x4000 are separate pool words, so they are separate externs.
 *   Residue: the original pair copy is ldr ip,[r0]; ldr lr,[dest]; ldr r3,[r0,#4]
 *   with the source in its own pool word 0x4090; this form reads State +0xC
 *   from the shared 0x4084 pool word (one pool word fewer, 4 bytes short) and
 *   allocates r1/ip/r3. With the source as a separate extern (0x4090) the
 *   compiler merges the two loads into ldm (also 256 bytes). Tried with no gain:
 *   Pair struct copy, const source, local Pair, two word locals, pointer
 *   locals, static inline copy helper, u64 copy, pair copy moved before the byte
 *   stores or after the value store, peephole/scheduling/opt_lifetimes/
 *   opt_propagation/opt_common_subs off.
 * symbols:
 *   d_021D3F00 0x021D3F00 data a4
 *   d_021D3FF8 0x021D3FF8 data a4
 *   d_021D4000 0x021D4000 data a4
 *   d_021D4098 0x021D4098 data a4
 *   d_021D4084 0x021D4084 data a4
 *   d_021D3EFC 0x021D3EFC data a4
 *   d_021CF6D4 0x021CF6D4 data a4
 *   d_021CF754 0x021CF754 data a4
 *   func_02092344 0x02092344 arm
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    u32 buf[60];
    u8 first, second, third, gap[5];
    u32 pair[2];
    u32 buf2[32];
    u32 value;
} Block;
typedef struct {
    u32 words[5];
    u8 first, second;
    u8 gap[0x186];
    u32 value;
} State;
extern Block d_021D3F00;
extern u32 d_021D3FF8[], d_021D4000[], d_021D4090[];
extern Block d_021D4098;
extern State d_021D4084;
extern void *d_021D3EFC;
extern unsigned d_021CF6D4[], d_021CF754[];
extern void *func_02092344(void *, const void *, u32);
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C9530(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v)
{
    func_02092344(d_021D3F00.buf, p, 240);
    d_021D3F00.first = a - 1;
    d_021D3F00.second = b - 1;
    d_021D3F00.third = c;
    d_021D3FF8[0] = d_021D4084.words[3];
    d_021D3FF8[1] = d_021D4084.words[4];
    func_02092344(d_021D4000, q, 128);
    d_021D3F00.value = v;
    d_021D4098 = d_021D3F00;
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF754, d_021D4084.words[2], &d_021D4098, 388, 0) == 0) {
        d_021D4084.words[0] = 6;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}
