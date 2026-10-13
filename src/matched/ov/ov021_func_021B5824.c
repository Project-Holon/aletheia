/*
 * function: SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList
 * address:  0x021B5824
 * packet:   pkt_ov021_021B5824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_02030734  0x02030734  arm
 *   sScrcmdFldBattleFileName     0x021DE248  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char sScrcmdFldBattleFileName[];
extern void *func_0200CA1C(void *a);
struct Blk37;
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

u16 *SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(u8 *a0, void *a1, u16 *a2, int a3)
{
    int i = 0;
    void *r;
    u16 *v;

    *a2 = 0;
    r = func_0200CA1C(a1);
    v = func_02030734((u16)((a3 & 0x7fff) | 0x8000), 0x40, 1, sScrcmdFldBattleFileName, 0xac);
    for (i = 0; i < 0x28b; i++) {
        if (a0[0xa + i / 8] & (1 << (i % 8))) {
            if (func_0200CED4(r, (u16)i)) {
                if (*a2 >= 0x20) {
                    break;
                }
                v[(*a2)++] = i;
            }
        }
    }
    return v;
}
