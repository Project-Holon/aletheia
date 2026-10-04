/*
 * function: func_021866C4
 * address:  0x021866C4
 * packet:   pkt_ov023_021866C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_02184180  0x02184180  thumb  ov022
 *   func_02039338  0x02039338  arm
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Big;
struct L0200ED54;
struct Sub0200852CObj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern char *func_02184180(unsigned char *p, int i);
typedef unsigned short u16;
extern u16 func_02039338(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);

void func_021866C4(u32 *p)
{
    int i;
    u32 h;
    u32 r;

    h = (u32)func_0200ED48(func_02012EBC((struct Big *)(*(u32 *)(p[1] + 4))));
    for (i = 0; i < 5; i++) {
        r = (u32)func_02184180((unsigned char *)(*(u32 *)p[1]), (u8)i);
        if (r != 0) {
            if (i != func_02039338()) {
                func_0200ED54((struct L0200ED54 *)h, func_02008530((const struct Sub0200852CObj *)r));
            }
        }
    }
}
