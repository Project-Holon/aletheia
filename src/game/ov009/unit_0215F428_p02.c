/*
 * file:     unit_0215F428_p02.c
 * unit:     yes
 * function: func_0215F4DC, func_0215F500
 * address:  0x0215F4DC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOCL_ReadFrom   0x0215d6c8 arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int SOCL_ReadFrom(int s, void *buffer, int buffer_len,
                         unsigned short *remote_port, unsigned long *remote_ip,
                         int flags);
extern int func_0215D6C8(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, int flags);
int SOC_Recv(int s, void *buf, int len, int flags);
int func_0215F500(int a0, int a1, int a2, int a3, u8 *out);


int SOC_Recv(int s, void *buf, int len, int flags)
{
    return SOCL_ReadFrom(s, buf, len, 0, 0, flags);
}


/*
 * Ask func_0215D6C8 for a two-word header into locals; on success and with a
 * non-null destination object, write the byte-swapped halfword to +2 and the
 * byte-swapped word to +4.  Returns the callee's result.
 */
int func_0215F500(int a0, int a1, int a2, int a3, u8 *out)
{
    u16 h;
    u32 w;
    int r;

    r = func_0215D6C8(a0, (void *)a1, a2, &h, (long unsigned int *)(&w), a3);
    if (r < 0)
        return r;
    if (out == 0)
        return r;

    *(u16 *)(out + 2) = (u16)(((h >> 8) & 0xff) | ((h << 8) & 0xff00));
    *(u32 *)(out + 4) = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00)
                      | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
    return r;
}
