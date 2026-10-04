/*
 * function: func_02201258
 * address: 0x02201258
 * packet: pkt_ov135_02201258
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045808 0x02045808 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0217BC44 0x0217BC44 arm ov009
 */
#include "../include/Obj06520.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
struct Strbuf;
extern struct U16Vec *func_020457B0(u32, u32);
extern void func_02045994(struct Strbuf *,const u16 *,u32);
extern u16 *func_02045A90(struct U16Vec *);
extern u16 func_020458F8(struct U16Vec *);
extern u16 func_02045A98(void);
extern void func_02045808(struct U16Vec *);
extern void func_02082BCC(void *, int, u32);
extern void func_0217BC44(void *, int, int, int, void *, void *, int);
int func_02201258(u8 *p)
{
    struct U16Vec *s;
    u16 *text;
    u32 i;
    u16 c;
    s=func_020457B0(8,0x48);
    func_02045994((struct Strbuf *)s,(u16 *)(p+0x1F4),8);
    func_02082BCC(p+0x1300,0,0x28);
    ((struct Obj06520 *)p)->f1324=0x48;
    text=func_02045A90(s);
    for(i=0;i<func_020458F8(s)+1;i++) {
        c=*(u16 *)((u32)text+i*2);
        if(c==func_02045A98()) *(u16 *)((u32)p+i*2+0x1300)=0;
        else *(u16 *)((u32)p+i*2+0x1300)=c;
    }
    ((struct Obj06520 *)p)->f1318=(u32)(p+0x1300);
    ((struct Obj06520 *)p)->f1320=0;
    func_0217BC44(p+0x1318,1,0,0,p+0x131C,p+0x1320,0x80);
    func_02045808(s);
    ((struct Obj06520 *)p)->f28=5;
    ((struct Obj06520 *)p)->fF8C=0;
    return 2;
}
