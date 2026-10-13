/*
 * function: func_021C04FC
 * address: 0x021C04FC
 * packet: pkt_ov217_021C04FC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37A4 0x021C37A4 data a4
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_020307B0 0x020307B0 arm
 *   BMP_Delete 0x020437AC arm
 */
#include "../include/Obj14753.h"
#include "../include/Obj14754.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Entry { int x,y,pad,bank,index,px,py; u8 r,g,b,pad2; u32 arc,member,enabled; };
struct Bmp;
struct MsgBank;
struct Obj020437AC;
extern const struct Entry d_021C37A4[];
extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);
extern void BMP_Blit(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern u32 func_020307B0(void *p);
extern void BMP_Delete(struct Obj020437AC *);
void func_021C04FC(u8 *p)
{
    const struct Entry *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u8 *dest;
    int i;
    for(i=0;i<2;i++) {
        q=&d_021C37A4[i];
        if(q->enabled) {
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct Obj14753 *)p)->f4);
            dest=p+i*4;
            BMP_Blit(bmp,*(struct Bmp * *)&((struct Obj14754 *)dest)->f3B0,0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+12+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct Obj14754 *)dest)->f3B0,q->px,q->py,text,((struct Obj14753 *)p)->f8,color);
            func_020307B0(text);
            BMP_Delete((struct Obj020437AC *)bmp);
        }
    }
}
