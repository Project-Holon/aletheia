/*
 * function: func_0217BE64
 * address:  0x0217BE64
 * packet:   pkt_ov019_0217BE64
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217EC04  0x0217EC04  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02173AFC  0x02173AFC  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020392B8  0x020392B8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   memcmp         0x0203EFC8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned int   u32;

typedef struct Obj {
    u8   pad00[0x18];
    u8  *p18;
    u8   pad1C[0x24 - 0x1C];
    u8   addr[6];
    u8   b2A;
    u8   pad2B[0x6C - 0x2B];
    s16  s6C;
} Obj;

typedef unsigned short u16;
extern int func_0217BB04(char *p);
extern int func_0217B8E4(char *p, int v);
extern u16 func_0217EC04(void ***ctx);
extern u32 func_0217F1EC(u8 *p);
extern void func_0217F210(u8 *p, u8 *a, u32 b);
extern void func_02172D20(u8 *p);
extern int func_02172D68(u8 *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern int  func_02173AFC(int v);
extern void func_0203D14C(int a, int b, void *c);
extern int  func_0203D1B4(void);
extern u32 func_0203D1C0(u32 index);
extern void func_0203D1E8(u32 unused, void *arg);
extern void func_0203D7BC(u8 a0);
extern int  func_020392B8(void);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 id);
extern int  memcmp(const void *a, const void *b, u32 n);

int func_0217BE64(void *w, Obj *obj, u8 *a2, u8 *state)
{
    int i;

    if (func_0217BB04(w) == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        func_0203D14C(1, 1, 0);
        obj->s6C = 0;
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 0) {
            break;
        }
        if (func_0203D1B4() > 1) {
            for (i = 2; i < 5; i++) {
                if ((int)func_0203D1C0((u8)i) == 1) {
                    break;
                }
            }
            if (i < 5 || func_020392B8() > 2) {
                func_0217F210(w, a2, func_0217EC04(w));
                func_0217B8E4(w, 0);
                func_02172D20(w);
                *state = 4;
            } else {
                func_0203D7BC(1);
                func_0203D1E8((u32)func_020399A8(), 0);
                *state = 2;
            }
        } else {
            obj->s6C++;
            if (obj->s6C > 600 || (func_020362DC() & 2)) {
                func_02172D20(w);
                func_0217B8E4(w, 0);
                func_021734A8(w, 1, 0);
                if (obj->s6C > 600) {
                    func_0217F210(w, a2, func_0217EC04(w));
                } else {
                    func_0217F210(w, a2, 10);
                }
                *state = 5;
            }
        }
        break;
    case 2:
        if (obj->b2A == 1) {
            if (memcmp(obj->addr, obj->p18 + 0x64, 6) != 0) {
                if (func_02173AFC(2) == 1) {
                    func_0203D7BC(0);
                    *state = 6;
                }
            } else {
                if (func_02173AFC(1) == 1) {
                    func_020061E4(0x806);
                    func_0217B8E4(w, 7);
                    func_021734A8(w, 3, (u32)obj->p18);
                    func_021734A8(w, 1, 0);
                    *state = 3;
                }
            }
        }
        break;
    case 3:
        if (func_0217F1EC(w) == 1) {
            return 1;
        }
        break;
    case 4:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 0xF3)) {
            return 1;
        }
        break;
    case 5:
        if (func_02172D68(w) == 0) {
            *state = 4;
        }
        break;
    case 6:
        if (func_020392B8() <= 1) {
            func_02172D20(w);
            (*state)++;
        }
        break;
    case 7:
        if (func_02172D68(w) == 0) {
            obj->b2A = 0;
            *state = 0;
        }
        break;
    }
    return 0;
}
