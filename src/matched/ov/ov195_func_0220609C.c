/*
 * function: func_0220609C
 * address:  0x0220609C
 * packet:   pkt_0220609C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *
 * 0x02016020 (arm9 Thumb leaf `str r1,[r0,#0x30]; bx lr`) resolves as label
 * since its function_starts seed (2026-09-27). EXACT*: the listing extent
 * includes the 2 bytes of alignment padding at 0x022060BA.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *p, u32 v);
extern void func_02015BF0(void *obj);

void func_0220609C(char *a)
{
    *(u32 *)(a + 0x4c) = (u32)func_02014B08(2, (void *)(*(u16 *)a));
    func_02016020((void *)(*(u32 *)(a + 0x4c)), 0x30000);
    func_02015BF0((void *)(*(u32 *)(a + 0x4c)));
}
