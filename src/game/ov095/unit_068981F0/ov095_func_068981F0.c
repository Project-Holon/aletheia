/*
 * function: func_068981F0
 * address:  0x068981F0
 * packet:   pkt_ov095_068981F0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0689D6C8     0x0689D6C8  data   ov095  a4
 *   func_068982C0  0x068982C0  thumb  ov095
 *   func_0689827C  0x0689827C  thumb  ov095
 *   func_0689828C  0x0689828C  thumb  ov095
 *   func_0689829C  0x0689829C  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int key;
    int (*fn)(u32 *);
} Ent;

extern Ent d_0689D6C8[5];
extern int func_068982C0(int a, int b);
extern void *func_0689827C(int id, u16 key, int pri, u32 sub_pri, u32 sub, u32 f8, u16 f16);
extern void func_0689828C(void *p, u8 i, u32 v);
extern void func_0689829C(void *p, int i, u32 v);

void *func_068981F0(int a, int b, u32 c, u32 *arr, u8 n)
{
    u32 i;
    u32 v;
    void *r;

    for (i = 0; i < 5; i++) {
        if (a == d_0689D6C8[i].key) {
            int x;
            if (func_068982C0(a, b) == 0)
                break;
            x = d_0689D6C8[i].fn(&v);
            r = func_0689827C(1, a, 1, 0, b, x, v);
            if (r != 0) {
                for (i = 0; i < n; i++)
                    func_0689828C(r, i, arr[i]);
                func_0689829C(r, 6, c);
            }
            return r;
        }
    }
    return 0;
}
