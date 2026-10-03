/*
 * function: func_02207BAC
 * address: 0x02207BAC
 * packet: pkt_ov094_02207BAC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: matched ov094_func_02207C94.c and its existing shard cover the
 *   48-byte follower at 02207C94; retain this lead as a single function.
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02018584 0x02018584 thumb
 *   func_02207EA8 0x02207EA8 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    char p0[0x48];
    int f48, f4c, f50, f54, f58, f5c;
    char p60[8];
    int f68;
    u8 f6c;
    char p6d[3];
    u32 lo : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 f4 : 4;
    u32 f8 : 8;
    u32 mid : 12;
    u32 b28 : 1;
    u32 hi : 3;
    char p74[12];
} E;
typedef struct { char pad[0x40]; E e[8]; } O;
extern int func_021D59B4(u8 *p, int k);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern u32 func_02018584(u16, u16, u16);
extern void func_02207EA8(E *, int);
void func_02207BAC(O *o, void *q, int idx)
{
    int delta;
    u32 next;
    delta = o->e[idx].f58 - o->e[idx].f54;
    o->e[idx].f48 = func_021D59B4(q, 13);
    o->e[idx].f4c = func_021D59B4(q, 14);
    o->e[idx].f50 = (int)0x80000000;
    o->e[idx].f68 = 0;
    o->e[idx].f6c = func_021D59B4(q, 15);
    next = func_02018584(func_021D5444(q), func_021D59B4(q, 19), func_021D59B4(q, 15) + 1);
    o->e[idx].f5c = next - func_02018584(func_021D5444(q), func_021D59B4(q, 19), func_021D59B4(q, 15));
    o->e[idx].f4 = 0;
    o->e[idx].b2 = 1;
    o->e[idx].f8 = 0;
    o->e[idx].b28 = 1;
    func_02207EA8(&o->e[idx], delta);
}
