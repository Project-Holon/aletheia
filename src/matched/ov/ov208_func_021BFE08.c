/*
 * function: func_021BFE08
 * address:  0x021BFE08
 * packet:   pkt_ov208_021BFE08
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_021C1AD4  0x021C1AD4  thumb  ov208
 *   func_021C1D0C  0x021C1D0C  thumb  ov208
 *   func_021C1920  0x021C1920  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct S {
    u8 pad0[0x424];
    u32 f424;
    u32 f428;
    u32 f42c;
    u32 f430;
    u32 f434;
};

extern int func_021BC3B4(int *p);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(void *p);
extern void func_021C1AD4(u16 *heap, u8 *p, int key);
extern void func_021C1D0C(int a, int b, int c);
extern void func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern void func_021BDBA0(int p);
extern int func_021BC3A4(int *p);
extern int func_021BDC2C(char *p);
extern void func_02012BE0(void *p, u32 a, u32 b);

void func_021BFE08(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 16: case 19:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 17: case 18: case 20:
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9: case 19:
        flag = 1;
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C1AD4(heap, (u8 *)st, (int)obj);
            func_021C1D0C((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C(obj);
        if (old != func_021BC3C0(obj)) {
            func_021C1AD4(heap, (u8 *)st, (int)obj);
            func_021C1D0C((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f424 = 2;
        return;
    case 6: case 8: case 9:
        st->f424 = 1;
        return;
    case 3:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0(sc);
                return;
            }
        }
        break;
    case 4:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0(sc);
                return;
            }
        }
        break;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x12, func_021BDC2C((char *)sc));
        func_021BDBA0(sc);
        return;
    case 19:
        func_021C1920(heap, (u8 *)st, (int)obj, 6);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}
