/*
 * function: func_021C2560
 * address:  0x021C2560
 * packet:   pkt_ov208_021C2560
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC32C  0x021BC32C  thumb  ov208
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021BC3A8  0x021BC3A8  thumb  ov208
 *   func_021BC3AC  0x021BC3AC  thumb  ov208
 *   func_021BC3B0  0x021BC3B0  thumb  ov208
 *   ov208_func_021BCF4C  0x021BCF4C  thumb  ov208
 *   func_021C2BE0  0x021C2BE0  thumb
 *   func_021C2BA8  0x021C2BA8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_021BC448  0x021BC448  thumb  ov208
 *   func_021BC518  0x021BC518  thumb  ov208
 *   func_021BC508  0x021BC508  thumb  ov208
 *   func_021BC610  0x021BC610  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct S {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 pad0c[0x10];
    u32 f1c;
    u8 pad20[0x34];
    u32 a54[2];
    u32 f5c;
    u8 pad60[8];
    u32 f68;
    u8 pad6c[8];
    u16 f74;
    u16 f76;
    u8 pad78[0x40];
    u32 fb8;
    u32 fbc;
    u32 fc0;
    u32 fc4;
    u32 fc8;
    u32 fcc;
    u32 fd0;
};

struct Ov208Buf;
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void MI_CpuFill8(void *dst, int v, u32 n);
extern int func_021BC3A8(int *p);
extern int func_021BC3AC(int *p);
extern int func_021BC3B0(int *p);
extern u32 ov208_func_021BCF4C(int v);
extern void func_021C2BE0(void *unused, u8 *p, void *a2);
extern void func_021C2BA8(void *a0, u8 *st);
extern u32 func_020056A0(void (*cb)(void *, u8 *), void *arg, int pri);
extern void *func_021BC448(u32 heap);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void *func_021BC610(u32 heap);

u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj)
{
    struct S *st;
    u8 i;

    st = func_021BC32C(a0, 0xd4, *desc);
    MI_CpuFill8(st, 0, 0xd4);
    i = 0;
    st->f0 = ov208_func_021BCF4C(func_021BC3A8(obj));
    st->f4 = func_021BC3AC(obj);
    st->f8 = func_021BC3B0(obj);
    st->f1c = 0;
    st->f68 = 0;
    st->f74 = 0;
    st->f76 = 1;
    st->fb8 = 0;
    func_021C2BE0(desc, (u8 *)st, obj);
    st->fbc = func_020056A0(func_021C2BA8, st, 1);
    st->fc0 = (u32)func_021BC448(*desc);
    st->fc4 = (u32)func_021BC448(*desc);
    func_021BC518((int *)st->fc0);
    func_021BC518((int *)st->fc4);
    func_021BC508(0, (int *)st->fc0);
    func_021BC508(1, (int *)st->fc4);
    st->fc8 = (u32)func_021BC610(*desc);
    st->fcc = 0;
    st->fd0 = 1;
    for (i = 0; i < 2; i++) {
        st->a54[i] = 0;
    }
    st->f5c = 0;
    return 1;
}
