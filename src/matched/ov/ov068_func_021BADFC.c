/*
 * function: OPTION_MENU_ExitMessageBox
 * address: 0x021BADFC
 * packet: pkt_ov068_021BADFC
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   OPTION_MENU_ExitTextBox 0x021BA254 thumb ov068
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void OPTION_MENU_ExitTextBox(u8 *);
extern void MI_CpuFill8(void *, u32, u32);
void OPTION_MENU_ExitMessageBox(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) STRBUF_Delete((struct U16Vec *)(*(u32 *)(p + i * 12 + 60)));
    OPTION_MENU_ExitTextBox(p);
    MI_CpuFill8(p, 0, 112);
}
