/*
 * unit:     no
 * function: NNSi_G2dRendererDrawCellTransformedZOffset
 * address:  0x02065D4C
 * packet:   pkt_02065D4C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02147B88  0x02147B88  data  a4
 *   NNS_G2dGetOamSoftEmuAutoZOffsetStep  0x02066E20  arm
 *   func_02066DEC  0x02066DEC  arm
 *   NNS_G2dSetOamSoftEmuAutoZOffsetStep  0x02066E10  arm
 *   func_02066DFC  0x02066DFC  arm
 *   NNSi_G2dRendererDrawCellTransformed  0x02065878  arm
 */

typedef struct
{
    unsigned char pad[0x80];
    int f80;
} Inner;

typedef struct
{
    unsigned char pad[8];
    Inner *f8;
} Ctx;

extern Ctx g_02147B88;

extern int NNS_G2dGetOamSoftEmuAutoZOffsetStep(void);
extern void func_02066DEC(int);
extern void NNS_G2dSetOamSoftEmuAutoZOffsetStep(int);
extern void func_02066DFC(void);
struct Obj02065878;
extern void NNSi_G2dRendererDrawCellTransformed(struct Obj02065878 *c);

void NNSi_G2dRendererDrawCellTransformedZOffset(void *a0)
{
    int saved;

    if (((volatile Ctx *)&g_02147B88)->f8->f80 != 0)
    {
        saved = NNS_G2dGetOamSoftEmuAutoZOffsetStep();
        func_02066DEC(1);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(((volatile Ctx *)&g_02147B88)->f8->f80);
        NNSi_G2dRendererDrawCellTransformed(a0);
        func_02066DEC(0);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(saved);
        func_02066DFC();
    }
    else
    {
        NNSi_G2dRendererDrawCellTransformed(a0);
    }
}
