/*
 * file:     scrcmd_palpark.c
 * unit:     yes
 * function: func_021CC544, func_021CC570, func_021CC5D8, func_021CC614, func_021CC6A8, func_021CC6FC
 * address:  0x021CC544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): __FILE__ anchor 021CC5CC (d_021DE5A8 "scrcmd_palpark.c"); 021CC544 has the script-command (work, ctx) shape of 021CC6FC.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216C204  0x0216C204  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02014840  0x02014840  thumb
 *   d_021DE5A8     0x021DE5A8  data
 *   ov107_id       0x0000006B  data
 *   d_021F6D78     0x021F6D78  data  ov107
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1A4  0x0200C1A4  thumb
 *   func_0200C184  0x0200C184  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216530C  0x0216530C  thumb  ov010
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021653C4  0x021653C4  thumb  ov010
 *   func_021656A0  0x021656A0  thumb  ov010
 *   func_021656D0  0x021656D0  thumb  ov010
 *   func_0216573C  0x0216573C  thumb  ov010
 *   func_02165604  0x02165604  thumb  ov010
 *   func_02165634  0x02165634  thumb  ov010
 *   func_0216566C  0x0216566C  thumb  ov010
 *   func_02010F18  0x02010F18  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02010F40  0x02010F40  thumb
 *   func_02010F8C  0x02010F8C  thumb
 *   func_021F5340  0x021F5340  thumb  ov083
 */
struct Ctx;
struct Big;
struct Blk34;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Script virtual machine: the read pointer into the command stream. */
typedef struct ScriptVM {
    u8 pad0[0x14];
    u8 *pc;
} ScriptVM;

/* Parameter block of the ov107 Pal Park process (8 bytes). */
typedef struct PalParkProcParam {
    u8 result;
    void *gameData;
} PalParkProcParam;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *p);
extern int func_0216C204(void *a, u8 *b);
extern void func_0215897C(void *a, void *b);
extern void *func_0215A5E4(void *a0);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern u8 func_0200C1A4(struct Blk34 *p);
extern u32 func_0200C184(struct Blk34 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_0216530C(void *a0);
extern void func_02165534(void *a0);
extern void func_021653C4(void);
extern void func_021656A0(void);
extern void func_021656D0(u8 a);
extern void func_0216573C(void);
extern void func_02165604(void);
extern void func_02165634(void *a0);
extern void func_0216566C(void);
extern u8 func_02010F18(void);
extern void *func_02010F7C(u32 heap);
extern void func_02010F40(u16 v, void *p);
extern void func_02010F8C(void *p);
extern void *func_021F5340(void *p);

int func_021CC544(void *core, void *work);
int func_021CC570(u32 core, u32 work);
int func_021CC5D8(ScriptVM *core, void *work);
int func_021CC614(u32 core, u32 work);
int func_021CC6A8(void *core, void *work);
int func_021CC6FC(u32 unused, u32 work, u32 unused2, u32 unused3);

extern const char d_021DE5A8[];
extern const u8 ov107_id[];
extern u8 d_021F6D78[];

/* Script command: calls the event that ov010 func_0216C204 builds on the field map. */
int func_021CC544(void *core, void *work)
{
    void *script = func_0215A5F4(work);
    void *gsys = func_0215A5DC(work);
    func_0215897C(script, (void *)func_0216C204((void *)gsys, (u8 *)func_0201210C(gsys)));
    return 1;
}

/* Script command: runs the ov107 Pal Park process as a field sub-process. */
int func_021CC570(u32 core, u32 work)
{
    void *script;
    void *gsys;
    void *gameData;
    void *fieldmap;
    PalParkProcParam *param;

    script = func_0215A5F4((void *)work);
    gsys = func_0215A5DC((void *)work);
    gameData = func_0215A5E4((void *)work);
    fieldmap = func_0201210C((void *)gsys);
    param = func_02030734(4, 8, 0, d_021DE5A8, 0x44);
    param->result = 0;
    param->gameData = gameData;
    func_0215897C(script, func_02014840(gsys, (int)fieldmap, (u32)ov107_id, (int)d_021F6D78, (int)param, 0, (int)param));
    return 1;
}

/* Script command: mode byte, result variable; stores one of two values of a save block. */
int func_021CC5D8(ScriptVM *core, void *work)
{
    u8 mode;
    u16 *result;
    void *saveBlock;

    mode = *core->pc;
    core->pc++;
    result = func_02159AE8(core, work);
    saveBlock = func_0200C0F0(func_02012EBC(func_0215A5E4(work)));
    switch (mode) {
    case 0:
        *result = func_0200C1A4(saveBlock);
        break;
    case 1:
        *result = func_0200C184(saveBlock);
        break;
    }
    return 0;
}

/*
 * Script command: sets one game beacon (kind 0..8) with one value.
 * func_020120F4 takes the func_0215A5DC result as its argument (r0 still
 * holds it at the bl), as at every other caller; the results are unused.
 */
int func_021CC614(u32 core, u32 work)
{
    u32 kind;
    u32 value;
    void *gsys;

    kind = func_02159B10((void *)core, (void *)work);
    value = func_02159B10((void *)core, (void *)work);
    gsys = func_0215A5DC((void *)work);
    func_020120F4(gsys);
    func_0201210C((void *)gsys);
    func_0215A5F4((void *)work);
    switch (kind) {
    case 0:
        func_0216530C((void *)value);
        break;
    case 1:
        func_02165534((void *)value);
        break;
    case 2:
        func_021653C4();
        break;
    case 3:
        func_021656A0();
        break;
    case 4:
        func_021656D0(value);
        break;
    case 5:
        func_0216573C();
        break;
    case 6:
        func_02165604();
        break;
    case 7:
        func_02165634((void *)value);
        break;
    case 8:
        func_0216566C();
        break;
    }
    return 0;
}

/*
 * Script command: stores the expiring G power id (0x30 = none) and whether a
 * power is still active after that one is cleared.
 */
int func_021CC6A8(void *core, void *work)
{
    u16 *powerId = func_02159AE8(core, work);
    u16 *stillActive = func_02159AE8(core, work);
    void *powerTable;

    *powerId = func_02010F18();
    if (*powerId != 0x30) {
        powerTable = func_02010F7C(0x8015);
        func_02010F40(*powerId, powerTable);
        func_02010F8C(powerTable);
        *stillActive = (func_02010F18() != 0x30) ? 1 : 0;
    } else {
        *stillActive = 0;
    }
    return 0;
}

/* Script command: calls the event that ov083 func_021F5340 builds. */
int func_021CC6FC(u32 unused, u32 work, u32 unused2, u32 unused3)
{
    func_0215897C(func_0215A5F4((void *)work), func_021F5340(func_0215A5DC((void *)work)));
    return 1;
}
