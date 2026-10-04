/*
 * function: func_02173BFC
 * address:  0x02173BFC
 * packet:   pkt_ov012_02173BFC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02034714  0x02034714  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02012944  0x02012944  thumb
 *   func_021CD624  0x021CD624  thumb  ov021
 */

typedef unsigned char u8;

struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02087C6C(void *p);
extern u8 *func_02012944(void *p);
extern void func_021CD624(int a, int b, int c, int d, void *e);

void func_02173BFC(int a, int x, u8 *b, u8 *p)
{
    int *r4;
    int r7;
    int buf[2];

    r4 = *(int **)(p + 0x355C);
    r7 = (int)func_020120F4((const struct Ctx *)(*(int *)(*(u8 **)p + 0xc)));
    if (r4 == 0 || r4[0] == 0 || r4[0x5a] == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    func_02087C6C(buf);
    func_021CD624(r4[0x5a], a, (int)func_02012944((void *)r7), b[0x27], buf);
}
