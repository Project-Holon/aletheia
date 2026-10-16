/*
 * file:     wih_dwc.c
 * unit:     yes
 * function: WIH_DWC_PollSystem, WIH_DWC_Create, WIH_DWC_Delete, WIH_DWC_PauseTimers, WIH_DWC_ResumeTimers, WIH_DWC_AddBeacon, WIH_DWC_TickTimers, WIH_DWC_IsSsidInFilterList, WIH_DWC_IsOpenTaggedBeacon, WIH_DWC_IsPrivacyBeacon, WIH_DWC_PollStatus, WIH_DWC_CreateFilterBuffer, WIH_DWC_ResetFilterState, WIH_DWC_FindSlotByKey, WIH_DWC_GetAlertLevel, WIH_DWC_RequestAlertLevel, WIH_DWC_Dummy
 * address:  0x0201034C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * wih_dwc.c: the wireless/DWC beacon helper.  The state is one global
 * (gWihDwc): the 0x328-byte context object and a 0xA00-byte filter buffer.
 * The net_err.c error window that used to precede this file is now net_err.c,
 * and the GFL_NET_SAVE_* save task that used to trail it is now net_save.c.
 *
 * symbols:
 *   GFL_NET_AllocAligned     0x0203D7C8  arm
 *   GFL_NET_FreeAligned      0x0203D7FC  arm
 *   GFL_NET_GetInitParam     0x0203D798  arm
 *   GFL_NET_GetNegotiationNum   0x0203D1B4  arm
 *   GFL_NET_GetScanResult    0x0203CF10  arm
 *   GFL_NET_GetRunState      0x0203CD98  arm
 *   DWC_GetParseWMBssDescWorkSize   0x0205D010  arm
 *   DWC_ParseWMBssDesc       0x0205D01C  arm
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   NET_WHPIPE_GetEntryKind  0x02178098  thumb  ov014
 *   NET_WHPIPE_GetEntryBeaconKind   0x02177B80  thumb  ov014
 *   MI_CpuCopy8              0x02082D44  arm
 *   GF_STANDARD_GetStringLength   0x0203F004  arm
 *   GF_STANDARD_CompareBytes   0x0203EFC8  arm
 *   OS_GetMacAddress         0x02087C6C  arm
 *   GFL_USE_PollPowerExit    0x020053EC  thumb
 *   GFL_USE_UpdateSound      0x02005BC0  thumb
 *   PM_VOICE_StopFinished    0x020065FC  thumb
 *   SAVEDATA_PanicFail            0x02034714  arm
 *   GF_OVERLAY_Load            0x02034AC4  arm
 *   GF_OVERLAY_Unload            0x02034A5C  arm
 *   NCFG_ReadConfig            0x0205FAA8  arm
 *   sub_0202E8D8             0x0202E8D8  thumb
 *   gWihDwc                  0x021461E0  data
 *   sWihDwcAssertArg         0x020A7240  data
 *   sWihDwcFile              0x020A7244  data
 *   sWihBeaconSsidTag        0x020A7250  data
 *   ov015_id                 0x0000000F  data
 *   UI_Update  0x02034F5C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* One 0xC0-byte beacon record (a WMBssDesc) that the ov014 receive callback queues */
struct WihBssDesc {
    u8 bssid[6];
    u16 length;
    u16 rssi;
    u16 ssidLength;
    u8 ssid[0x20];      /* +0x0C */
    u16 capaInfo;       /* +0x2C, bit 0x10 is the privacy flag */
    u8 rest[0x92];
};

/* the 0xA00-byte buffer behind the global's second word */
struct WihFilterBuf {
    u8 scanWork[0x600];
    u8 filterState[0x40];
    u8 ssidSlot[3][0x100];  /* +0x640 */
    u8 pad940[0xC0];
};

/* the 0x328-byte context object WIH_DWC_Create allocates */
struct WihContext {
    struct WihBssDesc beacon[4];
    void *matchWork;                    /* +0x300 */
    struct WihFilterBuf *filterBuf;     /* +0x304 */
    u8 pad308[4];
    u16 paused;                         /* +0x30C, nonzero stops the timers */
    u16 alertCooldown;                  /* +0x30E */
    u16 maxBeacons;                     /* +0x310 */
    u16 alertLevel;                     /* +0x312 */
    u16 pendingAlertLevel;              /* +0x314 */
    u16 beaconCount;                    /* +0x316 */
    s32 knownGameTimer;                 /* +0x318 */
    s32 taggedGameTimer;                /* +0x31C */
    s32 openNetworkTimer;               /* +0x320 */
    s32 securedNetworkTimer;            /* +0x324 */
};

/* the global at 0x021461E0 */
struct WihGlobals {
    struct WihContext *context;
    struct WihFilterBuf *filterBuf;
};

struct WihSsidInfo {
    int kind;          /* +0x00 */
    u8  rest[0x3C];    /* +0x04 */
};

/* the connection state block GFL_NET_GetInitParam returns (fields used here) */
struct GFLNetInitializeStruct {
    u8 unused00[0x62];
    u8 slotCount;
    u8 unused63[4];
    u8 connectState;
};

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);
extern void *GFL_NET_AllocAligned(u32 heapId, u32 size, const char *file, u16 line);
extern u32  DWC_GetParseWMBssDescWorkSize(void);
extern int GF_OVERLAY_Load(int id);
extern void WIH_SetBeaconFoundCallback(u32 callback);
extern void GFL_NET_FreeAligned(void *p);
extern void GF_OVERLAY_Unload(int handle);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32 GF_STANDARD_GetStringLength(const u8 *s);
extern s32 GF_STANDARD_CompareBytes(const void *a, const void *b, u32 n);
extern void *GFL_NET_GetInitParam(void);
extern int  GFL_NET_GetNegotiationNum(void);
extern u32 GFL_NET_GetScanResult(u32 slot);
extern u8   NET_WHPIPE_GetEntryKind(u8 slot);
extern int  DWC_ParseWMBssDesc(void *work, struct WihBssDesc *beacon, struct WihSsidInfo *out);
extern void NCFG_ReadConfig(u8 *filterState, u32 value);
extern int  GFL_NET_GetRunState(void);
extern void OS_GetMacAddress(u8 *mac);
extern u8 NET_WHPIPE_GetEntryBeaconKind(int slot);
extern int sub_0202E8D8(char *record, int key, char *mac);
extern int UI_Update(int a);
extern int GFL_USE_PollPowerExit(void);
extern int GFL_USE_UpdateSound(int a);
extern int PM_VOICE_StopFinished(int a);

int WIH_DWC_PollSystem(void);
struct WihContext *WIH_DWC_Create(int maxBeacons, void *heap);
void WIH_DWC_Delete(struct WihContext *context);
void WIH_DWC_PauseTimers(void);
void WIH_DWC_ResumeTimers(void);
void WIH_DWC_AddBeacon(const void *beacon);
void WIH_DWC_TickTimers(void);
int WIH_DWC_IsSsidInFilterList(struct WihBssDesc *beacon);
int WIH_DWC_IsOpenTaggedBeacon(const struct WihBssDesc *beacon);
u32 WIH_DWC_IsPrivacyBeacon(const struct WihBssDesc *beacon);
u32 WIH_DWC_PollStatus(void *searchKey);
void WIH_DWC_CreateFilterBuffer(u32 heapId);
void WIH_DWC_ResetFilterState(void);
int WIH_DWC_FindSlotByKey(void *searchKey);
u16 WIH_DWC_GetAlertLevel(void);
void WIH_DWC_RequestAlertLevel(u32 level);
void WIH_DWC_Dummy(void);
extern struct WihGlobals gWihDwc;
extern u8 sWihDwcAssertArg;
extern u8 sWihDwcFile[];
extern u8 ov015_id[];
extern u8 sWihBeaconSsidTag[];


/*
 * wih_dwc.c per-frame system poll: power-exit check, then the sound update
 * and the finished-voice stop, chained through their return values.
 */
int WIH_DWC_PollSystem(void)
{
    int t0 = GFL_USE_PollPowerExit();
    int t1 = UI_Update(t0);
    int t2 = GFL_USE_UpdateSound(t1);
    int t3 = PM_VOICE_StopFinished(t2);

    return t3;
}


/*
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by DWC_GetParseWMBssDescWorkSize
 * (line 0x4C) into +0x300, registers WIH_DWC_AddBeacon as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  WIH_DWC_Delete is its destructor.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     rewritten 2026-09-23 (wave 14): every concrete byte right, 11 of
 *           12 relocation sites resolved.
 *
 *           Thumb leaf in ov014 (wih.c): 0x0217963C decodes as
 *           `ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,[r2,r1];
 *           bx lr`, a setter of word +0x1E88 of the object behind 0x021797A8
 *           (the same shape as the labelled WIH_SetConnectCallback just before it,
 *           which sets +0x1E84).  asm/overlays/ov014.s prints it as .word
 *           data, so attest_overlay_label() has no label to accept.  SEED
 *           REQUEST for the integrator: `ov014 0x0217963C thumb`, evidence
 *           the bl at arm9 0x020103B6 (this function) and 0x020103FE
 *           (WIH_DWC_Delete).  Once seeded, 0x020103FE is an outside witness
 *           for this file and 0x020103B6 for WIH_DWC_Delete: both go EXACT
 *           with no C change.
 *
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by DWC_GetParseWMBssDescWorkSize
 * (line 0x4C) into +0x300, registers WIH_DWC_AddBeacon as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  WIH_DWC_Delete is its destructor.
 * Two readings corrected from the previous file: the pool word is
 * 0x021461E0 (not 0x020461E0), and 0x0201045D is the Thumb address of
 * WIH_DWC_AddBeacon, a function pointer, not data.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_Create.c \
 *       --func WIH_DWC_Create --addr 0x02010360 --thumb
 */
struct WihContext *WIH_DWC_Create(int maxBeacons, void *heap)
{
    struct WihContext *context;

    if (maxBeacons > 4) {
        SAVEDATA_PanicFail((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    if (gWihDwc.context != 0) {
        SAVEDATA_PanicFail((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    context = GFL_NET_AllocAligned((u32)heap, 0x328, (const char *)sWihDwcFile, 0x49);
    context->maxBeacons = maxBeacons;
    context->matchWork = GFL_NET_AllocAligned((u32)heap, DWC_GetParseWMBssDescWorkSize(), (const char *)sWihDwcFile, 0x4C);
    WIH_SetBeaconFoundCallback((u32)WIH_DWC_AddBeacon);
    gWihDwc.context = context;
    context->filterBuf = gWihDwc.filterBuf;
    GF_OVERLAY_Load((int)ov015_id);
    return context;
}


/*
 * wih_dwc.c teardown, the counterpart of WIH_DWC_Create.  WIH_SetBeaconFoundCallback is an
 * unlabelled ov014 Thumb setter.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           address in overlay space: two overlays overlap it (ov009, ov014)
 *           and NEITHER carries a func_ label there (ov009 decodes it as
 *           `moveq r0, #1` in the middle of a function, ov014 has the data
 *           word 0x680A4902).  attest_overlay_label() needs part 1 of the
 *           rule, a label in the overlay's own listing, so the site has no
 *           witness outside this range and no cut can give it one: the only
 *           branch to 0x0217963C in the image is the pair at 0x020103B6 and
 *           0x020103FE, and both are inside this packet.  `matched` cannot
 *           reach it either (0x0217963C is not matched).
 *           2026-09-23 (wave 14): 0x0217963C is an unlabelled ov014 Thumb
 *           setter (`ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,
 *           [r2,r1]; bx lr`), printed as .word data.  SEED REQUEST: `ov014
 *           0x0217963C thumb`; the two bl sites then witness each other and
 *           this file and WIH_DWC_Create go EXACT unchanged.
 *
 * "wih_dwc.c" teardown, the counterpart of WIH_DWC_Create (same packet):
 * both guard on the same pointer at 0x021461E0 being null before running
 * the 0x020A7240-argument call, both take the same (p, 0, p) argument
 * triple, and both end by clearing that pointer again.  The pool word is
 * the address of the four zero bytes immediately before the "wih_dwc.c"
 * string at 0x020A7244 - the file anchor the packet reports.
 *
 * The last call's argument arrives from a pool word holding 0x0000000F, not
 * from a `movs`, so it is a symbol rather than an integer: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  The
 * pool words on either side of this function (0x020103E0 and 0x02010428)
 * both hold 0x0F, and GF_OVERLAY_Load - the sibling entry point in
 * src/pending/unit_0200BA58.c - takes the same kind of value, so this is
 * the same linker-defined id, spelled ov015_id here.  It is `literal`-
 * attested by 0x020103E0, which is outside this function's range.
 *
 * The call at 0x0217963C is a branch into overlay space (it is why the
 * listing prints it as .inst.w "outside this region").  Its argument is a
 * literal zero, and that same zero is what the store at +0x30 writes: mwcc
 * materialises it once, keeps it in r4 across both GFL_NET_FreeAligned calls and
 * stores it, which is the `movs r4, #0` beside the `movs r0, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_Delete.c \
 *       --func WIH_DWC_Delete --addr 0x020103E4 --cc 1.1p1 --thumb
 *   MATCH, 72 bytes, 7 relocation sites, 6 resolved, 1 wildcard:
 *     +001A THM_CALL WIH_SetBeaconFoundCallback - unresolved, no outside witness.
 */
void WIH_DWC_Delete(struct WihContext *context)
{
    if (gWihDwc.context == 0) {
        SAVEDATA_PanicFail((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    WIH_SetBeaconFoundCallback(0);
    GFL_NET_FreeAligned(context->matchWork);
    GFL_NET_FreeAligned(context);
    gWihDwc.context = 0;
    GF_OVERLAY_Unload((int)ov015_id);
}


/*
 * Two mirror-image functions: set and clear the flag halfword at +0x30C of
 * the context object.
 */
/*
 * Two mirror-image four-word functions: set and clear one flag halfword of
 * entry 0xC3 in a table reached through the pointer variable at 0x0214617C's
 * neighbour, 0x021461E0.  0x021461E0 is a plain literal pool word (the same
 * address is loaded by nine other functions in this file's neighbourhood, at
 * 0x020103D4, 0x02010420 and so on), so it needed no relocation resolution,
 * the same situation documented in src/matched/GFL_NET_ERR_RestoreBrightness.c for 0x0214617C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201042C.c \
 *       --addr 0x0201042C --thumb
 */
void WIH_DWC_PauseTimers(void)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0) {
        context->paused = 1;
    }
}


void WIH_DWC_ResumeTimers(void)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0) {
        context->paused = 0;
    }
}


/*
 * wih_dwc.c: append one 0xC0-byte record to the four-slot table at the head
 * of the context object, guarded on the capacity at +0x310 and the fill
 * index at +0x316.  WIH_DWC_Create hands this function's address to the ov014
 * setter, so it is a receive callback.  MI_CpuCopy8 takes three arguments.
 */
void WIH_DWC_AddBeacon(const void *beacon)
{
    struct WihContext *context = gWihDwc.context;

    if (context->maxBeacons != 0 && context->beaconCount < context->maxBeacons && context->beaconCount < 4) {
        MI_CpuCopy8(beacon, &context->beacon[context->beaconCount], 0xC0);
        gWihDwc.context->beaconCount = gWihDwc.context->beaconCount + 1;
    }
}


/*
 * Per-frame countdown of the four timers at +0x318..+0x324 (the real
 * prologue is at 0x02010498).
 */
/*
 *           function_starts.txt line 337 seeds this leaf at 0x0201049C (4 bytes
 *           too high); the real prologue and byte-exact fit are at 0x02010498,
 *           per docs/notes/unit_0201045C.c.txt.
 * blocked:  +005C ABS32 gWihDwc : unresolved: no address for 'gWihDwc':
 *           not in the symbols: block, not an address-bearing name, not in
 *           layout/symbols_sdk.json
 */
void WIH_DWC_TickTimers(void)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0 && context->paused != 0)
        return;
    if (context == 0)
        return;
    if (context->knownGameTimer > 0)
        context->knownGameTimer = context->knownGameTimer - 1;
    context = gWihDwc.context;
    if (context->taggedGameTimer > 0)
        context->taggedGameTimer = context->taggedGameTimer - 1;
    context = gWihDwc.context;
    if (context->openNetworkTimer > 0)
        context->openNetworkTimer = context->openNetworkTimer - 1;
    context = gWihDwc.context;
    if (context->securedNetworkTimer > 0)
        context->securedNetworkTimer = context->securedNetworkTimer - 1;
}


/*
 * Three 0x100-byte slots at +0x640 of the buffer behind the context's +0x304;
 * the first slot with a positive GF_STANDARD_GetStringLength whose GF_STANDARD_CompareBytes against
 * the record's name returns zero makes the function return 1.  GF_STANDARD_CompareBytes
 * takes THREE arguments, the third is the result of GF_STANDARD_GetStringLength (kept in
 * r2).  `i` must be initialised before `q`, and the loop-body local `n` must
 * be declared inside the loop.
 */
/*
 * Three 0x100-byte slots at +0x640 of the object hanging off +0x304 of the
 * global at 0x021461E0 (the same global WIH_DWC_AddBeacon reads); the first slot
 * with a positive GF_STANDARD_GetStringLength whose GF_STANDARD_CompareBytes against obj+0xC returns
 * zero makes the function return 1.
 *
 * Three spellings the previous pass (docs/notes/pkt_0201045C.c.txt) did not
 * have, and each is needed:
 *
 *  1. the pool word is 0x021461E0, not 0x020461E0, and it holds a POINTER,
 *     not the object: the original does one `ldr r1, [r7]` and then
 *     `ldr r1, [r1, r0]` with r0 = 0x304.  Reading it as `**` costs an extra
 *     dereference at both sites.  It is the same global WIH_DWC_AddBeacon reads.
 *  2. GF_STANDARD_CompareBytes takes THREE arguments, and the third is the result of
 *     GF_STANDARD_GetStringLength.  That is what the otherwise pointless `adds r2, r0, #0`
 *     at 0x02010518 is: r2 is set right after the first call and is still
 *     live, unwritten, at the `blx` to GF_STANDARD_CompareBytes twenty-four bytes
 *     later.  Two arguments plus a named local for the comparison folds the
 *     copy away (80 bytes); a function-scope or volatile local gives it a
 *     stack home (`str r0, [sp]` / `ldr r0, [sp]`) instead of r2.  The local
 *     must be declared inside the loop body.
 *     docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md
 *  3. `i` must be initialised before `q`: the original opens
 *     `movs r4, #0` then `adds r6, #0xc`, and writing the loop as a plain
 *     `for (i = 0; ...)` after `u8 *q = obj + 0xC;` emits those two the
 *     other way round.  That swap is the last two bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_IsSsidInFilterList.c \
 *       --func WIH_DWC_IsSsidInFilterList --addr 0x020104F8 --cc 1.1p1 --thumb
 */
int WIH_DWC_IsSsidInFilterList(struct WihBssDesc *beacon)
{
    int slotIndex = 0;
    u8 *ssid = beacon->ssid;

    for (; slotIndex < 3; slotIndex++) {
        u8 *slot = gWihDwc.context->filterBuf->ssidSlot[slotIndex];
        int slotLength = GF_STANDARD_GetStringLength(slot);

        if (slotLength > 0) {
            slot = gWihDwc.context->filterBuf->ssidSlot[slotIndex];
            if (GF_STANDARD_CompareBytes(slot, ssid, slotLength) == 0)
                return 1;
        }
    }
    return 0;
}


/*
 * Three gates on one record then `return 1`; all false paths share the single
 * `return 0` at the bottom.  The compare is against the 8 bytes at
 * 0x020A7250, GF_STANDARD_CompareBytes is a memcmp-shaped helper whose zero means equal.
 */
/*
 * Three gates on one object then `return 1`.  All three false paths share the
 * single `return 0` at the bottom, which is what puts the `bne`/`beq` on the
 * shared epilogue instead of inlining two `movs r0, #0`: the source is a nest
 * of three `if`s with one `return 1` inside and one `return 0` after them.
 * The compare is against the 8 bytes at 0x020A7250, a cast address constant
 * (no relocation), and `GF_STANDARD_CompareBytes` is a memcmp-shaped helper whose zero
 * means equal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_IsOpenTaggedBeacon.c \
 *       --func WIH_DWC_IsOpenTaggedBeacon --addr 0x0201054C --cc 1.1p1 --thumb
 */
int WIH_DWC_IsOpenTaggedBeacon(const struct WihBssDesc *beacon)
{
    if (beacon->ssidLength == 8) {
        if (GF_STANDARD_CompareBytes(sWihBeaconSsidTag, beacon->ssid, 8) != 0) {
            if ((beacon->capaInfo & 0x10) == 0) {
                return 1;
            }
        }
    }
    return 0;
}


/*
 * A boolean test of bit 0x10 of the halfword at +0x2C of a record.
 */
/*
 * Sixteen bytes: a boolean test of bit 0x10 of a halfword field at +0x2C of
 * its argument.  The functions on both sides of it are not matched yet, so
 * it is a file of its own, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201057C.c \
 *       --func WIH_DWC_IsPrivacyBeacon --addr 0x0201057C --cc 1.1p1
 */
u32 WIH_DWC_IsPrivacyBeacon(const struct WihBssDesc *beacon)
{
    if (beacon->capaInfo & 0x10) {
        return 1;
    }
    return 0;
}


/*
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in WIH_DWC_FindSlotByKey, the connection state byte +0x67
 * and slot count +0x62 of the GFL_NET_GetInitParam state block, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * WIH_DWC_AddBeacon fills, arming the four countdowns at +0x318..+0x324 that
 * WIH_DWC_TickTimers decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.  DWC_ParseWMBssDesc's third argument is a
 * 0x40-byte out record whose first word is the switch key; the switch has
 * explicit empty arms for 7 and 9 so the 13-entry halfword table exists.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02178098 as .word data (0x680B4909), and this call is
 *           the only branch to it in the image.  SEED REQUEST: `ov014
 *           0x02178098 thumb`, evidence the bl at arm9 0x020105E8.  Every
 *           other site resolves and every concrete byte matches (520 of 520).
 *
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in WIH_DWC_FindSlotByKey, the connection state byte +0x67
 * and slot count +0x62 of the GFL_NET_GetInitParam context, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * WIH_DWC_AddBeacon fills, arming the four countdowns at +0x318..+0x324 that
 * WIH_DWC_TickTimers decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.
 *
 * Two declaration facts close it: DWC_ParseWMBssDesc's third argument is a
 * 0x40-byte out record whose first word is the switch key (the frame is
 * sub sp,#0x60 plus the r3 pad; an `int *` gives sub sp,#0x24), and the
 * switch has explicit empty arms for 7 and 9 so the 13-entry halfword table
 * exists (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_PollStatus.c \
 *       --func WIH_DWC_PollStatus --addr 0x0201058C --thumb
 */
u32 WIH_DWC_PollStatus(void *searchKey)
{
    u32 flags = 0;
    struct GFLNetInitializeStruct *netState = GFL_NET_GetInitParam();
    int slot;
    int beaconIndex;
    struct WihBssDesc *beacon;
    struct WihSsidInfo ssidInfo;
    u8 slotState;

    if (gWihDwc.context == 0)
        return flags;

    if (WIH_DWC_FindSlotByKey(searchKey) != -1)
        flags |= 8;
    if (netState->connectState == 2 && GFL_NET_GetNegotiationNum() > 1)
        flags |= 4;

    for (slot = 0; slot < netState->slotCount; slot++) {
        if (GFL_NET_GetScanResult(slot) != 0) {
            slotState = NET_WHPIPE_GetEntryKind(slot);
            if (slotState >= 0x14 && slotState <= 0x1B)
                flags |= 0x10;
            else if (slotState == 9)
                flags |= 0x20;
        }
    }

    for (beaconIndex = 0; beaconIndex < gWihDwc.context->beaconCount; beaconIndex++) {
        beacon = &gWihDwc.context->beacon[beaconIndex];
        if (WIH_DWC_IsSsidInFilterList(beacon)) {
            gWihDwc.context->knownGameTimer = 600;
        } else if (WIH_DWC_IsOpenTaggedBeacon(beacon)) {
            gWihDwc.context->taggedGameTimer = 600;
        } else if (DWC_ParseWMBssDesc(gWihDwc.context->matchWork, beacon, &ssidInfo)) {
            switch (ssidInfo.kind) {
            case 0: case 1: case 2: case 3:
            case 10: case 11: case 12:
                gWihDwc.context->knownGameTimer = 600;
                break;
            case 4: case 5: case 6: case 8:
                gWihDwc.context->taggedGameTimer = 600;
                break;
            case 7: case 9:
                break;
            }
        } else if (beacon->ssidLength != 0) {
            if (WIH_DWC_IsPrivacyBeacon(beacon) == 0)
                gWihDwc.context->openNetworkTimer = 400;
            else
                gWihDwc.context->securedNetworkTimer = 400;
        }
    }

    if (gWihDwc.context->knownGameTimer > 0)
        flags |= 0x40;
    if (gWihDwc.context->taggedGameTimer > 0)
        flags |= 0x80;
    if (gWihDwc.context->openNetworkTimer > 0)
        flags |= 0x100;
    if (gWihDwc.context->securedNetworkTimer > 0)
        flags |= 0x200;
    if (gWihDwc.context->alertCooldown != 0)
        gWihDwc.context->alertCooldown = gWihDwc.context->alertCooldown - 1;

    if (flags == 0) {
        gWihDwc.context->alertLevel = 0;
    } else if (gWihDwc.context->pendingAlertLevel != 0 && gWihDwc.context->alertCooldown == 0) {
        gWihDwc.context->alertLevel = gWihDwc.context->pendingAlertLevel;
        gWihDwc.context->alertCooldown = 400;
        gWihDwc.context->pendingAlertLevel = 0;
    }
    gWihDwc.context->beaconCount = 0;
    return flags | 2;
}


/*
 * wih_dwc.c: (re)build the second field of the global.  The guard fires when
 * the pointer is ALREADY set (a re-initialisation warning).  The allocator
 * takes a heap id, a size, a __FILE__ string and a line number.
 */
/*
 * wih_dwc.c: (re)build the second field of the object at 0x021461E0.  The
 * guard is the same file-name call the rest of this file makes - here the
 * polarity is inverted, so it fires when the pointer is ALREADY set (a
 * re-initialisation warning rather than an uninitialised one).
 *
 * The tail calls GFL_NET_AllocAligned(heap, 0xA00, "wih_dwc.c", 0x1C0), which is the
 * debug/allocator shape this SDK uses: a heap ID, a size, a __FILE__
 * string and a line number.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_CreateFilterBuffer.c \
 *       --func WIH_DWC_CreateFilterBuffer --addr 0x02010794 --cc 1.1p1 --thumb
 */
void WIH_DWC_CreateFilterBuffer(u32 heapId)
{
    if (gWihDwc.filterBuf != 0) {
        SAVEDATA_PanicFail((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    gWihDwc.filterBuf = GFL_NET_AllocAligned(heapId, 0xA00, (const char *)sWihDwcFile, 0x1C0);
}


/*
 * wih_dwc.c: the sibling of WIH_DWC_CreateFilterBuffer, same guard on the buffer (here it
 * fires when it is unset); the field is re-read afterwards.  The tail is
 * NCFG_ReadConfig(buf + 0x600, 0).
 */
/*
 * wih_dwc.c: the sibling of WIH_DWC_CreateFilterBuffer in the same packet - same guard on
 * the +0x04 field of the object at 0x021461E0, same file-name call, and the
 * field is re-read afterwards (a second pool load), so the callee is allowed
 * to have set it.  The tail is NCFG_ReadConfig(f4 + 0x600, 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_ResetFilterState.c \
 *       --func WIH_DWC_ResetFilterState --addr 0x020107CC --cc 1.1p1 --thumb
 *
 *           and no branch anywhere else in the image reaches that address -
 *           this function is its only caller - so the site has no witness
 *           outside the compared range and no cut can give it one (shrinking
 *           the range to this one function keeps the call inside it).  The
 *           target is not in an EXACT manifest entry either, so the `matched`
 *           class does not reach it.  Byte-correct as it stands.
 */
void WIH_DWC_ResetFilterState(void)
{
    if (gWihDwc.filterBuf == 0) {
        SAVEDATA_PanicFail((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    NCFG_ReadConfig(gWihDwc.filterBuf->filterState, 0);
}


/*
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * GFL_NET_GetScanResult record sub_0202E8D8 accepts against (key, own MAC address);
 * -1 when none, or when GFL_NET_GetRunState reports the layer inactive.  The guard
 * is a wrapping `if` (it branches forward over the whole body to the shared
 * -1 exit) and the two loop tests are joined by &&.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02177B80 as .word data (0x680B4909, `ldr r1,[pc,#0x24];
 *           ldr r3,[r1]`...), and this call is the only branch to it in the
 *           image.  SEED REQUEST: `ov014 0x02177B80 thumb`, evidence the bl at
 *           arm9 0x0201081A.  Once labelled, `sole-ref/code` (or `label`, if a
 *           second referrer turns up in ov014) can carry the site.
 *           The MATCH is also starred: the listing extent runs to 0x02010888
 *           over three unlabelled leaves, filed as src/matched/unit_02010848.c.
 *
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * GFL_NET_GetScanResult record COMM_PLAYER_SUPPORT_FindPeerRecord accepts against (key, own MAC address);
 * -1 when none, or when GFL_NET_GetRunState reports the layer inactive.  The
 * closing lever over docs/notes/pkt_020107CC.c.txt was the wrapping `if`
 * instead of an early return (the original's guard branches forward over
 * the whole body to the shared -1 exit) plus the two loop tests joined by &&.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_FindSlotByKey.c \
 *       --func WIH_DWC_FindSlotByKey --addr 0x020107FC --thumb
 */
int WIH_DWC_FindSlotByKey(void *searchKey)
{
    u8 mac[8];
    int slot;

    if (GFL_NET_GetRunState() != 0) {
        GFL_NET_GetInitParam();
        OS_GetMacAddress(mac);
        for (slot = 0; slot < 0x10; slot++) {
            if (NET_WHPIPE_GetEntryBeaconKind(slot) == 0x20 && sub_0202E8D8((void *)GFL_NET_GetScanResult(slot), (int)searchKey, (char *)mac) != 0) {
                return slot;
            }
        }
    }
    return -1;
}


/*
 * Three unlabelled leaves: a getter of the halfword at +0x312 of the context
 * object (0 when there is none), a raising setter of the halfword at +0x314
 * (only upward, and only below 4; the first compare is signed, the bound
 * unsigned, so the parameter is u32 and the field is compared as int), and
 * an empty function.
 */
/*
 * wih_dwc.c: three unlabelled leaves after WIH_DWC_FindSlotByKey (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  GFL_NET_SAVE_SetStep
 * (src/matched/GFL_NET_SAVE_SetStep.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
u16 WIH_DWC_GetAlertLevel(void)
{
    if (gWihDwc.context != 0)
        return gWihDwc.context->alertLevel;
    return 0;
}


void WIH_DWC_RequestAlertLevel(u32 level)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0 && (int)context->pendingAlertLevel < (int)level && level < 4)
        context->pendingAlertLevel = level;
}


void WIH_DWC_Dummy(void)
{
}
