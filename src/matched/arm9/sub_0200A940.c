/*
 * function: IRC_RANKING_FindClosestEntry
 * address:  0x0200A940
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_0200A8AC   0x0200A8AC  thumb
 *   sub_0200A8D0   0x0200A8D0  thumb
 *   sub_0200AA00   0x0200AA00  thumb
 *   GFL_USE_GetRandom   0x020056EC  thumb
 */

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
struct Date;
struct Rec;
extern s32 sub_0200A8AC(struct Rec *r);
extern u8 sub_0200A8D0(struct Rec *r, u32 index);
extern u8 sub_0200AA00(u32 a0, u32 a1, struct Date *src);
extern u32 GFL_USE_GetRandom(u32 range);

int IRC_RANKING_FindClosestEntry(void *a0, int a1, int a2, void *a3)
{
    u32 n = sub_0200A8AC(a0);
    int target = sub_0200AA00(a1, a2, a3);
    int best = 0;
    u32 bestd = 0xffffffffu;
    u32 i;

    for (i = 0; i < n; i++) {
        int d = sub_0200A8D0(a0, i) - target;
        if (d < 0) {
            d = -d;
        }
        if (bestd == d) {
            u32 tmp[2];
            tmp[0] = (u32)best;
            tmp[1] = (u32)i;
            best = (int)tmp[GFL_USE_GetRandom(2)];
        } else if (bestd > d) {
            best = i;
            bestd = d;
        }
    }
    return best;
}
