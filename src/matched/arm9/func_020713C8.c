/*
 * function: NNSi_G3dSendTexMtx4x4
 * address:  0x020713C8
 * packet:   pkt_020713C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Builds a 0x4c-byte descriptor on the stack, fills its transform slots
 * through a dispatch handler selected by the low three bits of the object's
 * flag word, then applies the object's two fixed-point (1.12) scale factors
 * to the three components of each of the two vectors when the factor is not
 * unity, and hands the finished descriptor to NNS_G3dGeBufferOP_N.
 *
 * The two scale fields are declared volatile because the image re-reads
 * [r4,#0x30] / [r4,#0x34] before each of the three smulls in its block,
 * where 1.1p1 -O4,p otherwise caches the field in a register and batches
 * the three multiplies together (308 bytes against the original's 328).
 *
 * symbols:
 *   NNS_G3dGeBufferOP_N    0x0206DDA4  arm
 *   g_dispatch       0x020A8438  data a4
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dSendTexMtx4x4.c \
 *       --func NNSi_G3dSendTexMtx4x4 --addr 0x020713C8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj;
typedef void (*Fn)(int *out, struct Obj *o);

extern Fn   g_dispatch[8];
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);

struct Obj {
    u32 flags;   /* +0x00 */
    char pad[0x2c];
    volatile int sx;  /* +0x30 */
    volatile int sy;  /* +0x34 */
};

void NNSi_G3dSendTexMtx4x4(struct Obj *o)
{
    int buf[0x13];
    int sc;

    if (o->flags & 8) buf[0] = 0x00101610;
    else              buf[0] = 0x00101810;

    buf[1] = 3;
    buf[0x12] = 2;
    buf[0x10] = 0;
    buf[13] = 0;
    buf[12] = 0;
    buf[11] = 0;
    buf[10] = 0;
    buf[9] = 0;
    buf[8] = 0;
    buf[5] = 0;
    buf[4] = 0;
    buf[0x11] = 0x1000;

    g_dispatch[o->flags & 7](&buf[2], o);

    sc = o->sx;
    if (sc != 0x1000) {
        buf[2] = (int)(((long long)sc * buf[2]) >> 12);
        buf[3] = (int)(((long long)o->sx * buf[3]) >> 12);
        buf[14] = (int)(((long long)o->sx * buf[14]) >> 12);
    }
    sc = o->sy;
    if (sc != 0x1000) {
        buf[6] = (int)(((long long)sc * buf[6]) >> 12);
        buf[7] = (int)(((long long)o->sy * buf[7]) >> 12);
        buf[15] = (int)(((long long)o->sy * buf[15]) >> 12);
    }

    {
        char *q = (char *)buf;
        NNS_G3dGeBufferOP_N((u32)buf[0], (int *)(q + 4), 0x12);
    }
}
