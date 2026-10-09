/*
 * function: func_021C0898
 * address: 0x021C0898
 * packet: pkt_ov093_021C0898
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Explicit u8 cast on wide return preserves the post-call shift pair;
 *   wide last extern argument preserves the full r3 passed without narrowing.
 * symbols:
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021C08CC 0x021C08CC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct UtilWork;
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern void func_021C08CC(u8 *, u8 *, int, u32);
int func_021C0898(u8 *p, u8 *a, u32 b, u32 c)
{
    u32 limit = (u8)(u32)func_021D5584((struct UtilWork *)a, b);
    if (c >= limit) c = limit;
    if (c != 0) {
        func_021C08CC(p, a, b, c);
        return 1;
    }
    return 0;
}
