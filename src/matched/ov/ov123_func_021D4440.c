/*
 * function: func_021D4440
 * address: 0x021D4440
 * packet: pkt_ov123_021D4440
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4AB4 0x021D4AB4 thumb ov123
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern int func_0203CD98(void);
extern void *func_02012138(void *);
struct Comm;
extern void func_02026400(struct Comm *p);
extern void func_021D4244(char *, void *, int);
extern void func_021D4AB4(char *p);
typedef struct {
    char pad00[8];
    int f08;
    u16 f0c;
    char pad0e[0x256];
    void *f264;
    char pad268[0x24];
    int f28c;
} Object;
void func_021D4440(Object *p)
{
    p->f28c = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, p->f0c);
    switch (p->f08) {
    case 2:
    case 3:
        if (func_0203CD98())
            func_02026400(func_02012138(p->f264));
        break;
    }
    func_021D4244((char *)p, func_021D4AB4, 0x1aa);
}
