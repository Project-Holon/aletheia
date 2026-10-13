/*
 * file:     unit_0206DB24.c
 * unit:     yes
 * function: func_0206DB24, NNS_G3dGeSetBuffer, NNS_G3dGeReleaseBuffer
 * address:  0x0206DB24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0214BAB4      0x0214BAB4  data  a4
 *   g_0214BAB4       0x0214BAB4  data
 */
typedef unsigned int u32;

extern void   func_0206DB80(void);
int NNS_G3dGeIsBufferExist(void);
void NNS_G3dGeSetBuffer(u32 *cmdBuffer);
void *NNS_G3dGeReleaseBuffer(void);
extern char d_0214BAB4;
extern char *g_0214BAB4;


/* NNS_G3dGeIsBufferExist (the SDK table names this address NNS_G3dGeIsBufferExist; wrong). */
int NNS_G3dGeIsBufferExist(void)
{
    return *(void **)&d_0214BAB4 != 0;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGeSetBuffer.c \
 *       --func NNS_G3dGeSetBuffer --addr 0x0206DB40 --cc 1.1p1 --arm
 */
/* NNS_G3dGeSetBuffer: install the geometry command buffer (empty) if none is set. */
void NNS_G3dGeSetBuffer(u32 *cmdBuffer)
{
    if (g_0214BAB4 == 0) {
        *cmdBuffer = 0;
        g_0214BAB4 = (char *)cmdBuffer;
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGeReleaseBuffer.c \
 *       --func NNS_G3dGeReleaseBuffer --addr 0x0206DB60 --cc 1.1p1 --arm
 */
/* NNS_G3dGeReleaseBuffer: flush the pending commands, then hand the buffer back. */
void *NNS_G3dGeReleaseBuffer(void)
{
    void *cmdBuffer;

    func_0206DB80();
    cmdBuffer = g_0214BAB4;
    g_0214BAB4 = 0;
    return cmdBuffer;
}
