/*
 * function: func_021CCC0C
 * address:  0x021CCC0C
 * packet:   pkt_021CCC0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CCC0C   0x021CCC0C  thumb
 *   func_021CCAA8   0x021CCAA8  thumb ov093
 *   func_021CCAE0   0x021CCAE0  thumb ov093
 *   func_021CCB34   0x021CCB34  thumb ov093
 *   func_021CCB98   0x021CCB98  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_021CCAA8(void *w, u8 v);
extern void func_021CCAE0(void *w, u16 v);
extern void func_021CCB34(void *w, u32 v);
extern void func_021CCB98(void *w, s32 v);

void func_021CCC0C(void *w, u32 id, int cmd, s32 *a)
{
    int i;

    func_021CCAE0(w, id);
    switch (cmd) {
    case 1:
        func_021CCAA8(w, a[0]);
        break;
    case 17:
        func_021CCAE0(w, a[0]);
        break;
    case 2:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        break;
    case 18:
        func_021CCAA8(w, a[0]);
        func_021CCAE0(w, a[1]);
        break;
    case 34:
        func_021CCAA8(w, a[0]);
        func_021CCB98(w, a[1]);
        break;
    case 50:
        func_021CCAA8(w, ((a[0] & 0xF) << 4) | (a[1] & 0xF));
        break;
    case 66:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        break;
    case 3:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        break;
    case 19:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAE0(w, a[2]);
        break;
    case 35:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        break;
    case 51:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        break;
    case 67:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        break;
    case 83:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCB98(w, a[2]);
        break;
    case 20:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, ((a[2] & 0x1F) << 3) | (a[3] & 7));
        break;
    case 4:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 36:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAA8(w, a[3]);
        break;
    case 52:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAE0(w, a[3]);
        break;
    case 68:
        func_021CCAE0(w, (a[2] & 0x3F) | (((a[1] & 0x1F) << 6) | ((a[0] & 0x1F) << 11)));
        func_021CCAE0(w, a[3]);
        break;
    case 84:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 5:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        func_021CCAE0(w, a[3]);
        func_021CCAE0(w, a[4]);
        break;
    case 21: {
        u8 hi = ((a[0] & 0x1F) << 3) | (a[1] & 7);
        u8 lo = ((a[2] & 0x7F) << 1) | (a[3] & 1);
        func_021CCAE0(w, hi);
        func_021CCAE0(w, lo);
        func_021CCAE0(w, a[4]);
        break;
    }
    case 37:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 7) << 2) | ((a[2] & 1) << 1) | (a[3] & 1));
        func_021CCAE0(w, a[4]);
        break;
    case 6: {
        u16 v0 = (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10));
        u16 v1 = (a[5] & 0x1F) | (((a[4] & 0x1F) << 5) | ((a[3] & 0x1F) << 10));
        func_021CCAE0(w, v0);
        func_021CCAE0(w, v1);
        break;
    }
    case 22:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 3) << 3) | ((a[2] & 1) << 2) | ((a[3] & 1) << 1) | (a[4] & 1));
        func_021CCAE0(w, a[5]);
        break;
    case 38:
        func_021CCB34(w, ((a[0] & 0x1F) << 15) | ((a[1] & 0x1F) << 10) | ((a[2] & 0x1F) << 5) | (a[3] & 0x1F));
        func_021CCAE0(w, a[4]);
        func_021CCAE0(w, a[5]);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            func_021CCAA8(w, a[i]);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            func_021CCAA8(w, a[i]);
        break;
    }
}
