/*
 * function: func_02173744
 * address:  0x02173744
 * packet:   pkt_ov012_02173744
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02012944  0x02012944  thumb
 *   func_020263D8  0x020263D8  thumb
 *   func_021653C4  0x021653C4  thumb  ov010
 *   d_02175610     0x02175610  data   ov012  a1
 *   d_02175614     0x02175614  data   ov012  a1
 */

struct Ctx;
extern unsigned int func_02012138(const struct Ctx *a);
typedef unsigned char  u8;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02026454(int a);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_02012944(void *p);
extern void func_020263D8(int a, int b, void *c);
extern void func_021653C4(void);
extern char d_02175610[];
extern char d_02175614[];

void func_02173744(int a)
{
    int r5;
    int r7;
    int *p;

    r5 = func_02012138((const struct Ctx *)a);
    r7 = (int)func_020120F4((const struct Ctx *)a);
    if (func_02026454(r5) != 0) {
        func_02034714(d_02175610, 0, d_02175610);
    }
    p = func_02030734(5, 0x10, 1, d_02175614, 0x37);
    p[0] = (int)func_02012944((void *)r7);
    p[1] = r5;
    p[2] = r7;
    p[3] = a;
    func_020263D8(r5, 3, p);
    func_021653C4();
}
