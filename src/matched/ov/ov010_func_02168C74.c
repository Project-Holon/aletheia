/*
 * function: FLD_BTL_INST_TOOL_PartySelectStepEventMain
 * address:  0x02168C74
 * packet:   pkt_ov010_02168C74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Battle state step: state 0 starts the request and moves to state 1; state 1 releases the
 * object and stores the result flag. The flag store is written in each arm of the if/else
 * (2026-10-05 recoup), which keeps the store before the epilogue add sp.
 *
 * symbols:
 *   FLD_BTL_INST_TOOL_CreatePokeListEvent  0x02167EF4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    u32 f30;
} C;

struct Evt;
extern int FLD_BTL_INST_TOOL_CreatePokeListEvent(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 func_020307B0(void *p);


int FLD_BTL_INST_TOOL_PartySelectStepEventMain(int a, int *b, C *c)
{
    int r0 = c->f0;
    switch (*b) {
    case 0: {
        int t = FLD_BTL_INST_TOOL_CreatePokeListEvent(r0, c->f10, 0x17, c->f14, c->f18, (int)(&c->f28), (int)(&c->f20), (int)(&c->f24), *(int *)(c->f30 + 0x128));
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)t);
        *b = 1;
        break;
    }
    case 1:
        if (c->f1c != 0)
            func_020307B0((void *)c->f1c);
        if (c->f24 != 0 || (u32)(c->f20 - 7) <= 1)
            *c->fc = 0;
        else
            *c->fc = 1;
        return 1;
    }
    return 0;
}
