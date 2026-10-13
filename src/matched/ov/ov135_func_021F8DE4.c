/*
 * function: func_021F8DE4
 * address: 0x021F8DE4
 * packet: pkt_ov135_021F8DE4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   PROCSYS_Push 0x02031348 arm
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   func_021F8F5C 0x021F8F5C thumb ov135
 *   str_02203C34 0x02203C34 data a1
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   ov115_id 0x00000073 data
 */
#include "../include/Obj04527.h"
#include "../include/Obj23403.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    void *save;
    int zero;
    int enabled;
    int pad[2];
    void (*callback)(void);
    void *context;
} Req;
typedef unsigned short u16;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, u32, u32);
extern void *func_020120F4(const struct Ctx *p);
extern void PROCSYS_Push(void *, u32, void *, void *);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern u32 func_021F8F5C(u8 *p);
extern char str_02203C34[];
extern u8 tbl_021D654C[];
extern u8 ov115_id[];
int func_021F8DE4(u8 *p)
{
    Req *r;
    *(Req * *)&((struct Obj04527 *)p)->f10DC = func_02030734(72, 28, 0, str_02203C34, 689);
    func_02082BCC(*(Req * *)&((struct Obj04527 *)p)->f10DC, 0, 28);
    r = *(Req * *)&((struct Obj04527 *)p)->f10DC;
    r->save = func_020120F4(((struct Obj23403 *)(*(u8 * *)&((struct Obj04527 *)p)->f0))->f40);
    r->zero = 0;
    r->enabled = 1;
    r->callback = (void (*)(void))func_021F8F5C;
    r->context = p;
    PROCSYS_Push(((struct Obj04527 *)p)->f12F0, (u32)ov115_id, tbl_021D654C, *(Req * *)&((struct Obj04527 *)p)->f10DC);
    ((struct Obj04527 *)p)->f28 = 5;
    GFL_NET_ERR_ShowScreen(0);
    return 2;
}
