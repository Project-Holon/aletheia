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
 *   func_021C7CF4  0x021C7CF4  thumb
 *   func_021C8020  0x021C8020  thumb
 *   func_021C8138  0x021C8138  thumb
 *   func_021C83D4  0x021C83D4  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D5B48  0x021D5B48  thumb
 *   func_021D7040  0x021D7040  thumb
 *   func_021D775C  0x021D775C  thumb
 *   func_021D7B74  0x021D7B74  thumb
 *   d_0689D698 0x0689D698 data ov095 a4
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

extern int func_021D775C(int k);
extern int func_021C83D4(int b);
extern u32 func_021C8138(int b);
extern int func_021C8020(int b, int c);
extern int func_021C7CF4();
extern int func_021D5B48(int x);
extern M *func_021C88A4(int b, int n, int k);
extern u16 func_021D7B74(int x, int n);
extern void func_021C8838(void *p, int n, int v);
extern void func_021C8860(void *p, int k);
extern void func_021C88C8(int b, void *p);
extern void func_021D7040(int a);
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
    if (func_021D775C(2) == 0x1f && func_021C83D4(b) == 0) {
        if (d->w0 == 0) {
            d->w1 = func_021C8138(b);
            d->w0 = 1;
        } else if (func_021C8138(b) > d->w1) {
            int s = func_021C8020(b, c);

            if (s != 0x1f) {
                if (func_021D5B48(func_021C7CF4(b, s)) == 0) {
                    u8 k = d->w6;
                    int t = func_021C7CF4(b, k);
                    M *m = func_021C88A4(b, 5, k);

                    m->b6 = s;
                    m->h4 = func_021D7B74(t, 2);
                    func_021C8838(m->f8, 2, 0x2bc);
                    func_021C8860(m->f8, k);
                    func_021C88C8(b, m);
                }
            }
            func_021D7040(a);
        }
    }
}
