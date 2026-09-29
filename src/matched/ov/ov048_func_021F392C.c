/*
 * function: func_021F392C
 * address:  0x021F392C
 * packet:   pkt_ov048_021F392C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02049030  0x02049030  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_021F4C10  0x021F4C10  thumb  ov048
 *   d_021F5224     0x021F5224  data  ov048  a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u32 a;
    u32 b;
    u32 pad[29];
} Rec;

typedef struct Obj {
    u16 f00;
    u32 f04;
    u32 pad08[5];
    Rec *f1c;
} Obj;

extern const char d_021F5224[];

extern u32 func_02188C9C(u32 a);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_02049030(u32 id);
extern u32 func_020111E8(void);
extern void func_021F4C10(Rec *r, u32 id, u32 i);

void func_021F392C(Obj *o)
{
    u32 i;
    u32 n;
    u32 r5;
    Rec buf;

    if (o->f1c == 0) {
        r5 = func_02188C9C(o->f04);
        i = 0;
        o->f1c = func_02030734(o->f00, 0x7c, 0, d_021F5224, 0x387);
        n = func_02049030(0xae);
        for (; i < n; i++) {
            func_021F4C10(&buf, 0xae, i);
            if (buf.a == r5) {
                if (buf.b == 0 || buf.b == func_020111E8()) {
                    *o->f1c = buf;
                    return;
                }
            }
        }
    }
}
