/*
 * function: EVENT_FIELD_PROCLINK_CreateBagParam
 * address: 0x02160FE0
 * packet: pkt_ov010_02160FE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P21): EXACT. Older note draft (60 B off) lacked the repeated
 * default body at the end of case 0 (the `b` to the next block at +0x72 is a cross-jumped
 * copy, see a-branch-to-the-next-case-block-is-a-repeated-case-body.md). Plain literals
 * (4, -1) match; the n local was not needed. Sets the dispatch table via explicit cases
 * 1 and 3..8 beside default.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   EVENT_FIELD_PROCLINK_IsSpecialZone  0x02160FB4  thumb  ov010
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   func_02008298  0x02008298  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct MyItemSave;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *);
extern int EVENT_FIELD_PROCLINK_IsSpecialZone(void *);
struct BigObj;
extern void *BAG_PARAM_Create(const struct BigObj *a0, int a1, int a2, int a3);
extern void func_02008298(struct MyItemSave *, u16);

int *EVENT_FIELD_PROCLINK_CreateBagParam(u8 *a0, int a1, int a2, const int *a3)
{
    int h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)**(int **)(a0 + 0x18));
    int *r;

    switch (a2) {
    case 2:
        r = BAG_PARAM_Create((const struct BigObj *)h, (int)(a0 + 0x34), EVENT_FIELD_PROCLINK_IsSpecialZone((void *)**(int **)(a0 + 0x18)), 4);
        if (a1 != -1) {
            func_02008298((struct MyItemSave *)r[3], (u16)a1);
        }
        break;
    case 0:
        if (a3[16] == 3) {
            r = BAG_PARAM_Create((const struct BigObj *)h, (int)(a0 + 0x34), 2, 4);
        } else {
            r = BAG_PARAM_Create((const struct BigObj *)h, (int)(a0 + 0x34), EVENT_FIELD_PROCLINK_IsSpecialZone((void *)**(int **)(a0 + 0x18)), 4);
        }
        break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        r = BAG_PARAM_Create((const struct BigObj *)h, (int)(a0 + 0x34), EVENT_FIELD_PROCLINK_IsSpecialZone((void *)**(int **)(a0 + 0x18)), 4);
        break;
    }
    return r;
}
