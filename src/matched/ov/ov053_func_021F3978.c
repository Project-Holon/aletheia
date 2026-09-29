/*
 * function: func_021F3978
 * address:  0x021F3978
 * packet:   pkt_ov053_021F3978
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021F3CF0     0x021F3CF0  data  a4
 */

typedef struct { int v[5]; } T5;

extern T5 d_021F3CF0;
extern int *func_02048F60(int, int, int);
extern void func_020307B0(int *);

void func_021F3978(char *a)
{
    T5 t = d_021F3CF0;
    int i;

    for (i = 0; i < 5; i++) {
        int *p = func_02048F60(0x94, t.v[i], *(unsigned short *)a);
        ((int *)(a + 0x30))[i] = p[0];
        ((int *)(a + 0x44))[i] = p[1];
        func_020307B0(p);
    }
}
