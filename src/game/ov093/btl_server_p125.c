/*
 * file:     btl_server_p125.c
 * unit:     yes
 * function: func_021CCB34, func_021CCB78, func_021CCB98, func_021CCBE8, func_021CCC0C, func_021CD0F0, func_021CD4B0
 * address:  0x021CCB34
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021F3A84  0x021F3A84  data
 *   func_02034714  0x02034714  arm
 *   func_021CCAA8   0x021CCAA8  thumb ov093
 *   func_021CCAE0   0x021CCAE0  thumb ov093
 *   func_021CCAD4   0x021CCAD4  thumb ov093
 *   func_021CCB18   0x021CCB18  thumb ov093
 *   data_021EFF14  0x021EFF14  data  ov093
 *   data_021F3B44  0x021F3B44  data  ov093
 */
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[0xBB6];
} Buf_021CCB34;

typedef struct {
    u32 unk0;
    u32 pos;
} ByteStream;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[0xBB5];
} Buf_021CCB98;

typedef struct { u32 wpos,rpos; u8 buf[3000]; } Buf_021CCBE8;

typedef char *va_list;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021CCAA8(void *w, u8 v);
extern void func_021CCAE0(void *w, u16 v);
extern u8 func_021CCAD4(u8 *p);
extern u16 func_021CCB18(void *r);
void func_021CCB34(Buf_021CCB34 *w, u32 v);
/* read a 24-bit big-endian value and advance the cursor */ u32 func_021CCB78(ByteStream *s);
void func_021CCB98(Buf_021CCB98 *w, u32 v);
u32 func_021CCBE8(Buf_021CCBE8 *p);
void func_021CCC0C(void *w, u32 id, int cmd, s32 *a);
void func_021CD0F0(void *r, int cmd, s32 *a);
void func_021CD4B0(void *w, volatile u32 id, ...);
extern char data_021F3A84[];
extern const u8 data_021EFF14[];
extern s32 data_021F3B44[];


void func_021CCB34(Buf_021CCB34 *w, u32 v)
{
    if (w->wpos >= 0xBB6) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}


/* read a 24-bit big-endian value and advance the cursor */
u32 func_021CCB78(ByteStream *s)
{
    u32 pos = s->pos;
    u8 *p = (u8 *)s + pos;
    u32 v = (p[8] << 16) | (p[9] << 8) | p[10];

    s->pos = pos + 3;
    return v;
}


void func_021CCB98(Buf_021CCB98 *w, u32 v)
{
    if (w->wpos >= 0xBB5) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 24;
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}

u32 func_021CCBE8(Buf_021CCBE8 *p) {u32 v;u8 *q;q=(u8*)p+p->rpos;v=((u32)q[8]<<24)|((u32)q[9]<<16)|((u32)q[10]<<8)|q[11];p->rpos+=4;return v;}


void func_021CCC0C(void *w, u32 id, int cmd, s32 *a)
{
    int i;

    func_021CCAE0(w, id);
    switch (cmd) {
    case 1:
        func_021CCAA8(w, a[0]);
        break;
    case 17:
        func_021CCAE0(w, a[0]);
        break;
    case 2:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        break;
    case 18:
        func_021CCAA8(w, a[0]);
        func_021CCAE0(w, a[1]);
        break;
    case 34:
        func_021CCAA8(w, a[0]);
        func_021CCB98(w, a[1]);
        break;
    case 50:
        func_021CCAA8(w, ((a[0] & 0xF) << 4) | (a[1] & 0xF));
        break;
    case 66:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        break;
    case 3:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        break;
    case 19:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAE0(w, a[2]);
        break;
    case 35:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        break;
    case 51:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        break;
    case 67:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        break;
    case 83:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCB98(w, a[2]);
        break;
    case 20:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, ((a[2] & 0x1F) << 3) | (a[3] & 7));
        break;
    case 4:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 36:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAA8(w, a[3]);
        break;
    case 52:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAE0(w, a[3]);
        break;
    case 68:
        func_021CCAE0(w, (a[2] & 0x3F) | (((a[1] & 0x1F) << 6) | ((a[0] & 0x1F) << 11)));
        func_021CCAE0(w, a[3]);
        break;
    case 84:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 5:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        func_021CCAE0(w, a[3]);
        func_021CCAE0(w, a[4]);
        break;
    case 21: {
        u8 hi = ((a[0] & 0x1F) << 3) | (a[1] & 7);
        u8 lo = ((a[2] & 0x7F) << 1) | (a[3] & 1);
        func_021CCAE0(w, hi);
        func_021CCAE0(w, lo);
        func_021CCAE0(w, a[4]);
        break;
    }
    case 37:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 7) << 2) | ((a[2] & 1) << 1) | (a[3] & 1));
        func_021CCAE0(w, a[4]);
        break;
    case 6: {
        u16 v0 = (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10));
        u16 v1 = (a[5] & 0x1F) | (((a[4] & 0x1F) << 5) | ((a[3] & 0x1F) << 10));
        func_021CCAE0(w, v0);
        func_021CCAE0(w, v1);
        break;
    }
    case 22:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 3) << 3) | ((a[2] & 1) << 2) | ((a[3] & 1) << 1) | (a[4] & 1));
        func_021CCAE0(w, a[5]);
        break;
    case 38:
        func_021CCB34(w, ((a[0] & 0x1F) << 15) | ((a[1] & 0x1F) << 10) | ((a[2] & 0x1F) << 5) | (a[3] & 0x1F));
        func_021CCAE0(w, a[4]);
        func_021CCAE0(w, a[5]);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            func_021CCAA8(w, a[i]);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            func_021CCAA8(w, a[i]);
        break;
    }
}


void func_021CD0F0(void *r, int cmd, s32 *a)
{
    u8 b;
    u32 h;
    u32 x;
    int i;

    switch (cmd) {
    case 1:
        a[0] = func_021CCAD4(r);
        break;
    case 17:
        a[0] = func_021CCB18(r);
        break;
    case 2:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        break;
    case 18:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCB18(r);
        break;
    case 34:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCBE8(r);
        break;
    case 50:
        b = func_021CCAD4(r);
        a[0] = (b >> 4) & 0xF;
        a[1] = b & 0xF;
        break;
    case 66:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        break;
    case 3:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        break;
    case 19:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCB18(r);
        break;
    case 35:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        break;
    case 51:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        break;
    case 67:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        break;
    case 83:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCBE8(r);
        break;
    case 20:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        b = func_021CCAD4(r);
        a[2] = (b >> 3) & 0x1F;
        a[3] = b & 7;
        break;
    case 4:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        a[3] = func_021CCB18(r);
        break;
    case 36:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCAD4(r);
        break;
    case 52:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCB18(r);
        break;
    case 68:
        h = func_021CCB18(r);
        a[0] = (h >> 11) & 0x1F;
        a[1] = (h >> 6) & 0x1F;
        a[2] = h & 0x3F;
        a[3] = func_021CCB18(r);
        break;
    case 84:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        a[3] = func_021CCB18(r);
        break;
    case 5:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        a[3] = func_021CCB18(r);
        a[4] = func_021CCB18(r);
        break;
    case 21: {
        u32 hi = func_021CCB18(r);
        u32 lo = func_021CCB18(r);
        a[0] = ((u8)hi >> 3) & 0x1F;
        a[1] = (u8)hi & 7;
        a[2] = ((u8)lo >> 1) & 0x7F;
        a[3] = (u8)lo & 1;
        a[4] = func_021CCB18(r);
        break;
    }
    case 37:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 2) & 7;
        a[2] = (x >> 1) & 1;
        a[3] = x & 1;
        a[4] = func_021CCB18(r);
        break;
    case 6: {
        u32 v0 = func_021CCB18(r);
        u32 v1 = func_021CCB18(r);
        a[0] = (v0 >> 10) & 0x1F;
        a[1] = (v0 >> 5) & 0x1F;
        a[2] = v0 & 0x1F;
        a[3] = (v1 >> 10) & 0x1F;
        a[4] = (v1 >> 5) & 0x1F;
        a[5] = v1 & 0x1F;
        break;
    }
    case 22:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 3) & 3;
        a[2] = (x >> 2) & 1;
        a[3] = (x >> 1) & 1;
        a[4] = x & 1;
        a[5] = func_021CCB18(r);
        break;
    case 38:
        x = func_021CCB78(r);
        a[0] = (x >> 15) & 0x1F;
        a[1] = (x >> 10) & 0x1F;
        a[2] = (x >> 5) & 0x1F;
        a[3] = x & 0x1F;
        a[4] = func_021CCB18(r);
        a[5] = func_021CCB18(r);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            a[i] = func_021CCAD4(r);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            a[i] = func_021CCAD4(r);
        break;
    }
}

void func_021CD4B0(void *w, volatile u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = data_021EFF14[id];
    u32 n = cmd & 0xF;
    va_start(ap, id);
    for (; i < n; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    func_021CCC0C(w, id, cmd, data_021F3B44);
}
