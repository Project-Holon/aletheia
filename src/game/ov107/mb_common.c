/*
 * file:     mb_common.c
 * unit:     yes
 * function: func_021F3C80, func_021F3CB8
 * address:  0x021F3C80
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned long u32;

typedef unsigned short u16;

extern void DC_FlushRange(const void *p, u32 size);
extern void DC_WaitWriteBufferEmpty(void);
extern int MBi_SendMP(u32 *sendbuf, int body_len, u16 pollbmp);
int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf);
u16 MBi_calc_cksum(u16 *buf, int length);


int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf)
{
    DC_FlushRange(sendbuf, (body_len + 31) & ~31);
    DC_WaitWriteBufferEmpty();
    return MBi_SendMP(sendbuf, body_len, pollbmp);
}


u16 MBi_calc_cksum(u16 *buf, int length)
{
    u32 sum;
    int nwords;

    sum = 0;
    nwords = length >> 1;
    while (nwords > 0) {
        sum += *buf++;
        nwords--;
    }
    sum = (sum >> 16) + (u16)sum;
    sum = sum + (sum >> 16);
    return (u16)(sum ^ 0xffff);
}
