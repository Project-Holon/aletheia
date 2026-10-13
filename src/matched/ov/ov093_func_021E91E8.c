/*
 * function: BTLV_CORE_StepOpeningDemo
 * address:  0x021E91E8
 * packet:   pkt_ov093_021E91E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * symbols:
 *   func_021F745C  0x021F745C  thumb  ov094
 *   func_021F7544  0x021F7544  thumb  ov094
 *   func_021F7C0C  0x021F7C0C  thumb  ov094
 *   func_021F7C2C  0x021F7C2C  thumb  ov094
 *   func_021F7CFC  0x021F7CFC  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F80FC  0x021F80FC  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   func_021E95B4  0x021E95B4  thumb  ov093
 *   func_021E95C4  0x021E95C4  thumb  ov093
 *   func_021E95D4  0x021E95D4  thumb  ov093
 *   func_021E95E4  0x021E95E4  thumb  ov093
 *   func_021E95F4  0x021E95F4  thumb  ov093
 *   func_021E9604  0x021E9604  thumb  ov093
 *   func_021E9614  0x021E9614  thumb  ov093
 *   func_021E9624  0x021E9624  thumb  ov093
 *   BTLV_CORE_GetPokeParamAtViewPos  0x021E9634  thumb  ov093
 *   BTLV_CORE_StartBagMenu  0x021E9D04  thumb  ov093
 *   BTLV_CORE_PollBagMenu  0x021E9E80  thumb  ov093
 *   BTLV_CORE_BuildAndPrintMessage  0x021EA614  thumb  ov093
 *   BTLV_CORE_BuildAndPrintMessageNow  0x021EA65C  thumb  ov093
 *   BTLV_CORE_PrintItemUseMessage  0x021EA6F4  thumb  ov093
 *   BTLV_CORE_WaitMessage  0x021EA710  thumb  ov093
 *   BTLV_CORE_ConsumeMessageFlag  0x021EA720  thumb  ov093
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 *   BTLV_CORE_StartViewEffect262  0x021EA7C8  thumb  ov093
 *   BTLV_CORE_WaitViewEffectDone  0x021EA7E8  thumb  ov093
 *   func_021EAF00  0x021EAF00  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   BTLV_SCU_SetupDisplay  0x021EB028  thumb  ov093
 *   BTLV_SCU_StartEntryScene  0x021EB32C  thumb  ov093
 *   BTLV_SCU_RunProc  0x021EB52C  thumb  ov093
 *   BTLV_SCU_StartWazaEffect  0x021ED118  thumb  ov093
 *   BTLV_SCU_RunWazaProc  0x021ED1B0  thumb  ov093
 *   BTLV_SCU_IsMonDamageAnimDone  0x021ED250  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *
 * note (2026-10-03, wave B3 lane 01): every instruction, branch and pool word
 * matches (972 bytes, jump table included). The verdict is capped by the 8
 * calls to 0x021E95B4/95C4/95D4/95E4/95F4/9604/9614/9624: these are Thumb
 * bx-pc interworking veneers (bx pc; nop; ldr ip,[pc]; bx ip; .word) that the
 * linker placed right after this function. They have no label and no witness
 * outside this range, and C cannot produce them, so no witness file is
 * possible. The trailing star is the same 128 veneer bytes counted in the
 * listing extent (1100 = 972 + 8*16). It becomes EXACT when the Thumb bx-pc
 * veneer class is attested by the tools (out of scope for lanes).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u32 x0;             /* 0x000 */
    u8 pad4[0xA8];
    u32 xAC;            /* 0x0AC */
    u8 padB0[4];
    u32 xB4;            /* 0x0B4 */
    u32 xB8;            /* 0x0B8 */
    u32 xBC;            /* 0x0BC */
    u32 xC0;            /* 0x0C0 */
    u32 xC4;            /* 0x0C4 */
    u8 padC8[0x175 - 0xC8];
    u8 b175;            /* 0x175 */
    u8 pad176[0x17C - 0x176];
    u32 x17C;           /* 0x17C */
    u32 x180;           /* 0x180 */
    u16 h184;           /* 0x184 */
} Obj;

typedef struct Work {
    u32 heap;
    int timer;
} Work;

struct L;
struct MsgBank;
struct Rec;
extern void *func_021F745C(u8 *p, int a, u16 heap);
extern void func_021F7544(u32 a, u32 b, u16 c);
extern u32 func_020307B0(void *p);
extern void BTLV_SCU_SetupDisplay(u8 *p);
extern void func_021E95B4(u32 a);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BTLV_SCU_StartEntryScene(u8 *p, u32 flag);
extern int BTLV_SCU_RunProc(u32 a);
struct H;
struct Pair;
extern u8 *BTLV_CORE_GetPokeParamAtViewPos(struct Pair *s, u32 k);
extern void func_021EAF18(struct L *p, int kind, int id);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *p, u8 v);
extern void BTLV_CORE_BuildAndPrintMessageNow(char *p, struct H *h);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern void func_021E9604(u32 a, u32 b, u8 c, u32 d);
extern int func_021E95C4(u32 a);
extern void func_021E95D4(u32 a, u32 b, u32 c);
extern int func_021E95E4(u32 a);
extern void BTLV_CORE_PrintItemUseMessage(void *p, u8 b, u16 c);
extern void func_021E9624(u32 a);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern int func_021E95F4(u32 a);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern void BTLV_SCU_StartWazaEffect(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f);
extern int BTLV_SCU_RunWazaProc(char *p);
extern int func_021D59B4(u8 *p, int k);
extern int func_0209C0A4(int a, int b);
extern void func_021F80FC(u32 a, u32 b);
extern void func_021F7C2C(int a, int b);
extern void func_021EAF00(u8 *p, int a);
extern int BTLV_SCU_IsMonDamageAnimDone(u32 a);
extern void BTLV_CORE_StartViewEffect262(void *ctx, int a);
extern int BTLV_CORE_WaitViewEffectDone(void *w, int v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);
extern int func_021E9614(u32 a);
extern void BTLV_CORE_StartBagMenu(u8 *p, int x, u8 a, u8 b, u8 c, u8 d);
extern int BTLV_CORE_PollBagMenu(u8 *p);
extern int func_021F7EB4(void);
extern void func_021F7CFC(u32 a, u16 b, u8 c, int d, int e);
extern int BTLV_CORE_ConsumeMessageFlag(u32 *p);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);
extern int GFL_USE_IsBgmPlaying(void);
extern void func_021F7C0C(void);
extern u32 MSGDATA_Delete(struct Rec *rec);

int BTLV_CORE_StepOpeningDemo(Obj *p, int *state, Work *w)
{
    switch (*state) {
    case 0: {
        u32 h = (u32)func_021F745C((u8 *)p->x0, p->x17C, p->h184);
        func_021F7544(h, p->xB4, p->h184);
        func_020307B0((void *)h);
        BTLV_SCU_SetupDisplay((u8 *)p->x17C);
        func_021E95B4(p->x180);
        w->heap = (u32)func_02045B38(0, 2, 0x14, p->h184);
        w->timer = 0;
        (*state)++;
        break;
    }
    case 1:
        BTLV_SCU_StartEntryScene((u8 *)p->x17C, 0);
        (*state)++;
        break;
    case 2:
        if (BTLV_SCU_RunProc(p->x17C)) {
            u8 msg[0x24];
            u8 *v = BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 0);
            func_021EAF18((struct L *)msg, 1, 0x45);
            func_021EAF50((struct L *)msg, BTL_POKEPARAM_GetPokeId(v));
            func_021EAF78(msg, 0);
            BTLV_CORE_BuildAndPrintMessageNow((char *)p, (struct H *)msg);
            (*state)++;
        }
        break;
    case 3:
        p->xBC = (u32)BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 0);
        p->xC0 = BTL_POKEPARAM_GetPokeId((u8 *)p->xBC);
        p->xB8 = 0;
        p->xC4 = 0;
        p->b175 = 0;
        func_021E9604(p->x180, p->xBC, p->b175, 0);
        (*state)++;
        break;
    case 4:
        if (func_021E95C4(p->x180)) {
            func_021E95D4(p->x180, p->xBC, p->xB8);
            (*state)++;
        }
        break;
    case 5:
        if (func_021E95E4(p->x180)) {
            BTLV_CORE_PrintItemUseMessage(p, BTL_POKEPARAM_GetPokeId(BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 0)), 1);
            func_021E9624(p->x180);
            (*state)++;
        }
        break;
    case 6:
        if (BTLV_CORE_WaitMessage((u32 *)p) && func_021E95F4(p->x180)) {
            BTLV_SCU_StartWazaEffect((u8 *)p->x17C, 0, 1, 1, WAZA_TOOL_GetParam(1, 0x1B), 0, 0);
            (*state)++;
        }
        break;
    case 7:
        if (BTLV_SCU_RunWazaProc((char *)p->x17C)) {
            func_021F80FC(1, func_0209C0A4(func_021D59B4(BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 1), 0xE), 6));
            func_021F7C2C(1, 1);
            func_021EAF00((u8 *)p, 0x564);
            (*state)++;
        }
        break;
    case 8:
        if (BTLV_SCU_IsMonDamageAnimDone(p->x17C)) {
            BTLV_CORE_PrintItemUseMessage(p, BTL_POKEPARAM_GetPokeId(BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 1)), 0x2B);
            (*state)++;
        }
        break;
    case 9:
        if (BTLV_CORE_WaitMessage((u32 *)p)) {
            BTLV_SCU_StartWazaEffect((u8 *)p->x17C, 1, 0, 0x2B, WAZA_TOOL_GetParam(0x2B, 0x1B), 0, 0);
            (*state)++;
        }
        break;
    case 10:
        if (BTLV_SCU_RunWazaProc((char *)p->x17C)) {
            BTLV_CORE_StartViewEffect262(p, 0);
            (*state)++;
        }
        break;
    case 11:
        if (BTLV_CORE_WaitViewEffectDone(p, 0)) {
            u8 msg[0x24];
            u8 *v = BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 0);
            func_021EAF18((struct L *)msg, 2, 0x5D);
            func_021EAF50((struct L *)msg, BTL_POKEPARAM_GetPokeId(v));
            func_021EAF78(msg, 0);
            BTLV_CORE_BuildAndPrintMessage((char *)p, (struct H *)msg);
            (*state)++;
        }
        break;
    case 12:
        if (BTLV_CORE_WaitMessage((u32 *)p)) {
            func_02045CAC((struct MsgBank *)w->heap, 0, (void *)p->xAC);
            BTLV_CORE_StartPrintMessage((char *)p, p->xAC, 0, 0);
            w->timer = 0x3C;
            (*state)++;
        }
        break;
    case 13:
        if (BTLV_CORE_WaitMessage((u32 *)p) && --w->timer == 0) {
            func_021E9604(p->x180, p->xBC, p->b175, p->xB8);
            (*state)++;
        }
        break;
    case 14:
        if (func_021E9614(p->x180)) {
            BTLV_CORE_StartBagMenu((u8 *)p, 2, 0, 0, 1, 0);
            (*state)++;
        }
        break;
    case 15:
        if (BTLV_CORE_PollBagMenu((u8 *)p)) {
            func_02045CAC((struct MsgBank *)w->heap, 1, (void *)p->xAC);
            BTLV_CORE_StartPrintMessage((char *)p, p->xAC, 0, 0);
            func_021E9624(p->x180);
            (*state)++;
        }
        break;
    case 16:
        if (BTLV_CORE_WaitMessage((u32 *)p) && !func_021F7EB4()) {
            func_021F7CFC(1, 4, 3, 1, 0);
            (*state)++;
        }
        break;
    case 17:
        if (!func_021F7EB4()) {
            u8 msg[0x24];
            u8 *v = BTLV_CORE_GetPokeParamAtViewPos((struct Pair *)p, 1);
            func_021EAF18((struct L *)msg, 1, 0x41);
            func_021EAF50((struct L *)msg, BTL_POKEPARAM_GetPokeId(v));
            BTLV_CORE_BuildAndPrintMessage((char *)p, (struct H *)msg);
            (*state)++;
        }
        break;
    case 18:
        if (BTLV_CORE_ConsumeMessageFlag((u32 *)p)) {
            GFL_USE_CancelChangeAndPlayBgm(0x518, 0xFFFF);
        }
        if (BTLV_CORE_WaitMessage((u32 *)p)) {
            (*state)++;
        }
        break;
    case 19:
        if (!GFL_USE_IsBgmPlaying()) {
            func_021F7C0C();
            MSGDATA_Delete((struct Rec *)w->heap);
            (*state)++;
        }
        break;
    case 20:
        return 1;
    }
    return 0;
}
