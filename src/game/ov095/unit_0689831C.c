/*
 * file:     unit_0689831C.c
 * unit:     yes
 * function: func_0689831C, func_06898328
 * address:  0x0689831C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0689D698 0x0689D698 data ov095 a4
 *   func_068983DC  0x068983DC  thumb  ov095
 *   func_068983EC  0x068983EC  thumb  ov095
 *   func_068983FC  0x068983FC  thumb  ov095
 *   func_0689840C  0x0689840C  thumb  ov095
 *   func_0689841C  0x0689841C  thumb  ov095
 *   func_0689842C  0x0689842C  thumb  ov095
 *   func_0689843C  0x0689843C  thumb  ov095
 *   func_0689844C  0x0689844C  thumb  ov095
 *   func_0689845C  0x0689845C  thumb  ov095
 *   func_0689846C  0x0689846C  thumb  ov095
 *   func_0689847C  0x0689847C  thumb  ov095
 *   func_0689848C  0x0689848C  thumb  ov095
 *   func_0689849C  0x0689849C  thumb  ov095
 *   func_068984AC  0x068984AC  thumb  ov095
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u8 pad[0x10];
    u32 w6;
} D;

typedef struct {
    u8 pad0[4];
    u16 h4;
    u8 b6;
    u8 pad7;
    u8 f8[1];
} M;

extern int func_068983DC(int k);
extern int func_068983EC(int b);
extern u32 func_068983FC(int b);
extern u32 func_0689840C(int b);
extern int func_0689841C(int b, int c);
extern int func_0689842C(int b, int s);
extern int func_0689843C(int x);
extern int func_0689844C(int b, int k);
extern M *func_0689845C(int b, int n, int k);
extern u16 func_0689846C(int x, int n);
extern void func_0689847C(void *p, int n, int v);
extern void func_0689848C(void *p, int k);
extern void func_0689849C(int b, void *p);
extern void func_068984AC(int a);
unsigned int *func_0689831C(unsigned int *p);
void func_06898328(int a, int b, int c, D *d);
extern unsigned int d_0689D698;

/*
 * note: Unlabelled follower after the 0689830C veneer; ends before existing 06898328.
 */
unsigned int *func_0689831C(unsigned int *p)
{
    *p = 1;
    return &d_0689D698;
}


void func_06898328(int a, int b, int c, D *d)
{
    if (func_068983DC(2) == 0x1f && func_068983EC(b) == 0) {
        if (d->w0 == 0) {
            d->w1 = func_068983FC(b);
            d->w0 = 1;
        } else if (func_0689840C(b) > d->w1) {
            int s = func_0689841C(b, c);

            if (s != 0x1f) {
                if (func_0689843C(func_0689842C(b, s)) == 0) {
                    u8 k = d->w6;
                    int t = func_0689844C(b, k);
                    M *m = func_0689845C(b, 5, k);

                    m->b6 = s;
                    m->h4 = func_0689846C(t, 2);
                    func_0689847C(m->f8, 2, 0x2bc);
                    func_0689848C(m->f8, k);
                    func_0689849C(b, m);
                }
            }
            func_068984AC(a);
        }
    }
}
