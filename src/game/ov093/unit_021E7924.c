/*
 * file:     unit_021E7924.c
 * unit:     yes
 * function: func_021E7924, func_021E7950, func_021E795C, func_021E7974, func_021E798C, func_021E7998, func_021E7A08, func_021E7A78
 * address:  0x021E7924
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2998     0x021F2998  data   ov093  a4
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F2684     0x021F2684  data   ov093  a4
 *   d_021F265C     0x021F265C  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeIdAtPos 0x021C7D34 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   d_021F2634 0x021F2634 data a4
 *   d_021F269C     0x021F269C  data   ov093  a4
 */
#include "../../matched/include/Obj13545.h"
#include "../../matched/include/Obj13546.h"
#include "../../matched/include/Obj10101.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern Word BTLV_CORE_MakeSlotKind2Index(int k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_SERVER_FLOW_GetPokeIdAtPos(char *p, int i);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *, int, u8 *);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
void func_021E7924(int a, int b, int c);
int *func_021E7950(int *p);
void func_021E795C(int a, int b, int c);
void func_021E7974(int a, int b, int c);
int *func_021E798C(int *p);
void func_021E7998(int a, int b, int c);
int *func_021E79FC(int *p);
void func_021E7A08(int a, int b, int c);
int *func_021E7A6C(int *p);
void func_021E7A78(int a, int b, int c);
int *func_021E7B34(int *p);
/* 021E795C  shape F1: gate on BTL_EVENT_GetVar(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E7972; movs r0, #0x51; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
extern int d_021F2998[];
extern int d_021F2684[];
extern int d_021F265C[];
extern int d_021F2634[];
/*
 * BTLV_CORE_MakeSlotKind2Index returns a one-word struct: that is the `push {r3,..}; sub sp, #4`
 * frame word (docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
extern int d_021F269C[];



void func_021E7924(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x3c) == 0xb)
        BTL_EVENT_OverwriteVar(0x3d, BTL_EVENT_GetVar(0x3d) + 1);
}



int *func_021E7950(int *p)
{
    *p = 2;
    return d_021F2998;
}



void func_021E795C(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x51, 1);
}




/* 021E7974  shape F1: gate on BTL_EVENT_GetVar(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E798A; movs r0, #0x4b; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void func_021E7974(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x4b, 1);
}


int *func_021E798C(int *p)
{
    *p = 1;
    return d_021F269C;
}


void func_021E7998(int a, int b, int c)
{
    int k;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        k = 6;
        if (BTL_FIELD_GetStaticSlotObject(k) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x1b, c);
            ((struct Obj13545 *)p)->f4 = k;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2Index(5);
            BTL_SERVER_FLOW_InitMsgRecord(p + 0x10, 1, 0xb2);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        } else {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x1c, c);
            ((struct Obj13545 *)p)->f4 = k;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        }
    }
}



int *func_021E79FC(int *p)
{
    *p = 1;
    return d_021F2684;
}



void func_021E7A08(int a, int b, int c)
{
    int k;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        k = 7;
        if (BTL_FIELD_GetStaticSlotObject(k) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x1b, c);
            ((struct Obj13546 *)p)->f4 = k;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2Index(5);
            BTL_SERVER_FLOW_InitMsgRecord(p + 0x10, 1, 0xb4);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        } else {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x1c, c);
            ((struct Obj13546 *)p)->f4 = k;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        }
    }
}



int *func_021E7A6C(int *p)
{
    *p = 1;
    return d_021F265C;
}



/*
 * lever: the byte-valued count remains u8; +7 is a one-bit field assignment.
 */
void func_021E7A78(int a, int b, int c)
{
    u8 list[4];
    u8 k, i;
    u8 n;
    int slot;
    u8 *x;
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        slot = BTL_SERVER_FLOW_GetPokeIdAtPos((char *)b, k);
        if (slot != 6) {
            n = BTL_SERVER_FLOW_CollectAlivePokeIds((int *)b, (u16)(0x900 | slot), list);
            for (i = 0; i < n; i++) {
                if (list[i] != k) {
                    x = BTL_SERVER_FLOW_GetPokeParam((int *)b, list[i]);
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 7, c);
                    p[6] = list[i];
                    ((struct Obj10101 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(x, 16);
                    ((struct Flag { u8 bit : 1; } *)(p + 7))->bit = 1;
                    BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x451);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), p[6]);
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
        }
    }
}



int *func_021E7B34(int *p)
{
    *p = 1;
    return d_021F2634;
}
