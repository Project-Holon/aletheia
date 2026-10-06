/*
 * function: func_021C9F6C
 * address: 0x021C9F6C
 * packet: pkt_ov093_021C9F6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA0B8 0x021CA0B8 thumb ov093
 *   func_021CA0C8 0x021CA0C8 thumb ov093
 *   func_021CA0D8 0x021CA0D8 thumb ov093
 *   func_021CA0E8 0x021CA0E8 thumb ov093
 *   func_021CA0F8 0x021CA0F8 thumb ov093
 *   func_021CA108 0x021CA108 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021BF83C 0x021BF83C thumb ov093
 *   func_021BF3D8 0x021BF3D8 thumb ov093
 *   func_021BF4AC 0x021BF4AC thumb ov093
 *   func_021BF8D4 0x021BF8D4 thumb ov093
 *   func_021CA118 0x021CA118 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021C091C 0x021C091C thumb ov093
 */
#include "../include/Obj00003.h"
#include "../include/Obj05194.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Out { u16 h0,h2,h4; u8 b6,pad7; u32 w8,wc,w10; };
struct State { u16 h0; u8 b2,b3,b4; u8 flag:1; u8 rest:7; };
extern u8 *func_021B9934(char *p, int i);
struct Out64B4;
struct Unk021BD1E0;
struct Unk021BD200;
extern void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern void func_021CA0B8(void *);
extern void func_021CA0C8(void *);
extern void func_021CA0D8(void *, u8 *);
extern void func_021CA0E8(void *, int);
extern void func_021CA0F8(void *);
extern int func_021CA108(void *);
extern void func_021C5718(u8 *, u8 *, u32);
extern void func_021BF83C(u8 *, u16 *, u8 *, int);
extern void func_021BF3D8(u8 *, int, u8 *, int, void *);
extern void func_021BF4AC(u8 *, u8 *, u8 *, void *, void *);
extern void func_021BF8D4(u8 *, u16 *, u8 *, int);
extern int func_021CA118(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *p);
extern void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t);
extern void func_021C091C(u8 *, u8 *, u8 *, u8 *, u32, u32);
u8 func_021C9F6C(u8 *p, u8 *q)
{
    u8 work[28];
    struct Out *out = (struct Out *)(work + 8);
    u16 *saved;
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
    struct State *state;
    u32 flag;
    func_021C64B4(p, *(u16 *)(q + 6), a, (struct Out64B4 *)out);
    func_021CA0B8(((struct Obj00003 *)p)->f860);
    func_021CA0C8(((struct Obj00003 *)p)->f868);
    func_021CA0D8(((struct Obj00003 *)p)->f868, b);
    func_021CA0E8(((struct Obj00003 *)p)->f868, 1);
    func_021CA0F8(((struct Obj00003 *)p)->f868);
    if (func_021CA108(((struct Obj00003 *)p)->f868)) {
        func_021C5718(p, a, ((u16 *)work)[4]);
        return 0;
    }
    func_021BF83C(p, (u16 *)out, a, *(int *)&((struct Obj00003 *)p)->f868);
    func_021BF3D8(p, (int)out, a, *(int *)&((struct Obj00003 *)p)->f868, p + 0x1f88);
    func_021BF4AC(p, (u8 *)out, a, ((struct Obj00003 *)p)->f868, p + 0x1f88);
    func_021BF8D4(p, (u16 *)out, a, *(int *)&((struct Obj00003 *)p)->f868);
    if (func_021CA118(((struct Obj00003 *)p)->f868)) return 0;
    state = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
    saved = (u16 *)work;
    saved[0] = ((struct Obj05194 *)state)->f0;
    saved[1] = ((struct Obj05194 *)state)->f2;
    saved[2] = ((struct Obj05194 *)state)->f4;
    func_021BD1E0((struct Unk021BD1E0 *)state);
    func_021BD200((struct Unk021BD200 *)(*(struct State * *)&((struct Obj00003 *)p)->f4A8), p, a, *(int *)&((struct Obj00003 *)p)->f868);
    (*(struct State * *)&((struct Obj00003 *)p)->f4A8)->b4 = 1;
    func_021C091C(p, (u8 *)out, a, *(u8 * *)&((struct Obj00003 *)p)->f868, (u32)(p + 0x1f88), 1);
    state = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
    flag = state->flag;
    ((struct Obj05194 *)state)->f0 = saved[0];
    ((struct Obj05194 *)state)->f2 = saved[1];
    ((struct Obj05194 *)state)->f4 = saved[2];
    return flag;
}
