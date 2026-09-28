/*
 * function: func_02157C48
 * address:  0x02157C48
 * packet:   pkt_ov010_02157C48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen, same size; loop count/compare value swap r6/r7 (count should be r6, the far word r7), tst operand order, and the 020056EC result copy to r2; tried declaration orders, hoisted v, operand swaps.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_0203F328  0x0203F328  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_02157960  0x02157960  thumb
 *   func_02157AF0  0x02157AF0  thumb
 *   func_02157B88  0x02157B88  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_020399A8();
extern int func_02039CB4();
extern void func_02039C68();
extern void func_0203F328();
extern int func_020056EC();
extern void func_02157960();
extern void func_02157AF0();
extern void func_02157B88();

void func_02157C48(int *p)
{
    u8 *b = (u8 *)p;
    int *e;
    int i;
    unsigned n;
    if (func_02039CB4(func_020399A8(), 0x17, (u8)p[0]) == 0)
        return;
    if (b[0x675] != 0) {
        e = 0;
        b[0x676] = 0;
        n = p[0x1E];
        for (i = 0; i < n; i++) {
            e = (int *)(b + 8 + i * 16);
            if (e[2] == *(int *)(b + 0x67C) && (e[3] & *(int *)(b + 0x680))) {
                b[0x677] = i;
                b[0x676] = 1;
                break;
            }
        }
        func_02157960(p, (void *)func_02157B88, 0x188);
        if (b[0x676] == 1) {
            int t = func_020056EC(0);
            *(int *)(b + 0x668) = t;
            func_0203F328(e[1], e[0]);
            *(int **)(b + 0x664) = e;
        }
        return;
    }
    func_02039C68(func_020399A8(), 0x18, (u8)p[0]);
    func_02157960(p, (void *)func_02157AF0, 0x193);
}
