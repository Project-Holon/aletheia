/*
 * function: BTL_SERVER_FLOW_ProcAfterMemberIn
 * address: 0x021BDA00
 * packet: pkt_ov093_021BDA00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum queue offset declared after the live locals retains r7;
 * cursor declared before out places cursor at sp+8 and out at sp+4.
 * symbols:
 *   func_021BDB28 0x021BDB28 thumb ov093
 *   BTL_SERVER_FLOW_InitFieldPokeIter 0x021BD2B4 thumb ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter 0x021BD34C thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021BDB38 0x021BDB38 thumb ov093
 *   func_021BDB48 0x021BDB48 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMemberInBeginEvent 0x021BDBEC thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021BDB58 0x021BDB58 thumb ov093
 *   func_021BDB68 0x021BDB68 thumb ov093
 *   BTL_SERVER_FLOW_DispatchPokeEntryEvent 0x021BDB88 thumb ov093
 *   func_021BDB78 0x021BDB78 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMemberInEndEvent 0x021BDC0C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor { u8 a, b, c, d; };
enum Offset { queue = 0x1a68 };
extern void func_021BDB28(void *);
extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *p, u8 **q);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *p, u8 **q, u8 **out);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021BDB38(void *, u8 *);
extern void func_021BDB48(void *, u8 *);
extern u32 func_021CC8D8(void *, int);
extern void BTL_SERVER_FLOW_DispatchMemberInBeginEvent(u8 *);
extern int func_021C88E4(u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021BDB58(void *);
extern u8 *func_021BDB68(void *);
extern void BTL_SERVER_FLOW_DispatchPokeEntryEvent(u8 *, u8 *);
extern u8 *func_021BDB78(void *);
extern void BTL_SERVER_FLOW_DispatchMemberInEndEvent(u8 *);
int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *p)
{
    int result = 0;
    struct Cursor cursor;
    u8 *out;
    u32 lock;
    u8 *flag;
    enum Offset q = queue;
    func_021BDB28(p + q);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)(&cursor), (u8 **)p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)(&cursor), (u8 **)p, &out) != 0) {
        flag = p + BTL_POKEPARAM_GetPokeId(out);
        if (flag[0x7c1] != 0) {
            func_021BDB38(p + q, out);
            flag[0x7c1] = 0;
        }
    }
    func_021BDB48(p + q, p);
    lock = func_021CC8D8(p + 0x1d74, 3096);
    BTL_SERVER_FLOW_DispatchMemberInBeginEvent(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 3102);
    func_021BDB58(p + q);
    out = func_021BDB68(p + q);
    while (out != 0) {
        lock = func_021CC8D8(p + 0x1d74, 3108);
        BTL_SERVER_FLOW_DispatchPokeEntryEvent(p, out);
        if (func_021C88E4(p) != 0) result = 1;
        func_021CC95C((u32 *)(p + 0x1d74), lock, 3114);
        out = func_021BDB78(p + q);
    }
    lock = func_021CC8D8(p + 0x1d74, 3117);
    BTL_SERVER_FLOW_DispatchMemberInEndEvent(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 3123);
    return result;
}
