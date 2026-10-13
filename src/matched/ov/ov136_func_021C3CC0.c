/*
 * function: func_021C3CC0
 * address: 0x021C3CC0
 * packet: pkt_ov136_021C3CC0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   func_02030734 0x02030734 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_02008EAC 0x02008EAC thumb
 *   func_02008F48 0x02008F48 thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 */
#include "../include/Obj01163.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C7EE0[];
struct Sub02008F80Obj;
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
typedef unsigned int   u32;
struct Big;
struct Sub02008EACObj;
struct Sub02008EACObjLayout;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(unsigned, void *, unsigned);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MAIL_Create(int a0);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void func_02008F48(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused, void *p);
void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap)
{
    u8 *p;
    unsigned v;
    v = (unsigned int)func_02008FEC(a);
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x43);
    MIi_CpuClearFast(0, p, 0x1C);
    p[0xF] = d;
    p[0xE] = c;
    ((struct Obj01163 *)p)->f18 = v;
    ((struct Obj01163 *)p)->f0 = 1;
    ((struct Obj01163 *)p)->f8 = b;
    ((struct Obj01163 *)p)->fC = 0;
    ((struct Obj01163 *)p)->f10 = GAME_DATA_GetSaveControl(a);
    ((struct Obj01163 *)p)->f14 = MAIL_Create((unsigned)((u16)heap));
    func_02008EAC(((struct Obj01163 *)p)->f14);
    func_02008F48(((struct Obj01163 *)p)->f14, 0xFF, c, a);
    return p;
}
