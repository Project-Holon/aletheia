/*
 * function: func_021BC7FC
 * address:  0x021BC7FC
 * packet:   pkt_ov172_021BC7FC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: 2 bytes off (one instruction). At +0x16C the original has `movs r0, #1`
 * (keep = 1 as a constant); `keep = match;` gives `ldr r0, [sp, #0x10]` instead, and
 * `keep = 1;` makes the compiler fetch changed's 1 from keep's slot and reorder the
 * stores (18 bytes off). Loop counters i/j are one variable (fixes the stack slot
 * order); `j--` before `any = 1` in the compaction loop; eb temp orders the b20 loads.
 * func_021BD0A4 is declared to return a value (matched definition says void, the call
 * site uses r0).
 *
 * symbols:
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021B8108  0x021B8108  thumb  ov172
 *   func_02177B80  0x02177B80  thumb  ov014
 *   func_021B85D0  0x021B85D0  thumb  ov172
 *   func_021BD0A4  0x021BD0A4  thumb  ov172
 *   func_021BCB88  0x021BCB88  thumb  ov172
 *   func_021BCEF8  0x021BCEF8  thumb  ov172
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8  p0[2];
    u8  : 1;
    u8  kind : 5;
    u8  : 2;
    u8  p3;
    u32 f4;
    u8  p8[3];
    u8  : 7;
    u8  bit7 : 1;
    u32 : 17;
    u32 id : 10;
    u32 : 5;
    u8  p10[10];
    u8  x1a[6];
    u8  b20;
    u8  : 1;
    u8  bit1 : 1;
    u8  : 6;
};

struct Rec {
    u32 flag;
    u8  pad[0x14];
    u8  slot;
    u8  pad2[3];
};

struct Ent {
    u32 used;
    u32 f;
    u32 g;
    u32 pad[2];
    u8 *data;
    u8  kind;
    u8  name[6];
    u8  pad2;
    u8  recIdx;
    u8  pad3[3];
};

struct Ctx {
    u8  head[4];
    u32 pad4;
    int state;
    u32 f0c;
    u8  pad10[0x30];
    struct Rec rec[15];
    struct Ent ent[15];
};

extern u32  func_021BDFE4(void *p);
extern int  func_021B8108(void *a0, u32 v);
extern u32  func_0203CF10(u32 a);
extern u32  func_0203CF3C(u32 a);
extern u8   func_02177B80(int i);
extern u32  func_020084F4(struct Obj *o);
extern u32  func_02008550(struct Obj *o);
extern u32  func_02008530(struct Obj *o);
extern void func_02087C6C(void *buf);
extern int  func_021B85D0(struct Obj *o, void *buf);
extern u32  func_021BD0A4(void *a0, struct Ctx *ctx, u32 a, u32 b, u32 c);
extern u32  sub_02013D5C(u32 id);
extern u32  sub_02013D9C(u32 id);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_021BCB88(void *a0, struct Ctx *ctx);
extern void func_021BCEF8(void *a0, struct Ctx *ctx);

void func_021BC7FC(void *a0, struct Ctx *ctx)
{
    u8 buf[8];
    int any;
    int moved;
    int keep;
    int changed;
    struct Obj *obj;
    int kind;
    u32 p18;
    u32 p14;
    int match;
    u32 found;
    int j;
    u8 k;
    u8 m;
    u8 n;
    u8 t;
    int ok;
    u8 *name;
    u32 d;
    u8 eb;

    any = 0;
    moved = 0;
    if (func_021B8108(a0, func_021BDFE4(a0)) == 0) {
        return;
    }
    for (j = 0; j < 15; j++) {
        if (ctx->ent[j].used == 1) {
            ctx->ent[j].f = 1;
        }
    }
    if (ctx->state == 7 || ctx->state == 9 || ctx->state == 10 || ctx->state < 5) {
        goto second;
    }
    for (j = 0; j < 16; j++) {
        keep = 0;
        changed = 0;
        obj = (struct Obj *)func_0203CF10(j);
        if (obj == 0) {
            continue;
        }
        found = 0xff;
        name = (u8 *)func_0203CF3C(j);
        kind = func_02177B80(j);
        if (kind == 3 && obj->kind != 2) {
            continue;
        }
        ok = 0;
        if (kind == 0x20) {
            p18 = func_020084F4(obj);
            d = func_02008550(obj);
            p14 = func_02008530(obj);
            func_02087C6C(buf);
            if (obj->bit1 == 0 || func_021B85D0(obj, buf) == 1) {
                ok = func_021BD0A4(a0, ctx, p18, p14, d);
            }
        } else if (sub_02013D5C((u16)obj->id) == 0 && sub_02013D9C((u16)obj->id) == 0) {
            ok = func_021BD0A4(a0, ctx, (u32)obj->x1a, obj->f4, obj->bit7);
        }
        if (ok == 0) {
            continue;
        }
        for (k = 0; k < 15; k++) {
            if (ctx->ent[k].used == 1) {
                match = 1;
                for (m = 0; m < 6; m++) {
                    if (name[m] != ctx->ent[k].name[m]) {
                        match = 0;
                        break;
                    }
                }
                if (match == 1) {
                    ctx->ent[k].f = 0;
                    keep = match;
                    if (kind != ctx->ent[k].kind) {
                        changed = 1;
                        keep = 0;
                        found = k;
                        for (n = 0; n < 3; n++) {
                            if (ctx->head[n] == k) {
                                ctx->head[n] = 0xff;
                                moved = 1;
                            }
                        }
                        if (ctx->head[3] == k) {
                            ctx->head[3] = 0xff;
                            moved = 1;
                        }
                    }
                    if (kind == 0x20) {
                        eb = ((struct Obj *)ctx->ent[k].data)->b20;
                        if (eb != obj->b20) {
                            keep = 0;
                            changed = 1;
                            found = k;
                        }
                    }
                    break;
                }
            } else if (found == 0xff) {
                found = k;
            }
        }
        if (keep != 0 || found == 0xff) {
            continue;
        }
        ctx->ent[found].used = 1;
        ctx->ent[found].f = 0;
        ctx->ent[found].g = 0;
        for (m = 0; m < 6; m++) {
            ctx->ent[found].name[m] = name[m];
        }
        if (kind == 0x20) {
            ctx->ent[found].kind = 0x20;
            func_02082D44(obj, ctx->ent[found].data, 0x34);
        } else {
            ctx->ent[found].kind = 3;
            func_02082D44(obj, ctx->ent[found].data, 0x64);
        }
        if (changed == 0) {
            for (t = 0; t < 15; t++) {
                if (ctx->rec[t].slot == 0xff) {
                    ctx->rec[t].slot = found;
                    ctx->ent[found].recIdx = t;
                    ctx->rec[t].flag = 1;
                    break;
                }
            }
        } else {
            ctx->rec[ctx->ent[found].recIdx].flag = 1;
        }
        any = 1;
    }
second:
    for (j = 0; j < 15; j++) {
        if (ctx->ent[j].used == 1 && ctx->ent[j].f == 1) {
            u8 r = ctx->ent[j].recIdx;
            for (; r < 14; r++) {
                u8 s = ctx->rec[r + 1].slot;
                if (s == 0xff) {
                    break;
                }
                ctx->rec[r].slot = s;
                ctx->ent[ctx->rec[r].slot].recIdx = r;
                ctx->rec[r].flag = 1;
            }
            ctx->rec[r].slot = 0xff;
            ctx->rec[r].flag = 1;
            ctx->ent[j].recIdx = 0xff;
            ctx->ent[j].used = 0;
            for (n = 0; n < 3; n++) {
                if (ctx->head[n] == j) {
                    ctx->head[n] = 0xff;
                    moved = 1;
                }
            }
            if (ctx->head[3] == j) {
                ctx->head[3] = 0xff;
                moved = 1;
            }
            j--;
            any = 1;
        }
    }
    if (any == 1) {
        func_021BCB88(a0, ctx);
        moved = 1;
        ctx->f0c = 1;
    }
    if (moved == 1 && ctx->state == 5) {
        func_021BCEF8(a0, ctx);
    }
}
