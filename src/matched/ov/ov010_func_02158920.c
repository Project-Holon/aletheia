/*
 * function: SCRIPT_SYS_CreateScriptEvent
 * address:  0x02158920
 * packet:   pkt_ov010_02158920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRIPT_SYS_Create  0x02158804  thumb
 *   SCRIPT_WORK_Create  0x02158E7C  thumb
 *   SCRIPT_WORK_SetTargetObj  0x02158F94  thumb
 *   SCRIPT_SYS_GetZoneId  0x021588D0  thumb
 *   SCRIPT_SYS_AddScript  0x021589A0  thumb
 *   SCRIPT_SYS_EventMain  0x021588DC  thumb
 */

struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
typedef unsigned int   u32;
extern void *SCRIPT_SYS_Create(u32 heap);
typedef unsigned short u16;
extern int *SCRIPT_WORK_Create(u16 a, int b, int c, int d, int e, int f);
extern void SCRIPT_WORK_SetTargetObj(void *p, void *q);
extern int SCRIPT_SYS_GetZoneId(int);
extern int SCRIPT_SYS_AddScript(int a, int b, int c);
extern int SCRIPT_SYS_EventMain(int a0, int a1, int a2);

struct Desc *SCRIPT_SYS_CreateScriptEvent(int a, int b, int c, int d, int e)
{
    struct Desc *h = func_020122C0((void *)a, 0, (void *)SCRIPT_SYS_EventMain, 8);
    void **w = func_020124E8((struct Obj *)h);
    w[1] = SCRIPT_SYS_Create(4);
    w[0] = SCRIPT_WORK_Create(4, a, (int)h, c, e, 0);
    SCRIPT_WORK_SetTargetObj(w[0], (void *)d);
    SCRIPT_SYS_AddScript((int)w[0], SCRIPT_SYS_GetZoneId(a), c);
    return h;
}
