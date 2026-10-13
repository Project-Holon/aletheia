/*
 * function: INTRUDE_COMM_SendPeerLeft
 * address:  0x021738E4
 * packet:   pkt_ov011_021738E4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   INTRUDE_COMM_RecvPeerLeft  0x021738BC  thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned short u16;

int INTRUDE_COMM_IsLinked(void);
struct Entry;
u16 func_02039338(void);
struct Entry *func_020399A8(void);
typedef unsigned char  u8;
void INTRUDE_COMM_RecvPeerLeft(int a, int b, int *c, u8 *d, void *e);
typedef unsigned int   u32;
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);

int INTRUDE_COMM_SendPeerLeft(void *a, int b)
{
    int h;

    if (INTRUDE_COMM_IsLinked() == 0) {
        h = func_02039338();
        INTRUDE_COMM_RecvPeerLeft(h, 4, &b, (u8 *)a, func_020399A8());
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x204, 4, (u32)(&b));
}
