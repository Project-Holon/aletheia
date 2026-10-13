/*
 * function: TRCARD_SYS_CountStars
 * address:  0x0216F830
 * packet:   pkt_ov010_0216F830
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts how many of five save-data conditions hold.
 *
 * Byte-correct (MATCH*, the 136-byte extent includes two bytes of pad).
 * Blocker: the call to 0x02012EF0 has no witness. 0x02012EF0 is an
 * unlabelled ARM9 Thumb thunk (`ldr r0, [r0]; ldr r3, =0x020071CD;
 * movs r1, #0x3a; bx r3`, i.e. `return func_020071CC(*p, 0x3A);`, with the
 * sibling at 0x02012F00 passing 0x3B) whose only caller is this function.
 * Matching that thunk (ARM9 territory) or seeding its start closes this file.
 *
 * symbols:
 *   GAME_DATA_GetSaveBlock3A  0x02012EF0  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200A73C  0x0200A73C  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef signed int     s32;
struct Big;
struct Blk1AC;
struct Rec1B0;
extern void *GAME_DATA_GetSaveBlock3A(void **p);
extern void *GAME_DATA_GetSaveBlock2A(void *save);
extern void *GAME_DATA_GetLastBattleRecSlot(void *save);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, int id);
extern void *func_0200CA1C(void *save);
extern int func_0200D298(void *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0200A73C(struct Big *p);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);

int TRCARD_SYS_CountStars(void *save)
{
    int n;
    void *a;
    void *b;
    void *c;

    n = 0;
    a = GAME_DATA_GetSaveBlock3A(save);
    b = GAME_DATA_GetSaveBlock2A(save);
    c = GAME_DATA_GetLastBattleRecSlot(save);
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(save), 0x960))
        n++;
    if (func_0200D298(func_0200CA1C(save)))
        n++;
    if (func_0200DBA0(a, 7, 0) && func_0200DBA0(a, 8, 0))
        n++;
    if (func_0200A73C(b))
        n++;
    if (func_0200BDF8(c) >= 30 && func_0200BDFC(c) >= 30)
        n++;
    return n;
}
