/*
 * function: func_021C47A0
 * address: 0x021C47A0
 * packet: pkt_ov127_021C47A0
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C6110 0x021C6110 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_02030734(u16,u32,int,const char *,u16);
extern const char d_021C6110[];
typedef struct {u16 width,height;void *entries;} Grid;
Grid *func_021C47A0(u32 w,u32 h,u32 heap) { Grid *p;p=func_02030734(heap,8,1,d_021C6110,76);p->width=w;p->height=h;p->entries=func_02030734(heap,p->width*p->height*4,1,d_021C6110,83);return p; }
