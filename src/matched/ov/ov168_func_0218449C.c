/*
 * function: MICTEST_GetMicLevel
 * address: 0x0218449C
 * packet: pkt_ov168_0218449C
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 pad0; const u8 *data; int count; } Buf;
int MICTEST_GetMicLevel(Buf *p)
{
    int max = 0;
    int i;
    int n = p->count - 1;
    const u8 *d = p->data;
    i = 0;
    for (; i < n; i++) {
        u32 v = d[i];
        if (v < 0x80) v = 255 - v;
        if ((int)v > max) max = v;
    }
    return max;
}
