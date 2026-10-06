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
 *   sub_02031194 0x02031194 arm
 *   sub_02045B38 0x02045B38 arm
 *   sub_02045EC0 0x02045EC0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   sub_02045334 0x02045334 arm
 *   sub_02045374 0x02045374 arm
 *   sub_02045730 0x02045730 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_0201F79C 0x0201F79C thumb
 *   sub_02045C04 0x02045C04 arm
 *   func_0204047C 0x0204047C arm
 *   sub_02040588 0x02040588 arm
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
extern void sub_02031194(struct TcblNode *);
extern struct MsgBank *sub_02045B38(u32,u32,u32,u32);
extern void *sub_02045EC0(struct MsgBank *,u32);
extern void func_0201DD78(u32,u32,u32);
/* The caller stores the live r0 result, although the matched wrapper was typed void. */
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void sub_02045334(struct Descriptor *);
extern void sub_02045374(struct Cfg *);
extern u8 sub_02045730(struct Descriptor *);
extern void sub_020409B4(u32);
extern void func_0201F79C(void *,u32,u32,u32);
extern u32 sub_02045C04(struct Rec *rec);
extern void func_0204047C(int,u16);
extern void sub_02040588(u32,u32);
void func_021BF320(struct TcblNode *task, struct Context *ctx)
{
    struct Config *cfg = ctx->cfg;
    if (cfg->ac != 0) {
        func_021BF470((char *)ctx);
        sub_02031194(task);
        return;
    }
    switch (ctx->state) {
    case 0: {
        struct MsgBank *bank = sub_02045B38(0,2,(u16)ctx->file,cfg->a2);
        void *desc;
        ctx->text = sub_02045EC0(bank,ctx->index);
        func_0201DD78(1,2,15);
        ctx->printer = func_0201CCE4((u32)ctx->desc,0,0,(u32)ctx->text,cfg->a24,cfg->a18,cfg->a20,0,cfg->a0,15);
        desc = ctx->desc;
        sub_02045334(desc);
        sub_02045374(desc);
        sub_020409B4(sub_02045730(desc));
        func_0201F79C(ctx->desc,1,ctx->base,0);
        sub_02045C04((struct Rec *)bank);
        func_0204047C(1,0);
        func_0204047C(0,1);
        sub_02040588(1,1);
        ctx->state++;
        break;
    }
    case 1:
        if (ctx->count++ >= ctx->limit) {
            func_021BF470((char *)ctx);
            sub_02031194(task);
        }
        break;
    }
}
