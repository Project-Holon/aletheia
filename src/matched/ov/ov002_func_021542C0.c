/*
 * function: func_021542C0
 * address:  0x021542C0
 * packet:   pkt_ov002_021542C0
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov003 func_021542C0 and ov004
 * func_02154390.  The second argument to func_020120B4 is pooled 0xC7 (199),
 * a linker overlay id for ov199; the third, 0x02213C4C, lies in its window.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov199_id       0x000000C7  data   a1
 *   d_02213C4C     0x02213C4C  data   ov199  a4
 *   d_02154460     0x02154460  data   ov002  a4
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
extern u32   func_020120F4(u32 a0);
extern void  func_020120B4(u32 a0, void *a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern void  func_02005D90(u32 a0, u32 a1);
extern void func_02005DF8(u32 a);
extern void *func_020145CC(u32 a0);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020307B0(void *p);
extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);
extern void *func_021BE92C(u32 a0, u32 a1, int a2, int a3, int a4, int a5, int a6);

extern char ov199_id[];
extern char d_02213C4C[];
extern char d_02154460[];

u32 func_021542C0(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[1];
    u32 *p;

    switch (*mode) {
    case 0:
        if (func_02026454(func_02012138((const struct Ctx *)a0)) == 0) {
            args[0] = func_02005C44();
            func_02005E30(6);
            (*mode)++;
        }
        break;
    case 1:
        if (args[7])
            func_02012374(obj, func_021BE8D4(a0, args[2], 0, 0));
        (*mode)++;
        break;
    case 2:
        func_02012374(obj, func_020144DC(a0, args[2]));
        (*mode)++;
        break;
    case 3:
        p = func_02030734(4, 0x14, 1, d_02154460, 0x86);
        args[3] = (u32)p;
        p[2] = args[4];
        p[0] = func_020120F4(a0);
        p[1] = args[6];
        p[3] = args[5];
        func_020120B4(a0, ov199_id, d_02213C4C, (void *)args[3]);
        (*mode)++;
        break;
    case 4:
        if (func_020120F0(a0) == 0) {
            func_020307B0((void *)args[3]);
            (*mode)++;
        }
        break;
    case 5:
        (*mode)++;
        break;
    case 6:
        func_02012374(obj, func_020145CC(a0));
        func_02005D90(args[0], 0xFFFF);
        func_02005DF8(0x3C);
        (*mode)++;
        break;
    case 7:
        if (args[7])
            func_02012374(obj, func_021BE92C(a0, args[2], 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
