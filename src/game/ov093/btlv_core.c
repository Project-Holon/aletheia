/*
 * file:     btlv_core.c
 * unit:     yes
 * function: BTLV_CORE_CheckPartySlotPair, BTLV_CORE_CheckPartySlotCondition, BTLV_CORE_CheckEitherSlotPair, BTLV_CORE_EventRedirectMove, BTLV_CORE_EventCounterMove, BTLV_CORE_EventQueueMoveNotice, BTLV_CORE_EventScaleDamage, BTLV_CORE_EventSetFlagIfAttacker, BTLV_CORE_EventTrySetFlagIfAttacker, BTLV_CORE_LoadDsiOverlay, BTLV_CORE_UnloadDsiOverlay, BTLV_CORE_GetZeroMasked, BTLV_CORE_IsSlotKindNone, BTLV_CORE_MakeSlotKind2Index, BTLV_CORE_MakeSlotKind2, BTLV_CORE_MakeSlotKind3, BTLV_CORE_MakeSlotKind1Empty, BTLV_CORE_MakeSlotKind1Value, BTLV_CORE_MakeSlotKind1, BTLV_CORE_MakeSlotKind4, BTLV_CORE_MakeSlotKind1Index15, BTLV_CORE_IsSlotKind1Index15, BTLV_CORE_GetSlotPosition, BTLV_CORE_SetSlotPosition, BTLV_CORE_GetSlotLow, BTLV_CORE_SetSlotValue, BTLV_CORE_GetSlotValue, BTLV_CORE_SetSlotFlag, BTLV_CORE_GetSlotFlag, BTLV_CORE_AddSlotIndex, BTLV_CORE_SetSlotIndex, BTLV_CORE_PackBytes, BTLV_CORE_PackByteTwice, BTLV_CORE_GetHighByte, BTLV_CORE_GetLowByte, BTLV_CORE_SplitBytes, BTLV_CORE_HasByte, BTLV_CORE_BytesOverlap, BTLV_CORE_BytesEqual, BTLV_CORE_LoadOverlays, BTLV_CORE_UnloadOverlays, BTLV_CORE_ResetDisplay, BTLV_CORE_InitDisplay, BTLV_CORE_ExitDisplay, BTLV_CORE_Create
 * address:  0x021E869C
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
 *   func_06899AF0  0x06899AF0  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   func_021E8638  0x021E8638  thumb  ov093
 *   func_021C8168  0x021C8168  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8434  0x021C8434  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   OS_GetConsoleType  0x02085CBC  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   gBtlvCoreDsiOverlayLoaded  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_0208068C  0x0208068C  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   gBtlvCoreVramBanks 0x021F387C data a4
 *   gBtlvCoreDispConfig 0x021F3850 data a4
 *   gBtlvCoreBgConfig 0x021F3860 data a4
 *   func_021F7808  0x021F7808  thumb  ov094
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   func_02030734 0x02030734 arm
 *   func_021D3D70 0x021D3D70 thumb ov093
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   BTLV_SCU_Create 0x021EAF7C thumb ov093
 *   BTL_MSG_Init 0x021EEC78 thumb ov093
 *   gBtlvCoreFileName 0x021F3AC4 data a4
 */
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct QF;
struct QI;
struct UtilWork;
struct DispConfig;
struct DispVram;
struct Cfg;
struct GfFont;
struct Tcbl;
struct U16Vec;

/*
 * One packed battle slot word.  Bits 0..2 hold the kind (1..4); the rest of
 * the word depends on the kind, so each accessor reads the variant it needs.
 * The constructors below zero the word and fill one variant.
 */
typedef union BtlvSlot {
    s32 word;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 extra : 17; } pos;
    struct { u32 kind : 3; u32 index : 6; u32 value : 16; u32 extra : 7; } param;
    struct { u32 kind : 3; u32 skip : 12; u32 value : 16; u32 extra : 1; } wideParam;
    struct { u32 kind : 3; u32 skip : 22; u32 flag : 1; u32 extra : 6; } flagMid;
    struct { u32 kind : 3; u32 skip : 28; u32 flag : 1; } flagHigh;
    struct { u32 kind : 3; u32 index : 6; u32 extra : 23; } indexOnly;
} BtlvSlot;

/* Event record from func_021C88A4: a 4-byte header, then a list. */
struct BtlvEventRec {
    u32 header;
    u8 list[];
};

/* Work area of the battle view core (0x188 bytes). */
struct BtlvCore {
    void *mainWork;
    void *netCtx;
    u32 mainRegion;
    u8 clientIndex, padAfterIndex[3];
    int state, counterA, counterB;
    u8 padAfterCounters[0x90];
    void *msgBuffer, *fontMain, *fontSub;
    u8 padAfterFonts[0xbc];
    u8 busy, padAfterBusy[3];
    void *taskList, *sceneUnit, *auxView;
    u16 heapId;
    u8 padTail[2];
};

extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int func_021E8638(int a, int b);
extern int func_021C8168(void *p);
extern u8 func_021B8DDC(u32 x);
extern int BTL_EVENT_GetVar(int key);
extern int func_021B9A24(u32 a, u32 b);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C8434(u8 *p, int a, int b);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u32 OS_GetConsoleType(void);
extern int GF_OVERLAY_Load(const void *overlayId);
extern void GF_OVERLAY_Unload(const void *overlayId);
extern int func_02034AC4(const void *overlayId);
extern void func_0208068C(unsigned int v);
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void func_02034A5C(const void *overlayId);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void G3D_SYSTEM_Init(u32, u32, u32, u32, u16, u16, void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void G3X_SetFog(int, int, int, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void CLACT_InitSystem(const struct Cfg *cfg, const struct DispVram *vram, u32 heapId);
extern void func_021F7808(void);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void G3D_SYSTEM_Exit(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_021D3D70(u8 *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *BTLV_SCU_Create(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap);
extern void *func_06899AF0(struct BtlvCore *, void *, u32, void *, void *, void *, int, u16);
extern void BTL_MSG_Init(u32, u32, u32, u32);
int BTLV_CORE_CheckPartySlotPair(void *party, int slot);
int BTLV_CORE_CheckPartySlotCondition(void *party, int slot);
int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB);
void BTLV_CORE_EventRedirectMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);
void BTLV_CORE_EventCounterMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);
void BTLV_CORE_EventQueueMoveNotice(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);
void BTLV_CORE_EventScaleDamage(int factor);
void BTLV_CORE_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2);
int BTLV_CORE_EventTrySetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId);
void BTLV_CORE_LoadDsiOverlay(void);
void BTLV_CORE_UnloadDsiOverlay(void);
u32 BTLV_CORE_GetZeroMasked(void);
int BTLV_CORE_IsSlotKindNone(BtlvSlot slot);
int BTLV_CORE_MakeSlotKind2Index(u32 index);
int BTLV_CORE_MakeSlotKind2(u32 index, u32 value);
int BTLV_CORE_MakeSlotKind3(u32 index);
int BTLV_CORE_MakeSlotKind1Empty(void);
int BTLV_CORE_MakeSlotKind1Value(u32 value);
int BTLV_CORE_MakeSlotKind1(u32 index, u32 value);
int BTLV_CORE_MakeSlotKind4(u32 hi, u32 lo);
int BTLV_CORE_MakeSlotKind1Index15(void);
int BTLV_CORE_IsSlotKind1Index15(BtlvSlot slot);
u8 BTLV_CORE_GetSlotPosition(BtlvSlot slot);
void BTLV_CORE_SetSlotPosition(BtlvSlot *slot, u8 pos);
u8 BTLV_CORE_GetSlotLow(BtlvSlot slot);
void BTLV_CORE_SetSlotValue(BtlvSlot *slot, u16 value);
u16 BTLV_CORE_GetSlotValue(BtlvSlot slot);
void BTLV_CORE_SetSlotFlag(BtlvSlot *slot, int flag);
u32 BTLV_CORE_GetSlotFlag(BtlvSlot slot);
void BTLV_CORE_AddSlotIndex(BtlvSlot *slot, u32 delta);
void BTLV_CORE_SetSlotIndex(BtlvSlot *slot, int count);
u16 BTLV_CORE_PackBytes(u32 high, u32 low);
int BTLV_CORE_PackByteTwice(int byte);
u8 BTLV_CORE_GetHighByte(s32 word);
int BTLV_CORE_GetLowByte(int word);
void BTLV_CORE_SplitBytes(int word, unsigned char *high, unsigned char *low);
int BTLV_CORE_HasByte(int word, int byte);
int BTLV_CORE_BytesOverlap(int wordA, int wordB);
int BTLV_CORE_BytesEqual(int word);
void BTLV_CORE_LoadOverlays(unsigned short heapId);
void BTLV_CORE_UnloadOverlays(void);
void BTLV_CORE_ResetDisplay(u16 heapId);
void BTLV_CORE_InitDisplay(u16 heapId);
void BTLV_CORE_ExitDisplay(void);
struct BtlvCore *BTLV_CORE_Create(void *mainWork, void *netCtx, u32 mainRegion, int param, u16 heapId);
extern u8 ov140_id[];
extern int gBtlvCoreDsiOverlayLoaded;
extern char ov094_id[], ov095_id[], ov096_id[];
extern const struct DispVram gBtlvCoreVramBanks;
extern struct DispConfig gBtlvCoreDispConfig;
extern const struct Cfg gBtlvCoreBgConfig;
extern const char gBtlvCoreFileName[];


int BTLV_CORE_CheckPartySlotPair(void *party, int slot)
{
    void *entry;
    int typeId;
    u16 level;

    entry = func_021C7CF4(party, slot);
    typeId = BTL_POKEPARAM_GetSpecies(entry);
    level = (int)BTL_POKEPARAM_GetItem(entry);
    if (func_021E8638(typeId, level) != 0)
        return 1;
    return 0;
}


/*
 * 2026-10-03: the `cmp r0,#1; beq; bne` pair is a disjunction of two tests that both
 * compare against 1 (likely two constants with the same value); the compiler keeps
 * one branch per operand.
 */
int BTLV_CORE_CheckPartySlotCondition(void *party, int slot)
{
    int result;

    if (func_021C8168(party) == 0) {
        result = func_021B8DDC(slot);
        if (result == 1 || result == 1)
            return 1;
    }
    return 0;
}


int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB)
{
    void *entryA;
    void *entryB;
    int typeId;
    u16 level;

    if (BTLV_CORE_CheckPartySlotCondition(party, slotA) != 0)
        return 1;
    if (BTLV_CORE_CheckPartySlotPair(party, slotB) != 0)
        return 1;
    entryA = func_021C7CF4(party, slotA);
    entryB = func_021C7CF4(party, slotB);
    typeId = BTL_POKEPARAM_GetSpecies(entryA);
    level = (int)BTL_POKEPARAM_GetItem(entryB);
    if (func_021E8638(typeId, level) != 0)
        return 1;
    return 0;
}


void BTLV_CORE_EventRedirectMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    u8 attackerId;
    u16 moveId;

    attackerId = BTL_EVENT_GetVar(2);
    if (func_021B9A24(attackerId, pokeId) == 0) {
        moveId = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetCategory(moveId) == 0xb) {
            if (WAZA_TOOL_GetFlag(moveId, 4) != 0) {
                if (BTL_EVENT_OverwriteVar(0x22, 0x19) != 0)
                    func_021C8434(eventCtx, pokeId, attackerId);
            }
        }
    }
}


void BTLV_CORE_EventCounterMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    u8 defenderId;
    u16 moveId;
    int flagBit;

    flagBit = 4;
    if (pokeId == BTL_EVENT_GetVar(4)) {
        if (BTL_EVENT_GetVar(0x4e) == 0) {
            if (BTL_POKEPARAM_IsSemiInvulnerable(func_021C7CF4(eventCtx, pokeId)) == 0) {
                moveId = BTL_EVENT_GetVar(0x12);
                if (WAZA_TOOL_GetFlag(moveId, flagBit) != 0) {
                    flagBit = 1;
                    if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
                        defenderId = BTL_EVENT_GetVar(3);
                        func_021C8434(eventCtx, pokeId, defenderId);
                        BTL_EVENT_OverwriteVar(0x51, flagBit);
                    }
                }
            }
        }
    }
}


void BTLV_CORE_EventQueueMoveNotice(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    struct BtlvEventRec *rec;
    int listKind;

    listKind = 2;
    if (pokeId == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_IsSemiInvulnerable(func_021C7CF4(eventCtx, pokeId)) == 0) {
            rec = func_021C88A4(eventCtx, 4, pokeId);
            func_021C8838(rec->list, listKind, 0x2fc);
            func_021C8860(rec->list, pokeId);
            func_021C8860(rec->list, BTL_EVENT_GetVar(0x12));
            func_021C88C8(eventCtx, rec);
        }
    }
}


void BTLV_CORE_EventScaleDamage(int factor)
{
    factor *= BTL_EVENT_GetVar(0x30);
    BTL_EVENT_OverwriteVar(0x30, factor);
}


void BTLV_CORE_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2)
{
    if (func_021B9A24((u8)BTL_EVENT_GetVar(2), pokeId) != 0)
        BTL_EVENT_OverwriteVar(0x51, 1);
}


int BTLV_CORE_EventTrySetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId)
{
    if (func_021B9A24((u8)BTL_EVENT_GetVar(2), pokeId) != 0) {
        if (BTL_EVENT_OverwriteVar(0x51, 1) != 0)
            return 1;
    }
    return 0;
}


void BTLV_CORE_LoadDsiOverlay(void)
{
    if (OS_GetConsoleType() & 0x02000000) {
        GF_OVERLAY_Load(ov140_id);
        gBtlvCoreDsiOverlayLoaded = 1;
    } else {
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}


void BTLV_CORE_UnloadDsiOverlay(void)
{
    if (gBtlvCoreDsiOverlayLoaded != 0) {
        GF_OVERLAY_Unload(ov140_id);
        gBtlvCoreDsiOverlayLoaded = 0;
    }
}


/*
 * Returns 0 with a 4-byte frame that nothing ever stores to.  Taking the address of a local array forces the slot, and the optimizer then removes both the store and the reload (nothing outside can alias it), so the frame and the register-resident value both survive.  A scalar `u32 v = 0; v &= ~7u;` folds to 4 bytes, which is why O28's residue could not reach this; the address-taken local is the missing form.
 * stand-in: the word is reached through a cast of the byte array; a u32 array, a union or an address-taken u32 each change the bytes.
 */
u32 BTLV_CORE_GetZeroMasked(void) { u8 bytes[4]; *(u32 *)bytes = 0; return *(u32 *)bytes & ~7u; }


int BTLV_CORE_IsSlotKindNone(BtlvSlot slot)
{
    if (slot.pos.kind == 0)
        return 1;
    return 0;
}


/*
 * 2026-10-03 EXACT (wave B3, lane 21): the second pool word is 0xFE0001FF, not
 * 0x000001FF. It is the value:16 clear mask of the BTLV_CORE_MakeSlotKind2 slot, so this is
 * BTLV_CORE_MakeSlotKind2 with value = 0 and extra left zero from the initialiser.
 */
int BTLV_CORE_MakeSlotKind2Index(u32 index)
{
    BtlvSlot slot = {0};

    slot.param.kind = 2;
    slot.param.index = index & 0x3f;
    slot.param.value = 0;
    return slot.word;
}


int BTLV_CORE_MakeSlotKind2(u32 index, u32 value)
{
    BtlvSlot slot = {0};

    slot.param.kind = 2;
    slot.param.index = index & 0x3f;
    slot.param.value = value;
    return slot.word;
}


/*
 * Recursive MATCH unblocker: named callee of the parked ov093 BTL_HANDLER_ITEM_DestinyKnot_Infatuate
 * (+0080, `BTLV_CORE_MakeSlotKind3(c)` stored at record +8).  Packs a 3-bit constant
 * (3) with the low six bits of the argument shifted left by three, as a
 * bitfield union read back as a word; the empty frame is the compiler's
 * storage for the union local, and `= {0}` is what emits `movs r2,#0`
 * instead of reading the uninitialised slot back.
 *
 * Addresses are Black-image addresses.
 */
int BTLV_CORE_MakeSlotKind3(u32 index)
{
    BtlvSlot slot = {0};

    slot.indexOnly.kind = 3;
    slot.indexOnly.index = index & 0x3f;
    return slot.word;
}


int BTLV_CORE_MakeSlotKind1Empty(void)
{
    BtlvSlot slot = {0};

    slot.indexOnly.kind = 1;
    return slot.word;
}


int BTLV_CORE_MakeSlotKind1Value(u32 value)
{
    BtlvSlot slot = {0};
    slot.param.kind = 1;
    slot.param.value = value;
    return slot.word;
}


/*
 * Unlabelled leaf, the only blocker of BTL_CALC_MakeSickContFromSpec's MATCH (case 1 of its
 * kind switch).  Sibling of BTLV_CORE_MakeSlotKind3: packs kind 1, a 6-bit field and a
 * 16-bit field into a one-word bitfield.
 */
int BTLV_CORE_MakeSlotKind1(u32 index, u32 value)
{
    BtlvSlot slot = {0};
    slot.param.kind = 1;
    slot.param.index = index & 0x3f;
    slot.param.value = value;
    return slot.word;
}


int BTLV_CORE_MakeSlotKind4(u32 hi, u32 lo)
{
    BtlvSlot slot = {0};

    slot.pos.kind = 4;
    slot.pos.lo = lo & 0x3f;
    slot.pos.hi = hi & 0x3f;
    return slot.word;
}


int BTLV_CORE_MakeSlotKind1Index15(void)
{
    BtlvSlot slot = {0};

    slot.indexOnly.kind = 1;
    slot.indexOnly.index = 0xf;
    return slot.word;
}


int BTLV_CORE_IsSlotKind1Index15(BtlvSlot slot)
{
    if (slot.pos.kind == 1 && slot.pos.lo == 0xf)
        return 1;
    return 0;
}


u8 BTLV_CORE_GetSlotPosition(BtlvSlot slot)
{
    if (slot.pos.kind == 3)
        return slot.pos.lo;
    if (slot.pos.kind == 4)
        return slot.pos.hi;
    return 0x1f;
}


void BTLV_CORE_SetSlotPosition(BtlvSlot *slot, u8 pos)
{
    if (slot->pos.kind == 3)
        slot->pos.lo = pos;
    else if (slot->pos.kind == 4)
        slot->pos.hi = pos;
}


u8 BTLV_CORE_GetSlotLow(BtlvSlot slot)
{
    if (slot.pos.kind == 2) return slot.pos.lo;
    if (slot.pos.kind == 4) return slot.pos.lo;
    return 0;
}


void BTLV_CORE_SetSlotValue(BtlvSlot *slot, u16 value)
{
    if (slot->param.kind == 1) slot->param.value = value;
    else if (slot->param.kind == 3) slot->param.value = value;
    else if (slot->param.kind == 4) slot->wideParam.value = value;
    else if (slot->param.kind == 2) slot->param.value = value;
}


u16 BTLV_CORE_GetSlotValue(BtlvSlot slot)
{
    if (slot.param.kind == 1) return slot.param.value;
    if (slot.param.kind == 3) return slot.param.value;
    if (slot.param.kind == 4) return slot.wideParam.value;
    if (slot.param.kind == 2) return slot.param.value;
    return 0;
}


void BTLV_CORE_SetSlotFlag(BtlvSlot *slot, int flag)
{
    if (slot->flagMid.kind == 1) slot->flagMid.flag = flag;
    else if (slot->flagMid.kind == 3) slot->flagMid.flag = flag;
    else if (slot->flagMid.kind == 4) slot->flagHigh.flag = flag;
    else if (slot->flagMid.kind == 2) slot->flagMid.flag = flag;
}


u32 BTLV_CORE_GetSlotFlag(BtlvSlot slot)
{
    if (slot.flagMid.kind == 1) return slot.flagMid.flag;
    if (slot.flagMid.kind == 3) return slot.flagMid.flag;
    if (slot.flagMid.kind == 4) return slot.flagHigh.flag;
    if (slot.flagMid.kind == 2) return slot.flagMid.flag;
    return 0;
}


void BTLV_CORE_AddSlotIndex(BtlvSlot *slot, u32 delta)
{
    if (slot->indexOnly.kind == 2 && slot->indexOnly.index < 8) slot->indexOnly.index = slot->indexOnly.index + delta;
    if (slot->indexOnly.kind == 4 && slot->indexOnly.index < 8) slot->indexOnly.index = slot->indexOnly.index + delta;
}


void BTLV_CORE_SetSlotIndex(BtlvSlot *slot, int count)
{
    if (slot->indexOnly.kind == 2 && slot->indexOnly.index < 8) slot->indexOnly.index = count;
    if (slot->indexOnly.kind == 4 && slot->indexOnly.index < 8) slot->indexOnly.index = count;
}


/* 021E8CE0  ((high & 0xff) << 8) | (low & 0xff) as u16 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: lsls r0, r0, #0x18; lsrs r2, r0, #0x10; lsls r0, r1, #0x18; lsrs r0, r0, #0x18; orrs r0, r2; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 BTLV_CORE_PackBytes(u32 high, u32 low) { return (u16)(((high & 0xff) << 8) | (low & 0xff)); }


int BTLV_CORE_PackByteTwice(int byte)
{
    return BTLV_CORE_PackBytes(byte, byte);
}


/* 021E8CFC  asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: asrs r0, r0, #8; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 BTLV_CORE_GetHighByte(s32 word) { return (u8)(word >> 8); }


int BTLV_CORE_GetLowByte(int word)
{
    return (unsigned char)word;
}


void BTLV_CORE_SplitBytes(int word, unsigned char *high, unsigned char *low)
{
    *high = BTLV_CORE_GetHighByte(word);
    *low = BTLV_CORE_GetLowByte(word);
}


int BTLV_CORE_HasByte(int word, int byte)
{
    if (byte == BTLV_CORE_GetHighByte(word)) {
        return 1;
    }
    if (byte == BTLV_CORE_GetLowByte(word)) {
        return 1;
    }
    return 0;
}


int BTLV_CORE_BytesOverlap(int wordA, int wordB)
{
    if (BTLV_CORE_GetHighByte(wordA) == BTLV_CORE_GetHighByte(wordB)) return 1;
    if (BTLV_CORE_GetHighByte(wordA) == BTLV_CORE_GetLowByte(wordB)) return 1;
    if (BTLV_CORE_GetLowByte(wordA) == BTLV_CORE_GetHighByte(wordB)) return 1;
    if (BTLV_CORE_GetLowByte(wordA) == BTLV_CORE_GetLowByte(wordB)) return 1;
    return 0;
}


int BTLV_CORE_BytesEqual(int word)
{
    if (BTLV_CORE_GetHighByte(word) == BTLV_CORE_GetLowByte(word)) {
        return 1;
    }
    return 0;
}


void BTLV_CORE_LoadOverlays(unsigned short heapId)
{
    BTLV_CORE_InitDisplay(heapId);
    func_02034AC4(ov094_id);
    func_0208068C(0x80);
    func_02034AC4(ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        func_02034AC4(ov096_id);
    }
}


void BTLV_CORE_UnloadOverlays(void)
{
    BTLV_CORE_ExitDisplay();
    func_02034A5C(ov094_id);
    func_02034A5C(ov095_id);
    if (GFL_NET_IsNetTypeWifi() == 0) {
        func_02034A5C(ov096_id);
    }
}


/*
 * wrapper over BTLV_CORE_ExitDisplay, BTLV_CORE_InitDisplay
 */
void BTLV_CORE_ResetDisplay(u16 heapId)
{
    BTLV_CORE_ExitDisplay();
    BTLV_CORE_InitDisplay(heapId);
}


/*
 * lever: the POWCNT read/OR/write is spelled as assignment, not compound assignment.
 * volatile: 021E8E60 POWCNT; 021E8E8E,021E8E9C,021E8EA4 DISP3DCNT; 021E8EBE BG0CNT.
 */
void BTLV_CORE_InitDisplay(u16 heapId)
{
    func_0203F8F4(heapId);
    BMP_WIN_Init(heapId);
    GF_FONT_ResetTextColor();
    BG_SYS_SetVramBanks(&gBtlvCoreVramBanks);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28(&gBtlvCoreDispConfig);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heapId, 0);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    G3X_SetFog(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0207D63C((void *)&BLDCNT, 2, 0x3d, 0x1f, 3);
    CLACT_InitSystem(&gBtlvCoreBgConfig, &gBtlvCoreVramBanks, heapId);
}


void BTLV_CORE_ExitDisplay(void)
{
    func_021F7808();
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    func_0203F9B4();
    G3D_SYSTEM_Exit();
}


struct BtlvCore *BTLV_CORE_Create(void *mainWork, void *netCtx, u32 mainRegion, int param, u16 heapId)
{
    struct BtlvCore *core;
    core = func_02030734(heapId, 0x188, 0, gBtlvCoreFileName, 0x12d);
    core->mainWork = mainWork;
    core->netCtx = netCtx;
    core->mainRegion = mainRegion;
    core->clientIndex = func_021D3D70(netCtx);
    core->state = 4;
    core->heapId = heapId;
    core->msgBuffer = STRBUF_Create(0x200, heapId);
    core->fontMain = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    core->fontSub = GF_FONT_Create(0x17, 2, 0, 0, heapId);
    core->taskList = TCBL_Create(heapId, heapId, 0x40, 0x80);
    core->sceneUnit = BTLV_SCU_Create((u32)core, (u32)core->mainWork, mainRegion, (u32)core->taskList, (u32)core->fontMain, (u32)core->fontSub, core->clientIndex, heapId);
    core->auxView = func_06899AF0(core, core->mainWork, mainRegion, core->taskList, core->fontMain, core->netCtx, param, heapId);
    core->counterA = 0;
    core->counterB = 0;
    core->busy = 0;
    BTL_MSG_Init((u32)mainWork, core->clientIndex, mainRegion, heapId);
    return core;
}
