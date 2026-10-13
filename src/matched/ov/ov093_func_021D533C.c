/*
 * function: BTL_POKEPARAM_RestoreIfNeeded
 * address: 0x021D533C
 * packet: pkt_ov093_021D533C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent tail: two zero alignment bytes at 021D5362; next code at 021D5364.
 * symbols:
 *   BTL_POKEPARAM_ReloadFromMon 0x021D4EFC thumb ov093
 *   BTL_POKEPARAM_ResetBattleMoves 0x021D5150 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S { void *f00; u8 pad04[0x17]; u8 lo : 5; u8 flag : 1; };
extern void BTL_POKEPARAM_ReloadFromMon(struct S *, void *, u32, u32);
struct Work;
extern void BTL_POKEPARAM_ResetBattleMoves(struct Work *p);
void BTL_POKEPARAM_RestoreIfNeeded(struct S *p)
{
    if (p->flag != 0) {
        BTL_POKEPARAM_ReloadFromMon(p, p->f00, 0, 1);
        BTL_POKEPARAM_ResetBattleMoves((struct Work *)p);
        p->flag = 0;
    }
}
