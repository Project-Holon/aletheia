/*
 * function: func_0216968C
 * address:  0x0216968C
 * packet:   pkt_ov010_0216968C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0206A9DC  0x0206A9DC  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0206AA0C  0x0206AA0C  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_021699A0  0x021699A0  thumb  ov010
 *   func_02047C8C  0x02047C8C  arm
 *   d_0217216C     0x0217216C  data   ov010  a4
 *   d_02172178     0x02172178  data   ov010  a4
 *   d_02148C08     0x02148C08  data   a4
 *   d_02148BCC     0x02148BCC  data   a4
 *   d_02172160     0x02172160  data   ov010  a4
 *   d_02148B98     0x02148B98  data   a4
 */
#include "../include/Obj03541.h"
#include "../include/Obj19050.h"
#include "../include/Obj19051.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0206A9DC(void *p);
extern void func_02082B60(void *a, void *b);
extern void func_0206AA0C(void *p);
extern void func_0206A854(void);
struct P02047C8C;
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern int func_021699A0(void *p);
extern void func_02047C8C(struct P02047C8C *p);
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern struct {
    u8 pad[0x7c];
    u32 f7c;
} d_02148BCC;
extern u8 d_02172160[];
extern u8 d_02148B98[];

int func_0216968C(u8 *p)
{
    int r;

    r = 0;
    if (*(u16 *)&((struct Obj03541 *)p)->f0 != 0 && ((struct Obj19050 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4 != 0) {
        func_0206A9DC(d_0217216C);
        func_02082B60(d_02172178, d_02148C08);
        d_02148BCC.f7c &= ~0xa4;
        func_0206AA0C(d_02172160);
        func_0206A854();
        func_0206DDA4(0x15, 0, 0);
        func_0206DDA4(0x17, d_02148B98, 0xc);
        func_0206DDA4(0x1c, p + 4, 3);
        if (func_021699A0(((struct Obj19051 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4) == 1) {
            func_02047C8C(((struct Obj03541 *)p)->f2C);
            r = 1;
        }
    }
    return r;
}
