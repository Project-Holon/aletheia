/*
 * function: func_02185254
 * address: 0x02185254
 * packet: pkt_ov219_02185254
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original truncates heap before 020457B0, and stack bytes before 02184D30; extern narrow widths preserve those visible operations.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045730 0x02045730 arm
 *   func_02184968 0x02184968 thumb ov219
 *   func_02184D30 0x02184D30 thumb ov219
 *   func_02185C84 0x02185C84 thumb ov219
 *   d_02185DCB 0x02185DCB data a1
 */
#include "../include/Obj02934.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern const u8 d_02185DCB[];
extern void *func_020457B0(unsigned,u16);
struct Cfg;
struct Descriptor;
struct Record;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F73C(void *,int,int,int);
struct Descriptor;
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(unsigned);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern u32 func_02184968(const u8 *p, int flag);
extern void func_02184D30(char *p, struct Record *out, struct Descriptor *d, void *text, u8 x, u8 y);
extern int func_02185C84(unsigned,unsigned,void *,void *,unsigned);
void func_02185254(char *p,unsigned key,unsigned member)
{
    void *first,*second,*object;
    first=func_020457B0(64,((struct Obj02934 *)p)->f0);
    second=func_020457B0(64,((struct Obj02934 *)p)->f0);
    ((struct Obj02934 *)p)->fC040=(void *)func_02184968(d_02185DCB,1);
    func_02185C84(key,member,first,second,((struct Obj02934 *)p)->f0);
    if(member!=0) func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,second,0,16);
    func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,first,0,0);
    func_02045808(second);
    func_02045808(first);
    func_0201F73C(((struct Obj02934 *)p)->fC040,0,34,7);
    object=((struct Obj02934 *)p)->fC040;
    func_02045334(object);
    func_02045374(object);
    func_02041B6C(func_02045730(object));
}
