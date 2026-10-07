/*
 * function: func_021D1CF4
 * address: 0x021D1CF4
 * packet: pkt_ov093_021D1CF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 * symbols:
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8CE8 0x021B8CE8 thumb ov093
 *   func_021D1DF4 0x021D1DF4 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021EA488 0x021EA488 thumb ov093
 *   func_021EA4C4 0x021EA4C4 thumb ov093
 *   func_021CDECC 0x021CDECC thumb ov093
 */
#include "../../../matched/include/Obj01691.h"
#include "../../../matched/include/Obj21146.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct S;
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021D5440(u8 *p);
extern int func_021B8CE8(int a, int b, int c);
extern int func_021D1DF4(void *);
struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
extern int func_021B9F70(u8 *p, int i);
struct H;
struct L;
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021EA488(struct S *s, u8 a, u8 b, u8 c);
extern int func_021EA4C4(struct S *s);
extern void func_021CDECC(u8 *p);
static inline void message(u8 *p, int code, u32 value, u32 id)
{
    func_021EAF18((struct L *)(p + 0x58), 1, code);
    func_021EAF50((struct L *)(p + 0x58), value);
    func_021EAF50((struct L *)(p + 0x58), id);
    func_021EA614(((struct Obj21146 *)p)->f54, (struct H *)(p + 0x58));
}
int func_021D1CF4(u8 *p, int *state, const u32 *params)
{
    u8 a = params[0];
    u8 b = params[1];
    u8 flag = params[3];
    u8 id;
    switch (*state) {
    case 0:
        if (flag != 0) {
            id = func_021D5440(func_021B9920(((struct Obj01691 *)p)->f4, a, b));
            if (func_021B8CE8((int)(((struct Obj01691 *)p)->f0), p[0x1A6], a) == 0) {
                if (p[0x1A6] == a) {
                    func_021EAF18((struct L *)(p + 0x58), 1, func_021D1DF4(p));
                    func_021EAF50((struct L *)(p + 0x58), id);
                    func_021EA614(((struct Obj01691 *)p)->f54, (struct H *)(p + 0x58));
                } else {
                    message(p, 0x11, a, id);
                }
            } else if (func_021B9F70(((struct Obj01691 *)p)->f0, a) != 0) {
                message(p, 0xE, a, id);
            } else {
                message(p, 0x11, a, id);
            }
        }
        (*state)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj01691 *)p)->f54) != 0) {
            func_021EA488(((struct Obj01691 *)p)->f54, func_021B8BEC(*(u8 * *)&((struct Obj01691 *)p)->f0, a, b), a, b);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA4C4(((struct Obj01691 *)p)->f54) != 0) {
            func_021CDECC(p);
            return 1;
        }
        break;
    }
    return 0;
}
