/*
 * function: func_021C3810
 * address: 0x021C3810
 * packet: pkt_ov093_021C3810
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: func_021B8E28 receives the full position int; its own u8 signature adds an absent truncation.
 * symbols:
 *   func_021C39CC 0x021C39CC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C3A4C 0x021C3A4C thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021C39F4 0x021C39F4 thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021BDD7C 0x021BDD7C thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021BD9D4 0x021BD9D4 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Mode { M0, M1, M2, Mneg = -1 };
struct Pair { u8 count, id; };
struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };
extern int func_021C39CC(u8 *);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern int func_021D5B68(void *p);
struct B;
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D69AC(u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern int func_021C3A4C(u8 *, int, u8 *);
extern int func_021C88E4(u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021B8E28(u8 *, int, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern int func_021C39F4(u8 *, u8 *);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021BDD7C(u8 *, u8 *, u32);
extern int func_021C99A0(void *, const struct Msg *);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern void func_021CD64C(void *, u8, ...);
extern int func_021BDA00(u8 *);
extern u8 func_021B8DDC(u32 x);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D8244(struct B *p, int n);
static inline u8 rule(u8 n)
{
    if (n != 0) {
        n--;
        if (n < 24) return n;
    }
    return 31;
}
int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    int position;
    u32 lock;
    u8 blocked;
    struct Pair pair;
    *out = 0;
    if (force) mode = M1;
    else mode = func_021C39CC(p);
    if (mode == M2) return 0;
    position = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(b));
    if (position == 6) return 0;
    if (func_021D5B68(b)) return 0;
    if (func_021D62C4((struct Unk021D62A8 *)b, 33)) return 0;
    if (rule(func_021D69AC(b, 4)) != 31) return 0;
    lock = func_021CC8D8(p + 0x1d74, 8732);
    blocked = func_021C3A4C(p, (int)a, b);
    if (blocked && func_021C88E4(p)) *out = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 8740);
    if (blocked) return 0;
    func_021B8E28(*(u8 * *)&((struct Obj00003 *)p)->f4, position, &pair.id, &pair.count);
    if (mode == M1) {
        u8 id;
        mode = func_021C39F4(p, func_021BB85C(*(u8 * *)&((struct Obj00003 *)p)->f0, pair.id));
        if (mode >= 0) {
            id = func_021D5440((u8 *)func_021B990C((char *)(*(u32 *)&((struct Obj00003 *)p)->f8), pair.id, (u8)mode));
            func_021BDD7C(p, b, move);
            if (msg) func_021C99A0(p, msg);
            func_021BD9D4(p, pair.id, pair.count, (u8)mode, 0);
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 845, id, 0xffff0000);
            func_021BDA00(p);
        } else return 0;
    } else {
        int slot;
        slot = func_021B8DDC(func_021D5440(a));
        if (!ignore) {
            u8 speed;
            speed = (u8)func_021D59B4(a, 15);
            if ((u8)func_021D59B4(b, 15) > speed) return 0;
        }
        func_021D8244((struct B *)(p + 0x4b8), slot);
        func_021BDD7C(p, b, move);
        *(u32 *)&((struct Obj00003 *)p)->f14 = 5;
    }
    return 1;
}
