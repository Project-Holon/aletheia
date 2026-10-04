/*
 * function: func_021CF5B0
 * address: 0x021CF5B0
 * packet: pkt_ov093_021CF5B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CF89C 0x021CF89C thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D62D8 0x021D62D8 thumb ov093
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC1C 0x021EFC1C thumb ov093
 */
#include "../include/Obj01894.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v; } Word;
struct L;
struct QI;
struct Unk021D62A8;
struct UtilSlots;
extern int func_021CF89C(u8 *p, void *q);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *, int);
extern u16 func_021E8B80(Word);
extern int func_021D5750(void *, u32);
extern void func_021EAF18(struct L *p, int kind, u16 id);
extern void func_021EAF50(struct L *p, u32 val);
extern u16 func_021D5B40(struct QI *p);
extern u8 func_021D5440(u8 *p);
extern u32 func_0201C314(void *p);
extern u16 func_021D67B8(u8 *p);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern int func_0201BEB8(u32, int);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021EFC1C(int, int, void *, u32);
int func_021CF5B0(u8 *g, void *m, u32 move, void *out)
{
    u32 k;
    u32 k2;
    Word w;
    if (move == 0xa5) return 0;
    if (func_021CF89C(g, m) && func_021D62C4(m, 0x1b)) {
        w = func_021D6314(m, 0x1b);
        k = func_021E8B80(w);
        if (func_021D5750(m, k) && k != move) {
            if (out) {
                func_021EAF18(out, 1, 0x63);
                func_021EAF50(out, func_021D5B40(m));
                func_021EAF50(out, k);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0x17)) {
        k2 = func_021E8B80(func_021D6314(m, 0x17));
        if (move != k2) {
            if (out) {
                func_021EAF18(out, 1, 0x64);
                func_021EAF50(out, func_021D5440(m));
                func_021EAF50(out, k2);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0xb) && func_0201C314((void *)move) == 0) {
        if (out) {
            func_021EAF18(out, 2, 0x23b);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xc) && move == func_021D67B8(m)) {
        if (out) {
            func_021EAF18(out, 2, 0x244);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xd) && move == func_021D62D8(m, 0xd) && move != 0xa5) {
        if (out) {
            func_021EAF18(out, 2, 0x253);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xf) && func_0201BEB8(move, 0xc)) {
        if (out) {
            func_021EAF18(out, 2, 0x37a);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 3) && func_021EFC1C(*(int *)&((struct Obj01894 *)g)->f34, *(int *)&((struct Obj01894 *)g)->f4, m, move)) {
        if (out) {
            func_021EAF18(out, 2, 0x24d);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) && func_0201BEB8(move, 9)) {
        if (out) {
            func_021EAF18(out, 2, 0x43e);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    return 0;
}
