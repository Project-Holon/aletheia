/*
 * function: func_021CA7F4
 * address: 0x021CA7F4
 * packet: pkt_ov093_021CA7F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   func_021CB214 0x021CB214 thumb ov093
 *   func_021CA8C8 0x021CA8C8 thumb ov093
 *   func_021CAA58 0x021CAA58 thumb ov093
 *   func_021CACF4 0x021CACF4 thumb ov093
 *   func_021CA8F8 0x021CA8F8 thumb ov093
 *   func_021CA8D8 0x021CA8D8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021CA8E8 0x021CA8E8 thumb ov093
 *   func_021CAFD8 0x021CAFD8 thumb ov093
 */
#include "../include/Obj09976.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u32 a:1; u32 b:31; };
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 func_021CB214(u8 *p, u8 *a, u8 *b);
extern void func_021CA8C8(void *);
extern int func_021CAA58(u8 *p, u8 *a, u16 move, u8 *q, int id, void *out);
extern int func_021CACF4(u8 *p, u8 *a, u16 move, u8 *q, long id, void *out);
extern int func_021CA8F8(u8 *p, u8 *a, int unused, u8 *q, int id, void *out);
extern u8 *func_021CA8D8(void *, int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 func_021CA8E8(void *, u8);
extern int func_021CAFD8(u8 *, u32, u8 *, const u8 *, u16, void *);
int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out)
{
    u32 mode = BTL_MAIN_GetRule(((struct Obj09976 *)p)->f4);
    u32 id = 31;
    if (!((struct Flags *)(q + 16))->a) id = func_021CB214(p, a, (u8 *)q);
    func_021CA8C8(out);
    p[0x77f] = 6;
    switch (mode) {
    case 0: default:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    case 1:
        id = func_021CAA58(p, a, b, (u8 *)q, id, out);
        break;
    case 2:
        id = func_021CACF4(p, a, b, (u8 *)q, id, out);
        break;
    case 3:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    }
    if (id == 1) {
        u8 *m = func_021CA8D8(out, 0);
        if (m) p[0x77f] = func_021CA8E8(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(m));
        if (!func_021CAFD8(p, mode, a, q, b, out)) id = 0;
    }
    return id;
}
