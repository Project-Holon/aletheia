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
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   MCSS_Add  0x020159C8  thumb  arm9
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb  arm9
 *   POKE_TOOL_Create  0x020173F0  thumb  arm9
 */
#include "../include/Obj10881.h"

struct Vec { int v[3]; };
extern const struct Vec defaultPos;
extern void *POKE_TOOL_Create(unsigned short, unsigned short, unsigned long long, unsigned short);
typedef unsigned int   u32;
struct Obj;
struct Rec;
struct Stats;
struct Sub150;
extern void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl);
extern u32 func_020307B0(void *p);
extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetAnmStopFlag(void *);
extern unsigned int func_0203F0A8(void);
typedef unsigned char  u8;
extern void func_021BF7F0(u8 *p);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);

void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i)
{
    char data[36];
    struct Vec pos = defaultPos;
    void *tmp = POKE_TOOL_Create((unsigned short)species, 0, 0, ((struct Obj10881 *)p)->f0);
    char *base = p + 8;
    unsigned int off = i * 12;
    MCSS_TOOL_MakeAddWorkFromPP(tmp, (struct Stats *)data, 0);
    func_020307B0(tmp);
    *(void **)(base + off) = MCSS_Add(((struct Obj10881 *)p)->f4, a, b, c, (const struct Sub150 *)data);
    MCSS_SetScale(*(void **)(base + off), (u32 *)(&pos));
    MCSS_SetAnmStopFlag(*(void **)(base + off));
    *(unsigned int *)(p + off + 12) = 0;
    *(unsigned int *)(p + off + 16) = 1;
    ((struct Obj10881 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)func_0203F0A8() * 5) >> 32) + 200;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
