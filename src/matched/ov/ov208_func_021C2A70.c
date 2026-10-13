/*
 * function: func_021C2A70
 * address:  0x021C2A70
 * packet:   pkt_ov208_021C2A70
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
 *   func_021C34A4  0x021C34A4  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct S {
    u8 pad0[0xcc];
    u32 fcc;
    u32 fd0;
};

extern int func_021BC3B4(int *p);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
struct Ov208Cur;
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_021C34A4(u16 *heap, u8 *p, int key);
extern void func_021BDBA0(int p);
extern int func_021BC3A4(int *p);
extern int func_021BDC2C(char *p);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);

void func_021C2A70(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 17:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 18:
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9:
        flag = 1;
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->fcc = 2;
        return;
    case 6: case 7: case 9:
        st->fcc = 1;
        return;
    case 3:
        func_021BDBA0(sc);
        return;
    case 4:
        func_021BDBA0(sc);
        return;
    case 5:
        GAME_DATA_SetSaveFlag((void *)func_021BC3A4(obj), 0x13, func_021BDC2C((char *)sc));
        func_021BDBA0(sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}
