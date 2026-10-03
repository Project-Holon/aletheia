/*
 * function: func_021BF550
 * address: 0x021BF550
 * packet: pkt_ov203_021BF550
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 0x04000052
 * symbols:
 *   func_021BF758 0x021BF758 thumb
 *   sub_02031194 0x02031194 arm
 *   sub_02049B68 0x02049B68 arm
 *   func_02049990 0x02049990 arm
 *   sub_0207C768 0x0207C768 arm
 *   func_0204047C 0x0204047C arm
 *   sub_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct TcblNode;
struct Config { u16 a0,heap; u32 a4,a8,stop,a10,a14,a18,a1c,a20,a24; void *archive; };
struct Context { struct Config *cfg; int state,count,wait; u32 first,a14,second; int fadein,fadeout,blend,step; };
extern void func_021BF758(struct Context *);
extern void sub_02031194(struct TcblNode *);
extern void sub_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *,u32,u32,u32,u32,u32,u32,u16);
extern u32 sub_0207C768(u32,u32);
extern void func_0204047C(int,u16);
extern void sub_02040588(u32,u32);
extern void func_0207D63C(u32,int,int,int,int);
void func_021BF550(struct TcblNode *task,struct Context *ctx)
{
    struct Config *cfg=ctx->cfg;
    float a;
    if(cfg->stop != 0) {
        func_021BF758(ctx);
        sub_02031194(task);
        return;
    }
    switch(ctx->state) {
    case 0:
        sub_02049B68(cfg->archive,ctx->first,0,0,0,cfg->heap);
        func_02049990(cfg->archive,ctx->second,1,0,0,0,1,cfg->heap);
        ctx->state++;
        break;
    case 1:
        ctx->count=0;
        ctx->blend=0;
        if(ctx->fadein>0) a=0.5f+(float)(ctx->fadein<<12);
        else a=(float)(ctx->fadein<<12)-0.5f;
        ctx->step=sub_0207C768(0x10000,(int)a);
        func_0204047C(1,0);
        func_0204047C(0,1);
        func_0207D63C(0x04000050,2,1,0,16);
        sub_02040588(1,1);
        ctx->state++;
        break;
    case 2:
        if(ctx->count++ < ctx->fadein) {
            int value;
            ctx->blend += ctx->step;
            value=ctx->blend>>12;
            *(volatile u16 *)0x04000052=value|((16-value)<<8);
        } else {
            *(volatile u16 *)0x04000052=16;
            ctx->count=0;
            ctx->state++;
        }
        break;
    case 3:
        if(ctx->count++ >= ctx->wait) {
            ctx->count=0;
            ctx->blend=0;
            if(ctx->fadeout>0) a=0.5f+(float)(ctx->fadeout<<12);
            else a=(float)(ctx->fadeout<<12)-0.5f;
            ctx->step=sub_0207C768(0x10000,(int)a);
            ctx->state++;
        }
        break;
    case 4:
        if(ctx->count++ < ctx->fadeout) {
            int value;
            ctx->blend += ctx->step;
            value=ctx->blend>>12;
            *(volatile u16 *)0x04000052=(16-value)|(value<<8);
        } else {
            *(volatile u16 *)0x04000052=0x1000;
            ctx->count=0;
            ctx->state++;
        }
        break;
    default:
        func_021BF758(ctx);
        sub_02031194(task);
        break;
    }
}
