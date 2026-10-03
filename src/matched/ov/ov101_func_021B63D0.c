/*
 * function: func_021B63D0
 * address: 0x021B63D0
 * packet: pkt_ov101_021B63D0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039468 0x02039468 arm
 *   func_021B6424 0x021B6424 thumb ov101
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Obj { unsigned char pad[0x78]; int busy; unsigned char pad7c[6]; u16 counter; } Obj;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern int func_02039468(u32,u32);
extern int func_021B6424(int);
int func_021B63D0(Obj *p)
{
    u16 old;
    if (p->busy) return 1;
    old = p->counter;
    p->counter += 1;
    if (old > 180) {
        p->counter = 0;
        if (!func_02039468(0xD02,func_0203D1A4((void *)func_020399A8())))
            return func_021B6424((int)p);
    }
    return 0;
}
