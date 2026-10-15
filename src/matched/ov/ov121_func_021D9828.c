/*
 * function: MYSTERY_GRAPHIC_ExitBg
 * address: 0x021D9828
 * packet: pkt_ov121_021D9828
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: u8 extern parameter reproduces original truncation before BLX.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021DF634 0x021DF634 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;
extern const Entry d_021DF634[];
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *,int,u32);
void MYSTERY_GRAPHIC_ExitBg(void *p) {
    u32 i=0;
    do { func_020403F4((u8)d_021DF634[i].id); ++i; } while(i<7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p,0,4);
}
