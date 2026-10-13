/*
 * function: func_02157450
 * address:  0x02157450
 * packet:   pkt_ov010_02157450
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Create the ov010 field-effect task: allocate it with func_0215739C as
 * its callback, pick the direction slot for effect kinds 4..23 (four kinds
 * per effect, the first matching case wins), start the effect object and
 * return the task.
 *
 * symbols:
 *   func_0215739C  0x0215739C  thumb  ov010
 *   func_02157650  0x02157650  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_SetupCommMulti  0x020137F0  thumb
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   func_02034714  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Sub {
    u8 pad00[0x48];
    int f48;            /* 0x48 */
    int f4c;            /* 0x4C */
} Sub;

typedef struct Rec {
    void *f00;          /* 0x00 */
    u8 pad04[0x0C];
    u16 f10;            /* 0x10 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    void *f14;          /* 0x14 */
    Sub f18;            /* 0x18 */
} Rec;

typedef struct Obj {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Obj;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj)];
    Sub *fF8;           /* 0xF8 */
} Work;

extern u8 d_0217277C[];

extern int func_0215739C(void *evt, u32 *state, struct Work *w);
extern void func_02157650(int *p, int v);
struct Ctx;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void BTL_SETUP_SetupCommSingle(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommDouble(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommTriple(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommRotation(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetupCommMulti(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5);
extern void BTL_SETUP_SetParty(void *p, void *src, int i);
struct ZoneData;
extern void BTL_SETUP_ApplyRegulation(u8 *o, void *a1, u32 a2);
extern void BTL_SETUP_AllocRecordBuffer(struct ZoneData *o, u32 heap);
extern void func_02034714(const char *expr, u32 line, const char *file);

void *func_02157450(void *a0, void *a1, u32 kind, Rec *rec)
{
    int dir = 0x29;
    void *task = func_020122C0(a0, 0, func_0215739C, 0xFC);
    Work *w = func_020124E8(task);
    Obj *o;
    void *sys;

    w->f00 = a0;
    w->f04 = a1;
    w->fF8 = &rec->f18;
    o = &w->f08;
    switch (kind) {
    case 5:
        func_02157650(&dir, 0);
    case 4:
        func_02157650(&dir, 2);
    case 7:
        func_02157650(&dir, 1);
    case 6:
        func_02157650(&dir, 3);
        sys = GAMESYSTEM_GetGameData(a0);
        BTL_SETUP_SetupCommSingle((u32)o, (u32)sys, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 9:
        func_02157650(&dir, 4);
    case 8:
        func_02157650(&dir, 6);
    case 11:
        func_02157650(&dir, 5);
    case 10:
        func_02157650(&dir, 7);
        sys = GAMESYSTEM_GetGameData(a0);
        BTL_SETUP_SetupCommDouble((u32)o, (u32)sys, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 13:
        func_02157650(&dir, 8);
    case 12:
        func_02157650(&dir, 10);
    case 15:
        func_02157650(&dir, 9);
    case 14:
        func_02157650(&dir, 11);
        sys = GAMESYSTEM_GetGameData(a0);
        BTL_SETUP_SetupCommTriple((u32)o, (u32)sys, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 17:
        func_02157650(&dir, 12);
    case 16:
        func_02157650(&dir, 14);
    case 19:
        func_02157650(&dir, 13);
    case 18:
        func_02157650(&dir, 15);
        sys = GAMESYSTEM_GetGameData(a0);
        BTL_SETUP_SetupCommRotation((u32)o, (u32)sys, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 21:
        func_02157650(&dir, 16);
    case 20:
        func_02157650(&dir, 18);
    case 23:
        func_02157650(&dir, 17);
    case 22:
        func_02157650(&dir, 19);
        sys = GAMESYSTEM_GetGameData(a0);
        BTL_SETUP_SetupCommMulti((u32)o, (u32)sys, (u32)GFL_NET_HANDLE_GetCurrentHandle(), 1, rec->f12, 4);
        break;
    default:
        func_02034714((const char *)d_0217277C, 0, (const char *)d_0217277C);
        return 0;
    }
    BTL_SETUP_SetParty(o, rec->f00, 0);
    BTL_SETUP_ApplyRegulation((u8 *)o, rec->f14, 4);
    o->f18 = rec->f10;
    w->fF8->f48 = dir;
    w->fF8->f4c = 0;
    BTL_SETUP_AllocRecordBuffer((struct ZoneData *)o, 1);
    return task;
}
