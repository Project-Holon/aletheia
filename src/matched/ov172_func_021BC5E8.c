/*
 * function: func_021BC5E8
 * address:  0x021BC5E8
 * packet:   pkt_ov172_021BC5E8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_020061E4  0x020061E4  thumb
 *   func_021BCEF8  0x021BCEF8  thumb  ov172
 *   func_0204B878  0x0204B878  arm
 *   func_0204B404  0x0204B404  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0202824C  0x0202824C  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02035C08  0x02035C08  arm
 *   func_020362DC  0x020362DC  arm
 *   d_021C7040     0x021C7040  data
 *
 * Touch handling for the selection list: a tap on a row toggles the entry (a kind 0x20 entry takes the single special slot +3, any other entry one of the three slots +0..+2) and refreshes the prompt; a tap on the scroll thumb grabs it, dragging moves it and scrolls the list; then polls the prompt's buttons and the exit rectangle.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

extern int func_02035D20(u32 *x, u32 *y);
extern int func_02035CB8(u32 *x, u32 *y);
extern u32 func_021BDFE4(void *p);
extern void func_020061E4(u32 id);
extern void func_021BCEF8(void *ctx, u8 *st);
extern void func_0204B878(u32 spr, int anim);
extern void func_0204B404(u32 spr, struct SpritePos *pos, int n);
extern u32 func_0202824C(u32 p);
extern void func_0202822C(u32 p, int v);
extern void func_0200616C(u32 id, int v);
extern int func_02035C08(const void *p);
extern u32 func_020362DC(void);
extern const u8 d_021C7040[];

void func_021BC5E8(void *ctx, u8 *list)
{
    u32 tx;
    u32 ty;
    u32 dx;
    u32 dy;
    struct SpritePos pos;
    int trg;
    int cont;
    s16 row;
    u8 id;
    u8 *e;
    int done;
    u8 i;
    int s;
    u32 range;

    trg = func_02035D20(&tx, &ty);
    cont = func_02035CB8(&dx, &dy);
    func_021BDFE4(ctx);
    if (trg == 1) {
        if (tx > 8 && tx < 0xe0) {
            row = (ty + *(u16 *)(list + 4)) >> 5;
            if (row >= 0 && row < 15) {
                id = *(list + row * 0x1c + 0x58);
                e = list + 0x1e4 + id * 0x24;
                done = 0;
                if (*(u32 *)e == 1 && e[0x1f] < 4) {
                    if (e[0x18] == 0x20) {
                        if (*(u32 *)(e + 8) == 0) {
                            list[3] = id;
                            done = 1;
                            *(u32 *)(e + 8) = 1;
                            *(u32 *)(e + 0x10) = 1;
                            *(u32 *)(list + 0xc) = 1;
                            func_020061E4(0x73b);
                        } else {
                            list[3] = 0xff;
                            *(u32 *)(e + 8) = 0;
                            done = 1;
                            *(u32 *)(e + 0x10) = 1;
                            *(u32 *)(list + 0xc) = 1;
                            func_020061E4(0x73c);
                        }
                    } else if (list[3] == 0xff) {
                        if (*(u32 *)(e + 8) == 0) {
                            for (i = 0; i < 3; i++) {
                                if (list[i] == 0xff) {
                                    list[i] = id;
                                    break;
                                }
                            }
                            if (i < 3) {
                                done = 1;
                                *(u32 *)(e + 8) = 1;
                                *(u32 *)(e + 0x10) = 1;
                                *(u32 *)(list + 0xc) = 1;
                                func_020061E4(0x73b);
                            }
                        } else {
                            for (i = 0; i < 3; i++) {
                                if (id == list[i]) {
                                    list[i] = 0xff;
                                    break;
                                }
                            }
                            *(u32 *)(e + 8) = 0;
                            done = 1;
                            *(u32 *)(e + 0x10) = 1;
                            *(u32 *)(list + 0xc) = 1;
                            func_020061E4(0x73c);
                        }
                    }
                }
                if (done == 1)
                    func_021BCEF8(ctx, list);
            }
        } else if (tx >= 0xec && tx <= 0x104 && ty >= *(u16 *)(list + 6) + 0xc
                   && ty <= *(u16 *)(list + 6) + 0x24 && list[0x14] > 5) {
            *(u32 *)(list + 0x10) = 1;
            func_0204B878(*(u32 *)(list + 0x404), 0xd);
            func_020061E4(0x66c);
        }
    }
    if (cont == 1 && *(u32 *)(list + 0x10) == 1 && list[0x14] > 5) {
        if (dx >= 0xec && dx <= 0x104 && dy >= 0xc && dy <= 0x9c) {
            range = (list[0x14] - 5) * 32;
            s = dy - 0x18;
            if (s < 0)
                s = 0;
            else if (s > 0x78)
                s = 0x78;
            *(u16 *)(list + 6) = s;
            pos.x = 0xf8;
            pos.y = *(u16 *)(list + 6) + 0x18;
            func_0204B404(*(u32 *)(list + 0x404), &pos, 1);
            *(u16 *)(list + 4) = *(u16 *)(list + 6) * range / 0x78;
            *(u32 *)(list + 0xc) = 1;
        }
    } else {
        *(u32 *)(list + 0x10) = 0;
        func_0204B878(*(u32 *)(list + 0x404), 0xc);
    }
    if (*(u32 *)(list + 0x1c) != 0 && func_0202824C(*(u32 *)(list + 0x1c)) == 1) {
        func_0202822C(*(u32 *)(list + 0x1c), 1);
        *(u32 *)(list + 8) = 6;
        func_020061E4(0x54c);
        if (*(u32 *)(list + 0x18) == 1)
            func_0200616C(0x73d, 2);
    }
    if (!func_02035C08(d_021C7040) || (func_020362DC() & 2)) {
        *(u32 *)(list + 8) = 6;
        *(u32 *)(list + 0x18) = 5;
        func_0204B878(*(u32 *)(list + 0x400), 9);
        func_020061E4(0x551);
    }
}
