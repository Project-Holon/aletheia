/*
 * file:     unit_021E6DAC.c
 * unit:     yes
 * function: func_021E6DAC, func_021E6E2C, func_021E6E38
 * address:  0x021E6DAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C8BC  0x0689C8BC  thumb
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8C20  0x021B8C20  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021C804C 0x021C804C thumb ov093
 *   func_021C814C 0x021C814C thumb ov093
 *   func_021C8374 0x021C8374 thumb ov093
 *   func_021D8340 0x021D8340 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   d_021F2968     0x021F2968  data    a4
 */
struct QL;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C815C(int *p);
extern u8 func_021B8C20(int kind, u32 flags, u32 v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D67A8(struct QL *p);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021D76BC(int key, u32 val);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021C804C(void *, u8, u32 *);
extern int func_021C814C(u8 *p, u8 v);
extern int func_021C8374(u8 *p, int i);
extern u32 func_021D8340(u32 *);
extern u32 func_0201C314(void *p);
extern int func_0689C8BC(u32);
void func_021E6DAC(int x, int a, int c, u8 *d);
int *func_021E6E2C(int *p);
void func_021E6E38(void *x, void *a, int c, u8 *d);
extern int d_021F2968[];


void func_021E6DAC(int x, int a, int c, u8 *d)
{
    u8 k;
    u16 t;
    u32 fl;

    if (c == func_021D775C(2)) {
        k = func_021D775C(0xe);
        if (k == 6) {
            fl = func_021C7D00((u8 *)a, c);
            k = func_021B8C20(func_021C815C((int *)a), fl, 0);
        }
        if (func_021C7F68((int *)a, k, d) != 0) {
            t = func_021D67A8(func_021C7CF4((int *)a, *d));
            if (t == 0 || func_0201BEB8(t, 6) == 0) {
                func_021D76BC(0x41, 1);
                return;
            }
            func_021D76BC(0x12, t);
            func_021D76BC(0xd, k);
        }
    }
}


int *func_021E6E2C(int *p)
{
    *p = 2;
    return d_021F2968;
}


/*
 * extent: 202 bytes of code followed by 2-byte alignment nop at 021E6F02,
 * then the labelled Thumb veneer func_0689C8BC.
 */
void func_021E6E38(void *x, void *a, int c, u8 *d)
{
    u8 k;
    u8 v;
    u32 flags;
    u32 desc;
    u32 id;
    int ok;
    if (c == func_021D775C(2)) {
        k = func_021D775C(14);
        if (k == 6) {
            flags = func_021C7D00(a, c);
            k = func_021B8C20(func_021C815C(a), flags, 0);
        }
        if (func_021C7F68(a, k, d) != 0) {
            void *m;
            m = func_021C7CF4(a, *d);
            v = *d;
            ok = 0;
            if (func_021D5BB0(m, 3) == 0) {
                if (func_021C804C(a, v, &desc) != 0) {
                    if (func_021C814C(a, v) != 0) {
                        if (func_021C8374(a, v) == 0) {
                            id = func_021D8340(&desc);
                            if (id != 0 && func_0201C314((void *)id) != 0 && func_0689C8BC(id) == 0)
                                ok = 1;
                        }
                    }
                }
            }
            if (ok != 0) {
                func_021D76BC(18, id);
                func_021D76BC(13, k);
                return;
            }
        }
        func_021D76BC(65, 1);
    }
}
