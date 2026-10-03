/*
 * function: func_021E1A2C
 * address:  0x021E1A2C
 * packet:   pkt_ov093_021E1A2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021E1AE4  0x021E1AE4  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7D44  0x021C7D44  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Ent { u16 a; u16 b; u8 c; u8 d; u8 e; u8 f; } Ent;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021E1AE4(void *m, int x, Ent *out);
extern int func_021C7D00(void *a, int b);
extern int func_021C7D44(char *p, int i);
extern int func_021C8030(u8 *p, int v, u16 k);
extern int func_021D76BC(int key, u32 val);

void func_021E1A2C(void *p, int id, int u, int x)
{
    Ent e;
    int t;
    int r;
    if (id == func_021D775C(3)) {
        if (func_021E1AE4(func_021C7CF4(p, id), x, &e)) {
            t = e.d;
            if (func_021C7D00(p, t) == 6) {
                r = e.e;
                t = 0x1f;
                if (r != 6)
                    t = func_021C7D44(p, r);
                if (t == 0x1f) {
                    r = func_021C8030(p, id, 1);
                    if (r != 6)
                        t = func_021C7D44(p, r);
                    if (t == 0x1f)
                        t = e.d;
                }
            }
            func_021D76BC(4, t);
        }
    }
}
