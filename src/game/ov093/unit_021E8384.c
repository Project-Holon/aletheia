/*
 * file:     unit_021E8384.c
 * unit:     yes
 * function: func_021E8384, func_021E83C0, func_021E83CC, func_021E8440, func_021E8478, func_021E8498, func_021E84B8, func_021E84FC, func_021E85F8, func_021E8624, func_021E8638
 * address:  0x021E8384
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
 *   func_0689C980  0x0689C980  thumb
 *   func_0689C990  0x0689C990  thumb
 *   d_021F2CF0  0x021F2CF0  data  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_EVENT_GetClientReservedChoice  0x021D6E50  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 *   BTLV_CORE_MakeSlotKind2Index 0x021E8940 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtPos 0x021C7D34 thumb ov093
 *   BTL_SERVER_FLOW_AreAllOtherActionsDone  0x021C80AC  thumb  ov093
 *   d_021F2F68     0x021F2F68  data   ov093  a4
 */
#include "../../matched/include/Obj07838.h"
#include "../../matched/include/Obj21548.h"

struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 a; u16 b; int v; } Ent;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_EVENT_GetClientReservedChoice(u8 *p, u8 *id, u16 *value);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern Word BTLV_CORE_MakeSlotKind2Index(int);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern int BTL_SERVER_FLOW_GetPokeIdAtPos(char *p, int i);
extern int BTL_SERVER_FLOW_AreAllOtherActionsDone(u8 *p, int key);
extern int func_0689C980(int b);
extern int func_0689C990(int b);
int func_021E8384(u32 x, u32 y);
int *func_021E83C0(int *p);
void func_021E83CC(void *a, void *b, int c, int *d);
void func_021E8440(int a, void *b, int c, int *d);
void func_021E8478(int a, int b, int c, int *d);
void func_021E8498(int a, int b, int c, int *d);
void func_021E84B8(int a, int b, int c, int *d);
void func_021E84FC(int a, int b, int c, const int *d);
int func_021E85F8(int v);
int func_021E8624(int a, int b);
int func_021E8638(int a, int b);
extern Ent d_021F2CF0[3];
extern int d_021F2F68[];


int func_021E8384(u32 x, u32 y)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        if ((x == d_021F2CF0[i].a && y == d_021F2CF0[i].b) ||
            (y == d_021F2CF0[i].a && x == d_021F2CF0[i].b))
            return d_021F2CF0[i].v;
    }
    return 0;
}


/*
 * Return r0 from func_021EC01C and func_021EA858 is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int *func_021E83C0(int *p)
{
    *p = 6;
    return d_021F2F68;
}


void func_021E83CC(void *a, void *b, int c, int *d)
{
    u16 y;
    u8 x;
    int r;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetClientReservedChoice(BTL_SERVER_FLOW_GetPokeParam(b, c), &x, &y) != 0) {
            r = func_021E8384(BTL_EVENT_GetFactorKey(a), y);
            k = BTL_EVENT_GetVar(0x16);
            if (r != 0) {
                d[1] = r;
                d[0] = 1;
                d[2] = x;
                switch (r) {
                case 1:
                    k = 10;
                    break;
                case 2:
                    k = 9;
                    break;
                case 3:
                    k = 11;
                    break;
                }
                BTL_EVENT_OverwriteVar(0x16, k);
            }
        }
    }
}


void func_021E8440(int a, void *b, int c, int *d)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3) && *d != 0) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(m + 4, 1, 0xbb);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}


void func_021E8478(int a, int b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(2) && *d != 0)
        BTL_EVENT_OverwriteVar(0x51, 1);
}


void func_021E8498(int a, int b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(3) && *d != 0)
        BTL_EVENT_OverwriteVar(0x30, 0x96);
}


void func_021E84B8(int a, int b, int c, int *d)
{
    int k;

    if (c == BTL_EVENT_GetVar(2)) {
        if (d[0] != 0) {
            k = 0;
            switch (d[1]) {
            case 1:
                k = 0x206;
                break;
            case 2:
                k = 0x207;
                break;
            case 3:
                k = 0x208;
                break;
            }
            BTL_EVENT_OverwriteVar(0x13, k);
        }
    }
}


/*
 * lever: byte locals plus declaration order restore the spill/register assignment.
 * permuter: rejected added return target; transferred only declarations and two temporaries.
 */
void func_021E84FC(int a, int b, int c, const int *d)
{
    int tmp;
    u8 *p;
    u8 selected;
    int code;
    u8 own;
    u8 other;
    int target;
    int slot;
    u8 message;
    u8 mode;
    u8 *tmp1;
    if (c == BTL_EVENT_GetVar(3) && d[0] != 0) {
        mode = 14;
        own = BTL_MAIN_IsPokeIdInSecondPair(c);
        other = BTL_MAIN_IsPokeIdInSecondPair((u8)BTL_EVENT_GetVar(6));
        code = 0;
        message = 0;
        target = 31;
        switch (d[1]) {
        case 1:
            message = 0xa4;
            mode = 11;
            selected = own;
            code = 0x28d;
            target = c;
            break;
        case 2:
            message = 0xa8;
            selected = other;
            mode = 12;
            code = 0x28e;
            target = (u8)BTL_EVENT_GetVar(6);
            break;
        case 3:
            message = 0xac;
            selected = other;
            mode = 13;
            code = 0x28f;
            target = (u8)BTL_EVENT_GetVar(6);
            break;
        }
        if (mode != 14) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 25, c);
            ((struct Obj07838 *)p)->f4 = mode;
            p[12] = selected;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2Index(4);
            BTL_SERVER_FLOW_InitMsgRecord(p + 16, 1, message);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 16), selected);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
            if (target != 31) {
                tmp = BTL_SERVER_FLOW_GetPokeIdAtPos((char *)b, target);
                slot = tmp;
                if (slot != 6) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x37, c);
                    p[6] = slot;
                    p[7] = 6;
                    tmp1 = p + 4;
                    ((struct Obj21548 *)tmp1)->f0 = code;
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
        }
    }
}


int func_021E85F8(int v)
{
    u32 i;
    u32 n;

    n = BTL_EVENT_GetVar(5);
    i = 0;
    if (n != 0) {
        do {
            if (v == BTL_EVENT_GetVar(i + 6))
                return 1;
            i++;
        } while (i < n);
    }
    return 0;
}


int func_021E8624(int a, int b)
{
    if (BTL_SERVER_FLOW_AreAllOtherActionsDone((u8 *)a, b) != 0)
        return 1;
    return 0;
}


int func_021E8638(int a, int b)
{
    switch (a) {
    case 0x1e7:
        if (b == 0x70)
            return 1;
        break;
    case 0x1ed:
        if (func_0689C980(b) != 0)
            return 1;
        break;
    case 0x289:
        if (func_0689C990(b) != 0)
            return 1;
        break;
    }
    return 0;
}
