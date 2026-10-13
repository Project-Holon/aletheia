/*
 * function: BTL_SERVER_CollectReplies
 * address:  0x021BB6A8
 * packet:   pkt_ov093_021BB6A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note 2026-10-05 (final push G6L5): closed by copying each word through a one-word struct
 *   (`typedef struct { u32 w; } W;`, source cursor `W *s`, destination element type W, so
 *   `p->d[i].v[j] = *s++;` is a struct assignment). The word-copy path creates the load before
 *   the destination address, which gives the walking source in r2 with j in r0, cnt in r1 and
 *   the load in r6. Plain `u32 *s` with `*s++` (every spelling) gave j=r1, cnt=r2, s=r3, load r0
 *   (51 bytes); indexed `s[j]` gave `ldr r6,[r2,r4]` (1 byte). Same shape in both lang c99 and c.
 *
 * symbols:
 *   BTL_SERVER_IsClientSlotUsed  0x021BB830  thumb  ov093
 *   BTL_ADAPTER_GetSendBuffer  0x021EEB64  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 h; u32 x[2]; } E;
typedef struct { u32 w; } W;
typedef struct { W v[3]; } D;
typedef struct {
    u8 pad0[0x14];
    E e[4];
    u8 pad1[0x70];
    D d[4];
    u8 c[4];
} P;

extern int BTL_SERVER_IsClientSlotUsed(u8 *);
struct QW;
extern u32 BTL_ADAPTER_GetSendBuffer(struct QW *p, u32 *out);

void BTL_SERVER_CollectReplies(P *p)
{
    u32 i;
    u32 j;
    u32 n;
    u32 cnt;
    W *s;
    E *e;

    for (i = 0; i < 4; i++) {
        e = &p->e[i];
        p->c[i] = 0;
        if (BTL_SERVER_IsClientSlotUsed((u8 *)e) != 0) {
            s = (W *)BTL_ADAPTER_GetSendBuffer((void *)e->h, &n);
            cnt = n >> 2;
            for (j = 0; j < cnt; j++) {
                p->d[i].v[j] = *s++;
                p->c[i]++;
            }
        }
    }
}
