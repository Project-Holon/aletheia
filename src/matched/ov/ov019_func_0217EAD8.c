/*
 * function: func_0217EAD8
 * address:  0x0217EAD8
 * packet:   pkt_ov019_0217EAD8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217F098  0x0217F098  thumb  ov019
 *   func_0217F188  0x0217F188  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0216F7F4  0x0216F7F4  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys;

void func_0217BAF0(u8 *w, int a, int v);
void func_0217F098(u8 *w, int a);
void func_0217F188(u8 *w, int msg);
int func_0217F1EC(u8 *w);
void func_0217F074(u8 *w);
int func_0217B8E4(u8 *w, int v);
void func_0217422C(u8 *w, int b, void *c);
int func_02174268(u8 *w);
void *func_0216F7F4(int a, u8 *e, int b);
int func_0200855C(u8 *a);
void func_0201F02C(int a, int b, u8 *c);
int func_020362DC(void);

int func_0217EAD8(u8 *w, void *obj, int a2, u8 *state)
{
    u8 *p;
    int t;
    int v;
    int msg;
    void *q;

    p = *(u8 **)(w + 0x355C);
    switch (*state) {
    case 0:
        func_0217BAF0(w, a2, 1);
        t = func_0200855C(p + 0x18 + p[0x16c] * 0x2c);
        if (t == 0x14 || t == 0x15) {
            v = (*(u8 **)(p + 0x134 + p[0x16c] * 4))[3];
            if (v < 5) {
                msg = 0x156 + v;
            } else if (v == 5) {
                switch (t) {
                case 0x15:
                    msg = 0x15c;
                    break;
                case 0x14:
                    msg = 0x15b;
                    break;
                default:
                    msg = 0x15d;
                    break;
                }
            } else {
                msg = 0x15d;
            }
        } else {
            msg = 0x15d;
        }
        func_0217F098(w, a2);
        func_0201F02C(*(int *)(w + 0x2804), 0, p + 0x18 + p[0x16c] * 0x2c);
        func_0217F188(w, msg);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 3)) {
            func_0217F074(w);
            (*(u8 **)(p + 0x134 + p[0x16c] * 4))[4] |= 0x20;
            q = func_0216F7F4((*(Sys **)w)->f8, *(u8 **)(p + 0x134 + p[0x16c] * 4), 0x41);
            *(void **)(w + 0x3558) = q;
            func_0217422C(w, 0x1c, q);
            (*state)++;
        }
        break;
    case 2:
        if (func_02174268(w) == 0) {
            *(void **)(w + 0x3558) = 0;
            (*state)++;
        }
        break;
    case 3:
        func_0217B8E4(w, 0x2a);
        return 1;
    }
    return 0;
}
