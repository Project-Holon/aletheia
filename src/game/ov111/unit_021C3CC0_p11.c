/*
 * file:     unit_021C3CC0_p11.c
 * unit:     yes
 * function: func_021C58E0, func_021C5938, func_021C5958, func_021C59B0, func_021C59DC, func_021C5ACC, func_021C5AEC, func_021C5B34, func_021C5B80, func_021C5BCC, func_021C5CF4, func_021C5DB8, func_021C5F50, func_021C5F64
 * address:  0x021C58E0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040B1C  0x02040B1C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041300  0x02041300  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207E468  0x0207E468  arm
 *   func_02035BA4  0x02035BA4  arm
 *   d_021C8534     0x021C8534  data  a1
 *   d_021C854C     0x021C854C  data  a1
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035C08  0x02035C08  arm
 *   func_02035D40  0x02035D40  arm
 *   d_021C852C     0x021C852C  data  a1
 *   d_021C853C     0x021C853C  data  a1
 *   d_021C86A8     0x021C86A8  data  a1
 */
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData;

typedef struct {
    u16 w;
    u16 h;
} ScrnData;

typedef struct {
    u8 pad0[0x3030];
    CharData *chr;
    u8 pad3034[0x31DC - 0x3034];
    ScrnData *scrn;
} Work_021C58E0;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
} Info_021C5AEC;

typedef struct {
    u8 pad0[0x28];
    Info_021C5AEC *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x32C7 - 0x3038];
    u8 blink;
    u8 phase;
} Work_021C5AEC;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef struct {
    u8 pad0[0x31EC];
    PlttData *pltt;
    int frame;
} Work_021C5B34;

typedef struct {
    u8 pad0[0x3034];
    u32 f3034;
    u8 pad3038[0x305E - 0x3038];
    u16 h305E;
    u8 pad3060[0x330F - 0x3060];
    u8 b330F;
} Work_021C5B80;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
} Info_021C5BCC;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

typedef struct {
    u8 pad0[0x28];
    Info_021C5BCC *info;
    u8 pad2C[0x305C - 0x2C];
    u16 h305C;
    u8 pad305E[0x32EA - 0x305E];
    TouchPos raw;
    TouchPos cur;
    u8 pad32F2[0x32F6 - 0x32F2];
    u8 size;
    u8 pad32F7[0x330F - 0x32F7];
    u8 b330F;
} Work_021C5BCC;

extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 layer);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern u32 func_0204162C(int channel);
extern void func_02041B6C(u32 bit);
extern void func_0207E468(const void *src, u32 offset, u32 size);
extern int func_02035BA4(const void *p);
extern u32 func_02035CB8(u32 *x, u32 *y);
extern int func_02035C08(const void *rect);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
void func_021C58E0(Work_021C58E0 *p);
void func_021C5938(void *p);
void func_021C5958(const u8 *src, u8 *dst);
void func_021C59B0(const u8 *src, u8 *dst);
void func_021C59DC(u32 bg, int mode);
void func_021C5ACC(u32 bg, const void *src, int mode);
void func_021C5AEC(Work_021C5AEC *p);
void func_021C5B34(Work_021C5B34 *p);
void func_021C5B80(Work_021C5B80 *p);
void func_021C5BCC(Work_021C5BCC *p, int side);
void func_021C5CF4(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel);
int func_021C5DB8(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side);
void func_021C5F50(TouchPos *src, TouchPos *dst);
int func_021C5F64(u8 *pix, TouchPos *cur, TouchPos *prev, int flush, const void *src, u8 clip, u8 side);
extern const u8 d_021C8534[];
extern const u8 d_021C854C[];
extern const u8 d_021C852C[];
extern const u8 d_021C853C[];
extern const u8 d_021C86A8[2][2][16];


/*
 * Addresses are Black-image addresses.
 */
void func_021C58E0(Work_021C58E0 *p)
{
    ScrnData *s;

    func_02040B1C(7, p->chr->data, p->chr->size, 0);
    s = p->scrn;
    func_020410D0(7, 0x15, 2, 10, 11, (u32)s + 0xC, 0x15, 2, s->w >> 3, s->h >> 3);
    func_020409B4(7);
}


void func_021C5938(void *p)
{
    func_02041300(7, 0, 0x14, 6, 6, 9, 0x10);
}


void func_021C5958(const u8 *src, u8 *dst)
{
    int i;

    for (i = 0; i < 0x3000; i++) {
        if ((src[i / 64 * 8 + (u8)(i / 8 % 8)] >> (u8)(i % 8)) & 1) {
            dst[i] = 7;
        }
    }
}


void func_021C59B0(const u8 *src, u8 *dst)
{
    int i, j;
    int v;

    for (i = 0; i < 0x600; i++) {
        v = 0;
        for (j = 0; j < 8; j++) {
            v |= (src[i * 8 + j] & 1) << j;
        }
        dst[i] = v;
    }
}


void func_021C59DC(u32 bg, int mode)
{
    u16 *map = (u16 *)func_0204162C((u8)bg);
    u8 x, y;
    u16 n;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 24; x++) {
            map[(y + 11) * 32 + 4 + x] = 0;
        }
    }
    n = 0;
    switch (mode) {
    case 2:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 24; x++) {
                n++;
                map[(y + 11) * 32 + 4 + x] = n;
            }
        }
        break;
    case 0:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    case 1:
        n += 12;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    }
    func_02041B6C((u8)bg);
}


void func_021C5ACC(u32 bg, const void *src, int mode)
{
    func_02040B1C((u8)bg, src, 0x3000, 1);
    func_021C59DC(bg, mode);
}


void func_021C5AEC(Work_021C5AEC *p)
{
    if (p->f3034 != 0 && p->info->f4_4) {
        p->blink++;
        if (p->blink > 20) {
            p->phase ^= 1;
            func_021C59DC(7, p->phase);
            p->blink = 0;
        }
    }
}


void func_021C5B34(Work_021C5B34 *p)
{
    u16 *pal = p->pltt->data;

    p->frame++;
    if (p->frame > 8) {
        p->frame = 0;
    }
    if (p->frame == 0) {
        func_0207E468(pal + 3, 6, 4);
    } else if (p->frame == 4) {
        func_0207E468(pal + 5, 6, 4);
    }
}


void func_021C5B80(Work_021C5B80 *p)
{
    if ((p->f3034 != 0 && p->h305E == 0 && func_02035BA4(d_021C8534))
        || (p->h305E == 1 && func_02035BA4(d_021C854C))) {
        p->b330F = 0;
    }
}


void func_021C5BCC(Work_021C5BCC *p, int side)
{
    u32 x, y;

    if (p->info->f4_5 || p->info->f4_4 == 1) {
        return;
    }
    if (func_02035CB8(&x, &y)) {
        if (side == 0) {
            if (!func_02035C08(d_021C852C)) {
                p->b330F = 1;
            }
            if (p->b330F != 0 && !func_02035D40((struct Ctx *)d_021C852C, x, y)) {
                p->raw.x = x;
                p->raw.y = y;
                p->raw.size = p->size;
                p->raw.active = 1;
                if (x < 0x80) {
                    p->h305C = 0;
                } else {
                    p->h305C = 1;
                }
            } else {
                p->raw.active = 0;
            }
        } else {
            if (!func_02035C08(d_021C853C)) {
                p->b330F = 1;
            }
            if (p->b330F != 0 && !func_02035D40((struct Ctx *)d_021C853C, x, y)) {
                p->raw.x = ((x - 0x20) + p->h305C * 0xC0) / 2 + 0x20;
                p->raw.y = (y - 0x18) / 2 + 0x58;
                p->raw.size = p->size;
                p->raw.active = 1;
            } else {
                p->raw.active = 0;
            }
        }
    } else {
        p->raw.active = 0;
    }
    p->cur.x = p->raw.x;
    p->cur.y = p->raw.y;
    p->cur.size = p->raw.size;
    p->cur.active = p->raw.active;
}

/*
 * 4x4 tile blit into an 8x8-tile layout, 24 tiles per row.
 * The `b skip` stubs are `n++; continue;` repeated in each rejection arm
 * (tail merging leaves a lone branch per arm). xx and yy declared at the top,
 * before j, k, n, give the image colours (xx r2, k r3, n r4).
 */
void func_021C5CF4(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel)
{
    int xx, yy;
    int j, k, n = 0;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            xx = x + k;
            yy = y + j;
            if (xx < 0 || yy < 0) {
                n++;
                continue;
            }
            if (xx >= w || yy >= h) {
                n++;
                continue;
            }
            if (mode == 1 && ((sel == 0 && xx >= 0x60) || (sel == 1 && xx <= 0x5f))) {
                n++;
                continue;
            }
            {
                int idx = xx % 8 + ((yy % 8) * 8 + ((yy / 8) * 24 + xx / 8) * 64);
                int c = src[n];
                if (c == 1) dst[idx] = 7;
                else if (c == 2) dst[idx] = 0;
            }
            n++;
        }
    }
}


int func_021C5DB8(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side)
{
    int n = 0;
    int x = *px;
    int y = *py;
    int ex = x1;
    int dx, dy;
    int ey = y1;
    int e, s;

    if (a == 0 && b == 0) {
        *px = x1;
        *py = y1;
        return n;
    }
    dx = x1 - x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = y1 - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dx > dy) {
        if (x > x1) {
            s = (y > y1) ? 1 : -1;
            ex = x;
            x = x1;
            y = y1;
        } else {
            s = (y < y1) ? 1 : -1;
        }
        func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
        x++;
        e = dx >> 1;
        n++;
        for (; x <= ex; x++) {
            e -= dy;
            if (e < 0) {
                e += dx;
                y += s;
            }
            func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    } else {
        if (y > y1) {
            s = (x > x1) ? 1 : -1;
            ey = y;
            y = y1;
            x = x1;
        } else {
            s = (x < x1) ? 1 : -1;
        }
        func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
        y++;
        e = dy >> 1;
        n++;
        for (; y <= ey; y++) {
            e -= dx;
            if (e < 0) {
                e += dy;
                x += s;
            }
            func_021C5CF4(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    }
    *px = x1;
    *py = y1;
    return n;
}


void func_021C5F50(TouchPos *src, TouchPos *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->size = src->size;
    dst->active = src->active;
}


int func_021C5F64(u8 *pix, TouchPos *cur, TouchPos *prev, int flush, const void *src, u8 clip, u8 side)
{
    int drew = 0;
    int n = 0;
    int ofs;
    int px, py;

    if (clip == 0) {
        ofs = 4;
    } else {
        ofs = 2;
    }
    if (cur->active) {
        if (prev->active) {
            px = prev->x - 0x20 - ofs;
            py = prev->y - 0x5A;
        }
        n = func_021C5DB8(pix, d_021C86A8[clip][cur->size], cur->x - 0x20 - ofs, cur->y - 0x5A, &px, &py, 0, prev->active, clip, side);
        drew = 1;
    }
    if (drew && flush) {
        func_02040B1C(7, src, 0x3000, 1);
    }
    func_021C5F50(cur, prev);
    cur->active = 0;
    return n;
}
