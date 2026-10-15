/*
 * function: B_BAG_MAIN_BuildPocketLists
 * address: 0x0220BA2C
 * packet: pkt_ov197_0220BA2C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD9r lane05): EXACT. The record address is an integer local reused for the row offset:
 *   `u32 e = c * 0x90; e = q[0x535] * 4 + (u32)(p + e);`. The mul stays first (e is defined in its own
 *   statement and used once more), and idx*4 is the first operand of the final add, so e shares idx*4's
 *   register (r0) and row takes r4 as in the original.
 * symbols:
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_020081DC 0x020081DC thumb
 *   func_020307B0 0x020307B0 arm
 *   d_0220DB3C 0x0220DB3C data a4
 *   d_0220DB3F 0x0220DB3F data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Item;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern struct Item *func_020081DC(u8 *base, u32 id, u32 index);
extern u32 func_020307B0(void *p);
extern const u8 d_0220DB3C[];
extern const u8 d_0220DB3F[];

void B_BAG_MAIN_BuildPocketLists(u8 *p)
{
    u8 *tbl;
    u16 *r;
    u32 i, j, k;

    tbl = ARC_TOOL_LoadMember(0xE8, 0, *(u16 *)(*(u8 **)p + 0xC));
    i = 0;
    do {
        j = 0;
        for (;;) {
            r = (u16 *)func_020081DC(**(void ***)p, d_0220DB3C[i], (u16)j);
            if (r == 0)
                break;
            if (r[0] != 0 && r[1] != 0) {
                u32 m = tbl[r[0]];
                for (k = 0; k < 4; k++) {
                    if (m & (1 << k)) {
                        int c = d_0220DB3F[k];
                        u8 *q = p + c;
                        u32 e = c * 0x90;
                        e = q[0x535] * 4 + (u32)(p + e);
                        *(u16 *)(e + 0x150) = r[0];
                        *(u16 *)(e + 0x152) = r[1];
                        q[0x535]++;
                    }
                }
            }
            j++;
        }
        i++;
    } while (i < 3);
    func_020307B0(tbl);
    for (i = 0; i < 4; i++) {
        u8 v = p[i + 0x535];
        u8 *s;
        if (v == 0)
            p[i + 0x539] = 0;
        else
            p[i + 0x539] = (v - 1) / 6;
        s = *(u8 **)p + i * 2;
        if (p[i + 0x539] < *(s16 *)(s + 0x38))
            *(s16 *)(s + 0x38) = p[i + 0x539];
    }
}
