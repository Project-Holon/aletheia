/*
 * file:     unit_021E7E58.c
 * unit:     yes
 * function: func_021E7E58, func_021E7F10, func_021E7F1C, func_021E7F6C, func_021E7FA8, func_021E7FB4, func_021E7FE4, func_021E8070, func_021E80C0, func_021E8104, func_021E814C, func_021E8184
 * address:  0x021E7E58
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
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_SERVER_FLOW_GetClientIdBySide  0x021C8300  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 *   BTL_MAIN_IsBackRowPos  0x021B99F0  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F29A8     0x021F29A8  data   ov093  a4
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById  0x021C846C  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_ReleaseBindingTargetById  0x021C8494  thumb  ov093
 *   BTL_SERVER_FLOW_IsPokeInPosTable  0x021C814C  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   d_021F2F98     0x021F2F98  data   ov093  a4
 *   d_021F281C     0x021F281C  data   ov093  a4
 */
struct S;
struct QF;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern int BTL_SERVER_FLOW_GetRule(int *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u32 BTL_SERVER_FLOW_GetClientIdBySide(int *p, u8 k);
extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);
extern u32 BTL_MAIN_IsBackRowPos(u32 x);
extern int BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(void *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(u8 *p, int a, int b, int *out);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern void BTL_SERVER_FLOW_ReleaseBindingTargetById(u8 *p, int i);
extern int BTL_SERVER_FLOW_IsPokeInPosTable(u8 *p, u8 v);
extern int BTL_POKEPARAM_HasType(void *a, int b);
void func_021E7E58(int a, u8 *b, int c);
int *func_021E7F10(int *p);
void func_021E7F1C(int a, void *b, int c);
void func_021E7F6C(int a, int b, int c);
int *func_021E7FA8(int *p);
void func_021E7FB4(int a, int b, int c);
void func_021E7FE4(int a, u8 *b, int c);
void func_021E8070(int a, void *b, int c);
void func_021E80C0(int a, void *b, int c);
void func_021E8104(int a, void *b, int c);
void func_021E814C(int a, void *b, int c);
int *func_021E8184(int *p);
extern int d_021F29A8[];
extern int d_021F2F98[];
extern int d_021F281C[];



void func_021E7E58(int a, u8 *b, int c)
{
    int x, y;
    u32 k;
    u8 *p;

    x = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
    y = c;
    switch (BTL_SERVER_FLOW_GetRule((int *)b)) {
    case 1:
        if (BTL_SERVER_FLOW_GetClientIdBySide((int *)b, BTL_MAIN_PokeIdToClientIdThunk(c)) == 4) {
            k = BTL_MAIN_GetOwnLanePos(x, 0);
            if (k == x)
                k = BTL_MAIN_GetOwnLanePos(x, 1);
            y = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, k);
        }
        break;
    case 2:
        if (BTL_MAIN_IsBackRowPos(x) == 0) {
            k = BTL_MAIN_GetOwnLanePos(x, 0);
            if (k == x)
                k = BTL_MAIN_GetOwnLanePos(x, 2);
            y = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, k);
        }
        break;
    }
    if (y != c) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x32, c);
        p[4] = c;
        p[5] = y;
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 1137);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), y);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}



int *func_021E7F10(int *p)
{
    *p = 2;
    return d_021F29A8;
}



void func_021E7F1C(int a, void *b, int c)
{
    void *m;
    int r;
    if (c == BTL_EVENT_GetVar(3)) {
        u8 k = BTL_EVENT_GetVar(4);
        m = BTL_SERVER_FLOW_GetPokeParam(b, k);
        r = BTL_POKEPARAM_GetSpecies(m);
        if (r == 0x32 || r == 0x33 || BTL_POKEPARAM_HasSick(m, 0x1f) != 0
            || BTL_POKEPARAM_HasSick(m, 0x15) != 0)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}




void func_021E7F6C(int a, int b, int c)
{
    void *m;
    if (c == BTL_EVENT_GetVar(3)) {
        m = (void *)BTL_EVENT_GetVar(0x3f);
        BTL_EVENT_OverwriteVar(0x1d, 0x20);
        BTL_SERVER_FLOW_InitMsgRecord(m, 2, 1140);
        BTL_SERVER_FLOW_AppendMsgRecordArg(m, BTL_EVENT_GetVar(4));
    }
}


int *func_021E7FA8(int *p)
{
    *p = 6;
    return d_021F2F98;
}


void func_021E7FB4(int a, int b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        if (k != 0x1f && BTL_MAIN_IsPokeSamePair(c, k) != 0)
            BTL_EVENT_OverwriteVar(0x41, 1);
    }
}




void func_021E7FE4(int a, u8 *b, int c)
{
    u8 k;
    int x;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        x = 0;
        if (k == 0x1f || BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(b, c, k, &x) == 0) {
            BTL_EVENT_OverwriteVar(0x41, 1);
            if (x != 0)
                BTL_EVENT_OverwriteVar(0x4f, 1);
        } else if (BTL_EVENT_OverwriteVar(0x51, 1) != 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 1118);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
}




void func_021E8070(int a, void *b, int c)
{
    u8 v, t;
    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t == 0x1f || BTL_SERVER_FLOW_GetFrontPosOfPoke(b, t) == 6)
            BTL_EVENT_OverwriteVar(0x41, 1);
        BTL_SERVER_FLOW_ReleaseBindingTargetById(b, c);
    }
}




void func_021E80C0(int a, void *b, int c)
{
    u8 v, t;
    if (BTL_SERVER_FLOW_GetRule(b) != 0 && BTL_SERVER_FLOW_GetRule(b) != 3) {
        v = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t != 0x1f)
            BTL_EVENT_OverwriteVar(4, t);
    }
}




void func_021E8104(int a, void *b, int c)
{
    u8 v, t;
    if (c == BTL_EVENT_GetVar(2)) {
        v = BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t != 0x1f && BTL_SERVER_FLOW_IsPokeInPosTable(b, t) == 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}




void func_021E814C(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_HasType(BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(4)), 2) != 0)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}


int *func_021E8184(int *p)
{
    *p = 1;
    return d_021F281C;
}
