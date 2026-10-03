/*
 * function: func_021D6FD8
 * address: 0x021D6FD8
 * packet: pkt_ov120_021D6FD8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B9A0(void *);
extern void func_0204B92C(void *, u32);
void func_021D6FD8(u8 *p, u32 flag)
{
    if (*(void **)(p + 0x140) != 0) {
        func_0204B9A0(*(void **)(p + 0x140));
        func_0204B92C(*(void **)(p + 0x140), flag);
    }
}
