/*
 * function: SCRIPT_SYS_CallScriptEvent
 * address: 0x02158780
 * packet: pkt_ov010_02158780
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   func_020124E8 0x020124E8 thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   SCRIPT_SYS_CreateScriptEvent 0x02158920 thumb ov010
 */
typedef unsigned short u16;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *func_020124E8(struct Obj *p);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEvent(int a, int b, int c, int d, int e);
int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e)
{
    struct Desc *h = SCRIPT_SYS_CreateScriptEvent((int)GAME_EVENT_GetGameSystem(p), e, b, c, d);
    int *q = func_020124E8((void *)h);
    GAME_EVENT_CallEvent(p, (struct Evt **)((void **)h));
    return *q;
}
