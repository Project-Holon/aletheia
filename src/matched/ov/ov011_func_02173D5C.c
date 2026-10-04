/*
 * function: func_02173D5C
 * address:  0x02173D5C
 * packet:   pkt_ov011_02173D5C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02175938  0x02175938  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned int   u32;
struct Link;
struct SaveBlock;
u32 func_02026478(void *obj);
void func_02175938(void *a, void *b, int c);
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D1A4(struct Link *p);
void *func_020127AC(struct SaveBlock *p, u32 idx);
void func_02082D44(void *d, int s, int n);

void func_02173D5C(int a, int b, char *c, char *d)
{
    int v;
    int t;

    v = func_02026478((void *)(*(int *)(d + 4)));
    t = (unsigned char)c[0x24];
    func_02175938(d + 0x1AC, c, t);
    if (t != func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        func_02082D44(c, (int)func_020127AC((struct SaveBlock *)v, t), 0x10);
    }
}
