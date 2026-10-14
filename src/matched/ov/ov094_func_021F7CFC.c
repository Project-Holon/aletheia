/*
 * function: BTLV_EFFECT_StartEffectWithColor
 * address:  0x021F7CFC
 * packet:   pkt_ov094_021F7CFC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFVM_InitParams  0x021F9844  thumb  ov094
 *   BTLV_EFFVM_StartScript  0x021F94F8  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b0, b1, b2, b3;
    int f4;
    int f8;
    u16 fc;
} Arg;

typedef struct {
    char pad[0x188];
    void *h188;
    char pad2[0x1e8 - 0x18c];
    int f1e8;
} Work;

extern Work *gBtlvEff;

extern void BTLV_EFFVM_InitParams(Arg *a);
extern void BTLV_EFFVM_StartScript(void *h, int a, u32 b, u16 c, Arg *d);

void BTLV_EFFECT_StartEffectWithColor(u32 a, u16 b, u8 c, int d, int e)
{
    Arg l;

    BTLV_EFFVM_InitParams(&l);
    l.b3 = c;
    l.f8 = e;
    l.f4 = d;
    l.fc = b;
    BTLV_EFFVM_StartScript(gBtlvEff->h188, 0, a, 0x23a, &l);
    gBtlvEff->f1e8 = 1;
}
