/*
 * function: func_021E6CDC
 * address:  0x021E6CDC
 * packet:   pkt_ov093_021E6CDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021E6D90  0x021E6D90  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
struct QG;
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_021E6D90(int e);
extern int func_0201BEB8(int bag, int item);
extern u32 func_021D78AC(u32 range);
extern int func_021C8030(int a, int b, int c);
extern int func_021D76BC(int key, u32 val);

void func_021E6CDC(int x, int a, int c, u32 *d)
{
    void *m;
    u8 n;
    u8 cnt;
    u8 i;
    int e;
    int t = 2;
    u16 id;
    int r;

    if (c == func_021D775C(2)) {
        m = func_021C7CF4(a, c);
        if (func_021D62C4(m, t) != 0) {
            n = func_021D5448(m);
            i = 0;
            cnt = 0;
            for (; i < n; i++) {
                e = func_021D54C0(m, i);
                if (func_021E6D90(e) == 0 && func_0201BEB8(e, 1) == 0) {
                    d[cnt++] = e;
                }
            }
            if (cnt != 0) {
                id = d[(u8)func_021D78AC(cnt)];
                r = func_021C8030(a, c, id);
                func_021D76BC(0x12, id);
                func_021D76BC(0xd, r);
            } else {
                func_021D76BC(0x41, 1);
            }
        }
    }
}
