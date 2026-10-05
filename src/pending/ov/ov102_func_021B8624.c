/*
 * function: func_021B8624
 * address: 0x021B8624
 * packet: pkt_ov102_021B8624
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * residual: 62/212 bytes differ (final push 2026-10-05 G8L1; was 70/212), 5/5 relocations resolved. Colouring only: the image keeps the window in r4,
 * the y coordinate in r7, palette0 in r6 and the row index in r2 (caller-saved, dead after the switch compare);
 * the build puts the window in r7, the index in r6 and y in r2.
 * note 2026-10-05 (wave P12 lane A2): older draft was docs/notes/pkt_ov102_021B8624.c.txt (70 B, same).
 *   Callee types checked against matched callers (func_020413B0 has u8 and u32 last-parameter forms, func_02045730
 *   returns u8, others void/int): no arity problem. Twin search: grep of func_020413B0, func_020409B4 and
 *   func_02045730 over src/matched/ov gives ov102 021B8724 (same row walk, loop form), ov031 021F07AC, ov107 021EF444,
 *   ov217 021C1038; none has the blink/palette pair. Plain literals: palettes are constants selected per arm, kept as
 *   per-arm locals (idiom: a-constant-kept-in-a-register-after-a-switch-is-assigned-in-every-arm). Tried, all >= 70:
 *   local i = p->index (70), int/u32 i (70), i read before the window call (114, size 208), blink declared last (118),
 *   blink int (120), u8 palettes (105, size 208), last callee parameter u32 with u32 palettes (105), direct row->x..h
 *   call arguments (90), y declared first / window declared before a,c,d (86), i*12+rows operand order (70), six
 *   per-function pragmas (opt_lifetimes, opt_propagation, opt_dead_assignments, scheduling, peephole: 70;
 *   opt_common_subs: 105). Idioms read: constant-kept-in-register-after-switch, call-result-ternary-keeps-default,
 *   flag-argument-ternary-keeps-argument-loads, narrow-flag-local-is-spilled, dead-assignment-in-one-switch-arm,
 *   two-long-lived-values-in-each-others-registers (all no change). Residue is the r2/r6 swap of index vs y.
 * note 2026-10-05 final push G8L1 (39 compiles, 3 rounds): palette1 must be u8 (a u32 adds lsls/lsrs before the stack store that the
 *   original lacks). opt_propagation off with named locals off=i*12 and rows=p->rows (statements in that order) reproduces the original
 *   index load/copy order and the row sequence (adds r1,r6,#0; muls r1,r0,r1; ldr r0,[r5,#0x28]; adds r0,r0,r1) (70 -> 62 B). Residue:
 *   colours only, y is coalesced with r2 (original: idx r2, y r7, win r4, palette0 r6, so the call lacks adds r2,r7,#0; size 208 vs 212).
 *   Single-call forms (ternary argument, pal local) give idx r2 and y r7 like the original but spill win and put blink in r6 (204/200 B):
 *   the original calls are per arm (one stack store per arm, tail cross-jumped). Also tried without effect: real State layout from matched
 *   ov102 021B8464 (windows[4], const Row *rows), rows[i], 12*i, u32 rows field, getRow inline, off local without pragma, int/u32 i,
 *   u16* row[1..4], a,b,c,d orders, y declared first/last/int, declaration orders (move p to r4), palette orders, if/else-if instead of switch (204),
 *   six pragmas on the u8 form (105/103), callee last parameter u32. See research notes in the lane folder.
 * checks: 1 own 51C88/061E4/45730/413B0/409B4 rederived 1/1/1/6/1 inputs and u8 accessor return; 2 ov1028724/86F8 no full twin; 3 scoped u8 window and wide palette unchanged70, byte palette105/208; 4 enum/inline/block-scope/typed-pointer idioms; 5 unfiltered idioms and current1028724/86F8,1038FA0,104829C reread. Next would be field getters with enum results.
 * residual (before G8L1): 212/212, 70 concrete bytes, 5/5 resolved; win/index/palette colors, blink slot and coordinate scheduling.
 * renewed: wave77 final retry: case-local palette70/212 improves71; u8 window plus u32 palette70; all case1 locals scoped70; unsigned long palette70; byte palette check105/208. Four iteration compiles ending with three nonshrinks plus one check; two scheduling variants. Best wide scoped spelling retained.
 * Historical types permuter300 consumed; not repeated. Its85/212 winner added volatile palette and unassigned reads after break; rejected. Palette is assigned only for image-supported indices0/1.
 * symbols:
 * func_02051C88 0x02051C88 arm
 * func_020061E4 0x020061E4 thumb
 * func_02045730 0x02045730 arm
 * func_020413B0 0x020413B0 arm
 * func_020409B4 0x020409B4 arm
  */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
struct Descriptor;
typedef struct { u16 tag,x,y,w,h,pad; } Row;
typedef struct {
    struct Ctx *ctx;
    u8 pad04[0x28-4];
    u8 *rows;
    u16 count, pad2e, index, done, phase, timer;
    u32 enabled;
} State;
extern int func_02051C88(struct Ctx *);
extern void func_020061E4(u32);
extern u8 func_02045730(struct Descriptor *);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_020409B4(u32);
static inline u8 rowY(const Row *row) { return row->y; }
#pragma opt_propagation off
void func_021B8624(State *p)
{
    typedef enum { PaletteNine=9, PaletteTwelve=12 } Palette;
    switch(p->phase) {
    case 0:
        p->done=0;
        if(func_02051C88(p->ctx) && p->enabled) {
            func_020061E4(1352);
            p->timer=0;
            p->phase=1;
        }
        break;
    case 1: {
        u8 win;
        u8 a,b,c,d;
        u8 blink;
        const Row *row;
        u16 i;
        int off;
        u8 *rows;
        u8 palette1;
        u8 palette0;
        blink=(u8)((p->timer/4)%2);
        win=func_02045730(*(struct Descriptor **)((u8 *)p+4+p->index*4));
        i=p->index;
        off=i*12;
        rows=p->rows;
        row=(const Row *)(rows+off);
        b=rowY(row); a=row->x; c=row->w; d=row->h;
        switch(i) {
        case 0: palette1=12; palette0=11; break;
        case 1: palette1=9; palette0=4; break;
        }
        if (blink == 0) func_020413B0(win,a,b,c,d,palette0);
        else func_020413B0(win,a,b,c,d,palette1);
        func_020409B4(win);
        (p->timer)++;
        if(p->timer>=16) {
            p->done=1;
            p->phase=0;
        }
        break;
    }
    }
}
#pragma opt_propagation reset
