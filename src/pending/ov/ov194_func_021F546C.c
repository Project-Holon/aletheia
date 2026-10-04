/*
 * function: func_021F546C
 * address:  0x021F546C
 * packet:   pkt_ov194_021F546C
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-04): DIFF, 10 bytes. Listing matches except the prologue schedule: original loads the stack arg first (ldr r1,[sp,#0x18]; adds r7,r0; lsls r1,#10; lsrs r5,r1,#16; adds r6,r3), compiled loads into r0 after adds r7 and uses r0. Count is (n<<10)>>16 (bits 6..21). Tried u16/int/u32 locals, declaration order, for vs while, split shift into two statements.
 *
 * note (2026-10-04, lane17): also tried a bitfield struct parameter (u32 lo:6, cnt:16, hi:10), `(n >> 6) & 0xFFFF` with do/while and for/return forms (worse, 15 bytes), and `u32 i = 0` at declaration. Same 10 bytes: original loads the stack arg into r1 before `adds r7,r0`.
 *
 * symbols:
 *   func_021F5494 0x021F5494 thumb ov194
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F5494(const u16 *a, const u16 *b);
void func_021F546C(const u16 *a, u32 b, u32 c, const u16 *d, u32 n)
{
    u32 i;
    u32 cnt = (n << 10) >> 16;
    for (i = 0; (int)i < (int)cnt; i++) {
        if (func_021F5494(a, d + i * 32) == 1) break;
    }
}
