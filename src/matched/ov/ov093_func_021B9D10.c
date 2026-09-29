/*
 * function: func_021B9D10
 * address:  0x021B9D10
 * packet:   pkt_ov093_021B9D10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 168, compiled 166, trailing padding)
 *
 * symbols:
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B8B78  0x021B8B78  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021D5848  0x021D5848  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021D5854  0x021D5854  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Arr { void *e[6]; u8 n; };

extern int func_021D5B7C(void *m);
extern u32 func_021B8588(void *p);
extern int func_021B8B78(void *p, int k);
extern int func_021D59B4(void *p, int k);
extern u32 func_021D5844(void *m);
extern void func_021D5848(void *m, u32 v);
extern int func_021D5864(void *m);
extern void func_021D5854(void *m);
extern int func_021D6C24(void *m);

void func_021B9D10(char *a, struct Arr *arr, int k)
{
    int j;
    void *m;
    int h;

    for (j = arr->n - 1; j > 0; j--) {
        if (func_021D5B7C(arr->e[j]) != 0)
            break;
    }
    if (func_021B8588(a) != 3)
        k = func_021B8B78(a, k);
    else
        k = 3;
    for (; k < arr->n; k++) {
        m = arr->e[k];
        if (func_021D59B4(m, 0x11) == 0x95) {
            if (k < j) {
                func_021D5848(m, func_021D5844(arr->e[j]));
            } else {
                h = func_021D5864(m);
                if (h != *(int *)(a + 0x2c0))
                    func_021D5854(m);
            }
        }
    }
    for (k = 0; k < arr->n; k++)
        func_021D6C24(arr->e[k]);
}
