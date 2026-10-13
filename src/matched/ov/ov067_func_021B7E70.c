/*
 * function: FRAME_LIST_ReadKeys
 * address:  0x021B7E70
 * packet:   pkt_ov067_021B7E70
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x40/0x80 arms re-read f5c after the f60 store (`p->f5c--`/`++`);
 * the 0x80 arm loads f5e before f5c and still compares f5c on the left,
 * which only the named bound `n = p->f5e - 1` gives.
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FRAME_LIST_UpdateHoldStage  0x021B83A0  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct S {
    u8 pad00[0x5c];
    s16 f5c;
    u16 f5e;
    s16 f60;
    s16 f62;
    u16 f64;
    u8 pad66[0x94 - 0x66];
    u8 f94;
    u8 f95;
    u8 f96;
} S;

extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern unsigned int KEY_GetCont(void);
extern void FRAME_LIST_UpdateHoldStage(S *p);

int FRAME_LIST_ReadKeys(S *p)
{
    int n;

    if ((KEY_GetTrg() & 0x3f1) && func_020355C4() == 1) {
        func_020355D8(0);
        p->f60 = 0xff;
        p->f96 = 8;
        return 0;
    }
    if (KEY_GetCont() == 0) {
        p->f94 = 0;
        p->f95 = 6;
    }
    if (KEY_GetCont() & 0x40) {
        func_020355D8(0);
        if (p->f5c != 0) {
            p->f60 = p->f5c;
            p->f5c--;
            p->f96 = 8;
            return 1;
        }
        if (p->f62 != 0) {
            p->f96 = 0;
            FRAME_LIST_UpdateHoldStage(p);
            return 2;
        }
        return 14;
    }
    if (KEY_GetCont() & 0x80) {
        func_020355D8(0);
        n = p->f5e - 1;
        if (p->f5c < n) {
            p->f60 = p->f5c;
            p->f5c++;
            p->f96 = 8;
            return 1;
        }
        if (p->f62 < p->f64) {
            p->f96 = 0;
            FRAME_LIST_UpdateHoldStage(p);
            return 3;
        }
        return 14;
    }
    if (KEY_GetCont() & 0x20) {
        func_020355D8(0);
        if (p->f62 != 0) {
            p->f96 = 4;
            return 4;
        }
        if (p->f5c != 0) {
            p->f60 = p->f5c;
            p->f5c = 0;
            p->f96 = 4;
            return 6;
        }
        return 14;
    }
    if (KEY_GetCont() & 0x10) {
        func_020355D8(0);
        if (p->f62 < p->f64) {
            p->f96 = 4;
            return 5;
        }
        if (p->f5c < p->f5e - 1) {
            p->f60 = p->f5c;
            p->f5c = p->f5e - 1;
            p->f96 = 4;
            return 7;
        }
        return 14;
    }
    if (KEY_GetTrg() & 1)
        return 12;
    if (KEY_GetTrg() & 0x200) {
        func_020355D8(0);
        if (p->f5c != 0 || p->f62 != 0)
            return 8;
        return 14;
    }
    if (KEY_GetTrg() & 0x100) {
        func_020355D8(0);
        if (p->f5c != p->f5e - 1 || p->f62 != p->f64)
            return 9;
        return 14;
    }
    return 14;
}
