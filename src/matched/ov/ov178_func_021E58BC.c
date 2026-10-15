/*
 * function: PARTY_STATUS_UpdateSub
 * address:  0x021E58BC
 * packet:   pkt_021E58BC
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PARTY_STATUS_NetSync  0x021E58F4  thumb  ov178
 *   PARTY_STATUS_NetSync2  0x021E5A90  thumb  ov178
 */
typedef unsigned int u32;

extern int PARTY_STATUS_NetSync(char **out, u32 *ctx, u32 *state);
extern unsigned PARTY_STATUS_NetSync2(void **d, unsigned *c, unsigned *state);

int PARTY_STATUS_UpdateSub(u32 a, u32 b, u32 *c, void *d)
{
    u32 r;

    switch (c[1]) {
    case 0:
        r = PARTY_STATUS_NetSync(d, c, (u32 *)b);
        break;
    case 1:
        r = PARTY_STATUS_NetSync2(d, c, (unsigned int *)b);
        break;
    }
    return r != 0;
}
