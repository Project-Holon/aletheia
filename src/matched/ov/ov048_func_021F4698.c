/*
 * function: func_021F4698
 * address:  0x021F4698
 * packet:   pkt_ov048_021F4698
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   d_021F523C     0x021F523C  data  a1
 */

extern void *func_02030734(unsigned short a, int b, int c, const char *d, int e);
extern int func_0201D7EC(int a, int b, int c, int d, int e);
extern const char d_021F523C[];

void *func_021F4698(unsigned char *p)
{
    int i;
    unsigned char *r5;

    r5 = func_02030734(*(unsigned short *)p, 0x1c, 0, d_021F523C, 0x60);
    i = 0;
    *(unsigned short *)r5 = *(unsigned short *)p;
    r5[2] = i;
    r5[3] = p[2];
    r5[4] = p[3];
    r5[5] = p[4];
    *(int *)(r5 + 0x10) = *(int *)(p + 8);
    *(int *)(r5 + 0x18) = i;
    *(int *)(r5 + 8) = (int)func_02030734(*(unsigned short *)p, p[2] * 4, 0, d_021F523C, 0x6d);
    *(int *)(r5 + 0xc) = (int)func_02030734(*(unsigned short *)p, p[2] * 4, 0, d_021F523C, 0x6f);
    for (i = 0; i < p[2]; i++) {
        (*(int **)(r5 + 8))[i] = 0;
        (*(int **)(r5 + 0xc))[i] = 0;
    }
    (*(int **)(r5 + 0xc))[0] = 1;
    *(int *)(r5 + 0x14) = func_0201D7EC(0x17, 0, 0, 0, *(unsigned short *)r5);
    return r5;
}
