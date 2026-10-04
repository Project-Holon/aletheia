/*
 * function: func_021F0054
 * address:  0x021F0054
 * packet:   pkt_ov031_021F0054
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02037174  0x02037174  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0202DBC4  0x0202DBC4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *obj);
extern void func_02037174(void);
extern void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
extern void func_0201C4E4(u32 a);
extern void func_0202DBC4(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern int func_0201C6C4(u32 a, u32 b);
extern void func_02045334(u32 a);

#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    char pad1[0x58 - 0x44];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

void func_021F0054(struct Obj *p, int mode)
{
    int i;

    func_02026474((void *)func_02012138((const struct Ctx *)p->w0));
    func_02037174();
    if (mode == 1)
        REG_DB_BLDCNT_SUB = 0;
    else
        G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_0201C4E4(p->w40);
    func_0202DBC4((void *)p->w7c);
    for (i = 0; i < 3; i++) {
        if (p->b[i] == 1) {
            u32 q = p->w40;
            if (p->s[i].f != 0) {
                if (func_0201C6C4(q, (u32)func_02045770((struct Descriptor *)p->s[i].h)) == 0) {
                    func_02045334(p->s[i].h);
                    p->s[i].f = 0;
                }
            }
        }
    }
}
