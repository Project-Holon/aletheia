/*
 * function: func_02156F14
 * address:  0x02156F14
 * packet:   pkt_ov009_02156F14
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   func_02060C94  0x02060C94  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {
    u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; u32 f14; u32 f18; u32 f1C; u16 f20;
} Obj;
extern Obj *d_021A8268;
extern void func_02060C94(u32 heap);
extern void func_020307B0(u32 p);
extern void func_020306F0(void);
void func_02156F14(void)
{
    if (d_021A8268->fC != 0) {
        func_02060C94(d_021A8268->f8);
        func_020307B0(d_021A8268->fC);
        d_021A8268->f8 = 0;
        d_021A8268->fC = 0;
        if (d_021A8268->f20 != 0) {
            func_020306F0();
            d_021A8268->f20 = 0;
        }
    }
}
