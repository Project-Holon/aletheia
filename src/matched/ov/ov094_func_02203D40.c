/*
 * function: func_02203D40
 * address: 0x02203D40
 * packet: pkt_ov094_02203D40
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02206AF8 0x02206AF8 thumb ov094
 *   func_02206A58 0x02206A58 thumb ov094
 *   func_02204960 0x02204960 thumb ov094
 *   func_022043C0 0x022043C0 thumb ov094
 *   func_022045A8 0x022045A8 thumb ov094
 *   func_0202173C 0x0202173C thumb
 *   func_02040588 0x02040588 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0220687C 0x0220687C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct Main {
    void *owner;
    char pad04[0x60];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1bc];
    void *obj228;
} Main;
typedef struct { Main *main; int state; } Ctx;
extern void func_02206AF8(char *p);
extern void func_02206A58(char *p);
extern void func_02204960(Main *, int, int, int, int, int, int, int);
extern void func_022043C0(Main *, int, int, int, int);
extern void func_022045A8(Main *, int, int);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void func_0220687C(char *p, void *q);
void func_02203D40(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_02206AF8((char *)c->main);
        func_02204960(c->main, 5, 0, 0, 0, 0, 2, 1);
        func_022043C0(c->main, 0x3000, 0x1000, -0x400, 0x98);
        func_02206A58((char *)c->main);
        func_0202173C(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            func_022045A8(c->main, 0, 0);
            func_02040588(5, 1);
            func_02040588(7, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            func_02045374(c->main->obj228);
            func_020409B4(6);
            func_02045334(c->main->obj228);
            func_02204960(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}
