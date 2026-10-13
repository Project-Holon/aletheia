/*
 * function: func_021EFFE8
 * address:  0x021EFFE8
 * packet:   pkt_ov031_021EFFE8
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
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   func_021F0420  0x021F0420  thumb  ov031
 *   func_021F056C  0x021F056C  thumb  ov031
 *   func_021F04D4  0x021F04D4  thumb  ov031
 *   func_021F0478  0x021F0478  thumb  ov031
 *   func_021F0348  0x021F0348  thumb  ov031
 *   func_021F022C  0x021F022C  thumb  ov031
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *obj);
struct Obj;
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_021F0420(char *p);
extern void func_021F056C(char *p);
extern void func_021F04D4(char *p);
extern void func_021F0478(char *p);
extern void func_021F0348(void *p);
extern void func_021F022C(char *p);
extern u32 func_020307B0(void *p);
extern void func_02037190(void);

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void func_021EFFE8(u32 *p)
{
    u8 *q;

    q = (u8 *)func_02026474((void *)func_02012138((const struct Ctx *)p[0]));
    if (q != 0)
        q[0x282E] = 0;
    PMS_DRAW_Delete((void *)p[0x1F]);
    func_021F0420((char *)p);
    func_021F056C((char *)p);
    func_021F04D4((char *)p);
    func_021F0478((char *)p);
    func_021F0348(p);
    func_021F022C((char *)p);
    func_020307B0(p);
    REG_DB_BLDCNT_SUB = 0;
    func_02037190();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}
