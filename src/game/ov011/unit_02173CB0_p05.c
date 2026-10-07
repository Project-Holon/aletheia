/*
 * file:     unit_02173CB0_p05.c
 * unit:     yes
 * function: func_02174320, func_02174374
 * address:  0x02174320
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020127B8  0x020127B8  thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 */
struct Link;
struct SaveBlock;
struct Entry;
typedef struct H {
    unsigned short f : 3;
} H;

typedef unsigned int   u32;

typedef unsigned short u16;

u32 func_02026478(void *obj);
struct Entry *func_020399A8(void);
u32 func_0203D1A4(struct Link *p);
void *func_020127AC(struct SaveBlock *p, u32 idx);
void func_02082D44(void *d, int s, int n);
void *func_020127B8(void *p);
int func_021736D8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02174320(int a, int b, void *c, char *d);
int func_02174374(int *a);


void func_02174320(int a, int b, void *c, char *d)
{
    int p;

    p = func_02026478((void *)(((int *)d)[1]));
    if (a != func_0203D1A4((struct Link *)((int)func_020399A8())) && ((unsigned char)d[0x8fb] & (1 << a))) {
        func_02082D44(c, (int)func_020127AC((struct SaveBlock *)p, a), 0x10);
        if (a == ((H *)(d + 0x86))->f) {
            d[0x8fb + 0xb] = 1;
        }
    }
}


int func_02174374(int *a)
{
    int r;

    r = (int)func_020127B8((void *)func_02026478((void *)a[1]));
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x21c, 0x10, r);
}
