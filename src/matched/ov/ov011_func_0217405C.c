/*
 * function: func_0217405C
 * address:  0x0217405C
 * packet:   pkt_ov011_0217405C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02175D20  0x02175D20  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02175BAC  0x02175BAC  thumb ov011
 */

typedef unsigned short u16;

int func_021736D8(void);
void func_02175D20(char *a);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
void func_02175BAC(char *a);

int func_0217405C(char *a, char *b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    func_02175D20(a + 0x1AC);
    r = func_0203D3A8(func_020399A8(), 0x216, 0x34, (u32)(b + 0x78));
    if (r == 1) {
        func_02175BAC(a + 0x1AC);
    }
    return r;
}
