/*
 * function: func_021F9140
 * address: 0x021F9140
 * packet: pkt_ov132_021F9140
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A380 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0204A380(u32, u32, u32, u16);
extern void *func_021FAD0C(void *, void *, int, u8);
void func_021F9140(u8 *p, u32 n, int i)
{
    void *table;
    u16 score;
    table = func_0204A380(*(u32 *)(p + 0x18), n + 0x37, 0, *(u16 *)p);
    score = *(u16 *)(*(u8 **)(*(u8 **)(p + 0x30) + i * 4 + 4) + 0x4a);
    if (score >= 70) {
        func_021FAD0C(*(void **)(p + 0xb0), table, 0, (u8)(1 << i));
    } else if (score >= 40) {
        func_021FAD0C(*(void **)(p + 0xb0), table, 1, (u8)(1 << i));
    } else {
        func_021FAD0C(*(void **)(p + 0xb0), table, 2, (u8)(1 << i));
    }
}
