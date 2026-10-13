/*
 * function: SCRIPT_SYS_CreateVm
 * address:  0x02158BFC
 * packet:   pkt_ov010_02158BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_IsChildScript  0x02158DB0  thumb  ov010
 *   SCRCMD_WORK_Create  0x0215A55C  thumb  ov010
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 *   SCRIPT_SYS_GetScriptFileId  0x02158CD0  thumb  ov010
 *   SCRIPT_SYS_LoadScriptFile  0x02158D78  thumb  ov010
 *   SCRCMD_WORK_LoadMsgData  0x0215A760  thumb  ov010
 *   VM_Start  0x0201127C  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   SCRIPT_SYS_SetCommandCheck  0x02158E38  thumb  ov010
 *   d_0217062C     0x0217062C  data  ov010
 *   d_021705D8     0x021705D8  data  ov010
 */

typedef unsigned short u16;

struct V { u16 x, y; int a; int b; int c; };
struct W { u16 w, h; int p; int q; };

extern int SCRIPT_SYS_IsChildScript(int);
extern int SCRCMD_WORK_Create(const struct V *, int);
typedef unsigned int   u32;
struct ScriptVm;
struct ScriptVmParams;
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
typedef unsigned char  u8;
struct ScriptVm;
extern void VM_Init(struct ScriptVm *vm, void *user);
extern u16 SCRIPT_SYS_GetScriptFileId(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3);
extern void *SCRIPT_SYS_LoadScriptFile(int a, int b);
extern void SCRCMD_WORK_LoadMsgData(u8 *a, unsigned b, unsigned c);
extern void VM_Start(struct ScriptVm *vm, u8 *pc);
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void SCRIPT_SYS_SetCommandCheck(void *a);
extern int d_0217062C;
extern int d_021705D8;

int *SCRIPT_SYS_CreateVm(u16 a0, int a1, u16 a2, u16 a3, int a4)
{
    struct V v;
    struct W w;
    u16 s[4];
    int r6, t, n;
    int *o;

    r6 = SCRIPT_SYS_IsChildScript(a4);
    v.x = a2;
    v.y = a3;
    v.a = a4;
    v.b = r6;
    v.c = a1;
    t = SCRCMD_WORK_Create(&v, a0);
    w.w = 0x100;
    w.h = 0x40;
    w.p = (int)&d_0217062C;
    w.q = d_021705D8;
    o = (int *)VM_Create(a0, (const struct ScriptVmParams *)(&w));
    VM_Init((struct ScriptVm *)o, (void *)t);
    n = SCRIPT_SYS_GetScriptFileId(a2, a3, &s[2], &s[1], &s[0]);
    o[0x2C / 4] = (int)SCRIPT_SYS_LoadScriptFile(s[2], a0);
    if (r6 == 0) {
        if (s[0] != -1)
            SCRCMD_WORK_LoadMsgData((u8 *)t, s[1], s[0]);
    }
    VM_Start((struct ScriptVm *)o, (u8 *)o[0x2C / 4]);
    o[0x14 / 4] += n << 2;
    o[0x14 / 4] += VM_GetU32((struct Cursor *)o);
    SCRIPT_SYS_SetCommandCheck(o);
    return o;
}
