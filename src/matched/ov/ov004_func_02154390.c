/*
 * function: func_02154390
 * address:  0x02154390
 * packet:   pkt_ov004_02154390
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov003 func_021542C0.  The second
 * argument to func_020120B4 is pooled 0x87 (135): a linker overlay id for
 * ov135, and the third, 0x02202BAC, lies in ov135's window.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov135_id       0x00000087  data   a1
 *   d_02202BAC     0x02202BAC  data   ov135  a4
 */

typedef unsigned int u32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int   func_02026454(int x);
typedef unsigned short u16;
struct Evt;
extern u16 func_02005C44(void);
extern void func_02005E30(u32 a);
extern void *func_020144DC(u32 a0, u32 a1);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void  func_020120B4(u32 a0, void *a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern void  func_02005D90(u32 a0, u32 a1);
extern void func_02005DF8(u32 a);
extern void *func_020145CC(u32 a0);
extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);
extern void *func_021BE92C(u32 a0, u32 a1, int a2, int a3, int a4, int a5, int a6);

extern char ov135_id[];
extern char d_02202BAC[];

u32 func_02154390(void *obj, u32 *mode, u32 *args)
{
    switch (*mode) {
    case 0:
        if (func_02026454(func_02012138((const struct Ctx *)args[1])) == 0)
            *mode = 1;
        break;
    case 1:
        if (args[20])
            func_02012374(obj, func_021BE8D4(args[1], args[2], 0, 0));
        args[0] = func_02005C44();
        func_02005E30(6);
        *mode = 2;
        break;
    case 2:
        func_02012374(obj, func_020144DC(args[1], args[2]));
        *mode = 3;
        break;
    case 3:
        func_020120B4(args[1], ov135_id, d_02202BAC, &args[3]);
        *mode = 4;
        break;
    case 4:
        if (func_020120F0(args[1]) == 0) {
            func_02005D90(args[0], 0xFFFF);
            func_02005DF8(0x3C);
            func_02012374(obj, func_020145CC(args[1]));
            *mode = 5;
        }
        break;
    case 5:
        if (args[20])
            func_02012374(obj, func_021BE92C(args[1], args[2], 0, 0, 1, 0, 0));
        *mode = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}
