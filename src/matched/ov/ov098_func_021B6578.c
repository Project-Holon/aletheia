/*
 * function: PDC_MAIN_StepChooseItem
 * address: 0x021B6578
 * packet: pkt_ov098_021B6578
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 * checks: 1 full callee/forwarder and live-argument audit; 614C word getter, 025D8 explicit r1=1, no arity residue; 2 ov098 6504/6910 twins confirm switch and opaque inputs, no init twin; 3 signed-byte enum stores add truncation (+4 B), pointer copy fields unchanged 53 B; const P is invalid because this function mutates P; 4 enum/struct/zero/signed-byte idioms read, enum zero only helps word stores; 5 fresh idiom list and ov097/098/094 callers plus 6504/6910 neighbours reread, no new init lever.
 * residual: 472 B / 53 concrete mismatches at +0034..+0068 initialization scheduling; 9 iterations, three final nongains, manual order/extraction 2/2, C1 0/C2 0/C3 2/C4 0/C5 0 compiles; types permuter budget 300 no improvement.
 * blockers: potential overlay leaves 021B614C ov098, 022026FC ov094, 021B6B74 ov098; caller is DIFF, so no leaves filed. Parent cleared only conditional B74.
 * next: isolate enum-byte conversion while preserving initialization webs; no additional manual order/extraction variant remains in this run.
 * wave82 (lane R10, retry): best C below unchanged at 53 B. The original's
 *   case-0 block is the source order with only one-slot latency fills: no
 *   word load moves above the word store before it. Every same-base spelling
 *   tried hoists ldr [8]/ldrh [0x6c]/ldr [0x70] up to the call and groups
 *   the zero stores (54 B): raw `*(u32 *)(p + K)` (v1), an inline
 *   init(p + 0x1c, p) (v3), a copy `s = p` for stores (v4, copy-propagated),
 *   `(u32)p + K` integer addresses on the stores (v5) or on the loads (v6),
 *   a `const u8 *` alias for the loads (54 B), and `const u8 *p` with stores
 *   cast back (65 B). A distinct base `u8 *s = p + 0x1c;` with stores
 *   through s and loads through p reproduces the original order exactly,
 *   but s takes r5 (`adds r5,r4,#0; adds r5,#0x1c`), so 387 B / 464. Lead:
 *   a second base the scheduler cannot disambiguate from p that still
 *   colours to r4 (p+0x1c..0x5f is a sub-object: case 1 passes &p[0x1c]
 *   to B_BAG_MAIN_Create).
 * wave82 checks: 1 021B614C (`ldr r0,[r0,#0x10]`), 022026FC and 021B6B74
 *   read r0 only, unchanged arity; definition conflicts: arm9
 *   PALANM_GetPairedCodeForFirst is defined `void (int)` but its result feeds
 *   POKE_TOOL_SetPartyValue (+0x1AE); arm9 TOUCHPANEL_GetTrg is defined `void (void)` but
 *   its return is tested at +0x180; 2 ov098 6504 twin uses the field form,
 *   no init twin; 3 const p (casts on stores) 65 B, const load alias 54 B;
 *   4 struct-field-stores-keep-source-order and integer-address idioms, both
 *   directions 54 B; 5 unfiltered idiom list (575) re-read, nothing new
 *   applies. Runs: baseline + 4 iteration + 4 check compiles; iteration stopped after four
 *   consecutive nonshrinking changes; permuter not re-run (recorded above).
 * recoup 2026-10-05 (wave P26 lane 4): extent is 472 B (not 28), a real Thumb
 *   switch function. Baseline unchanged 53 B differ at +0034..+0068 (case 0 init).
 *   Residue kind: the original keeps source order (loads of [8], [0x70], [0x6c]
 *   stay below the earlier stores, only zero stores fill latency slots); our build
 *   hoists the loads and defers the zero stores. Tried, all 53 B: nested sub-struct
 *   for the stored fields (p->s.f), nested sub-structs for the loaded fields,
 *   parameter as char * with ((struct P *)p)-> casts (as ov098 021B6504 does),
 *   #pragma scheduling off (no change), opt_propagation off (53 B), opt_lifetimes
 *   off (53 B), opt_common_subs off (59 B). Idioms read: removing-const-from-a-read-only-
 *   parameter-sinks-a-grouped-load-below-a-store, an-int-spelled-object-base-hoists-
 *   field-addresses, a-restrict-position-parameter-sinks-a-store-past-the-next-load,
 *   const-pointer-lets-a-field-load-survive-a-store, a-field-spelled-two-ways-is-copy-
 *   propagated (none changes the init order). Callee problems: PALANM_GetPairedCodeForFirst is
 *   defined void (int) but its result is used at +01A8; TOUCHPANEL_GetTrg returns u16 and
 *   is declared int here (fine). The unresolved relocations are 021B614C, 022026FC,
 *   021B6B74 (no witness in this overlay). Still open: the loads need a base the
 *   scheduler cannot separate from the stores that still colours to r4.
 * recoup 2026-10-05 P30R5: MATCH, 0 bytes differ (was 53 B). Fix: the case 0 source
 *   order. The earlier drafts stored the zeros early; the original source stores
 *   w1c, w38, w24, w20, h28 first and the zero stores (h32, w3c, b30, b31, b35),
 *   then w48, w5c. The scheduler fills load-latency slots with the later zero
 *   stores, which gave the original interleaving. The enum zero local is gone
 *   (plain literal 0). Remaining relocations unresolved: 021B614C (tiny leaf, listed
 *   in ov179 as a file; the ov098 copy needs a witness), 022026FC (ov094), 021B6B74
 *   (ov098). Integrator: seed these labels, then the verdict becomes EXACT.
 *
 * prototype: 0202142C result feeds setter at 021B672A; 02035C60 live return tested at 021B66F8.
 * symbols:
 *   ov196_id 0x000000C4 data
 *   ov197_id 0x000000C5 data
 *   PDC_GetMyItem 0x021B614C thumb ov098
 *   PDC_GetMon 0x021B6140 thumb ov098
 *   PDC_MAIN_SetStep 0x021B6364 thumb ov098
 *   PDC_MAIN_StepConfirm 0x021B6504 thumb ov098
 *   PDC_MSG_PrintMessage1 0x021B6988 thumb ov098
 *   PDC_MSG_PrintMessage2 0x021B69C4 thumb ov098
 *   PDC_MSG_Update 0x021B6A3C thumb ov098
 *   PDC_MSG_TakeStreamEnded 0x021B6B74 thumb ov098
 *   BTLV_INPUT_StartPaletteFadeTask 0x022025D8 thumb ov094
 *   BTLV_INPUT_IsScreenBusy 0x022026FC thumb ov094
 *   BTLV_INPUT_StartScreenFadeTask 0x0220266C thumb ov094
 *   B_BAG_MAIN_Create 0x0220C834 thumb ov197
 *   BTLV_EFFECT_StartEffectWithColor 0x021F7CFC thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTLV_EFFECT_ResumeVm 0x021F7C0C thumb ov094
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_02007F1C 0x02007F1C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct P {
    void *parent; u32 pad04; void *w08; u32 pad0c; char *window; u8 *object; u32 pad18;
    u32 b1c; void *w20; u32 w24; u16 h28; u8 pad2a[6]; u8 b30, b31; u16 h32;
    u8 pad34, b35; u8 pad36[2]; void *w38; u32 w3c; u8 pad40[8]; u8 *w48;
    u8 pad4c[16]; u32 w5c, state; int timer; u32 pad68; u16 heap; u16 pad6e;
    void *w70; u8 workspace[1];
};
extern char ov196_id[], ov197_id[];
typedef signed int     s32;
struct Obj;
struct W;
extern int PDC_GetMyItem(int *p);
extern int PDC_GetMon(void *);
extern void PDC_MAIN_SetStep(u8 *, u32);
extern int PDC_MAIN_StepConfirm(char *);
extern void PDC_MSG_PrintMessage1(int, int);
extern void PDC_MSG_PrintMessage2(int, int);
extern int PDC_MSG_Update(u8 *);
extern int PDC_MSG_TakeStreamEnded(u8 *);
extern void BTLV_INPUT_StartPaletteFadeTask(char *, int);
extern int BTLV_INPUT_IsScreenBusy(struct W *p);
extern void BTLV_INPUT_StartScreenFadeTask(struct Obj *p);
extern void B_BAG_MAIN_Create(u8 *);
extern void BTLV_EFFECT_StartEffectWithColor(u32, u16, u8, int, int);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFECT_ResumeVm(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u32 func_02007F1C(u8 *, u16, u16, u16);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u16);
extern int GFL_USE_IsBgmPlaying(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void FADE_Start(u32, int, int, int);
extern int FADE_IsActive(void);
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
int PDC_MAIN_StepChooseItem(struct P *p)
{
    u32 t;
    switch (p->state) {
    case 0:
        p->b1c = PDC_GetMyItem(p->parent);
        p->w38 = p->w70;
        p->w24 = 3;
        p->w20 = p->w08;
        p->h28 = p->heap;
        p->h32 = 0;
        p->w3c = 0;
        p->b30 = 0; p->b31 = 0; p->b35 = 0;
        p->w48 = p->workspace;
        p->w5c = 1;
        BTLV_INPUT_StartPaletteFadeTask(p->window, 1);
        func_02034AC4((s32)ov196_id);
        (p->state)++;
        break;
    case 1:
        if (!BTLV_INPUT_IsScreenBusy((struct W *)p->window)) {
            func_02034AC4((s32)ov197_id);
            B_BAG_MAIN_Create((u8 *)&p->b1c);
            (p->state)++;
        }
        break;
    case 2:
        if (p->b35) {
            func_02034A5C((s32)ov196_id); func_02034A5C((s32)ov197_id);
            BTLV_INPUT_StartScreenFadeTask((struct Obj *)p->window);
            if (p->h32 == 0) p->state = 3;
            else {
                func_02007F1C((u8 *)PDC_GetMyItem(p->parent), p->h32, 1, p->heap);
                p->state = 4;
            }
        }
        break;
    case 3:
        if (!BTLV_INPUT_IsScreenBusy((struct W *)p->window)) PDC_MAIN_SetStep((u8 *)p, (u32)PDC_MAIN_StepConfirm);
        break;
    case 4:
        if (!BTLV_INPUT_IsScreenBusy((struct W *)p->window)) {
            PDC_MSG_PrintMessage1((int)p->object, (int)p->parent);
            (p->state)++;
        }
        break;
    case 5:
        if (PDC_MSG_Update(p->object)) {
            BTLV_EFFECT_StartEffectWithColor(1, p->h32, 4, 1, 0);
            (p->state)++;
        }
        break;
    case 6:
        if (!BTLV_EFFECT_IsBusy()) {
            PDC_MSG_PrintMessage2((int)p->object, (int)p->parent);
            (p->state)++;
        }
        break;
    case 7:
        if (PDC_MSG_TakeStreamEnded(p->object)) GFL_USE_CancelChangeAndPlayBgm(0x518, 0xffff);
        if (PDC_MSG_Update(p->object)) (p->state)++;
        break;
    case 8:
        if (!GFL_USE_IsBgmPlaying()) {
            BTLV_EFFECT_ResumeVm(); GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            (p->state)++;
        }
        break;
    case 9:
        if (!BTLV_EFFECT_IsBusy()) {
            p->timer = 80;
            (p->state)++;
        }
        break;
    case 10:
        if (((u32)KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() || --p->timer == 0) {
            FADE_Start(3, 0, 16, 2);
            (p->state)++;
        }
        break;
    case 11:
        if (!FADE_IsActive()) {
            t = PALANM_GetPairedCodeForFirst(p->h32);
            POKE_TOOL_SetPartyValue((void *)PDC_GetMon(p->parent), 152, t);
            return 1;
        }
        break;
    }
    return 0;
}
