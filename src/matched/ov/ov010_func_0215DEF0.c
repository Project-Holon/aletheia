/*
 * function: SCRCMD_MUSICAL_TaskShowMusicalProc
 * address:  0x0215DEF0
 * packet:   pkt_ov010_0215DEF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   MUSICAL_DRESSUP_SYS_ProcTable     0x02172724  data
 */

typedef unsigned int u32;

typedef struct { u32 f0; } Ctx;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct IcaAnime;
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern const char MUSICAL_DRESSUP_SYS_ProcTable[];

int SCRCMD_MUSICAL_TaskShowMusicalProc(void *a, u32 *st, u32 *c)
{
    void *h = func_020124E4(a);
    GAMESYSTEM_GetGameData(h);
    GAMESYSTEM_GetFieldMap(h);
    switch (*st) {
    case 0:
        (*st)++;
        break;
    case 1:
        (*st)++;
        break;
    case 2:
        (*st)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(h, -1, (void *)MUSICAL_DRESSUP_SYS_ProcTable, (void *)(*c));
        (*st)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(h) != 0)
            break;
        (*st)++;
        break;
    case 5:
        (*st)++;
        break;
    case 6:
        func_020307B0(((void **)*c)[1]);
        func_020307B0((void *)*c);
        return 1;
    }
    return 0;
}
