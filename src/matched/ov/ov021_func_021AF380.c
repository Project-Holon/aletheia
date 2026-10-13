/*
 * function: SCRCMD_PlayPokeVoice
 * address:  0x021AF380
 * packet:   pkt_ov021_021AF380
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_PokeVoiceEvent  0x021AF4E8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u32 f4;
    u32 f8;
} Rec;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *a, void *b, void *c, unsigned int d);
extern void *func_020124E8(struct Obj *p);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern int SCRCMD_PokeVoiceEvent(u32 a, u32 b, Rec *c);

int SCRCMD_PlayPokeVoice(u32 a, u32 b)
{
    u32 u, v, h;
    void *p;
    void *x;
    Rec *r;

    p = SCRCMD_WORK_GetScriptWork((void *)b);
    x = SCRCMD_WORK_GetGameSystem((void *)b);
    u = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    h = (u32)func_020122C0(x, 0, (void *)SCRCMD_PokeVoiceEvent, 12);
    r = func_020124E8((struct Obj *)h);
    r->a = u;
    r->b = v;
    r->f4 = 0;
    r->f8 = b;
    SCRIPT_SYS_CallEvent(p, (void *)h);
    return 1;
}
