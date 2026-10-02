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

int func_020120F8(int x);
int func_02012AC8(int x);
int func_02189BBC(int x);
void func_0203064C(int a, int b, int c);
void func_02030678(void *a, int b, int c);
void *func_0203159C(int a, int size, int heap);
void *func_02188030(int a, int b);
void func_02012110(int a, void *b);
int func_0201214C(int x);
int func_02012138(int x);
int func_02026454(int x);
void func_02026400(int x);

int func_02187F00(int a, int *state, int b)
{
    switch (*state) {
    case 0:
        {
            int sz = func_02189BBC(func_02012AC8(func_020120F8(b))) - 0xD000;
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
            func_02012110(b, p);
        }
        (*state)++;
        break;
    case 1:
        if (func_0201214C(b) == 0) {
            int t = func_02012138(b);
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
