/*
 * function: func_021CCF7C
 * address:  0x021CCF7C
 * packet:   pkt_ov021_021CCF7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02020D0C  0x02020D0C  thumb
 *   func_02020298  0x02020298  thumb
 */

typedef struct {
    int pad[4];
    int f10;
} Info;

typedef unsigned int   u32;
extern u32 func_02020D0C(unsigned char *p);
typedef unsigned char  u8;
struct Obj;
extern void func_02020298(struct Obj *obj, u8 a, u8 b, u8 c);

void func_021CCF7C(void *p, int k)
{
    Info *i = (Info *)func_02020D0C(p);

    if (k == 0 && i->f10 == 1) {
        func_02020298(p, 1, 0, 2);
        return;
    }
    if (k == 1) {
        func_02020298(p, 1, 0, 2);
        return;
    }
    func_02020298(p, 1, 0, 2);
}
