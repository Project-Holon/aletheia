/*
 * function: func_0216B280
 * address:  0x0216B280
 * packet:   pkt_ov010_0216B280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02176850  0x02176850  thumb  ov011
 *   func_02176870  0x02176870  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020124E4(int p);
extern int func_02012138(int p);
extern int func_02158344(int a0);
extern int func_02176850();
extern int func_02176870();

int func_0216B280(int a0, int *state, u8 **work)
{
    int r;
    u16 *p;

    r = func_02158344(func_02012138(func_020124E4(a0)));
    if (r == 0) {
        p = *(u16 **)work;
        if (p != 0)
            *p = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_02176850(r, ((u8 *)work)[4]) == 1)
            (*state)++;
        break;
    case 1:
        if (func_02176870(r) == 1)
            (*state)++;
        break;
    case 2:
        p = *(u16 **)work;
        if (p != 0)
            *p = 1;
        return 1;
    }
    return 0;
}
