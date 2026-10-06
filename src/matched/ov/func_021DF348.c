/*
 * function: func_021DF348
 * address:  0x021DF348
 * packet:   pkt_021DF348
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202E474  0x0202E474  thumb
 *   func_02031348  0x02031348  arm
 *   d_021BB96C     0x021BB96C  data  ov170  a4
 *   ov070_id       0x00000046  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

struct BigObj;
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern void func_02031348(void *a, u32 id, void *b, void *c);
extern u8 ov070_id[];

int func_021DF348(void **p)
{
    void *r = func_0202E474((const struct BigObj *)(*(u32 *)p[0]), 0, 2, 0x4b);

    func_02031348(p[1], (u32)ov070_id, (void *)0x021bb96c, r);
    p[3] = r;
    return 0;
}
