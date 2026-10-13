/*
 * function: func_021E1784
 * address: 0x021E1784
 * packet: pkt_ov137_021E1784
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_0202F190 0x0202F190 thumb
 *   func_02019CE0 0x02019CE0 thumb
 */
#include "../include/Obj14255.h"
typedef unsigned char u8;
extern int func_021DCE00(char *p, int i);
extern void *POKEPARTY_GetMember(void *, unsigned);
typedef unsigned short u16;
struct RecDC;
extern void *func_021DEB10(char *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
typedef unsigned int   u32;
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
void func_021E1784(char *p, int i)
{
    void *party;
    void *other;
    int slot;
    void *a;
    void *b;
    void *q;
    party = ((struct Obj14255 *)p)->f24;
    other = (void *)func_021DCE00(*(char * *)&((struct Obj14255 *)p)->fDC, i);
    slot = *(int *)(p + 0x44 + i * 4);
    a = POKEPARTY_GetMember(party, (*(int **)(p + 0xd8))[1]);
    b = POKEPARTY_GetMember(other, slot);
    q = func_021DEB10(p);
    func_0202F190(b, (int)6, (u32)UNION_APP_GetMemberEntry(q, (u8)GFL_NET_SYSTEM_GetCurrentAid()), (int)30002, (int)114);
    func_02019CE0(b, a);
}
