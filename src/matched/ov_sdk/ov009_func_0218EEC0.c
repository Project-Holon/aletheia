/*
 * function: gpiDestroyPeer
 * address:  0x0218EEC0
 * packet:   pkt_ov009_0218EEC0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiDestroyPeer (gpipeer.o)
 *
 * symbols:
 *   gsifree     0x0217EAE0  arm
 *   ArrayFree   0x021841B0  arm
 */

struct DArrayImplementation;

struct GPIBuffer {
    char *data;  /* +0x00 */
    int   len;   /* +0x04 */
    int   size;  /* +0x08 */
    int   pad;   /* +0x0c */
};

struct GPIPeer_s {
    char pad0[0x1c];
    struct GPIBuffer inputBuffer;   /* +0x1c */
    struct GPIBuffer outputBuffer;  /* +0x2c */
    struct DArrayImplementation *messages; /* +0x3c */
};

extern void gsifree(void *ptr);
extern void ArrayFree(struct DArrayImplementation *array);

void gpiDestroyPeer(void **connection, struct GPIPeer_s *peer)
{
    gsifree(peer->inputBuffer.data);
    peer->inputBuffer.data = 0;
    gsifree(peer->outputBuffer.data);
    peer->outputBuffer.data = 0;
    if (peer->messages != 0) {
        ArrayFree(peer->messages);
        peer->messages = 0;
    }
    gsifree(peer);
}
