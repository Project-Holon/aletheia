/*
 * function: SOC_RecvFrom
 * address:  0x0215F500
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Ask SOCL_ReadFrom for a two-word header into locals; on success and with a
 * non-null destination object, write the byte-swapped halfword to +2 and the
 * byte-swapped word to +4.  Returns the callee's result.
 *
 * symbols:
 *   SOCL_ReadFrom  0x0215D6C8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int SOCL_ReadFrom(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, int flags);

int SOC_RecvFrom(int a0, int a1, int a2, int a3, u8 *out)
{
    u16 h;
    u32 w;
    int r;

    r = SOCL_ReadFrom(a0, (void *)a1, a2, &h, (long unsigned int *)(&w), a3);
    if (r < 0)
        return r;
    if (out == 0)
        return r;

    *(u16 *)(out + 2) = (u16)(((h >> 8) & 0xff) | ((h << 8) & 0xff00));
    *(u32 *)(out + 4) = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00)
                      | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
    return r;
}
