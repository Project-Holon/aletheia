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
 * residual: 70/212 bytes differ, 5/5 relocations resolved. Colouring only: the image keeps the window in r4,
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
 * checks: 1 own 51C88/061E4/45730/413B0/409B4 rederived 1/1/1/6/1 inputs and u8 accessor return; 2 ov1028724/86F8 no full twin; 3 scoped u8 window and wide palette unchanged70, byte palette105/208; 4 enum/inline/block-scope/typed-pointer idioms; 5 unfiltered idioms and current1028724/86F8,1038FA0,104829C reread. Next would be field getters with enum results.
 * residual: 212/212, 70 concrete bytes, 5/5 resolved; win/index/palette colors, blink slot and coordinate scheduling.
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
        u32 palette1;
        u8 palette0;
        blink=(u8)((p->timer/4)%2);
        win=func_02045730(*(struct Descriptor **)((u8 *)p+4+p->index*4));
        i=p->index;
        row=(const Row *)(p->rows+i*12);
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
