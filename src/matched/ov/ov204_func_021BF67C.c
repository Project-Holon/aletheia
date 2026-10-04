/*
 * function: func_021BF67C
 * address: 0x021BF67C
 * packet: pkt_ov204_021BF67C
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   defaultPos 0x021C08FC data
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015E04 0x02015E04 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 */
#include "../include/Obj10881.h"

struct Vec { int v[3]; };
extern const struct Vec defaultPos;
extern void *func_020173F0(unsigned short, unsigned short, unsigned long long, unsigned short);
extern void func_02017100(void *, void *, unsigned int);
extern void func_020307B0(void *);
extern void *func_020159C8(void *, unsigned int, unsigned int, unsigned int, void *);
extern void func_02015CAC(void *, void *);
extern void func_02015E04(void *);
extern unsigned int func_0203F0A8(void);
typedef unsigned char  u8;
extern void func_021BF7F0(u8 *p);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);

void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i)
{
    char data[36];
    struct Vec pos = defaultPos;
    void *tmp = func_020173F0((unsigned short)species, 0, 0, ((struct Obj10881 *)p)->f0);
    char *base = p + 8;
    unsigned int off = i * 12;
    func_02017100(tmp, data, 0);
    func_020307B0(tmp);
    *(void **)(base + off) = func_020159C8(((struct Obj10881 *)p)->f4, a, b, c, data);
    func_02015CAC(*(void **)(base + off), &pos);
    func_02015E04(*(void **)(base + off));
    *(unsigned int *)(p + off + 12) = 0;
    *(unsigned int *)(p + off + 16) = 1;
    ((struct Obj10881 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)func_0203F0A8() * 5) >> 32) + 200;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
