/*
 * function: GAME_BEACON_RequestSend
 * address:  0x02026FB8
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   GAME_BEACON_Work     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f00;
    u32 f04 : 17;
    u32 f04hi : 15;
    u32 f08 : 17;
    u32 f08b : 5;
    u32 f08hi : 10;
    u32 f0clo : 16;
    u32 f0c : 10;
    u32 f0chi : 6;
    u8  pad10[0x5c - 0x10];
    u16 f5c;
    u8  f5e;
} Obj;

extern void *GAME_BEACON_Work;

struct Big;
struct Blk34;
struct PlayTime;
extern void *func_02012EBC(struct Big *p);
extern int func_02012FCC(int p0);
extern void *func_0200C0F0(void *a);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u32 func_0200C1C4(struct Blk34 *p);
extern u32 func_0200C1DC(struct Blk34 *p);

void GAME_BEACON_RequestSend(Obj *o)
{
    void *a;
    void *b;

    a = func_02012EBC(*(void **)GAME_BEACON_Work);
    b = (void *)func_02012FCC((int)(*(void **)GAME_BEACON_Work));
    a = func_0200C0F0(a);
    o->f0c = func_0200864C(b);
    o->f0chi = func_02008650(b);
    o->f08 = func_0200C1C4(a);
    o->f04 = func_0200C1DC(a);
    o->f08b = o->f08b + 1;
    o->f5c = 0;
    o->f5e = 1;
}
