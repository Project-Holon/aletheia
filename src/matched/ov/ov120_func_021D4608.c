/*
 * function: func_021D4608
 * address: 0x021D4608
 * packet: pkt_ov120_021D4608
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02039338 0x02039338 arm
 *   func_0200ED48 0x0200ED48 thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4584 0x021D4584 thumb ov120
 */
#include "../include/Obj08076.h"
#include "../include/Obj22823.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0217BC90(void);
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern u16 func_02039338(void);
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4584(u8 *p);
void func_021D4608(u8 *p)
{
    int ready = 0;
    int value = ((struct Obj22823 *)(*(u8 * *)&((struct Obj08076 *)p)->f48))->f18;
    int active;
    void *message;
    void *text;
    int result;
    active = func_0217BC90() == 2;
    if (active)
        ready = ((struct Obj08076 *)p)->f1A8 > 0;
    if (active) {
        if (ready) {
            message = func_02045B38(0, 2, 0x51, 0x1f);
            text = func_02045EC0(message, 15);
            func_02045C04(message);
            func_020084E4((u16 *)value, text);
            func_02045808(text);
        }
        func_02008494((void *)value, func_02012950((struct Sub24 *)(((struct Obj08076 *)p)->f2C), 1 - func_02039338()));
        result = func_02008530((const struct Sub0200852CObj *)value);
        func_0200ED54(func_0200ED48((void *)(((struct Obj08076 *)p)->f30)), result);
        func_021D4244((int)p, (void (*)(int))func_021D4584, 0x283);
    }
}
