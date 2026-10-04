/*
 * function: func_02189B30
 * address:  0x02189B30
 * packet:   pkt_ov021_02189B30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02189B28  0x02189B28  thumb  ov021
 *   func_02159BF4  0x02159BF4  thumb  ov010
 *   func_02159BF8  0x02159BF8  thumb  ov010
 *   func_02159BFC  0x02159BFC  thumb  ov010
 *   func_02159C20  0x02159C20  thumb  ov010
 *   func_020140BC  0x020140BC  thumb
 *   func_020140C0  0x020140C0  thumb
 *   func_020140CC  0x020140CC  thumb
 *   d_021D3700     0x021D3700  data  a4
 */

typedef struct Rec { int w[15]; } Rec;
typedef struct Ent { Rec r; int f3c; int f40; int f44; } Ent;

extern Ent d_021D3700[];
extern unsigned int func_02189B28(unsigned int a);
struct Obj;
extern unsigned short func_02159BF4(struct Obj *p);
extern unsigned short func_02159BF8(struct Obj *p);
extern int func_02159BFC(struct Obj *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sub020140BCObj;
extern char *func_02159C20(char *p);
extern u16 func_020140BC(struct Sub020140BCObj *p);
extern u32 func_020140C0(struct Sub020140BCObj *p);
extern u32 func_020140CC(struct Sub020140BCObj *p);

void func_02189B30(int a, int x, char *out, void *obj)
{
    int i = (int)func_02189B28((unsigned int)a);

    *(Rec *)out = d_021D3700[i].r;
    if (d_021D3700[i].f40 != 0) {
        *(unsigned short *)(out + 0x14) = func_02159BF4(obj);
        *(unsigned short *)(out + 0x16) = func_02159BF8(obj);
        *(int *)(out + 0x18) = func_02159BFC(obj);
        *(int *)(out + 0x1c) = (int)func_02159C20(obj);
    }
    *(int *)(out + 0x20) = 1;
    *(int *)(out + 0x24) = 0xe;
    *(int *)(out + 0x28) = func_020140BC((struct Sub020140BCObj *)x);
    *(int *)(out + 0x2c) = func_020140C0((struct Sub020140BCObj *)x);
    *(int *)(out + 0x30) = func_020140CC((struct Sub020140BCObj *)x);
}
