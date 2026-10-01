/*
 * function: func_021C2DE0
 * address: 0x021C2DE0
 * packet: pkt_ov217_021C2DE0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C408C 0x021C408C data ov217 a1
 */
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern char d_021C408C[];
void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count)
{
    int i;
    *(int *)(p + 4) = 1;
    *(unsigned short **)(p + 8) = dst;
    *(unsigned char *)(p + 16) = count;
    *(unsigned short **)(p + 12) = func_02030734(*(unsigned short *)p, count * 2, 0, d_021C408C, 728);
    for (i = 0; i < count; i++)
        (*(unsigned short **)(p + 12))[i] = src[i];
}
