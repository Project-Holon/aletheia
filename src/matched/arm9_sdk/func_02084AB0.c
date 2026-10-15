/*
 * function: OSi_SyncWithOtherProc
 * address:  0x02084AB0
 * packet:   pkt_02084AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   SVC_WaitByLoop  0x02004490  thumb
 *
 * Bit-banged ack protocol over a four-byte register window.  a0 == 0 selects
 * the send direction: the window is walked with the nibble counter in the top
 * bit, and the loop only advances when the peer answers p[2].  a0 != 0 is the
 * receive direction: p[1] mirrors p[0] and the mirrored bytes are accumulated
 * until the sum passes 0x300, then the window is re-armed and the final handshake
 * waits for p[3].
 *
 * The window pointer is `volatile`: every store is followed by a fresh load of
 * the same byte in the image (strb r0,[r5] then ldrb r1,[r5]; strb r6,[r5,#1]
 * then ldrb r1,[r5,#1]), which a non-volatile pointer would let the compiler
 * forward.
 */

typedef unsigned char u8;

extern void SVC_WaitByLoop(int v);

void OSi_SyncWithOtherProc(int a0, volatile u8 *p)
{
    if (a0 == 0) {
        int i = 0;

        p[2] = 0;
        do {
            p[0] = (u8)((i & 0xf) | 0x80);
            while (p[0] != p[1] && p[2] == 0) {
                SVC_WaitByLoop(0x400);
            }
            i++;
        } while (p[2] == 0);
        p[3] = 1;
    } else {
        int sum = 0;

        p[1] = 0;
        while (sum < 0x300) {
            if (p[1] != p[0]) {
                p[1] = p[0];
                sum += p[1];
            } else {
                SVC_WaitByLoop(0x400);
            }
        }
        p[3] = 0;
        p[2] = 1;
        while (p[3] == 0) {
            SVC_WaitByLoop(0x400);
        }
    }
}
