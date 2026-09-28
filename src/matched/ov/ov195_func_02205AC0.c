/*
 * function: func_02205AC0
 * address:  0x02205AC0
 * packet:   pkt_02205AC0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208CA0 0x02208CA0 data a4
 *   d_02208D1C 0x02208D1C data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *
 * Twin of func_02205A34: the `(int)i` cast on the id read keeps the element
 * address from being hoisted above the guard.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 id;
    u8 data[0x20];
    u32 len;
    u32 mode;
} Entry;

extern u8 d_02208CA0[];
extern Entry d_02208D1C[];
extern void func_02082BCC(void *, int, int);
extern void func_0203F8F4(void *);
extern void func_02045088(void *);
extern void func_0203FC28(void *);
extern void func_0203FCA0(u8, void *, u8);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);

void func_02205AC0(void *a, void *b)
{
    u32 i;

    func_02082BCC(a, 0, 4);
    func_0203F8F4(b);
    func_02045088(b);
    func_0203FC28(d_02208CA0);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v <= 3) {
            Entry *e = &d_02208D1C[i];
            func_0203FCA0(v, e->data, e->len);
            func_020414AC(v);
            func_02040588(v, e->mode);
        }
    }
}
