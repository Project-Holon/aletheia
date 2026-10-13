/*
 * function: func_0215CB08
 * address:  0x0215CB08
 * packet:   pkt_ov010_0215CB08
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls func_02165344, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * func_0215C63C.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but func_0215C63C
 * (which forwards its r2 to GAMESYSTEM_CallProc's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. d_021BA1A4 (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching func_0215C63C, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> GAMESYSTEM_CallProc r1) and the hints resolve. Not fixable in C.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02165344  0x02165344  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   d_021BA1A4     0x021BA1A4  data  ov221  a4
 *   d_021BA250     0x021BA250  data  ov222  a4
 *   d_021B9BF8     0x021B9BF8  data  ov224  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Box8 {
    void *sys;          /* 0x00 */
    u32 v;              /* 0x04 */
} Box8;

extern void *func_0215A5DC(void *vm);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u32 func_02159B10(void *c, void *vm);
extern void func_02165344(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char d_021728F0[];
extern const u8 d_021BA1A4[];
extern const u8 d_021BA250[];
extern const u8 d_021B9BF8[];
extern u8 ov221_id[];
extern u8 ov222_id[];
extern u8 ov224_id[];

int func_0215CB08(void *c, void *vm)
{
    void *sys;
    void *sub;
    u32 mode;
    u32 v;
    Box8 *b;
    void **w;

    sys = func_020120F4(func_0215A5DC(vm));
    sub = func_02012944(sys);
    mode = func_02159B10(c, vm);
    v = func_02159B10(c, vm);
    if (mode != 2) {
        func_02165344();
    }
    switch (mode) {
    case 0:
        b = func_02030734(4, 8, 1, d_021728F0, 0x22B);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov221_id, d_021BA1A4, b, 0, 0);
        break;
    case 1:
        b = func_02030734(4, 8, 1, d_021728F0, 0x233);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov222_id, d_021BA250, b, 0, 0);
        break;
    case 2:
        w = func_02030734(4, 4, 1, d_021728F0, 0x23C);
        *w = sub;
        func_0215C63C(c, vm, (u32)ov224_id, d_021B9BF8, w, 0, 0);
        break;
    }
    return 1;
}
