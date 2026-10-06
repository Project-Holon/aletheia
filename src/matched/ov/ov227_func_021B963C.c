/*
 * function: func_021B963C
 * address:  0x021B963C
 * packet:   pkt_ov227_021B963C
 * region:   ov227
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wave D4 lane 01): EXACT. Closed by: case 1/2 bodies under `if (r != 1) { ... }`
 * with `return 0;` after the block (late per-case epilogues); the f24 test through an `ok` flag
 * (`ok = 0; if (g->f24 == 1) ok = 1; if (ok)`); `fl = 0;` written after the func_0202F190 call;
 * g->f08 as an if/else on fl. Pool words 0xCF/0xC2 are overlay ids (ov207_id, ov194_id).
 *
 * symbols:
 *   func_020074D8  0x020074D8  thumb
 *   func_02007698  0x02007698  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02013E4C  0x02013E4C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_02031330  0x02031330  arm
 *   func_02031348  0x02031348  arm
 *   ov207_id  0x000000CF  data
 *   ov194_id  0x000000C2  data
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0216C0A4  0x0216C0A4  thumb  ov010
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   func_0216C0D4  0x0216C0D4  thumb  ov010
 *   func_0216C0E4  0x0216C0E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0, f1, f2;
} Ctx;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u16 pad32;
    u32 f34;
} G;

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk37;
struct MsgBank;
struct Party;
struct PartyMon;
struct Rec;
struct Rec44;
struct SaveBlock;
struct Sub02007454Entry;
struct Sub02008C20Obj;
extern unsigned int func_02031330(void *p);
extern unsigned char ov207_id[];
extern unsigned char ov194_id[];
extern u32 func_02031348(u32 a, u32 b, u32 c, void *d);
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0201293C(const struct BigObj *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_02008500(void *a, void *b);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_02007698(void *save);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E4C(u32 a);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
extern int func_0216C0E4(int *p);
extern void func_0216C0D4(int *p, int a1);
extern int func_0216C0C0(int a0);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020185F0(u32 a);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);

u32 func_021B963C(u32 a0, u32 *state, Ctx *c, G *g)
{
    u32 r, x30, x20, x24, x1c, x28, x18, h, r7;
    int x2c, fl, ok;

    r = func_02031330((void *)g->f34);
    if (r == 1) {
        return 0;
    }
    switch (*state) {
    case 0:
        x24 = (u32)func_02012934((const struct BigObj *)c->f0);
        x20 = (u32)func_02012944((void *)c->f0);
        r7 = (u32)func_0200CA1C((void *)c->f0);
        x1c = func_0201293C((const struct BigObj *)c->f0);
        if (c->f1 == 1) {
            x28 = (u32)func_02012F2C((int *)c->f0);
            func_02008DF0((struct Sub02008C20Obj *)x28, (u32)7);
            func_02008DF0((struct Sub02008C20Obj *)x28, (u32)0x54);
            func_02008500((void *)x20, (void *)g->f04);
            func_02017E40((void *)c->f2, 0x8d, g->f04);
            x2c = (int)func_0201AA18((void *)x24);
            if (x2c >= (int)func_0201AA14((void *)x24)) {
                u32 a, b;
                a = func_02007698((void *)x1c);
                b = 0;
                func_020076D0((void *)x1c, (int *)(&a), (int *)(&b));
                g->f2c = a;
                h = (u32)func_02045B38(0, 2, 0xea, 0x8b);
                g->f28 = (u32)func_02045EC0((struct MsgBank *)h, func_020142E8((void *)func_0201296C((const struct BigObj *)c->f0), (u32)0x96d) != 0 ? 0xb1 : 0xb0);
                func_02045C04((struct Rec *)h);
            }
            x30 = func_02013E4C((u32)func_02012AC8(func_020127A4((struct SaveBlock *)c->f0)));
            func_0202F190((void *)c->f2, 0, x20, x30, (u32)g->f30);
            fl = 0;
            x18 = func_0200CA38((struct Blk37 *)r7);
            if (func_0200CED4((struct Blk37 *)r7, (u16)func_02017E1C((void *)c->f2, 5, 0)) == 0) {
                fl = 1;
            }
            func_0200CFA0((struct Blk37 *)r7, (void *)c->f2);
            func_0200CDE0((struct Blk37 *)r7, (void *)c->f2);
            g->f0c = c->f2;
            g->f10 = x18;
            g->f14 = g->f28;
            g->f18 = x1c;
            g->f1c = g->f2c;
            g->f20 = c->f0;
            if (fl) {
                g->f08 = 0;
            } else {
                g->f08 = 1;
            }
            func_02031348(g->f34, (u32)ov207_id, 0x0220BAB0, &g->f08);
            (*state)++;
            break;
        }
        if (c->f1 == 2) {
            func_0200CFA0((struct Blk37 *)r7, (void *)c->f2);
        }
        *state = 4;
        break;
    case 1:
        if (r != 1) {
        r7 = func_0201293C((const struct BigObj *)c->f0);
        ok = 0;
        if (g->f24 == 1) {
            ok = 1;
        }
        if (ok) {
            g->f00 = (u32)func_0216C0A4((u32)g->f30, (u32)c->f2, (u32)0xa, (u32)0, (u32)g->f28, (u32)r7, (u32)g->f2c, (u32)func_0200C0F0(func_02012EBC((struct Big *)c->f0)));
            func_02031348(g->f34, (u32)ov194_id, 0x021F5580, (void *)g->f00);
            (*state)++;
            break;
        }
        *state = 3;
        break;
        }
        return 0;
    case 2:
        if (r != 1) {
        if ((u32)func_0216C0E4((int *)g->f00) == 0) {
            func_0216C0D4((int *)g->f00, (u32)g->f04);
            func_02017E40((void *)c->f2, 0x73, g->f04);
            func_02008DF0(func_02012F2C((int *)c->f0), (u32)0x1e);
        }
        func_0216C0C0((u32)g->f00);
        g->f00 = 0;
        (*state)++;
        break;
        }
        return 0;
    case 3:
        x24 = (u32)func_02012934((const struct BigObj *)c->f0);
        if (g->f28 == 0) {
            func_0201A98C((struct Party *)x24, (const struct PartyMon *)c->f2);
        } else {
            r7 = func_0201293C((const struct BigObj *)c->f0);
            func_020074D8((void **)r7, (const struct Sub02007454Entry *)func_020185F0(c->f2));
        }
        (*state)++;
        break;
    case 4:
    default:
        return 1;
    }
    return 0;
}
