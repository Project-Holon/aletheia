/*
 * function: func_021F1520
 * address: 0x021F1520
 * packet: pkt_ov107_021F1520
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TALKMSGWIN_Delete 0x02194798 thumb ov021
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_021F18EC 0x021F18EC thumb ov107
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov021_id 0x00000015 data
 */
typedef unsigned char  u8;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenu;
struct TaskMenuState;
struct U16Vec;
extern void TALKMSGWIN_Delete(unsigned char *a);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern void TIME_ICON_Delete(u8 *p);
extern int APP_KEYCURSOR_Delete(int a0);
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021F18EC(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern char ov021_id[];
#define P(k) (*(void **)(p+(k)))
void func_021F1520(char *p)
{
    if(P(0x54))TALKMSGWIN_Delete(P(0x54));
    if(P(0x3C))APP_TASKMENU_CloseMenu(P(0x3C));
    if(P(0x50))BMP_MENU_DeleteYesNo(P(0x50));
    if(P(0x5C)){TIME_ICON_Delete(P(0x5C));P(0x5C)=0;}
    APP_KEYCURSOR_Delete((int)P(0x44));APP_TASKMENU_RES_Delete(P(0x40));func_0201C4C0(P(0x30));
    if(P(0x18))func_0201CE48(P(0x18));
    if(P(0x20))STRBUF_Delete(P(0x20));
    if(P(0x24))func_021F18EC(p);
    MSGDATA_Delete(P(0x1C));
    if(P(0x10))func_020452E8(P(0x10));
    GF_FONT_Delete(P(0x14));TCBL_Destroy(P(0x0C));func_020307B0(p);func_02034A5C((int)ov021_id);
}
