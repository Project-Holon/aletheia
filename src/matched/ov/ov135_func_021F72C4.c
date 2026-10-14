/*
 * function: WORLDTRADE_DEMO_ReadMyStatus
 * address:  0x021F72C4
 * packet:   pkt_021F72C4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_02008560  0x02008560  thumb
 *   func_02008568  0x02008568  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008574  0x02008574  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
} Info;

typedef struct {
    u8 pad0[0xF6];
    u8 fF6;
    u8 padF7[0x108 - 0xF7];
    u32 f108;
    u32 f10C;
    u8 name[0x120 - 0x110];
    u8 f120;
    u8 f121;
    u8 f122;
    u8 pad123;
    u8 f124;
    u8 f125;
} Entry;

extern void *MYSTATUS_Create(int a0);
struct Sub0200852CObj;
extern void MYSTATUS_Init(struct Sub0200852CObj *p);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_02008560(struct Sub0200852CObj *obj, u8 value);
extern void func_02008568(struct Sub0200852CObj *obj, u8 value);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);

Info *WORLDTRADE_DEMO_ReadMyStatus(Entry *e)
{
    Info *info;

    info = MYSTATUS_Create(0x48);
    MYSTATUS_Init((struct Sub0200852CObj *)info);
    func_020084D4((u32)info, e->name);
    func_02008560((struct Sub0200852CObj *)info, e->f124);
    func_02008568((struct Sub0200852CObj *)info, e->f125);
    func_0200854C((struct Sub0200852CObj *)info, e->fF6);
    func_02008558((struct Sub0200852CObj *)info, e->f122);
    func_02008574((struct Sub0200852CObj *)info, e->f120, e->f121);
    info->f10 = e->f10C;
    info->f14 = e->f108;
    return info;
}
