/*
 * function: func_021BCB70
 * address: 0x021BCB70
 * packet: pkt_ov217_021BCB70
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041B6C 0x02041B6C arm
 * Original narrows the heap before 020490F4; its extern takes u16.
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arc;
extern void *func_020490F4(unsigned int id, u16 heap);
struct ArcFile;
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_02041B6C(u32 bit);
extern void func_020307B0(void *);
extern void func_02049238(void *);
void func_021BCB70(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (((struct Obj00025 *)p)->f8 & 0x7FFF) | 0x8000);
    buf = func_02049250(arc, 3, ((struct Obj00025 *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(0, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(0);
    func_020307B0(buf);
    func_02049238(arc);
}
