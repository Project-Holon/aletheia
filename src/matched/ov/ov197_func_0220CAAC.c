/*
 * function: func_0220CAAC
 * address: 0x0220CAAC
 * packet: pkt_ov197_0220CAAC
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: word-address arithmetic reuses MMIO pool base for +0x1c; typed pointer addition pools a second word.
 * symbols:
 *   d_04001050 0x04001050 data a2
 *   func_0207D534 0x0207D534 arm
 *   TCBL_Create 0x0203101C arm
 *   func_0220AF40 0x0220AF40 thumb ov196
 *   func_0220D5C0 0x0220D5C0 thumb ov197
 *   func_0220D6DC 0x0220D6DC thumb ov197
 *   func_0220D798 0x0220D798 thumb ov197
 *   func_0220BB1C 0x0220BB1C thumb ov197
 *   func_0220D7F0 0x0220D7F0 thumb ov197
 *   func_0220B120 0x0220B120 thumb ov197
 *   func_0220B1B0 0x0220B1B0 thumb ov197
 *   func_0220B990 0x0220B990 thumb ov197
 *   func_0220BBE4 0x0220BBE4 thumb ov197
 *   func_0220BD24 0x0220BD24 thumb ov197
 *   func_0220C034 0x0220C034 thumb ov197
 *   func_0220C4EC 0x0220C4EC thumb ov197
 *   func_0220AFDC 0x0220AFDC thumb
 *   func_0220D8C4 0x0220D8C4 thumb ov197
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj01076.h"
#include "../include/Obj25059.h"
#include "../include/Obj25060.h"
#include "../include/Obj25061.h"
#include "../include/Obj25062.h"
#include "../include/Obj25064.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 d_04001050[];
typedef unsigned int   u32;
struct PalAnmSlot;
struct Tcbl;
extern void func_0207D534(volatile u16 *reg, int brightness);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *func_0220AF40(u16 v);
extern void func_0220D5C0(char *);
extern void func_0220D6DC(char *);
extern void func_0220D798(char *);
extern void func_0220BB1C(char *);
extern void func_0220D7F0(void *, int);
extern void func_0220B120(char *);
extern void func_0220B1B0(char *, int);
extern unsigned func_0220B990(u8 *);
extern void func_0220BBE4(char *);
extern void func_0220BD24(char *, int);
extern void func_0220C034(char *);
extern void func_0220C4EC(char *, int);
extern void func_0220AFDC(char *, void *);
extern void func_0220D8C4(u8 *, unsigned, unsigned);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned, unsigned);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void *BTLV_EFFECT_GetOwner(void);
extern int PALANM_RequestFade(void *, u16, u16, short, u8, u8, u16, void *);
int func_0220CAAC(char *p)
{
    d_04001050[0] = 0;
    func_0207D534((u16 *)((unsigned)d_04001050 + 0x1c), -16);
    ((struct Obj01076 *)p)->f4 = TCBL_Create(((struct Obj25059 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC, ((struct Obj25060 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC, 1, 4);
    ((struct Obj01076 *)p)->f148 = func_0220AF40(((struct Obj25061 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC);
    func_0220D5C0(p);
    func_0220D6DC(p);
    func_0220D798(p);
    func_0220BB1C(p);
    func_0220D7F0(p, ((struct Obj01076 *)p)->f532);
    func_0220B120(p);
    func_0220B1B0(p, ((struct Obj01076 *)p)->f532);
    func_0220B990((u8 *)p);
    func_0220BBE4(p);
    func_0220BD24(p, ((struct Obj01076 *)p)->f532);
    func_0220C034(p);
    func_0220C4EC(p, ((struct Obj01076 *)p)->f532);
    if (**(u8 * *)&((struct Obj25062 *)(*(char * *)&((struct Obj01076 *)p)->f0))->f2C == 1) ((struct Obj01076 *)p)->f598 = (void *)1;
    else ((struct Obj01076 *)p)->f598 = 0;
    func_0220AFDC(*(char * *)&((struct Obj01076 *)p)->f148, ((struct Obj01076 *)p)->f598);
    func_0220D8C4((u8 *)p, ((struct Obj01076 *)p)->f532, 0);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj25064 *)(*(char * *)&((struct Obj01076 *)p)->f0))->fC);
    PALANM_CopyHwPaletteToSlot(((struct Obj01076 *)p)->f8, 3, 0xe0, 0x20);
    PALANM_RequestFade(((struct Obj01076 *)p)->f8, 0xa, 0xffff, 0, 0x10, 0, 0, BTLV_EFFECT_GetOwner());
    ((struct Obj01076 *)p)->f5A0 = 1;
    return 2;
}
