/*
 * function: func_021B9898
 * address: 0x021B9898
 * packet: pkt_ov218_021B9898
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct Item { void *text; u16 color; u16 padding; u32 value; };
struct TaskMenuTmpl { u32 heapId; u8 count; u8 pad05[3]; const void *unk08; u32 unk0c; u8 pad10[2]; u8 unk12, unk13; };
extern void *func_02045EC0(struct MsgBank *, u32);
extern void STRBUF_Delete(struct U16Vec *);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *, void *);
struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap)
{
    struct TaskMenuTmpl config;
    struct Item items[2];
    struct TaskMenu *menu;
    u32 i;
    for (i = 0; i < 2; i++) {
        items[i].text = func_02045EC0(bank, i + 235);
        items[i].color = 0x39e3;
        items[i].value = 0;
    }
    config.heapId = heap;
    config.count = 2;
    config.unk08 = items;
    config.unk0c = 1;
    config.pad10[0] = 32;
    config.pad10[1] = 18;
    config.unk12 = 13;
    config.unk13 = 3;
    menu = APP_TASKMENU_OpenMenu(&config, arg);
    for (i = 0; i < 2; i++)
        STRBUF_Delete((struct U16Vec *)items[i].text);
    return menu;
}
