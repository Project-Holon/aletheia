/*
 * function: func_02184504
 * address:  0x02184504
 * packet:   pkt_ov020_02184504
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A30  0x02012A30  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02184360  0x02184360  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
struct Evt;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern void *func_02184360(u8 *p, int value);

int func_02184504(int a, int *state, u8 *p)
{
    int r;
    int v;
    int x;
    int z;
    int y;

    x = *(int *)(p + 0);
    z = *(int *)(p + 8);
    y = *(int *)(p + 4);
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        r = (int)func_02161824((void *)x, (void *)z);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 1:
        func_02029D44(v, y, *(u16 *)(p + 0x14), (u8)*(u16 *)(p + 0x4a));
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 2:
        r = (int)func_02184360(p, *(u8 *)(p + 0x30));
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
