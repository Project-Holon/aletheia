/*
 * function: BTLV_EFFVM_StartScript
 * address:  0x021F94F8
 * packet:   pkt_ov094_021F94F8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_Start  0x0201127C  thumb
 *   VM_GetUserData  0x02011324  thumb
 *   func_02040588  0x02040588  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   BTLV_EFFECT_GaugeSetSideVisible  0x021F8198  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_EFFECT_SetAllPokeSpriteAnim  0x021F8934  thumb  ov094
 *   BTLV_EFFECT_DeleteTasksByArg  0x021F8A10  thumb  ov094
 *   BTLV_EFFVM_StartSeVolumeTweenTask  0x021FE410  thumb  ov094
 *   BTLV_EFFVM_IsMultiSideResourceId  0x021FEAA0  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_GetSpriteAttrFlags  0x021FFF38  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 w[4];
} Quad;

typedef struct {
    u32 lo : 6;
    u32 b6 : 1;
    u32 b7 : 5;
    u32 b12 : 1;
    u32 b13 : 4;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 rest : 13;
    int f4;
    char pad0[0xdc - 8];
    u32 fdc;            /* 0x0DC */
    u32 fe0;            /* 0x0E0 */
    char pad1[0x1e8 - 0xe4];
    u8 *f1e8;           /* 0x1E8 */
    u8 *f1ec;           /* 0x1EC */
    int f1f0;           /* 0x1F0 */
    char pad2[0x238 - 0x1f4];
    u16 h238;           /* 0x238 */
    char pad3[0x244 - 0x23a];
    int f244;           /* 0x244 */
    Quad q248;          /* 0x248 */
    u16 h258;           /* 0x258 */
    char pad4[2];
    int f25c;           /* 0x25C */
    char pad5[0x2a4 - 0x260];
    u32 f2a4;           /* 0x2A4 */
    u32 f2a8;           /* 0x2A8 */
} T;

struct ScriptVm;
extern void VM_Start(struct ScriptVm *vm, u8 *pc);
extern void *VM_GetUserData(struct ScriptVm *vm);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void BTLV_EFFECT_GaugeSetSideVisible(int a, int b);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_EFFECT_SetAllPokeSpriteAnim(int a);
extern void BTLV_EFFECT_DeleteTasksByArg(int a);
extern void BTLV_EFFVM_StartSeVolumeTweenTask(T *t, int a, int b, int c);
extern int BTLV_EFFVM_IsMultiSideResourceId(int v);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern int BTLV_MCSS_GetSpriteAttrFlags(char *p, int key);

void BTLV_EFFVM_StartScript(void *vm, u32 a1, u32 a2, u16 id, Quad *q)
{
    T *t;
    int off;
    int flag;
    u8 *p;

    t = VM_GetUserData(vm);
    t->f1e8 = 0;
    BTLV_EFFECT_DeleteTasksByArg(1);
    if (q != 0)
        t->q248 = *q;
    else
        MIi_CpuClear16(0, &t->q248, 0x10);
    t->fdc = a1;
    t->fe0 = a2;
    t->f244 = 1;
    t->h258 = id;
    if (t->h258 >= 0x231 && (u16)(t->h258 + 0xFD9F) <= 1
        && t->f2a4 == t->h258 && t->f2a8 == a1)
        return;
    t->f2a4 = t->h258;
    t->f2a8 = a1;
    if (BTLV_EFFVM_IsMultiSideResourceId(t->h258) == 0)
        BTLV_EFFECT_SetAllPokeSpriteAnim(0);
    if (t->h258 < 0x231) {
        t->f1e8 = ARC_TOOL_LoadMember(0x42, id, (u16)((t->h238 & 0x7fff) | 0x8000));
        if (t->h258 != 0x90 && t->h258 != 0x77 && t->h258 != 0x10b)
            BTLV_EFFECT_GaugeSetSideVisible(0, 2);
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        t->b6 = 0;
        BTLV_EFFVM_StartSeVolumeTweenTask(t, 0x7F000, 0x6B000, 0x14);
    } else {
        t->f1e8 = ARC_TOOL_LoadMember(0x43, id - 0x231, (u16)((t->h238 & 0x7fff) | 0x8000));
        t->b6 = 1;
        if (id >= 0x256 && (*(volatile u16 *)0x04000052 & 0x1f) == 0)
            func_02040588(1, 0);
    }
    off = 4;
    if (q != 0) {
        if (*t->f1e8 <= ((u8 *)q)[1])
            ((u8 *)q)[1] = 0;
        off += ((u8 *)q)[1] * 0x38;
    }
    flag = 0;
    if (BTLV_MCSS_IsSpriteLoaded((char *)BTLV_EFFECT_GetMcss(), t->fdc)) {
        if (((t->h258 == 0xf8 || t->h258 == 0x161) && ((u8 *)q)[1] == 1)
            || t->h258 == 0x90 || t->h258 == 0x77 || t->h258 == 0x10b) {
        } else {
            flag = BTLV_MCSS_GetSpriteAttrFlags((char *)BTLV_EFFECT_GetMcss(), t->fdc) & 1;
        }
    }
    if (t->h258 == 0x27e)
        t->b18 = 1;
    if (t->h258 == 0x291)
        t->b18 = 0;
    if (t->h258 == 0x27e && flag) {
        t->f1ec = t->f1e8;
        t->f1f0 = off;
        t->f1e8 = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((t->h238 & 0x7fff) | 0x8000));
        t->b6 = 1;
        t->b17 = 1;
        off = 4;
    } else if (!t->b6 && t->h258 != 0x90 && !t->b17 && flag) {
        t->f1ec = t->f1e8;
        t->f1f0 = off;
        t->f1e8 = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((t->h238 & 0x7fff) | 0x8000));
        t->b6 = 1;
        off = 4;
    }
    p = t->f1e8;
    t->f4 = 0;
    t->b12 = 0;
    t->f25c = 8;
    VM_Start(vm, t->f1e8 + *(int *)(p + off));
}
