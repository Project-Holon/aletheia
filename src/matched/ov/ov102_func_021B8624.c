/*
 * function: func_021B8624
 * address: 0x021B8624
 * packet: pkt_ov102_021B8624
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: pass 2 2026-10-06 P2L47: closed from 62 B. The draw and the commit call are written in each arm of the blink
 *   test (the two arms are tail-merged into one call sequence by the compiler); this gives the window four uses, so
 *   palette1 (not the window) is spilled and y keeps its own register with the copy into r2 at the call. Callee
 *   prototypes are the u8 forms used by matched callers (ov103 021B8FA0, ov121 021DDC58): func_020413B0(u8 x6),
 *   func_020409B4(u8). palette0 declared first (window r4, palette0 r6); row fields read in field order x, y, w, h.
 *   opt_propagation off with named off/rows locals keeps the index copy and row address sequence (G8L1).
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
extern void func_020413B0(u8,u8,u8,u8,u8,u8);
extern void func_020409B4(u8);
#pragma opt_propagation off
void func_021B8624(State *p)
{
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
        u8 palette0;
        u8 win;
        u8 a,b,c,d;
        u8 blink;
        const Row *row;
        u16 i;
        int off;
        u8 *rows;
        u8 palette1;
        blink=(u8)((p->timer/4)%2);
        win=func_02045730(*(struct Descriptor **)((u8 *)p+4+p->index*4));
        i=p->index;
        off=i*12;
        rows=p->rows;
        row=(const Row *)(rows+off);
        a=row->x; b=row->y; c=row->w; d=row->h;
        switch(i) {
        case 0: palette1=12; palette0=11; break;
        case 1: palette1=9; palette0=4; break;
        }
        if (blink == 0) {
            func_020413B0(win,a,b,c,d,palette0);
            func_020409B4(win);
        } else {
            func_020413B0(win,a,b,c,d,palette1);
            func_020409B4(win);
        }
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
