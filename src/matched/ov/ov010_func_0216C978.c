/*
 * function: NAMEIN_SETUP_RunProcCallEvent
 * address:  0x0216C978
 * packet:   pkt_ov010_0216C978
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 */

typedef unsigned int   u32;
struct Ctx;
struct IcaAnime;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern char d_02172548[];

int NAMEIN_SETUP_RunProcCallEvent(int a, int *st, int *o)
{
    int x = o[0];
    int *t;
    switch (*st) {
    case 0:
        t = o + 3;
        o[3] = (int)GAMESYSTEM_GetGameData((const struct Ctx *)x);
        t[1] = o[1];
        t[2] = o[2];
        GAMESYSTEM_CallProc((struct IcaAnime *)x, ~0, d_02172548, t);
        (*st)++;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)x) == 0)
            return 1;
        break;
    }
    return 0;
}
