/*
 * function: func_021BAB04
 * address:  0x021BAB04
 * packet:   pkt_ov070_021BAB04
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocked: every concrete byte matches; the one wildcard is the bl at +0x0E to
 * WAZA_TOOL_GetDamageType, an arm9 unlabelled leaf (the integrator's) between unit_0201C1C8 and
 * unit_0201C1F4 with no label and no matched entry; its other caller
 * (src/pending/ov/ov070_func_021B97E8.c) is itself MATCH on the same leaf.
 * Unblocks once the leaf is filed.
 * blocker:
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb  (arm9; `one --thumb`, no region: EXACT)
 *     extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *     int WAZA_TOOL_GetDamageType(int a) { return func_0201BD28(a, 2); }
 *
 * Levers: a byte-pointer object and the window address bound to a local
 * (win = p + 0x734) before the first statement; that makes 0x734 the pooled
 * constant every other offset (0x6C0, 0x6CC) is derived from.
 *
 * symbols:
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BB6E0  0x021BB6E0  thumb  ov070
 *   func_021BB724  0x021BB724  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Bmp;
struct Descriptor;
struct MsgBank;
struct Obj;
struct WordSet;
extern int WAZA_TOOL_GetDamageType(int a);
extern int WAZA_TOOL_GetType(u16);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
extern u32 func_0201BD28(u16 id, u32 field);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BB6E0(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void func_021BB724(void **p);

void func_021BAB04(u8 *p, int x)
{
    int a;
    int b;
    int c;
    u8 *win;

    win = p + 0x734;

    func_0204B3DC((struct Obj *)(*(int *)(p + WAZA_TOOL_GetDamageType((u16)x) * 4 + 0x6C0)), (int)1);
    func_0204B3DC((struct Obj *)(*(int *)(p + WAZA_TOOL_GetType(x) * 4 + 0x6CC)), (int)1);
    a = (int)WAZA_TOOL_GetMaxPP(x, (int)0);
    b = (int)func_0201BD28(x, (int)3);
    c = (int)func_0201BD28(x, (int)4);
    func_02043AF4(func_02045770((struct Descriptor *)(*(int *)win)), 0xB0, 0, 0x20, 0x28, 0);
    func_02043AF4(func_02045770((struct Descriptor *)(*(int *)win)), 0xE8, 0, 0x18, 0x18, 0);
    if (b <= 1) {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x17, (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x524)), 0xB0, 4, 0x3DC0);
    } else {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x5F, (void *)(*(int *)(p + 0x524)));
        func_0201EFA4((struct WordSet *)(*(int *)(p + 0x520)), (int)0, (int)b, (int)3, (int)0, (int)1);
        func_0201F250((struct WordSet *)(*(int *)(p + 0x520)), (void *)(*(int *)(p + 0x528)), (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x528)), 0xB0, 4, 0x3DC0);
    }
    if (c == 0 || (int)WAZA_TOOL_IsAlwaysHit(x) == 1) {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x17, (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x524)), 0xB0, 0x18, 0x3DC0);
    } else {
        func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x5F, (void *)(*(int *)(p + 0x524)));
        func_0201EFA4((struct WordSet *)(*(int *)(p + 0x520)), (int)0, (int)c, (int)3, (int)0, (int)1);
        func_0201F250((struct WordSet *)(*(int *)(p + 0x520)), (void *)(*(int *)(p + 0x528)), (void *)(*(int *)(p + 0x524)));
        func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x528)), 0xB0, 0x18, 0x3DC0);
    }
    func_02045CAC((struct MsgBank *)(*(int *)(p + 0x51C)), (int)0x5E, (void *)(*(int *)(p + 0x524)));
    func_0201EFA4((struct WordSet *)(*(int *)(p + 0x520)), (int)0, (int)a, (int)2, (int)0, (int)1);
    func_0201F250((struct WordSet *)(*(int *)(p + 0x520)), (void *)(*(int *)(p + 0x528)), (void *)(*(int *)(p + 0x524)));
    func_021BB6E0((int)p, (u32 *)win, (int)(*(int *)(p + 0x528)), 0xE8, 4, 0x3DC0);
    func_021BB724((void **)win);
}
