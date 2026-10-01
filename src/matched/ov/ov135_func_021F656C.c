/*
 * function: func_021F656C
 * address: 0x021F656C
 * packet: pkt_ov135_021F656C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F6B40 0x021F6B40 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[8]; void *party; void *save; } Ctx;
typedef struct { Ctx *ctx; u8 pad4[0x28-4]; unsigned state; u8 pad2c[0xC4-0x2C]; u16 box, slot; unsigned count; void *mon; u8 padD0[0xDD0-0xD0]; void *dd0; } Work;
extern unsigned func_021F4D14(void *p);
extern void func_021F4CE4(void *p);
extern void func_021F4EC0(void *p, unsigned a, unsigned b);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_0201F7A8(void *desc, unsigned kind);
int func_021F656C(Work *p)
{
    unsigned result = func_021F4D14(p);
    if (result == 1) {
        func_021F4CE4(p);
        p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        p->state = 2;
        func_021F4EC0(p, 6, 0);
    } else if (result == 2) {
        func_021F4CE4(p);
        func_0201F7A8(p->dd0, 0);
        p->state = 1;
    }
    return 2;
}
