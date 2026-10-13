/*
 * function: func_021BCBA4
 * address: 0x021BCBA4
 * packet: pkt_ov216_021BCBA4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCF08 0x021BCF08 thumb ov216
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   func_021BD174 0x021BD174 thumb ov216
 *   func_021BD0E4 0x021BD0E4 thumb ov216
 *   func_021BD448 0x021BD448 thumb ov216
 *   func_021BCD60 0x021BCD60 thumb ov216
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00051.h"
extern void func_021BCF08(char *p);
typedef unsigned short u16;
struct Queue;
struct Rec;
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct Rec *out, u16 *tag, int delta);
typedef unsigned char  u8;
extern void func_021BD174(char *p, void *record, u16 unused, u8 slot);
extern void func_021BD0E4(char *p, u8 index, unsigned int enable);
extern void func_021BD448(char *p);
typedef unsigned int   u32;
extern void func_021BCD60(unsigned char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void func_021BCBA4(unsigned char *p)
{
    func_021BCF08((char *)p);
    GAME_BEACON_ACCESSOR_TableRingGet(((struct Obj00051 *)p)->f24,((struct Obj00051 *)p)->f28,(u16 *)(p+0x2c),*(p+p[0x30]+0x31));
    func_021BD174((char *)p,((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f2C,p[0x2e]);
    func_021BD0E4((char *)p,p[0x2e],1);
    func_021BD0E4((char *)p,p[0x2e]^1,0);
    func_021BD448((char *)p); func_021BCD60(p);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00051 *)p)->f2);
}
