/*
 * function: UNION_MAIN_StartComm
 * address:  0x02173744
 * packet:   pkt_ov012_02173744
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_COMM_Start  0x020263D8  thumb
 *   GAME_BEACON_SEARCH_SetFieldEvent  0x021653C4  thumb  ov010
 *   d_02175610     0x02175610  data   ov012  a1
 *   d_02175614     0x02175614  data   ov012  a1
 */

struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *a);
typedef unsigned char  u8;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern unsigned int func_02026454(void *obj);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Comm;
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);
extern void GAME_BEACON_SEARCH_SetFieldEvent(void);
extern char d_02175610[];
extern char d_02175614[];

void UNION_MAIN_StartComm(int a)
{
    int r5;
    int r7;
    int *p;

    r5 = GAMESYSTEM_GetGameComm((const struct Ctx *)a);
    r7 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    if (func_02026454((void *)r5) != 0) {
        func_02034714(d_02175610, 0, d_02175610);
    }
    p = func_02030734(5, 0x10, 1, d_02175614, 0x37);
    p[0] = (int)GAME_DATA_GetMyStatus((void *)r7);
    p[1] = r5;
    p[2] = r7;
    p[3] = a;
    GAME_COMM_Start((struct Comm *)r5, 3, (u32)p);
    GAME_BEACON_SEARCH_SetFieldEvent();
}
