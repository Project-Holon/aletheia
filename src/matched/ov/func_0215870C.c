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
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 a : 6; u8 f : 1; u8 b : 1; } FlagsF8;

u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
int GFL_NET_IsSessionNull(void);

int INTRUDE_COMM_IsSessionEndPending(void *p, int b)
{
    u8 *q;

    if (func_02026454((void *)((int)p)) != 2)
        return 0;
    q = (u8 *)func_02026474((void *)((int)p));
    if (q == 0)
        return 0;
    if (((FlagsF8 *)(q + 0x8f8))->f == 0)
        return 0;
    if (GFL_NET_IsSessionNull() == 1)
        return 0;
    return 1;
}
