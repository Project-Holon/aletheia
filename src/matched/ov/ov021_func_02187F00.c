/*
 * function: func_02187F00
 * address:  0x02187F00
 * packet:   pkt_ov021_02187F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02189BBC  0x02189BBC  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_02030678  0x02030678  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02188030  0x02188030  thumb
 *   func_02012110  0x02012110  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   d_021DE700     0x021DE700  data
 */

extern char d_021DE700[];

struct Ctx;
unsigned char *func_020120F8(const struct Ctx *x);
struct Rec44;
unsigned short func_02012AC8(const struct Rec44 *x);
int func_02189BBC(int x);
void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
typedef unsigned int   u32;
struct Ctx;
void func_02030678(void *a, u32 b, u32 c);
void *func_0203159C(int a, int size, int heap);
void *func_02188030(int a, int b);
void func_02012110(struct Ctx *p, void *v);
unsigned int func_0201214C(const struct Ctx *x);
unsigned int func_02012138(const struct Ctx *x);
int func_02026454(int x);
void func_02026400(int x);

int func_02187F00(int a, int *state, int b)
{
    switch (*state) {
    case 0:
        {
            int sz = func_02189BBC(func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)b))) - 0xD000;
            func_0203064C(1, 0x15, sz);
        }
        func_0203064C(1, 0x70, 0xD000);
        func_0203064C(0x15, 0x50, 0xC000);
        func_02030678(d_021DE700, 0x10000, 0x89);
        func_0203064C(0x89, 0x92, 0x6400);
        func_0203064C(0x89, 0x93, 0x7400);
        func_0203064C(0x89, 0x96, 0x500);
        {
            void **w = (void **)func_0203159C(a, 4, 0x15);
            void *p = func_02188030(b, 0x15);
            *w = p;
            func_02012110((void *)b, p);
        }
        (*state)++;
        break;
    case 1:
        if (func_0201214C((const struct Ctx *)b) == 0) {
            int t = func_02012138((const struct Ctx *)b);
            switch (func_02026454(t)) {
            case 1:
            case 2:
                func_02026400(t);
                break;
            }
        }
        return 1;
    }
    return 0;
}
