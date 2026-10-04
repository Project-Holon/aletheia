/*
 * function: func_021B644C
 * address:  0x021B644C
 * packet:   pkt_ov098_021B644C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6B5C  0x021B6B5C  thumb  ov098
 *   func_021B6B68  0x021B6B68  thumb  ov098
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021B67A4  0x021B67A4  thumb  ov098
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021B6910  0x021B6910  thumb  ov098
 *   func_021B6A3C  0x021B6A3C  thumb  ov098
 *   func_021B6154  0x021B6154  thumb  ov098
 *   func_021B6140  0x021B6140  thumb  ov098
 *   func_021F8090  0x021F8090  thumb  ov094
 *   func_021B6364  0x021B6364  thumb  ov098
 *   func_021B6504  0x021B6504  thumb  ov098
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021B6B5C(char *p);
extern int func_021B6B68(char *p);
extern void func_021F7EE8(void *m, int key);
extern void func_021F7998(u32 a);
extern void func_021B67A4(int a);
extern int func_021F7EB4(void);
extern void func_021B6910(int a, int b);
extern int func_021B6A3C(u8 *p);
extern int func_021B6154(void *p);
extern int func_021B6140(void *p);
extern void func_021F8090(u32 a, u32 b, u32 c);
extern void func_021B6364(u8 *p, u32 v);
extern int func_021B6504(char *p);

int func_021B644C(char *p)
{
    int r;

    switch (*(int *)(p + 0x60)) {
    case 0:
        func_021B6B5C((char *)(*(int *)(p + 0x14)));
        *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        break;
    case 1:
        if (func_021B6B68((char *)(*(int *)(p + 0x14))) != 0) {
            func_021F7EE8(*(void **)(p + 4), 1);
            func_021F7998(0x231);
            func_021B67A4(2);
            *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021B6910(*(int *)(p + 0x14), *(int *)p);
            *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        }
        break;
    case 3:
        if (func_021B6A3C((u8 *)(*(int *)(p + 0x14))) != 0) {
            r = func_021B6154(*(void **)p);
            func_021F8090(r, func_021B6140(*(void **)p), 1);
            func_021B6B5C((char *)(*(int *)(p + 0x14)));
            *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        }
        break;
    case 4:
        if (func_021B6B68((char *)(*(int *)(p + 0x14))) != 0) {
            func_021F7998(0x23e);
            *(int *)(p + 0x60) = *(int *)(p + 0x60) + 1;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0)
            func_021B6364((u8 *)p, (u32)func_021B6504);
        break;
    }
    return 0;
}
