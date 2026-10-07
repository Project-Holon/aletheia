/*
 * file:     demo3d_graphic_p05.c
 * unit:     yes
 * function: func_021BE538, func_021BE620, func_021BE62C
 * address:  0x021BE538
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201160C 0x0201160C thumb
 *   func_021BF858 0x021BF858 thumb
 *   func_020115C0 0x020115C0 thumb
 *   func_02011B8C 0x02011B8C thumb
 *   sub_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 *   func_021BE508 0x021BE508 thumb
 *   func_02048AD0 0x02048AD0 arm
 *   func_021BDF18 0x021BDF18 thumb
 *   func_02047A60 0x02047A60 arm
 *   func_021BDF24 0x021BDF24 thumb
 *   func_0204EA4C 0x0204EA4C arm
 *   func_02011608 0x02011608 thumb
 */
#include "../../matched/include/Obj25315.h"
#include "../../matched/include/Obj25316.h"

struct IcaAnime;
struct Light;
struct Arg;
struct Obj11245;
struct Owner;
struct TcblNode;
struct Obj11244;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct Context { void *a0; u32 a4,a8,ac,a10,step; struct IcaAnime *anime; u8 *table; void *light; u32 a24,a28,count; u8 args[0x3c]; void *events; u16 *indices; void *a74; };

typedef struct Config {unsigned words[11];} Config;

extern u32 func_0201160C(struct Obj11245 *p);
extern void func_021BF858(void *,int,int);
extern u32 func_020115C0(struct IcaAnime *,int);
extern void func_02011B8C(void *,void *);
extern u32 sub_02048A18(u8 *,int);
extern int func_0204779C(int *);
extern int func_02047910(void *,int,int);
extern void func_021BE508(char *p, struct Light *q);
extern void func_02048AD0(struct Light *);
extern void func_021BDF18(char *p);
extern void func_02047A60(void *,struct Arg *);
extern void func_021BDF24(char *p);
extern void func_0204EA4C(void);
extern u32 func_02011608(struct Obj11244 *p);
int func_021BE538(const struct Context *ctx, u32 frames);
int func_021BE620(char *p);
u32 func_021BE62C(char *p);

int func_021BE538(const struct Context *ctx, u32 frames)
{
    u32 done;
    long advance = 0;
    unsigned long time = func_0201160C((struct Obj11245 *)ctx->anime);
    u32 i;
    for(i=0;i<frames+1;i++) {
        if(ctx->a8 == 0) func_021BF858(ctx->events,time+advance,i);
        else func_021BF858(ctx->events,-4096,i);
        advance += ctx->step;
    }
    done = func_020115C0(ctx->anime,advance);
    func_02011B8C(ctx->light,ctx->anime);
    for(i=0;i<ctx->count;i++) {
        void *obj=(void *)sub_02048A18(ctx->table,ctx->indices[i]);
        int j, count=func_0204779C(obj);
        for(j=0;j<count;j++) func_02047910(obj,(u16)j,advance);
    }
    if(ctx->a10 != 0) func_021BE508((char *)ctx,ctx->light);
    func_02048AD0(ctx->light);
    func_021BDF18(ctx->a0);
    for(i=0;i<ctx->count;i++) {
        func_02047A60((void *)sub_02048A18(ctx->table,ctx->indices[i]),(struct Arg *)ctx->args);
    }
    func_021BDF24(ctx->a0);
    if(ctx->a10 != 0) func_0204EA4C();
    return done;
}

int func_021BE620(char *p) { return func_0201160C(((struct Obj25315 *)p)->f18); }

u32 func_021BE62C(char *p) { return func_02011608(((struct Obj25316 *)p)->f18); }
