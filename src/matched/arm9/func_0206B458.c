/*
 * function: NNSi_G3dSbcRun
 * address:  0x0206B458
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * The object driver loop of the 0x0206B7D0 script family: clear bit 6 of the
 * flag word at +0x08, read the opcode byte through the program pointer at
 * +0x00, dispatch its low five bits through the handler table at 0x020A83B8
 * with the top three bits as the second argument, and repeat until bit 5 of
 * the flag word is set.  2.0/sp2 pin: under dsi/1.1p1 the same source is 72
 * bytes with 9 concrete bytes out (the state pointer takes r0 and the object
 * argument is deferred); see docs/notes/NNSi_G3dSbcRun.c.txt.
 *
 * symbols:
 *   gSbcFuncTable  0x020A83B8  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Ctx0206B458 Ctx0206B458;
struct Ctx0206B458 {
    u8 *f00;
    u32 f04;
    u32 f08;
};

typedef void (*Cb0206B458)(Ctx0206B458 *ctx, u32 arg);

extern Cb0206B458 gSbcFuncTable[];

void NNSi_G3dSbcRun(Ctx0206B458 *ctx)
{
    u32 cmd;

    do {
        ctx->f08 &= ~0x40u;
        cmd = *ctx->f00;
        gSbcFuncTable[cmd & 0x1f](ctx, cmd & 0xe0u);
    } while ((ctx->f08 & 0x20u) == 0);
}
