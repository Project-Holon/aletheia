/*
 * function: func_021C4D1C
 * address: 0x021C4D1C
 * packet: pkt_ov093_021C4D1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF8B8 0x021EF8B8 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C3BE0 0x021C3BE0 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021C4E08 0x021C4E08 thumb ov093
 *   func_021C4E18 0x021C4E18 thumb ov093
 *   func_021C4E28 0x021C4E28 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021D7BD4 0x021D7BD4 thumb ov093
 *   func_021C4E38 0x021C4E38 thumb ov093
 *   func_021C4EA4 0x021C4EA4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021C70E4 0x021C70E4 thumb ov093
 *   func_021C5200 0x021C5200 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021EF8B8(void);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C3BE0(u8 *p, u32 a);
extern int func_021C2AB0(u8 *);
extern void func_021C4E08(void *);
extern u8 *func_021C4E18(void *);
extern u8 *func_021C4E28(void *);
extern int func_021D5B68(void *);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern u32 func_021CC8D8(void *, int);
extern int func_021D7BD4(void *, int);
extern int func_021C4E38(u8 *, u8 *, u32, u32);
extern void func_021C4EA4(u8 *, u8 *, int, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021C4F64(u8 *, u8 *);
extern void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);
extern int func_021C5200(u8 *);
int func_021C4D1C(u8 *p, void *it)
{
    int r;
    int changed;
    int mode;
    u8 *a;
    u32 lock;
    int line;
    r = func_021EF8B8();
    if (r) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x40, r);
        func_021C3BE0(p, 0);
        return 0;
    }
    changed = 0;
    mode = func_021C2AB0(p);
    func_021C4E08(it);
    a = func_021C4E18(it);
    if (a) {
        line = 0x26c6;
        line += 12;
        do {
            if (!func_021D5B68(a) && !func_021D5BDC((struct UtilWork *)a, 5) && !func_021D5BDC((struct UtilWork *)a, 4)) {
                lock = func_021CC8D8(p + 0x1d74, 0x26c6);
                r = func_021C4E38(p, a, mode, func_021D7BD4(a, mode));
                if (r) {
                    func_021C4EA4(p, a, mode, r);
                    changed = 1;
                }
                func_021CC95C((u32 *)(p + 0x1d74), lock, line);
                func_021C4F64(p, a);
            }
            a = func_021C4E28(it);
        } while (a);
    }
    if (changed) func_021C70E4(p, 0x255, 6, 6, 0, 0);
    return func_021C5200(p);
}
