/*
 * function: FIELD_STATUS_SubProcNoFadeEvent
 * address:  0x02014698
 * packet:   pkt_02014698
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The step function FIELD_STATUS_CreateSubProcNoFadeEvent installs (argsize 0x14, args p[0]..p[4]),
 * one stage per call on *mode.  Closed in wave 13: the earlier goto/label
 * spelling (docs/notes/FIELD_STATUS_SubProcNoFadeEvent.c.txt, one byte out) was the wrong
 * shape.  Written plainly -- every arm carries its own `(*mode)++; break;`
 * and case 2 is `if (poll() == 0) (*mode)++;` -- the compiler cross-jumps
 * the repeated increments itself, and that leaves case 2's tail jump on
 * case 1's `b inc` block exactly as the image has it.
 *
 * symbols:
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 */

typedef unsigned int u32;

struct Ctx;
struct IcaAnime;
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 FIELD_STATUS_SubProcNoFadeEvent(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];

    switch (*mode) {
    case 0:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(a0, args[1]));
        (*mode)++;
        break;
    case 1:
        GAMESYSTEM_CallProc((struct IcaAnime *)a0, args[2], (void *)args[3], (void *)args[4]);
        (*mode)++;
        break;
    case 2:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) == 0) {
            (*mode)++;
        }
        break;
    case 3:
        GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)a0));
        (*mode)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
