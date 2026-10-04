/*
 * function: func_02173CB0
 * address:  0x02173CB0
 * packet:   pkt_ov011_02173CB0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02175648  0x02175648  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct Out;
u32 func_02026478(void *obj);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
int func_021736D8(void);
void func_02175648(void *sv, struct Out *o);
struct Entry;
extern struct Entry *func_020399A8(void);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02173CB0(int *a, int b)
{
    int v;
    int buf[4];

    v = func_02026478((void *)a[1]);
    func_0200BE48(func_02012EBC((struct Big *)v));
    if (func_021736D8() == 0) {
        return 1;
    }
    func_02175648((void *)v, (struct Out *)buf);
    return func_0203D4D0((int)func_020399A8(), (unsigned char)b, 0x20D, 0x10, (u32)buf, 0, 0, 0);
}
