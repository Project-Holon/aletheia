/*
 * function: MYSTERY_UTIL_CreateMenu
 * address: 0x021DA038
 * packet: pkt_ov121_021DA038
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const source parameter and the original heap stack argument to 0201F878.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   d_021DF78C 0x021DF78C data a4
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj01542.h"
#include "../include/Obj01731.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 word[13];} Config;
extern const char d_021DFBA0[];
extern const Config d_021DF78C;
struct Cfg;
struct Descriptor;
struct Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,u32);
struct Slot;
struct Src;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
extern void *BMP_MENUWORK_Create(u32,u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02020D10(u8 *p, u32 v);
void *MYSTERY_UTIL_CreateMenu(const u8 *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    Config cfg;
    out=func_02030734(heap,24,0,d_021DFBA0,0x2cb);
    MI_CpuFill8(out,0,24);
    ((struct Obj01731 *)out)->f4=((struct Obj01542 *)p)->f8;
    ((struct Obj01731 *)out)->f0=(void *)BMP_WIN_Create((u8)(((struct Obj01542 *)p)->f1C),(u16)19,(u16)((u8)(17-(u8)(((struct Obj01542 *)p)->f18*2))),(u8)12,(u8)(((struct Obj01542 *)p)->f18*2),((struct Obj01542 *)p)->f1E,1);
    BMP_MENUWORK_DrawWindow(((struct Obj01731 *)out)->f0,2,((struct Obj01542 *)p)->f22,(u8)(((struct Obj01542 *)p)->f20));
    q=((struct Obj01731 *)out)->f0;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    ((struct Obj01731 *)out)->f8=((struct Obj01731 *)out)->f0;
    out[12]=0;
    ((struct Obj01731 *)out)->f14=BMP_MENUWORK_Create(((struct Obj01542 *)p)->f18,heap);
    for(i=0;i<((struct Obj01542 *)p)->f18;i++)
        BMP_MENUWORK_AddMsgItem(((struct Obj01731 *)out)->f14,((struct Obj01542 *)p)->f0,*(u32 *)(p+12+i*4),i,(u16)heap);
    cfg=d_021DF78C;
    cfg.word[0]=*(u32 *)&((struct Obj01731 *)out)->f14;
    *(u16 *)((u8 *)&cfg+0x10)=((struct Obj01542 *)p)->f18;
    *(u16 *)((u8 *)&cfg+0x12)=((struct Obj01542 *)p)->f18;
    cfg.word[3]=*(u32 *)&((struct Obj01731 *)out)->f0;
    cfg.word[9]=((struct Obj01542 *)p)->f0;
    cfg.word[10]=(u32)(out+8);
    cfg.word[11]=((struct Obj01542 *)p)->f8;
    cfg.word[12]=((struct Obj01542 *)p)->f4;
    ((struct Obj01731 *)out)->f10=BMP_MENULIST_Create((struct Src *)(&cfg),0,0,heap);
    func_02020CF8(((struct Obj01731 *)out)->f10,heap);
    func_02020D10(((struct Obj01731 *)out)->f10,0);
    return out;
}
