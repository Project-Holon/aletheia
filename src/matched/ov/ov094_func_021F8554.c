/*
 * function: func_021F8554
 * address:  0x021F8554
 * packet:   pkt_ov094_021F8554
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F8628  0x021F8628  thumb  ov094
 *   func_021F6EDC  0x021F6EDC  thumb  ov094
 *   func_021F6F48  0x021F6F48  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 */
typedef unsigned int u32;
typedef struct { int x, y, z; } VecFx32;

typedef struct {
    char pad[0x19C];
    void *cam;          /* 0x19C */
    char pad2[0x1C];
    int mode;           /* 0x1BC */
} Work;

extern Work *d_0220AF20;

extern void func_021F8628(u32 a, VecFx32 *out, VecFx32 *p);
extern void func_021F6EDC(void *cam, VecFx32 *a, VecFx32 *b);
extern void func_021F6F48(void *cam, VecFx32 *a, VecFx32 *b, int n, int s, int t);
extern void func_021F7998(u32 a);

void func_021F8554(u32 flags, int kind, int n, int s, int t)
{
    VecFx32 a;
    VecFx32 b;

    if (flags & 1) {
        func_021F8628(flags, &a, &b);
        switch (kind) {
        case 0:
            func_021F6EDC(d_0220AF20->cam, &a, &b);
            break;
        case 1:
            func_021F6F48(d_0220AF20->cam, &a, &b, n, s, t);
            break;
        }
        return;
    }
    switch (d_0220AF20->mode) {
    case 0:
        func_021F7998(0x23F);
        break;
    case 1:
        if (flags == 2) {
            func_021F7998(0x240);
        } else {
            func_021F7998(0x241);
        }
        break;
    case 2:
        if (flags == 2) {
            func_021F7998(0x242);
        } else if (flags == 4) {
            func_021F7998(0x23F);
        } else {
            func_021F7998(0x243);
        }
        break;
    case 3:
        func_021F7998(0x245);
        break;
    }
}
