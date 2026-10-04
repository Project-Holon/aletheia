/*
 * function: func_02173828
 * address:  0x02173828
 * packet:   pkt_ov011_02173828
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02175920  0x02175920  thumb ov011
 *   func_0217592C  0x0217592C  thumb ov011
 */

int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D578(int a, int b);
void func_02082D44(void *d, void *s, int n);
int func_0203D3F8(int a, int b, int c, int d, void *e, int f, int g, int h);
typedef unsigned int   u32;
u32 func_0203D378(void);
void func_02175920(void *p);
void func_0217592C(void *p);

int func_02173828(char *p)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x203) == 1) {
        return 0;
    }
    func_02082D44(p + 0x160, p + 0x3A4, 0x4C);
    r = func_0203D3F8((int)func_020399A8(), 0xFF, 0x203, 0x4C, p + 0x3A4, 0, 0, 1);
    if (r == 1) {
        p[0x8FE] = 0;
        if (func_0203D378() == 1) {
            p[0x903] = 1;
            func_02175920(p + 0x1AC);
            func_0217592C(p + 0x1AC);
        }
    }
    return r;
}
