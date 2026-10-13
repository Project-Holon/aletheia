/*
 * function: FIELD_GIMMICK_CART_LANES_ApplySwitch
 * address:  0x021F4740
 * packet:   pkt_ov039_021F4740
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_CART_LANES_ApplySwitch  0x021F4740  thumb
 *   FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit  0x021F4894  thumb
 *   FIELD_GIMMICK_CART_LANES_SwapCartAnimes  0x021F47D8  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

struct Big;
struct Ctx;
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit(void *p, int i, u8 j);
extern void FIELD_GIMMICK_CART_LANES_SwapCartAnimes(void *a, int f, int i);

void FIELD_GIMMICK_CART_LANES_ApplySwitch(u32 a, void *b)
{
    s8 *p;
    u8 *q;
    u8 *arr;
    u8 v;
    s8 i;

    p = (s8 *)FIELDMAP_GetCommonWork((char *)a, 1);
    q = (u8 *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), 2);
    i = p[5];
    if (i == -1) {
        return;
    }
    arr = q + 0x10;
    v = arr[i];
    arr[i] = (v + 1) % 2;
    if (FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit(b, (u8)i, *((u8 *)p + p[5] + 0x21EC)) != 0) {
        FIELD_GIMMICK_CART_LANES_SwapCartAnimes(b, v, (u8)p[5]);
        i = p[5];
        *((u8 *)p + i + 0x21EC) = i * 2 + *(u8 *)(q + i + 0x10);
    } else {
        u8 *r = (u8 *)p + 0x21E8;

        i = p[5];
        if (r[i] != 0) {
            r[i] = 0;
        } else {
            r[i] = 1;
        }
    }
}
