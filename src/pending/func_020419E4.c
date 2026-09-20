/*
 * function: func_020419E4
 * address:  0x020419E4
 * packet:   pkt_020416D4
 * status:   MATCH
 * symbols:
 *   g_BgConfig     0x02146A44  data
 *   func_02041B94  0x02041B94  arm
 *   func_02041A1C  0x02041A1C  arm
 */

typedef unsigned short u16;

struct BgConfigRecord {
    char pad_00[4];
    u16 unk04;
    u16 unk06;
};

extern struct BgConfigRecord *g_BgConfig;

extern void func_02041B94(void);
extern void func_02041A1C(void);

void func_020419E4(void)
{
    if (g_BgConfig == 0) {
        return;
    }

    func_02041B94();
    func_02041A1C();

    g_BgConfig->unk04 = 0;
    g_BgConfig->unk06 = 0;
}
