/*
 * function: func_021C6E3C
 * address: 0x021C6E3C
 * packet: pkt_ov128_021C6E3C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027778 0x02027778 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {int heap;u8 count;u8 pad[3];void *entries;int mode;u8 x,y,a,b;} TextConfig;
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
void *func_021C6E3C(void *p,void **q,int a,int heap) {TextConfig c;c.heap=heap;c.count=2;c.entries=p;c.mode=1;c.x=32;if(a==1)c.y=18;else c.y=12;c.a=8;c.b=3;return func_02027778((struct TaskMenuTmpl *)(&c),*q);}
