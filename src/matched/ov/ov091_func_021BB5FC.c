/*
 * function: PLIST_MESSAGE_Destroy
 * address:  0x021BB5FC
 * packet:   pkt_ov091_021BB5FC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void TIME_ICON_Delete(u8 *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern int APP_KEYCURSOR_Delete(int a0);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 func_020307B0(void *p);

void PLIST_MESSAGE_Destroy(void *a, int *s)
{
    if (s[0] != 4) {
        PLIST_MESSAGE_CloseWindow(a, (u32 *)s);
    }
    if (s[13] != 0) {
        TIME_ICON_Delete((u8 *)s[13]);
    }
    if (s[3] != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)s[3]);
        STRBUF_Delete((struct U16Vec *)s[4]);
    }
    PRINTSYS_QUE_Clear((struct PrintSys *)s[10]);
    PRINTSYS_QUE_Delete((struct PrintSys *)s[10]);
    APP_KEYCURSOR_Delete(s[5]);
    TCBL_Destroy((struct S02031140 *)s[2]);
    func_020307B0(s);
}
