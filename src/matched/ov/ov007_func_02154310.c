/*
 * function: func_02154310
 * address:  0x02154310
 * packet:   pkt_ov007_02154310
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov004 func_02154390; the task
 * callback func_021542CC installs.  Second argument to func_020120B4 is
 * pooled 0x74 (116), a linker overlay id; the third lies in ov116.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov116_id       0x00000074  data   a1
 *   d_021D83A4     0x021D83A4  data   ov116  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_0201210C(void *p);
extern int   func_02012138(u32 a0);
extern int   func_02026454(int x);
extern void *func_020144DC(u32 a0, u32 a1);
extern void  func_02012374(void *obj, void *out);
extern void  func_020120B4(u32 a0, void *a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern void *func_020145CC(u32 a0, u32 a1);
extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);
extern void *func_021BE92C(u32 a0, u32 a1, int a2, int a3, int a4, int a5, int a6);

extern char ov116_id[];
extern char d_021D83A4[];

u32 func_02154310(void *obj, u32 *mode, u32 *args)
{
    u32 h = args[1];
    void *x = func_0201210C((void *)h);

    switch (*mode) {
    case 0:
        if (func_02026454(func_02012138(h)) == 0)
            (*mode)++;
        break;
    case 1:
        func_02012374(obj, func_021BE8D4(h, x, 0, 0));
        (*mode)++;
        break;
    case 2:
        func_02012374(obj, func_020144DC(h, x));
        (*mode)++;
        break;
    case 3:
        func_020120B4(h, ov116_id, d_021D83A4, args);
        (*mode)++;
        break;
    case 4:
        if (func_020120F0(h) == 0) {
            if (args[2] == 0)
                *(u16 *)args[3] = 1;
            else
                *(u16 *)args[3] = 0;
            (*mode)++;
        }
        break;
    case 5:
        func_02012374(obj, func_020145CC(h, x));
        (*mode)++;
        break;
    case 6:
        func_02012374(obj, func_021BE92C(h, x, 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}
