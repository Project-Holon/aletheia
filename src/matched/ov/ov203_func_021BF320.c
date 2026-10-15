/*
 * function: func_021BF320
 * address: 0x021BF320
 * packet: pkt_ov203_021BF320
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF470 0x021BF470 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENUWORK_DrawWindowEx 0x0201F79C thumb
 *   sub_02045C04 0x02045C04 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
struct MsgBank;
struct TcblNode;
struct Descriptor;
struct Cfg;
struct Config { u16 a0,a2; u32 a4,a8,ac,a10,a14; s8 a18; u8 pad[7]; u32 a20,a24; };
struct Context { struct Config *cfg; int state,count,limit; u32 file,index,base; void *desc; u32 printer; void *text; };
struct Rec;
extern void func_021BF470(char *p);
extern void TCBL_DeleteTask(struct TcblNode *);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32,u32,u32,u32);
extern void *MSGDATA_AllocString(struct MsgBank *,u32);
extern void GF_FONT_SetTextColor(u32,u32,u32);
/* The caller stores the live r0 result, although the matched wrapper was typed void. */
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void BG_SYS_PushTile(u32);
extern void BMP_MENUWORK_DrawWindowEx(void *,u32,u32,u32);
extern u32 sub_02045C04(struct Rec *rec);
extern void BG_SYS_SetVisibleLayer(int,u16);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
void func_021BF320(struct TcblNode *task, struct Context *ctx)
{
    struct Config *cfg = ctx->cfg;
    if (cfg->ac != 0) {
        func_021BF470((char *)ctx);
        TCBL_DeleteTask(task);
        return;
    }
    switch (ctx->state) {
    case 0: {
        struct MsgBank *bank = MSGDATA_CreateFromArchive(0,2,(u16)ctx->file,cfg->a2);
        void *desc;
        ctx->text = MSGDATA_AllocString(bank,ctx->index);
        GF_FONT_SetTextColor(1,2,15);
        ctx->printer = PRINTSYS_PrintStream((u32)ctx->desc,0,0,(u32)ctx->text,cfg->a24,cfg->a18,cfg->a20,0,cfg->a0,15);
        desc = ctx->desc;
        BMP_WIN_TransferChars(desc);
        BMP_WIN_MakeScreen(desc);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(desc));
        BMP_MENUWORK_DrawWindowEx(ctx->desc,1,ctx->base,0);
        sub_02045C04((struct Rec *)bank);
        BG_SYS_SetVisibleLayer(1,0);
        BG_SYS_SetVisibleLayer(0,1);
        BG_SYS_SetPlaneVisible(1,1);
        ctx->state++;
        break;
    }
    case 1:
        if (ctx->count++ >= ctx->limit) {
            func_021BF470((char *)ctx);
            TCBL_DeleteTask(task);
        }
        break;
    }
}
