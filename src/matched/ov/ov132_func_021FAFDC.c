/*
 * function: func_021FAFDC
 * address: 0x021FAFDC
 * packet: pkt_ov132_021FAFDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB0DC 0x021FB0DC thumb ov132
 *   func_021F96D0 0x021F96D0 thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
extern int func_0201134C(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_021F9DFC(void *);
extern void *func_021FADA0(char *, u32, u32, u32);
extern void func_021FB0DC(void *, void *);
extern void func_021F96D0(void *);
int func_021FAFDC(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char **)ctx;
    wait = func_0201134C(*(void **)(ctx + 4));
    p = func_02030734(*(u16 *)owner, 0x18, 0, d_021FDD00, 0x1c1);
    *(char **)(p + 0x10) = owner;
    *(void **)p = *(void **)(owner + 0x34);
    *(u16 *)(p + 0xe) = 0;
    *(int *)(p + 4) = func_021F9DFC(*(void **)(owner + 0x34));
    *(int *)(p + 8) = 0;
    delta = *(int *)(p + 8) - *(int *)(p + 4);
    if (delta < 0) delta = -delta;
    *(u16 *)(p + 0xc) = delta / 2;
    *(void **)(p + 0x14) = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    func_021F96D0(*(void **)(owner + 0x34));
    if (wait == 1) {
        *(u16 *)(ctx + 0x14) = *(u16 *)(p + 0xc);
        return 1;
    }
    return 0;
}
