/*
 * file:     btlv_effvm_p11.c
 * unit:     yes
 * function: func_021F7F58, func_021F8010, func_021F803C, func_021F8090
 * address:  0x021F7F58
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   d_02209D0C     0x02209D0C  data   ov094  a1
 *   func_021F88F4  0x021F88F4  thumb  ov094
 *   func_021FF088  0x021FF088  thumb  ov094
 *   func_021FF144  0x021FF144  thumb  ov094
 *   func_021FF0F8 0x021FF0F8 thumb ov094
 *   func_022070C0  0x022070C0  thumb  ov094
 *   func_02207288 0x02207288 thumb ov094
 */
struct W;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021F88F4(void);
extern void func_021FF088(u32 obj, int a, u32 b);
extern void func_021FF144(u32 obj, u32 b, u32 c, u32 d, u32 e);
extern void func_021FF0F8(void *, int);
extern void func_022070C0(struct W *p, void *a, void *q, int mode, int i);
extern void func_02207288(struct W *p, void *a, void *q, int mode, int i);
void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);
void func_021F8010(int a);
void func_021F803C(u32 a, void *m, u32 c);
void func_021F8090(u32 a, u32 b, u32 c);
extern char *d_0220AF20;
extern u8 d_02209D0C[];


void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e)
{
    if (!(b & 1)) {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 4;
            break;
        case 0x3D:
            a = 2;
            break;
        case 0x25:
            a = 3;
            break;
        default:
            if (d_02209D0C[a] == 0)
                a = 0;
            else
                a = 1;
            break;
        }
    } else {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 0x67;
            break;
        }
    }
    func_021FF088(*(u32 *)(d_0220AF20 + 0x190), a, b);
    if (c != 0 || d != 0 || e != 0)
        func_021FF144(*(u32 *)(d_0220AF20 + 0x190), b, c, d, e);
    *(u32 *)(d_0220AF20 + (b - 8) * 4 + 0x1F8) = b;
}


void func_021F8010(int a)
{
    func_021FF0F8(*(void **)(d_0220AF20 + 0x190), a);
    ((int *)(d_0220AF20 + 0x1f8))[a - 8] = -1;
}


void func_021F803C(u32 a, void *m, u32 c)
{
    switch (*(u32 *)(d_0220AF20 + 0x1BC)) {
    case 2:
        func_022070C0((struct W *)(*(u32 *)(d_0220AF20 + 0x1A4)), (void *)a, m, 2, c);
        break;
    case 3:
        func_022070C0((struct W *)(*(u32 *)(d_0220AF20 + 0x1A4)), (void *)a, m, 3, c);
        break;
    default:
        func_022070C0((struct W *)(*(u32 *)(d_0220AF20 + 0x1A4)), (void *)a, m, 0, c);
        break;
    }
}


/*
 * extent: Already matched followers begin at 0x021F80E4.
 */
void func_021F8090(u32 a, u32 b, u32 c)
{
    switch (*(u32 *)(d_0220AF20 + 0x1BC)) {
    case 2:
        func_02207288((struct W *)(*(u32 *)(d_0220AF20 + 0x1A4)), (void *)a, (void *)b, 2, c);
        break;
    case 3:
        func_02207288((struct W *)(*(u32 *)(d_0220AF20 + 0x1A4)), (void *)a, (void *)b, 3, c);
        break;
    default:
        func_02207288((struct W *)(*(u32 *)(d_0220AF20 + 0x1A4)), (void *)a, (void *)b, 0, c);
        break;
    }
}
