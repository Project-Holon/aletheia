/*
 * function: BTLV_EFFVM_CmdStartWaitTask
 * address:  0x021FC3D8
 * packet:   pkt_ov094_021FC3D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_EFFVM_MultiPokeTaskMain  0x021FE930  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094
 */
typedef unsigned short u16;

typedef struct {
    int pad0;
    int pad4;
    void *f8;
    char pad1[0x238 - 0xc];
    u16 h238;
    char pad2[2];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern void *func_02030DA8(void *owner, void *fn, void *p, unsigned a3);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFVM_MultiPokeTaskMain(void *p);
extern char d_0220AE68[];

int BTLV_EFFVM_CmdStartWaitTask(struct Cursor *a, State *s)
{
    int v = VM_GetU32(a);
    int *p;

    p = func_02030734((u16)((s->h238 & 0x7fff) | 0x8000), 0xc, 0, d_0220AE68, 0x1250);
    p[0] = (int)s;
    p[1] = v;
    p[2] = 0;
    BTLV_EFFECT_RegisterTask(func_02030DA8(s->f8, (void *)BTLV_EFFVM_MultiPokeTaskMain, p, 0), 0, 1);
    return s->f23c;
}
