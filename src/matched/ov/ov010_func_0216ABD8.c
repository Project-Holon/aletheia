/*
 * function: SCRCMD_SYMBOL_StartViewEvent
 * address:  0x0216ABD8
 * packet:   pkt_ov010_0216ABD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_SYMBOL_GetMmdl  0x0216AED0  thumb  ov010
 *   SCRCMD_SYMBOL_CreateObjectPokemon  0x0216AF1C  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_SYMBOL_CreateViewEvent  0x0216AF74  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_SYMBOL_GetMmdl(void *p, u32 id);
extern int SCRCMD_SYMBOL_CreateObjectPokemon();
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc;
extern struct Desc *SCRCMD_SYMBOL_CreateViewEvent(int a0, int a1, int a2, int a3, u16 *a4, u16 a5);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_SYMBOL_StartViewEvent(int a0, int a1)
{
    int buf;
    int *pb;
    int k;
    u16 *p;
    int q;
    void *s;
    void *t;
    void *r;

    pb = &buf;
    k = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    p = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    r = SCRCMD_SYMBOL_GetMmdl((void *)a1, k);
    if (r != 0) {
        q = SCRCMD_SYMBOL_CreateObjectPokemon(a1, r, 4, pb);
        if (q != 0) {
            s = SCRCMD_WORK_GetScriptWork((void *)a1);
            t = SCRCMD_WORK_GetGameSystem((void *)a1);
            SCRIPT_SYS_CallEvent(s, SCRCMD_SYMBOL_CreateViewEvent((int)t, (int)GAMESYSTEM_GetFieldMap((void *)t), q, *pb, p, 4));
        }
    }
    return 1;
}
