/*
 * function: ERROR_SCREEN_PrintMessage
 * address:  0x021B6368
 * packet:   pkt_ov017_021B6368
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_0207E24C  0x0207E24C  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   BMP_CreateFromVram  0x02043754  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   BMP_Delete  0x020437AC  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0207DFB4(void);
extern u32 func_0207E24C(void);
extern void MIi_CpuClear16(int, u32, u32);
typedef signed short   s16;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void BMP_Delete(struct Obj020437AC *p);

void ERROR_SCREEN_PrintMessage(int a)
{
    u16 *base;
    int j, i;
    u16 v;
    int p, q, r, s;

    base = func_0207DFB4();
    v = 0x20;
    for (i = 4; i < 20; i++) {
        for (j = 1; j < 31; j++) {
            base[i * 32 + j] = v;
            v++;
        }
    }
    MIi_CpuClear16(0x7777, func_0207E24C() + 0x400, 0x3C00);
    p = (int)BMP_CreateFromVram((void *)(func_0207E24C() + 0x400), 30, 16, 32, 1);
    q = (int)GF_FONT_Create(0x17, 0, 0, 0, 1);
    r = (int)func_02045B38(0, 2, 0xe8, 1);
    s = (int)func_02045EC0((struct MsgBank *)r, a);
    PRINTSYS_PrintColor((void *)p, 0, 0, (void *)s, (void *)q, 0x1167);
    STRBUF_Delete((struct U16Vec *)s);
    MSGDATA_Delete((struct Rec *)r);
    GF_FONT_Delete((void *)q);
    BMP_Delete((struct Obj020437AC *)p);
}
