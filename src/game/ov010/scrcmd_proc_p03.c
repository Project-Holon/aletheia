/*
 * file:     scrcmd_proc_p03.c
 * unit:     yes
 * function: func_0215C0D0, func_0215C138
 * address:  0x0215C0D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215B4DC  0x0215B4DC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   d_02171180     0x02171180  data   ov010  a2
 *   d_0217118E     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 *   d_02171182 0x02171182 data a1
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185C4(void *);
extern u16 *func_02159AE8(void *c, void *vm);
extern int func_0215B4DC(void *a0, void *a1, void *a2);
int func_0215C0D0(void *a0, void *a1);
int func_0215C138(void *c, void *vm);
extern struct { u16 a; u16 b; } d_0217118E[6];
extern const u8 d_02171182[];


int func_0215C0D0(void *a0, void *a1)
{
    int k = func_02159B10(a0, a1);
    u32 x = func_02159B10(a0, a1);
    u32 y = func_02159B10(a0, a1);
    void *v;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (x == d_0217118E[i].a) {
            if (y <= d_0217118E[i].b && func_0215B4AC(a1, k, &v) == 1) {
                func_02017E40(v, x, y);
                func_020185C4(v);
            }
            return 0;
        }
    }
    return 0;
}

/*
 * lever: selector remains live in r2 and is func_0215B4DC's third argument.
 */
int func_0215C138(void *c, void *vm)
{
    u16 *dst;
    u32 arg;
    u32 sel;
    u32 i;
    dst = func_02159AE8(c, vm);
    arg = func_02159B10(c, vm);
    sel = func_02159B10(c, vm);
    for (i = 0; i < 12; i++) {
        if (sel == d_02171182[i]) {
            *dst = func_0215B4DC(vm, (void *)arg, (void *)sel);
            return 0;
        }
    }
    *dst = 0;
    return 0;
}
