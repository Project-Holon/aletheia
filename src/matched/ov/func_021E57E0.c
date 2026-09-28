/*
 * function: func_021E57E0
 * address:  0x021E57E0
 * packet:   pkt_021E57E0
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC   0x02012EBC  thumb
 *   func_02012944   0x02012944  thumb
 *   func_0200CA1C   0x0200CA1C  thumb
 *   func_0200873C   0x0200873C  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0200CA38   0x0200CA38  thumb
 *
 * Populate the 0x28-byte record from the two source objects.
 */


extern int func_02012EBC(int);
extern void func_02012944(int);
extern int func_0200CA1C(int);
extern int func_0200873C(int);
extern int func_0201AA18(int);
extern int func_0200CA38(int);

void func_021E57E0(int *r5, int *r6, char *r4)
{
    int a;
    int b;
    a = func_02012EBC(r5[5]);
    func_02012944(r5[5]);
    b = func_0200CA1C(r5[5]);
    *(int *)r4 = r6[1];
    *(int *)(r4 + 8) = r5[5];
    *(int *)(r4 + 4) = func_0200873C(a);
    *(char *)(r4 + 0xC) = 1;
    *(char *)(r4 + 0xD) = 1;
    *(char *)(r4 + 0xE) = func_0201AA18(r6[1]);
    *(char *)(r4 + 0xF) = 0;
    *(char *)(r4 + 0x10) = 0;
    *(char *)(r4 + 0x11) = 0;
    *(char *)(r4 + 0x12) = 0;
    *(short *)(r4 + 0x14) = 0;
    *(int *)(r4 + 0x18) = func_0200CA38(b);
    *(int *)(r4 + 0x20) = 0;
    *(int *)(r4 + 0x24) = 0;
}
