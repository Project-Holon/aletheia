/*
 * function: INTRUDE_FIELD_StartComm
 * address:  0x0217BA54
 * packet:   pkt_ov018_0217BA54
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02030734  0x02030734  arm
 *   GAME_COMM_Start  0x020263D8  thumb
 *   INTRUDE_FIELD_gStartParamFile     0x02183AE0  data   a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f00;
    int f04;
    int pad;
    u16 pad2;
    u8 f0e;
} Rec;

typedef unsigned int   u32;
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 func_0200FB24(void);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern int func_02035390(void);
extern int func_020353B0(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Comm;
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);
extern const char INTRUDE_FIELD_gStartParamFile[];

void INTRUDE_FIELD_StartComm(void *a)
{
    int h;
    Rec *r;

    h = GAMESYSTEM_GetGameComm(a);
    if (func_0200FB24() != 0)
        return;
    if (GAMESYSTEM_IsNetOffBySleep(a) == 1)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    r = func_02030734(0x8005, 0x10, 1, INTRUDE_FIELD_gStartParamFile, 0x528);
    r->f0e = 1;
    r->f00 = (int)a;
    r->f04 = h;
    GAME_COMM_Start((struct Comm *)h, 2, (u32)r);
}
