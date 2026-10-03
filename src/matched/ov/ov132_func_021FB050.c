/*
 * function: func_021FB050
 * address: 0x021FB050
 * packet: pkt_ov132_021FB050
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_021F9E00 0x021F9E00 thumb ov132
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB0DC 0x021FB0DC thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
extern int func_0201134C(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_021F9DFC(void *);
extern void func_021F9E00(void *, u16);
extern void *func_021FADA0(char *, u32, u32, u32);
extern void func_021FB0DC(void *unused, char *p);
int func_021FB050(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char **)ctx;
    time = func_0201134C(*(void **)(ctx + 4));
    target = func_0201134C(*(void **)(ctx + 4));
    wait = func_0201134C(*(void **)(ctx + 4));
    if (time == 0) {
        func_021F9E00(*(void **)(owner + 0x34), target);
    } else {
        p = func_02030734(*(u16 *)owner, 0x18, 0, d_021FDD00, 0x1e9);
        *(char **)(p + 0x10) = owner;
        *(void **)p = *(void **)(owner + 0x34);
        *(u16 *)(p + 0xe) = 0;
        *(int *)(p + 4) = func_021F9DFC(*(void **)(owner + 0x34));
        *(int *)(p + 8) = target;
        *(u16 *)(p + 0xc) = time;
        *(void **)(p + 0x14) = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
        if (wait == 1) {
            *(u16 *)(ctx + 0x14) = *(u16 *)(p + 0xc);
            return 1;
        }
    }
    return 0;
}
