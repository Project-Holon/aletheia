/*
 * function: INTRUDE_FIELD_IsCommAllowed
 * address:  0x0217BFD8
 * packet:   pkt_ov018_0217BFD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202647C  0x0202647C  thumb
 */

typedef unsigned char  u8;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern unsigned int GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern u32 func_0202648C(void *obj);
extern u32 func_02026454(void *obj);
extern u32 func_0202647C(void *obj);

int INTRUDE_FIELD_IsCommAllowed(const struct Ctx *a, int b)
{
    int h;
    int t;
    int w;

    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    t = GAMESYSTEM_GetGameComm((const struct Ctx *)a);
    w = INTRUDE_COMM_GetWorkIfRunning(t);
    if (GAME_DATA_GetIntrudeCount((const struct BigObj *)h) == 0)
        return 0;
    if (w != 0)
        return 0;
    if (GAMESYSTEM_IsNetOffBySleep(a) == 1)
        return 1;
    if (func_02013D5C(b) == 1) {
        if (func_0202648C((void *)t) != 0)
            return 1;
        return 0;
    }
    if (func_02013D9C(b) == 1) {
        if (func_02026454((void *)t) == 2 || (func_02026454((void *)t) == 0 && func_0202647C((void *)t) == 2 && func_0202648C((void *)t) != 0))
            return 1;
        return 0;
    }
    return 1;
}
