/*
 * function: func_021F02FC
 * address:  0x021F02FC
 * packet:   pkt_ov035_021F02FC
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F0640    0x021F0640 data ov035 a4
 *   d_021F064C    0x021F064C data ov035 a4
 *   func_02045EC0 0x02045EC0 arm
 *   func_0202784C 0x0202784C thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02045808 0x02045808 arm
 */

extern int d_021F0640[];
extern char d_021F064C[];
extern int func_02045EC0(int, int);
extern int func_0202784C(void *, int);
extern void func_02027CD8(int, int);
extern void func_02045808(int);

void func_021F02FC(char *p, int a1)
{
    int *d = d_021F0640;

    d[3] = a1;
    d[8] = func_02045EC0(*(int *)(p + 0x38), 5);
    d[11] = func_02045EC0(*(int *)(p + 0x38), 6);
    *(int *)(p + 0x44) = func_0202784C(d_021F064C, *(int *)(p + 0x40));
    func_02027CD8(*(int *)(p + 0x44), 1);
    func_02045808(d[8]);
    func_02045808(d[11]);
}
