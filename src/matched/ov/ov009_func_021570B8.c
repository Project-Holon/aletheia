/*
 * function: func_021570B8
 * address:  0x021570B8
 * packet:   pkt_ov009_021570B8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02156F14  0x02156F14  thumb  ov009
 *   func_02060C94  0x02060C94  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

extern Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02156F14(void);
extern void func_02060C94(void *heap);
extern u32 func_020307B0(void *p);

void func_021570B8(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f1C == 1 || d_021A8268->fC != 0) {
        func_02156F14();
    }
    func_02060C94((void *)d_021A8268->f0);
    func_020307B0((void *)d_021A8268->f4);
    func_020307B0(d_021A8268);
    d_021A8268 = 0;
}
