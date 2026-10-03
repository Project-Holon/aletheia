/*
 * function: func_021B832C
 * address: 0x021B832C
 * packet: pkt_ov070_021B832C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: func_021BA9C0 reads the count in r2; passing j keeps it in r2.
 * symbols:
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   func_021B8280 0x021B8280 thumb ov070
 *   func_021BA9C0 0x021BA9C0 thumb ov070
 */
typedef struct { int v[11]; } T44;
typedef struct { unsigned char v[4]; } T4;
extern T44 d_021BB998;
extern T4 d_021BB95C;
extern void func_021B8280(int p, T4 *a);
extern void func_021BA9C0(unsigned char *p, int *tbl, int n);
void func_021B832C(int p)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    func_021B8280(p, &a);
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            *(int *)((char *)p + j * 4 + 0x828) = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    func_021BA9C0((unsigned char *)p, tmp, j);
}
