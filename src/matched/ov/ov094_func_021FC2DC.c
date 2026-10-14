/*
 * function: BTLV_EFFVM_CmdReturnScript
 * address:  0x021FC2DC
 * packet:   pkt_ov094_021FC2DC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   VM_Return  0x020113C4  thumb
 */
typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    void *f1e8;
    char pad2[0x23c - 0x1ec];
    int f23c;
    char pad3[0x260 - 0x240];
    int f260;
} State;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct Ring;
extern u32 VM_Return(struct Ring *r);

int BTLV_EFFVM_CmdReturnScript(int a, State *s)
{
    int n;

    s->f260--;
    func_020307B0(s->f1e8);
    n = s->f260;
    s->fdc = s->a0[n];
    s->fe0 = s->a1[n];
    s->f1e8 = (void *)s->a2[n];
    s->f4 = s->a3[n];
    VM_Return((struct Ring *)a);
    return s->f23c;
}
