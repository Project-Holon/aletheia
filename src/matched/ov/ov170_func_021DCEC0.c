/*
 * function: BOX2_MAIN_CreateTaskMenu
 * address: 0x021DCEC0
 * packet: pkt_ov170_021DCEC0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 */
typedef unsigned int   u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
typedef unsigned short u16;
struct R;
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
#define WORK(p) (*(char **)((p)+0x2c))
#define PTR(p,n) (*(void **)(WORK(p)+(n)))
#define HALF(p,n) (*(unsigned short *)(WORK(p)+(n)))
void BOX2_MAIN_CreateTaskMenu(char *p)
{
    PTR(p,0x184)=func_02045EC0(PTR(p,0x80),0x6e);
    HALF(p,0x188)=0x39e3;
    PTR(p,0x18c)=0;
    PTR(p,0x190)=func_02045EC0(PTR(p,0x80),0x6f);
    HALF(p,0x194)=0x39e3;
    PTR(p,0x198)=0;
    PTR(p,0x19c)=APP_TASKMENU_RES_Create(0,8,(u32)PTR(p,0x78),(u32)PTR(p,0x8c),0x4c);
}
