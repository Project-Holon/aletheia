/*
 * function: DWCi_InitReliableQueue
 * address:  0x021B2F98
 * packet:   pkt_ov013_021B2F98
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVoiceFramePool 0x021B4C24 data
*/

typedef struct E E;

typedef struct {
    E *cur;
    E *buf;
} G;

extern G gVoiceFramePool;

void DWCi_InitReliableQueue(void)
{
    gVoiceFramePool.cur = 0;
    gVoiceFramePool.buf = 0;
}

