/*
 * file:     unit_021E75E0.c
 * unit:     yes
 * function: func_021E75E0, func_021E7634, func_021E7760, func_021E781C, func_021E78A4
 * address:  0x021E75E0
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
 *   d_021F257C     0x021F257C  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F28B8     0x021F28B8  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus 0x021C8374 thumb ov093
 *   BTL_SERVER_FLOW_IsPokeGroundedById 0x021C8234 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   BTLV_CORE_MakeSlotKind1Empty 0x021E89C0 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   d_021F274C 0x021F274C data a4
 *   d_021F2714     0x021F2714  data   ov093  a4
 *   BTL_POKEPARAM_GetTypePair   0x021D57FC  thumb ov093
 */
#include "../../matched/include/Obj13543.h"
#include "../../matched/include/Obj02139.h"
#include "../../matched/include/Obj00663.h"
#include "../../matched/include/Obj07237.h"

struct QQ;
struct Unk021D62A8;
struct UtilWork;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *p, int i);
extern int BTL_SERVER_FLOW_IsPokeGroundedById(u8 *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern Word BTLV_CORE_MakeSlotKind1Empty(u32);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
u16 BTL_POKEPARAM_GetTypePair(void *p);
void func_021E75E0(int a, int b, int c);
int *func_021E7628(int *p);
void func_021E7634(int a, int b, int c);
int *func_021E7754(int *p);
void func_021E7760(int a, int b, int c);
int *func_021E7810(int *p);
void func_021E781C(void *a, int b, int c);
extern int d_021F28B8[];
extern int d_021F274C[];
extern int d_021F2714[];


void func_021E75E0(int a, int b, int c)
{
    u8 *p;
    int k, r;

    if (c == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x2e, c);
        p[6] = BTL_EVENT_GetVar(6);
        r = BTL_EVENT_GetFactorKey((void *)a);
        k = 0x1fd;
        if (r == k)
            k += 0x8e;
        else
            k += 0x8f;
        ((struct Obj13543 *)p)->f4 = k;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    }
}


/*
 * The call result is bound to `r` before `k = 0x1fd`: with the constant
 * assigned first it is hoisted above the call into a callee-saved register.
 */
int *func_021E7628(int *p)
{
    *p = 2;
    return d_021F28B8;
}

/*
 * lever: BTLV_CORE_MakeSlotKind1Empty returns a one-word aggregate, reserving its frame temporary.
 */
void func_021E7634(int a, int b, int c)
{
    u8 k;
    void *x;
    int flag;
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        x = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
        flag = 0;
        if (BTL_SERVER_FLOW_IsPokeAfflictedByStatus((u8 *)b, k) == 0) {
            if (BTL_SERVER_FLOW_IsPokeGroundedById((u8 *)b, k) != 0 && BTL_POKEPARAM_HasSick(x, 0x21) == 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 12, c);
                p[15] = k;
                ((struct Obj02139 *)p)->f4 = 0x1f;
                *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Empty(0x1f);
                BTL_SERVER_FLOW_InitMsgRecord(p + 20, 2, 0x468);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 20), k);
                BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                flag = 1;
                if (BTL_POKEPARAM_HasSick(x, 0x1e) != 0) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    ((struct Obj02139 *)p)->f4 = 0x1e;
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
                if (BTL_POKEPARAM_HasSick(x, 0x20) != 0) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    ((struct Obj02139 *)p)->f4 = 0x20;
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
            if (BTL_POKEPARAM_TestContFlag(x, 3) != 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x36, c);
                p[4] = k;
                *(int *)(p + 8) = 3;
                if (flag == 0) {
                    BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x468);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), k);
                }
                BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
            }
        }
    }
}


int *func_021E7754(int *p)
{
    *p = 1;
    return d_021F274C;
}


void func_021E7760(int a, int b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 2;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 4;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 1;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 3;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 5;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    }
}


int *func_021E7810(int *p)
{
    *p = 1;
    return d_021F2714;
}


/*
 * Gate on BTL_EVENT_GetVar(3); the (u8) of BTL_EVENT_GetVar(6) keys BTL_SERVER_FLOW_GetPokeParam,
 * whose result is halfword-stored through BTL_POKEPARAM_GetTypePair in record #0x14.  A
 * second record #4 gets the 4<<22 flag in its header word and the two-string
 * tail (c and the key).
 */
void func_021E781C(void *a, int b, int c)
{
    u8 k;
    void *r;
    u8 *p;

    if (c != BTL_EVENT_GetVar(3))
        return;
    k = (u8)BTL_EVENT_GetVar(6);
    r = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x14, c);
    ((struct Obj07237 *)p)->f6 = c;
    ((struct Obj07237 *)p)->f4 = BTL_POKEPARAM_GetTypePair(r);
    ((struct Obj07237 *)p)->f7 = 1;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    ((struct Obj07237 *)p)->f0 |= 4 << 22;
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x441);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}


extern int d_021F257C[];
int *func_021E78A4(int *p);

int *func_021E78A4(int *p)
{
    *p = 1;
    return d_021F257C;
}
