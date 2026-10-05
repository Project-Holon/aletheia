/*
 * function: func_021D9F04
 * address:  0x021D9F04
 * packet:   pkt_021D9F04
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02006210  0x02006210  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02012E08  0x02012E08  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_02157170  0x02157170  thumb
 *   func_021DCE60  0x021DCE60  thumb
 *   func_021DCEE0  0x021DCEE0  thumb
 *   func_021DCFDC  0x021DCFDC  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_021DCFFC  0x021DCFFC  thumb
 *
 * Error poll: while the link is up, classifies the transport error through 0x02157170 (0..4); otherwise classifies the stored error record by its kind, and on a nonzero class shuts the screens down, runs the class action (1 reset, 2 fatal screen, 3 retry) and clears the record.
 */
#include "../include/Obj08279.h"

typedef unsigned long u32;

extern int func_0203CD98(void);
extern u32 func_0200FB24(void);
extern void func_0203D7B0(int a);
extern void func_0203D7BC(int a);
extern void func_02006210(void);
typedef unsigned char  u8;
extern u8 func_02012E40(const u8 *o);
extern void func_02012E08(char *p);
extern void func_0200F7C0(u32 value);
extern int func_02157170(void *a, void *b);
extern u32 func_021DCE60(int a);
extern u32 func_021DCEE0(int a, int b, int c);
extern u32 func_021DCFDC(u32 v);
extern void func_0203C968(void);
extern void func_0203CA04(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_0200FAAC(void);
extern void func_0200FB38(void);
extern void func_0200FA84(void);
extern void func_021DCFFC(void *p);

typedef enum { RES_NONE, RES_1, RES_2, RES_3, RES_4 } Res;

int func_021D9F04(char *ctx, void *a, void *b)
{
    u32 *rec = (u32 *)(ctx + 0x18);
    Res r = RES_NONE;

    if (func_0203CD98()) {
        if (func_0200FB24()) {
            func_0203D7B0(r);
            func_0203D7BC(r);
            func_02006210();
            if (func_02012E40((const u8 *)(((struct Obj08279 *)ctx)->f8))) {
                func_02012E08((char *)(((struct Obj08279 *)ctx)->f8));
                func_0200F7C0(0x29);
            }
        }
        switch (func_02157170(a, b)) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = RES_1;
            break;
        case 2:
            r = RES_2;
            break;
        case 3:
            r = RES_3;
            break;
        case 4:
            r = RES_4;
            break;
        }
        return r;
    }
    if (r == RES_NONE) {
        switch (rec[7]) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = func_021DCE60(rec[0]);
            break;
        case 2:
            r = func_021DCEE0(rec[1], rec[2], rec[3]);
            break;
        case 3:
        case 4:
            r = RES_NONE;
            break;
        case 5:
            r = func_021DCFDC(rec[6]);
            break;
        default:
            r = RES_NONE;
            break;
        }
        if (r != RES_NONE) {
            func_0203D7B0(0);
            func_0203D7BC(0);
            func_02006210();
            if (func_02012E40((const u8 *)(((struct Obj08279 *)ctx)->f8))) {
                func_02012E08((char *)(((struct Obj08279 *)ctx)->f8));
                func_0200F7C0(0x29);
            }
        }
        switch (r) {
        case RES_1:
            func_0203C968();
            func_0203CA04();
            func_0200F83C();
            func_0200FBA0();
            break;
        case RES_2:
            if (!func_0200FB24()) {
                func_0203C9AC(0, 0, 0, 0x3F7);
                func_0200FAAC();
            }
            func_0200FB38();
            break;
        case RES_3:
            func_0200FA84();
            break;
        }
        if (r != RES_NONE)
            func_021DCFFC(rec);
    }
    return r;
}
