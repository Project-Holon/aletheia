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
 *   func_0204384C 0x0204384C arm
 *   func_020439A0 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Entry { int x,y,pad,bank,index,px,py; u8 r,g,b,pad2; u32 arc,member,enabled; };
struct Bmp;
struct MsgBank;
struct Obj020437AC;
extern const struct Entry d_021C37A4[];
extern struct Bmp *func_0204384C(u32,u32,u32,u32);
extern void func_020439A0(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_020307B0(void *);
extern void func_020437AC(struct Obj020437AC *);
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
            bmp=func_0204384C(q->arc,q->member,0,*(u16 *)(p+4));
            dest=p+i*4;
            func_020439A0(bmp,*(struct Bmp **)(dest+0x3B0),0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+12+q->bank*4),q->index);
            func_0201C7D0(*(void **)(dest+0x3B0),q->px,q->py,text,*(void **)(p+8),color);
            func_020307B0(text);
            func_020437AC((struct Obj020437AC *)bmp);
        }
    }
}
