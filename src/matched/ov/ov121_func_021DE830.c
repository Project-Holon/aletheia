/*
 * function: func_021DE830
 * address: 0x021DE830
 * packet: pkt_ov121_021DE830
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02157DD8 0x02157DD8 thumb ov010
 *   func_02157E34 0x02157E34 thumb ov010
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE910 0x021DE910 thumb ov121
 *   d_0209DF0C 0x0209DF0C data a1
 */
#include "../include/Obj06455.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Descriptor {
    int kind;
    u16 zero, heap;
    int size;
    void *data;
    int setting;
    int flags;
    u8 pad[0x60];
    int enabled;
} Descriptor;
extern void func_02082BCC(void *, int, int);
extern void *func_02157DD8(void *);
extern int func_02157E34(void *);
extern int func_0203CD98(void);
extern void func_0203D34C(unsigned, unsigned);
typedef unsigned int   u32;
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE910(void *, int *, char *);
extern u8 d_0209DF0C;
void func_021DE830(void *a, int *state, char *p)
{
    Descriptor d;
    switch (*state) {
    case 0:
        func_02082BCC(&d, 0, 0x7c);
        d.kind = 9;
        d.size = 0x2d0;
        d.data = p + 0x7a4;
        d.zero = 0;
        d.heap = ((struct Obj06455 *)p)->f58;
        d.setting = d_0209DF0C;
        d.enabled = 1;
        d.flags = 0x200000;
        ((struct Obj06455 *)p)->f79C = func_02157DD8(&d);
        func_02157E34(((struct Obj06455 *)p)->f79C);
        ((struct Obj06455 *)p)->f17A4 = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203CD98()) {
            func_0203D34C(1, ((struct Obj06455 *)p)->f58);
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE910);
        break;
    }
}
