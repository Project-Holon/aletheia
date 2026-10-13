/*
 * function: INTRUDE_COMM_IsSessionEndPending
 * address:  0x0215870C
 * packet:   pkt_0215870C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three guards (state == 2, a non-null lookup, bit 6 of a far byte) then a
 * predicate whose one result is inverted.
 *
 * symbols:
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 a : 6; u8 f : 1; u8 b : 1; } FlagsF8;

u32 GAME_COMM_GetKind(void *obj);
u32 GAME_COMM_GetWork(void *obj);
int GFL_NET_IsSessionNull(void);

int INTRUDE_COMM_IsSessionEndPending(void *p, int b)
{
    u8 *q;

    if (GAME_COMM_GetKind((void *)((int)p)) != 2)
        return 0;
    q = (u8 *)GAME_COMM_GetWork((void *)((int)p));
    if (q == 0)
        return 0;
    if (((FlagsF8 *)(q + 0x8f8))->f == 0)
        return 0;
    if (GFL_NET_IsSessionNull() == 1)
        return 0;
    return 1;
}
