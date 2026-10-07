/*
 * function: func_021BF4AC
 * address: 0x021BF4AC
 * packet: pkt_ov093_021BF4AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Four separate veneer iterator loops; retain the explicit fourth C6668 argument.
 * symbols:
 *   func_021BF5E8 0x021BF5E8 thumb ov093
 *   func_021BF5F8 0x021BF5F8 thumb ov093
 *   func_021BF608 0x021BF608 thumb ov093
 *   func_021BF618 0x021BF618 thumb ov093
 *   func_021BF628 0x021BF628 thumb ov093
 *   func_021BF638 0x021BF638 thumb ov093
 *   func_021BF648 0x021BF648 thumb ov093
 *   func_021BF658 0x021BF658 thumb ov093
 *   func_021BF668 0x021BF668 thumb ov093
 *   func_021BF678 0x021BF678 thumb ov093
 *   func_021BF688 0x021BF688 thumb ov093
 *   func_021BF698 0x021BF698 thumb ov093
 *   func_021BF6A8 0x021BF6A8 thumb ov093
 *   func_021BF6B8 0x021BF6B8 thumb ov093
 *   func_021BF6C8 0x021BF6C8 thumb ov093
 *   func_021BF6D8 0x021BF6D8 thumb ov093
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021BF6E8 0x021BF6E8 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021C6668 0x021C6668 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 */
#include "../../../matched/include/Obj04358.h"
#include "../../../matched/include/Obj13316.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BF5E8(void *);
extern u8 *func_021BF5F8(void *);
extern void func_021BF608(void *, u8 *);
extern u8 *func_021BF618(void *);
extern void func_021BF628(void *);
extern u8 *func_021BF638(void *);
extern void func_021BF648(void *, u8 *);
extern u8 *func_021BF658(void *);
extern void func_021BF668(void *);
extern u8 *func_021BF678(void *);
extern void func_021BF688(void *, u8 *);
extern u8 *func_021BF698(void *);
extern void func_021BF6A8(void *);
extern u8 *func_021BF6B8(void *);
extern void func_021BF6C8(void *, u8 *);
extern u8 *func_021BF6D8(void *);
extern int func_021BF324(u8 *, u8 *, u8 *);
extern int func_021BF6E8(u8 *, u8 *, u8 *, u8 *, void *, int);
extern u32 func_0201BEB8(u16, u32);
struct UtilWork;
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021C6668(u8 *, u8 *, u8 *, u16);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
void func_021BF4AC(u8 *p, u8 *b, u8 *a, void *d, void *e)
{
    u8 *q;
    func_021BF5E8(d);
    q = func_021BF5F8(d);
    while (q) {
        if (func_021BF324(p, a, q) == 0 && func_021BF6E8(p, b, a, q, e, 43))
            func_021BF608(d, q);
        q = func_021BF618(d);
    }
    func_021BF628(d);
    q = func_021BF638(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 44)) func_021BF648(d, q);
        q = func_021BF658(d);
    }
    if (func_0201BEB8(((struct Obj04358 *)b)->f0, 3)) {
        func_021BF668(d);
        q = func_021BF678(d);
        while (q) {
            if (func_021D5BB0((struct UtilWork *)q, 7) && func_021C6668(p, a, q, ((struct Obj04358 *)b)->f0) == 0) {
                func_021BF688(d, q);
                func_021CD64C(((struct Obj13316 *)p)->fC, 91, 523, func_021D5440(q), 0xffff0000);
            }
            q = func_021BF698(d);
        }
    }
    func_021BF6A8(d);
    q = func_021BF6B8(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 45)) func_021BF6C8(d, q);
        q = func_021BF6D8(d);
    }
}
