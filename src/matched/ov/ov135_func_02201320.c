/*
 * function: func_02201320
 * address: 0x02201320
 * packet: pkt_ov135_02201320
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045808 0x02045808 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 */
#include "../include/Obj05420.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0217BC90(void);
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
int func_02201320(u8 *p)
{
    int done;
    int positive;
    u16 *dst;
    void *bank;
    void *str;
    u16 *text;
    int i;
    done = func_0217BC90() == 2;
    if (done) positive = ((struct Obj05420 *)p)->f1320 > 0;
    if (done) {
        if (positive) {
            dst = (u16 *)(p + 0x1f4);
            bank = func_02045B38(0, 2, 0x51, 0x48);
            str = func_02045EC0(bank, 0xf);
            func_02045C04(bank);
            text = func_02045A90(str);
            for (i = 0; i < 7 && (u32)i < func_020458F8(str); i++) dst[i] = text[i];
            dst[i] = func_02045A98();
            func_02045808(str);
        }
        ((struct Obj05420 *)p)->f28 = ((struct Obj05420 *)p)->fE10;
    } else {
        if ((((struct Obj05420 *)p)->fF8C)++ == 0xe10) {
            ((struct Obj05420 *)p)->f38 = -5;
            ((struct Obj05420 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
        }
    }
    return 2;
}
