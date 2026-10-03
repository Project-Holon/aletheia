/*
 * function: func_0218C0D8
 * address:  0x0218C0D8
 * packet:   pkt_ov021_0218C0D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204779C  0x0204779C  arm
 *   func_02047790  0x02047790  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
extern int func_0204779C(int *p);
extern void *func_02047790(void *h, u16 i);
extern void func_0204762C(struct Rec *p);
extern void *func_02047788(void *h);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);

void func_0218C0D8(void **s)
{
    int n;
    int i;
    void *r;

    if (s[0] != 0) {
        n = func_0204779C(s[0]);
        for (i = 0; i < n; i++) {
            void *o = func_02047790(s[0], i);
            if (o != 0)
                func_0204762C(o);
        }
        r = func_02047788(s[0]);
        func_02047738(s[0]);
        s[0] = 0;
        s[1] = 0;
        func_02047504(r);
    }
}
