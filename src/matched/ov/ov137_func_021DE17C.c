/*
 * function: func_021DE17C
 * address: 0x021DE17C
 * packet: pkt_ov137_021DE17C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj02868.h"
#include "../include/Obj23729.h"
#include "../include/Obj23730.h"
#include "../include/Obj23731.h"
#include "../include/Obj23732.h"
#include "../include/Obj23733.h"
typedef unsigned char  u8;
extern void *func_021DCF50(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern int func_021841A4(unsigned char *p);
extern u16 func_02039338(void);
void func_021DE17C(char *p, int command, int player) {
    void *target;
    if (((struct Obj02868 *)p)->f118 == 3) {
        switch (command) {
        case 1:
            target = func_02184180(func_021DCF50((u8 *)p), player);
            if (target != 0)
                func_0201F02C(((struct Obj02868 *)p)->f3C, 0, target);
            ((struct Obj02868 *)p)->f118 = command;
            ((struct Obj23729 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = func_021841A4(func_021DCF50((u8 *)p));
            ((struct Obj23730 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            return;
        case 19:
            func_0201F02C(((struct Obj02868 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), player));
            if (player != func_02039338()) {
                if (func_02039338() == 0)
                    ((struct Obj23731 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 &= player ^ 0xffff;
                ((struct Obj02868 *)p)->f118 = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Obj23732 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            ((struct Obj23733 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = func_021841A4(func_021DCF50((u8 *)p));
        }
    }
}
