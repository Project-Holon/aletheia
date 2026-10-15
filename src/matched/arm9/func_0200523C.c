/*
 * unit:     no
 * function: GFL_USE_InitGameSystems
 * address:  0x0200523C
 * packet:   pkt_02005230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocking class: label. Seven `bl` sites in this range have no branch witness
 * anywhere else in the image, so their relocation fields stay wildcarded:
 *   0x02006F20 (row of this lane, still unfiled), 0x02034704, 0x02005B24,
 *   0x02006544, 0x020082DC, 0x020266E0, 0x02010DB4.
 * Every other site resolves (label / matched) and every concrete byte in the
 * 152-byte body plus its 24-byte pool reproduces: compiled 176 bytes against
 * the original's 176, 0 concrete differences.
 *
 * Two spellings the original needs and that are not guessable from the bytes:
 *   * the first two calls pass FS_OVERLAY_ID-style absolute symbols, not the
 *     numbers 10 and 11. `func_02034AC4(10)` compiles `movs r0, #0xa` (2 bytes,
 *     no pool word) where the original has `ldr r0, [pc, #0x94]` over a pool
 *     word 0x0000000A; declaring `extern u8 ov010_id[]` at 0x0000000A in the
 *     symbols block is what puts the pool word back. Same for 0x0000000B.
 *     (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md)
 *   * 0x02006C01 and 0x02006C2D are two Thumb function pointers. Written as
 *     plain integers mwcc folds the second to `adds r2, r1, #0x2c` off the
 *     first; written as `&PM_VOICE_GetCryIndex` / `&PM_VOICE_PrepareCry` the two ABS32
 *     relocations keep both pool words, which is the original's shape.
 *
 * symbols:
 *   SAVEDATA_SetFailHook   0x02034704  arm
 *   func_0200FB6C   0x0200FB6C  thumb
 *   PM_VOICE_GetCryIndex   0x02006C00  thumb
 *   PM_VOICE_PrepareCry   0x02006C2C  thumb
 *   ov010_id        0x0000000A  data
 *   ov011_id        0x0000000B  data
 *   GFL_USE_ApplySoundModeFromConfig  0x0200530C  thumb
 *   GFL_USE_InitSound  0x02005B24  thumb
 *   PM_VOICE_Init  0x02006544  thumb
 *   SAVE_CONTROL_Create  0x02006F20  thumb
 *   CONFIG_ApplyAppliedFlag  0x02008414  thumb
 *   WIH_DWC_CreateFilterBuffer  0x02010794  thumb
 *   WIH_DWC_ResetFilterState  0x020107CC  thumb
 *   GPOWER_Init  0x02010DB4  thumb
 *   POKE_TOOL_InitSystem  0x020173D0  thumb
 *   PRINTSYS_Init  0x0201C41C  thumb
 *   GAME_BEACON_Create  0x020266E0  thumb
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   GFL_NET_SetupHeaps  0x0203CB34  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02034AC4(int handle);
struct SaveCtrl;
struct Sub02007084Ctrl;
struct Sub02008700Obj;
extern void PRINTSYS_Init(void *arg);
extern void GFL_NET_SetupHeaps(u32 a, u32 b, u32 c, u32 d);
extern void WIH_DWC_CreateFilterBuffer(u32 a0);
extern void WIH_DWC_ResetFilterState(void);
extern void PROCSYS_PushGlobal(u32 a0, u32 a1, u32 a2);
extern struct SaveCtrl *SAVE_CONTROL_Create(int heap);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub02008700Obj *func_0200873C(void *sys);
struct Flags02008414;
extern u8 CONFIG_ApplyAppliedFlag(const struct Flags02008414 *p);
extern void func_02012FF0(void *val);
extern void func_0200F6B8(void);
extern void func_0200F6D8(u32 kind);
extern void SAVEDATA_SetFailHook(u32 a0);
extern void func_0201F344(u16 heap);
extern void POKE_TOOL_InitSystem(u32 heap);
extern void GFL_USE_InitSound(void);
extern void PM_VOICE_Init(u16 a0, u32 a1, u32 a2);
extern void GFL_USE_ApplySoundModeFromConfig(void *obj);
extern void func_020082DC(void);
extern void GAME_BEACON_Create(u32 a0);
extern void GPOWER_Init(void);

extern void func_0200FB6C(void);
extern void PM_VOICE_GetCryIndex(u32 species, u32 form, u32 *out);
extern u32 PM_VOICE_PrepareCry(u32 species, u32 form, void **rec, void **owner, u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch);
extern u8 ov010_id[];
extern u8 ov011_id[];

void GFL_USE_InitGameSystems(void)
{
    int v = 0xC;

    func_02034AC4((int)ov010_id);
    func_02034AC4((int)ov011_id);
    PRINTSYS_Init(0);
    GFL_NET_SetupHeaps(1, 0, 1, v);
    WIH_DWC_CreateFilterBuffer(v);
    WIH_DWC_ResetFilterState();
    PROCSYS_PushGlobal(v - 0xD, (u32)(void *)0x020A0480, 0);
    SAVE_CONTROL_Create(7);
    CONFIG_ApplyAppliedFlag((const struct Flags02008414 *)func_0200873C(func_020070A4()));
    func_02012FF0(func_020070A4());
    func_0200F6B8();
    func_0200F6D8(8);
    SAVEDATA_SetFailHook((u32)&func_0200FB6C);
    func_0201F344(0);
    POKE_TOOL_InitSystem(0);
    GFL_USE_InitSound();
    PM_VOICE_Init(1, (u32)&PM_VOICE_GetCryIndex, (u32)&PM_VOICE_PrepareCry);
    GFL_USE_ApplySoundModeFromConfig(func_0200873C(func_020070A4()));
    func_020082DC();
    GAME_BEACON_Create(1);
    GPOWER_Init();
}
