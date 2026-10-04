/*
 * unit: yes
 * function: func_021DFE6C,func_021DFEA0,func_021DFEAC,func_021DFEB8
 * address: 0x021DFE6C
 * packet: pkt_ov137_021DFE6C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * followers: 021DFEA0,021DFEAC,021DFEB8 are pooled tail-call stubs; parent cleared ownership.
 * symbols:
 *   func_021DFE6C  0x021DFE6C  thumb  ov137
 *   func_021E1634 0x021E1634 thumb ov137
 *   func_02062B30 0x02062B30 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj23769.h"
#include "../include/Obj23770.h"
typedef unsigned char u8;
extern void *func_021E1634(u8 *,int,int);
extern int func_02062B30(void *,void **);
typedef unsigned int   u32;
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_020409B4(u32 index);
extern void func_020307B0(void *);
void func_021DFE6C(u8 *p,int file)
{
    void *buf;
    u8 *screen;
    buf=func_021E1634(p,file,0);
    func_02062B30(buf,(void **)(p+3420));
    screen=*(u8 * *)&((struct Obj23769 *)p)->fD5C;
    func_02040AE0(6,screen+12,((struct Obj23770 *)screen)->f8);
    func_020409B4(6);
    func_020307B0(buf);
}
void func_021DFEA0(u8 *p) { func_021DFE6C(p,26); }
void func_021DFEAC(u8 *p) { func_021DFE6C(p,24); }
void func_021DFEB8(u8 *p) { func_021DFE6C(p,25); }
