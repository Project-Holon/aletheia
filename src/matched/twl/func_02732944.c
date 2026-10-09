/*
 * function: func_02732944
 * address:  0x02732944
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
 *   func_020862B8  0x020862B8  arm  twl
 *   func_02166804  0x02166804  arm  ov009
 *   func_02166358  0x02166358  arm  ov009
 *   func_02731F14  0x02731F14  arm  twl
 *   func_027032E0  0x027032E0  arm  twl
 *   func_02732648  0x02732648  arm  twl
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
extern void func_021659B4(u32 a, void *b, u32 c, u32 line);
extern void func_020862B8(void *buf, u32 len);
extern void func_02166804(u8 v);
extern void func_02166358(u8 *a, u8 *b, u8 *c, u32 len);
extern void func_02731F14(void);
extern int func_027032E0(void *cb, u8 flag, void *buf);
extern void func_02732648(void *arg);

void func_02732944(Pkt *p)
{
    NetWork *w = func_021657C8();
    int lv;

    switch (p->kind) {
    case 0:
        if (w->state == 12) {
            func_02165A4C(8);
            func_02731F14();
            return;
        }
        switch (func_027032E0(func_02732648, (w->flags & 2) ? 1 : 0, w->buf)) {
        case 2:
            return;
        case 6:
            func_02165A4C(12);
            func_021659B4(1, w->buf, 0, 1286);
            return;
        case 3:
        default:
            func_02165A4C(11);
            func_021659B4(7, w->buf, 0, 1295);
            return;
        }
    case 11:
        func_020862B8(p->data, 0x620);
        lv = p->level;
        if (lv < 0) {
            lv = 0;
        }
        if (lv > 0x100) {
            lv = 0xff;
        }
        func_02166804(lv);
        func_02166358(p->data + 6, p->data, p->data + 14, p->len - 14);
        return;
    }
}