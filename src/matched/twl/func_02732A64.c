/*
 * function: func_02732A64
 * address:  0x02732A64
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_021659B4  0x021659B4  arm  ov009
 *   func_02731F14  0x02731F14  arm  twl
 *   func_02703424  0x02703424  arm  twl
 *   func_02732874  0x02732874  arm  twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct NetWork {
    u8 pad0[0x12da];
    u16 phase;
    u8 pad1[2];
    u8 state;
    u8 pad2[0x12e0 - 0x12df];
    u8 buf[0x130c - 0x12e0];
    u16 flags;
} NetWork;
typedef struct Pkt {
    u16 pad0;
    u16 kind;
    u16 pad1;
    short level;
    u32 len;
    u8 *data;
} Pkt;

extern NetWork *func_021657C8(void);
extern void func_02165A4C(u8 phase);
extern void func_02731F14(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 line);
extern int func_02703424(void *cb);
extern void func_02732874(void);

void func_02732A64(Pkt *p)
{
    NetWork *w = func_021657C8();
    switch (p->kind) {
    case 0:
        if (w->state == 12) {
            func_02165A4C(10);
            func_02731F14();
            return;
        }
        switch (func_02703424(func_02732874)) {
        case 2:
            func_02165A4C(10);
            w->phase = 6;
            return;
        case 6:
            func_02165A4C(12);
            func_021659B4(1, w->buf, 0, 1365);
            return;
        case 3:
            func_02165A4C(10);
            func_02731F14();
            return;
        default:
            func_02165A4C(11);
            func_021659B4(7, w->buf, 0, 1378);
            return;
        }
    case 1:
    case 2:
        break;
    }
    func_02165A4C(11);
    func_021659B4(7, w->buf, 0, 1390);
}
